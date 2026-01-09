// SI/data/planets.h - data of planets as of 2025
#pragma once

#include "../../SI/literals.h"

namespace SI { namespace data {

typedef struct {
	std::string name;
	SI::mass mass;
} planet_data;

const planet_data Mercury = { "Mercury", 0_kg };
const planet_data Venus = { "Venus", 0_kg };
const planet_data Earth = { "Earth", 0_kg };
const planet_data Mars = { "Mars", 6.4171e23_kg };
const planet_data Jupiter = { "Jupiter", 0_kg };
const planet_data Saturn = { "Saturn", 0_kg };
const planet_data Uranus = { "Uranus", 0_kg };
const planet_data Neptune = { "Neptune", 0_kg };

const planet_data planets[] = {
	Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune
};

} } // SI::data

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/Mars
