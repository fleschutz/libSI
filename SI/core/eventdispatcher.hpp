#pragma once

// workaround for towconsts.h
#undef L3

#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>
#include <boost/signals2.hpp>

#ifdef EVENT_DISPATCHER_ENABLE_QT
#include "boost_qt_connect.hpp"
#endif

namespace events {
	class group {
	public:
		enum group_type {
			uninitialized = 0,
			pointer = 1,
			unique = 2
		};

		group() : value(0), type(uninitialized) {};


		explicit group(std::ptrdiff_t v, group_type type = pointer) : value(v), type(type) {
		}

		group_type type;
		std::ptrdiff_t value;
	};

	inline bool operator<(group const & a, group const & b) {
		if (a.type == b.type)
			return a.value < b.value;
		
		return a.type < b.type;
	}

	/// use this with instance pointers
	template<typename T>
	group make_group(T const & p) {
		BOOST_STATIC_ASSERT_MSG(boost::is_pointer<T>::value, "T must be a pointer");
		return group(reinterpret_cast<std::ptrdiff_t>(p), group::pointer);
	}

	/// use this when instance pointer is not sufficient, and store return value...
	__declspec(noinline) inline group make_group() {
		static std::ptrdiff_t _group = 0;

		return group(_group++, group::unique);
	}

	namespace detail {
		template<typename Signature>
		class signal : public boost::signals2::signal<
				Signature,
				boost::signals2::optional_last_value<typename boost::function_traits<Signature>::result_type>,
				group
			> {
		public:
//
//#ifdef EVENT_DISPATCHER_ENABLE_QT
//			boost::signals2::connection connect(boost::signals2::signal::slot_type const & slot) {
//				connect(slot, at_back);
//			}
//
//			boost::signals2::connection connect(group& g, QThread* thread, boost::signals2::signal::slot_type const & slot) {
//				return ::connect(g, *this, thread, slot);
//			}
//#endif
		};
	}

	template<typename Signature>
	using signal = detail::signal<Signature>;
}

#define EVENT_DECLARE_SIGNAL_N(CATEGORY, NAME, RETURN, ...) \
	namespace events { \
		namespace CATEGORY { \
			/*__declspec(selectany) detail::signal<RETURN (##__VA_ARGS__##)> NAME;*/ \
			__declspec(selectany) detail::signal<RETURN (##__VA_ARGS__##)> NAME; \
		} \
	}

#define EVENT_DECLARE_SIGNAL(CATEGORY, NAME) EVENT_DECLARE_SIGNAL_N(CATEGORY, NAME, void)