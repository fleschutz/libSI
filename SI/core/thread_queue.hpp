#pragma once
#include <functional>
#include <vector>
#include <Windows.h>

#include <tower/core/utility.hpp>

namespace core
{
	/// Utility class for queuing function calls to another thread
	/**
		This queue can be used to queue generic functors (which can also capture /
		transport arbitrary state) to another thread.

		All enqueued functors are asynchronously executed in the owning thread.
		The owning thread is the thread which created the instance of `thread_queue`.
		This threads needs to run a Win32 message pump / Qt application (typically
		the main thread).

		This class can serve as a building block for multi-threaded application
		architectures.
	*/
	class thread_queue
	{
	public:
		/// Queues functors to the calling thread
		explicit thread_queue(HINSTANCE hInstance);

		thread_queue(const thread_queue&) = delete;
		thread_queue& operator=(const thread_queue&) = delete;
		~thread_queue();

		/// Enqueue a functor
		/**
			The functor and all its captured state is copied to the internal queue
			and executed by the owning thread as soon as possible.

			All functors are executed in order.
		*/
		void enqueue(std::function<void()> f);

	private:
		LRESULT window_procedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

		HWND m_hwnd = nullptr;

		core::critical_section m_cs;
		std::vector<std::function<void()>> m_queue, m_swap_queue;
	};
};