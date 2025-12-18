// SI/formulas.hpp - contains common formulas
#pragma once

#include <cmath>
#include "units.hpp"

namespace si
{
	namespace formula
	{

		length circumference(length radius)
		{
			return 2.0 * M_PI * radius;
		}

		length radius_of_circumference(length circumference)
		{
			return circumference / (2.0 * M_PI);
		}

		area area_in_circle(length radius)
		{
			return M_PI * radius * radius;
		}

		area area_of_ball(length radius)
		{
			return 2.0 * M_PI * radius * radius;
		}

		volume volume_of_ball(length radius)
		{
			return (4.0 / 3.0) * M_PI * radius * radius * radius;
		}

		// Returns the hypotenuse in a right triangle, based on Pythagorean equation a² + b² = c² 
		length hypotenuse_in_triangle(length a, length b)
		{
			return sqrt(a*a + b*b);
		}

		// Returns the kinetic energy of a non-rotating object of mass m traveling at speed v.
		energy kinetic_energy(mass m, speed v)
		{
			return 0.5 * m * v * v;
		}

		length wavelength(speed v, frequency f)
		{
			return v / f;
		}

		auto Newtons_motion(length s0, speed v0, acceleration a, time t)
		{
			return s0 + v0 * t + .5 * a * t * t;
		}

		auto Lorentz_force(double q, speed v, double B)
		{
			return q * v * B;
		}
#if 0
		auto Kepler(mass m, length a)
		{
			return 4 * constant::pi * constant::pi * a*a*a / (constant::Gravity_constant * m );
		}
#endif

		time free_fall_time(height h, acceleration gravity)
		{
			return sqrt((2.0 * h) / gravity);
		}

		angle glide_path(length horizontal_distance, height vertical_change)
		{
			return atan2(vertical_change, horizontal_distance);
		}

		height vertical_height(angle glide_path, length horizontal_distance)
		{
			return horizontal_distance * tan(glide_path);
		}

		length braking_distance(speed from_speed, speed to_speed, acceleration deceleration)
		{
			return (from_speed * from_speed - to_speed * to_speed) / (2.0 * deceleration);
		}

		acceleration acceleration_for_distance(speed current_speed, speed target_speed, length distance)
		{
			return (target_speed * target_speed - current_speed * current_speed) / (2.0 * distance);
		}

		// Calculates the body-mass-index
		auto BMI(mass weight, length height)
		{
			return weight / (height * height);
		}
	}
}
