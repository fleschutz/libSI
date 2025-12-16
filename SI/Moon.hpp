// SI/Moon.hpp - contains data of the Moon
#pragma once
#include "types.hpp"
#define CONST(_name, _value, _unit)  static constexpr auto _name = _unit(_value)

namespace si
{
	namespace Moon // source: https://en.wikipedia.org/wiki/Moon
	{
CONST( equatorial_radius,            1'738.1, kilometer);
CONST( polar_radius,                 1'736.0, kilometer);
CONST( mean_radius,                  1'737.4, kilometer);
CONST( mean_diameter,      mean_radius * 2, meter);
CONST( flattening,                       0.0012, quantity);
CONST( equatorial_circumference,    10'921, kilometer);
CONST( surface_area,               3.793e7, kilometer2);
CONST( volume,                   2.1958e10, kilometer3);
CONST( mass,                      7.346e22, kilogram);
CONST( surface_gravity,              1.622, meters_per_second2);
CONST( equatorial_rotation_velocity, 4.627, meters_per_second);
CONST( human_population,             0, quantity); // as of 2025
	}
}

#undef CONST
