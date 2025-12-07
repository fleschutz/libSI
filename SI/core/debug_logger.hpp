#pragma once
#include <cstdio>
#include <tower/core/utility.hpp>

namespace core
{
	/// Logger class for logging debug output to a separate text file
	/**
		Can be used for more extensive debug logging in situations where the normal ATTower logger
		is not available or not fast enough.

		Typical Usage:
			- create a global debug_logger in some cpp file, e.g.
				debug_logger logger("test.log");
			- use the logger via the DEBUG_LOG macro, e.g.
				DEBUG_LOG(logger).printf("The answer is %d", 42);
			- to use the same logger in a different cpp, import it using extern, e.g.
				extern debug_logger logger;
			- make sure to not check-in any of this
	*/
	class debug_logger
	{
	public:
		/// No-op constructor, logger can be opened via open() later on
		debug_logger();
		/// Calls open() with the given parameters (see there for further description)
		explicit debug_logger(const char* name, bool flush = true, bool pid_prefix = false);
		/// Calls close()
		~debug_logger();

		debug_logger& operator=(const debug_logger&) = delete;
		debug_logger(const debug_logger&) = delete;

		///@{ 
		/// Methods for recursively locking the logger to prevent interleaving output
		/**
			Typically not called directly by the user, use DEBUG_LOG instead.
		*/
		void lock();
		void unlock();
		///@}

		/// Opens a text file with the given name
		/**
			The file is created in the current working directory (executables folder), prefixed with the
			computer name. If pid_prefix is true, it is also prefixed with the current process ID (to support
			debugging of multiple, parallel processes on the same machine).

			If flush is true, the file is flushed after every write, which prevents data loss when crashing but
			reduces performance.
		*/
		void open(const char* name, bool flush, bool pid_prefix);

		/// Closes the text file
		void close();

		///@{ 
		/// Methods for outputting
		/**
			Typically not called directly by the user, use DEBUG_LOG instead.
		*/
		debug_logger& printf(const char* format, ...);
		debug_logger& vprintf(const char* format, va_list arg);
		debug_logger& print_time();
		///@}

	private:
		FILE* m_file;
		bool m_flush;
		core::critical_section m_mutex;
	};

	/// Utility macro for outputting a single line via a debug logger
	/**
		Automatically locks the logger, prefixes the output line with the source file, function, line,
		current time, and thread ID.

		Example usage:
		
		DEBUG_LOG(logger).printf("connection %p closed", handle);
	*/
	#define DEBUG_LOG(logger_) \
		::core::detail::debug_logger_printer(&logger_, __FILE__, __FUNCTION__, __LINE__)

	namespace detail
	{
		class debug_logger_printer 
		{
		public:
			debug_logger_printer(debug_logger* logger, const char* file, const char* func, int line);
			~debug_logger_printer();

			debug_logger_printer(const debug_logger_printer&) = delete;
			debug_logger_printer& operator=(const debug_logger_printer&) = delete;

			debug_logger_printer& printf(const char* format, ...);
			debug_logger_printer& vprintf(const char* format, va_list arg);

		private:
			debug_logger* m_logger;
		};
	}
}