#pragma once
#include <cmath>
#include <type_traits>

/** \file
	
	Simple vector classes for arithmetic / geometric calculations.

	ATTower code usually uses the typedefs `Vec2` and `Vec3` (using double precision), but there is also support
	for int or float vectors. Vectors try to mimic scalar behavior when mixing types (e.g. int + double = double,
	doubles can be converted to int but might trigger a warning, etc.)

	Operations / functions are based off GLM. Reasons for not using GLM:
		* This gives us a self-contained module for this very basic demand, without having to
		  introduce a 3rdparty dependency all over the place
		* This gives us more control over nuanced behavior (supported conversions, operations,
		  handling NaNs, etc.)

	Applications can still choose to use GLM for code that heavily relies on more sophisticated GLM
	functions (transformations, projections, etc.)
*/

// Try to enforce inlining as much as possible, ideally we don't want any real function calls
// (performance overhead + annoyance when stepping through code)
#define ATTOWER_CORE_VEC_INLINE __forceinline
#define ATTOWER_CORE_VEC_CONSTEXPR constexpr ATTOWER_CORE_VEC_INLINE

// Forward-declare the GLM vec type, this allows for some interopability without having to include GLM
namespace glm
{
	enum qualifier; // NOLINT(clang-diagnostic-microsoft-enum-forward-reference)
	template<int, class, qualifier> struct vec; // Seems to work with a forward-declared enum, at least with MSVC...
}

namespace core
{
	namespace detail
	{
		// To properly support (unnamed) unions, vec2/vec3 has to be trivially constructible.
		// But for all "normal" cases, we want to have a proper default constructor (initializing to 0).
		// This tag allows switching between two implementations (one with trivial default constructor, one with a safe constructor).
		// While still maintaining a clean, simple template structure (`core::vec<double>` will give you the safe version, plain and simple)
		template <class T> struct vec_trivally_constructible { using type = T; };

		// Some helper to constructs to strip the `vec_trivally_constructible` tag off a type
		template <class T> struct vec_value_type { using type = T; };
		template <class T> struct vec_value_type<vec_trivally_constructible<T>> { using type = T; };
		template <class... T> using vec_common_type_t = std::common_type_t<typename vec_value_type<T>::type...>;
	}

	template <int N, class T>
	struct vec;

	// Implementation with proper default constructor -> take the trivial version and just add the missing constructor
	template <class T>
	struct vec<2, T> : vec<2, detail::vec_trivally_constructible<T>>
	{
		using vec<2, detail::vec_trivally_constructible<T>>::vec;

		// Default construct to 0
		ATTOWER_CORE_VEC_CONSTEXPR vec() : vec<2, detail::vec_trivally_constructible<T>>(0, 0) {}
	};

	// Implementing all the basic vector stuff, but with a trivial default constructor
	template <class T>
	struct vec<2, detail::vec_trivally_constructible<T>>
	{
		static_assert(std::is_arithmetic_v<T>);

		ATTOWER_CORE_VEC_CONSTEXPR vec() = default;

		ATTOWER_CORE_VEC_CONSTEXPR vec(T x, T y) : x(x), y(y)
		{
			// Some basic checks to make sure nothing weird is happening
			static_assert(sizeof(vec) == 2 * sizeof(T));
			static_assert(std::is_trivially_copyable_v<vec>);
		}

		// This constructor is used for explicit conversions from other value types
		template <class U>
		ATTOWER_CORE_VEC_CONSTEXPR explicit vec(const vec<2, U>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y)) {}

		// This operator is used for implicit conversions to other value types
		// Implemented to trigger the normal warnings when converting with precision loss
		template <class U>
		ATTOWER_CORE_VEC_CONSTEXPR operator vec<2, U>() const { return vec<2, U>(x, static_cast<detail::vec_common_type_t<U>>(y)); } // NOLINT(google-explicit-constructor)

		// Explicit conversion from vec3 (slicing off the z coordinate)
		template <class U>
		ATTOWER_CORE_VEC_CONSTEXPR explicit vec(const vec<3, U>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y)) {}

		// Returns false if null (and true for everything else, including NaN)
		ATTOWER_CORE_VEC_CONSTEXPR explicit operator bool() const noexcept { return !(x == 0 && y == 0); }

		// Support explicit conversion to / from GLM (only explicit to avoid ongoing, invisible back-and-forth conversions)
		template <class U, glm::qualifier Q> ATTOWER_CORE_VEC_CONSTEXPR explicit vec(const glm::vec<2, U, Q>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y)) {}
		template <class U, glm::qualifier Q> ATTOWER_CORE_VEC_CONSTEXPR explicit vec(const glm::vec<3, U, Q>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y)) {}
		template <class U, glm::qualifier Q> ATTOWER_CORE_VEC_CONSTEXPR explicit operator glm::vec<2, U, Q>() const { return { static_cast<U>(x), static_cast<U>(y) }; }

		T x;
		T y;
	};

	// Implementation with proper default constructor -> take the trivial version and just add the missing constructor
	template <class T>
	struct vec<3, T> : vec<3, detail::vec_trivally_constructible<T>>
	{
		using vec<3, detail::vec_trivally_constructible<T>>::vec;

		// Default construct to 0
		ATTOWER_CORE_VEC_CONSTEXPR vec() : vec<3, detail::vec_trivally_constructible<T>>(0, 0, 0) {}
	};

	// Implementing all the basic vector stuff, but with a trivial default constructor
	template <class T>
	struct vec<3, detail::vec_trivally_constructible<T>>
	{
		static_assert(std::is_arithmetic_v<T>);

		ATTOWER_CORE_VEC_CONSTEXPR vec() = default;
		
		ATTOWER_CORE_VEC_CONSTEXPR vec(T x, T y, T z) : x(x), y(y), z(z)
		{
			// Some basic checks to make sure nothing weird is happening
			static_assert(sizeof(vec) == 3 * sizeof(T));
			static_assert(std::is_trivially_copyable_v<vec>);
		}

		template <class U>
		ATTOWER_CORE_VEC_CONSTEXPR vec(const vec<2, U>& xy, T z) : vec(xy.x, xy.y, z) {}

		// This constructor is used for explicit conversions from other value types
		template <class U>
		ATTOWER_CORE_VEC_CONSTEXPR explicit vec(const vec<3, U>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y), static_cast<T>(other.z)) {}

		// This operator is used for implicit conversions to other value types
		// Implemented to trigger the normal warnings when converting with precision loss
		template <class U>
		ATTOWER_CORE_VEC_CONSTEXPR operator vec<3, U>() const { return vec<3, U>(x, static_cast<detail::vec_common_type_t<U>>(y), static_cast<detail::vec_common_type_t<U>>(z)); } // NOLINT(google-explicit-constructor)

		// Returns false if null (and true for everything else, including NaN)
		ATTOWER_CORE_VEC_CONSTEXPR explicit operator bool() const noexcept { return !(x == 0 && y == 0 && z == 0); }

		// Support explicit conversion to / from GLM (only explicit to avoid ongoing, invisible back-and-forth conversions)
		template <class U, glm::qualifier Q> ATTOWER_CORE_VEC_CONSTEXPR explicit vec(const glm::vec<3, U, Q>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y), static_cast<T>(other.z)) {}
		template <class U, glm::qualifier Q> ATTOWER_CORE_VEC_CONSTEXPR explicit vec(const glm::vec<4, U, Q>& other) : vec(static_cast<T>(other.x), static_cast<T>(other.y), static_cast<T>(other.z)) {}
		template <class U, glm::qualifier Q> ATTOWER_CORE_VEC_CONSTEXPR explicit operator glm::vec<3, U, Q>() const { return { static_cast<U>(x), static_cast<U>(y), static_cast<U>(z) }; }

		union
		{
			struct
			{
				T x;
				T y;
			};

			// Have to use the trivial implementation for usage in a union
			core::vec<2, detail::vec_trivally_constructible<T>> xy;
		};
		T z;
	};

	template <class T> using vec2 = vec<2, T>;
	template <class T> using vec3 = vec<3, T>;

	// Unary operators
	template <class T> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<T> operator-(const vec2<T>& v) { return { -v.x, -v.y }; }
	template <class T> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<T> operator-(const vec3<T>& v) { return { -v.x, -v.y, -v.z }; }

	// Comparsion operators
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR bool operator==(const vec2<T>& lhs, const vec2<U>& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR bool operator==(const vec3<T>& lhs, const vec3<U>& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR bool operator!=(const vec2<T>& lhs, const vec2<U>& rhs) { return lhs.x != rhs.x || lhs.y != rhs.y; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR bool operator!=(const vec3<T>& lhs, const vec3<U>& rhs) { return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z; }

	// Compound assignment with other vectors
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR vec2<T>& operator+=(vec2<T>& lhs, const vec2<U>& rhs) { lhs.x += rhs.x; lhs.y += rhs.y; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR vec3<T>& operator+=(vec3<T>& lhs, const vec3<U>& rhs) { lhs.x += rhs.x; lhs.y += rhs.y; lhs.z += rhs.z; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR vec2<T>& operator-=(vec2<T>& lhs, const vec2<U>& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR vec3<T>& operator-=(vec3<T>& lhs, const vec3<U>& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y; lhs.z -= rhs.z; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR vec2<T>& operator*=(vec2<T>& lhs, const vec2<U>& rhs) { lhs.x *= rhs.x; lhs.y *= rhs.y; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR vec3<T>& operator*=(vec3<T>& lhs, const vec3<U>& rhs) { lhs.x *= rhs.x; lhs.y *= rhs.y; lhs.z *= rhs.z; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR vec2<T>& operator/=(vec2<T>& lhs, const vec2<U>& rhs) { lhs.x /= rhs.x; lhs.y /= rhs.y; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR vec3<T>& operator/=(vec3<T>& lhs, const vec3<U>& rhs) { lhs.x /= rhs.x; lhs.y /= rhs.y; lhs.z /= rhs.z; return lhs; }

	// Compound assignment with scalars
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec2<T>&> operator+=(vec2<T>& lhs, U rhs) { lhs.x += rhs; lhs.y += rhs; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec3<T>&> operator+=(vec3<T>& lhs, U rhs) { lhs.x += rhs; lhs.y += rhs; lhs.z += rhs; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec2<T>&> operator-=(vec2<T>& lhs, U rhs) { lhs.x -= rhs; lhs.y -= rhs; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec3<T>&> operator-=(vec3<T>& lhs, U rhs) { lhs.x -= rhs; lhs.y -= rhs; lhs.z -= rhs; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec2<T>&> operator*=(vec2<T>& lhs, U rhs) { lhs.x *= rhs; lhs.y *= rhs; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec3<T>&> operator*=(vec3<T>& lhs, U rhs) { lhs.x *= rhs; lhs.y *= rhs; lhs.z *= rhs; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec2<T>&> operator/=(vec2<T>& lhs, U rhs) { lhs.x /= rhs; lhs.y /= rhs; return lhs; }
	template <class T, class U> ATTOWER_CORE_VEC_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<U>, vec3<T>&> operator/=(vec3<T>& lhs, U rhs) { lhs.x /= rhs; lhs.y /= rhs; lhs.z /= rhs; return lhs; }

	// Binary operators with other vectors
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator+(const vec2<T>& lhs, const vec2<U>& rhs) { return {lhs.x + rhs.x, lhs.y + rhs.y }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator+(const vec3<T>& lhs, const vec3<U>& rhs) { return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator-(const vec2<T>& lhs, const vec2<U>& rhs) { return {lhs.x - rhs.x, lhs.y - rhs.y }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator-(const vec3<T>& lhs, const vec3<U>& rhs) { return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator*(const vec2<T>& lhs, const vec2<U>& rhs) { return {lhs.x * rhs.x, lhs.y * rhs.y }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator*(const vec3<T>& lhs, const vec3<U>& rhs) { return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator/(const vec2<T>& lhs, const vec2<U>& rhs) { return {lhs.x / rhs.x, lhs.y / rhs.y }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator/(const vec3<T>& lhs, const vec3<U>& rhs) { return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z }; }

	// Binary operators with scalars on the right side
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator+(const vec2<T>& lhs, U rhs) { return { lhs.x + rhs, lhs.y + rhs}; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator+(const vec3<T>& lhs, U rhs) { return { lhs.x + rhs, lhs.y + rhs, lhs.z + rhs}; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator-(const vec2<T>& lhs, U rhs) { return { lhs.x - rhs, lhs.y - rhs}; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator-(const vec3<T>& lhs, U rhs) { return { lhs.x - rhs, lhs.y - rhs, lhs.z - rhs}; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator*(const vec2<T>& lhs, U rhs) { return { lhs.x * rhs, lhs.y * rhs}; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator*(const vec3<T>& lhs, U rhs) { return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs}; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator/(const vec2<T>& lhs, U rhs) { return { lhs.x / rhs, lhs.y / rhs}; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator/(const vec3<T>& lhs, U rhs) { return { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs}; }

	// Binary operators with scalars on the left side
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator+(T lhs, const vec2<U>& rhs) { return { lhs + rhs.x, lhs + rhs.y }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator+(T lhs, const vec3<U>& rhs) { return { lhs + rhs.x, lhs + rhs.y, lhs + rhs.z }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator-(T lhs, const vec2<U>& rhs) { return { lhs - rhs.x, lhs - rhs.y }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator-(T lhs, const vec3<U>& rhs) { return { lhs - rhs.x, lhs - rhs.y, lhs - rhs.z }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator*(T lhs, const vec2<U>& rhs) { return { lhs * rhs.x, lhs * rhs.y }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator*(T lhs, const vec3<U>& rhs) { return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> operator/(T lhs, const vec2<U>& rhs) { return { lhs / rhs.x, lhs / rhs.y }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> operator/(T lhs, const vec3<U>& rhs) { return { lhs / rhs.x, lhs / rhs.y, lhs / rhs.z }; }

	// Absolute Value (componentwise)
	template <class T> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T>> abs(const vec2<T>& v) { return { std::abs(v.x), std::abs(v.y) }; }
	template <class T> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T>> abs(const vec3<T>& v) { return { std::abs(v.x), std::abs(v.y), std::abs(v.z) }; }

	// Sign Of (componentwise)
	template <class T> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T>, T> sign(T x) { return x > 0 ? 1 : x < 0 ? -1 : 0; }
	template <class T> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T>> sign(const vec2<T>& v) { return { sign(v.x), sign(v.y) }; }
	template <class T> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T>> sign(const vec3<T>& v) { return { sign(v.x), sign(v.y), sign(v.z) }; }

	// Min / Max (componentwise)
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, std::common_type_t<T, U>> min(T lhs, U rhs) { return (rhs < lhs) ? rhs : lhs; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, std::common_type_t<T, U>> max(T lhs, U rhs) { return (lhs < rhs) ? rhs : lhs; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> min(const vec2<T>& lhs, const vec2<U>& rhs) { return { min(lhs.x, rhs.x), min(lhs.y, rhs.y) }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> min(const vec3<T>& lhs, const vec3<U>& rhs) { return { min(lhs.x, rhs.x), min(lhs.y, rhs.y), min(lhs.z, rhs.z) }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U>> max(const vec2<T>& lhs, const vec2<U>& rhs) { return { max(lhs.x, rhs.x), max(lhs.y, rhs.y) }; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> max(const vec3<T>& lhs, const vec3<U>& rhs) { return { max(lhs.x, rhs.x), max(lhs.y, rhs.y), max(lhs.z, rhs.z) }; }

	// Clamping (componentwise)
	template <class T, class U, class V> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR std::enable_if_t<std::is_arithmetic_v<T>, std::common_type_t<T, U, V>> clamp(T value, U min, V max) { return (min > value) ? min : (max < value) ? max : value; }
	template <class T, class U, class V> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U, V>> clamp(const vec2<T>& value, U min, V max) { return { clamp(value.x, min, max), clamp(value.y, min, max) }; }
	template <class T, class U, class V> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U, V>> clamp(const vec2<T>& value, const vec2<U>& min, const vec2<V>& max) { return { clamp(value.x, min.x, max.x), clamp(value.y, min.y, max.y) }; }
	template <class T, class U, class V> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U, V>> clamp(const vec3<T>& value, U min, V max) { return { clamp(value.x, min, max), clamp(value.y, min, max), clamp(value.z, min, max) }; }
	template <class T, class U, class V> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U, V>> clamp(const vec3<T>& value, const vec3<U>& min, const vec3<V>& max) { return { clamp(value.x, min.x, max.x), clamp(value.y, min.y, max.y), clamp(value.z, min.z, max.z) }; }

	// Dot Product / Inner Product of two vectors
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR auto dot(const vec2<T>& lhs, const vec2<U>& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR auto dot(const vec3<T>& lhs, const vec3<U>& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z; }

	// Euclidean Length of a vector
	template <class T> [[nodiscard]] ATTOWER_CORE_VEC_INLINE auto length(const vec2<T>& v) { return std::sqrt(dot(v, v)); }
	template <class T> [[nodiscard]] ATTOWER_CORE_VEC_INLINE auto length(const vec3<T>& v) { return std::sqrt(dot(v, v)); }

	// Normalization (returns null vector when given null vectors for robustness)
	// Multiplies with the inverse sqrt to be 1:1 compatible to GLM (avoids minimal, but noticeable deviations)
	template <class T> [[nodiscard]] ATTOWER_CORE_VEC_INLINE auto normalize(const vec2<T>& v) { auto l = length(v); return v * (l ? (1 / l) : 0); }
	template <class T> [[nodiscard]] ATTOWER_CORE_VEC_INLINE auto normalize(const vec3<T>& v) { auto l = length(v); return v * (l ? (1 / l) : 0); }

	// Euclidean Distance between to vectors / points
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_INLINE auto distance(const vec2<T>& a, const vec2<U>& b) { return length(b - a); }
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_INLINE auto distance(const vec3<T>& a, const vec3<U>& b) { return length(b - a); }

	// Cross Product / Outer Product of two vectors
	template <class T, class U> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U>> cross(const vec3<T>& lhs, const vec3<U>& rhs) { return { lhs.y * rhs.z - rhs.y * lhs.z, lhs.z * rhs.x - rhs.z * lhs.x, lhs.x * rhs.y - rhs.x * lhs.y }; }

	// Mixing / Interpolation (componentwise), returns `(1 - t) * a + t * b`
	template <class T, class U, class V> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR std::common_type_t<T, U, V> mix(T a, U b, V t) { return (1 - t) * a + t * b; }
	template <class T, class U, class V> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec2<detail::vec_common_type_t<T, U, V>> mix(const vec2<T>& a, const vec2<U>& b, V t) { return { mix(a.x, b.x, t), mix(a.y, b.y, t) }; }
	template <class T, class U, class V> [[nodiscard]] ATTOWER_CORE_VEC_CONSTEXPR vec3<detail::vec_common_type_t<T, U, V>> mix(const vec3<T>& a, const vec3<U>& b, V t) { return { mix(a.x, b.x, t), mix(a.y, b.y, t), mix(a.z, b.z, t) }; }
}

#undef ATTOWER_CORE_VEC_INLINE
#undef ATTOWER_CORE_VEC_CONSTEXPR

// Typedefs for common ATTower usage (More concise, fits better with legacy code)
using Vec2 = core::vec2<double>;
using Vec3 = core::vec3<double>;
using Vec2f = core::vec2<float>;
using Vec3f = core::vec3<float>;
using Vec2i = core::vec2<int>;
using Vec3i = core::vec3<int>;

// Typedefs ONLY for usage in unions
// These types are fully compatible with the normal Vec*, but DO NOT ZERO INITIALIZE themselves
// This allows them to be used in C-ish unions (also see ATTOWER_CORE_COMPATIBILITY_VEC* below)
using UnionVec2 = core::vec2<core::detail::vec_trivally_constructible<double>>;
using UnionVec3 = core::vec3<core::detail::vec_trivally_constructible<double>>;

// Compatibility unions to support introduction of core::vec into legacy structures
// This macro defines a union that makes a point / vector accessible via both core::vec and primitive
// data members (e.g. `pm->posx` will be identical to `pm->pos.x`).
// This makes it possible to transition from primitive types to core::vec step by step
// !! NOTE: This compatibility union will NOT initialize itself to zero, just like primitive types !!
// (This is necessary due to restrictions of unions in C++, or actually the MSVC compiler in this case)
#define ATTOWER_CORE_COMPATIBILITY_VEC2(type_, vec_, x_, y_)	\
	union { core::vec2<core::detail::vec_trivally_constructible<type_>> vec_; struct { type_ x_; type_ y_; }; }
#define ATTOWER_CORE_COMPATIBILITY_VEC3(type_, vec_, x_, y_, z_)	\
	union { core::vec3<core::detail::vec_trivally_constructible<type_>> vec_; struct { type_ x_; type_ y_; type_ z_; }; }