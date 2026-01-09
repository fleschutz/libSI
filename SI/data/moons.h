// SI/data/moons.h - data of moons as of 2025
#pragma once

#include "../../SI/literals.h"

namespace SI { namespace data {

typedef struct {
	std::string name;
	SI::mass mass;
} moon_data;

const moon_data Moon = { "Moon", 0_kg };

const moon_data moons[] = { Moon };

} } // SI::data

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/Moon
