#pragma once
#include <string>
#include <string_view>
#include <stdexcept>

#include <boost/optional.hpp>

#include <tower/core/fwd.hpp>

/** \file
	Utility classes to access structured data, e.g. XML files. Use very basic XPath syntax to query stuff.

	# Examples:

	## Load XML file
		value_tree file(value_tree::xml_file, "path/to.xml")
		auto root_node = file.node("root")

	## Query values
		node.get("child")								// query value of child node "child" as string, throws if missing
		node.get("@foo", "nil")							// query value of attribute "foo" as string, returns "nil" if missing
		node.get<int>("child/grandchild@foo")			// query value of sub-node attribute, throws if missing or invalid
		node.get<float>("child[@bar]@foo", 1.f)			// query value of attribute "foo" from first "child" node which has an attribute "bar"

	## Test values
	The `get` method either throws on error or returns a fallback, depending on wheter a fallback argument has been passed.
	To test a value for its validity, use the `value` method instead:

		if (auto value = node.value<int>("child@foo"))	// query value and check validity
		{
			value.get(); // access the value
		}

	## Navigate the tree
		node.node("child/grandchild")					// returns grandchild
		node.node("child/grandchild@foo")				// returns attribute of grandchild
		node.node("child/grandchild[3]")				// returns fourth grandchild
		node.node("child/*[@foo='bar'])					// returns first child with an attribute "foo" of value "bar"

		for (auto child : node.range("child"))					// iterates all "child" nodes
		for (auto grandchild : node.range("child/grandchild"))	// iterates all "grandchild" nodes below the first "child" node
		for (auto n : node.range("*"))							// iterates all sub-nodes of the current node
		for (auto value : node.range("child/*[2]@value"))		// iterates all attributes "value" of all sub-nodes of the first "child" node, starting with the third sub-node
		for (auto value : node.range("*[@foo='bar']@value"))	// iterates all attributes "value" of all sub-nodes which have an attribute "foo" of value "bar"

	## Create XML file
		value_tree file(value_tree::xml_file)
		file.set_value("root/the/answer", 42)					// creates nodes "root", "the", "answer", sets value of answer to "42"
		file.node("root").node("the").node("answer").set(42)	// equivalent to line above, nodes are not created before set is called
		auto node = file.node("root/foo")
		node.add_node("child/grandchild")						// adds new sub-node "grandchild". "root/foo/child" are created if necessary
		file.save("path/to.xml")

	## Remove nodes
		node.remove_node()								// removes this node
		node.remove_node("@value")						// removes attribute value from this node
		node.remove_node("child")						// removes the first sub-node of name "child"
		node.remove_range("child")						// removes all sub-nodes of name "child"
		node.remove_range("child/grandchild[2]@value")	// removes all attributes "value" from all "grandchild" nodes, starting with the third node
*/
namespace core
{
	namespace detail
	{
		template <class T>
		class value_tree_range;
		class value_tree_document;
		typedef struct value_tree_document_node_tag {} *value_tree_document_node;
		struct query_value_result;
	}

	/// Exception class used by value_tree classes
	/**
		Stores a message and a path to where the error occured.
	*/
	class value_tree_error : public std::runtime_error
	{
	public:
		value_tree_error();
		explicit value_tree_error(const std::string& message, std::string path);
		const char* path() const;

	private:
		std::string m_path;
	};

	/// Helper class for returning values
	/**
		This class stores either a value of type T or an error in case the value couldn't be read successfully.
		It allows to use either exceptions or return values for error checking: You are free to either check
		every return before querying the value or to just access the value and handle any exceptions caused by
		invalid values.
	*/
	template <class T>
	class value_tree_value
	{
	public:
		value_tree_value();
		/*explicit*/ value_tree_value(T x); ///< construct from value
		/*explicit*/ value_tree_value(value_tree_error error, bool allow_fallback = false); ///< construct from error

		bool valid() const; ///< returns true if a value was successfully stored
		explicit operator bool() const; ///< checks valid()

		const T& get() const; ///< returns value if valid, throws error if invalid

		/// returns value if valid, returns fallback if tree node did not exist
		/**
			Still throws if value did exist but was invalid
		*/
		const T& get(const T& fallback_value) const;

		const value_tree_error& error() const; ///< returns error, may only be called on invalid values
	private:
		// stores either an error or an value (can't use boost::variant because .NET will refuse to start on Windows 7 with included variants... sic!)
		boost::optional<std::pair<value_tree_error, bool>> m_error; // error and whether fallback is allowed
		boost::optional<T> m_value;
	};

	class value_tree;
	class value_tree_node;
	class const_value_tree_node;

	typedef detail::value_tree_range<value_tree_node> value_tree_range;
	typedef detail::value_tree_range<const_value_tree_node> const_value_tree_range;

	/// Handle to a const value tree node
	class const_value_tree_node
	{
	public:
		/// Default construct node
		/**
			Calls to default constructed nodes are not allowed, you have to assign an actual node first.
			This is only to make it possible to e.g. have nodes as class members and initialize them
			in the constructor.
		*/
		const_value_tree_node();

		/*explicit*/ const_value_tree_node(const value_tree_node& other); ///< conversion from non-const node

		/// Query value from given path
		/**
			Returns invalid value if path does not exist. An empty path queries the value of this node
		*/
		value_tree_value<std::string> value(std::string_view path = {}) const;

		/// Query value of given type from given path
		template <class T>
		value_tree_value<T> value(std::string_view path = {}) const;

		std::string get(std::string_view path, std::string_view fallback_value) const;
		std::string get(std::string_view path = {}) const;

		template <class T>
		T get(std::string_view path, const T& fallback_value) const;
		template <class T>
		T get(std::string_view path = {}) const;

		/// Returns sub-node from given path
		const_value_tree_node node(std::string_view path) const;

		/// Returns all sub-nodes matching the given path
		const_value_tree_range range(std::string_view path) const;

		/// Checks if this node actually exists in the value tree
		/**
			Operations on non-existent nodes will always return invalid values / non-existent sub-nodes
		*/
		bool exists() const;

		/// Returns the name of this node, throws error for non-existing nodes
		std::string name() const;

		/// Checks if this node is empty, throws error for non-existing nodes
		bool empty() const;

		const std::string& path() const;

		/// Creates the string representation for this node and all its sub-nodes
		/**
			Whitespaces can be added for better readability.
			Returns empty string for non-existing nodes.
		*/
		std::string to_string(bool whitespaces) const;

	private:
		explicit const_value_tree_node(detail::value_tree_document* document, detail::value_tree_document_node node, std::string path, size_t missing, size_t attribute);
		boost::optional<std::string_view> query_value(std::string_view path, std::string* resolved_path) const;

		detail::value_tree_document* m_document;
		detail::value_tree_document_node m_node;
		std::string m_path;
		size_t m_missing;
		size_t m_attribute;

		friend class value_tree_node; // needs to access everyting
		friend class value_tree; // needs to access m_backend + m_node
		friend class detail::value_tree_range<const_value_tree_node>; // needs to construct nodes
		friend class detail::value_tree_range<value_tree_node>; // needs to construct nodes
	};

	/// Handle to a non-const value tree node
	class value_tree_node : public const_value_tree_node
	{
	public:
		/// Default construct node
		/**
			Calls to default constructed nodes are not allowed, you have to assign an actual node first.
			This is only to make it possible to e.g. have nodes as class members and initialize them
			in the constructor.
		*/
		value_tree_node();

		/*explicit*/ value_tree_node(const value_tree& other); ///< conversion from value_tree

		/// Returns sub-node from given path
		value_tree_node node(std::string_view path) const;
		/// Returns all sub-nodes matching the given path
		value_tree_range range(std::string_view path) const;
		/// Adds a new sub-node to the value tree
		value_tree_node add_node(std::string_view path);

		/// Removes the node at the given path (or this node)
		/**
			Can be used to delete both elements and attributes, has no effect on non-existing nodes.
			Be aware that child nodes may not be updated properly, i.e. all child nodes have to be
			considered invalidated by removing their parent (e.g. they may still report they
			are existing etc.)
		*/
		void remove_node(std::string_view path = {});

		/// Removes all sub-nodes matching the given path
		void remove_range(std::string_view path);

		/// Set value to given path
		/**
			Creates intermediate nodes as required, i.e. this can make a non-existent node existent.
		*/
		void set_value(std::string_view path, const char* value);
		template <class T>
		void set_value(std::string_view path, const T& value);

		/// Set value to this node, equivalent to set_value({}, value)
		void set_value(const char* value);		
		template <class T>
		void set_value(const T& value);

		void set_comment(std::string_view path, const char* comment);

	private:
		using const_value_tree_node::const_value_tree_node;

		friend class detail::value_tree_range<value_tree_node>; // needs to construct nodes
	};

	/// Root node of a value tree, has ownership of all sub-nodes
	class value_tree : public value_tree_node
	{
	public:
		/// Flags for constructing a value tree
		enum format
		{
			/// @{
			/// Read XML / INI file
			/**
				With file path: Opens existing file, throws error on missing file
				Without file path (nullptr): Starts a new file for later saving
			*/
			xml_file,
			ini_file,
			/// @}

			/// @{
			/// Read XML / INI string
			xml_string, 
			ini_string,
			/// @}

			/// @{
			/// Read XML file
			/**
				With file path: Opens file if already existing, starts new file otherwise
				Without file path: Starts a new file for later saving
			*/
			xml_file_new_or_existing,
			ini_file_new_or_existing,
			/// @}

			/// Create new XML element
			/**
				Given string is the name of the new XML element (a single, free-standing XML node)
			*/
			xml_element, 

			/// Creates new INI section
			/**
				Given string is the name of the new INI section (a single, free-standing INI section)
			*/
			ini_section,
		};

		/// Create new value tree
		/**
			String parameter is interpreted depending on format (see format doc)
		*/
		explicit value_tree(format format = xml_file, const char* str = nullptr);
		~value_tree();

		value_tree(const value_tree&) = delete;
		value_tree& operator=(const value_tree&) = delete;

		void save_file(const char* path) const;
		std::string to_string(bool whitespaces) const;
		void load_file(const char* path);
		void load_string(const char* string);
	};

	/// Utility function for converting string to value of given type
	/**
		Converts strings utilizing the value_tree infrastructure.

		Returns an invalid value if conversion fails (see value_tree_value
		for details).
	*/
	template <class T>
	value_tree_value<T> value_from_string(std::string_view str);

	/// Utility function for converting value to string
	/**
		Converts to string utilizing the value_tree infrastructure.
	*/
	template <class T>
	std::string value_to_string(const T& value);
}

#include "value_tree.ipp"