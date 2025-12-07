#pragma once
#include <cstdint>
#include <type_traits>
#include <boost/iterator/iterator_facade.hpp>

namespace core
{

	/// Collection of status bits encoded in a type
	/**
		Utility class to set / reset / test a fixed collection of status bits.

		See CORE_DEFINE_STATUS_MASK on how to define a status bit mask.

		Also supports iterating over all masked status values:
		```
		for (auto status : my_bit_mask)
		{
		}
		```
	*/
	template <auto... Statuses>
	class status_bits_mask
	{
	public:
		using status_type = std::common_type_t<decltype(Statuses)...>; //NOLINT(attower-cstyle-cast)

		class iterator 
			: public boost::iterator_facade<iterator, status_type, boost::forward_traversal_tag, status_type>
		{
		public:
			explicit iterator(size_t idx = 0);

		private:
			status_type dereference() const;
			bool equal(const iterator& other) const;
			void increment();

			size_t m_idx;

			friend class boost::iterator_core_access;
		};

		iterator begin() const;
		iterator end() const;

		/// Copies the state of all masked status bits from `source` to `dest`
		template <class StatusBits>
		void copy(const StatusBits& source, StatusBits& dest) const;
	};

	/// Defines a constant status bit mask
	/**
		Example:
		```
		CORE_DEFINE_STATUS_MASK(MyMask, STATUS_A, STATUS_B, STATUS_C);
		...
		statusBits.reset(MyMask);
		assert(statusBits.none(MyMask));
		```
	*/
#define CORE_DEFINE_STATUS_MASK(name_, ...)	\
	inline constexpr ::core::status_bits_mask<__VA_ARGS__> name_ = {}

	/// Collection of `Count` boolean statuses
	/**
		Every status is stored as an independent bit. `Status` should be an enum (class),
		`Count` the total count of statuses.

		Most methods take a variadic number of arguments. Arguments can be either indivudal
		statuses or a collection of statuses (see `status_bits_mask`)

		Note that this class does not offer a constructor / zero-initialization in order
		to be compatible with unions. Therefore, every instance needs to be initializied
		explicitly (e.g. `status_bits s = {};`).
	*/
	template <class Status, Status Count>
	class status_bits
	{
	public:
		/// Returns the state of the given status
		[[nodiscard]] constexpr __forceinline bool operator[](Status status) const;

		/// Returns true iff all given states are set
		template <class... Statuses>
		[[nodiscard]] constexpr __forceinline bool all(Statuses... statuses) const;

		/// Returns true iff any of the given states is set
		template <class... Statuses>
		[[nodiscard]] constexpr __forceinline bool any(Statuses... statuses) const;

		/// Returns true iff none of the given states is set
		template <class... Statuses>
		[[nodiscard]] constexpr __forceinline bool none(Statuses... statuses) const;

		/// Sets all of the given states
		template <class... Statuses>
		constexpr __forceinline void set(Statuses... statuses);

		/// Resets all of the given states
		template <class... Statuses>
		constexpr __forceinline void reset(Statuses... statuses);

		/// Toggles all of the given states
		template <class... Statuses>
		constexpr __forceinline void toggle(Statuses... statuses);

		/// Clears all states
		constexpr __forceinline void clear();

		/// Returns true if no state is set at all
		[[nodiscard]] constexpr __forceinline bool empty() const;

	private:
		constexpr __forceinline bool all2(Status status) const;
		template <Status... Statuses>
		constexpr __forceinline bool all2(status_bits_mask<Statuses...>) const;
		constexpr __forceinline bool any2(Status status) const;
		template <Status... Statuses>
		constexpr __forceinline bool any2(status_bits_mask<Statuses...>) const;
		constexpr __forceinline void set2(Status status);
		template <Status... Statuses>
		constexpr __forceinline void set2(status_bits_mask<Statuses...>);
		constexpr __forceinline void reset2(Status status);
		template <Status... Statuses>
		constexpr __forceinline void reset2(status_bits_mask<Statuses...>);
		constexpr __forceinline void toggle2(Status status);
		template <Status... Statuses>
		constexpr __forceinline void toggle2(status_bits_mask<Statuses...>);

		// Remember to update the debugger visualization in `tower.natvis` file when
		// changing the status layout
		std::uint32_t m_bits[(static_cast<size_t>(Count) + 31) / 32]; // NOLINT(attower-cstyle-cast)
	};
}

#include "status_bits.ipp"