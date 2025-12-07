#pragma once
#include <cassert>
#include <utility>

#include <tower/core/serialization/core.hpp>

/// smart pointer for pimpl-idiom
/**
	Both unique_ptr and shared_ptr have their drawbacks when used for pimpl:
	With unique_ptr, the destructer of the enclosing class has to be put into the
	implementation file. With shared_ptr you get some performance overhead. Neither
	of the two supports deep copy.

	This utility class adresses this issues: The enclosing class just has to define
	constructors and pass the arguments to the impl_ref (this has to be done in the
	implementation file, where the type of the implementation class is complete).

	The big five (move/copy-constructor/assignment + destructor) are then implemented
	properly in terms of deep copy by the compiler-generated functions, so you don't
	have to do anything else.

	It's called impl_ref because it behaves more like a reference (can never be NULL).
	Space overhead of one pointer per instance, no additional allocations are performed.

	Example declaration:

	class foo
	{
	public:
		foo(...);

	private:
		struct impl;
		impl_ref<impl> m_impl;
	}
*/
template <class T>
class impl_ref
{
public:
	/// forwards all arguments to the implementation constructor
	template <class... Args>
	explicit impl_ref(Args&&... args) : m_impl{ new T{ std::forward<Args>(args)... } }
	{
		m_vtable = get_vtable();
	}

	/// deep copies the implementation object
	impl_ref(const impl_ref& rhs)
	{
		assert(rhs.m_vtable); // all constructed impl_ref must have a vtable
		m_impl = rhs.m_vtable->copy(rhs.m_impl); // allocate a copy
		m_vtable = rhs.m_vtable; // all impl_ref of the same type share the same vtable
	}

	/// deep copies the implementation object
	impl_ref& operator=(const impl_ref& rhs)
	{
		// vtables can differ in case of DLLs (one static vtable in the executable, another (identical) static vtable in the DLL)
		assert(m_vtable /*&& m_vtable == rhs.m_vtable*/);
		m_vtable->assign(m_impl, rhs.m_impl);

		return *this;
	}

	/// moves the implementation object
	impl_ref(impl_ref&& rhs) : m_impl{ rhs.m_impl }, m_vtable{ rhs.m_vtable }
	{
		rhs.m_impl = nullptr;
		// rhs can keep its vtable pointer
	}

	/// moves the implementation object
	impl_ref& operator=(impl_ref&& rhs)
	{
		if (m_impl)
		{
			assert(m_vtable);
			m_vtable->destroy(m_impl);
		}
		// vtables can differ in case of DLLs (one static vtable in the executable, another (identical) static vtable in the DLL)
		// assert(m_vtable == rhs.m_vtable);
		m_impl = rhs.m_impl;
		rhs.m_impl = nullptr;
		m_vtable = rhs.m_vtable;

		return *this;
	}	

	~impl_ref()
	{
		if (m_impl)
		{
			assert(m_vtable);
			m_vtable->destroy(m_impl);
		}
	}

	T& get() const
	{
		assert(m_impl);
		return *m_impl;
	}

	// cannot overload operator., so we have to use operator-> even though it's called ref
	T* operator->() const
	{
		return &get();
	}

	void operator()(core::serialization_visitor v)
	{
		if (v.serializing())
		{
			v(*m_impl);
		}
		else if (v.deserializing())
		{
			m_impl = v.source().read_unique<T>().release();
			m_vtable = get_vtable();
		}
	}

private:
	// the big five are typically called from compiler-generated functions.
	// in this situation, the implementation type is incomplete,
	// so we cannot copy / delete directly, instead we are using a vtable
	struct vtable
	{
		virtual T* copy(const T* rhs) const = 0;
		virtual void assign(T* lhs, const T* rhs) const = 0;
		virtual void destroy(T* impl) const = 0;
	};

	// the vtable implementation is templated
	// so the implementation type has to be complete only at the point
	// of instantiation of this template (see the forwarding constructor)
	// -> the functions are "injected" at construction time (much like std::shared_ptr does)
	template <typename U>
	struct vtable_impl : vtable
	{
		U* copy(const U* rhs) const override
		{
			assert(rhs);
			return new U(*rhs);
		}

		void assign(T* lhs, const T* rhs) const override
		{
			assert(lhs);
			assert(rhs);
			*lhs = *rhs;
		}

		void destroy(U* impl) const override
		{
			// assert taken from std::unique_ptr, just to make sure things are going right
			static_assert(0 < sizeof(U), "can't delete an incomplete type"); // NOLINT(bugprone-sizeof-expression)
			delete impl;
		}
	};

	const vtable* get_vtable()
	{
		// all instances share the same, constant vtable
		// the vtable template gets instantiated right here, so the implementation type
		// has to be complete here (and only here)

		static const vtable_impl<T> vtable;
		return &vtable;
	}
	

	T* m_impl; // dynamically allocated implementation object
	const vtable* m_vtable; // pointer to static vtable
};

/// Convenience macro for making a class a pimpl-class
/**
	Declares a nested class "impl", defines a impl_ref<impl> member
	named "m_impl".

	Also defines a friend function "access_impl" that allows internal
	modules to access the implementation object
*/
#define PIMPL_CLASS(class_)							\
		class impl;									\
	private:										\
		impl_ref<impl> m_impl;						\
	friend impl& access_impl(const class_& pimpl)	\
	{												\
		return pimpl.m_impl.get();					\
	}