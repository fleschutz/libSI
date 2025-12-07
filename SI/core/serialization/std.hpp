#pragma once
#include "core.hpp"

#include <array>
#include <optional>
#include <memory>
#include <variant>

/** \file

	Serialization traits for more std types and additional serialization utilities.

	Note that forward declaring std types is undefined behavior, therefore we have to include all
	the std headers right here.
*/

namespace core
{
	/// Deserializes from a base64 string
	class serialization_base64_source final : public serialization_source
	{
	public:
		explicit serialization_base64_source(std::string_view str);
		void read_bytes(void* dst, size_t bytes) override;
		size_t available_bytes() const override;

	private:
		std::string_view m_str;
		unsigned char m_buffer[3];
		unsigned char m_buffer_count;
	};

	/// Serializes to a base64 string
	/**
		'finish' has to be called after the last serialization and before the string is obtained
		so that all characters and padding can be flushed to the ostream.
	*/
	class serialization_base64_sink final : public serialization_sink
	{
	public:
		explicit serialization_base64_sink(std::ostream* os);
		~serialization_base64_sink();

		serialization_base64_sink(const serialization_base64_sink&) = delete;
		serialization_base64_sink& operator=(const serialization_base64_sink&) = delete;

		void write_bytes(const void* data, size_t bytes) override;
		void finish();

	private:
		std::ostream* m_os;
		unsigned char m_buffer[3];
		unsigned char m_buffer_count;
	};

	template <class T, size_t N>
	struct serialization_traits<std::array<T, N>>
	{
		static void serialize(serialization_sink& sink, const std::array<T, N>& arr)
		{
			if constexpr (is_trivially_serializable<T>::value)
			{
				sink.write_bytes(arr.data(), N * sizeof(T));
			}
			else
			{
				for (const auto& x : arr)
					sink.write(x);
			}
		}

		static void deserialize_inplace(serialization_source& source, std::array<T, N>* arr)
		{
			if constexpr (is_trivially_serializable<T>::value)
			{
				source.read_bytes(arr->data(), N * sizeof(T));
			}
			else
			{
				for (auto& x : *arr)
					source.read(&x);
			}
		}
	};

	namespace detail
	{
		template <class Optional>
		struct serialization_traits_optional
		{
			static void serialize(serialization_sink& sink, const Optional& o)
			{
				if (o)
				{
					sink.write(true);
					sink.write(*o);
				}
				else
				{
					sink.write(false);
				}
			}

			static void deserialize_inplace(serialization_source& source, Optional* o)
			{
				if (source.read<bool>())
				{
					if (*o)
						source.read(&**o);
					else
						*o = source.read<typename Optional::value_type>();
				}
				else
				{
					o->reset();
				}
			}
		};
	}

	template <class T>
	struct serialization_traits<std::optional<T>> : detail::serialization_traits_optional<std::optional<T>> {};

	template <class T>
	struct serialization_traits<std::unique_ptr<T>> : detail::serialization_traits_optional<std::unique_ptr<T>>
	{
		static void deserialize_inplace(serialization_source& source, std::unique_ptr<T>* ptr)
		{
			if (source.read<bool>())
			{
				if (*ptr)
					source.read(ptr->get());
				else
					*ptr = source.read_unique<T>();
			}
			else
			{
				ptr->reset();
			}
		}
	};

	template <class... T>
	struct serialization_traits<std::tuple<T...>>
	{
		template<std::size_t... I>
		static void serialize(serialization_sink& sink, const std::tuple<T...>& t, std::index_sequence<I...>)
		{
			(sink.write(std::get<I>(t)), ...);
		}

		static void serialize(serialization_sink& sink, const std::tuple<T...>& t)
		{
			serialize(sink, t, std::index_sequence_for<T...>());
		}

		template<std::size_t... I>
		static void deserialize_inplace(serialization_source& source, std::tuple<T...>* t, std::index_sequence<I...>)
		{
			(source.read(&std::get<I>(*t)), ...);
		}

		static void deserialize_inplace(serialization_source& source, std::tuple<T...>* t)
		{
			deserialize_inplace(source, t, std::index_sequence_for<T...>());
		}

		static std::tuple<T...> deserialize(serialization_source& source)
		{
			return { source.read<T>()... };
		}
	};

	template <class... T>
	struct serialization_traits<std::variant<T...>>
	{
		static void serialize(serialization_sink& sink, const std::variant<T...>& v)
		{
			auto visitor = [&sink](const auto& value)
			{
				sink.write(value);
			};

			sink.write<int>(v.index());
			visit(visitor, v);
		}

		template <size_t N>
		static void deserialize_inplace(int idx, serialization_source& source, std::variant<T...>* v)
		{
			if (idx != N)
				return deserialize_inplace<N + 1>(idx, source, v);

			*v = source.read<std::variant_alternative_t<N, std::variant<T...>>>();
		}

		template <>
		static void deserialize_inplace<sizeof...(T)>(int, serialization_source&, std::variant<T...>*)
		{
			throw serialization_error("invalid variant index");
		}

		static void deserialize_inplace(serialization_source& source, std::variant<T...>* v)
		{
			auto index = source.read<int>();
			deserialize_inplace<0>(index, source, v);
		}
	};
}