// prefixes.hpp - contains the 24 SI prefixes as of 2022.
#pragma once

#include "types.hpp"

namespace si
{
	namespace prefix // details: https://en.wikipedia.org/wiki/Metric_prefix
	{
		                                 // Symbol
		const quantity quetta = 10e30;   // Q
		const quantity ronna  = 10e27;   // R
		const quantity yotta  = 10e24;   // Y
		const quantity zetta  = 10e21;   // Z
		const quantity exa    = 10e18;   // E
		const quantity peta   = 10e15;   // P
		const quantity tera   = 10e12;   // T
		const quantity giga   = 10e9;    // G
		const quantity mega   = 10e6;    // k
		const quantity kilo   = 10e3;    // k
		const quantity hecto  = 10e2;    // h
		const quantity deca   = 10e1;    // da

		const quantity deci   = 10e-1;   // d
		const quantity centi  = 10e-2;   // c
		const quantity milli  = 10e-3;   // m
		const quantity micro  = 10e-6;   // μ
		const quantity nano   = 10e-9;   // n
		const quantity pico   = 10e-12;  // p
		const quantity femto  = 10e-15;  // f
		const quantity atto   = 10e-18;  // a
		const quantity zepto  = 10e-21;  // z
		const quantity yocto  = 10e-24;  // y
		const quantity ronto  = 10e-27;  // r
		const quantity quecto = 10e-30;  // q
	}
}	
