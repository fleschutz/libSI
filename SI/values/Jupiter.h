// SI/values/Jupiter.h - type-safe values of planet Jupiter as of 2025
#pragma once

#include "../../SI/units.h"

namespace si
{
	namespace Jupiter // source: https://en.wikipedia.org/wiki/Jupiter
	{
#define SET(_name, _value, _unit)  const auto _name = _unit(_value)
SET( equatorial_radius,            71'492, kilometer);
SET( polar_radius,                 66'854, kilometer);
SET( mean_radius,                  69'911, kilometer);
SET( flattening,                  0.06487, quantity);
SET( surface_area,              6.1469e10, kilometer2);
SET( volume,                    1.4313e15, kilometer3);
SET( mass,                      1.8982e27, kilogram);
SET( surface_gravity,               24.79, meters_per_second2);
SET( equatorial_rotation_velocity, 12'600, meters_per_second);
SET( satellites,                       97, quantity);
SET( human_population,                  0, quantity);
//...

#undef SET
	}
}

