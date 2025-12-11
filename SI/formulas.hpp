#pragma once

#include <cmath>
#include "types.hpp"

namespace si
{
	namespace formula
	{
		// Calculates the hypotenuse in a right triangle, based on Pythagorean equation a² + b² = c² 
		si::length hypotenuse_in_triangle(si::length a, si::length b)
		{
			return sqrt(a*a + b*b);
		}

		// Calculates the kinetic energy of a non-rotating object of mass m traveling at speed v.
		si::energy kinetic_energy(si::mass m, si::speed v)
		{
			return 0.5 * m * v * v;
		}

		auto wavelength(si::speed v, si::frequency f)
		{
			return v / f;
		}

		auto Newtons_motion(si::length s0, si::speed v0, si::acceleration a, si::time t)
		{
			return s0 + v0 * t + .5 * a * t * t;
		}

		auto Lorentz_force(double q, speed v, double B)
		{
			return q * v * B;
		}

		si::time free_fall_time(si::height h, si::acceleration gravity)
		{
			return sqrt((2.0 * h) / gravity);
		}

		si::angle glide_path(si::length horizontal_distance, si::height vertical_change)
		{
			return atan2(horizontal_distance, vertical_change);
		}

		si::height vertical_height(si::angle glide_path, si::length horizontal_distance)
		{
			return horizontal_distance * tan(glide_path);
		}

		si::length distance_to_brake(si::speed current_speed, si::speed target_speed, si::acceleration deceleration)
		{
			return (current_speed * current_speed - target_speed * target_speed) / (2.0 * deceleration);
		}

		si::acceleration acceleration_for_distance(si::speed current_speed, si::speed target_speed, si::length distance)
		{
			return (target_speed * target_speed - current_speed * current_speed) / (2.0 * distance);
		}
	}
}
