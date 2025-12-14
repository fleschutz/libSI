// SI/prefixes.hpp - contains the SI prefixes 
#pragma once

#include "types.hpp"

namespace si
{
	namespace prefix
	{
	       	// 24 SI prefixes as of 2022 (source: https://en.wikipedia.org/wiki/Metric_prefix)
		                                // Symbol
		const quantity quetta = 1e30;   // Q
		const quantity ronna  = 1e27;   // R
		const quantity yotta  = 1e24;   // Y
		const quantity zetta  = 1e21;   // Z
		const quantity exa    = 1e18;   // E
		const quantity peta   = 1e15;   // P
		const quantity tera   = 1e12;   // T
		const quantity giga   = 1e9;    // G
		const quantity mega   = 1e6;    // k
		const quantity kilo   = 1e3;    // k
		const quantity hecto  = 1e2;    // h
		const quantity deca   = 1e1;    // da

		const quantity deci   = 1e-1;   // d
		const quantity centi  = 1e-2;   // c
		const quantity milli  = 1e-3;   // m
		const quantity micro  = 1e-6;   // μ
		const quantity nano   = 1e-9;   // n
		const quantity pico   = 1e-12;  // p
		const quantity femto  = 1e-15;  // f
		const quantity atto   = 1e-18;  // a
		const quantity zepto  = 1e-21;  // z
		const quantity yocto  = 1e-24;  // y
		const quantity ronto  = 1e-27;  // r
		const quantity quecto = 1e-30;  // q
	}
}	
