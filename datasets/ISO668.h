/// @file  datasets/ISO668.h
/// @brief Contains ISO 668: Series 1 freight containers

#pragma once
#include <SI/literals.h>
using namespace SI;

constexpr struct {

  length container_1AA_ext_length   = 12.192_m; // (aka 40-foot standard)
  length container_1AA_ext_height   =  2.591_m;
  length container_1AA_ext_width    =  2.438_m;
  mass container_1AA_max_gross_mass = 36'000_kg;
  // TODO

} ISO668;
