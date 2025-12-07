#pragma once
#include <boost\signals2.hpp>
#include <boost\make_shared.hpp>
#include <type_traits>

class QObject;
class QEvent;

/** \file

	# Generic signals for publishing events.

	## Intro

	Add signals to your class by making them public members:

		class foo
		{
		public:
    		void setValue(int);
    		int value() const;
    	
    		core::signal<int> valueChanged; // signal passing an integer
    		core::signal<> changed; // signal passing nothing
		}

	Signals can take and pass an arbitrary amount of parameters. Users of your class
	can now connect to this signals to receive notifications:

		void bar::showValue(int value);
  
		foo->valueChanged.connect(bar, &bar::showValue); // invoke bar->showValue method when value has changed

	To call a signal, call `call` on the signal object:

		valueChanged.call(newValue); // invokes all listeners of "valueChanged"
		changed.call(); // invokes all listeners of "changed"

	Make sure to disconnect any signals when destroying listener objects. See "Connection Management" for details.

	`core::signal` is interoperable with Qt, see "Connection Management" and "Multi-Threading" for details.

	## Connecting to signals

	You can either connect class methods, generic functors (e.g. lambdas) or other signals.

	Connecting methods works like `std::bind`/`boost::bind`, so you can use placeholders (`core::placeholders`) or pass additional
	values on connecting:

		class bar
		{
			void showName(const std::string& name);
		}
	
		bar* b = ...;
		core::signal<std::string> nameChanged;
	
		using namespace core::placeholders;
		nameChanged.connect(b, &bar::showName); // invokes showName, passing the std::string parameters
		nameChanged.connect(b, &bar::showName, _1); // same as above, but with explicit placeholders
		nameChanged.connect(b, &bar::showName, ""); // invokes showName, always passing an empty string, ignoring the signal value
	
	Connecting functors requires an additional `context` parameter which is used to disconnect signals. Typically
	this is a pointer to an object captured by the functor:

		core::signal<std::string> nameChanged;
		nameChanged.connect(this, [this](const std::string& name)
		{
			showName(name);
		});

	Any return values from listeners are ignored.
	
	## Multi-Threading

	`core::signal` is thread-safe to a certain point: It is possible to connect/emit/disconnect from various threads,
	but automatic connection management may fail when invoking signals concurrently to cleaning up listeners, so try
	to avoid this situations. `core::signal` works best in a single-threaded environment.

	Listeners are invoked synchronously, i.e. they will be called from the emitting thread. This also means that listeners
	can be called concurrently if connected signals are emitted concurrently.

	If a QObject is used as context object (either by calling a method on a QObject or by explicitly passing a QObject as context),
	corresponding listeners may be invoked asynchronously: If the signal is emitted from the Qt thread, the listeners are called
	synchronously. Otherwise the signal is queued to the correct Qt thread and the listener is invoked asynchronously. This means
	Qt listeners are always invoked from their corresponding Qt thread.

	## Connection Management

	Listeners have to be disconnected from signals before destroying them. This can be done explicitly by calling `disconnect`
	with the corresponding context pointer or by calling `disconnect` on stored `signal_connection` objects.

	`core::signal` also supports automatic connection management for listeners derived from either `core::signal_trackable` or
	`QObject`. For these classes, all connections will be automatically disconnected on destruction:

	    class bar : public core::signal_trackable
	    {
			explicit bar(foo* foo)
			{
				foo->mouseDown.connect(this, &bar, show);
			}
			
			~bar()
			{
				// foo->disconnect(this); <- not necessary
				// bar will automatically disconnect itself on destruction
			}
			
	    	void show();
	    }
		
*/
namespace core
{
	/// Deriving a class from signal_trackable enables automatic connection management for connections to objects of this class
	/**
		Boost does not recommend use of trackable, because connections are disconnected in the base class destructor, after the derived class
		is already destructed. This should only affect multi-threaded use, though.
	*/
	using signal_trackable = boost::signals2::trackable;

	/// Connection class for storing and explicit disconnect of connections
	using signal_connection = boost::signals2::connection;

	/// Use core::placeholders (_1, _2, _3) in connect methods
	namespace placeholders
	{
		using namespace boost::placeholders;
	}

	template <class... SignalArgs>
	class signal;

	namespace detail
	{
		// use the context pointer to group signals
		using signal_group = const void*;

		struct signal_void_combiner
		{
			using result_type = void;
			template <class Iterator>
			void operator()(Iterator itr, Iterator end) const
			{
				while (itr != end) *itr++;
			}
		};

		template <class... Args>
		using signal_type = boost::signals2::signal<void(const Args&...), signal_void_combiner, signal_group>;

		template <class... SignalArgs>
		inline constexpr bool signal_check_args = (std::is_same_v<SignalArgs, std::decay_t<SignalArgs>> && ...);
	}

	template <class... SignalArgs>
	class signal
	{
	public:
		static_assert(detail::signal_check_args<SignalArgs...>, "use plain types as signal args, they will be passed as reference by default");

		/// Connect to a method
		template <class Context, class Ret, class Class, class... Args>
		signal_connection connect(Context* context, Ret(Class::*method)(Args...))
		{
			assert(context);
			return m_signal.connect(detail::signal_group(context), enable_qt_tracking(context, detail::auto_bind(method, context)));
		}

		/// Connect to a const method
		template <class Context, class Ret, class Class, class... Args>
		signal_connection connect(Context* context, Ret(Class::*method)(Args...) const)
		{
			assert(context);
			return m_signal.connect(detail::signal_group(context), enable_qt_tracking(context, detail::auto_bind(method, context)));
		}

		/// Connect to a method using placeholders
		template <class Context, class Ret, class Class, class... Args, class Head, class... Tail>
		signal_connection connect(Context* context, Ret(Class::*method)(Args...), Head head, Tail... tail)
		{
			assert(context);
			return m_signal.connect(detail::signal_group(context), enable_qt_tracking(context, boost::bind(method, context, head, tail...)));
		}

		/// Connect to a const method using placeholders
		template <class Context, class Ret, class Class, class... Args, class Head, class... Tail>
		signal_connection connect(Context* context, Ret(Class::*method)(Args...) const, Head head, Tail... tail)
		{
			assert(context);
			return m_signal.connect(detail::signal_group(context), enable_qt_tracking(context, boost::bind(method, context, head, tail...)));
		}

		/// Connect to a functor
		/**
			A context has to be supplied explicity, typically an object pointer also captured by the functor.
		*/
		template <class Context, class F>
		signal_connection connect(Context* context, F func)
		{
			assert(context);
			if constexpr(std::is_base_of_v<QObject, Context>)
				return m_signal.connect(detail::signal_group(context), enable_qt_tracking(context, std::move(func)));
			else
				return m_signal.connect(detail::signal_group(context), detail::trackable_functor<Context, F>(context, std::move(func)));
		}

		/// Connect to another signal
		/**
			Emitting this signal will emit the other signal. Signals automatically disconnect from each other on destruction.
		*/
		template <class... OtherArgs>
		signal_connection connect(signal<OtherArgs...>& other)
		{
			// Get some types to extract the method pointer to operator() const of the other signal
			// Have to connect to the boost::signal, not to the enclosing core::signal, otherwise tracking won't work
			using other_signal_type = typename signal<OtherArgs...>::signal_type;
			using result_type = typename other_signal_type::result_type;
			auto call = static_cast<result_type(other_signal_type::*)(const OtherArgs&...) const>(&other_signal_type::operator());
			return connect(&other.m_signal, call);
		}

		/// Disconnect all connections to the given context
		template <class Context>
		void disconnect(Context* context)
		{
			if (!context)
				return;

			return m_signal.disconnect(detail::signal_group(context));
		}

		/// Disconnect another signal
		template <class... OtherArgs>
		void disconnect(signal<OtherArgs...>& other)
		{
			return disconnect(&other.m_signal);
		}

		/// Emit the signal
		/**
			Synchronously invokes all connected slots.

			Using "call" instead of "operator()" for better readability and less ambiguities.
			Cannot "emit" thanks to Qt using "emit" as preprocessor define.
		*/
		void call(const SignalArgs&... args) const
		{
			return m_signal.operator()(args...);
		}

	private:
		using signal_type = detail::signal_type<SignalArgs...>;

		template <class Context, class F>
		std::enable_if_t<std::is_base_of<QObject, Context>::value, typename signal_type::slot_type> enable_qt_tracking(Context* context, F f) const
		{
			typename signal_type::slot_type slot(detail::qt_proxy<Context, F>(context, f));

			// boost slots perform tracking by storing weak_ptr to some shared_ptr whose lifetime is bound to the context
			// so we need a shared_ptr that is destroyed iff the QObject is destroyed

			// just make a shared_ptr to our this pointer (could be anything, but maybe the pointer comes in handy at some point)
			// note that this is not a shared_ptr owning this object, it is a shared_ptr owning a pointer to this object
			auto tracker = boost::make_shared<const signal*>(this); 

			// capture the tracker pointer and connect it to the QObject. We don't need any handling, the idea is to attach the tracker
			// to the QObject. QObjects destroy all their connections when they are destroyed, so it will also destroy the captured shared_ptr.
			// This would work with any signal, not only QObject::destroyed.
			QObject::connect(context, &QObject::destroyed, [tracker]{});

			// now keep track of the shared_ptr
			slot.track(tracker);

			return slot;
		}

		template <class Context, class F>
		std::enable_if_t<!std::is_base_of<QObject, Context>::value, F> enable_qt_tracking(Context*, F f) const
		{
			// not a QObject, nothing to do
			return f;
		}

		signal_type m_signal;

		template <class...>
		friend class signal;
	};

	namespace detail
	{
		template <class F>
		struct trackable_functor_function_wrapper;

		// trackable_functor base class to wrap a function pointer into a functor
		template <class Ret, class... Args>
		struct trackable_functor_function_wrapper<Ret(*)(Args...)>
		{
			using function_pointer = Ret(*)(Args...);
			explicit trackable_functor_function_wrapper(function_pointer function)
				: function(function)
			{
			}

			Ret operator()(Args... args) const
			{
				return function(std::forward<Args>(args)...);
			}

			function_pointer function;
		};

		template <class F>
		using trackable_functor_function_base = std::conditional_t<std::is_pointer_v<F>, trackable_functor_function_wrapper<F>, F>;

		// this functor combines a general functor and a context pointer, which allows automatic tracking
		// if the context is a signal_trackable
		template <class Trackable, class F>
		struct trackable_functor : trackable_functor_function_base<F>
		{
			trackable_functor(const Trackable* ptr, F f)
				: trackable_functor_function_base<F>(std::move(f)), trackable(ptr)
			{
			}

			const Trackable* trackable;
		};

		// boost uses visit_each to extract trackable objects
		template <typename Visitor, class Trackable, class F>
		void visit_each(Visitor& visitor, const trackable_functor<Trackable, F>& f, int)
		{
			visitor(f);
			visitor(f.trackable);
		}

		// this object is created and pushed into the Qt event queue in case we have
		// to do a call across threads
		template <class F,
			class Base, // Base is always QObject, but this allows compilation without having QObject included
			class Event // Event is always QEvent, but this allows compilation without having QEvent included
		>
			struct qt_proxy2 : Base
		{
			explicit qt_proxy2(F func)
				: func(std::move(func))
			{
			}

			bool event(Event* evt) override
			{
				if (evt->type() == Event::User)
				{
					func();
					delete this; // we are done, delete us
					return true;
				}

				return false;
			}

			F func;
		};

		bool in_same_thread_as(QObject* context);
		void post_user_event(QObject* destination);

		// Proxy functor to invoke general functors in a Qt context
		template <class Context, class F>
		struct qt_proxy
		{
			qt_proxy(Context* context, F func)
				: context(context), func(std::move(func))
			{
			}

			template <class... Args>
			void operator()(Args&&... args)
			{
				if (in_same_thread_as(context))
				{
					// we are running in the Qt context's thread, just invoke the functor
					func(std::forward<Args>(args)...);
				}
				else
				{
					// we are not running in the Qt context's thread, enqueue the call to
					// the right thread

					auto lambda = [=]()
					{
						func(args...);
					};

					auto proxy = new qt_proxy2<decltype(lambda), QObject, QEvent>(lambda);
					proxy->moveToThread(context->thread());
					post_user_event(proxy);
				}
			}

			Context* context;
			F func;
		};

		template <class Method, class Context, size_t... N>
		auto auto_bind_impl(Method method, Context* object, std::index_sequence<N...>)
		{
			return boost::bind(method, object, boost::arg<N + 1>{}...);
		}

		template <class Ret, class Class, class... Args, class Context>
		auto auto_bind(Ret(Class::*method)(Args...), Context* object)
		{
			return auto_bind_impl(method, object, std::make_index_sequence<sizeof...(Args)>{});
		}

		template <class Ret, class Class, class... Args, class Context>
		auto auto_bind(Ret(Class::*method)(Args...) const, Context* object)
		{
			return auto_bind_impl(method, object, std::make_index_sequence<sizeof...(Args)>{});
		}
	}
}