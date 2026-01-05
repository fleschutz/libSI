// SI/data/Venus.h - data of planet Venus as of 2025
#pragma once

#include "../../SI/units.h"
#define SET(_name, _value, _unit) const auto _name = _unit(_value ## L)

namespace SI { namespace Venus {

SET( equatorial_radius,        3'396.2, kilometer);
SET( polar_radius,             3'376.2, kilometer);
SET( surface_area,            1.4437e8, kilometer2);
SET( volume,                1.63118e11, kilometer3);
SET( mass,                   6.4171e23, kilogram);
SET( surface_gravity,          3.72075, meters_per_second2);
SET( equatorial_rotation_velocity, 241, meters_per_second);
SET( day,               24.7 * 60 * 60, second); 
SET( natural_satellites,             0, dimensionless);
SET( human_population,               0, dimensionless); 

} } // SI::Venus
#undef SET

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/Venus
