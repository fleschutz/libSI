#pragma once
#include "value_tree.hpp"

#include <boost/optional.hpp>
#include <optional>

/** \file
	More high-level interface to read/write structured data on top of value_tree.

	The idea is to define how a given C++ type should be represented in structured data (e.g. assign attribute names to all its members)
	and to let this module take care of the rest (building up the structure, nesting stuff into each other, etc.).

	This is especially useful when a type needs support for both reading and writing, because with this module still only one single
	function has to be defined per type.

	This module has special treatments for collections, unique_ptr and optional members to write / read them in a suitable way.

	To add support for a user-defined type, the type has to accept a value_tree_visitor (see value_tree_visitor doc for details).

	# Examples:

	## Define Types
		struct foo
		{
			int id;
			std::string name;

			// intrusive accept
			void operator()(value_tree_visitor v)
			{
				// pass all relevant members to the visitor
				v("@id", id); // attribute "id", no fallback value
				v("name", name, ""); // sub-node "name", fallback value ""
			}
		};

		struct bar
		{
			double x, y;
			std::vector<foo> foos;
		};

		// non-intrusive accept (has to be in the same namespace as bar)
		void accept(bar& obj, value_tree_visitor v)
		{
			// pass all relevant members to the visitor
			v("pos@x", x); // attribute "x" of sub-node "pos", no fallback value
			v("pos@y", y); // attribute "y" of sub-node "pos", no fallback value
			v.collection("foos", "foo", foos); // special method for collections
		}

	## Read Object from root node "bar"
		value_tree file(value_tree::xml_file, "path/to.xml");
		bar bar = {};
		read(file.node("bar"), bar);

	## Write Object to root node "bar"
		value_tree file(value_tree::xml_file);
		write(bar, file.node("bar"));
		file.save_file("path/to.xml");
*/
namespace core
{
	struct value_tree_noop{};

	/// Reads a complex type from a value tree node
	/**
		Type must accept a value_tree_visitor
	*/
	template <class T>
	void read(const_value_tree_node from, T& to);

	/// Writes a complex type to a value tree node
	/**
		Type must accept a value_tree_visitor
	*/
	template <class T>
	void write(const T& from, value_tree_node to);

	/// Reads a collection from a value tree node
	/**
		Collection items are read from sub-nodes with the given item name.
	*/
	template <class Collection, class Factory = value_tree_noop>
	void read_collection(const const_value_tree_node& from, const char* items, Collection& to, Factory factory = Factory());

	/// Writes a collection to a value tree node
	/**
		Collection items are written to sub-nodes with the given item name.
	*/
	template <class Collection>
	void write_collection(const Collection& from, value_tree_node to, const char* items);

	/// User-defined classes can accept this visitor to enable read/write
	/**
		Accept by either method "void operator()(value_tree_visitor)" (intrusive) 
		or free function "void accept(T& obj, value_tree_visitor)" (non-intrusive)

		Typically, all members of a class are passed to the visitor.
	*/
	class value_tree_visitor
	{
	public:
		/// Returns a visitor for the given sub-node
		value_tree_visitor node(const char* path);

		/// Returns the node this visitor is currently reading from
		/**
			This can be used to implement special code for reading in the accept function.
			May only be called if reading.
		*/
		const const_value_tree_node& read_node();

		/// Returns the node this visitor is currently writing to
		/**
			This can be used to implement special code for writing in the accept function.
			May only be called if writing.
		*/
		const value_tree_node& write_node();

		bool reading() const; ///< true if this visitor originated from a call to read
		bool writing() const; ///< true if this visitor originated from a call to write

		/// Passes a member to the visitor
		/**
			The member is read/written from/to the given path, relative to the object's root.
		*/
		template <class T>
		void operator()(const char* path, T& x);

		/// Passes a member to the visitor
		/**
			The member is read/written from/to the given path, relative to the object's root.
		*/
		template <class T, class U>
		void operator()(const char* path, T& x, U&& fallback_value);

		/// Passes a collection to the visitor
		/**
			The member is read/written from/to the given path, relative to the object's root.
			The item name is used to name the individual items.

			Example:

			<path>
				<item />
				<item />
				<item />
			</path>
		*/
		template <class Collection, class Factory = value_tree_noop>
		void collection(const char* path, const char* items, Collection& collection, Factory factory = Factory());

		/// Passes a collection to the visitor
		/**
			The member is read/written from/to the given path, relative to the object's root.
			The item name is used to name the individual items.

			Example:

			<path>
				<item />
				<item />
				<item />
			</path>
		*/
		template <class Collection, class Factory = value_tree_noop>
		void collection(const char* path, const char* items, Collection& collection, const Collection& fallback_collection, Factory factory = Factory());


		/// Passes an enumeration member to the visitor
		/**
			The given table is used to translate between value and string.

			# Example:

			v.enumeration("@enum", m_enum,
				ValueA, "A",
				ValueB, "B"
			)

			# Example with fallback value:

			v.enumeration("@enum", m_enum, ValueA,
				ValueA, "A",
				ValueB, "B"
			)
		*/
		template <class Enum, class... EnumTable>
		void enumeration(const char* path, Enum& x, EnumTable... table);

		/// Passes an si member to the visitor
		/**
			A unit conversion function has to be passed for both reading and writing (typically both are identical)

			# Example:

			v.si("@distance", d, si::meter)
		*/
		template <class Member, class Unit>
		void si(const char* path, Member& m, const Unit& unit);

		template <class Member, class Unit, class Fallback>
		void si(const char* path, Member& m, const Unit& unit, Fallback&& fallback);


		/// Passes a custom member to the visitor
		/**
			A conversion functor for both reading and writing has to be supplied.

			The read functor converts from string to value, the write functor from value to string.
		*/
		template <class Member, class Read, class Write>
		void custom(const char* path, Member& m, Read read, Write write);

		template <class Member, class Read, class Write, class Fallback>
		void custom(const char* path, Member& m, Read read, Write write, Fallback&& fallback);

	private:
		explicit value_tree_visitor(value_tree_node node);
		explicit value_tree_visitor(const_value_tree_node node);

		boost::optional<value_tree_node> m_write_node;
		boost::optional<const_value_tree_node> m_read_node;

		template <class T>
		friend void core::read(const_value_tree_node, T&); // NOLINT(readability-redundant-declaration)
		template <class T>
		friend void core::write(const T&, value_tree_node); // NOLINT(readability-redundant-declaration)
	};
}

#include "value_tree_visitor.ipp"