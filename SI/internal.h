// SI/internal.h - internal datatypes, classes, etc.
#pragma once

#include <cmath>
#include <type_traits>
#define INLINE inline 
#define INLINE_CONSTEXPR constexpr inline

namespace SI
{
	typedef double SIfloat;      // <-- internal datatype to hold floating point values

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

			INLINE_CONSTEXPR vec() : vec<2, detail::vec_trivally_constructible<T>>(0, 0) {}
		};

		template <class T>
		struct vec<2, detail::vec_trivally_constructible<T>>
		{
			static_assert(std::is_arithmetic_v<T>);

			INLINE_CONSTEXPR vec() = default;

			INLINE_CONSTEXPR vec(T x, T y) : x(x), y(y)
			{
				static_assert(sizeof(vec) == 2 * sizeof(T));
				static_assert(std::is_trivially_copyable_v<vec>);
			}

			template <class U>
			INLINE_CONSTEXPR explicit vec(const vec<2, U>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y)) {}

			template <class U>
			INLINE_CONSTEXPR operator vec<2, U>() const { return vec<2, U>(x, static_cast<detail::vec_common_type_t<U>>(y)); } // NOLINT(google-explicit-constructor)

			template <class U>
			INLINE_CONSTEXPR explicit vec(const vec<3, U>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y)) {}

			INLINE_CONSTEXPR explicit operator bool() const noexcept { return !(x == 0 && y == 0); }

			T x;
			T y;
		};

		template <class T>
		struct vec<3, T> : vec<3, detail::vec_trivally_constructible<T>>
		{
			using vec<3, detail::vec_trivally_constructible<T>>::vec;
			INLINE_CONSTEXPR vec() : vec<3, detail::vec_trivally_constructible<T>>(0, 0, 0) {}
		};

		template <class T>
		struct vec<3, detail::vec_trivally_constructible<T>>
		{
			static_assert(std::is_arithmetic_v<T>);

			INLINE_CONSTEXPR vec() = default;
			
			INLINE_CONSTEXPR vec(T x, T y, T z) : x(x), y(y), z(z)
			{
				static_assert(sizeof(vec) == 3 * sizeof(T));
				static_assert(std::is_trivially_copyable_v<vec>);
			}

			template <class U>
			INLINE_CONSTEXPR vec(const vec<2, U>& xy, T z) : vec(xy.x, xy.y, z) {}

			template <class U>
			INLINE_CONSTEXPR explicit vec(const vec<3, U>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y), static_cast<T>(other.z)) {}

			template <class U>
			INLINE_CONSTEXPR operator vec<3, U>() const { return vec<3, U>(x, static_cast<detail::vec_common_type_t<U>>(y), static_cast<detail::vec_common_type_t<U>>(z)); } // NOLINT(google-explicit-constructor)

			INLINE_CONSTEXPR explicit operator bool() const noexcept { return !(x == 0 && y == 0 && z == 0); }
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
		template <class T> [[nodiscard]] INLINE_CONSTEXPR vec2<T> operator-(const vec2<T>& v) { return { -v.x, -v.y }; }
		template <class T> [[nodiscard]] INLINE_CONSTEXPR vec3<T> operator-(const vec3<T>& v) { return { -v.x, -v.y, -v.z }; }

		// Comparsion operators
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR bool operator==(const vec2<T>& lhs, const vec2<U>& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR bool operator==(const vec3<T>& lhs, const vec3<U>& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR bool operator!=(const vec2<T>& lhs, const vec2<U>& rhs) { return lhs.x != rhs.x || lhs.y != rhs.y; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR bool operator!=(const vec3<T>& lhs, const vec3<U>& rhs) { return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z; }

		// Compound assignment with other vectors
		template <class T, class U> INLINE_CONSTEXPR vec2<T>& operator+=(vec2<T>& lhs, const vec2<U>& rhs) { lhs.x += rhs.x; lhs.y += rhs.y; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR vec3<T>& operator+=(vec3<T>& lhs, const vec3<U>& rhs) { lhs.x += rhs.x; lhs.y += rhs.y; lhs.z += rhs.z; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR vec2<T>& operator-=(vec2<T>& lhs, const vec2<U>& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR vec3<T>& operator-=(vec3<T>& lhs, const vec3<U>& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y; lhs.z -= rhs.z; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR vec2<T>& operator*=(vec2<T>& lhs, const vec2<U>& rhs) { lhs.x *= rhs.x; lhs.y *= rhs.y; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR vec3<T>& operator*=(vec3<T>& lhs, const vec3<U>& rhs) { lhs.x *= rhs.x; lhs.y *= rhs.y; lhs.z *= rhs.z; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR vec2<T>& operator/=(vec2<T>& lhs, const vec2<U>& rhs) { lhs.x /= rhs.x; lhs.y /= rhs.y; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR vec3<T>& operator/=(vec3<T>& lhs, const vec3<U>& rhs) { lhs.x /= rhs.x; lhs.y /= rhs.y; lhs.z /= rhs.z; return lhs; }

		// Compound assignment with scalars
		template <class T, class U> INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec2<T>&> operator+=(vec2<T>& lhs, U rhs) { lhs.x += rhs; lhs.y += rhs; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec3<T>&> operator+=(vec3<T>& lhs, U rhs) { lhs.x += rhs; lhs.y += rhs; lhs.z += rhs; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec2<T>&> operator-=(vec2<T>& lhs, U rhs) { lhs.x -= rhs; lhs.y -= rhs; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec3<T>&> operator-=(vec3<T>& lhs, U rhs) { lhs.x -= rhs; lhs.y -= rhs; lhs.z -= rhs; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec2<T>&> operator*=(vec2<T>& lhs, U rhs) { lhs.x *= rhs; lhs.y *= rhs; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec3<T>&> operator*=(vec3<T>& lhs, U rhs) { lhs.x *= rhs; lhs.y *= rhs; lhs.z *= rhs; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec2<T>&> operator/=(vec2<T>& lhs, U rhs) { lhs.x /= rhs; lhs.y /= rhs; return lhs; }
		template <class T, class U> INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec3<T>&> operator/=(vec3<T>& lhs, U rhs) { lhs.x /= rhs; lhs.y /= rhs; lhs.z /= rhs; return lhs; }

		// Binary operators with other vectors
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator+(const vec2<T>& lhs, const vec2<U>& rhs) { return {lhs.x + rhs.x, lhs.y + rhs.y }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator+(const vec3<T>& lhs, const vec3<U>& rhs) { return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator-(const vec2<T>& lhs, const vec2<U>& rhs) { return {lhs.x - rhs.x, lhs.y - rhs.y }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator-(const vec3<T>& lhs, const vec3<U>& rhs) { return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator*(const vec2<T>& lhs, const vec2<U>& rhs) { return {lhs.x * rhs.x, lhs.y * rhs.y }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator*(const vec3<T>& lhs, const vec3<U>& rhs) { return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator/(const vec2<T>& lhs, const vec2<U>& rhs) { return {lhs.x / rhs.x, lhs.y / rhs.y }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator/(const vec3<T>& lhs, const vec3<U>& rhs) { return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z }; }

		// Binary operators with scalars on the right side
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator+(const vec2<T>& lhs, U rhs) { return { lhs.x + rhs, lhs.y + rhs}; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator+(const vec3<T>& lhs, U rhs) { return { lhs.x + rhs, lhs.y + rhs, lhs.z + rhs}; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator-(const vec2<T>& lhs, U rhs) { return { lhs.x - rhs, lhs.y - rhs}; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator-(const vec3<T>& lhs, U rhs) { return { lhs.x - rhs, lhs.y - rhs, lhs.z - rhs}; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator*(const vec2<T>& lhs, U rhs) { return { lhs.x * rhs, lhs.y * rhs}; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator*(const vec3<T>& lhs, U rhs) { return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs}; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator/(const vec2<T>& lhs, U rhs) { return { lhs.x / rhs, lhs.y / rhs}; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator/(const vec3<T>& lhs, U rhs) { return { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs}; }

		// Binary operators with scalars on the left side
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator+(T lhs, const vec2<U>& rhs) { return { lhs + rhs.x, lhs + rhs.y }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator+(T lhs, const vec3<U>& rhs) { return { lhs + rhs.x, lhs + rhs.y, lhs + rhs.z }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator-(T lhs, const vec2<U>& rhs) { return { lhs - rhs.x, lhs - rhs.y }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator-(T lhs, const vec3<U>& rhs) { return { lhs - rhs.x, lhs - rhs.y, lhs - rhs.z }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator*(T lhs, const vec2<U>& rhs) { return { lhs * rhs.x, lhs * rhs.y }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator*(T lhs, const vec3<U>& rhs) { return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator/(T lhs, const vec2<U>& rhs) { return { lhs / rhs.x, lhs / rhs.y }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator/(T lhs, const vec3<U>& rhs) { return { lhs / rhs.x, lhs / rhs.y, lhs / rhs.z }; }

		// Absolute Value (componentwise)
		template <class T> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T>> abs(const vec2<T>& v) { return { std::abs(v.x), std::abs(v.y) }; }
		template <class T> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T>> abs(const vec3<T>& v) { return { std::abs(v.x), std::abs(v.y), std::abs(v.z) }; }

		// Sign Of (componentwise)
		template <class T> [[nodiscard]] INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T>, T> sign(T x) { return x > 0 ? 1 : x < 0 ? -1 : 0; }
		template <class T> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T>> sign(const vec2<T>& v) { return { sign(v.x), sign(v.y) }; }
		template <class T> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T>> sign(const vec3<T>& v) { return { sign(v.x), sign(v.y), sign(v.z) }; }

		// Min / Max (componentwise)
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, std::common_type_t<T, U>> min(T lhs, U rhs) { return (rhs < lhs) ? rhs : lhs; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, std::common_type_t<T, U>> max(T lhs, U rhs) { return (lhs < rhs) ? rhs : lhs; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> min(const vec2<T>& lhs, const vec2<U>& rhs) { return { min(lhs.x, rhs.x), min(lhs.y, rhs.y) }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> min(const vec3<T>& lhs, const vec3<U>& rhs) { return { min(lhs.x, rhs.x), min(lhs.y, rhs.y), min(lhs.z, rhs.z) }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> max(const vec2<T>& lhs, const vec2<U>& rhs) { return { max(lhs.x, rhs.x), max(lhs.y, rhs.y) }; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> max(const vec3<T>& lhs, const vec3<U>& rhs) { return { max(lhs.x, rhs.x), max(lhs.y, rhs.y), max(lhs.z, rhs.z) }; }

		// Clamping (componentwise)
		template <class T, class U, class V> [[nodiscard]] INLINE_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T>, std::common_type_t<T, U, V>> clamp(T value, U min, V max) { return (min > value) ? min : (max < value) ? max : value; }
		template <class T, class U, class V> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U, V>> clamp(const vec2<T>& value, U min, V max) { return { clamp(value.x, min, max), clamp(value.y, min, max) }; }
		template <class T, class U, class V> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U, V>> clamp(const vec2<T>& value, const vec2<U>& min, const vec2<V>& max) { return { clamp(value.x, min.x, max.x), clamp(value.y, min.y, max.y) }; }
		template <class T, class U, class V> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U, V>> clamp(const vec3<T>& value, U min, V max) { return { clamp(value.x, min, max), clamp(value.y, min, max), clamp(value.z, min, max) }; }
		template <class T, class U, class V> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U, V>> clamp(const vec3<T>& value, const vec3<U>& min, const vec3<V>& max) { return { clamp(value.x, min.x, max.x), clamp(value.y, min.y, max.y), clamp(value.z, min.z, max.z) }; }

		// Dot Product / Inner Product of two vectors
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR auto dot(const vec2<T>& lhs, const vec2<U>& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR auto dot(const vec3<T>& lhs, const vec3<U>& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z; }

		// Euclidean Length of a vector
		template <class T> [[nodiscard]] INLINE auto length(const vec2<T>& v) { return std::sqrt(dot(v, v)); }
		template <class T> [[nodiscard]] INLINE auto length(const vec3<T>& v) { return std::sqrt(dot(v, v)); }

		// Normalization (returns null vector when given null vectors for robustness)
		// Multiplies with the inverse sqrt to be 1:1 compatible to GLM (avoids minimal, but noticeable deviations)
		template <class T> [[nodiscard]] INLINE auto normalize(const vec2<T>& v) { auto l = length(v); return v * (l ? (1 / l) : 0); }
		template <class T> [[nodiscard]] INLINE auto normalize(const vec3<T>& v) { auto l = length(v); return v * (l ? (1 / l) : 0); }

		// Euclidean Distance between to vectors / points
		template <class T, class U> [[nodiscard]] INLINE auto distance(const vec2<T>& a, const vec2<U>& b) { return length(b - a); }
		template <class T, class U> [[nodiscard]] INLINE auto distance(const vec3<T>& a, const vec3<U>& b) { return length(b - a); }

		// Cross Product / Outer Product of two vectors
		template <class T, class U> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> cross(const vec3<T>& lhs, const vec3<U>& rhs) { return { lhs.y * rhs.z - rhs.y * lhs.z, lhs.z * rhs.x - rhs.z * lhs.x, lhs.x * rhs.y - rhs.x * lhs.y }; }

		// Mixing / Interpolation (componentwise), returns `(1 - t) * a + t * b`
		template <class T, class U, class V> [[nodiscard]] INLINE_CONSTEXPR std::common_type_t<T, U, V> mix(T a, U b, V t) { return (1 - t) * a + t * b; }
		template <class T, class U, class V> [[nodiscard]] INLINE_CONSTEXPR vec2<detail::vec_common_type_t<T, U, V>> mix(const vec2<T>& a, const vec2<U>& b, V t) { return { mix(a.x, b.x, t), mix(a.y, b.y, t) }; }
		template <class T, class U, class V> [[nodiscard]] INLINE_CONSTEXPR vec3<detail::vec_common_type_t<T, U, V>> mix(const vec3<T>& a, const vec3<U>& b, V t) { return { mix(a.x, b.x, t), mix(a.y, b.y, t), mix(a.z, b.z, t) }; }
	}
}

#undef INLINE
#undef INLINE_CONSTEXPR
