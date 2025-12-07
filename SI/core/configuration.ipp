#pragma once
#include "configuration.hpp"

#include <mxml/mxml.h>
#include <boost/lexical_cast/try_lexical_convert.hpp>

namespace configuration {

	namespace detail {
		/// String casting
		template<typename T>
		boost::optional<T> lexical_cast(...); // this one gets selected if nothing else matched (and triggers a compile error)

		template<typename T>
		boost::optional<std::string> lexical_cast(boost::optional<T> arg)
		{
			if (!arg)
				return boost::none;

			std::string result;
			if (boost::conversion::try_lexical_convert(*arg, result))
				return result;

			return boost::none;
		}

		// lexical_cast for all integer types
		template <typename T>
		typename boost::enable_if<boost::is_integral<T>, boost::optional<T> >::type
		lexical_cast(const char* arg) {
			if (!arg) // handling NULL here simplifies some things
				return boost::none;

			char* endptr = NULL;
			long i = strtol(arg, &endptr, 0); // base 0 allows 123, 0x123, 0123
			if (endptr == arg)
				return boost::none;

			return static_cast<T>(i);
		}

		// lexical_cast for all floating types
		template <typename T>
		typename boost::enable_if<boost::is_floating_point<T>, boost::optional<T> >::type
		lexical_cast(const char* arg) {
			if (!arg)
				return boost::none;

			char* endptr = NULL;
			double f = strtod(arg, &endptr);
			if (endptr == arg)
				return boost::none;

			return static_cast<T>(f);
		}

		template<>
		boost::optional<bool> lexical_cast<bool>(const char* arg);
	}

	template <typename T>
	template <typename U>
	bool node::bidirectional_iterator<T>::equal(bidirectional_iterator<U> const & other) const
	{
		return this->_current._xml_node == other._current._xml_node;
	}

	template <typename T>
	typename translator<T>::result_type node::attr(const char* name) const {
		assert(_xml_node);
		boost::optional<typename translator<T>::result_type> result = translator<T>::translate(*this, name);
		if (!result)
		{
			// TODO: error
		}

		return *result;
	}

	template<typename T>
	typename translator<T>::result_type node::attr(const char* name, T const & defaultValue) const {
		assert(_xml_node);
		boost::optional<typename translator<T>::result_type> result = translator<T>::translate(*this, name);
		if (!result)
		{
			return defaultValue;
		}

		return *result;
	}

	template <typename T>
	typename translator<T>::result_type node::get() const {
		assert(_xml_node);
		boost::optional<typename translator<T>::result_type> result = translator<T>::translate(*this, NULL);
		if (!result)
		{
			// TODO: error
		}

		return *result;
	}

	template<typename T>
	typename translator<T>::result_type node::get(T const & defaultValue) const {
		assert(_xml_node);
		boost::optional<typename translator<T>::result_type> result = translator<T>::translate(*this, NULL);
		if (!result)
		{
			return defaultValue;
		}

		return *result;
	}

	template<typename T>
	typename translator<T>::result_type node::get(const char* path, T const & defaultValue) const {
		const_iterator n = find(path);

		if (n == end()) {
			return defaultValue;
		}

		return n->get(defaultValue);
	}

	template<typename T>
	typename translator<T>::result_type store::get(const char* path, T const & defaultValue) const {
		return _root.get<T>(path, defaultValue);
	}

	template<typename T>
	void node::set(const T& val, const char* attribute /*= nullptr*/)
	{
		auto res = translator<T>::translateFwd(val);
		if (res)
		{
			if (attribute == nullptr)
			{
				// check if there is already a text - needs to be replaced.
				if (text())
					mxmlDelete(mxmlGetFirstChild(_xml_node));
				mxmlNewOpaque(_xml_node, (*res).c_str());
			}
			else
			{
				mxmlElementSetAttr(_xml_node, attribute, (*res).c_str());
			}
		}
	}

	template <typename T>
	boost::optional<T> translator<T>::translate(node const & n, const char* attribute_name) {
		return detail::lexical_cast<T>(attribute_name ? n.attr(attribute_name) : n.text());
	}
	
	template <typename T>
	boost::optional<std::string> translator<T>::translateFwd(boost::optional<result_type> value)
	{
		return detail::lexical_cast(value);
	}


#ifdef CONFIGURATION_ENABLE_GLM_TYPES
	template <typename T, glm::precision P>
	boost::optional< glm::vec<2, T, P> > translator< glm::vec<2, T, P> >::translate(node const & n, const char* attribute_name) {
		boost::optional<T> x;
		boost::optional<T> y;

		if (attribute_name) {
			// combine the vec out of three attributes, using attribute_name as prefix
			std::string str = attribute_name;
			x = translator<T>::translate(n, (str + "X").c_str());
			y = translator<T>::translate(n, (str + "Y").c_str());
		}
		else {
			// combine the vec out of three attributes
			// this is a inconsistency; we should read text and not attributes (or disallow this one)
			x = translator<T>::translate(n, "x");
			y = translator<T>::translate(n, "y");
		}

		if (x && y)
			return glm::vec<2, T, P>(*x, *y);

		return boost::none;
	}
#endif

}