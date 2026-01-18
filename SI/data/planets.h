// SI/data/planets.h - data of planets as of 2025
#pragma once

#include <SI/literals.h>

namespace SI { namespace data {

typedef struct {
	std::string name;
	SI::volume volume;
	SI::mass mass;
	SI::density density;
	SI::acceleration surface_gravity;
	SI::length equatorial_circumference;
	dimensionless population;
} planet_data;

//                             NAME      VOLUME            MASS           DENSITY         SURFACE GRAVITY   CIRCUMERENCE   POPULATION
const planet_data Mercury = { "Mercury", 0.0608272e12_km³, 0.33022e24_kg, 5.43_g_per_cm³, 3.7_m_per_s²,     0_km,          0,     };
const planet_data Venus   = { "Venus",   0.92840e12_km³,   4.86850e24_kg, 5.24_g_per_cm³, 8.872_m_per_s²,   0_km,          0,     };
const planet_data Earth   = { "Earth",   1.0832e12_km³,    5.97370e24_kg, 5.515_g_per_cm³,9.80665_m_per_s², 40075.0167_km, 8.2e9, };
const planet_data Mars    = { "Mars",    0.16314e12_km³,   0.64185e24_kg, 3.93_g_per_cm³, 3.72076_m_per_s², 0_km,          0,     };
const planet_data Jupiter = { "Jupiter", 1425.5e12_km³,    1898.70e24_kg, 1.33_g_per_cm³, 24.79_m_per_s²,   0_km,          0,     };
const planet_data Saturn  = { "Saturn",  827.13e12_km³,    568.510e24_kg, 0.7_g_per_cm³,  10.44_m_per_s²,   0_km,          0,     };
const planet_data Uranus  = { "Uranus",  69.142e12_km³,    86.849e24_kg,  1.3_g_per_cm³,  8.87_m_per_s²,    0_km,          0,     };
const planet_data Neptune = { "Neptune", 62.526e12_km³,    102.44e24_kg,  1.64_g_per_cm³, 11.15_m_per_s²,   0_km,          0,     };

} } // SI::data

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/List_of_gravitationally_rounded_objects_of_the_Solar_System
