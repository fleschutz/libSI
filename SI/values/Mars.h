// SI/values/Mars.h - type-safe values of planet Mars as of 2025
#pragma once

#include "../../SI/units.h"

namespace SI
{
	namespace Mars // source: https://en.wikipedia.org/wiki/Mars
	{
#define SET(_name, _value, _unit)   const auto _name = _unit(_value)
SET( equatorial_radius,        3'396.2, kilometer);
SET( polar_radius,             3'376.2, kilometer);
SET( surface_area,            1.4437e8, kilometer2);
SET( volume,                1.63118e11, kilometer3);
SET( mass,                   6.4171e23, kilogram);
SET( surface_gravity,          3.72075, meters_per_second2);
SET( equatorial_rotation_velocity, 241, meters_per_second);
SET( satellites,                     2, quantity); // Phobos and Deimos
SET( human_population,               0, quantity); 
//...

#undef SET
	}
}

