// SI/internal.h - internal datatypes, classes, etc.
#pragma once

#include <cmath>
#include <type_traits>
#define SI_INLINE inline 
#define SI_INLINE_CONSTEXPR constexpr inline

namespace SI
{
	typedef double SIfloat;        // <- internal datatype to hold floating point values
	typedef SIfloat dimensionless; // <- basic datatype to hold a dimensionless value (without any unit), e.g. 42

	namespace internal
	{
		namespace detail
		{
			template <class T> struct vec_trivally_constructible { using type = T; };
			template <class T> struct vec_value_type { using type = T; };
			template <class T> struct vec_value_type<vec_trivally_constructible<T>> { using type = T; };
			template <class... T> using vec_common_type_t = std::common_type_t<typename vec_value_type<T>::type...>;
		}


		template <int N, class T>
		struct vec;

		template <class T>
		struct vec<2, T> : vec<2, detail::vec_trivally_constructible<T>>
		{
			using vec<2, detail::vec_trivally_constructible<T>>::vec;

			SI_INLINE_CONSTEXPR vec() : vec<2, detail::vec_trivally_constructible<T>>(0, 0) {}
		};

		template <class T>
		struct vec<2, detail::vec_trivally_constructible<T>>
		{
			static_assert(std::is_arithmetic_v<T>);

			SI_INLINE_CONSTEXPR vec() = default;

			SI_INLINE_CONSTEXPR vec(T x, T y) : x(x), y(y)
			{
				static_assert(sizeof(vec) == 2 * sizeof(T));
				static_assert(std::is_trivially_copyable_v<vec>);
			}

			template <class U>
			SI_INLINE_CONSTEXPR explicit vec(const vec<2, U>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y)) {}

			template <class U>
			SI_INLINE_CONSTEXPR operator vec<2, U>() const { return vec<2, U>(x, static_cast<detail::vec_common_type_t<U>>(y)); } // NOLINT(google-explicit-constructor)

			template <class U>
			SI_INLINE_CONSTEXPR explicit vec(const vec<3, U>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y)) {}

			SI_INLINE_CONSTEXPR explicit operator bool() const noexcept { return !(x == 0 && y == 0); }

			T x;
			T y;
		};

		template <class T>
		struct vec<3, T> : vec<3, detail::vec_trivally_constructible<T>>
		{
			using vec<3, detail::vec_trivally_constructible<T>>::vec;
			SI_INLINE_CONSTEXPR vec() : vec<3, detail::vec_trivally_constructible<T>>(0, 0, 0) {}
		};

		template <class T>
		struct vec<3, detail::vec_trivally_constructible<T>>
		{
			static_assert(std::is_arithmetic_v<T>);

			SI_INLINE_CONSTEXPR vec() = default;
			
			SI_INLINE_CONSTEXPR vec(T x, T y, T z) : x(x), y(y), z(z)
			{
				static_assert(sizeof(vec) == 3 * sizeof(T));
				static_assert(std::is_trivially_copyable_v<vec>);
			}

			template <class U>
			SI_INLINE_CONSTEXPR vec(const vec<2, U>& xy, T z) : vec(xy.x, xy.y, z) {}

			template <class U>
			SI_INLINE_CONSTEXPR explicit vec(const vec<3, U>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y), static_cast<T>(other.z)) {}

			template <class U>
			SI_INLINE_CONSTEXPR operator vec<3, U>() const { return vec<3, U>(x, static_cast<detail::vec_common_type_t<U>>(y), static_cast<detail::vec_common_type_t<U>>(z)); } // NOLINT(google-explicit-constructor)

			SI_INLINE_CONSTEXPR explicit operator bool() const noexcept { return !(x == 0 && y == 0 && z == 0); }
			union
			{
				struct
				{
					T x;
					T y;
				};
				internal::vec<2, detail::vec_trivally_constructible<T>> xy;
			};
			T z;
		};

		template <class T> using vec2 = vec<2, T>;
		template <class T> using vec3 = vec<3, T>;

		// Unary operators
		template <class T> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<T> operator-(const vec2<T>& v) { return { -v.x, -v.y }; }
		template <class T> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<T> operator-(const vec3<T>& v) { return { -v.x, -v.y, -v.z }; }

		// Comparsion operators
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR bool operator==(const vec2<T>& lhs, const vec2<U>& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR bool operator==(const vec3<T>& lhs, const vec3<U>& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR bool operator!=(const vec2<T>& lhs, const vec2<U>& rhs) { return lhs.x != rhs.x || lhs.y != rhs.y; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR bool operator!=(const vec3<T>& lhs, const vec3<U>& rhs) { return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z; }

		// Compound assignment with other vectors
		template <class T, class U> SI_INLINE_CONSTEXPR vec2<T>& operator+=(vec2<T>& lhs, const vec2<U>& rhs) { lhs.x += rhs.x; lhs.y += rhs.y; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR vec3<T>& operator+=(vec3<T>& lhs, const vec3<U>& rhs) { lhs.x += rhs.x; lhs.y += rhs.y; lhs.z += rhs.z; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR vec2<T>& operator-=(vec2<T>& lhs, const vec2<U>& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR vec3<T>& operator-=(vec3<T>& lhs, const vec3<U>& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y; lhs.z -= rhs.z; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR vec2<T>& operator*=(vec2<T>& lhs, const vec2<U>& rhs) { lhs.x *= rhs.x; lhs.y *= rhs.y; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR vec3<T>& operator*=(vec3<T>& lhs, const vec3<U>& rhs) { lhs.x *= rhs.x; lhs.y *= rhs.y; lhs.z *= rhs.z; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR vec2<T>& operator/=(vec2<T>& lhs, const vec2<U>& rhs) { lhs.x /= rhs.x; lhs.y /= rhs.y; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR vec3<T>& operator/=(vec3<T>& lhs, const vec3<U>& rhs) { lhs.x /= rhs.x; lhs.y /= rhs.y; lhs.z /= rhs.z; return lhs; }

		// Compound assignment with scalars
		template <class T, class U> SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec2<T>&> operator+=(vec2<T>& lhs, U rhs) { lhs.x += rhs; lhs.y += rhs; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec3<T>&> operator+=(vec3<T>& lhs, U rhs) { lhs.x += rhs; lhs.y += rhs; lhs.z += rhs; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec2<T>&> operator-=(vec2<T>& lhs, U rhs) { lhs.x -= rhs; lhs.y -= rhs; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec3<T>&> operator-=(vec3<T>& lhs, U rhs) { lhs.x -= rhs; lhs.y -= rhs; lhs.z -= rhs; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec2<T>&> operator*=(vec2<T>& lhs, U rhs) { lhs.x *= rhs; lhs.y *= rhs; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec3<T>&> operator*=(vec3<T>& lhs, U rhs) { lhs.x *= rhs; lhs.y *= rhs; lhs.z *= rhs; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec2<T>&> operator/=(vec2<T>& lhs, U rhs) { lhs.x /= rhs; lhs.y /= rhs; return lhs; }
		template <class T, class U> SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec3<T>&> operator/=(vec3<T>& lhs, U rhs) { lhs.x /= rhs; lhs.y /= rhs; lhs.z /= rhs; return lhs; }

		// Binary operators with other vectors
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator+(const vec2<T>& lhs, const vec2<U>& rhs) { return {lhs.x + rhs.x, lhs.y + rhs.y }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator+(const vec3<T>& lhs, const vec3<U>& rhs) { return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator-(const vec2<T>& lhs, const vec2<U>& rhs) { return {lhs.x - rhs.x, lhs.y - rhs.y }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator-(const vec3<T>& lhs, const vec3<U>& rhs) { return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator*(const vec2<T>& lhs, const vec2<U>& rhs) { return {lhs.x * rhs.x, lhs.y * rhs.y }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator*(const vec3<T>& lhs, const vec3<U>& rhs) { return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator/(const vec2<T>& lhs, const vec2<U>& rhs) { return {lhs.x / rhs.x, lhs.y / rhs.y }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator/(const vec3<T>& lhs, const vec3<U>& rhs) { return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z }; }

		// Binary operators with scalars on the right side
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator+(const vec2<T>& lhs, U rhs) { return { lhs.x + rhs, lhs.y + rhs}; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator+(const vec3<T>& lhs, U rhs) { return { lhs.x + rhs, lhs.y + rhs, lhs.z + rhs}; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator-(const vec2<T>& lhs, U rhs) { return { lhs.x - rhs, lhs.y - rhs}; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator-(const vec3<T>& lhs, U rhs) { return { lhs.x - rhs, lhs.y - rhs, lhs.z - rhs}; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator*(const vec2<T>& lhs, U rhs) { return { lhs.x * rhs, lhs.y * rhs}; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator*(const vec3<T>& lhs, U rhs) { return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs}; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator/(const vec2<T>& lhs, U rhs) { return { lhs.x / rhs, lhs.y / rhs}; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator/(const vec3<T>& lhs, U rhs) { return { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs}; }

		// Binary operators with scalars on the left side
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator+(T lhs, const vec2<U>& rhs) { return { lhs + rhs.x, lhs + rhs.y }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator+(T lhs, const vec3<U>& rhs) { return { lhs + rhs.x, lhs + rhs.y, lhs + rhs.z }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator-(T lhs, const vec2<U>& rhs) { return { lhs - rhs.x, lhs - rhs.y }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator-(T lhs, const vec3<U>& rhs) { return { lhs - rhs.x, lhs - rhs.y, lhs - rhs.z }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator*(T lhs, const vec2<U>& rhs) { return { lhs * rhs.x, lhs * rhs.y }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator*(T lhs, const vec3<U>& rhs) { return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator/(T lhs, const vec2<U>& rhs) { return { lhs / rhs.x, lhs / rhs.y }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator/(T lhs, const vec3<U>& rhs) { return { lhs / rhs.x, lhs / rhs.y, lhs / rhs.z }; }

		// Absolute Value (componentwise)
		template <class T> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T>> abs(const vec2<T>& v) { return { std::abs(v.x), std::abs(v.y) }; }
		template <class T> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T>> abs(const vec3<T>& v) { return { std::abs(v.x), std::abs(v.y), std::abs(v.z) }; }

		// Sign Of (componentwise)
		template <class T> [[nodiscard]] SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T>, T> sign(T x) { return x > 0 ? 1 : x < 0 ? -1 : 0; }
		template <class T> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T>> sign(const vec2<T>& v) { return { sign(v.x), sign(v.y) }; }
		template <class T> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T>> sign(const vec3<T>& v) { return { sign(v.x), sign(v.y), sign(v.z) }; }

		// Min / Max (componentwise)
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, std::common_type_t<T, U>> min(T lhs, U rhs) { return (rhs < lhs) ? rhs : lhs; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, std::common_type_t<T, U>> max(T lhs, U rhs) { return (lhs < rhs) ? rhs : lhs; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> min(const vec2<T>& lhs, const vec2<U>& rhs) { return { min(lhs.x, rhs.x), min(lhs.y, rhs.y) }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> min(const vec3<T>& lhs, const vec3<U>& rhs) { return { min(lhs.x, rhs.x), min(lhs.y, rhs.y), min(lhs.z, rhs.z) }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> max(const vec2<T>& lhs, const vec2<U>& rhs) { return { max(lhs.x, rhs.x), max(lhs.y, rhs.y) }; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> max(const vec3<T>& lhs, const vec3<U>& rhs) { return { max(lhs.x, rhs.x), max(lhs.y, rhs.y), max(lhs.z, rhs.z) }; }

		// Clamping (componentwise)
		template <class T, class U, class V> [[nodiscard]] SI_INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T>, std::common_type_t<T, U, V>> clamp(T value, U min, V max) { return (min > value) ? min : (max < value) ? max : value; }
		template <class T, class U, class V> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U, V>> clamp(const vec2<T>& value, U min, V max) { return { clamp(value.x, min, max), clamp(value.y, min, max) }; }
		template <class T, class U, class V> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U, V>> clamp(const vec2<T>& value, const vec2<U>& min, const vec2<V>& max) { return { clamp(value.x, min.x, max.x), clamp(value.y, min.y, max.y) }; }
		template <class T, class U, class V> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U, V>> clamp(const vec3<T>& value, U min, V max) { return { clamp(value.x, min, max), clamp(value.y, min, max), clamp(value.z, min, max) }; }
		template <class T, class U, class V> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U, V>> clamp(const vec3<T>& value, const vec3<U>& min, const vec3<V>& max) { return { clamp(value.x, min.x, max.x), clamp(value.y, min.y, max.y), clamp(value.z, min.z, max.z) }; }

		// Dot Product / Inner Product of two vectors
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR auto dot(const vec2<T>& lhs, const vec2<U>& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR auto dot(const vec3<T>& lhs, const vec3<U>& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z; }

		// Euclidean Length of a vector
		template <class T> [[nodiscard]] SI_INLINE auto length(const vec2<T>& v) { return std::sqrt(dot(v, v)); }
		template <class T> [[nodiscard]] SI_INLINE auto length(const vec3<T>& v) { return std::sqrt(dot(v, v)); }

		// Normalization (returns null vector when given null vectors for robustness)
		// Multiplies with the inverse sqrt to be 1:1 compatible to GLM (avoids minimal, but noticeable deviations)
		template <class T> [[nodiscard]] SI_INLINE auto normalize(const vec2<T>& v) { auto l = length(v); return v * (l ? (1 / l) : 0); }
		template <class T> [[nodiscard]] SI_INLINE auto normalize(const vec3<T>& v) { auto l = length(v); return v * (l ? (1 / l) : 0); }

		// Euclidean Distance between to vectors / points
		template <class T, class U> [[nodiscard]] SI_INLINE auto distance(const vec2<T>& a, const vec2<U>& b) { return length(b - a); }
		template <class T, class U> [[nodiscard]] SI_INLINE auto distance(const vec3<T>& a, const vec3<U>& b) { return length(b - a); }

		// Cross Product / Outer Product of two vectors
		template <class T, class U> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> cross(const vec3<T>& lhs, const vec3<U>& rhs) { return { lhs.y * rhs.z - rhs.y * lhs.z, lhs.z * rhs.x - rhs.z * lhs.x, lhs.x * rhs.y - rhs.x * lhs.y }; }

		// Mixing / Interpolation (componentwise), returns `(1 - t) * a + t * b`
		template <class T, class U, class V> [[nodiscard]] SI_INLINE_CONSTEXPR std::common_type_t<T, U, V> mix(T a, U b, V t) { return (1 - t) * a + t * b; }
		template <class T, class U, class V> [[nodiscard]] SI_INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U, V>> mix(const vec2<T>& a, const vec2<U>& b, V t) { return { mix(a.x, b.x, t), mix(a.y, b.y, t) }; }
		template <class T, class U, class V> [[nodiscard]] SI_INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U, V>> mix(const vec3<T>& a, const vec3<U>& b, V t) { return { mix(a.x, b.x, t), mix(a.y, b.y, t), mix(a.z, b.z, t) }; }
	}

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
			  Mass=0, Time=-1, Temp=0, Current=0
			- force is mass times acceleration which is mass^1*length^1/time^2, so the exponents are
			  Length=1, Mass=1, Time=-2, Temp=0, Current=0

			This template converts this concept into a C++ type.
			In order to add a new exponent one has to update the three templates dimension, value_dimension and SI_DIMENSION_OP
		*/
		template <long Length, long Mass, long Time, long Temperature, long Current>
		struct dimension
		{
			static constexpr long length = Length;
			static constexpr long mass = Mass;
			static constexpr long time = Time;
			static constexpr long temperature = Temperature;
			static constexpr long current = Current;
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

		template <long Length, long Mass, long Time, long Temperature, long Current>
		struct dimension_of<dimension<Length, Mass, Time, Temperature, Current>>
		{
			using type = dimension<Length, Mass, Time, Temperature, Current>;
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
			Lhs::current op_ Rhs::current >

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
			static constexpr auto factor = static_cast<SIfloat>(Num) / Den;
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
		using promoted_scalar_type = std::conditional_t<std::is_same_v<scalar_value_type_t<T>, SIfloat>, SIfloat, SIfloat>;

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

			SI_INLINE_CONSTEXPR SIfloat operator()(const quantity<Dimension, SIfloat>& q) const
			{
				return value(q);
			}

			SI_INLINE_CONSTEXPR vec2<SIfloat> operator()(const quantity<Dimension, vec2<SIfloat>>& q) const
			{
				return value(q);
			}

			SI_INLINE_CONSTEXPR vec3<SIfloat> operator()(const quantity<Dimension, vec3<SIfloat>>& q) const
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
}

#undef SI_INLINE
#undef SI_INLINE_CONSTEXPR
