#pragma once
#include <boost/asio/io_service.hpp>
#include <boost/beast/http/message.hpp>
#include <boost/beast/http/vector_body.hpp>

namespace core
{
	/// http_client for issuing simple GET / POST queries
	/**
		The client class supports both HTTP and HTTPS (via OpenSSL).
		All operations are performed asynchronously (i.e. non-blocking) in a separate thread.
		http_client is thread-safe, i.e. queries can be issued from multiple threads in parallel.
		A new connection is used for every single query (no support for keep-alive).
	*/
	class http_client
	{
	public:
		/// HTTP / Connection setup
		/**
			Default is HTTP (no SSL) on port 80
			For SSL, set `ssl` to true and 'port' to "443"
		*/
		struct setup
		{
			std::string port = "80";
			bool ssl = false;

			/// Enable/disable compression ("Accept-Encoding")
			/**
				Compressed responses are automatically decompressed before passing them to the user handler.
			*/
			bool accept_compression = true;

			std::string user_agent; ///< String for HTTP user agent (uses BOOST_BEAST if empty), see `create_user_agent_string`

			size_t body_limit = 0; ///< Can be set to increase the body limit (in bytes, default is 8 MB)
		};

		/// Response is a plain Boost.Beast response
		using response = boost::beast::http::response<boost::beast::http::vector_body<char>>;

		/// Response handler
		/**
			Called when a query finishes, either with error or the received response.
			Response is only valid if no error is set (`if (!ec)`).

			IMPORTANT: Handlers are ALWAYS called from the internal THREAD, e.g. NOT from the main thread.
			So synchronization within the handler is almost always REQUIRED.
		*/
		using response_handler = std::function<void(boost::system::error_code ec, const response& response)>;

		/// Additional options for HTTP requests
		struct request_options
		{
			std::string cookie;

			/// Enable/disable check for ssl-certificate compliance with rfc2818
			bool verify_certificate;
		};

		/// Sets up the HTTP Client
		/**
			Connection is not opened until a query is made.

			Host could be "www.google.com", "postman-echo.com", "192.168.100.56", etc.
		*/
		explicit http_client(std::string host, setup setup);

		/// Closes the HTTP Client
		/**
			Any outstanding queries are discarded.
		*/
		~http_client();

		http_client(const http_client&) = delete;
		http_client& operator=(const http_client&) = delete;

		/// Starts GET query
		void get(std::string target, response_handler handler, const request_options& options = {});

		/// Starts POST query
		void post(std::string target, const std::string& content_type, const std::string& body, response_handler handler, const request_options& options = {});

		/// Creates an ATTower user agent string
		static std::string create_user_agent_string(const char* application_id);

	private:
		class impl;
		std::unique_ptr<impl> m_impl;
	};
}