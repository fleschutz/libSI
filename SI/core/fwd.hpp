#pragma once

/** \file
	
	This file contains forward declarations for various core classes.

	Including (only) this header allows you to use core types in pointer declarations or
	as parameters without having to include the full-fledged header containing the complete
	definitions with all its dependencies.

	Usually this fwd.hpp is included in headers, implementation files are using the corresponding
	full includes.
*/

namespace core
{
	class serialization_sink;
	class serialization_source;
	class serialization_visitor;
	class serialization_key {};

	template <class T>
	struct is_trivially_serializable;

	template <class T, class Enable = void>
	struct serialization_traits;

	namespace detail
	{
		template <class T, class = void>
		struct value_tree_translator;
	}
	template <class T>
	class value_tree_value;

	class value_tree_error;

	class value_tree_visitor;
	class const_value_tree_node;
	class value_tree_node;
}