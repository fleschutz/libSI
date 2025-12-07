#include <functional>
#include <memory>

#include <boost/signals2.hpp>

#include <QApplication>
#include <QEvent>
#include <QObject>

/// connects a boost signal to arbitrary Qt code
/**
	If the given signal gets triggered, a call to the given function is queued into the given thread.
	The signal arguments are passed to the function.
	Only signals without return value are supported.
*/
template <class Signal, class Function>
boost::signals2::connection connect(Signal& signal, QThread* thread, Function func)
{
	return signal.connect(boost_qt_connect::detail::enqueuer < Function > {thread, std::move(func)});
}

namespace boost_qt_connect 
{
	namespace detail
	{
		class receiver;

		class event : public QEvent
		{
		public:
			event(const std::shared_ptr<receiver>& receiver, std::function<void()> func) : QEvent{ User }, m_receiver{ receiver }, m_function{ std::move(func) }
			{
			}

			void callFunction()
			{
				m_function();
			}

		private:
			std::shared_ptr<receiver> m_receiver; // need to hold a reference, otherwise pending events may access an already deleted receiver (after the signal connection was destroyed)
			std::function<void()> m_function;
		};

		class receiver : public QObject
		{
			//Q_OBJECT
		public:
			bool event(QEvent* e) override
			{
				// Qt queues all events into the receiver's thread
				// so in this function, we are executing within the target thread
				if (e->type() == QEvent::User)
				{
					// so just call the function
					static_cast<detail::event*>(e)->callFunction();
					return true;
				}

				return QObject::event(e);
			}

		private:
		};

		template <class F>
		class enqueuer
		{
		public:
			enqueuer(QThread* thread, F func) : m_func{ std::move(func) }, m_receiver{ std::make_shared<receiver>() }
			{
				// associate the receiver with the given thread
				m_receiver->moveToThread(thread);
			}

			template <class... Args>
			void operator()(const Args&... args) const
			{
				// perfect forwarding not possible because we have to capture all arguments

				// capture all arguments, put the call into a new event
				F func = m_func; // capture member by value
				auto evt = new event(m_receiver, [=] () mutable // mutable so we can call non-const operator() functors (e.g. std::bind functors)
				{
					func(args...);
				});

				// this transfers the ownership of the event object to Qt
				QApplication::postEvent(m_receiver.get(), evt);
			}

		private:
			F m_func;
			std::shared_ptr<receiver> m_receiver;
		};
	}
}