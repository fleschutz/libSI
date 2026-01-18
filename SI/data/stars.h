// SI/data/stars.h - data of stars as of 2025
#pragma once

#include <SI/literals.h>

namespace SI { namespace data {

typedef struct {
	std::string name;
	SI::mass mass;
	SI::density mean_density;
	length mean_radius;
} star_data;

const star_data Sun = { "Sun", 1.9884e33_kg, 1.408_g_per_cm³, 695'700'000_m };

const star_data stars[] = {
	Sun
};

} } // SI::data

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/Sun
