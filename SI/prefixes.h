/// @file   SI/prefixes.h
/// @brief  Defines the 24 SI prefixes

#pragma once
#include <SI/units.h>

namespace SI {

	constexpr dimensionless quetta = 1e30; // 'Q' prefix
	constexpr dimensionless ronna  = 1e27; // 'R' prefix
	constexpr dimensionless yotta  = 1e24; // 'Y' prefix
	constexpr dimensionless zetta  = 1e21; // 'Z' prefix
	constexpr dimensionless exa    = 1e18; // 'E' prefix
	constexpr dimensionless peta   = 1e15; // 'P' prefix
	constexpr dimensionless tera   = 1e12; // 'T' prefix
	constexpr dimensionless giga   = 1e9;  // 'G' prefix
	constexpr dimensionless mega   = 1e6;  // 'M' prefix
	constexpr dimensionless kilo   = 1e3;  // 'k' prefix
	constexpr dimensionless hecto  = 1e2;  // 'h' prefix
	constexpr dimensionless deca   = 1e1;  // 'da' prefix

	constexpr dimensionless deci   = 1e-1; // 'd' prefix
	constexpr dimensionless centi  = 1e-2; // 'c' prefix
	constexpr dimensionless milli  = 1e-3; // 'm' prefix
	constexpr dimensionless micro  = 1e-6; // 'µ' prefix
	constexpr dimensionless nano   = 1e-9; // 'n' prefix
	constexpr dimensionless pico   = 1e-12;// 'p' prefix
	constexpr dimensionless femto  = 1e-15;// 'f' prefix
	constexpr dimensionless atto   = 1e-18;// 'a' prefix
	constexpr dimensionless zepto  = 1e-21;// 'z' prefix
	constexpr dimensionless yocto  = 1e-24;// 'y' prefix
	constexpr dimensionless ronto  = 1e-27;// 'r' prefix
	constexpr dimensionless quecto = 1e-30;// 'q' prefix

} // end of namespace
