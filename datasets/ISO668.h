/// @file  SI/datasets/ISO668.h
/// @brief Contains ISO 668: Series 1 freight containers

#pragma once
#include <SI/literals.h>

namespace ISO668 {
	using namespace SI;

	const length container_1AA_ext_length   = 12.192_m; // (aka 40-foot standard)
	const length container_1AA_ext_height   =  2.591_m;
	const length container_1AA_ext_width    =  2.438_m;
	const mass container_1AA_max_gross_mass = 36'000_kg;
	// TODO

} // namespace ISO668
