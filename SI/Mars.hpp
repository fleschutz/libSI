// SI/Mars.hpp - contains data of planet Mars
#pragma once
#include "types.hpp"
#define CONST(_name, _value, _unit)  static constexpr auto _name = _unit(_value)

namespace si
{
	namespace Mars // source: https://en.wikipedia.org/wiki/Mars
	{
CONST( equatorial_radius,          3'396.2, kilometer);
CONST( polar_radius,               3'376.2, kilometer);
CONST( surface_area,            1.4437e8, kilometer2);
CONST( volume,                1.63118e11, kilometer3);
CONST( mass,                   6.4171e23, kg);
CONST( surface_gravity,                3.72075, meters_per_second2);
CONST( equatorial_rotation_velocity, 241, meters_per_second);
CONST( satellites,                     2, quantity); // Phobos and Deimos
CONST( human_population,               0, quantity); // as of 2025
	}
}

#undef CONST
