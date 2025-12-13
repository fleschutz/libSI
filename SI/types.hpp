#pragma once

#include <type_traits>
#include <limits>
#include <utility>
#include <cmath>
#include <algorithm>
#include <charconv>

#include "internal/vec.hpp"

namespace si
{
	namespace detail
	{
		template <class T>
		using vec2 = core::vec2<T>;

		template <class T>
		using vec3 = core::vec3<T>;

		// Dimension of a physical quantity
		/*
			Every physical quantity has a dimension which is specified by it's dimensional exponents.
			Examples:
			- speed is length per time or length^1/time^1, so the exponents for speed are Length=1,
			  Mass=0, Time=-1, Temp=0, Angle=0
			- force is mass times acceleration which is mass^1*length^1/time^2, so the exponents are
			  Length=1, Mass=1, Time=-2, Temp=0, Angle=0

			This template converts this concept into a C++ type.
			In order to add a new exponent one has to update the three templates dimension, value_dimension and SI_DIMENSION_OP
		*/
		template <int Length, int Mass, int Time, int Temperature, int Angle>
		struct dimension
		{
			static constexpr int length = Length;
			static constexpr int mass = Mass;
			static constexpr int time = Time;
			static constexpr int temperature = Temperature;
			static constexpr int angle = Angle;
		};

		template <int Value>
		using value_dimension = dimension<Value, Value, Value, Value, Value>;

		using null_dimension = value_dimension<0>;

		template <class, class>
		struct quantity;
		template <class, class>
		struct unit;

		template <class T>
		struct dimension_of
		{
			using type = null_dimension;
		};

		template <int Length, int Mass, int Time, int Temperature, int Angle>
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

		// Resolves to the dimension of anything that might have a dimension (types with no dimension end up with null_dimension)
		template <class T>
		using dimension_of_t = typename dimension_of<std::decay_t<T>>::type;

		// Checks whether the given type is/has null_dimension
		template <class T>
		inline constexpr bool is_null_dimension_v = std::is_same_v<null_dimension, dimension_of_t<T>>;

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

#define SI_INLINE /*!!!TODO __forceinline*/
#define SI_INLINE_CONSTEXPR constexpr SI_INLINE

		// Storage for plain arithmetic types (float, double, int, ...)
		template <class Dimension, class T>
		class quantity_storage
		{
		public:
			// Make sure no funny stuff is going on
			// static_assert(std::is_arithmetic_v<T> && std::is_same_v<std::decay_t<T>, T>, "Not a valid T");

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
			// Make sure we are not creating quantities with null_dimension (null_dimensions should be plain arithmetic types)
			static_assert(!is_null_dimension_v<Dimension>);

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
		inline constexpr bool is_si_v = is_si<T>::value;

		// Fallback value for any plain type, simply returns the value as-is
		template <class T, class = std::enable_if_t<!is_si_v<T>>>
		SI_INLINE_CONSTEXPR const T& value(const T& x)
		{
			return x;
		}

		SI_INLINE_CONSTEXPR int value(zero_t)
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
		inline constexpr bool has_common_dimension_v = 
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
			static_assert(is_null_dimension_v<U>, "incompatible SI dimensions");
			value(lhs) *= value(rhs);
			return lhs;
		}

		template <class T, class Dimension, class U>
		SI_INLINE_CONSTEXPR quantity<Dimension, T>& operator/=(quantity<Dimension, T>& lhs, const U& rhs)
		{
			static_assert(is_null_dimension_v<U>, "incompatible SI dimensions");
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
		if constexpr(is_null_dimension_v<dimension_>)	return (__VA_ARGS__);	\
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
#if 0
		template <class Dimension, class T>
		SI_INLINE_CONSTEXPR auto sign(const quantity<Dimension, T>& x)
		{
			using core::sign;
			return sign(value(x));
		}
		template <class Dimension, class T>
		SI_INLINE_CONSTEXPR bool isnan(const quantity<Dimension, T>& x)
		{
			return ::isnan(value(x));
		}

		template <class Dimension, class T>
		SI_INLINE_CONSTEXPR bool isinf(const quantity<Dimension, T>& x)
		{
			return ::isinf(value(x));
		}
#endif

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

		template <int Exponent, class Dimension, class T>
		SI_INLINE auto pow(const quantity<Dimension, T>& x)
		{
			using std::pow;
			using result_dimension = dimension_multiply<Dimension, value_dimension<Exponent>>;
			SI_RETURN_QUANTITY(result_dimension, pow(value(x), Exponent));
		}

		template <int Degree, class Dimension, class T>
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

		template <class T>
		SI_INLINE auto sin(const quantity<dimension<0, 0, 0, 0, 1>, T>& x)
		{
			return std::sin(value(x));
		}

		template <class T>
		SI_INLINE auto cos(const quantity<dimension<0, 0, 0, 0, 1>, T>& x)
		{
			return std::cos(value(x));
		}

		template <class T>
		SI_INLINE auto tan(const quantity<dimension<0, 0, 0, 0, 1>, T>& x)
		{
			return std::tan(value(x));
		}

		template <class Lhs, class Rhs, class = enable_for_si<Lhs, Rhs>>
		SI_INLINE auto atan2(const Lhs& y, const Rhs& x)
		{
			static_assert(has_common_dimension_v<Lhs, Rhs>, "incompatible SI dimensions");
			auto rad = std::atan2(value2(y, x), value2(x, y));
			return quantity{ dimension<0, 0, 0, 0, 1>(), rad };
		}

		template <class T> struct element_count : std::integral_constant<int, 1> {};
		template <class Dimension, class T> struct element_count<quantity<Dimension, T>> : element_count<T> {};

		template <class T>
		inline constexpr int element_count_v = element_count<T>::value;

		template <class Value, class Min, class Max>
		SI_INLINE_CONSTEXPR auto clamp(const Value& x, const Min& min, const Max& max)
		{
			static_assert(has_common_dimension_v<Value, Min>, "incompatible SI dimensions");
			static_assert(has_common_dimension_v<Value, Max>, "incompatible SI dimensions");

			using result_dimension = dimension_of_t<Value>;
			SI_RETURN_QUANTITY(result_dimension, std::clamp(value(x), value(min), value(max)));
		}

		template <int Num, int Den>
		struct ratio
		{
			static constexpr auto factor = static_cast<double>(Num) / Den;
		};

		struct ratio_degree
		{
			static constexpr auto factor = 0.01745329251994329576923690768489;
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
		using promoted_scalar_type = std::conditional_t<std::is_same_v<scalar_value_type_t<T>, float>, float, double>;

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

		template <class Dimension, int N>
		struct unit<Dimension, ratio<N, N>>
		{
			template <class T, class = std::enable_if_t<is_arithmetic<T>::value>>
			SI_INLINE_CONSTEXPR auto operator()(T value) const
			{
				SI_RETURN_QUANTITY(Dimension, value);
			}

			// Special operator for constructing a SI quantity from a trivally constructible core::vec
			template <int D, class T>
			SI_INLINE_CONSTEXPR auto operator()(const core::vec<D, core::detail::vec_trivally_constructible<T>>& value) const
			{
				SI_RETURN_QUANTITY(Dimension, core::vec<D, T>(value));
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

			SI_INLINE_CONSTEXPR double operator()(const quantity<Dimension, double>& q) const
			{
				return value(q);
			}

			SI_INLINE_CONSTEXPR vec2<double> operator()(const quantity<Dimension, vec2<double>>& q) const
			{
				return value(q);
			}

			SI_INLINE_CONSTEXPR vec3<double> operator()(const quantity<Dimension, vec3<double>>& q) const
			{
				return value(q);
			}
		};

		template <class Ratio>
		struct unit<null_dimension, Ratio> {};

		template <int N>
		struct unit<null_dimension, ratio<N, N>>
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

		std::from_chars_result from_chars(const char* first, const char* last, const int* dimension, double& value);
	}

	inline constexpr detail::zero_t zero;

	template <class Dimension, int Numerator = 1, int Denumerator = 1>
	using unit = detail::unit<detail::dimension_of_t<Dimension>, detail::ratio<Numerator, Denumerator>>;

	using detail::abs;
	using detail::normalize;
	using detail::norm;
	using detail::distance;
	using detail::pow;
	using detail::root;
	using detail::sqrt;
	using detail::sin;
	using detail::cos;
	using detail::tan;
	using detail::atan2;
	using detail::dot;
	using detail::clamp;
	using detail::deangle;
#if 0
	using detail::sign;
	using detail::isnan;
	using detail::isinf;
#endif
	using detail::is_si;
	using detail::is_si_v;

#define SI_QUANTITY(name_, length_, mass_, time_, temperature_, angle_)											\
	namespace detail { using name_ ## _dimension = dimension<length_, mass_, time_, temperature_, angle_>; }	\
	template <class T> using name_ ## _t = detail::quantity<detail:: name_ ## _dimension, T>;					\
	using name_ = name_ ## _t<double>;																			\
	using name_ ## f = name_ ## _t<float>;																		\
	using name_ ## 2 = name_ ## _t<detail::vec2<double>>;														\
	using name_ ## 2f = name_ ## _t<detail::vec2<float>>;														\
	using name_ ## 3 = name_ ## _t<detail::vec3<double>>;														\
	using name_ ## 3f = name_ ## _t<detail::vec3<float>>															
	SI_QUANTITY(angle, 0, 0, 0, 0, 1);

	SI_QUANTITY(length, 1, 0, 0, 0, 0);
	SI_QUANTITY(height, 1, 0, 0, 0, 0);
	SI_QUANTITY(mass, 0, 1, 0, 0, 0);
	SI_QUANTITY(time, 0, 0, 1, 0, 0);
	SI_QUANTITY(temperature, 0, 0, 0, 1, 0);

	SI_QUANTITY(frequency, 0, 0, -1, 0, 0);
	SI_QUANTITY(speed, 1, 0, -1, 0, 0);
	SI_QUANTITY(angular_speed, 0, 0, -1, 0, 1);
	SI_QUANTITY(acceleration, 1, 0, -2, 0, 0);
	SI_QUANTITY(jerk, 1, 0, -3, 0, 0);
	SI_QUANTITY(force, 1, 1, -2, 0, 0);
	SI_QUANTITY(impulse, 1, 1, -1, 0, 0);
	SI_QUANTITY(pressure, -1, 1, -2, 0, 0);
	SI_QUANTITY(energy, 2, 1, -2, 0, 0);
	SI_QUANTITY(torque, 2, 1, -2, 0, 0);
	SI_QUANTITY(power, 2, 1, -3, 0, 0);
	SI_QUANTITY(area, 2, 0, 0, 0, 0);
	SI_QUANTITY(density, -3, 1, 0, 0, 0);

	using position2d = length2;
	using position = length3;

	// SI prefixes
	inline constexpr auto giga  = unit<detail::null_dimension, 1000000000>();
	inline constexpr auto mega  = unit<detail::null_dimension, 1000000>();
	inline constexpr auto hecto = unit<detail::null_dimension, 100>();
	inline constexpr auto kilo  = unit<detail::null_dimension, 1000>();
	inline constexpr auto one   = unit<detail::null_dimension>();
	inline constexpr auto milli = unit<detail::null_dimension, 1, 1000>();
	inline constexpr auto micro = unit<detail::null_dimension, 1, 1000000>();

	inline constexpr auto meter = unit<length>();
	inline constexpr auto centimeter = unit<length, 1, 100>();
	inline constexpr auto millimeter = unit<length, 1, 1000>();
	inline constexpr auto kilometer = unit<length, 1000>();
	inline constexpr auto feet = unit<length, 3048, 10000>();
	inline constexpr auto nautical_mile = unit<length, 185318, 100>(); // !!! this is NOT the correct factor, but for sake of compatibility this value from TowMacros.h is used !!!
	//inline constexpr auto nautical_mile = unit<length, 1852>(); // !!! this is NOT the value used by TowMacros.h but the correct factor !!!
	inline constexpr auto inch = unit<length, 254, 10000>();
	inline constexpr auto statute_mile = unit<length, 1609344, 1000>(); // that's the "international mile", the U.S. survey mile is about 1609.347218694 metres (sigh)

	inline constexpr auto kilogram = unit<mass>();
	inline constexpr auto gram = unit<mass, 1, 1000>();
	inline constexpr auto milligram = unit<mass, 1, 1000000>();
	inline constexpr auto ton = unit<mass, 1000>();
	inline constexpr auto pound = unit<mass, 45359237, 100000000>();

	inline constexpr auto second = unit<time>();
	inline constexpr auto minute = unit<time, 60>();
	inline constexpr auto hour = unit<time, 3600>();
	inline constexpr auto day = unit<time, 24 * 3600>();
	inline constexpr auto millisecond = milli * second;
	inline constexpr auto microsecond = micro * second;

	//@{
	/**
		Because of the different zero points, care has to be taken when using temperature in calculations.

		In particular:
		- 'si::celsius(a / b)' IS NOT EQUAL TO 'si::celsius(a) / si::celsius(b)'
		- [...]
	*/
	inline constexpr auto kelvin = unit<temperature>();
	inline constexpr auto celsius = detail::unit<detail::temperature_dimension, detail::tag_celsius>();
	inline constexpr auto fahrenheit = detail::unit<detail::temperature_dimension, detail::tag_fahrenheit>();
	//@}

	inline constexpr auto radian = unit<angle>();
	inline constexpr auto degree = detail::unit<detail::angle_dimension, detail::ratio_degree>();

	inline constexpr auto meter2 = unit<area>();

	inline constexpr auto hertz = unit<frequency>();
	inline constexpr auto kilohertz = kilo * hertz;
	inline constexpr auto megahertz = mega * hertz;
	inline constexpr auto gigahertz = giga * hertz;
	inline constexpr auto per_minute = one / minute;

	inline constexpr auto radians_per_second = unit<angular_speed>();
	inline constexpr auto degrees_per_second = degree / second;

	inline constexpr auto meters_per_second = meter / second;
	inline constexpr auto kilometers_per_hour = kilometer / hour;
	inline constexpr auto miles_per_hour = statute_mile / hour;

	// Knots are "nautical_mile / hour", but we cannot use nautical_mile because those are incorrect (see note above)
	// Here, we have to use the correct factor of 1852 m / 3600 s = 0.5144444 m/s (which is what ExEngine MS2KTS uses)
	// inline constexpr auto knots = nautical_mile / hour;
	inline constexpr auto knots = unit<speed, 1852, 3600>();

	inline constexpr auto feet_per_minute = feet / minute;
	inline constexpr auto millimeters_per_hour = millimeter / hour;
	inline constexpr auto inches_per_hour = inch / hour;

	inline constexpr auto newton = kilogram * meter / (second * second);
	inline constexpr auto kilonewton = kilo * newton;
	inline constexpr auto meganewton = mega * newton;
	inline constexpr auto giganewton = giga * newton;

	inline constexpr auto joule = newton * meter;
	inline constexpr auto kilojoule = kilonewton * meter;
	inline constexpr auto megajoule = meganewton * meter;
	inline constexpr auto gigajoule = giganewton * meter;

	inline constexpr auto meters_per_second2 = meter / (second * second);

	inline constexpr auto pascal_ = newton / (meter * meter);
	inline constexpr auto hectopascal = hecto * pascal_;
	inline constexpr auto millibar = hectopascal;
	inline constexpr auto bar = hecto * kilo * pascal_;

	inline constexpr auto newtonmeter = newton * meter;
	inline constexpr auto newtonsecond = newton * second;

	inline constexpr auto kilograms_per_meter3 = kilogram / (meter * meter * meter);

	// Declaring the following constants constexpr somehow caused si functions to show up in completely unrelated template error diagnostics


	///@{
	/// Prints a quantity to string
	/**
		Prints value in base units, without adding the unit string.

		Example: 1000 meters is printed as "1000"
	*/
	template <class Dimension, class T>
	std::to_chars_result to_chars(char* first, char* last, const detail::quantity<Dimension, T>& q)
	{
		return std::to_chars(first, last, value(q));
	}
	///@}

	/// Reads a quantity from a string
	/**
		Supports some basic unit strings (e.g. "m", "ft", "m/s", "km/h", ...).

		Silently skips any superfluous whitespaces between value
		and unit.
	*/
	template <class Dimension, class T>
	std::from_chars_result from_chars(const char* first, const char* last, detail::quantity<Dimension, T>& q)
	{
		static constexpr int dimension[] = { Dimension::length, Dimension::mass, Dimension::time, Dimension::temperature, Dimension::angle };

		double x = {};
		auto ret = detail::from_chars(first, last, dimension, x);
		value(q) = static_cast<T>(x);

		return ret;
	}

	typedef long double ampere;
	// DIGITAL UNITS:
	typedef long double byte;

	typedef long double quantity; // big enough

	void unit_tests(); // Unit tests in SI/unit_tests.cpp
}

#if 0
namespace core
{
	namespace detail
	{
		template <class Dimension, class T>
		struct value_tree_translator<si::detail::quantity<Dimension, T>>
		{
			static std::string to_string(const si::detail::quantity<Dimension, T>& value)
			{
				char buffer[128] = "";
				auto result = si::to_chars(std::begin(buffer), std::end(buffer), value);
				return buffer;
			}

			static value_tree_value<si::detail::quantity<Dimension, T>> from_string(std::string_view text)
			{
				if (!text.empty())
				{
					si::detail::quantity<Dimension, T> value = {};
					auto last = text.data() + text.size();
					auto result = si::from_chars(text.data(), last, value);

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
	}
}
#endif

#undef SI_RETURN_QUANTITY
#undef SI_QUANTITY
#undef SI_INLINE_CONSTEXPR
#undef SI_INLINE
