// <SI/formulas.h> - 52 common formulas based on type-safe SI units, e.g. SI::formula::wavelength()
//                   (sorted by 2D, 3D, moving objects, vehicles, aircrafts, various)
#pragma once

#include <SI/constants.h>

namespace SI { namespace formula {

// +++ 2D +++
// Calculates the hypotenuse in a right triangle, based on Pythagorean equation: a² + b² = c² 
length hypotenuse_of_triangle(length a, length b)
{
	return sqrt(a*a + b*b);
}

// Calculates the angle in a right triangle, based on opposite and hypotenuse.
angle angle1_in_triangle(length opposite, length hypotenuse)
{
	return radians(asin(opposite / hypotenuse));
}

// Calculates the angle in a right triangle, based on adjacent and hypotenuse.
angle angle2_in_triangle(length adjacent, length hypotenuse)
{
	return radians(acos(adjacent / hypotenuse));
}

// Calculates the angle in a right triangle, based on adjacent and opposite.
angle angle3_in_triangle(length adjacent, length opposite)
{
	return radians(atan(opposite / adjacent));
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
	return 2.0 * constant::pi * radius;
}

length radius_of_circumference(length circumference)
{
	return circumference / (2.0 * constant::pi);
}

area area_of_circle(length radius)
{
	return constant::pi * radius * radius;
}

// Calculates approximately(!) the perimeter of an ellipse, a=length of semi-major axis, b=length of semi-minor axis
length perimeter_of_ellipse(length a, length b)
{
	return constant::pi * sqrt(2.0 * (square(a) + square(b)));
}

area area_of_ellipse(length a, length b)
{
	return constant::pi * a * b;
}

dimensionless eccentricity_of_ellipse(length a, length b)
{
	return std::sqrt(1.0 - (square(b) / square(a)));
}

length latus_rectum_of_ellipse(length a, length b)
{
	return 2.0 * square(b) / a;
}

// Calculates the shortest distance between two points in 2D.
length distance(length x1, length y1, length x2, length y2)
{
	const length dx = x2 - x1;
	const length dy = y2 - y1;
	return sqrt((dx * dx) + (dy * dy));
}

// +++ 3D +++
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
	return constant::pi * square(radius) * height;
}

area area_of_cone(length radius, length height)
{
	return constant::pi * radius * (radius + height);
}

volume volume_of_cone(length radius, length height)
{
	return (1./3.) * constant::pi * square(radius) * height;
}

area area_of_sphere(length radius)
{
	return 4. * constant::pi * square(radius);
}

volume volume_of_sphere(length radius)
{
	return (4. / 3.) * constant::pi * radius * radius * radius;
}

volume volume_of_prism(area base_area, length height)
{
	return base_area * height;
}

// +++ MOVING OBJECTS +++
// Calculates the kinetic energy of a non-rotating object of mass m traveling at velocity v.
energy kinetic_energy(mass m, velocity v)
{
	return 0.5 * m * square(v);
}

time time_of_free_fall(length height, acceleration gravity)
{
	return sqrt((2. * height) / gravity);
}

// Calculates the braking distance to brake from v0 to v1 with the given deceleration.
length braking_distance(velocity v0, velocity v1, acceleration deceleration)
{
	return (square(v0) - square(v1)) / (2.0 * deceleration);
}

// Calculates the acceleration necessary to accelerate from v0 to v1 within the given distance.
acceleration acceleration_for_distance(velocity v0, velocity v1, length distance)
{
	return (square(v1) - square(v0)) / (2.0 * distance);
}

// Calculates the final velocity based on initial velocity (i) with acceleration (a) for time (t).
velocity final_velocity(velocity i, acceleration a, time t)
{
	return i + a * t;
}

// Calculate the acceleration from change in velocity (delta_v) and time interval (delta_t).
acceleration acceleration_of(velocity delta_v, time delta_t)
{
	return delta_v / delta_t;
}

// +++ VEHICLES +++
// Calculates the turning radius of wheeled vehicles.
length turning_radius_of_vehicle(length wheelbase, angle steering_angle, length tire_width)
{
	return wheelbase / sin(steering_angle) + tire_width / 2.0;
}

// +++ AIRCRAFTS +++
// Calculates the true airspeed (TAS).
velocity true_airspeed(force lift_force, dimensionless lift_coefficient, area wing_surface, density air_density)
{
	return sqrt((2.0 * lift_force) / (lift_coefficient * wing_surface * air_density));
}

// Calculates the lift force of an aircraft wing.
force lift_force_of_wing(dimensionless lift_coefficient, area wing_surface, density air_density, velocity true_air_speed)
{
	return 0.5 * air_density * square(true_air_speed) * wing_surface * lift_coefficient;
}

angle glide_path(length horizontal_distance, length vertical_change)
{
	return atan2(vertical_change, horizontal_distance);
}

length vertical_height(angle glide_path, length horizontal_distance)
{
	return horizontal_distance * tan(glide_path);
}

velocity climb_rate(velocity ground_speed, angle climb_angle)
{
	return sin(climb_angle) * ground_speed;
}

// +++ VARIOUS FORMULAS +++
frequency frequency_of_chromatic_note(int note, int reference_note, frequency reference_frequency)
{
	return std::pow(std::pow(2., 1. / 12.), note - reference_note) * reference_frequency;
}

// Calculates the wavelength from velocity and frequency.
length wavelength(velocity v, frequency f)
{
	return v / f;
}

auto Newtons_motion(length s0, velocity v0, acceleration a, time t)
{
	return s0 + v0 * t + 0.5 * a * t * t;
}

// Calculates the Lorentz force.
auto Lorentz_force(double q, velocity v, double B)
{
	return q * v * B;
}

// Calculates the windchill temperature.
temperature windchill_temperature(temperature air_temperature, velocity wind_speed)
{
	auto air_celsius = celsius(air_temperature);
	return celsius(13.12 + 0.6215 * air_celsius
	  + (0.3965 * air_celsius - 11.37) * std::pow(wind_speed / 1_km_per_h, 0.16));
}

// Calculates the density of dry air.
density density_of_dry_air(pressure air_pressure, temperature air_temperature)
{
	return air_pressure / (constant::R_dry_air * air_temperature);
}

// Calculates the body-mass index (BMI).
auto BMI(mass weight, length height)
{
	return weight / square(height);
}

auto consumed_electrical_power(electric_current I, electric_potential U)
{
	return I * U;
}

auto sound_intensity(power power_of_sound_source, length distance_from_sound_source)
{
	return power_of_sound_source / (4.0 * constant::pi * square(distance_from_sound_source));
}

// Calculates the max height of a bullet (without force of drag, wind, etc.), based on:
// initial launch velocity (v0), initial height (h), launch angle (a), and gravitation (g).
length ballistic_max_height(velocity v0, length h, angle a, acceleration g)
{
	return h + square(v0 * sin(a)) / (2.0 * g);
}

// Calculates the max range of a bullet (without force of drag, wind, etc.), based on:
// initial launch velocity (v0), initial height (h), launch angle (a), and gravitation (g).
length ballistic_max_range(velocity v0, length h, angle a, acceleration g)
{
	return ((v0 * sin(a) + sqrt(square(v0 * sin(a)) + 2.0 * g * h)) / g) * cos(a) * v0;
}

// Calculates the flight time of a bullet (without force of drag, wind, etc.), based on:
// initial launch velocity (v0), initial height (h), launch angle (a), and gravitation (g).
time ballistic_travel_time(velocity v0, length h, angle a, acceleration g)
{
	return (v0 * sin(a) + sqrt(square(v0 * sin(a)) + 2.0 * g * h)) / g;
}

// Calculates the escape velocity from a Mass (M) of body (e.g. a planet) with radius of body (r).
velocity gravitational_escape_velocity(mass M, length r)
{
	return sqrt((2.0 * constant::G * M) / r);
}

// Calculates the amount of energy absorbed (E) from a source of radiation by some material per mass (m)
specific_energy absorbed_dose(energy E, mass m)
{
	return E / m;
}

} } // namespace SI::formula

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/Turning_radius
// 2. https://en.wikipedia.org/wiki/Lift_(force)
// 3. https://en.wikipedia.org/wiki/Wavelength
// 4. https://en.wikipedia.org/wiki/Lorentz_force
// 5. https://de.wikipedia.org/wiki/Windchill
// 6. https://en.wikipedia.org/wiki/Density_of_air
// 7. https://physics.info/equations/
// 8. https://www.vcalc.com/wiki/ballistic-max-height
// 9. https://www.vcalc.com/wiki/ballistic-range
// 10. https://www.vcalc.com/wiki/ballistic-travel-time
