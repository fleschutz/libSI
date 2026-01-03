// SI/data/Sun.h - data of the Sun as of 2025
#pragma once

#include "../../SI/units.h"
#define SET(_name, _value, _unit) const auto _name = _unit(_value)

namespace SI { namespace Sun {

SET( equatorial_radius,        695'700'000, meter);
SET( equatorial_rotation_velocity,    1997, meters_per_second);
SET( equatorial_surface_gravity,       274, meters_per_second2);
SET( surface_area,                 6.09e12, meter2);
SET( diameter,               1'390'176'000, meter);
SET( radius,                  diameter / 2, meter);
SET( mass,                       1.9884e33, kilogram);
SET( mean_distance_from_Earth,    1.496e11, meter);
SET( flattening,                   0.00005, dimensionless);
SET( average_density,                1.408, grams_per_centimeter3);
SET( center_temperature,        15'700'000, kelvin);
SET( photosphere_temperature,        5'772, kelvin);
SET( corona_temperature,         5'000'000, kelvin);
SET( human_population,                   0, dimensionless); 

}	}
#undef SET

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/Sun
