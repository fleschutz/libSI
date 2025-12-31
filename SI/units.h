// SI/units.h - defines type-safe SI units
#pragma once

#include <type_traits>
#include <limits>
#include <utility>
#include <cmath>
#include <algorithm>
#include <charconv>
#include "internal.h"
#define SI_INLINE inline 
#define SI_INLINE_CONSTEXPR constexpr SI_INLINE

namespace SI
{
	typedef double_t quantity; // datatype to hold a dimensionless value (without any unit), e.g. 42

	namespace detail
	{
		template <class T>
		using vec2 = internal::vec2<T>;

		template <class T>
		using vec3 = internal::vec3<T>;

		// Dimension of a physical quantity
		/*
			Every physical quantity has a dimension which is specified by it's dimensional exponents.
			Examples:
			- velocity is length per time or length^1/time^1, so the exponents for velocity are Length=1,
			  Mass=0, Time=-1, Temp=0, Angle=0
			- force is mass times acceleration which is mass^1*length^1/time^2, so the exponents are
			  Length=1, Mass=1, Time=-2, Temp=0, Angle=0

			This template converts this concept into a C++ type.
			In order to add a new exponent one has to update the three templates dimension, value_dimension and SI_DIMENSION_OP
		*/
		template <long Length, long Mass, long Time, long Temperature, long Angle>
		struct dimension
		{
			static constexpr long length = Length;
			static constexpr long mass = Mass;
			static constexpr long time = Time;
			static constexpr long temperature = Temperature;
			static constexpr long angle = Angle;
		};

		template <long Value>
		using value_dimension = dimension<Value, Value, Value, Value, Value>;

		using dimensionless = value_dimension<0>; // zero dimensions

		template <class, class>
		struct quantity;
		template <class, class>
		struct unit;

		template <class T>
		struct dimension_of
		{
			using type = dimensionless;
		};

		template <long Length, long Mass, long Time, long Temperature, long Angle>
		struct dimension_of<dimension<Length, Mass, Time, Temperature, Angle>>
		{
			using type = dimension<Length, Mass, Time, Temperature, Angle>;
		};

		template <class Dimension, class T>
		struct dimension_of<quantity<Dimension, T>>
		{
			using type = Dimension;
		};

		template <class Dimension, class Ratio>
		struct dimension_of<unit<Dimension, Ratio>>
		{
			using type = Dimension;
		};

		// Resolves to the dimension of anything that might have a dimension (types with no dimension end up with dimensionless)
		template <class T>
		using dimension_of_t = typename dimension_of<std::decay_t<T>>::type;

		// Checks whether the given type is/has dimensionless
		template <class T>
		SI_INLINE_CONSTEXPR bool is_dimensionless_v = std::is_same_v<dimensionless, dimension_of_t<T>>;

#define SI_DIMENSION_OP(op_) dimension<				\
			Lhs::length op_ Rhs::length,		\
			Lhs::mass op_ Rhs::mass,		\
			Lhs::time op_ Rhs::time,		\
			Lhs::temperature op_ Rhs::temperature,	\
			Lhs::angle op_ Rhs::angle >

		template <class Lhs, class Rhs> using dimension_add_impl = SI_DIMENSION_OP(+);
		template <class Lhs, class Rhs> using dimension_subtract_impl = SI_DIMENSION_OP(-);
		template <class Lhs, class Rhs> using dimension_multiply_impl = SI_DIMENSION_OP(*);
		template <class Lhs, class Rhs> using dimension_divide_impl = SI_DIMENSION_OP(/);

		template <class Lhs, class Rhs> using dimension_add = dimension_add_impl <dimension_of_t<Lhs>, dimension_of_t<Rhs>>;
		template <class Lhs, class Rhs> using dimension_subtract = dimension_subtract_impl <dimension_of_t<Lhs>, dimension_of_t<Rhs>>;
		template <class Lhs, class Rhs> using dimension_multiply = dimension_multiply_impl <dimension_of_t<Lhs>, dimension_of_t<Rhs>>;
		template <class Lhs, class Rhs> using dimension_divide = dimension_divide_impl <dimension_of_t<Lhs>, dimension_of_t<Rhs>>;

#undef SI_DIMENSION_OP

		struct zero_t {};

		template <class T> struct scalar_value_type { using type = T; };
		template <> struct scalar_value_type<zero_t> { using type = int; };
		template <class Dimension, class T> struct scalar_value_type<quantity<Dimension, T>> { using type = typename scalar_value_type<T>::type; };

		template <class T>
		using scalar_value_type_t = typename scalar_value_type<T>::type;

		// Storage for plain arithmetic types (float, double, int, ...)
		template <class Dimension, class T>
		class quantity_storage
		{
		public:
			SI_INLINE_CONSTEXPR quantity_storage()
				: m_value(0)
			{}

			SI_INLINE_CONSTEXPR explicit operator bool() const
			{
				return static_cast<bool>(m_value);
			}

		private:
			T m_value;

			friend SI_INLINE_CONSTEXPR const T& value(const quantity_storage& x)
			{
				return x.m_value;
			}

			friend SI_INLINE_CONSTEXPR T& value(quantity_storage& x)
			{
				return x.m_value;
			}
		};

		// Helper function for filling all components of either a scalar or a vector to a given value
		template <class T>
		SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T>> fill(T& x, T value)
		{
			x = value;
		}

		template <class Dimension, class T>
		struct quantity final : quantity_storage<Dimension, T>
		{
			// Make sure we are not creating quantities with dimensionless (dimensionlesss should be plain arithmetic types)
			static_assert(!is_dimensionless_v<Dimension>);

			using value_type = T;
			using dimension_type = Dimension;

			SI_INLINE_CONSTEXPR quantity(zero_t = {}) // NOLINT(google-explicit-constructor)
			{
			}

			SI_INLINE_CONSTEXPR quantity(Dimension, const T& x)
			{
				value(*this) = x;
			}

			template <class U>
			SI_INLINE_CONSTEXPR quantity(const quantity<Dimension, U>& q) // NOLINT(google-explicit-constructor)
			{
				value(*this) = value(q);
			}

			static SI_INLINE_CONSTEXPR quantity<Dimension, T> infinity()
			{
				using scalar_type = scalar_value_type_t<T>;
				static_assert(std::is_floating_point_v<scalar_type>);
				T value = {};
				fill(value, std::numeric_limits<scalar_type>::infinity());
				return { Dimension(), value };
			}

			static SI_INLINE_CONSTEXPR quantity<Dimension, T> NaN()
			{
				using scalar_type = scalar_value_type_t<T>;
				static_assert(std::is_floating_point_v<scalar_type>);
				T value = {};
				fill(value, std::numeric_limits<scalar_type>::quiet_NaN());
				return { Dimension(), value };
			}
		};

		template <class T>
		struct is_si : std::bool_constant<false> {};

		template <class Dimension, class T>
		struct is_si<quantity<Dimension, T> > : std::bool_constant<true> {};

		template <>
		struct is_si<zero_t> : std::bool_constant<true> {};

		// Checks wheter the given type is a si type
		template <class T>
		SI_INLINE_CONSTEXPR bool is_si_v = is_si<T>::value;

		// Fallback value for any plain type, simply returns the value as-is
		template <class T, class = std::enable_if_t<!is_si_v<T>>>
		SI_INLINE_CONSTEXPR const T& value(const T& x)
		{
			return x;
		}

		SI_INLINE_CONSTEXPR long value(zero_t)
		{
			return 0;
		}

		// Helper function for arithmetic functions with two arguments, returns the value of the first argument but uses
		// the second argument to deduce the returned type in case of si::zero
		template <class T, class U>
		SI_INLINE_CONSTEXPR decltype(auto) value2(T&& x, U)
		{
			return value(std::forward<T>(x));
		}

		template <class U>
		SI_INLINE_CONSTEXPR auto value2(zero_t, const U& other)
		{
			// Return zero of the given other type (i.e. return vec2() instead of plain 0)
			return decltype(value(other)){};
		}

		// Checks wheter two types have compatible dimensions (zero is compatible with everything)
		template <class Lhs, class Rhs>
		SI_INLINE_CONSTEXPR bool has_common_dimension_v = 
			std::is_same_v<dimension_of_t<Lhs>, dimension_of_t<Rhs>> || std::is_same_v<Lhs, zero_t> || std::is_same_v<Rhs, zero_t>;

		template <class Lhs, class Rhs>
		using dimension_common = std::conditional_t<std::is_same_v<Lhs, zero_t>, dimension_of_t<Rhs>, dimension_of_t<Lhs>>;

		template <class T, class U = void, class V = void>
		using enable_for_si = std::enable_if_t<is_si_v<T> || is_si_v<U> || is_si_v<V>>;

		template <class T, class Dimension>
		SI_INLINE_CONSTEXPR quantity<Dimension, T> operator-(quantity<Dimension, T> x)
		{
			value(x) = -value(x);
			return x;
		}

		template <class T, class Dimension, class U>
		SI_INLINE_CONSTEXPR quantity<Dimension, T>& operator+=(quantity<Dimension, T>& lhs, const U& rhs)
		{
			static_assert(has_common_dimension_v<Dimension, U>, "incompatible SI dimensions");
			value(lhs) += value(rhs);
			return lhs;
		}

		template <class T, class Dimension, class U>
		SI_INLINE_CONSTEXPR quantity<Dimension, T>& operator-=(quantity<Dimension, T>& lhs, const U& rhs)
		{
			static_assert(has_common_dimension_v<Dimension, U>, "incompatible SI dimensions");
			value(lhs) -= value(rhs);
			return lhs;
		}

		template <class T, class Dimension, class U>
		SI_INLINE_CONSTEXPR quantity<Dimension, T>& operator*=(quantity<Dimension, T>& lhs, const U& rhs)
		{
			static_assert(is_dimensionless_v<U>, "incompatible SI dimensions");
			value(lhs) *= value(rhs);
			return lhs;
		}

		template <class T, class Dimension, class U>
		SI_INLINE_CONSTEXPR quantity<Dimension, T>& operator/=(quantity<Dimension, T>& lhs, const U& rhs)
		{
			static_assert(is_dimensionless_v<U>, "incompatible SI dimensions");
			value(lhs) /= value(rhs);
			return lhs;
		}

		template <class Lhs, class Rhs, class = enable_for_si<Lhs, Rhs>>
		SI_INLINE_CONSTEXPR auto operator<(const Lhs& lhs, const Rhs& rhs)
		{
			static_assert(has_common_dimension_v<Lhs, Rhs>, "incompatible SI dimensions");
			return value2(lhs, rhs) < value2(rhs, lhs);
		}

		template <class Lhs, class Rhs, class = enable_for_si<Lhs, Rhs>>
		SI_INLINE_CONSTEXPR auto operator<=(const Lhs& lhs, const Rhs& rhs)
		{
			static_assert(has_common_dimension_v<Lhs, Rhs>, "incompatible SI dimensions");
			return value2(lhs, rhs) <= value2(rhs, lhs);
		}

		template <class Lhs, class Rhs, class = enable_for_si<Lhs, Rhs>>
		SI_INLINE_CONSTEXPR auto operator>(const Lhs& lhs, const Rhs& rhs)
		{
			static_assert(has_common_dimension_v<Lhs, Rhs>, "incompatible SI dimensions");
			return value2(lhs, rhs) > value2(rhs, lhs);
		}

		template <class Lhs, class Rhs, class = enable_for_si<Lhs, Rhs>>
		SI_INLINE_CONSTEXPR auto operator>=(const Lhs& lhs, const Rhs& rhs)
		{
			static_assert(has_common_dimension_v<Lhs, Rhs>, "incompatible SI dimensions");
			return value2(lhs, rhs) >= value2(rhs, lhs);
		}

		template <class Lhs, class Rhs, class = enable_for_si<Lhs, Rhs>>
		SI_INLINE_CONSTEXPR auto operator==(const Lhs& lhs, const Rhs& rhs)
		{
			static_assert(has_common_dimension_v<Lhs, Rhs>, "incompatible SI dimensions");
			return value2(lhs, rhs) == value2(rhs, lhs);
		}

		template <class Lhs, class Rhs, class = enable_for_si<Lhs, Rhs>>
		SI_INLINE_CONSTEXPR auto operator!=(const Lhs& lhs, const Rhs& rhs)
		{
			static_assert(has_common_dimension_v<Lhs, Rhs>, "incompatible SI dimensions");
			return value2(lhs, rhs) != value2(rhs, lhs);
		}

		// helper macro returning a quantity for non-null dimensions and plain value otherwise
#define SI_RETURN_QUANTITY(dimension_, ...)										\
		if constexpr(is_dimensionless_v<dimension_>)	return (__VA_ARGS__);	\
		else return quantity{dimension_(), (__VA_ARGS__)}

		template <class Lhs, class Rhs, class = enable_for_si<Lhs, Rhs>>
		SI_INLINE_CONSTEXPR auto operator+(const Lhs& lhs, const Rhs& rhs)
		{
			static_assert(has_common_dimension_v<Lhs, Rhs>, "incompatible SI dimensions");
			using result_dimension = dimension_common<Lhs, Rhs>;
			SI_RETURN_QUANTITY(result_dimension, value2(lhs, rhs) + value2(rhs, lhs));
		}

		template <class Lhs, class Rhs, class = enable_for_si<Lhs, Rhs>>
		SI_INLINE_CONSTEXPR auto operator-(const Lhs& lhs, const Rhs& rhs)
		{
			static_assert(has_common_dimension_v<Lhs, Rhs>, "incompatible SI dimensions");
			using result_dimension = dimension_common<Lhs, Rhs>;
			SI_RETURN_QUANTITY(result_dimension, value2(lhs, rhs) - value2(rhs, lhs));
		}

		template <class Lhs, class Rhs, class = enable_for_si<Lhs, Rhs>>
		SI_INLINE_CONSTEXPR auto operator*(const Lhs& lhs, const Rhs& rhs)
		{
			using result_dimension = dimension_add<Lhs, Rhs>;
			SI_RETURN_QUANTITY(result_dimension, value2(lhs, rhs) * value2(rhs, lhs));
		}

		template <class Lhs, class Rhs, class = enable_for_si<Lhs, Rhs>>
		SI_INLINE_CONSTEXPR auto operator/(const Lhs& lhs, const Rhs& rhs)
		{
			using result_dimension = dimension_subtract<Lhs, Rhs>;
			SI_RETURN_QUANTITY(result_dimension, value2(lhs, rhs) / value2(rhs, lhs));
		}

		template <class Dimension, class T>
		SI_INLINE_CONSTEXPR quantity<Dimension, T> abs(const quantity<Dimension, T>& x)
		{
			using std::abs;
			return { Dimension(), abs(value(x)) };
		}

		template <class Lhs, class Rhs, class = enable_for_si<Lhs, Rhs>>
		SI_INLINE_CONSTEXPR auto dot(const Lhs& lhs, const Rhs& rhs)
		{
			using result_dimension = dimension_add<Lhs, Rhs>;
			SI_RETURN_QUANTITY(result_dimension, dot(value(lhs), value(rhs)));
		}

		template <class Dimension, class T>
		SI_INLINE auto normalize(const quantity<Dimension, T>& x)
		{
			return normalize(value(x));
		}

		template <class Dimension, class T>
		SI_INLINE auto norm(const quantity<Dimension, T>& x)
		{
			return quantity{ Dimension(), length(value(x)) };
		}

		template <class T>
		SI_INLINE auto distance(const quantity<dimension<1, 0, 0, 0, 0>, T>& a, const quantity<dimension<1, 0, 0, 0, 0>, T>& b)
		{
			return quantity{ dimension<1, 0, 0, 0, 0>(), distance(value(a), value(b)) };
		}

		template <long Exponent, class Dimension, class T>
		SI_INLINE auto pow(const quantity<Dimension, T>& x)
		{
			using std::pow;
			using result_dimension = dimension_multiply<Dimension, value_dimension<Exponent>>;
			SI_RETURN_QUANTITY(result_dimension, pow(value(x), Exponent));
		}

		template <long Degree, class Dimension, class T>
		SI_INLINE auto root(const quantity<Dimension, T>& x)
		{
			using std::pow;
			using result_dimension = dimension_divide<Dimension, value_dimension<Degree>>;
			static_assert(std::is_same_v<dimension_multiply<result_dimension, value_dimension<Degree>>, Dimension>, "cannot take root of this SI dimension");

			SI_RETURN_QUANTITY(result_dimension, pow(value(x), 1. / Degree));
		}

		template <class Dimension, class T>
		SI_INLINE auto sqrt(const quantity<Dimension, T>& x)
		{
			using std::sqrt;
			using result_dimension = dimension_divide<Dimension, value_dimension<2>>;
			static_assert(std::is_same_v<dimension_multiply<result_dimension, value_dimension<2>>, Dimension>, "cannot take sqrt of this SI dimension");

			SI_RETURN_QUANTITY(result_dimension, sqrt(value(x)));
		}

		template <class Dimension, class T>
		SI_INLINE_CONSTEXPR auto deangle(const quantity<Dimension, T>& x)
		{
			using result_dimension = dimension<Dimension::length, Dimension::mass, Dimension::time, Dimension::temperature, 0>;
			SI_RETURN_QUANTITY(result_dimension, value(x));
		}

		template <class T> struct element_count : std::integral_constant<int, 1> {};
		template <class Dimension, class T> struct element_count<quantity<Dimension, T>> : element_count<T> {};

		template <class T>
		SI_INLINE_CONSTEXPR long element_count_v = element_count<T>::value;

		template <class Value, class Min, class Max>
		SI_INLINE_CONSTEXPR auto clamp(const Value& x, const Min& min, const Max& max)
		{
			static_assert(has_common_dimension_v<Value, Min>, "incompatible SI dimensions");
			static_assert(has_common_dimension_v<Value, Max>, "incompatible SI dimensions");

			using result_dimension = dimension_of_t<Value>;
			SI_RETURN_QUANTITY(result_dimension, std::clamp(value(x), value(min), value(max)));
		}

		template <long Num, long Den>
		struct ratio
		{
			static constexpr auto factor = static_cast<double_t>(Num) / Den;
		};

		struct tag_celsius {};
		struct tag_fahrenheit {};

		template <class Lhs, class Rhs>
		struct ratio_product
		{
			static constexpr auto factor = Lhs::factor * Rhs::factor;
		};

		template <class Lhs, class Rhs>
		struct ratio_quotient
		{
			static constexpr auto factor = Lhs::factor / Rhs::factor;
		};

		template <class T>
		using promoted_scalar_type = std::conditional_t<std::is_same_v<scalar_value_type_t<T>, float_t>, float_t, double_t>;

		template <class T>
		struct is_arithmetic : std::is_arithmetic<T> {};

		template <class Dimension, class UnitRatio>
		struct unit
		{
			template <class T, class = std::enable_if_t<is_arithmetic<T>::value>>
			SI_INLINE_CONSTEXPR auto operator()(const T& x) const
			{
				using scalar_type = promoted_scalar_type<T>;

				if constexpr (std::is_same_v<tag_celsius, UnitRatio>)
				{
					SI_RETURN_QUANTITY(Dimension, x + static_cast<scalar_type>(273.15));
				}
				else if constexpr (std::is_same_v<tag_fahrenheit, UnitRatio>)
				{
					SI_RETURN_QUANTITY(Dimension, (x + static_cast<scalar_type>(459.67)) * static_cast<scalar_type>(5. / 9));
				}
				else
				{
					SI_RETURN_QUANTITY(Dimension, x * static_cast<scalar_type>(UnitRatio::factor));
				}
			}
			template <class T, class U>
			SI_INLINE_CONSTEXPR auto operator()(T x, U y) const
			{
				using common_type = std::common_type_t<T, U>;
				using scalar_type = promoted_scalar_type<common_type>;

				if constexpr (std::is_same_v<tag_celsius, UnitRatio>)
				{
					SI_RETURN_QUANTITY(Dimension, vec2<scalar_type>(x, y) + static_cast<scalar_type>(273.15));
				}
				else if constexpr (std::is_same_v<tag_fahrenheit, UnitRatio>)
				{
					SI_RETURN_QUANTITY(Dimension, (vec2<scalar_type>(x, y) + static_cast<scalar_type>(459.67)) * static_cast<scalar_type>(5. / 9));
				}
				else
				{
					SI_RETURN_QUANTITY(Dimension, vec2<scalar_type>(x, y) * static_cast<scalar_type>(UnitRatio::factor));
				}
			}

			template <class T, class U, class V>
			SI_INLINE_CONSTEXPR auto operator()(T x, U y, V z) const
			{
				using common_type = std::common_type_t<T, U, V>;
				using scalar_type = promoted_scalar_type<common_type>;

				if constexpr (std::is_same_v<tag_celsius, UnitRatio>)
				{
					SI_RETURN_QUANTITY(Dimension, vec3<scalar_type>(x, y, z) + static_cast<scalar_type>(273.15));
				}
				else if constexpr (std::is_same_v<tag_fahrenheit, UnitRatio>)
				{
					SI_RETURN_QUANTITY(Dimension, (vec3<scalar_type>(x, y, z) + static_cast<scalar_type>(459.67)) * static_cast<scalar_type>(5. / 9));
				}
				else
				{
					SI_RETURN_QUANTITY(Dimension, vec3<scalar_type>(x, y, z) * static_cast<scalar_type>(UnitRatio::factor));
				}
			}

			template <class T>
			SI_INLINE_CONSTEXPR auto operator()(const quantity<Dimension, T>& q) const
			{
				using scalar_type = promoted_scalar_type<T>;

				if constexpr(std::is_same_v<tag_celsius, UnitRatio>)
					return value(q) - static_cast<scalar_type>(273.15);
				else if constexpr (std::is_same_v<tag_fahrenheit, UnitRatio>)
					return value(q) * static_cast<scalar_type>(9. / 5) - static_cast<scalar_type>(459.67);
				else
					return value(q) / static_cast<scalar_type>(UnitRatio::factor);
			}
		};

		template <class Dimension, long N>
		struct unit<Dimension, ratio<N, N>>
		{
			template <class T, class = std::enable_if_t<is_arithmetic<T>::value>>
			SI_INLINE_CONSTEXPR auto operator()(T value) const
			{
				SI_RETURN_QUANTITY(Dimension, value);
			}

			// Special operator for constructing a SI quantity from a trivally constructible internal::vec
			template <long D, class T>
			SI_INLINE_CONSTEXPR auto operator()(const internal::vec<D, internal::detail::vec_trivally_constructible<T>>& value) const
			{
				SI_RETURN_QUANTITY(Dimension, internal::vec<D, T>(value));
			}

			template <class T, class U>
			SI_INLINE_CONSTEXPR auto operator()(T x, U y) const
			{
				using common_type = std::common_type_t<T, U>;

				SI_RETURN_QUANTITY(Dimension, vec2<common_type>(x, y));
			}

			template <class T, class U, class V>
			SI_INLINE_CONSTEXPR auto operator()(T x, U y, V z) const
			{
				using common_type = std::common_type_t<T, U, V>;

				SI_RETURN_QUANTITY(Dimension, vec3<common_type>(x, y, z));
			}

			template <class T>
			SI_INLINE_CONSTEXPR T operator()(const quantity<Dimension, T>& q) const
			{
				return value(q);
			}

			SI_INLINE_CONSTEXPR double_t operator()(const quantity<Dimension, double_t>& q) const
			{
				return value(q);
			}

			SI_INLINE_CONSTEXPR vec2<double_t> operator()(const quantity<Dimension, vec2<double_t>>& q) const
			{
				return value(q);
			}

			SI_INLINE_CONSTEXPR vec3<double_t> operator()(const quantity<Dimension, vec3<double_t>>& q) const
			{
				return value(q);
			}
		};

		template <class Ratio>
		struct unit<dimensionless, Ratio> {};

		template <long N>
		struct unit<dimensionless, ratio<N, N>>
		{
			template <class T, class = std::enable_if_t<is_arithmetic<T>::value>>
			SI_INLINE_CONSTEXPR const T& operator()(const T& value) const
			{
				return value;
			}
		};

		template <class DimensionLhs, class RatioLhs, class DimensionRhs, class RatioRhs>
		SI_INLINE_CONSTEXPR auto operator*(unit<DimensionLhs, RatioLhs>, unit<DimensionRhs, RatioRhs>)
		{
			return unit<dimension_add<DimensionLhs, DimensionRhs>, ratio_product<RatioLhs, RatioRhs>>();
		}

		template <class DimensionLhs, class RatioLhs, class DimensionRhs, class RatioRhs>
		SI_INLINE_CONSTEXPR auto operator/(unit<DimensionLhs, RatioLhs>, unit<DimensionRhs, RatioRhs>)
		{
			return unit<dimension_subtract<DimensionLhs, DimensionRhs>, ratio_quotient<RatioLhs, RatioRhs>>();
		}
	}

	SI_INLINE_CONSTEXPR detail::zero_t zero;

	template <class Dimension, long Numerator = 1, long Denumerator = 1>
	using unit = detail::unit<detail::dimension_of_t<Dimension>, detail::ratio<Numerator, Denumerator>>;

	using detail::abs;
	using detail::normalize;
	using detail::norm;
	using detail::distance;
	using detail::pow;
	using detail::root;
	using detail::sqrt;
	using detail::dot;
	using detail::clamp;
	using detail::deangle;
	using detail::is_si;
	using detail::is_si_v;

#define SI_QUANTITY(name_, length_, mass_, time_, temperature_, angle_)						\
	namespace detail { using name_ ## _dimension = dimension<length_, mass_, time_, temperature_, angle_>; }\
	template <class T> using name_ ## _t = detail::quantity<detail:: name_ ## _dimension, T>;		\
	using name_ = name_ ## _t<double_t>;									\
	using name_ ## f = name_ ## _t<float_t>;								\
	using name_ ## 2 = name_ ## _t<detail::vec2<double_t>>;							\
	using name_ ## 2f = name_ ## _t<detail::vec2<float_t>>;							\
	using name_ ## 3 = name_ ## _t<detail::vec3<double_t>>;							\
	using name_ ## 3f = name_ ## _t<detail::vec3<float_t>>															
	// The 7 SI Dimensions
	// -------------------                 l  m  t  T  ° 
	SI_QUANTITY(length,                    1, 0, 0, 0, 0);
	SI_QUANTITY(mass,                      0, 1, 0, 0, 0);
	SI_QUANTITY(time,                      0, 0, 1, 0, 0);
	SI_QUANTITY(temperature,               0, 0, 0, 1, 0); // (thermodynamic temperature)
	SI_QUANTITY(electric_current,          0, 0, 0, 0, 1); // TODO
	SI_QUANTITY(amount_of_substance,       0, 0, 0, 0, 1); // TODO
	SI_QUANTITY(luminous_intensity,        0, 0, 0, 0, 1); // TODO
	//...

	// The 22 SI Derived Dimensions
	// ----------------------------
	SI_QUANTITY(area,          2, 0,  0, 0, 0); // (length²)
	SI_QUANTITY(volume,        3, 0,  0, 0, 0); // (length³)
	SI_QUANTITY(frequency,     0, 0, -1, 0, 0); // (per time)
	SI_QUANTITY(velocity,      1, 0, -1, 0, 0); // (length per time)
	SI_QUANTITY(angular_speed, 0, 0, -1, 0, 1); // (degree per time)
	SI_QUANTITY(acceleration,  1, 0, -2, 0, 0); // (length per time²)
	SI_QUANTITY(jerk,          1, 0, -3, 0, 0);
	SI_QUANTITY(force,         1, 1, -2, 0, 0);
	SI_QUANTITY(impulse,       1, 1, -1, 0, 0);
	SI_QUANTITY(pressure,     -1, 1, -2, 0, 0);
	SI_QUANTITY(energy,        2, 1, -2, 0, 0);
	SI_QUANTITY(torque,        2, 1, -2, 0, 0);
	SI_QUANTITY(power,         2, 1, -3, 0, 0);
	SI_QUANTITY(density,      -3, 1,  0, 0, 0); // (mass per length³)
	SI_QUANTITY(BMI,          -2, 1,  0, 0, 0); // (mass per length²)
	SI_QUANTITY(reciprocal_length,-1, 0,  0, 0, 0); // (per length)
	SI_QUANTITY(reciprocal_amount_of_substance,0, 0,  0, 0,-1); // (per amount of substance)
	//...

	using position2d = length2;
	using position = length3;

	// The SI Prefixes
	// ---------------
	//SI_INLINE_CONSTEXPR auto exa   = unit<detail::dimensionless, 1000000000000000000>();
	//SI_INLINE_CONSTEXPR auto peta  = unit<detail::dimensionless, 1000000000000000>();
	//SI_INLINE_CONSTEXPR auto tera  = unit<detail::dimensionless, 1000000000000>();
	SI_INLINE_CONSTEXPR auto giga  = unit<detail::dimensionless, 1000000000>();
	SI_INLINE_CONSTEXPR auto mega  = unit<detail::dimensionless, 1000000>();
	SI_INLINE_CONSTEXPR auto kilo  = unit<detail::dimensionless, 1000>();
	SI_INLINE_CONSTEXPR auto hecto = unit<detail::dimensionless, 100>();

	SI_INLINE_CONSTEXPR auto centi = unit<detail::dimensionless, 1, 100>();
	SI_INLINE_CONSTEXPR auto milli = unit<detail::dimensionless, 1, 1000>();
	SI_INLINE_CONSTEXPR auto micro = unit<detail::dimensionless, 1, 1000000>();
	SI_INLINE_CONSTEXPR auto nano  = unit<detail::dimensionless, 1, 1000000000>();
	//SI_INLINE_CONSTEXPR auto pico  = unit<detail::dimensionless, 1, 1000000000000>();
	//SI_INLINE_CONSTEXPR auto femto = unit<detail::dimensionless, 1, 1000000000000000>();

	// The 7 SI Base Units
	// -------------------
	// length in...
	SI_INLINE_CONSTEXPR auto meter       = unit<length>();
	SI_INLINE_CONSTEXPR auto kilometer   = kilo * meter; 
	SI_INLINE_CONSTEXPR auto centimeter  = centi * meter;
	SI_INLINE_CONSTEXPR auto millimeter  = milli * meter;
	// time in...
	SI_INLINE_CONSTEXPR auto second      = unit<time>();
	SI_INLINE_CONSTEXPR auto minute      = unit<time, 60>();
	SI_INLINE_CONSTEXPR auto hour        = unit<time, 3600>();
	SI_INLINE_CONSTEXPR auto day         = unit<time, 24*3600>();
	SI_INLINE_CONSTEXPR auto millisecond = milli * second;
	SI_INLINE_CONSTEXPR auto microsecond = micro * second;
	// mass in...
	SI_INLINE_CONSTEXPR auto kilogram    = unit<mass>();
	SI_INLINE_CONSTEXPR auto ton         = kilo * kilogram;
	SI_INLINE_CONSTEXPR auto gram        = milli * kilogram;
	SI_INLINE_CONSTEXPR auto milligram   = micro * kilogram;
	// thermodynamic temperature in...
	SI_INLINE_CONSTEXPR auto kelvin      = unit<temperature>();
	// electric current in...
	SI_INLINE_CONSTEXPR auto ampere      = unit<electric_current>();
	// amount of substance in...
	SI_INLINE_CONSTEXPR auto mol         = unit<amount_of_substance>(); 
	// luminous intensity in...
	SI_INLINE_CONSTEXPR auto candela     = unit<luminous_intensity>();

	// The 22 SI Derived Units
	// -----------------------
	SI_INLINE_CONSTEXPR auto hertz       = unit<frequency>();
	SI_INLINE_CONSTEXPR auto kilohertz   = kilo * hertz;

	SI_INLINE_CONSTEXPR auto meter2      = unit<area>();
	SI_INLINE_CONSTEXPR auto kilometer2  = kilo * kilo * meter2;
	SI_INLINE_CONSTEXPR auto centimeter2 = centi * centi * meter2;
	SI_INLINE_CONSTEXPR auto millimeter2 = milli * milli * meter2;

	SI_INLINE_CONSTEXPR auto meter2_per_second = meter2 / second;
	SI_INLINE_CONSTEXPR auto kilograms_per_meter2 = kilogram / meter2;
	SI_INLINE_CONSTEXPR auto kilograms_per_mol = kilogram / mol;

	SI_INLINE_CONSTEXPR auto meter3      = unit<volume>();
	SI_INLINE_CONSTEXPR auto kilometer3  = kilo * kilo * kilo * meter3;
	SI_INLINE_CONSTEXPR auto centimeter3 = centi * centi * centi * meter3;
	SI_INLINE_CONSTEXPR auto millimeter3 = milli * milli * milli * meter3;

	SI_INLINE_CONSTEXPR auto meter3_per_second = meter3 / second;
	SI_INLINE_CONSTEXPR auto kilograms_per_meter3 = kilogram / meter3;
	SI_INLINE_CONSTEXPR auto grams_per_centimeter3 = gram / centimeter3;

	SI_INLINE_CONSTEXPR auto meters_per_second = meter / second;
	SI_INLINE_CONSTEXPR auto kilometers_per_hour = kilometer / hour;
	SI_INLINE_CONSTEXPR auto millimeters_per_hour = millimeter / hour;

	SI_INLINE_CONSTEXPR auto meters_per_second2 = meter / (second * second);

	SI_INLINE_CONSTEXPR auto newton      = kilogram * meter / (second * second);
	SI_INLINE_CONSTEXPR auto kilonewton  = kilo * newton;
	SI_INLINE_CONSTEXPR auto meganewton  = mega * newton;
	SI_INLINE_CONSTEXPR auto giganewton  = giga * newton;

	SI_INLINE_CONSTEXPR auto joule       = newton * meter;
	SI_INLINE_CONSTEXPR auto kilojoule   = kilo * joule;
	SI_INLINE_CONSTEXPR auto megajoule   = mega * joule;
	SI_INLINE_CONSTEXPR auto gigajoule   = giga * joule;

	SI_INLINE_CONSTEXPR auto joulesecond = joule * second;
	SI_INLINE_CONSTEXPR auto joules_per_kelvin = joule / kelvin;
	SI_INLINE_CONSTEXPR auto joules_per_second_per_kilogram = joule / second / kilogram;
	SI_INLINE_CONSTEXPR auto joules_per_kilogram_per_kelvin = joule / kilogram / kelvin;
	SI_INLINE_CONSTEXPR auto gray = joule / kilogram;
	SI_INLINE_CONSTEXPR auto sievert = joule / kilogram;

	SI_INLINE_CONSTEXPR auto joules_per_second = joule / second;
	SI_INLINE_CONSTEXPR auto watt        = joule / second; // (energy per time span)
	SI_INLINE_CONSTEXPR auto watt_per_meter2 = watt / meter2;

	SI_INLINE_CONSTEXPR auto pascal_     = newton / (meter * meter);
	SI_INLINE_CONSTEXPR auto hectopascal = hecto * pascal_;
	SI_INLINE_CONSTEXPR auto millibar    = hecto * pascal_;
	SI_INLINE_CONSTEXPR auto bar         = hecto * kilo * pascal_;

	SI_INLINE_CONSTEXPR auto newtonmeter = newton * meter;
	SI_INLINE_CONSTEXPR auto newtonsecond= newton * second;

	SI_INLINE_CONSTEXPR auto ampere_per_meter = ampere / meter;
	SI_INLINE_CONSTEXPR auto ampere_per_meter2 = ampere / (meter * meter);
	SI_INLINE_CONSTEXPR auto coulomb     = ampere * second;
	SI_INLINE_CONSTEXPR auto coulombs_per_mol = coulomb / mol;
	SI_INLINE_CONSTEXPR auto ampere_hours= ampere * hour;
	SI_INLINE_CONSTEXPR auto volt        = joule / coulomb; 
	SI_INLINE_CONSTEXPR auto farad       = coulomb / volt;
	SI_INLINE_CONSTEXPR auto farads_per_meter = farad / meter;
	SI_INLINE_CONSTEXPR auto ohm         = volt / ampere;
	SI_INLINE_CONSTEXPR auto ohm_meter   = ohm * meter;
	SI_INLINE_CONSTEXPR auto siemens     = ampere / volt;
	SI_INLINE_CONSTEXPR auto siemens_per_meter = siemens / meter;
	SI_INLINE_CONSTEXPR auto henry       = volt * second / ampere;
	SI_INLINE_CONSTEXPR auto weber       = volt * second;
	SI_INLINE_CONSTEXPR auto tesla       = kilogram / (ampere * second * second);
	SI_INLINE_CONSTEXPR auto joules_per_tesla = joule / tesla;

	SI_INLINE_CONSTEXPR auto steradian   = unit<detail::dimensionless>();

	SI_INLINE_CONSTEXPR auto lumen       = candela * steradian; 
	SI_INLINE_CONSTEXPR auto lumen_second = lumen * second;
	SI_INLINE_CONSTEXPR auto lumens_per_watt = lumen / watt; 

	SI_INLINE_CONSTEXPR auto per_meter    = unit<reciprocal_length>(); 
	SI_INLINE_CONSTEXPR auto per_mol      = unit<reciprocal_amount_of_substance>(); 

	// IMPERIAL UNITS
	SI_INLINE_CONSTEXPR auto pound        = unit<mass, 45359237, 100000000>();
	SI_INLINE_CONSTEXPR auto feet         = unit<length, 3048, 10000>();
	SI_INLINE_CONSTEXPR auto nautical_mile = unit<length, 1852, 100>();
	SI_INLINE_CONSTEXPR auto inch         = unit<length, 254, 10000>();
	SI_INLINE_CONSTEXPR auto statute_mile = unit<length, 1609344, 1000>();
	SI_INLINE_CONSTEXPR auto fahrenheit   = detail::unit<detail::temperature_dimension, detail::tag_fahrenheit>();
	SI_INLINE_CONSTEXPR auto miles_per_hour = statute_mile / hour;
	SI_INLINE_CONSTEXPR auto knots        = nautical_mile / hour;
	SI_INLINE_CONSTEXPR auto feet_per_minute = feet / minute;
	SI_INLINE_CONSTEXPR auto inches_per_hour = inch / hour;

	// VARIOUS UNITS
	SI_INLINE_CONSTEXPR auto celsius     = detail::unit<detail::temperature_dimension, detail::tag_celsius>();

	SI_INLINE_CONSTEXPR auto byte        = unit<detail::dimensionless>();
	SI_INLINE_CONSTEXPR auto bytes_per_second = byte / second;

	// ANGLE (DIMENSIONLESS)
	typedef long double angle;
	typedef angle radian;

	SI_INLINE angle sin(angle a)
	{
		return std::sin(radian(a));
	}

	SI_INLINE angle cos(angle a)
	{
		return std::cos(radian(a));
	}

	SI_INLINE angle tan(angle a)
	{
		return std::tan(radian(a));
	}

	SI_INLINE angle atan2(length y, length x)
	{
		return std::atan2(meter(y), meter(x));
	}

	// Returns the square of x (x² or x*x).
	template <typename T>
	SI_INLINE auto square(T x) {
		return x * x;
	}
}

#undef SI_RETURN_QUANTITY
#undef SI_QUANTITY
#undef SI_INLINE_CONSTEXPR
#undef SI_INLINE
