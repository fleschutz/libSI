#pragma once
#include <atomic>
#include <cassert>
#include <malloc.h>
#include <type_traits>

#include <boost/iterator/iterator_facade.hpp>

#include <tower/core/utility.hpp>
#include <tower/core/serialization/std.hpp>

namespace core
{
	/// Read-only range to an arbitrary container
	/**
		A range<T> can reference any container storing T, e.g. std::vector<T> or std::list<T>
		and plain C-arrays T[]. It provides basic functions for iterating the range (begin,
		end, size, empty, etc). The range does not store the data, it merely references the
		original container (just like iterators). Therefore, the container must outlive the
		range. In particular, you should not return a local container via range.

		Offers basic conversion functions, e.g. a range<T*> can be created from a container storing
		std::unique_ptr<T>. More complex conversions can be performed with the explicit make_range_*
		functions.

		Uses type-erasue to store iterators.

		Examples:

		core::range<int> foo()
		{
			return m_vector;
		}

		[...]

		for (auto i : foo())
		{
		}

		[...]

		std::map<int, std::unique_ptr<bar>> m;
		auto ptr = core::make_range_second<const bar*>(m);
	*/
	template <class T>
	class range;

	template <class T>
	class range_iterator;

	/// Creates a range that passes all container values through the given adapter
	/**
		The adapted range can return a different type than the original container.

		Example:

		std::vector<std::string> strings;
		core::range<size_t> sizes = core::make_range_adapted(strings, [](const auto& str) { return str.size(); });

		Be careful not to return temporaries as references.

		Supplying an explicit ElementType (e.g. `make_range_adapter<int*>(...)` can increase performance).
	*/
	template <class ElementType = void, class Iterator, class Adapter = void>
	auto make_range_adapted(const Iterator& begin, const Iterator& end, Adapter adapter)
	{
		using element_type = std::conditional_t<std::is_void_v<ElementType>,
			std::decay_t<decltype(adapter(*begin))>,
			ElementType>;

		return core::range<element_type>(begin, end, std::move(adapter));
	}

	template <class ElementType = void, class Container, class Adapter = void>
	auto make_range_adapted(const Container& container, Adapter adapter)
	{
		using element_type = std::conditional_t<std::is_void_v<ElementType>,
			std::decay_t<decltype(adapter(*std::begin(container)))>,
			ElementType>;

		return core::range<element_type>(container, std::move(adapter));
	}

	/// Creates an adapted range by casting to the given type
	/**
		Uses a C-Style cast for explicit casting. Note that ranges can always perform implicit casts.

		Example:

		std::vector<const char*> strings;
		core::range<char*> range = core::range_cast<char*>(strings); // remove the const
	*/
	template <class T, class Container>
	auto range_cast(const Container& container)
	{
		return make_range_adapted(container, [](const auto& x)
		{
			return (T)x; //NOLINT(attower-cstyle-cast)
		});
	}

	/// Returns `first` member of iterator's value type (can be used to iterate over map values)
	template <class ElementType = void, class Iterator>
	auto make_range_first(const Iterator& begin, const Iterator& end)
	{
		return make_range_adapted<ElementType>(begin, end, [](const auto& pair) -> const auto&
		{
			return pair.first;
		});
	}

	/// Returns `first` member of container's value type (can be used to iterate over map keys)
	template <class ElementType = void, class Container>
	auto make_range_first(const Container& container)
	{
		return make_range_adapted<ElementType>(container, [](const auto& pair) -> const auto&
		{
			return pair.first;
		});
	}

	/// Returns `second` member of iterator's value type (can be used to iterate over map values)
	template <class ElementType = void, class Iterator>
	auto make_range_second(const Iterator& begin, const Iterator& end)
	{
		return make_range_adapted<ElementType>(begin, end, [](const auto& pair) -> const auto&
		{
			return pair.second;
		});
	}

	/// Returns `second` member of container's value type (can be used to iterate over map values)
	template <class ElementType = void, class Container>
	auto make_range_second(const Container& container)
	{
		return make_range_adapted<ElementType>(container, [](const auto& pair) -> const auto&
		{
			return pair.second;
		});
	}

	/// Dereferences the container's value type (pointer to value)
	template <class ElementType = void, class Container = void>
	auto make_range_deref(const Container& container)
	{
		return make_range_adapted<ElementType>(container, [](const auto& ptr) -> const auto&
		{
			return *ptr;
		});
	}

	/// Returns the given Member of container's value type
	/**
		Example:
		
		struct foo
		{
			int member;
		}
		std::vector<foo> foos;
		core::range<int> ints = core::make_range_member<&foo::member>(foos);
	*/
	template <auto Member, class ElementType = void, class Container = void>
	auto make_range_member(const Container& container)
	{
		return make_range_adapted<ElementType>(container, [](const auto& x) -> decltype(auto)
		{
			return core::member(x, Member);
		});
	}

	namespace detail { namespace range
	{
		// Storage for type-erased iterators. Should be big enough to keep all the std iterators
		using storage = std::aligned_storage_t<3 * sizeof(void*), alignof(void*)>;

		// VTable for accessing type-erased iterator
		struct iterator_vtable
		{
			virtual void copy_construct(storage& destination, const storage& other) const = 0;
			virtual void move_construct(storage& destination, storage& other) const = 0;
			virtual void copy_assign(storage& lhs, const storage& rhs) const = 0;
			virtual void move_assign(storage& lhs, storage& rhs) const = 0;
			virtual void destroy(storage& storage) const = 0;

			virtual void increment(storage& storage) const = 0;
			virtual void decrement(storage& storage) const = 0;
			virtual bool equal(const storage& lhs, const storage& rhs) const = 0;
			virtual std::ptrdiff_t distance(const storage& from, const storage& to) const = 0;
			virtual void advance(storage& storage, std::ptrdiff_t off) const = 0;
		};

		template <class Iterator>
		struct iterator_vtable_impl final : iterator_vtable
		{
			// Use Heap if Iterator is too big or has incompatible alignment
			static constexpr bool heap = sizeof(Iterator) > sizeof(storage) || (alignof(storage) % alignof(Iterator) != 0); // NOLINT(bugprone-sizeof-expression)

			static const Iterator* ptr(const storage& storage)
			{
				if constexpr(heap)
					return *reinterpret_cast<Iterator const* const*>(&storage);
				else
					return reinterpret_cast<Iterator const*>(&storage);
			}

			static std::conditional_t<heap, Iterator*&, Iterator*> ptr(storage& storage)
			{
				if constexpr(heap)
					return *reinterpret_cast<Iterator**>(&storage);
				else
					return reinterpret_cast<Iterator*>(&storage);
			}

			static void construct(storage& destination, Iterator itr)
			{
				if constexpr(heap)
					ptr(destination) = new Iterator(std::move(itr)); //NOLINT(attower-new-delete)
				else
					new(&destination)Iterator(std::move(itr));
			}

			void copy_construct(storage& destination, const storage& other) const override
			{
				if constexpr(heap)
					ptr(destination) = ptr(other) ? new Iterator(*ptr(other)) : nullptr; //NOLINT(attower-new-delete)
				else
					new(&destination)Iterator(*ptr(other));
			}

			void move_construct(storage& destination, storage& other) const override
			{
				if constexpr(heap)
				{
					ptr(destination) = ptr(other);
					ptr(other) = nullptr;
				}
				else
				{
					new(&destination)Iterator(std::move(*ptr(other)));
				}
			}

			void copy_assign(storage& lhs, const storage& rhs) const override
			{
				if constexpr(heap)
				{
					if (ptr(lhs))
					{
						if (ptr(rhs))
						{
							if constexpr (std::is_copy_assignable_v<Iterator>)
							{
								*ptr(lhs) = *ptr(rhs);
							}
							else
							{
								destroy(lhs);
								copy_construct(lhs, rhs);
							}
						}
						else
						{
							destroy(lhs);
						}
					}
					else if (ptr(rhs))
					{
						copy_construct(lhs, rhs);
					}
				}
				else
				{
					if constexpr (std::is_copy_assignable_v<Iterator>)
					{
						*ptr(lhs) = *ptr(rhs);
					}
					else
					{
						destroy(lhs);
						copy_construct(lhs, rhs);
					}
				}
			}

			void move_assign(storage& lhs, storage& rhs) const override
			{
				if constexpr(heap)
				{
					std::swap(ptr(lhs), ptr(rhs));
				}
				else
				{
					if constexpr (std::is_move_assignable_v<Iterator>)
					{
						*ptr(lhs) = std::move(*ptr(rhs));
					}
					else
					{
						destroy(lhs);
						move_construct(lhs, rhs);
					}
				}
			}

			void destroy(storage& storage) const override
			{
				if constexpr(heap)
				{
					delete ptr(storage); //NOLINT(attower-new-delete)
					ptr(storage) = nullptr;
				}
				else
				{
					ptr(storage)->~Iterator();
				}
			}

			void increment(storage& storage) const override
			{
				assert(ptr(storage) && "incrementing invalid iterator");
				++(*ptr(storage));
			}

			void decrement(storage& storage) const override
			{
				assert(ptr(storage) && "decrementing invalid iterator");
				--(*ptr(storage));
			}

			bool equal(const storage& lhs, const storage& rhs) const override
			{
				assert(ptr(lhs) && ptr(rhs) && "comparing invalid iterators");
				return *ptr(lhs) == *ptr(rhs);
			}

			std::ptrdiff_t distance(const storage& from, const storage& to) const override
			{
				assert(ptr(from) && ptr(to) && "comparing invalid iterators");
				return std::distance(*ptr(from), *ptr(to));
			}

			void advance(storage& storage, std::ptrdiff_t off) const override
			{
				assert(ptr(storage) && "advancing invalid iterator");
				std::advance(*ptr(storage), off);
			}
		};

		template <class Reference, class Adapter>
		struct adapter_traits
		{
			template <class T>
			static Reference execute(const Adapter& adapter, const T& value)
			{
				decltype(auto) result = convert(adapter(value));

				static_assert(!std::is_reference_v<Reference> || std::is_convertible_v<std::decay_t<decltype(result)>&, std::decay_t<Reference>&>,
					"Reference types don't match, would return reference to temporary");
				static_assert(!std::is_reference_v<Reference> || std::is_reference_v<decltype(adapter(value))>,
					"Adapter returning temporary, expecting a reference");

				return convert(adapter(value));
			}

			template <class T>
			static decltype(auto) convert(const T& value)
			{
				return value;
			}

			template <class T, class R = Reference, class = std::enable_if_t<std::is_pointer_v<R>>>
			static decltype(auto) convert(const std::unique_ptr<T>& ptr)
			{
				return ptr.get();
			}

			template <class T, class R = Reference, class = std::enable_if_t<std::is_pointer_v<R>>>
			static decltype(auto) convert(const std::shared_ptr<T>& ptr)
			{
				return ptr.get();
			}
		};

		template <class Iterator>
		const iterator_vtable_impl<Iterator>* query_iterator_vtable()
		{
			// singleton vtable_impl for this type of Iterator
			static const iterator_vtable_impl<Iterator> impl;
			return &impl;
		}

		// every info structure manages a linked series of adapter_layers, a layer is added for every new adaptation on top of a range
		// the first range (directly referencing a container) has one single adapter_layer
		template <class Reference>
		struct adapter_layer
		{
			virtual Reference dereference(const storage& storage) const = 0;
			virtual void copy_inplace(void* destination) const = 0; // copies itself to the given destination
			virtual void destroy() const = 0; // destroys itself
		};

		// layer directly accessing the iterator
		template <class Reference, class Adapter, class Iterator>
		struct adapter_layer_direct : adapter_layer<Reference>, Adapter
		{
			explicit adapter_layer_direct(Adapter adapter)
				: Adapter(std::move(adapter))
			{
			}

			Reference dereference(const storage& storage) const override
			{
				using impl = iterator_vtable_impl<Iterator>;
				using traits = adapter_traits<Reference, Adapter>;
				return traits::execute(*this, **impl::ptr(storage));
			}

			void copy_inplace(void* destination) const override
			{
				assert(uintptr_t(destination) % alignof(adapter_layer_direct) == 0);
				new(destination) adapter_layer_direct(*this);
			}

			void destroy() const override
			{
				this->~adapter_layer_direct();
			}
		};

		// layer accessing a nested layer
		template <class Reference, class Adapter, class OtherReference>
		struct adapter_layer_nested final : adapter_layer<Reference>, Adapter
		{
			size_t nested_offset = 0; // offset from this to next adapter_layer in bytes

			explicit adapter_layer_nested(Adapter adapter)
				: Adapter(std::move(adapter))
			{
			}

			const adapter_layer<OtherReference>* nested() const
			{
				return reinterpret_cast<const adapter_layer<OtherReference>*>(reinterpret_cast<const char*>(this) + nested_offset);
			}

			adapter_layer<OtherReference>* nested()
			{
				return reinterpret_cast<adapter_layer<OtherReference>*>(reinterpret_cast<char*>(this) + nested_offset);
			}

			Reference dereference(const storage& storage) const override
			{
				using traits = adapter_traits<Reference, Adapter>;
				return traits::execute(*this, nested()->dereference(storage));
			}

			void copy_inplace(void* destination) const override
			{
				// copy both this layer and nested one (recursively copies all layers)
				assert(uintptr_t(destination) % alignof(adapter_layer_nested) == 0);
				auto copy = new(destination) adapter_layer_nested(*this);
				nested()->copy_inplace(copy->nested());
			}

			void destroy() const override
			{
				// destroy both this layer and nested one (recursively destroys all layers)
				nested()->destroy();
				this->~adapter_layer_nested();
			}
		};

		// info structure, storing everything required for type-erasure of both iterator and adapter
		// having a separate info structure has several advantages: 1. it's easier to separate iterator
		// and adapter type-erasure. Combining both lead to much more code / indirected calls. 2. it's
		// easier to uniquely identify different ranges, because every range-instantiation will create
		// its own info structure (think about comparing lambad adapters) 3. makes it easier to avoid
		// heap allocations by storing iterators within the iterator storage and all the adapter layers
		// in one chunk of memory
		template <class Reference>
		struct info
		{
			info() = default;
			info(const info&) = delete;
			info& operator=(const info&) = delete;
			~info() = default;

			const iterator_vtable* iterator_vtable = nullptr; // vtable for accessing iterator storage
			const adapter_layer<Reference>* adapter_layer = nullptr; // pointer to the first adapter layer (the adapter memory block)
			size_t adapter_size = 0, adapter_alignment = 0; // properties of the adapter memory block

			virtual void acquire() = 0; // increases the use count
			virtual void release() = 0; // decreases the use count, may free the memory
		};

		template <bool Stateless>
		struct info_direct_base
		{
		};

		template <>
		struct info_direct_base<false>
		{
			std::atomic_int use_count = 1;
		};

		// info structure for directly accessing an iterator (no nested adapters)
		// the single adapter layer is part of the object
		// implemented as a singleton for stateless adapters (no need to allocate individual instances if it is a stateless adapter ->
		// they are all the same)
		template <class Reference, class Adapter, class Iterator>
		struct info_direct final : info<Reference>, info_direct_base<std::is_empty_v<Adapter>>, adapter_layer_direct<Reference, Adapter, Iterator>
		{
			using this_adapter_layer = adapter_layer_direct<Reference, Adapter, Iterator>;

			explicit info_direct(Adapter adapter)
				: this_adapter_layer(std::move(adapter))
			{
				this->iterator_vtable = query_iterator_vtable<Iterator>();
				this->info<Reference>::adapter_layer = this;
				this->adapter_size = sizeof(this_adapter_layer);
				this->adapter_alignment = alignof(this_adapter_layer);
			}

			static info_direct* query(Adapter adapter)
			{
				if constexpr(std::is_empty_v<Adapter>)
				{
					static info_direct s_instance(std::move(adapter)); // NOLINT(attower-global-state)
					return &s_instance;
				}
				else
				{
					return new info_direct(std::move(adapter)); // NOLINT(attower-new-delete)
				}
			}

			void acquire() override
			{
				if constexpr(!std::is_empty_v<Adapter>)
					++this->use_count;
			}

			void release() override
			{
				if constexpr(!std::is_empty_v<Adapter>)
				{
					if (--this->use_count == 0)
						delete this; // NOLINT(attower-new-delete)
				}
			}
		};

		// info structure storing a set of adapter layers
		// this layer returns Reference, the following one OtherReference
		// dynamically layouts memory to keep all the layers in one chunk of memory, together with the info structure itself
		template <class Reference, class Adapter, class OtherReference>
		struct info_nested final : info<Reference>
		{
			std::atomic_int use_count = 1;

			// reassembles C standard layouting for concatenating a structure (size, alignment) with a nested structure
			// (nested_size, nested_alignment). size/alignment are set to the combined size and alignment, returns the offset
			// from the first structure to the nested one
			static size_t calculate_layout(size_t* size, size_t* alignment, size_t nested_size, size_t nested_alignment)
			{
				size_t offset = *size;
				if (*alignment < nested_alignment)
				{
					// use maximum alignment, add padding between the two to properly align the nested structure
					offset = ((offset + nested_alignment - 1) / nested_alignment) * nested_alignment;
					*alignment = nested_alignment;
				}
				*size = offset + nested_size;

				return offset;
			}

			static info_nested* query(Adapter adapter, const info<OtherReference>* nested)
			{
				using this_adapter_layer = adapter_layer_nested<Reference, Adapter, OtherReference>;

				auto adapter_size = sizeof(this_adapter_layer);
				auto adapter_alignment = alignof(this_adapter_layer);

				// offset from this layer to nested layer
				auto nested_offset = calculate_layout(&adapter_size, &adapter_alignment, nested->adapter_size, nested->adapter_alignment);

				auto info_size = sizeof(info_nested);
				auto info_alignment = alignof(info_nested);

				// offset from this info structure to this layer
				auto layer_offset = calculate_layout(&info_size, &info_alignment, adapter_size, adapter_alignment);

				auto ptr = static_cast<info_nested*>(_aligned_malloc(info_size, info_alignment));
				assert(uintptr_t(ptr) % alignof(info_nested) == 0);
				new(ptr) info_nested();
				ptr->iterator_vtable = nested->iterator_vtable;
				auto layer_ptr = reinterpret_cast<this_adapter_layer*>(reinterpret_cast<char*>(ptr) + layer_offset);
				ptr->adapter_layer = layer_ptr;
				ptr->adapter_size = adapter_size;
				ptr->adapter_alignment = adapter_alignment;
				
				assert(uintptr_t(layer_ptr) % alignof(this_adapter_layer) == 0);
				auto this_layer = new(layer_ptr) this_adapter_layer(std::move(adapter));
				this_layer->nested_offset = nested_offset;

				// now copy all existing layers behind this layer
				nested->adapter_layer->copy_inplace(this_layer->nested());

				return ptr;
			}

			void acquire() override
			{
				++use_count;
			}

			void release() override
			{
				if (--use_count == 0)
				{
					this->adapter_layer->destroy();
					this->~info_nested();
					_aligned_free(this);
				}
			}
		};

		// bidirectional tag fits for most std iterators and is all we need for most of the time
		// return by value for scalar types, makes interface a bit easier and simplifies built-in conversions
		template <class T>
		using iterator_base = boost::iterator_facade<
			range_iterator<T>,
			const T,
			boost::bidirectional_traversal_tag,
			std::conditional_t<std::is_scalar_v<T>, T, const T&>
		>;

		// default adapter for returning Reference
		struct default_adapter
		{
			template <class T>
			decltype(auto) operator()(const T& value) const
			{
				return value;
			}
		};
	}}

	template <class T>
	class range_iterator : public detail::range::iterator_base<T>
	{
		static_assert(std::is_same_v<T, std::decay_t<T>>);
	public:
		using reference = typename detail::range::iterator_base<T>::reference;
		using _Unchecked_type = range_iterator; // silences C4996 warnings about unchecked iterators

		range_iterator() = default;

		range_iterator(const range_iterator& other)
			: m_info(other.m_info)
		{
			if (m_info)
			{
				m_info->acquire();
				m_info->iterator_vtable->copy_construct(m_storage, other.m_storage);
			}
		}

		range_iterator(range_iterator&& other)
			: m_info(other.m_info)
		{
			if (m_info)
			{
				m_info->iterator_vtable->move_construct(m_storage, other.m_storage);

				// reset other to default state, take ownership of info (no need to call acquire)
				m_info->iterator_vtable->destroy(other.m_storage);
				other.m_info = nullptr;
			}
		}

		range_iterator& operator=(const range_iterator& other)
		{
			if (this == &other)
				return *this;

			if (m_info == other.m_info)
			{
				if (m_info)
					m_info->iterator_vtable->copy_assign(m_storage, other.m_storage);
			}
			else
			{
				if (m_info)
				{
					m_info->iterator_vtable->destroy(m_storage);
					m_info->release();
				}
				m_info = other.m_info;
				if (m_info)
				{
					m_info->acquire();
					m_info->iterator_vtable->copy_construct(m_storage, other.m_storage);
				}
			}

			return *this;
		}

		range_iterator& operator=(range_iterator&& other)
		{
			if (this == &other)
				return *this;

			if (m_info == other.m_info)
			{
				if (m_info)
				{
					m_info->iterator_vtable->move_assign(m_storage, other.m_storage);

					// reset other to default state
					m_info->iterator_vtable->destroy(other.m_storage);
					m_info->release();
					other.m_info = nullptr;
				}
			}
			else
			{
				if (m_info)
				{
					m_info->iterator_vtable->destroy(m_storage);
					m_info->release();
				}
				m_info = other.m_info;
				if (m_info)
				{
					m_info->iterator_vtable->move_construct(m_storage, other.m_storage);

					// reset other to default state, take ownership of info (no need to call acquire)
					m_info->iterator_vtable->destroy(other.m_storage);
					other.m_info = nullptr;
				}
			}

			return *this;
		}

		~range_iterator()
		{
			if (m_info)
			{
				m_info->iterator_vtable->destroy(m_storage);
				m_info->release();
			}
		}

		// calculates distance to given iterator, implemented to support range::size
		// not efficient for non-random-access iterators, which is why this iterator
		// wasn't declared random-access
		std::ptrdiff_t distance(const range_iterator& to) const
		{
			assert(m_info == to.m_info && "comparing incompatible iterators");

			if (!m_info)
				return 0;

			return m_info->iterator_vtable->distance(m_storage, to.m_storage);
		}

		// advances the iterator, implemented to support range::operator[]
		// not efficient for non-random-access iterators, which is why this iterator
		// wasn't declared random-access
		void advance(std::ptrdiff_t off)
		{
			assert(m_info && "advancing invalid iterator");
			m_info->iterator_vtable->advance(m_storage, off);
		}

	private:
		void increment()
		{
			assert(m_info && "incrementing invalid iterator");
			m_info->iterator_vtable->increment(m_storage);
		}

		void decrement()
		{
			assert(m_info && "decrementing invalid iterator");
			m_info->iterator_vtable->decrement(m_storage);
		}

		reference dereference() const
		{
			assert(m_info && "dereferencing invalid iterator");
			return m_info->adapter_layer->dereference(m_storage);
		}

		bool equal(const range_iterator& other) const
		{
			assert(m_info == other.m_info && "comparing incompatible iterators");

			if (!m_info)
				return true;

			return m_info->iterator_vtable->equal(m_storage, other.m_storage);
		}

		detail::range::info<reference>* m_info = nullptr;
		detail::range::storage m_storage = {};

		template <class>
		friend class range;

		friend class boost::iterator_core_access;
	};

	template <class T>
	class range
	{
	public:
		using const_iterator = range_iterator<T>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;
		using reference = typename range_iterator<T>::reference;
		using value_type = std::decay_t<T>;

		range() = default;

		template <class Container, class Adapter = detail::range::default_adapter>
		/*explicit*/ range(const Container& c, Adapter adapter = {})
		{
			using std::size;
			using std::begin;
			using std::end;
			init(begin(c), end(c), std::move(adapter), size(c));
		}

		//template <class Container, class Adapter, class = std::enable_if_t<!std::is_same_v<std::decay_t<Container>, std::decay_t<Adapter>>>>
		//range(const Container& c, Adapter&& adapter)
		//{
		//	init(std::begin(c), std::end(c), std::forward<Adapter>(adapter), std::size(c));
		//}

		template <class Iterator, class Adapter = detail::range::default_adapter>
		range(const Iterator& begin, const Iterator& end, Adapter adapter = {})
		{
			init(begin, end, std::move(adapter), -1);
		}

		range(range_iterator<T> begin, range_iterator<T> end)
			: m_begin(std::move(begin)), m_end(std::move(end))
		{
			m_size = m_begin.distance(m_end);
		}

		const range_iterator<T>& begin() const
		{
			return m_begin;
		}

		const range_iterator<T>& end() const
		{
			return m_end;
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(m_end);
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(m_begin);
		}

		size_t size() const
		{
			return m_size;
		}

		bool empty() const
		{
			return m_size == 0;
		}

		/// Access elements by index
		/**
			Not efficient for non-random-access iterators. Prefer iterators instead.
		*/
		reference operator[](size_t idx) const
		{
			auto itr = m_begin;
			itr.advance(idx);
			return *itr;
		}

		reference front() const
		{
			return *m_begin;
		}

		reference back() const
		{
			auto itr = m_end;
			--itr;
			return *itr;
		}

		/// Returns true if range contains the given value
		/**
			Always performs a linear lookup, which is not efficient if underlying container is e.g. a std::set.
		*/
		bool contains(reference value) const
		{
			for (const auto& x : *this)
			{
				if (x == value)
					return true;
			}

			return false;
		}

	private:
		template <class Iterator, class Adapter>
		void init(Iterator begin, Iterator end, Adapter adapter, size_t size)
		{
			using vtable_impl = detail::range::iterator_vtable_impl<Iterator>;

			vtable_impl::construct(m_begin.m_storage, begin);
			vtable_impl::construct(m_end.m_storage, end);
			m_begin.m_info = m_end.m_info = detail::range::info_direct<reference, Adapter, Iterator>::query(std::move(adapter));
			m_end.m_info->acquire(); // query already set use_count to 1, acquire for the second iterator
			m_size = (size != -1) ? size : std::distance(begin, end);
		}

		template <class U, class Adapter>
		void init(const range_iterator<U>& begin, const range_iterator<U>& end, Adapter adapter, size_t size)
		{
			using other_reference = typename range_iterator<U>::reference;

			assert(begin.m_info == end.m_info);

			begin.m_info->iterator_vtable->copy_construct(m_begin.m_storage, begin.m_storage);
			end.m_info->iterator_vtable->copy_construct(m_end.m_storage, end.m_storage);
			m_begin.m_info = m_end.m_info = detail::range::info_nested<reference, Adapter, other_reference>::query(std::move(adapter), begin.m_info);
			m_end.m_info->acquire(); // query already set use_count to 1, acquire for the second iterator
			m_size = (size != -1) ? size : m_begin.distance(m_end);
		}

		size_t m_size = 0; // store size for performance reasons and for debugging
		range_iterator<T> m_begin, m_end;
	};
}