// SI/formulas.h - type-safe formulas based on SI units
#pragma once

#include <cmath>
#include "constants.h"

namespace SI
{
	namespace formula
	{
		// 2D FORMULAS:

		// Returns the hypotenuse in a right triangle, based on Pythagorean equation: a² + b² = c² 
		length hypotenuse_of_triangle(length a, length b)
		{
			return sqrt(a*a + b*b);
		}

		// Returns the angle in a right triangle, based on opposite and hypotenuse.
		angle angle1_in_triangle(length opposite, length hypotenuse)
		{
			return radian(asin(opposite / hypotenuse));
		}

		// Returns the angle in a right triangle, based on adjacent and hypotenuse.
		angle angle2_in_triangle(length adjacent, length hypotenuse)
		{
			return radian(acos(adjacent / hypotenuse));
		}

		// Returns the angle in a right triangle, based on adjacent and opposite.
		angle angle3_in_triangle(length adjacent, length opposite)
		{
			return radian(atan(opposite / adjacent));
		}

		area area_of_triangle(length base, length height)
		{
			return 0.5 * base * height;
		}

		length perimeter_of_rectangle(length l, length b)
		{
			return 2. * (l + b);
		}

		area area_of_rectangle(length l, length b)
		{
			return l * b;
		}

		length perimeter_of_square(length a)
		{
			return 4. * a;
		}

		area area_of_square(length a)
		{
			return a * a;
		}

		area area_of_trapezoid(length b1, length b2, length h)
		{
			return 0.5 * (b1 + b2) * h;
		}

		length circumference_of_circle(length radius)
		{
			return 2. * constant::pi * radius;
		}

		length radius_of_circumference(length circumference)
		{
			return circumference / (2. * constant::pi);
		}

		area area_of_circle(length radius)
		{
			return constant::pi * radius * radius;
		}

		// Returns the shortest distance between two points in 2D.
		length distance(length x1, length y1, length x2, length y2)
		{
			const length dx = x2 - x1;
			const length dy = y2 - y1;
			return sqrt((dx * dx) + (dy * dy));
		}

		// 3D FORMULAS:

		area area_of_cube(length a)
		{
			return 6. * a * a;
		}

		volume volume_of_cube(length a)
		{
			return a * a * a;
		}

		area area_of_cylinder(length radius, length height)
		{
			return 2. * constant::pi * radius * (radius + height);
		}

		volume volume_of_cylinder(length radius, length height)
		{
			return constant::pi * radius * radius * height;
		}

		area area_of_cone(length radius, length height)
		{
			return constant::pi * radius * (radius + height);
		}

		volume volume_of_cone(length radius, length height)
		{
			return (1./3.) * constant::pi * radius * radius * height;
		}

		area area_of_sphere(length radius)
		{
			return 4. * constant::pi * radius * radius;
		}

		volume volume_of_sphere(length radius)
		{
			return (4. / 3.) * constant::pi * radius * radius * radius;
		}

		volume volume_of_prism(area base_area, length height)
		{
			return base_area * height;
		}

		// VARIOUS FORMULAS:

		// Returns the kinetic energy of a non-rotating object of mass m traveling at velocity v.
		energy kinetic_energy(mass m, velocity v)
		{
			return 0.5 * m * v * v;
		}

		length wavelength(velocity v, frequency f)
		{
			return v / f;
		}

		auto Newtons_motion(length s0, velocity v0, acceleration a, time t)
		{
			return s0 + v0 * t + 0.5 * a * t * t;
		}

		auto Lorentz_force(double q, velocity v, double B)
		{
			return q * v * B;
		}

		time time_of_free_fall(length height, acceleration gravity)
		{
			return sqrt((2. * height) / gravity);
		}

		angle glide_path(length horizontal_distance, length vertical_change)
		{
			return atan2(vertical_change, horizontal_distance);
		}

		length vertical_height(angle glide_path, length horizontal_distance)
		{
			return horizontal_distance * tan(glide_path);
		}

		length braking_distance(velocity from_speed, velocity to_speed, acceleration deceleration)
		{
			return (from_speed * from_speed - to_speed * to_speed) / (.0 * deceleration);
		}

		acceleration acceleration_for_distance(velocity current_speed, velocity target_speed, length distance)
		{
			return (target_speed * target_speed - current_speed * current_speed) / (2. * distance);
		}

		// Calculates the body-mass index (BMI).
		auto BMI(mass weight, length height)
		{
			return weight / (height * height);
		}

		// Returns the windchill temperature (see: https://de.wikipedia.org/wiki/Windchill)
		temperature windchill_temperature(temperature air_temp, velocity wind_speed)
		{
			auto air_celsius = celsius(air_temp);
			return celsius(13.12 + 0.6215 * air_celsius
			  + (0.3965 * air_celsius - 11.37) * std::pow(wind_speed / 1_km_per_h, 0.16));
		}
	}
}
