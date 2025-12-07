#pragma once
#include "status_bits.hpp"

#include <cassert>
#include <iterator>

namespace core
{
	template <auto... Statuses>
	status_bits_mask<Statuses...>::iterator::iterator(size_t idx)
		: m_idx(idx)
	{
	}

	template <auto... Statuses>
	typename status_bits_mask<Statuses...>::status_type status_bits_mask<Statuses...>::iterator::dereference() const
	{
		assert(m_idx < sizeof...(Statuses));
		const typename status_bits_mask<Statuses...>::status_type list[] = { Statuses... };
		return list[m_idx];
	}

	template <auto... Statuses>
	bool status_bits_mask<Statuses...>::iterator::equal(const iterator& other) const
	{
		return m_idx == other.m_idx;
	}

	template <auto... Statuses>
	void status_bits_mask<Statuses...>::iterator::increment()
	{
		++m_idx;
	}

	template <auto... Statuses>
	typename status_bits_mask<Statuses...>::iterator status_bits_mask<Statuses...>::begin() const
	{
		return iterator(0);
	}

	template <auto... Statuses>
	typename status_bits_mask<Statuses...>::iterator status_bits_mask<Statuses...>::end() const
	{
		return iterator(sizeof...(Statuses));
	}

	template <auto... Statuses>
	template <class StatusBits>
	void status_bits_mask<Statuses...>::copy(const StatusBits& source, StatusBits& dest) const
	{
		auto copy_status = [&source, &dest](auto status)
		{
			if (source[status])
				dest.set(status);
			else
				dest.reset(status);

			return 0;
		};

		int ignore[] = { copy_status(Statuses)... };
	}

	template <class Status, Status Count>
	constexpr __forceinline bool status_bits<Status, Count>::operator[](Status status) const  // NOLINT(attower-cstyle-cast)
	{
		assert(static_cast<size_t>(status) < static_cast<size_t>(Count));
		auto idx = static_cast<size_t>(status) / 32;
		assert(idx < std::size(m_bits));
		return m_bits[idx] & (1 << (static_cast<size_t>(status) - idx * 32));
	}

	namespace detail
	{
		template <class Status, class Check>
		struct status_bits_compatible : std::is_same<Status, Check> {};

		template <class Status, Status... Statuses>
		struct status_bits_compatible<Status, status_bits_mask<Statuses...>> : std::true_type {};

		template <class Status, class... Statuses>
		inline constexpr bool status_bits_compatible_v = (status_bits_compatible<Status, Statuses>::value && ...);
	}

	template <class Status, Status Count>
	template <class... Statuses>
	constexpr __forceinline bool status_bits<Status, Count>::all(Statuses... statuses) const
	{
		static_assert(detail::status_bits_compatible_v<Status, Statuses...>, "Not all parameters are compatible with this status type");
		return (all2(statuses) && ...);
	}

	template <class Status, Status Count>
	template <class... Statuses>
	constexpr __forceinline bool status_bits<Status, Count>::any(Statuses... statuses) const
	{
		static_assert(detail::status_bits_compatible_v<Status, Statuses...>, "Not all parameters are compatible with this status type");
		return (any2(statuses) || ...);
	}

	template <class Status, Status Count>
	template <class... Statuses>
	constexpr __forceinline bool status_bits<Status, Count>::none(Statuses... statuses) const
	{
		static_assert(detail::status_bits_compatible_v<Status, Statuses...>, "Not all parameters are compatible with this status type");
		return !any(statuses...);
	}

	template <class Status, Status Count>
	template <class... Statuses>
	constexpr __forceinline void status_bits<Status, Count>::set(Statuses... statuses)
	{
		static_assert(detail::status_bits_compatible_v<Status, Statuses...>, "Not all parameters are compatible with this status type");
		int ignore[] = { (set2(statuses), 0)... };
	}

	template <class Status, Status Count>
	template <class... Statuses>
	constexpr __forceinline void status_bits<Status, Count>::reset(Statuses... statuses)
	{
		static_assert(detail::status_bits_compatible_v<Status, Statuses...>, "Not all parameters are compatible with this status type");
		int ignore[] = { (reset2(statuses), 0)... };
	}

	template <class Status, Status Count>
	template <class... Statuses>
	constexpr __forceinline void status_bits<Status, Count>::toggle(Statuses... statuses)
	{
		static_assert(detail::status_bits_compatible_v<Status, Statuses...>, "Not all parameters are compatible with this status type");
		int ignore[] = { (toggle2(statuses), 0)... };
	}

	template <class Status, Status Count>
	constexpr __forceinline void status_bits<Status, Count>::clear()
	{
		for (auto& bits : m_bits)
			bits = 0;
	}

	template <class Status, Status Count>
	constexpr __forceinline bool status_bits<Status, Count>::empty() const
	{
		for (auto bits : m_bits)
		{
			if (bits)
				return false;
		}

		return true;
	}

	template <class Status, Status Count>
	constexpr __forceinline bool status_bits<Status, Count>::all2(Status status) const
	{
		return (*this)[status];
	}

	template <class Status, Status Count>
	template <Status... Statuses>
	constexpr __forceinline bool status_bits<Status, Count>::all2(status_bits_mask<Statuses...>) const
	{
		return all(Statuses...);
	}

	template <class Status, Status Count>
	constexpr __forceinline bool status_bits<Status, Count>::any2(Status status) const
	{
		return (*this)[status];
	}

	template <class Status, Status Count>
	template <Status... Statuses>
	constexpr __forceinline bool status_bits<Status, Count>::any2(status_bits_mask<Statuses...>) const
	{
		return any(Statuses...);
	}

	template <class Status, Status Count>
	constexpr __forceinline void status_bits<Status, Count>::set2(Status status)
	{
		assert(static_cast<size_t>(status) < static_cast<size_t>(Count));
		auto idx = static_cast<size_t>(status) / 32;
		assert(idx < std::size(m_bits));
		m_bits[idx] |= (1 << (static_cast<size_t>(status) - idx * 32));
	}

	template <class Status, Status Count>
	template <Status... Statuses>
	constexpr __forceinline void status_bits<Status, Count>::set2(status_bits_mask<Statuses...>)
	{
		set(Statuses...);
	}

	template <class Status, Status Count>
	constexpr __forceinline void status_bits<Status, Count>::reset2(Status status)
	{
		assert(static_cast<size_t>(status) < static_cast<size_t>(Count));
		auto idx = static_cast<size_t>(status) / 32;
		assert(idx < std::size(m_bits));
		m_bits[idx] &= ~(1 << (static_cast<size_t>(status) - idx * 32));
	}

	template <class Status, Status Count>
	template <Status... Statuses>
	constexpr __forceinline void status_bits<Status, Count>::reset2(status_bits_mask<Statuses...>)
	{
		reset(Statuses...);
	}

	template <class Status, Status Count>
	constexpr __forceinline void status_bits<Status, Count>::toggle2(Status status)
	{
		if ((*this)[status])
			reset(status);
		else
			set(status);
	}

	template <class Status, Status Count>
	template <Status... Statuses>
	constexpr __forceinline void status_bits<Status, Count>::toggle2(status_bits_mask<Statuses...>)
	{
		toggle(Statuses...);
	}
}