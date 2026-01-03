// SI/data/Moon.h - data of the Moon as of 2025
#pragma once

#include "../../SI/units.h"
#define SET(_name, _value, _unit) const auto _name = _unit(_value)

namespace SI { namespace Moon {

SET( equatorial_radius,              1'738.1, kilometer);
SET( polar_radius,                   1'736.0, kilometer);
SET( mean_radius,                    1'737.4, kilometer);
SET( mean_diameter,          mean_radius * 2, meter);
SET( flattening,                      0.0012, dimensionless);
SET( equatorial_circumference,        10'921, kilometer);
SET( surface_area,                   3.793e7, kilometer2);
SET( volume,                       2.1958e10, kilometer3);
SET( mass,                          7.346e22, kilogram);
SET( surface_gravity,                  1.622, meters_per_second2);
SET( equatorial_rotation_velocity,     4.627, meters_per_second);
SET( day,                    708.7 * 60 * 60, second); 
SET( human_population,                     0, dimensionless);

}	}
#undef SET

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/Moon
