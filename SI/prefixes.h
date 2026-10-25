/// @file    SI/prefixes.h
/// @brief   Defines the 24 SI prefixes as of 2026
/// @details More info at: https://en.wikipedia.org/wiki/Metric_prefix

#pragma once
#include <SI/units.h>

namespace SI {

  //                      NAME     VALUE     SYMBOL
  constexpr dimensionless quetta = 1e30;  // Q
  constexpr dimensionless ronna  = 1e27;  // R
  constexpr dimensionless yotta  = 1e24;  // Y
  constexpr dimensionless zetta  = 1e21;  // Z
  constexpr dimensionless exa    = 1e18;  // E
  constexpr dimensionless peta   = 1e15;  // P
  constexpr dimensionless tera   = 1e12;  // T
  constexpr dimensionless giga   = 1e9;   // G
  constexpr dimensionless mega   = 1e6;   // M
  constexpr dimensionless kilo   = 1e3;   // k
  constexpr dimensionless hecto  = 1e2;   // h
  constexpr dimensionless deca   = 1e1;   // da

  constexpr dimensionless deci   = 1e-1;  // d
  constexpr dimensionless centi  = 1e-2;  // c
  constexpr dimensionless milli  = 1e-3;  // m
  constexpr dimensionless micro  = 1e-6;  // µ
  constexpr dimensionless nano   = 1e-9;  // n
  constexpr dimensionless pico   = 1e-12; // p
  constexpr dimensionless femto  = 1e-15; // f
  constexpr dimensionless atto   = 1e-18; // a
  constexpr dimensionless zepto  = 1e-21; // z
  constexpr dimensionless yocto  = 1e-24; // y
  constexpr dimensionless ronto  = 1e-27; // r
  constexpr dimensionless quecto = 1e-30; // q

} // end of namespace
