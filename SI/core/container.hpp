#pragma once
#include <boost/container/small_vector.hpp>
#include <boost/container/vector.hpp>
#include <boost/container/map.hpp>
#include <tower/core/serialization/core.hpp>

namespace core
{
	namespace detail
	{
		template <class T>
		struct small_count
		{
			static const size_t value = 1 + 5 * sizeof(int) / sizeof(T);
		};
	}

	using boost::container::vector;
	using boost::container::map;

	template <class T, size_t N = detail::small_count<T>::value>
	class small_vector : public boost::container::small_vector<T, N>
	{
	public:
		typedef boost::container::small_vector<T, N> base_type;

		small_vector()
		{
		}

		// to catch unintentional (expensive) copies
		//small_vector(const small_vector&) = delete;
		//small_vector& operator=(const small_vector&) = delete;
		small_vector(const small_vector&) = default;
		small_vector& operator=(const small_vector&) = default;

		small_vector(small_vector&& rhs) : base_type(std::move(rhs))
		{
		}

		small_vector& operator=(small_vector&& rhs)
		{
			base_type::operator=(std::move(rhs));
			return *this;
		}

		~small_vector() = default;		
	};

	template <class T, size_t N>
	struct serialization_traits<small_vector<T, N>> : detail::serialization_traits_vector<T> {};
}