#pragma once
#include "core.hpp"

namespace core
{
	/// Checks wheter a type is trivially serializable
	/**
		A type is trivially serializable if it is trivially copyable, not a pointer, not visitable
		and does not have a non-trivial value_type.

		This trait can be specialized for types that are certainly trivially serializable.
	*/
	template <class T>
	struct is_trivially_serializable;

	/// Serialization traits for serializing non-trivial types
	/**
		Offers methods for serialization and deserialization (see implementation of various traits below).

		This trait can be specialized to add support for complex types.
	*/
	template <class T, class Enable>
	struct serialization_traits;

	namespace detail
	{
		// Checks whether a type accepts a serialization_visitor
		template <class T, class Enable = void>
		struct is_serialization_visitable : std::false_type {};

		template <class T>
		struct is_serialization_visitable<T,
			void_t<decltype(static_cast<void (T::*)(serialization_visitor)>(&T::operator()))>
		> : std::true_type {};

		// Checks whether a type has a non-trivial value_type (which is highly suspicious
		// and most certainly indicates a non-trivial container of some sort)
		template <class T, class Enable = void>
		struct has_non_trivially_serializable_value_type : std::false_type {};

		template <class T>
		struct has_non_trivially_serializable_value_type<T, void_t<typename T::value_type>>
			: std::bool_constant<!is_trivially_serializable<typename T::value_type>::value> {};
	}

	template <class T>
	struct is_trivially_serializable : std::bool_constant<
		std::is_trivially_copyable_v<T> && 
		!std::is_pointer_v<T> && 
		!detail::is_serialization_visitable<T>::value &&
		!detail::has_non_trivially_serializable_value_type<T>::value
	> {};

	namespace detail
	{
		// Trait for serializing trivial types
		template <class T>
		struct serialization_traits_trivial
		{
			static void serialize(serialization_sink& sink, const T& value)
			{
				sink.write_bytes(&value, sizeof(T));
			}

			static void deserialize_inplace(serialization_source& source, T* value)
			{
				source.read_bytes(value, sizeof(T));
			}

			static T deserialize(serialization_source& source)
			{
				// Have to use an aligned storage for non-default-constructible types
				std::aligned_storage_t<sizeof(T), alignof(T)> storage = {};
				auto ptr = static_cast<void*>(&storage);
				source.read_bytes(ptr, sizeof(T));

				// copies right out the aligned storage as T, never calls the destructor of T
				// (as we never called a constructor of T). All this should be fine for
				// trivially serializable types.
				return *static_cast<const T*>(ptr);
			}
		};

		// serialization_traits2 is the fallback for types with no specific specialization of serialization_traits
		// This "second phase matching" uses more generic traits which might interfere with more specific traits when done
		// on the same level. The default uses trivial serialization.
		template <class T, class Enable = void>
		struct serialization_traits2 : serialization_traits_trivial<T>
		{
			static_assert(is_trivially_serializable<T>::value, "T is not trivially serializable");
		};

		// Trait for types accepting a serialization visitor
		template <class T>
		struct serialization_traits_visitable
		{
			static void serialize(serialization_sink& sink, const T& value)
			{
				serialization_visitor v(&sink);
				// Remove constness, we know that the serializing visitor is not going
				// to touch anything
				const_cast<T&>(value).operator()(v);
			}

			static void deserialize_inplace(serialization_source& source, T* value)
			{
				serialization_visitor v(&source);
				value->operator()(v);
			}

			static T deserialize(serialization_source& source)
			{
				if constexpr (std::is_default_constructible_v<T>)
				{
					T value = {};
					deserialize_inplace(source, &value);
					return value;
				}
				else
				{
					static_assert(std::is_constructible_v<T, serialization_key>,
						"The visitable type T is not default-constructible, it has to implement a `serialization_key` constructor");

					T value{ serialization_key() };
					deserialize_inplace(source, &value);
					return value;
				}
			}

			static std::unique_ptr<T> deserialize_unique(serialization_source& source)
			{
				if constexpr (std::is_default_constructible_v<T>)
				{
					auto ptr = std::make_unique<T>();
					deserialize_inplace(source, ptr.get());
					return ptr;
				}
				else
				{
					auto ptr = std::make_unique<T>(serialization_key());
					deserialize_inplace(source, ptr.get());
					return ptr;
				}
			}
		};

		template <class T>
		struct serialization_traits2 <T, std::enable_if_t<is_serialization_visitable<T>::value>>
			: detail::serialization_traits_visitable<T>
		{
		};

		// Trait for generic containers
		template <class Container>
		struct serialization_traits_container
		{
			static void serialize(serialization_sink& sink, const Container& c)
			{
				// use fixed size 32 bit for compatibility between 32-bit / 64-bit
				auto size = static_cast<std::uint32_t>(std::size(c));
				sink.write(size);
				for (const auto& value : c)
					sink.write(value);
			}

			static void deserialize_inplace(serialization_source& source, Container* c)
			{
				// use fixed size 32 bit for compatibility between 32-bit / 64-bit
				auto size = source.read<std::uint32_t>();

				c->clear();
				if (!size)
					return;

				for (std::uint32_t i = 0; i < size; ++i)
					c->insert(c->end(), source.read<typename Container::value_type>());
			}
		};

		// Match all types that are quacking like a container
		template <class T>
		struct serialization_traits2<T, core::void_t<
			std::enable_if_t<!is_trivially_serializable<T>::value && !is_serialization_visitable<T>::value>,
			decltype(std::declval<T>().begin()),
			decltype(std::declval<T>().end()),
			decltype(std::declval<T>().size()),
			typename T::value_type
			>> : detail::serialization_traits_container<T>{};

		// Optimized trait for serializing continuous memory (vectors, strings)
		template <class ValueType>
		struct serialization_traits_vector
		{
			template <class Vector>
			static void serialize(serialization_sink& sink, const Vector& v)
			{
				serialize(sink, v.empty() ? nullptr : v.data(), v.size());
			}

			static void serialize(serialization_sink& sink, const ValueType* data, size_t size)
			{
				// use fixed size 32 bit for compatibility between 32-bit / 64-bit
				sink.write(static_cast<std::uint32_t>(size));
				if constexpr (is_trivially_serializable<ValueType>::value)
				{
					sink.write_bytes(data, size * sizeof(ValueType));
				}
				else
				{
					for (size_t i = 0; i < size; ++i)
						sink.write(data[i]);
				}
			}

			template <class Vector>
			static void deserialize_inplace(serialization_source& source, Vector* v)
			{
				// use fixed size 32 bit for compatibility between 32-bit / 64-bit
				auto size = source.read<std::uint32_t>();

				v->clear();
				if (!size)
					return;

				if constexpr (std::is_default_constructible_v<ValueType> && is_trivially_serializable<ValueType>::value)
				{
					v->resize(size);
					source.read_bytes(v->data(), size * sizeof(ValueType));
				}
				else
				{
					v->reserve(size);
					for (std::uint32_t i = 0; i < size; ++i)
						v->emplace_back(source.read<ValueType>());
				}
			}
		};

		// Trait for serializing C-strings (does not support deserialization)
		template <class Char>
		struct serialization_traits_cstr
		{
			// Optionally takes a len to avoid unnecessary lookups if the len is already known
			// (e.g. in case of std::string)
			static void serialize(serialization_sink& sink, const Char* str, size_t len = 0)
			{
				assert(str);
				for (; str[len]; ++len);
				// serialize just like a vector does
				serialization_traits_vector<Char>::serialize(sink, str, len);
			}
		};
	}

	// Traits for non-specialized types: Use serialization_traits2 for a second-phase lookup
	template <class T, class Enable>
	struct serialization_traits : detail::serialization_traits2<T> {};

	template <class T>
	struct serialization_traits<std::vector<T>> : detail::serialization_traits_vector<T> {};

	template <>
	struct serialization_traits<char*> : detail::serialization_traits_cstr<char> {};

	template <>
	struct serialization_traits<wchar_t*> : detail::serialization_traits_cstr<wchar_t> {};

	template <class Char>
	struct serialization_traits<std::basic_string<Char>> : detail::serialization_traits_vector<Char> {};

	template <class First, class Second>
	struct serialization_traits<std::pair<First, Second>>
	{
		static void serialize(serialization_sink& sink, const std::pair<First, Second>& pair)
		{
			sink.write(pair.first);
			sink.write(pair.second);
		}

		static void deserialize_inplace(serialization_source& source, std::pair<First, Second>* c)
		{
			source.read(&c->first);
			source.read(&c->second);
		}

		static std::pair<First, Second> deserialize(serialization_source& source)
		{
			return { source.read<First>(), source.read<Second>() };
		}
	};

	template <class Type>
	void serialization_args::set_arg(Type arg)
	{
		for (auto& any : m_args)
		{
			if (auto stored = std::any_cast<Type>(&any))
			{
				*stored = std::move(arg);
				return;
			}
		}

		m_args.emplace_back(std::move(arg));
	}

	template <class Type>
	Type serialization_args::arg() const
	{
		for (auto& any : m_args)
		{
			if (auto stored = std::any_cast<Type>(&any))
			{
				return *stored;
			}
		}

		assert(!"arg not set");
		throw serialization_error("arg not set");
	}

	template <class T>
	void serialization_sink::write(const T& value)
	{
		serialization_traits<core::deep_decay_t<T>>::serialize(*this, value);
	}

	namespace detail
	{
		// read implementation for serialization_traits offering a constructing deserialize method
		template <class T>
		auto read_construct(serialization_source& source, int) ->
			decltype(serialization_traits<T>::deserialize(source))
		{
			return serialization_traits<T>::deserialize(source);
		}

		// read implementation for serialization_traits not offering a constructing deserialize method
		template <class T>
		auto read_construct(serialization_source& source, ...)
		{
			// Default-construct and deserialize inplace
			T value = {};
			source.read(&value);
			return value;
		}

		// read_unique implementation for serialization_traits offering a deserialize_unique method
		template <class T>
		auto read_unique(serialization_source& source, int) ->
			decltype(serialization_traits<T>::deserialize_unique(source))
		{
			return serialization_traits<T>::deserialize_unique(source);
		}

		// read_unique implementation for serialization_traits not offering a deserialize_unique method
		template <class T>
		auto read_unique(serialization_source& source, ...)
		{
			if constexpr (std::is_default_constructible_v<T>)
			{
				// Default-construct and deserialize inplace
				auto ptr = std::make_unique<T>();
				serialization_traits<T>::deserialize_inplace(source, ptr.get());
				return ptr;
			}
			else
			{
				// Deserialize and copy-construct
				return std::make_unique<T>(source.read<T>());
			}
		}
	}

	template <class T>
	T serialization_source::read()
	{
		return detail::read_construct<core::deep_decay_t<T>>(*this, 0);
	}

	template <class T>
	std::unique_ptr<T> serialization_source::read_unique()
	{
		return detail::read_unique<core::deep_decay_t<T>>(*this, 0);
	}

	template <class T>
	void serialization_source::read(T* value)
	{
		serialization_traits<core::deep_decay_t<T>>::deserialize_inplace(*this, value);
	}

	template <class T>
	void serialization_visitor::operator()(T& member)
	{
		if (m_source)
			m_source->read(&member);
		if (m_sink)
			m_sink->write(member);
	}

	template <class T, size_t N>
	void serialization_visitor::operator()(T(&member)[N])
	{
		for (size_t i = 0; i < N; ++i)
			this->operator()(member[i]);
	}

	template <class T>
	void serialization_visitor::trivial(T& member)
	{
		static_assert(!is_trivially_serializable<T>::value,
			"T is already known to be trivally serializable, don't use `trivial`");

		if (m_source)
			detail::serialization_traits_trivial<T>::deserialize_inplace(*m_source, &member);
		if (m_sink)
			detail::serialization_traits_trivial<T>::serialize(*m_sink, member);
	}

	template <class T, size_t N>
	void serialization_visitor::trivial(T(&member)[N])
	{
		for (size_t i = 0; i < N; ++i)
			this->trivial(member[i]);
	}

	template <class T>
	void serialization_visitor::ignore(T& member)
	{
	}

	template <class T>
	void serialization_visitor::write(const T& value)
	{
		if (m_sink)
			m_sink->write(value);
	}

	template <class T>
	T serialization_visitor::read()
	{
		assert(m_source);
		if (!m_source)
			throw serialization_error("tried to read while not deserializing");
		return m_source->read<T>();
	}

	template <class T>
	T serialization_visitor::arg()
	{
		assert(m_source || m_sink);
		return m_source ? m_source->arg<T>() : m_sink->arg<T>();
	}

	template <class T>
	void serialization_visitor::set_arg(T arg)
	{
		assert(m_source || m_sink);
		return m_source ? m_source->set_arg(arg) : m_sink->set_arg(arg);
	}
}