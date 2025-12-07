#pragma once
#include <tower/core/utility.hpp>

namespace core { 
namespace detail
{
	std::string strprintf_impl(const char* format, ...);

	// recursion end of check_printf_arguments
	bool check_printf_arguments(const char* format);

	template <typename Head, typename... Tail>
	bool check_printf_arguments(const char* format, Head, Tail&&... tail)
	{
		static_assert(std::is_integral<Head>::value || std::is_floating_point<Head>::value ||
			std::is_pointer<Head>::value || std::is_enum<Head>::value, "not a printf-compatible type");

		while (true)
		{
			// there are non-consumed arguments left, so there also has to be a conversion specification left
			format = strchr(format, '%');
			if (!format)
				return false;
			++format;

			if (*format != '%') // step over '%%'
			{
				// find the conversion specifier
				format = strpbrk(format, "diuoxXfFeEgGaAcspn");
				if (!format)
					return false;

				// do some basic type checking (ignoring the argument type specifier h, l, j etc.)
				switch (*format)
				{
				case 'd':
				case 'i':
				case 'u':
				case 'o':
				case 'x':
				case 'X':
				case 'c':
					if (!std::is_integral<Head>::value && !std::is_enum<Head>::value)
						return false;
					break;

				case 'f':
				case 'F':
				case 'e':
				case 'E':
				case 'g':
				case 'G':
				case 'a':
				case 'A':
					if (!std::is_floating_point<Head>::value)
						return false;
					break;

				case 's':
				case 'p':
				case 'n':
					if (!std::is_pointer<Head>::value)
						return false;
					break;
				}

				// our argument (head) was fine, go on with the next one
				return check_printf_arguments(format + 1, tail...);
			}

			// this was a '%%', go ahead
			++format;
		}
	}

	struct on_exit_tag {};

	template <class F>
	struct on_exit_caller
	{
		/*explicit*/ on_exit_caller(F func) :
			func(std::move(func))
		{
		}

		~on_exit_caller()
		{
			func();
		}

		on_exit_caller(const on_exit_caller&) = delete;
		on_exit_caller& operator=(const on_exit_caller&) = delete;

		F func;
	};

	template <class F>
	on_exit_caller<F> operator|(on_exit_tag, F func)
	{
		return{ std::move(func) };
	}
}}

namespace core
{

#if ATTOWER_TIDY
	std::string CORE_ATTRIBUTE_PRINTF(1, 2) strprintf(const char* format, ...);
	template <class OutputStream>
	size_t CORE_ATTRIBUTE_PRINTF(2, 3) osprintf(OutputStream& os, const char* format, ...);
	[[noreturn]] void CORE_ATTRIBUTE_PRINTF(1, 2) throwf(const char* format, ...);
#else
	template <class... Args>
	std::string strprintf(const char* format, Args&&... args)
	{
		assert(::core::detail::check_printf_arguments(format, args...));
		return detail::strprintf_impl(format, args...);
	}
#endif

#if LINUX == 0

	namespace detail
	{
		struct any_of_tag {};

		template <class T, class Args, size_t... N>
		bool any_of_impl(const T& lhs, const Args& rhs, std::index_sequence<N...>)
		{
			return ((lhs == std::get<N + 1>(rhs)) || ...);
		}

		template <class T, class... Args>
		bool operator==(const T& lhs, const std::tuple<any_of_tag, Args...>& rhs)
		{
			return any_of_impl(lhs, rhs, std::make_index_sequence<sizeof...(Args)>{});
		}

		template <class T, class... Args>
		bool operator!=(const T& lhs, const std::tuple<any_of_tag, Args...>& rhs)
		{
			return !any_of_impl(lhs, rhs, std::make_index_sequence<sizeof...(Args)>{});
		}
	}

	template <class... T>
	auto any_of(const T&... values)
	{
		return std::tuple<detail::any_of_tag, const T&...>({}, values...);
	}

	namespace detail
	{
		template <class... F>
		struct overloaded : F... { using F::operator()...; };
	}

	template <class... F>
	auto overload(F... f)
	{
		return detail::overloaded<F...>{std::move(f)...};
	}

	namespace detail
	{
		void* window_method_proxy_query(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* result);
		void* dialog_method_proxy_query(HWND hwnd, UINT msg, LPARAM lParam);
		WNDPROC window_method_subclass_impl(HWND hwnd, void* object, WNDPROC proc);
	}

	template <auto WindowMethod>
	LRESULT CALLBACK window_method_proxy(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		using class_type = typename functor_traits<decltype(WindowMethod)>::class_type;

		LRESULT result = 0;
		auto object = static_cast<class_type*>(detail::window_method_proxy_query(hWnd, uMsg, wParam, lParam, &result));
		if (object)
			return (*object.*WindowMethod)(hWnd, uMsg, wParam, lParam);
		return result;
	}

	template <auto WindowMethod>
	INT_PTR CALLBACK dialog_method_proxy(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		using class_type = typename functor_traits<decltype(WindowMethod)>::class_type;

		auto object = static_cast<class_type*>(detail::dialog_method_proxy_query(hwndDlg, uMsg, lParam));
		if (object)
			return (*object.*WindowMethod)(hwndDlg, uMsg, wParam, lParam);
		return FALSE;
	}

	template <auto WindowMethod, class T>
	WNDPROC window_method_subclass(HWND hWnd, T* object)
	{
		using class_type = typename functor_traits<decltype(WindowMethod)>::class_type;
		static_assert(std::is_same_v<class_type, T>);

		WNDPROC proc = window_method_proxy<WindowMethod>;
		return detail::window_method_subclass_impl(hWnd, object, proc);
	}

#endif // LINUX

	// function_traits for functors
	template <class F>
	struct functor_traits : functor_traits<decltype(&F::operator())>
	{
	};

	// function_traits for non-const methods
	template <class C, class R, class... Args>
	struct functor_traits< R(C::*)(Args...) > : boost::function_traits<R(Args...)>
	{
		using class_type = C;
	};

	// function_traits for const methods
	template <class C, class R, class... Args>
	struct functor_traits< R(C::*)(Args...) const > : boost::function_traits<R(Args...)>
	{
		using class_type = C;
	};

	// function_traits for functions
	template <class R, class... Args>
	struct functor_traits < R(Args...) > : boost::function_traits<R(Args...)>
	{
	};

	// function_traits for function pointers
	template <class R, class... Args>
	struct functor_traits < R(*)(Args...) > : boost::function_traits<R(Args...)>
	{
	};

	template <class T>
	struct deep_decay : std::decay<T>
	{
	};

	template <class T>
	struct deep_decay<T*>
	{
		using type = deep_decay_t<T>*;
	};

	template <class T>
	struct deep_decay<T* const>
	{
		using type = deep_decay_t<T>*;
	};
}