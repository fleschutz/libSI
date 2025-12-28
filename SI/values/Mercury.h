// SI/values/Mercury.h - type-safe values of planet Mercury as of 2025
#pragma once

#include "../../SI/units.h"

namespace SI
{
	namespace Mercury // source: https://en.wikipedia.org/wiki/Mercury_(planet)
	{
#define SET(_name, _value, _unit) const auto _name = _unit(_value)
SET( mean_radius,                2'439.7, kilometer);
SET( flattening,                  0.0009, quantity);
SET( surface_area,                7.48e7, kilometer2);
SET( volume,                    6.083e10, kilometer3);
SET( mass,                     3.3011e23, kilogram);
SET( surface_gravity,                3.7, meters_per_second2);
SET( equatorial_rotation_velocity, 3.026, meters_per_second);
SET( satellites,                       0, quantity);
SET( human_population,                 0, quantity);
//...

#undef SET
	}
}

