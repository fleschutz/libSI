#pragma once
#include "std.hpp"
#include <glm/detail/qualifier.hpp>

/** \file

	Serialization traits for 3rdparty types. Forward declares types as much as possible to avoid
	including all the dependencies right here.
*/

namespace boost
{
	template<class T>
	class optional;

	template <class, class...>
	class variant;
}

namespace core
{
	template <class T>
	struct serialization_traits<boost::optional<T>> : detail::serialization_traits_optional<boost::optional<T>> {};

	template <class... T>
	struct serialization_traits<boost::variant<T...>>
	{
		static void serialize(serialization_sink& sink, const boost::variant<T...>& v)
		{
			auto visitor = [&sink](const auto& value)
			{
				sink.write(value);
			};

			sink.write<int>(v.which());
			apply_visitor(visitor, v);
		}

		template <class Head, class... Tail>
		static void deserialize_inplace(int idx, serialization_source& source, boost::variant<T...>* v)
		{
			if (idx == 0)
			{
				*v = source.read<Head>();
				return;
			}
				
			if constexpr(sizeof...(Tail) == 0)
				throw serialization_error("invalid variant index");
			else
				return deserialize_inplace<Tail...>(idx - 1, source, v);
		}

		static void deserialize_inplace(serialization_source& source, boost::variant<T...>* v)
		{
			auto index = source.read<int>();
			deserialize_inplace<T...>(index, source, v);
		}
	};

	template<glm::length_t L, typename T, glm::qualifier Q>
	struct is_trivially_serializable<glm::vec<L, T, Q>> : std::true_type {};

	template<glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
	struct is_trivially_serializable<glm::mat<C, R, T, Q>> : std::true_type {};

	template<typename T, glm::qualifier Q>
	struct is_trivially_serializable<glm::qua<T, Q>> : std::true_type {};
}