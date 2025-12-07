#pragma once
#include "value_tree.hpp"

#include <charconv>
#include <sstream>
#include <memory>
#include <boost/iterator/iterator_facade.hpp>

#include <tower/core/utility.hpp>

class QString;

namespace core
{
	template <class T>
	value_tree_value<T>::value_tree_value()
	{
		m_error = std::make_pair(value_tree_error(), false);
	}

	template <class T>
	value_tree_value<T>::value_tree_value(T x)
		: m_value(std::move(x))
	{
	}

	template <class T>
	value_tree_value<T>::value_tree_value(value_tree_error error, bool allow_fallback)
	{
		m_error.emplace(std::move(error), allow_fallback);
	}

	template <class T>
	bool value_tree_value<T>::valid() const
	{
		assert(m_error || m_value);
		return !!m_value;
	}

	template <class T>
	value_tree_value<T>::operator bool() const
	{
		return valid();
	}

	template <class T>
	const T& value_tree_value<T>::get() const
	{
		if (!valid())
			throw error();
		return m_value.get();
	}

	template <class T>
	const T& value_tree_value<T>::get(const T& fallback_value) const
	{
		if (!valid())
		{
			bool allow_fallback = m_error->second;
			if (allow_fallback)
				return fallback_value;

			throw error();
		}
		return m_value.get();
	}

	template <class T>
	const value_tree_error& value_tree_value<T>::error() const
	{
		assert(m_error);
		return m_error->first;
	}

	namespace detail
	{
		struct value_tree_filter
		{
			struct predicate_base
			{
				virtual ~predicate_base() = default;
				virtual bool accepts(const value_tree_document* backend, value_tree_document_node node) const = 0;
			};

			enum mode
			{
				named_childs, // iterates all childs with same name
				all_childs, // iterates all childs
			};

			/*explicit*/ value_tree_filter(mode mode = named_childs) : mode(mode) {}

			mode mode;
			std::shared_ptr<const predicate_base> predicate;
		};

		template <class Node>
		class value_tree_range
		{
		public:
			class const_iterator : public boost::iterator_facade<const_iterator, Node, boost::forward_traversal_tag, Node>
			{
			public:
				const_iterator() = default;
				explicit const_iterator(value_tree_document_node node, const value_tree_range* range);

			private:
				Node dereference() const;
				bool equal(const const_iterator& other) const;
				void increment();

				size_t m_index = 0;
				value_tree_document_node m_node = nullptr;

				// always have the next node already prepared, this allows for
				// corner cases like removing nodes while iterating
				size_t m_next_index = 0;
				value_tree_document_node m_next_node = nullptr;
				const value_tree_range* m_range = nullptr;
				friend class boost::iterator_core_access;
			};

			value_tree_range();
			value_tree_range(value_tree_filter filter, value_tree_document* document, value_tree_document_node begin,
				std::string base_path, size_t index, size_t attribute);
			const_iterator begin() const;
			const_iterator end() const;
			bool empty() const;
			size_t size() const;

			template <class OtherNode>
			value_tree_range<OtherNode> convert() &&; // internally used to convert from const to non-const range

		private:
			value_tree_filter m_filter;
			value_tree_document* m_document;
			value_tree_document_node m_begin;
			std::string m_base_path;
			size_t m_index;
			size_t m_attribute;

			friend class const_iterator;
		};

		/// Traits class to convert values to/from string
		/**
			Specialize this class to add support for custom types. Two methods have to be defined:

			to_string, taking a value of type T and returning either std::string or const char*
			from_string, taking a const char* and returning a value_tree_value<T>

			On failure, from_string should return a value_tree_error with empty path.
		*/
		template <class T, class>
		struct value_tree_translator
		{
			static std::string to_string(const T& value)
			{
				std::ostringstream ss;
				ss << value;
				return ss.str();
			}

			static value_tree_value<T> from_string(std::string_view text)
			{
				std::string buf(text);
				std::istringstream ss(buf);
				T x{};
				ss >> x;

				if (ss.fail() || !ss.eof()) // make sure we consumed all characters
				{
					buf = "invalid value '";
					buf.append(text);
					buf.append("'");
					return value_tree_error(std::move(buf), "");
				}

				return x;
			}
		};

		// Trim function for trimming off insignificant whitespaces (e.g. when parsing integers)
		// Increases robustness against weird formatting
		// Should not be used when parsing strings, as whitespaces can have significance there
		inline std::string_view value_tree_trim(std::string_view str)
		{
			while (!str.empty() && strchr(" \t\n\r", str.front()))
				str.remove_prefix(1);
			while (!str.empty() && strchr(" \t\n\r", str.back()))
				str.remove_suffix(1);
			return str;
		}

		// Specialization for arithmetic types for better performance
		template <class T>
		struct value_tree_translator<T, std::enable_if_t<std::is_arithmetic<T>::value>>
		{
			static std::string to_string(const T& value)
			{
				char buffer[128] = "";
				auto result = std::to_chars(std::begin(buffer), std::end(buffer), value);

				return buffer;
			}

			static value_tree_value<T> from_string(std::string_view text)
			{
				text = value_tree_trim(text);

				if (!text.empty())
				{
					T value = 0;
					auto last = text.data() + text.size();
					auto result = std::from_chars(text.data(), last, value);

					// make sure we consumed all characters
					if (result.ptr == last && result.ec == std::errc())
						return value;
				}

				std::string err("invalid value '");
				err.append(text);
				err.append("'");
				return value_tree_error(std::move(err), "");
			}
		};

		template <>
		struct value_tree_translator<bool>
		{
			static const char* to_string(bool value)
			{
				return value ? "true" : "false";
			}

			static value_tree_value<bool> from_string(std::string_view text)
			{
				text = value_tree_trim(text);

				if (text.empty())
					return false;

				if (text == "1" || _strnicmp(text.data(), "true", text.size()) == 0)
					return true;

				return false; // interpret everything else as false
			}
		};

		// specialization to avoid unnecessary conversion of std::string
		template <>
		struct value_tree_translator<std::string>
		{
			static const std::string& to_string(const std::string& value)
			{
				return value;
			}

			static std::string from_string(std::string_view text)
			{
				return std::string{ text };
			}
		};

		// specialization to avoid unnecessary conversion of std::string_view
		template <>
		struct value_tree_translator<std::string_view>
		{
			static std::string to_string(std::string_view value)
			{
				return std::string{ value };
			}

			static std::string_view from_string(const std::string_view& text)
			{
				return text;
			}
		};

		// specialization to support passing nullptr
		template <>
		struct value_tree_translator<nullptr_t>
		{
			static const char* to_string(nullptr_t)
			{
				return nullptr;
			}

			// from_string not supported
		};

		template <>
		struct value_tree_translator<QString>
		{
			static std::string to_string(const QString& value);
			static QString from_string(std::string_view text);
		};

		// functions below are using a thread-local path storage to avoid
		// recurring string allocations in non-error cases
		// (this has been identified to be a performance bottle neck)
		std::string* thread_local_path_storage();
	}


	template <class T>
	value_tree_value<T> const_value_tree_node::value(std::string_view path) const
	{
		auto resolved_path = detail::thread_local_path_storage();
		auto value = query_value(path, resolved_path);

		if (!value)
			return{ value_tree_error("value does not exist", std::move(*resolved_path)), true };

		value_tree_value<T> translate_result = detail::value_tree_translator<T>::from_string(value.get());
		if (!translate_result.valid())
		{
			// conversion failed, take the error message and combine it with the acutal error path
			return{ value_tree_error(translate_result.error().what(), std::move(*resolved_path)), false };
		}

		return translate_result;
	}

	template <class T>
	T const_value_tree_node::get(std::string_view path, const T& fallback_value) const
	{
		auto resolved_path = detail::thread_local_path_storage();
		auto value = query_value(path, resolved_path);

		if (!value)
			return fallback_value;

		value_tree_value<T> translate_result = detail::value_tree_translator<T>::from_string(value.get());
		if (!translate_result.valid())
		{
			// conversion failed, take the error message and combine it with the acutal error path
			throw value_tree_error(translate_result.error().what(), std::move(*resolved_path));
		}

		return translate_result.get();
	}

	template <class T>
	T const_value_tree_node::get(std::string_view path) const
	{
		auto resolved_path = detail::thread_local_path_storage();
		auto value = query_value(path, resolved_path);

		if (!value)
			throw value_tree_error("value does not exist", std::move(*resolved_path));

		value_tree_value<T> translate_result = detail::value_tree_translator<T>::from_string(value.get());
		if (!translate_result.valid())
		{
			// conversion failed, take the error message and combine it with the acutal error path
			throw value_tree_error(translate_result.error().what(), std::move(*resolved_path));
		}

		return translate_result.get();
	}

	namespace detail
	{
		inline const char* c_str(const std::string& str)
		{
			return str.c_str();
		}

		inline const char* c_str(const char* str)
		{
			return str;
		}
	}

	template <class T>
	void value_tree_node::set_value(std::string_view path, const T& value)
	{
		const auto& str = detail::value_tree_translator<T>::to_string(value);
		set_value(path, detail::c_str(str));
	}

	template <class T>
	void value_tree_node::set_value(const T& value)
	{
		set_value({}, value);
	}

	template <class T>
	value_tree_value<T> value_from_string(std::string_view str)
	{
		return detail::value_tree_translator<T>::from_string(str);
	}

	template <class T>
	std::string value_to_string(const T& value)
	{
		return detail::value_tree_translator<T>::to_string(value);
	}
}