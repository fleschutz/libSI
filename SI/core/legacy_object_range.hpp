#pragma once

#include <cassert>
#include <boost\iterator\iterator_facade.hpp>

/** \file
	Defines a helper range proxy for streamlining access to legacy ATTower "object arrays".

	A typical example is the ExEngine PARAMETERS array:
	* Simple / plain array of structures / objects
	* Access to objects via pointers (PARAMETERS*)
	
	The `legacy_object_range` utility class gives access to such an array via standard iterators.
	* legacy_object_range iterators return pointers (instead of references)
	* legacy_object_range supports basic filtering (e.g. for skipping "invalid" objects)

	See `legacy_object_range_default_filter` on how to filter / convert elements
*/

namespace core
{
	namespace detail
	{
		// Write your own filter struct following this example to adapt your range
		template <class BaseIterator>
		struct legacy_object_range_default_filter
		{
			// Return true if the range should skip this given element
			bool skip(BaseIterator) const
			{
				return false;
			}

			// Return the value that should be returned for this element
			// Can convert the return value to a different type, access some sub-element, etc.
			decltype(auto) dereference(BaseIterator itr) const
			{
				return *itr;
			}
		};

		template <class ReturnType, class BaseIterator, class Filter>
		class legacy_object_range_iterator
			: public boost::iterator_facade<legacy_object_range_iterator<ReturnType, BaseIterator, Filter>, ReturnType, boost::forward_traversal_tag, ReturnType>
			, Filter
		{
		public:
			legacy_object_range_iterator() = default;

			template <class... FilterArg>
			explicit legacy_object_range_iterator(BaseIterator itr, BaseIterator end, FilterArg&&... arg)
				: Filter(std::forward<FilterArg>(arg)...), m_itr(itr), m_end(end)
			{
				// The first element might be filtered, move `m_ptr` to the first non-filtered object
				assert(m_itr <= m_end);
				while (m_itr != m_end && filter().skip(m_itr))
					++m_itr;
			}

			legacy_object_range_iterator end() const
			{
				legacy_object_range_iterator end = *this;
				end.m_itr = end.m_end;
				return end;
			}

		private:
			const Filter& filter() const
			{
				return *this;
			}

			ReturnType dereference() const
			{
				return filter().dereference(m_itr);
			}

			bool equal(const legacy_object_range_iterator& other) const
			{
				assert(m_end == other.m_end); // Make sure both iterators point to the same range
				return m_itr == other.m_itr;
			}

			void increment()
			{
				assert(m_itr);
				assert(m_itr < m_end);

				while (true)
				{
					++m_itr;

					if (m_itr == m_end)
						return; // Reached the end

					if (!filter().skip(m_itr))
						return; // This element is not filtered out, return

					// This element is filtered out, continue incrementing
				}
			}

			BaseIterator m_itr{};
			BaseIterator m_end{};

			friend class boost::iterator_core_access;
		};
	}

	template <class ReturnType, class BaseIterator, class Filter = detail::legacy_object_range_default_filter<BaseIterator>>
	class legacy_object_range
	{
	public:
		template <class... FilterArg>
		explicit legacy_object_range(BaseIterator begin, BaseIterator end, FilterArg&&... args)
			: m_iterator(begin, end, std::forward<FilterArg>(args)...)
		{

		}

		auto begin() const
		{
			return m_iterator;
		}

		auto end() const
		{
			return m_iterator.end();
		}

	private:
		detail::legacy_object_range_iterator<ReturnType, BaseIterator, Filter> m_iterator;
	};
}