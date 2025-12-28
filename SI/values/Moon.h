// SI/values/Moon.h - type-safe values of the Moon as of 2025
#pragma once

#include "../../SI/units.h"

namespace SI
{
	namespace Moon // source: https://en.wikipedia.org/wiki/Moon
	{
#define SET(_name, _value, _unit) const auto _name = _unit(_value)
SET( equatorial_radius,              1'738.1, kilometer);
SET( polar_radius,                   1'736.0, kilometer);
SET( mean_radius,                    1'737.4, kilometer);
SET( mean_diameter,          mean_radius * 2, meter);
SET( flattening,                      0.0012, quantity);
SET( equatorial_circumference,        10'921, kilometer);
SET( surface_area,                   3.793e7, kilometer2);
SET( volume,                       2.1958e10, kilometer3);
SET( mass,                          7.346e22, kilogram);
SET( surface_gravity,                  1.622, meters_per_second2);
SET( equatorial_rotation_velocity,     4.627, meters_per_second);
SET( human_population,                     0, quantity);
//...

#undef SET
	}
}

