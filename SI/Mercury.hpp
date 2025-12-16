// SI/Mercury.hpp - contains data of planet Mercury
#pragma once
#include "types.hpp"
#define CONST(_name, _value, _unit)  static constexpr auto _name = _unit(_value)

namespace si
{
	namespace Mercury // source: https://en.wikipedia.org/wiki/Mercury_(planet)
	{
CONST( mean_radius,                  2'439.7, kilometer);
CONST( flattening,                       0.0009, quantity);
CONST( surface_area,                7.48e7, kilometer2);
CONST( volume,                    6.083e10, kilometer3);
CONST( mass,                     3.3011e23, kilogram);
CONST( surface_gravity,                3.7, meters_per_second2);
CONST( equatorial_rotation_velocity,   3.026, meters_per_second);
CONST( satellites,                     0, quantity);
CONST( human_population,               0, quantity); // as of 2025
	}
}

#undef CONST
