#pragma once
#include <any>
#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>
#include <memory>

#include <tower/core/utility.hpp>
#include <tower/core/fwd.hpp>

namespace core
{
	/// Argument store for serialization_sink and serialization_source
	/**
		Both serialization_sink and serialization_source can store arbitrary arguments which can be queried during
		serialization / deserialization by specialized serialization traits.
	*/
	class serialization_args
	{
	public:
		/// Stores an argument, replaces existing argument with the same type
		template <class Type>
		void set_arg(Type arg);

		/// Queries the argument of the given type (argument with this type must exist)
		/**
			The given type must match exactly the stored type, e.g. "const char*" is different from "std::string".
		*/
		template <class Type>
		Type arg() const;

	private:
		std::vector<std::any> m_args;
	};

	/// Sink for serializing objects
	/**
		See `serialization_data_sink` for a ready-to-use implementation of this base class.
	*/
	class serialization_sink : public serialization_args
	{
	public:
		/// Serialize the given object
		/**
			This is the entry point for all serialization operations.
		*/
		template <class T>
		void write(const T& value);
		
		CORE_ATTRIBUTE_WIRE(2, 3)
		virtual void write_bytes(const void* data, size_t bytes) = 0;

	protected:
		~serialization_sink() = default;
	};

	/// Sink for deserializing objects
	/**
		See `serialization_data_source` for a ready-to-use implementation of this base class.
	*/
	class serialization_source : public serialization_args
	{
	public:
		/// @{
		/// Deserialize an object of the given type
		/**
			This is the entry point for all deserialization operations. There are different variants to deserialize either
			on stack, on heap, or inplace.

			For example `read_unique` is most useful for complex objects which cannot be default- or copy-constructed.
		*/
		template <class T>
		T read();

		template <class T>
		std::unique_ptr<T> read_unique();

		template <class T>
		void read(T* value);
		/// @}

		virtual void read_bytes(void* data, size_t bytes) = 0;
		virtual size_t available_bytes() const = 0;

	protected:
		~serialization_source() = default;
	};

	/// Serialization error
	/**
		Thrown if something goes wrong (normally only during deserialization, because
		serialization should always succeed, unless there is some user error)
	*/
	class serialization_error : public std::runtime_error
	{
	public:
		using std::runtime_error::runtime_error;
	};

	/// Serializes into a std::vector of raw bytes
	class serialization_data_sink final : public serialization_sink
	{
	public:
		/// Uses the given vector if non-null, or fills a new vector if null
		explicit serialization_data_sink(std::vector<std::byte>* vector = nullptr);

		serialization_data_sink(const serialization_data_sink&) = delete;
		serialization_data_sink& operator=(const serialization_data_sink&) = delete;
		~serialization_data_sink() = default;

		/// Shortcut for vector().data(), returns nullptr if empty
		std::byte* data();

		/// Shortcut for vector().size()
		size_t size() const;

		/// Gives access to the serialized data, you may move this vector out
		std::vector<std::byte>& vector();

		CORE_ATTRIBUTE_WIRE(2, 3)
		void write_bytes(const void* data, size_t bytes) override;

	private:
		std::vector<std::byte>* m_vector;
		std::vector<std::byte> m_local;
	};

	/// Deserializes from raw bytes
	class serialization_data_source final : public serialization_source
	{
	public:
		serialization_data_source(const void* data, size_t available);
		explicit serialization_data_source(std::vector<std::byte>* vector);

		const void* current() const;

		void read_bytes(void* data, size_t bytes) override;
		size_t available_bytes() const override;

	private:
		const std::byte* m_data;
		size_t m_available;
	};

	/// Serializes into a FILE
	/**
		FILE should be opened in binary mode.
	*/
	class serialization_file_sink final : public serialization_sink
	{
	public:
		explicit serialization_file_sink(FILE* fp);

		CORE_ATTRIBUTE_WIRE(2, 3)
		void write_bytes(const void* data, size_t bytes) override;

	private:
		FILE* m_fp;
	};

	namespace detail
	{
		template <class T>
		struct serialization_traits_visitable;
	}

	/// Visitor for serializing complex types
	/**
		You can make your class serializable by defining an `operator()(serialization_visitor v)`. This method has to
		pass all class members to the visitor.

		If your class is not default-constructible, see `serialization_key`.
	*/
	class serialization_visitor
	{
	public:
		/// Pass a normal member
		template <class T>
		void operator()(T& member);

		/// Pass a field member
		template <class T, size_t N>
		void operator()(T(&member)[N]);

		/// Pass a trivial copyable member
		/**
			If you are certain that a member is trivially copyable, you can use this method instead of
			specializing the is_trivially_serializable trait.
		*/
		template <class T>
		void trivial(T& member);

		/// Pass a trivial field member
		template <class T, size_t N>
		void trivial(T(&member)[N]);

		/// Pass a member that is not part of serialization
		/**
			This is a no-op, but explicitly signalizes that the given member should not be part of serialization.
		*/
		template <class T>
		void ignore(T& member);

		/// Checks wheter the visitor is currently serializing
		bool serializing() const;

		/// Checks wheter the visitor is currently deserializing
		bool deserializing() const;

		/// Writes some additional data to the underlying sink during serialization
		/**
			No-op during deserialization.
		*/
		template <class T>
		void write(const T& value);

		/// Reads some additional data from the underlying sink during deserialization
		/**
			May only be called during deserialization.
		*/
		template <class T>
		T read();

		/// Queries an argument from the underlying sink/source
		template <class T>
		T arg();

		/// Stores an argument to the underlying sink/source, replaces existing argument with the same type
		template <class T>
		void set_arg(T arg);

		/// Returns the source for deserialization only
		serialization_source& source();

		/// Returns the sink for serialization only
		serialization_sink& sink();

	private:
		explicit serialization_visitor(serialization_source* source);
		explicit serialization_visitor(serialization_sink* sink);

		serialization_source* m_source = nullptr;
		serialization_sink* m_sink = nullptr;

		template <class>
		friend struct detail::serialization_traits_visitable;
	};

	/**
		Classes that support the serialization_visitor but are not default-constructible should implement a constructer taking
		this serialization_key. The constructor should be a no-op.

		Pass the key down to members or bases if they also need the key.

		Example:

		class foo
		{
		public:
			foo(...); // some complex constructor
			explicit foo(serialization_key) {}
			void operator()(serialization_visitor v);
		};
	*/
	class serialization_key;
}

#include "core.ipp"