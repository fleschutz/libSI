// SI/data/moons.h - data of moons as of 2025
#pragma once

#include <SI/literals.h>

namespace SI { namespace data {

typedef struct {
	std::string name;
	SI::mass mass;
	SI::volume volume;
	SI::length equatorial_radius;
	SI::length polar_radius;
	SI::length mean_radius;
	SI::dimensionless flattening;
	SI::length equatorial_circumference;
	SI::area surface_area;
	SI::acceleration surface_gravity;
	SI::velocity equatorial_rotation_velocity;
	SI::time day;
} moon_data;

const moon_data Moon = {
	"Moon",
	7.346e22_kg,
	2.1958e10_km³,
	1'738.1_km,
	1'736.0_km,
	1'737.4_km,
	0.0012,
	10'921_km,
	3.793e7_km²,
	1.622_m_per_s²,
   	4.627_m_per_s,
	708.7 * 60 * 60_s, 
};

const moon_data moons[] = { Moon };

} } // SI::data

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/Moon
