#pragma once
#include <mutex>
#include <functional>
#include <vector>

#include <boost\system\error_code.hpp>

namespace core
{
	/// Utility class to simplify usage of boost asio sockets
	/**
		Implements most basic boilerplate code required for sending / receiving using asynchronous operations.
	*/
	template <class Socket>
	class socket_pipe
	{
	public:
		/// Read handler is called whenever a `async_read` was completed (or if an error occured)
		using read_handler = std::function<void(boost::system::error_code ec, const std::byte* data, size_t size)>;

		/// Takes ownership of the given socket, does not start any operations right away
		explicit socket_pipe(Socket socket);
		/// Closes and shuts down the socket
		~socket_pipe();

		socket_pipe(const socket_pipe&) = delete;
		socket_pipe& operator=(const socket_pipe&) = delete;

		/// Start an async_read operation
		/**
			The given handler will be called once the given amount of bytes have been received (or an error occured).
			The handler will be called from within `io_service::run`, so be careful when `run` is driven by parallel threads.
			Only one read operation can be pending at any time, i.e. DO NOT call async_read again before the previous read has
			finished.

			Typically, the read handler starts the next async_read after processing the received data.
		*/
		void async_read(size_t bytes, read_handler read_handler);

		/// Ignore all incoming data
		/**
			Incoming data gets discarded, useful to avoid unnecessary system buffering of incoming data.
		*/
		void ignore_read();

		/// @{
		/// Write / send the given binary data
		/**
			Returns immediately, the data will be send via the socket as soon as possible (and always in order).
		*/
		void write(const std::byte* data, size_t size);
		void write(const std::byte* const* data, const size_t* size, size_t count);
		/// @}

	private:
		void start_write();

		Socket m_socket;
		std::mutex m_mutex;
		bool m_writing = false; // True if a write is already pending
		std::vector<std::byte> m_write_queue; // Data not handed to ASIO yet (waiting for the current write to finish)
	};
}