#pragma once

#include <cassert>

#include <memory>
#include <iterator>
#include <string>

#include <boost/iterator/iterator_facade.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/optional.hpp>
#include <boost/type_traits.hpp>

#define CONFIGURATION_ENABLE_GLM_TYPES

#ifdef CONFIGURATION_ENABLE_GLM_TYPES
#include <glm/glm.hpp>
#endif

struct mxml_node_s;
typedef mxml_node_s mxml_node_t;

/// Abstraction layer for configuration / XML files.
/**
	// Usage:
	// 
	// XML:
	// 
	// <?xml version="1.0"?>
	// <vehicle>
	// 		<body>
	// 			<mass unit="kg">1500.0</mass>
	// 		</body>
	//		<wheels>
	//			<wheel id="0"></wheel>
	//			<wheel id="1"></wheel>
	//			<wheel id="2"></wheel>
	//			<wheel id="3"></wheel>
	//		</wheels>
	//		<engine>
	//			<torque>...</torque>
	//			<hp>...</hp>
	//			<newton>...</newton>
	//		</engine>
	// </vehicle>

	// Code:

	configuration::store_ptr cfg = configuration::store::load("config.xml");
	
	// get simple values
	float mass = cfg->get<float>("vehicle.body.mass", 5.0f);
	std::string unit = cfg->find("vehicle.body.mass")->attr("unit");
	std::string textContent = cfg->find("vehicle.body.mass")->text(); // Note: will always use MXML_OPAQUE, so will always work with the complete content of the node

	configuration::node::iterator i = cfg->find("vehicle.body.mass");
	
	if (i != cfg->end()) 
	{
		float m = i->get<float>();
		std::string s = i->attr("unit");
	}

	// iterating over collections
	for (configuration::node::iterator iter = cfg->find("vehicle.wheels.wheel"), iter != cfg->end(), iter++ )
	{
		int id = iter->get<int>("id");
	}

	// iterating over complete subtree via wildcard selector
	for (configuration::node::iterator iter = cfg->find("vehicle.engine.*"), iter != cfg->end(), iter++ )
	{
		// do something
	}

	// manipulating the tree is also possible:
	configuration::node::iterator a = [...];

	// adding/setting attribute will template depending on your input type
	a->set(0.0, "name-of-the-attribute")

	// setting the node value/text - use set without attribute name
	// Note: will always use MXML_OPAQUE, so will always work with the complete content of the node
	a->set("This is the node value");

	// create a new node
	configuration::node::iterator b = a->createNode("NewSubNodeOfA");

	// create a new xml
	configuration::store_ptr cfg2 = configuration::store::create();

	// save the xml directly
	cfg2->save("filename.xml");

	// get the document as string for further use
	cfg2->raw();

	// More useful stuff
	// get xml of a sub-tree
	std::string xmlNode = a->raw();

	// The xml-path of the current node
	// will return e.g.: rootNode.abc.a[3].b[0]
	// result can be used in 'find' method of the root node to get exactly the same node as before.
	std::string xmlPath = a->path();

	TODO:
	- iterator ranges DONE
	- clone method
	- load from mxml_node_t
	- exceptions
	- saving DONE
	- set methods DONE
	- iterator and const correctness DONE
	- remove configuration::end() DONE
	- configuration: skip text nodes optional?
	- $$$
 */
namespace configuration {
	
	template <typename>
	struct translator;


	class node {
	public:
		// boost::iterator_facade for simple iterator implementation
		template<typename T>
		class bidirectional_iterator : public boost::iterator_facade<bidirectional_iterator<T>, T, boost::forward_traversal_tag> {
		public:
			bidirectional_iterator();
			bidirectional_iterator(mxml_node_t* xml_node, const char* filter);
			bidirectional_iterator(mxml_node_t* xml_node, const std::string& filter);

			// this constructor allows conversion from iterator to const_iterator but not vice versa
			template <typename U>
			bidirectional_iterator(bidirectional_iterator<U> const & other,
				typename boost::enable_if<boost::is_convertible<U*, T*>, int>::type = 0)
				: _current(other._current._xml_node), _filterStr(other._filterStr) {}

		private:
			friend class boost::iterator_core_access; // boost::iterator_facade needs this
			template <class> friend class bidirectional_iterator; // iterator must be friend of const_iterator and vice versa

			template <typename U>
			bool equal(bidirectional_iterator<U> const & other) const;
			void increment();
			T & dereference() const;

			mutable typename boost::remove_cv<T>::type _current; // must be mutable to allow "T& dereference() const"
			std::string _filterStr;
		};

		typedef bidirectional_iterator<node> iterator;
		typedef bidirectional_iterator<const node> const_iterator;
		typedef boost::iterator_range<iterator> child_range;
		typedef boost::iterator_range<const_iterator> const_child_range;
		
		bool valid() const;

		const char* name() const;
		
		bool has_attr(const char* name) const;

		const char* attr(const char* name) const;

		/// The complete path to the current xml document; can be used with 'find' to reselect the exact node
		std::string path();

		/// the child-index of this node relative to its parent
		int index();
		
		template <typename T>
		typename translator<T>::result_type attr(const char* name) const;
		
		template<typename T>
		typename translator<T>::result_type attr(const char* name, T const & defaultValue) const;

		/// the nodes contents (aka the text between the opening and closing tag); Note: will always use MXML_OPAQUE, so will always work with the complete content of the node
		const char* text() const;

		/// get the raw xml of complete sub-tree, including the current node
		/**
		@fancyFormatting if set the tree will be formatted with additional newlines and tabs to produce a nice xml-tree.
		Use this only if the xml-tree was created on the fly. If you read a existing file it will most likely already 
		have the newlines and tabs.
		*/
		std::string raw(bool fancyFormatting = true) const;
		
		template <typename T>
		typename translator<T>::result_type get() const;
		
		template<typename T>
		typename translator<T>::result_type get(T const & defaultValue) const;
		
		template<typename T>
		typename translator<T>::result_type get(const char* path, T const & defaultValue) const;
		// cannot offer text() with path but without default, because the signature could clash with text(default)

		iterator iter();

		iterator find(const char * path);
		const_iterator find(const char * path) const;

		iterator first_child_of(const char * path);
		const_iterator first_child_of(const char * path) const;

		iterator begin(const char* filter = NULL);
		const_iterator begin(const char* filter = NULL) const;
		iterator end() const;
		
		child_range childs(const char* filter = NULL);
		const_child_range childs(const char* filter = NULL) const;

		// The origin of nodes
		node::iterator createNode(const std::string& nodeName);

		// Set attribute of node to value val.
		// attribute will be created if not present
		// if attribute is nullptr the text of the element will be set
		template<typename T>
		void set(const T& val, const char* attribute = nullptr);

		bool operator==(const node& rhs);

	private:
		mxml_node_t* _xml_node;

		friend class bidirectional_iterator<node>;
		friend class store;
		
		node(mxml_node_t* xml);
		
		node(node const & rhs);
		node & operator=(node const & rhs);
	};

#if _MSC_VER >= 1600
	typedef std::shared_ptr<store> store_ptr;
#else
	typedef std::tr1::shared_ptr<store> store_ptr;
#endif

	node::iterator end();

	class store {
	public:
		typedef node::iterator iterator;
		typedef node::const_iterator const_iterator;

		// made load a static method; makes sense and avoids friend declaration
		// makes also hammer
		static store_ptr load(const char* filename);
		static store_ptr loadExclusive(const char* filename, int retries=0);
		bool isExclusive() const;

		/// load xml from string
		static store_ptr loadFromString(const std::string& xmlString);

		/// load from existing node. Note: will not take ownership of root node
		static store_ptr loadFromMxmlNode(mxml_node_t* root);

		/// create an empty xml store
		static store_ptr create();
		~store();

		/// get the raw xml of complete tree, including the current node
		/**
		@fancyFormatting if set the tree will be formatted with additional newlines and tabs to produce a nice xml-tree.
		Use this only if the xml-tree was created on the fly. If you read a existing file it will most likely already
		have the newlines and tabs.
		*/
		std::string raw(bool fancyFormatting = true);
		void createXmlHeader();

		/// save the current xml-tree to a file
		/**
		@fancyFormatting if set the tree will be formatted with additional newlines and tabs to produce a nice xml-tree.
		Use this only if the xml-tree was created on the fly. If you read a existing file it will most likely already
		have the newlines and tabs.
		*/
		bool save(const std::string& filename, bool fancyFormatting = true);

		node const & root() const;
		node  & root();

		template <typename T>
		typename translator<T>::result_type get(const char* path, T const & defaultValue) const;

		iterator find(const char* path);
		const_iterator find(const char* path) const;

		const_iterator begin(const char* filter = NULL) const;
		iterator end() const;
		iterator begin(const char* filter = NULL);

		bool is_valid() const;

	private:
		store(node const & root, bool ownsRoot = true);
		store(store const & rhs);

		store & operator=(store const & rhs);

		node _root;
		bool _ownsRoot;

		void* _handle;
	};

	//store_ptr clone(store const * other);
	
	/**
		Store takes ownership of mxml_node_t. If retain count of node is > 1, exception is thrown.
	 */
	//store* load(mxml_node_t* node);


	/**
		Translators implement conversion from node text and attributes to application specific types.
		To add support for a new type, specialize the template either within this header file
		(if general purpose) or somewhere in your application (if application specific).
	*/

	// made translator a struct because some specializations return a type != T
	// and without C++11 we have to specify the return type somehow
	// also combined text and attribute translation
	// also the translator now gets a attribute name and has to extract the attribute string itself
	// also used boost::optional to signalize failure

	// default implementation
	template <typename T>
	struct translator {
		typedef T result_type;
		static boost::optional<result_type> translate(node const & n, const char* attribute_name);
		static boost::optional<std::string> translateFwd(boost::optional<result_type> value);
	};

	// std::string implementation
	template <>
	struct translator<std::string> {
		typedef std::string result_type;
		static boost::optional<result_type> translate(node const & n, const char* attribute_name);
		static boost::optional<std::string> translateFwd(boost::optional<result_type> value);
	};
	
	// const char* uses std::string implementation
	template <>
	struct translator < const char* > : translator<std::string> {};

	// const char[N] (string literals) uses std::string implementation
	template <size_t N>
	struct translator < const char[N] > : translator<std::string>{};
	
#ifdef CONFIGURATION_ENABLE_GLM_TYPES
	// glm::vec2 implementation
	template <typename T, glm::precision P>
	struct translator < glm::vec<2, T, P> > {
		typedef typename glm::vec<2, T, P> result_type;
		static boost::optional<result_type> translate(node const & n, const char* attribute_name);
	};

	// glm::vec3 implementation
	template <>
	struct translator < glm::vec3 > {
		typedef glm::vec3 result_type;
		static boost::optional<result_type> translate(node const & n, const char* attribute_name);
	};
#endif

} // configuration

#include "configuration.ipp"