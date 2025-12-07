#pragma once
#include <cassert>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <type_traits>

#include <boost/type_traits/function_traits.hpp>

#if LINUX
namespace std
{
	using byte = unsigned char;
}
#else
#include <Windows.h>
#endif

#include <tower/core/cutility.h>

namespace core
{
	/// sprintf to std::string
	/**
		Works like sprintf, but instead of writing the data to a user allocated buffer, it returns
		a std::string holding the formatted result.

		This function also performs some basic checking of the passed format string / the passed
		arguments and asserts if something is wrong.
	*/
#if ATTOWER_TIDY == 0
	template <class... Args>
	std::string strprintf(const char* format, Args&&... args);
#endif

	/// vsprintf to std::string
	/**
		Works like vsprintf, but instead of writing the data to a user allocated buffer, it returns
		a std::string holding the formatted result.
	*/
	std::string vstrprintf(const char* format, va_list args);

	/// sprintf to output stream
	/**
		Works like sprintf, but instead of taking a user allocated buffer, it takes
		a std::ostream as first argument.

		This function also performs some basic checking of the passed format string / the passed
		arguments and asserts if something is wrong.
	*/
#if ATTOWER_TIDY == 0
	template <class OutputStream, class... Args>
	size_t osprintf(OutputStream& os, const char* format, Args&&... args)
	{
		auto str = strprintf(format, std::forward<Args>(args)...);
		os << str;

		return str.size();
	}
#endif

	/// throw std::runtime_error with formatted message
	/**
		Uses strprintf to format a message and throws a runtime_error with this message.
	*/
#if ATTOWER_TIDY == 0
	template <typename... Args>
	[[noreturn]] void throwf(const char* format, Args&&... args)
	{
		std::string what = strprintf(format, std::forward<Args>(args)...);
		throw std::runtime_error{ std::move(what) };
	}
#endif

#if LINUX == 0

	/// Converts a wide character UTF-16 string to UTF-8
	/**
		Windows unicode functions (functions ending in "W" as opposed to "A") are returning
		UTF-16 wide character strings. This function can be used to convert the string right
		into the preferred UTF-8 encoding.
	*/
	std::string to_utf8(std::wstring_view wide);

	/// Converts a UTF-8 string to wide character UTF-16
	/**
		Windows unicode functions (functions ending in "W" as opposed to "A") are taking
		UTF-16 wide character strings. This function can be used to convert the preferred UTF-8
		to UTF-16 right before calling the windows function.
	*/
	std::wstring to_wide(std::string_view utf8);

	///@{
	/// Copies a string into a fixed-size character buffer, truncating if necessary
	/**
		This function is UTF-8 aware (unlike e.g. `strncpy`), i.e. it won't split multi-byte
		UTF-8 characters inbetween when truncating.

		If no truncation is desired, `strcpy_s` can be used.
	*/
	size_t truncate(char* buffer, size_t size, std::string_view str);

	template <size_t N>
	size_t truncate(char(&buffer)[N], std::string_view str)
	{
		return truncate(buffer, N, str);
	}
	///@}

#endif

	/// Executes a functor at the end of the current scope
	/**
		Can be used for releasing of resources and such, allows to have
		the benefits of RAII without having to write a RAII wrapper for
		every single situation.

		Simply put a lambda expression right after CORE_ON_EXIT, starting
		with the capture clause. Example:

		HANDLE handle = FindFirstFile(...);
		CORE_ON_EXIT[handle]
		{
			FindClose(handle);
		};
	*/
#define CORE_ON_EXIT										\
	__pragma(warning(suppress : 4189))						\
	const auto& CORE_DETAIL_CONCAT(on_exit_, __LINE__) =	\
	::core::detail::on_exit_tag() |

	/// Compresses the given raw data using zlib
	std::vector<std::byte> compress(const void* ptr, std::size_t size);

	/// Decompresses the given compressed data using zlib
	/**
		`guess` should be an upper limit for the expected decompressed data size. If it is to small,
		there will be a small performance penalty.

		May throw an exception on failure (e.g. invalid data).
	*/
	std::vector<std::byte> decompress(const void* ptr, std::size_t size, std::size_t guess = 0);

#if LINUX == 0

	/// Utility function for comparing a single value against a set of value
	/**
		Example:

		```
		if (str == core::any_of("alpha", "bravo", "charlie")) // "if str is equal to any of"
		```
		Is equivalent to:
		```
		if (str == "alpha" || str == "bravo" || str == "charlie")  // "if str is equal to any of"
		```

		```
		if (str != core::any_of("alpha", "bravo", "charlie")) // "if str is not equal to any of"
		```
		Is equivalent to:
		```
		if (str != "alpha" && str != "bravo" && str != "charlie")  // "if str is not equal to any of"
		```
	*/
	template <class... T>
	auto any_of(const T&... values);

	/// Utility function for "overloading" lambdas
	/**
		This function combines all given functors into one single functor, "overloading" the functor's
		operator(). This can be used to create a functor with type-specific implementations.

		Example:
		```
		// Define the various overloads
		auto ints = [](int value) { ... };
		auto strings = [](const std::string& value) { ... };
		
		// Combine them into one functor
		auto f = core::overload(ints, strings);

		// `f` can now handle both `int` and `std::string`
		f(42);
		f("42");
	*/
	template <class... F>
	auto overload(F... f);

	/// Returns an integer with the given bit set (e.g. core::bit<2> == 4)
	template <size_t N>
	inline constexpr std::uintmax_t bit = (1ull << N);

	///@{
	/// Downcasts a base pointer to a derived type using `dynamic_cast`
	/**
		Unlike dynamic_cast, this function asserts that it is actually a derived class.
	*/
	template <class Derived, class Base>
	Derived* downcast(Base* base)
	{
		static_assert(std::is_base_of_v<Base, Derived>);
		return dynamic_cast<Derived*>(base);
	}

	template <class Derived, class Base>
	const Derived* downcast(const Base* base)
	{
		static_assert(std::is_base_of_v<Base, Derived>);
		return dynamic_cast<const Derived*>(base);
	}
	///@}

	/// Replacement for `std::recursive_mutex` based on Windows CRITICAL_SECTION
	/**
		.NET Projects like Analyse don't support <mutex> or <thread>, so this class has to be used
		for locking in common library code instead.
	*/
	class critical_section
	{
	public:
		/// Replacement for `std::unique_lock<critical_section>`
		class scoped_lock {
		public:
			explicit scoped_lock(critical_section& critical_section);
			~scoped_lock();

			scoped_lock(const scoped_lock&) = delete;
			scoped_lock& operator=(const scoped_lock&) = delete;

			void lock();
			void unlock();

		private:
			critical_section* m_critical_section;
			bool m_locked;
		};

		critical_section();
		~critical_section();

		critical_section(const critical_section&) = delete;
		critical_section& operator=(const critical_section&) = delete;

		void lock();
		void unlock();
	private:
		CRITICAL_SECTION m_cs;
	};

	/// Templated WNDPROC that relays windows messages to a object method
	/**
		The method's signature must be LRESULT(HWND, UINT, WPARAM, LPARAM).
		CreateWindow must be called with the object pointer as lpParam.
		This proxy function uses GWLP_USERDATA to store the object pointer with the window.

		Example:
		```
		WNDCLASSW wc = {};
		wc.lpfnWndProc = window_method_proxy<&MyClass::windowProc>;
		//...
		CreateWindowW(wc.lpszClassName, "", 0, 0, 0, 0, 0, HWND_MESSAGE, nullptr, wc.hInstance, pointerToMyClass);
		```
	*/
	template <auto WindowMethod>
	LRESULT CALLBACK window_method_proxy(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	/// Templated DLGPROC that relays windows messages to a object method
	/**
		The method's signature must be INT_PTR(HWND, UINT, WPARAM, LPARAM).
		CreateDialogParam must be called with the object pointer as dwInitParam.
		This proxy function uses DWLP_USER to store the object pointer with the window.

		Example:
		```
		CreateDialogParam(hInstance, "", parent, dialog_method_proxy<&MyClass::dialogProc>, reinterpret_cast<LPARAM>(pointerToMyClass))
		```
	*/
	template <auto WindowMethod>
	INT_PTR CALLBACK dialog_method_proxy(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

	/// Subclass an already existing window
	/**
		Sets the given object pointer as GWLP_USERDATA and subclasses the window
		using window_method_proxy.
	*/
	template <auto WindowMethod, class T>
	WNDPROC window_method_subclass(HWND hWnd, T* object);
#endif

	///@{
	/// Checks if a type is a smart pointer (e.g. unique_ptr, shared_ptr)
	template <class T>
	struct is_smart_pointer : std::false_type {};

	template <class T>
	struct is_smart_pointer<std::unique_ptr<T>> : std::true_type {};

	template <class T>
	struct is_smart_pointer<std::shared_ptr<T>> : std::true_type {};

	template <class T>
	inline constexpr bool is_smart_pointer_v = is_smart_pointer<T>::value;
	///@}

	/// Unified access to get the pointer to a object, works with references, pointers and smart pointers.
	template <class T>
	decltype(auto) ptr(T&& object)
	{
		if constexpr (std::is_pointer<std::decay_t<T>>::value)
			return object;
		else if constexpr (is_smart_pointer_v<std::decay_t<T>>)
			return object.get();
		else
			return &object;
	}

	/// Unified access to object members, works with references, pointers, smart pointers, member fields and member methods.
	/**
		Example:

		```
		struct foo
		{
			int field;
			const std::string& method() const;
		};
		auto str = member(f, &foo::method); // access method by object reference
		member(&f, &foo:field) = 10; // access field by object pointer
		```
	*/
	template <class T, class Member>
	decltype(auto) member(T&& object, Member m)
	{
		if constexpr (std::is_member_function_pointer<Member>::value)
			return (ptr(object)->*m)();
		else
			return ptr(object)->*m;
	}

	/// boost::function_traits for all callable types
	/**
		this trait offers the same functionality as boost::function_traits, but supports
		all callable types (functions, function pointers, methods, functors)
	*/
	template <class F>
	struct functor_traits;

	namespace detail
	{
		template <class...> struct voider { using type = void; };
	}

	/// Alternative implementation of std::void_t
	/**
		When used for SFINAE, std::void_t might not work as expected on some compilers (e.g.
		clang, see CWG1558 / https://en.cppreference.com/w/cpp/types/void_t). This is the
		suggested alternative implementation that works on all compilers.
	*/
	template <class... T>
	using void_t = typename detail::voider<T...>::type;

	/// Removes cv-qualifiers like std::decay, but does so for all levels of indirection (e.g. pointer to const pointer)
	template <class T>
	struct deep_decay;

	template <class T>
	using deep_decay_t = typename deep_decay<T>::type;

	/// returns the Data File Protection Statement for the year provided, provide the year as number since AD, e.g.: 2021 -> [...] Copyright 2021 UFA, Inc. [...]
	std::string data_protection_statement(int year);

	/// returns the Data File Protection Statement for the current year according to system time
	std::string data_protection_statement_current_year();
}

#include <tower/core/utility.ipp>