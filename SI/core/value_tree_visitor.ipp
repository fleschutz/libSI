#pragma once
#include "value_tree_visitor.hpp"

#include <array>
#include <type_traits>
#include <memory>
#include <utility>

namespace core
{
	namespace detail
	{
		// calls object.operator()(visitor) if possible
		template <class T>
		auto accept(T& object, const value_tree_visitor& visitor) -> decltype(object.operator()(visitor))
		{
			return object.operator()(visitor);
		}

		template <class T>
		struct value_tree_visitor_create
		{
			static T create()
			{
				return T{};
			}
		};

		template <class First, class Second>
		struct value_tree_visitor_create<std::pair<First, Second> >
		{
			typedef typename std::remove_cv<First>::type first_type;
			typedef typename std::remove_cv<Second>::type second_type;
			static std::pair<first_type, second_type> create()
			{
				std::pair<first_type, second_type> pair;
				return pair;
			}
		};

		std::false_type accepts_value_tree_visitor_sfinae(...);
		template <class T>
		auto accepts_value_tree_visitor_sfinae(T* obj) -> decltype(accept(*obj, std::declval<value_tree_visitor>()), std::true_type());

		// true if accept(object, visitor) is a valid call
		template <class T>
		struct accepts_value_tree_visitor : decltype(accepts_value_tree_visitor_sfinae(static_cast<T*>(nullptr)))
		{
		};

		// default traits for types accepting the visitor
		template <class T, bool AcceptsVisitor>
		struct value_tree_visitor_traits_default
		{
			static void read_value(const const_value_tree_node& node, T& out)
			{
				read(node, out);
			}

			template <class U>
			static void read_value(const const_value_tree_node& node, T& out, U&& fallback_value)
			{
				if (node.exists())
					read(node, out);
				else
					out = std::forward<U>(fallback_value);
			}

			static void write_value(value_tree_node& node, const T& value)
			{
				write(value, node);
			}
		};

		// default traits for types not accepting the visitor
		template <class T>
		struct value_tree_visitor_traits_default<T, false>
		{
			static void read_value(const const_value_tree_node& node, T& out)
			{
				out = node.value<T>().get();
			}

			template <class U>
			static void read_value(const const_value_tree_node& node, T& out, U&& fallback_value)
			{
				out = node.value<T>().get(std::forward<U>(fallback_value));
			}

			static void write_value(value_tree_node& node, const T& value)
			{
				node.set_value(value);
			}
		};

		/// This traits determine how a type T is read/written
		/**
			Specialize this type to add support for custom member types
			A trait must support read_value, read_value with fallback and write_value
		*/
		template <class T>
		struct value_tree_visitor_traits : value_tree_visitor_traits_default<T, accepts_value_tree_visitor<T>::value>
		{
		};

		template <class T>
		struct value_tree_visitor_traits<std::unique_ptr<T>>
		{
			typedef value_tree_visitor_traits<T> value_traits;

			static void read_value(const const_value_tree_node& node, std::unique_ptr<T>& out)
			{
				if (!node.empty()) // throws if not existent
				{
					if (!out)
						out = std::make_unique<T>();
					value_traits::read_value(node, *out);
				}
				else
				{
					out.reset();
				}
			}

			template <class U>
			static void read_value(const const_value_tree_node& node, std::unique_ptr<T>& out, U fallback_value)
			{
				if (!node.exists())
				{
					out = std::move(fallback_value);
					return;
				}

				read_value(node, out);
			}

			static void write_value(value_tree_node& node, const std::unique_ptr<T>& value)
			{
				if (value)
					value_traits::write_value(node, *value);
				else
					node.set_value(""); // bring the node into existence, but leave it empty
			}
		};

		template <class Optional, class Value>
		struct value_tree_visitor_traits_optional
		{
			typedef value_tree_visitor_traits<Value> value_traits;

			static void read_value(const const_value_tree_node& node, Optional& out)
			{
				if (node.exists())
				{
					if (!out)
						out = value_tree_visitor_create<Value>::create();
					value_traits::read_value(node, *out);
				}
				else
				{
					out.reset();
				}
			}

			template <class U>
			static void read_value(const const_value_tree_node& node, Optional& out, U&& fallback_value)
			{
				if (node.exists())
				{
					if (!out)
						out = value_tree_visitor_create<Value>::create();
					value_traits::read_value(node, *out);
				}
				else
				{
					out = std::forward<U>(fallback_value);
				}
			}

			static void write_value(value_tree_node& node, const Optional& value)
			{
				if (value)
				{
					value_traits::write_value(node, *value);
				}
				else
				{
					node.set_value(nullptr); // remove attribute (TODO: what about optionals stored in nodes?)
				}
			}
		};

		template <class T>
		struct value_tree_visitor_traits<boost::optional<T>> : value_tree_visitor_traits_optional<boost::optional<T>, T>
		{
		};

		template <class T>
		struct value_tree_visitor_traits<std::optional<T>> : value_tree_visitor_traits_optional<std::optional<T>, T>
		{
		};

		template <class T>
		struct value_tree_visitor_optional_traits
		{
			typedef T value_type;
			static const bool is_optional = false;
			static void reset(T&) {}
			static T& get(T& x) { return x; } // NOLINT(attower-naming)
			static bool is_initialized(T&) { return true; }
		};

		template <class T>
		struct value_tree_visitor_optional_traits<boost::optional<T>>
		{
			typedef T value_type;
			static const bool is_optional = true;
			static void reset(boost::optional<T>& x) { x.reset(); }
			static T& get(boost::optional<T>& x) { return x.get(); }
			static bool is_initialized(boost::optional<T>& x) { return !!x; }
		};

		template <class T>
		struct value_tree_visitor_optional_traits<std::optional<T>>
		{
			typedef T value_type;
			static const bool is_optional = true;
			static void reset(std::optional<T>& x) { x.reset(); }
			static T& get(std::optional<T>& x) { return x.value(); }
			static bool is_initialized(std::optional<T>& x) { return !!x; }
		};

		template <class First, class Second>
		struct value_tree_visitor_traits<std::pair<First, Second>>
		{
			typedef std::pair<First, Second> original_type;

			typedef typename std::remove_cv<First>::type first_type;
			typedef typename std::remove_cv<Second>::type second_type;
			typedef value_tree_visitor_traits<first_type> traits_first;
			typedef value_tree_visitor_traits<second_type> traits_second;

			typedef std::pair<first_type, second_type> mutable_type;

			static const bool use_attributes = std::is_base_of<value_tree_visitor_traits_default<first_type, false>, traits_first>::value &&
				std::is_base_of<value_tree_visitor_traits_default<second_type, false>, traits_second>::value;

			static void read_value(const const_value_tree_node& node, mutable_type& out)
			{
				if (use_attributes)
				{
					traits_first::read_value(node.node("@first"), out.first);
					traits_second::read_value(node.node("@second"), out.second);
				}
				else
				{
					traits_first::read_value(node.node("first"), out.first);
					traits_second::read_value(node.node("second"), out.second);
				}
			}

			template <class U>
			static void read_value(const const_value_tree_node& node, mutable_type& out, U&& fallback_value)
			{
				if (!node.exists())
				{
					out = std::forward<U>(fallback_value);
					return;
				}

				read_value(node, out);
			}

			static void write_value(value_tree_node& node, const original_type& value)
			{
				const char* first_path = "@first";
				const char* second_path = "@second";
				if (!use_attributes)
				{
					++first_path;
					++second_path;
				}

				auto first_node = node.node(first_path);
				auto second_node = node.node(second_path);
				traits_first::write_value(first_node, value.first);
				traits_second::write_value(second_node, value.second);
			}
		};

		template <size_t N>
		struct value_tree_visitor_traits<char[N]>
		{
			static void read_value(const const_value_tree_node& node, char* out)
			{
				read_value(node, out, nullptr);
			}

			static void read_value(const const_value_tree_node& node, char* out, const char* fallback)
			{
				std::string str;
				if (fallback)
					value_tree_visitor_traits<std::string>::read_value(node, str, fallback);
				else
					value_tree_visitor_traits<std::string>::read_value(node, str);

				if (str.size() + 1 > N)
					throw value_tree_error("string exceeds maximum length", node.path());

				strcpy_s(out, N, str.c_str());
			}

			static void write_value(value_tree_node& node, const char* value)
			{
				node.set_value(value);
			}
		};
	}

	inline value_tree_visitor value_tree_visitor::node(const char* path)
	{
		if (reading())
		{
			return value_tree_visitor(m_read_node->node(path));
		}
		else
		{
			return value_tree_visitor(m_write_node->node(path));
		}
	}

	inline const const_value_tree_node& value_tree_visitor::read_node()
	{
		assert(reading());
		return *m_read_node;
	}

	inline const value_tree_node& value_tree_visitor::write_node()
	{
		assert(writing());
		return *m_write_node;
	}

	inline bool value_tree_visitor::reading() const
	{
		return !!m_read_node;
	}

	inline bool value_tree_visitor::writing() const
	{
		return !!m_write_node;
	}

	template <class T>
	void value_tree_visitor::operator()(const char* path, T& x)
	{
		typedef detail::value_tree_visitor_traits<T> traits;

		if (reading())
		{
			traits::read_value(m_read_node->node(path), x);
		}
		else if (writing())
		{
			auto node = m_write_node->node(path);
			// add const again to make sure traits are not messing things up
			traits::write_value(node, static_cast<const T&>(x));
		}
	}

	template <class T, class U>
	void value_tree_visitor::operator()(const char* path, T& x, U&& fallback_value)
	{
		typedef detail::value_tree_visitor_traits<T> traits;

		if (reading())
		{
			traits::read_value(m_read_node->node(path), x, std::forward<U>(fallback_value));
		}
		else if (writing())
		{
			auto node = m_write_node->node(path);
			// add const again to make sure traits are not messing things up
			traits::write_value(node, static_cast<const T&>(x));
		}
	}

	template <class Collection, class Factory>
	void value_tree_visitor::collection(const char* path, const char* items, Collection& collection, Factory factory)
	{
		if (reading())
		{
			read_collection(m_read_node->node(path), items, collection, factory);
		}
		else if (writing())
		{
			write_collection(collection, m_write_node->node(path), items);
		}
	}

	template <class Collection, class Factory>
	void value_tree_visitor::collection(const char* path, const char* items, Collection& collection, const Collection& fallback_collection, Factory factory)
	{
		if (reading())
		{
			auto node = m_read_node->node(path);
			if (!node.exists())
			{
				collection = fallback_collection;
				return;
			}

			read_collection(node, items, collection, factory);
		}
		else if (writing())
		{
			write_collection(collection, m_write_node->node(path), items);
		}
	}

	namespace detail
	{
		template <size_t Idx, class Array>
		void value_tree_enum_table_set(Array&)
		{
		}

		template <size_t Idx, class Array, class Enum, class... Tail>
		void value_tree_enum_table_set(Array& array, Enum e, const char* str, Tail... tail)
		{
			array[Idx].first = e;
			array[Idx].second = str;
			value_tree_enum_table_set<Idx + 1>(array, tail...);
		}

		template <class Fallback, class Enum, class... Tail>
		auto value_tree_create_enum_table(std::true_type, Fallback, Enum e, const char* name, Tail... tail)
		{
			std::array<std::pair<Enum, const char*>, 1 + sizeof...(Tail) / 2> array;
			value_tree_enum_table_set<0>(array, e, name, tail...);
			return array;
		}

		template <class Enum, class... Tail>
		auto value_tree_create_enum_table(std::false_type, Enum e, const char* name, Tail... tail)
		{
			std::array<std::pair<Enum, const char*>, 1 + sizeof...(Tail) / 2> array;
			value_tree_enum_table_set<0>(array, e, name, tail...);
			return array;
		}

		template <class Enum, class Fallback, class Tail>
		void value_tree_set_enum_fallback(Enum& x, Fallback fallback, Tail...)
		{
			x = fallback;
		}
	}

	template <class Enum, class... EnumTable>
	void value_tree_visitor::enumeration(const char* path, Enum& x, EnumTable... table)
	{
		typedef detail::value_tree_visitor_optional_traits<Enum> optional_traits;

		static const bool HasFallback = (sizeof...(table) % 2 != 0);
		const auto array = detail::value_tree_create_enum_table(std::integral_constant<bool, HasFallback>(), table...);

		if (reading())
		{
			auto node = m_read_node->node(path);

			if (!node.exists())
			{
				if (HasFallback)
				{
					detail::value_tree_set_enum_fallback(x, table...);
					return;
				}

				if (optional_traits::is_optional)
				{
					optional_traits::reset(x);
					return;
				}				
	
				// keep going, value().get() will throw the correct exception
			}

			std::string str = node.value().get();
			
			for (const auto& entry : array)
			{
				if (_stricmp(str.c_str(), entry.second) == 0)
				{
					x = entry.first;
					return;
				}
			}

			throw value_tree_error("invalid enumeration value '" + str + "'", node.path());
		}

		if (writing())
		{
			if (optional_traits::is_initialized(x))
			{
				for (const auto& entry : array)
				{
					if (optional_traits::get(x) == entry.first)
					{
						m_write_node->set_value(path, entry.second);
						return;
					}
				}

				assert(!"unknown enum value");
			}
		}
	}

	template <class Member, class Unit>
	void value_tree_visitor::si(const char* path, Member& m, const Unit& unit)
	{
		typedef detail::value_tree_visitor_optional_traits<Member> optional_traits;

		typedef typename optional_traits::value_type::value_type value_type;

		if (reading())
		{
			auto node = m_read_node->node(path);

			if (!node.exists())
			{
				if (optional_traits::is_optional)
				{
					optional_traits::reset(m);
					return;
				}

				// keep going, value().get() will throw the correct exception
			}

			value_type value = node.value<value_type>().get();
			m = unit(value);
		}
		else if (writing())
		{
			if (optional_traits::is_initialized(m))
			{
				value_type value = unit(optional_traits::get(m));
				m_write_node->set_value(path, value);
			}
		}
	}

	template <class Member, class Unit, class Fallback>
	void value_tree_visitor::si(const char* path, Member& m, const Unit& unit, Fallback&& fallback)
	{
		typedef detail::value_tree_visitor_optional_traits<Member> optional_traits;

		typedef typename optional_traits::value_type::value_type value_type;

		if (reading())
		{
			auto node = m_read_node->node(path);

			if (!node.exists())
			{
				m = std::forward<Fallback>(fallback);
				return;
			}

			value_type value = node.value<value_type>().get();
			m = unit(value);
		}
		else if (writing())
		{
			if (optional_traits::is_initialized(m))
			{
				value_type value = unit(optional_traits::get(m));
				m_write_node->set_value(path, value);
			}
		}
	}

	template <class Member, class Read, class Write>
	void value_tree_visitor::custom(const char* path, Member& m, Read read, Write write)
	{
		typedef detail::value_tree_visitor_optional_traits<Member> optional_traits;

		if (reading())
		{
			auto node = m_read_node->node(path);

			if (!node.exists())
			{
				if (optional_traits::is_optional)
				{
					optional_traits::reset(m);
					return;
				}

				// keep going, value().get() will throw the correct exception
			}

			m = read(node.value().get());
		}
		else if (writing())
		{
			if (optional_traits::is_initialized(m))
			{
				m_write_node->set_value(path, write(optional_traits::get(m)));
			}
		}
	}

	template <class Member, class Read, class Write, class Fallback>
	void value_tree_visitor::custom(const char* path, Member& m, Read read, Write write, Fallback&& fallback)
	{
		typedef detail::value_tree_visitor_optional_traits<Member> optional_traits;

		if (reading())
		{
			auto node = m_read_node->node(path);

			if (!node.exists())
			{
				m = std::forward<Fallback>(fallback);
				return;
			}

			m = read(node.value().get());
		}
		else if (writing())
		{
			if (optional_traits::is_initialized(m))
			{
				m_write_node->set_value(path, write(optional_traits::get(m)));
			}
		}
	}

	inline value_tree_visitor::value_tree_visitor(value_tree_node node)
		: m_write_node(std::move(node))
	{
	}

	inline value_tree_visitor::value_tree_visitor(const_value_tree_node node)
		: m_read_node(std::move(node))
	{
	}

	template <class T>
	void read(const_value_tree_node from, T& to)
	{
		static_assert(detail::accepts_value_tree_visitor<T>::value, "T does not accept the value_tree_visitor");

		using detail::accept;
		accept(to, value_tree_visitor{ std::move(from) });
	}

	template <class T>
	void write(const T& from, value_tree_node to)
	{
		static_assert(detail::accepts_value_tree_visitor<T>::value, "T does not accept the value_tree_visitor");

		using detail::accept;
		accept(const_cast<T&>(from), value_tree_visitor{ std::move(to) });
	}

	namespace detail
	{
		template <class T>
		auto value_tree_collection_create(value_tree_noop) -> decltype(value_tree_visitor_create<T>::create())
		{
			return value_tree_visitor_create<T>::create();
		}

		template <class T, class Factory>
		auto value_tree_collection_create(Factory factory) -> decltype(factory())
		{
			return factory();
		}
	}

	template <class Collection, class Factory>
	void read_collection(const const_value_tree_node& from, const char* items, Collection& to, Factory factory)
	{
		typedef typename Collection::value_type value_type;
		typedef detail::value_tree_visitor_traits<value_type> value_traits;

		from.empty(); // use call to empty to throw exception if node is missing
		to.clear();

		for (const auto& node : from.range(items))
		{
			auto value = detail::value_tree_collection_create<value_type>(factory);
			value_traits::read_value(node, value);
			to.insert(to.end(), std::move(value)); // works with every std container
		}
	}

	template <class Collection>
	void write_collection(const Collection& from, value_tree_node to, const char* items)
	{
		typedef typename Collection::value_type value_type;
		typedef detail::value_tree_visitor_traits<value_type> value_traits;

		if (from.begin() == from.end())
			to.set_value(""); // bring the node into existence, but leave it empty

		for (const auto& value : from)
		{
			auto node = to.add_node(items);
			value_traits::write_value(node, value);
		}
	}
}