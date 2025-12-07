#pragma once

#include <map>

namespace stdext
{
	template <typename A, typename B>
	std::multimap<B, A> inverse_map(const std::map<A, B>& src) 
	{
		std::multimap<B, A> res;

		for (auto iter = src.begin(); iter != src.end(); ++iter)
			res.insert({ iter->second, iter->first });

		return res;
	}
}