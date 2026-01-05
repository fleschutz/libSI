// SI/data/Mercury.h - data of planet Mercury as of 2025
#pragma once

#include "../../SI/units.h"
#define SET(_name, _value, _unit) const auto _name = _unit(_value ## L)

namespace SI { namespace Mercury {

SET( mean_radius,                2'439.7, kilometer);
SET( flattening,                  0.0009, dimensionless);
SET( surface_area,                7.48e7, kilometer2);
SET( volume,                    6.083e10, kilometer3);
SET( mass,                     3.3011e23, kilogram);
SET( surface_gravity,                3.7, meters_per_second2);
SET( equatorial_rotation_velocity, 3.026, meters_per_second);
SET( day,               4222.6 * 60 * 60, second); 
SET( natural_satellites,               0, dimensionless);
SET( human_population,                 0, dimensionless);

} } // SI::Mercury
#undef SET

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/Mercury_(planet)
