// <SI/formulas.h> - 61 common formulas based on type-safe SI datatypes, e.g. SI::formula::wavelength()
//                   (sorted by: 2D, 3D, moving objects, vehicles, aircrafts, gravitation, various)
#pragma once
#include <SI/constants.h>

namespace SI { namespace formula {

// +++ 2D +++

// Calculates the hypotenuse in a right triangle, based on Pythagorean equation: a² + b² = c² 
length hypotenuse_of_triangle(length a, length b)
{
	return sqrt(a*a + b*b);
}

// Calculates the angle in a right triangle from opposite (o) and hypotenuse (h).
angle angle1_in_triangle(length o, length h)
{
	return radians(asin(o / h));
}

// Calculates the angle in a right triangle from adjacent (a) and hypotenuse (h).
angle angle2_in_triangle(length a, length h)
{
	return radians(acos(a / h));
}

// Calculates the angle in a right triangle from adjacent (a) and opposite (o).
angle angle3_in_triangle(length a, length o)
{
	return radians(atan(o / a));
}

// Calculates the area of a triangle from base (b) and height (h).
area area_of_triangle(length b, length h)
{
	return 0.5 * b * h;
}

// Calculates the perimeter of a rectangle from length (l) and base (b).
length perimeter_of_rectangle(length l, length b)
{
	return 2. * (l + b);
}

// Calculates the area of a rectangle from length (l) and base (b).
area area_of_rectangle(length l, length b)
{
	return l * b;
}

// Calculates the perimeter of a square from length (a).
length perimeter_of_square(length a)
{
	return 4. * a;
}

// Calculates the area of a square from length (a).
area area_of_square(length a)
{
	return a * a;
}

// Calculates the area of a trapezoid from base 1 (b1), base 2 (b2) and height (h).
area area_of_trapezoid(length b1, length b2, length h)
{
	return 0.5 * (b1 + b2) * h;
}

// Calculates the circumference of a circle from radius (r).
length circumference_of_circle(length r)
{
	return constant::tau * r;
}

// Calculates the radius of a circle from circumference (c).
length radius_of_circumference(length c)
{
	return c / constant::tau;
}

// Calculates the area of a circle from radius (r).
area area_of_circle(length r)
{
	return constant::pi * r * r;
}

// Calculates approximately(!) the perimeter of an ellipse from length of semi-major axis (a) and length of semi-minor axis (b).
length perimeter_of_ellipse(length a, length b)
{
	return constant::pi * sqrt(2.0 * (square(a) + square(b)));
}

// Calculates the area of an ellipse from radius (a) and (b).
area area_of_ellipse(length a, length b)
{
	return constant::pi * a * b;
}

// Calculates the eccentricity of an ellipse from radius (a) and (b).
dimensionless eccentricity_of_ellipse(length a, length b)
{
	return std::sqrt(1.0 - (square(b) / square(a)));
}

// Calculates the latus rectum of an ellipse from radius (a) and (b).
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

// Calculates the area of a cube from length (a).
area area_of_cube(length a)
{
	return 6. * a * a;
}

// Calculates the volume of a cube from length (a).
volume volume_of_cube(length a)
{
	return a * a * a;
}

// Calculates the area of a cylinder from radius (r) and height (h).
area area_of_cylinder(length r, length h)
{
	return constant::tau * r * (r + h);
}

// Calculates the volume of a cylinder based on radius (r) and height (h).
volume volume_of_cylinder(length r, length h)
{
	return constant::pi * square(r) * h;
}

// Calculates the area of a cone from radius (r) and height (h).
area area_of_cone(length r, length h)
{
	return constant::pi * r * (r + h);
}

// Calculates the volume of a cone from radius (r) and height (h).
volume volume_of_cone(length r, length h)
{
	return (1./3.) * constant::pi * square(r) * h;
}

// Calculates the area of a sphere from radius (r).
area area_of_sphere(length r)
{
	return 4. * constant::pi * square(r);
}

// Calculates the volume of a sphere from radius (r).
volume volume_of_sphere(length r)
{
	return (4. / 3.) * constant::pi * r * r * r;
}

// Calculates the volume of a prism from base area (A) and height (h).
volume volume_of_prism(area A, length h)
{
	return A * h;
}

// +++ MOVING OBJECTS +++

// Calculates the kinetic energy of a non-rotating object of mass (m) traveling at velocity (v).
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

// Calculate the Mach number from velocity (v) of moving aircraft at altitude's speed of sound.
dimensionless Mach_number(velocity v, velocity speed_of_sound)
{
	return v / speed_of_sound;
}

// Calculate the glide path from horizontal distance (h) and vertical change (v).
angle glide_path(length h, length v)
{
	return atan2(v, h);
}

length vertical_height(angle glide_path, length horizontal_distance)
{
	return horizontal_distance * tan(glide_path);
}

velocity climb_rate(velocity ground_speed, angle climb_angle)
{
	return sin(climb_angle) * ground_speed;
}

// +++ GRAVITATION +++

// Calculates the gravitational potential energy of a mass (m) at height (h) based on gravity (e.g. on Earth).
energy gravitational_potential_energy(mass m, length h, acceleration gravity)
{
	return m * h * gravity;
}

// Calculates the attractive force between two bodies of masses (m1) and (m2) with distance (d) between their centres of mass.
force gravitational_attractive_force(mass m1, mass m2, length d)
{
	return (constant::G * m1 * m2) / square(d);
}

// Calculates the escape velocity from a Mass (M) of body (e.g. a planet) with radius of body (r).
velocity gravitational_escape_velocity(mass M, length r)
{
	return sqrt((2.0 * constant::G * M) / r);
}

// Calculates the flattening factor (f) of an astronomical object from radius to equator (Re) and radius to pole (Rp).
dimensionless flattening_factor(length Re, length Rp)
{
	return (Re - Rp) / Re;
}

// Calculates the theoretical local gravity at latitude (lat) and height above MSL (h).
acceleration local_gravity(angle lat, length h)
{
	auto IGF = 9.780327_m_per_s² * (1.0 + 0.0053024 * sin2(lat) - 0.0000058 * sin2(2.0 * lat)); // International Gravity Formula
	auto FAC = -3.086e-6_m_per_s² * meters(h); // Free Air Correction
	return IGF + FAC;
}

// +++ VARIOUS FORMULAS +++

// Calculates the wavelength from velocity (v) and frequency (f).
length wavelength(velocity v, frequency f)
{
	return v / f;
}

// Calculates the speed of sound in air based on temperature (T).
velocity speed_of_sound_in_air(temperature T)
{
	double adiabatic_index = 1.4; // for air
	auto M = 0.0289645_kg_per_mol; // molar mass of the gas
	return sqrt((adiabatic_index * constant::R * T) / M);
}

// Calculates the drag force based on mass density of the fluid (p), flow velocity (u), drag coefficient (cd) and reference area (A).
force drag_in_fluid(density p, velocity u, dimensionless cd, area A)
{
	return 0.5 * p * (u * u) * cd * A;
}

frequency frequency_of_chromatic_note(int note, int reference_note, frequency reference_frequency)
{
	return std::pow(std::pow(2., 1. / 12.), note - reference_note) * reference_frequency;
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

// Calculates the density from mass (m) and volume (V).
density density_of(mass m, volume V)
{
	return m / V;
}

// Calculates the mass from density (p) and volume (V).
mass mass_of(density p, volume V)
{
	return p * V;
}

// Calculates the volume from mass (m) and density (p).
volume volume_of(mass m, density p)
{
	return m / p;
}

// Calculates the body-mass index (BMI).
dimensionless BMI(mass weight, length height)
{
	return (weight / square(height)) / 1_kg_per_m²;
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

// Calculates the amount of energy absorbed (E) from a source of radiation by some material per mass (m)
specific_energy absorbed_dose(energy E, mass m)
{
	return E / m;
}

} } // namespace SI::formula

// References
// ----------
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
