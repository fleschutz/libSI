/// @file	SI/formulas.h
/// @brief	Defines 65 common formulas based on SI datatypes.
/// @details	Contains formulas for: 1. 2D, 2. 3D, 3. Moving Objects, 4. Vehicles, 5. Aircraft, 6. Gravitation, 7. Various, 8. References

#pragma once
#include <SI/constants.h>

namespace SI { namespace formula {

	// 1. Formulas for 2D
	// ------------------
	/// @brief Calculates the hypotenuse in a right triangle, based on Pythagorean equation: a² + b² = c² 
	inline length hypotenuse_of_triangle(length a, length b)
	{
		return sqrt(a*a + b*b);
	}

	/// @brief Calculates the angle in a right triangle from opposite (o) and hypotenuse (h).
	inline angle angle1_in_triangle(length o, length h)
	{
		return radians(asin(o / h));
	}

	/// @brief Calculates the angle in a right triangle from adjacent (a) and hypotenuse (h).
	inline angle angle2_in_triangle(length a, length h)
	{
		return radians(acos(a / h));
	}

	/// @brief Calculates the angle in a right triangle from adjacent (a) and opposite (o).
	inline angle angle3_in_triangle(length a, length o)
	{
		return radians(atan(o / a));
	}

	/// @brief Calculates the area of a triangle from base (b) and height (h).
	inline area area_of_triangle(length b, length h)
	{
		return 0.5 * b * h;
	}

	/// @brief Calculates the perimeter of a rectangle from length (l) and base (b).
	inline length perimeter_of_rectangle(length l, length b)
	{
		return 2. * (l + b);
	}

	/// @brief Calculates the area of a rectangle from length (l) and base (b).
	inline area area_of_rectangle(length l, length b)
	{
		return l * b;
	}

	/// @brief Calculates the perimeter of a square from length (a).
	inline length perimeter_of_square(length a)
	{
		return 4. * a;
	}

	/// @brief Calculates the area of a square from length (a).
	inline area area_of_square(length a)
	{
		return a * a;
	}

	/// @brief Calculates the area of a trapezoid from base 1 (b1), base 2 (b2) and height (h).
	inline area area_of_trapezoid(length b1, length b2, length h)
	{
		return 0.5 * (b1 + b2) * h;
	}

	/// @brief Calculates the circumference of a circle from radius (r).
	inline length circumference_of_circle(length r)
	{
		return constant::tau * r;
	}

	/// @brief Calculates the radius of a circle from circumference (c).
	inline length radius_of_circumference(length c)
	{
		return c / constant::tau;
	}

	/// @brief Calculates the area of a circle from radius (r).
	inline area area_of_circle(length r)
	{
		return constant::pi * r * r;
	}

	/// @brief Calculates approximately(!) the perimeter of an ellipse from length of semi-major axis (a) and length of semi-minor axis (b).
	inline length perimeter_of_ellipse(length a, length b)
	{
		return constant::pi * sqrt(2.0 * (square(a) + square(b)));
	}

	/// @brief Calculates the area of an ellipse from radius (a) and (b).
	inline area area_of_ellipse(length a, length b)
	{
		return constant::pi * a * b;
	}

	/// @brief Calculates the eccentricity of an ellipse from radius (a) and (b).
	inline dimensionless eccentricity_of_ellipse(length a, length b)
	{
		return std::sqrt(1.0 - (square(b) / square(a)));
	}

	/// @brief Calculates the latus rectum of an ellipse from radius (a) and (b).
	inline length latus_rectum_of_ellipse(length a, length b)
	{
		return 2.0 * square(b) / a;
	}

	/// @brief Calculates the shortest distance between two points in 2D.
	inline length distance(length x1, length y1, length x2, length y2)
	{
		const length dx = x2 - x1;
		const length dy = y2 - y1;
		return sqrt((dx * dx) + (dy * dy));
	}

	// 2. Formulas for 3D
	// ------------------
	/// @brief Calculates the area of a cube from length (a).
	inline area area_of_cube(length a)
	{
		return 6. * a * a;
	}

	/// @brief Calculates the volume of a cube from length (a).
	inline volume volume_of_cube(length a)
	{
		return a * a * a;
	}

	/// @brief Calculates the area of a cylinder from radius (r) and height (h).
	inline area area_of_cylinder(length r, length h)
	{
		return constant::tau * r * (r + h);
	}

	/// @brief Calculates the volume of a cylinder based on radius (r) and height (h).
	inline volume volume_of_cylinder(length r, length h)
	{
		return constant::pi * square(r) * h;
	}

	/// @brief Calculates the area of a cone from radius (r) and height (h).
	inline area area_of_cone(length r, length h)
	{
		return constant::pi * r * (r + h);
	}

	/// @brief Calculates the volume of a cone from radius (r) and height (h).
	inline volume volume_of_cone(length r, length h)
	{
		return (1./3.) * constant::pi * square(r) * h;
	}

	/// @brief Calculates the area of a sphere from radius (r).
	inline area area_of_sphere(length r)
	{
		return 4. * constant::pi * square(r);
	}

	/// @brief Calculates the volume of a sphere from radius (r).
	inline volume volume_of_sphere(length r)
	{
		return (4. / 3.) * constant::pi * r * r * r;
	}

	/// @brief Calculates the volume of a prism from base area (A) and height (h).
	inline volume volume_of_prism(area A, length h)
	{
		return A * h;
	}

	// 3. Formulas for Moving Objects
	// ------------------------------
	/// @brief Calculates the kinetic energy of a non-rotating object of mass (m) traveling at velocity (v).
	inline energy kinetic_energy(mass m, velocity v)
	{
		return 0.5 * m * square(v);
	}

	/// @brief Calculates the free fall time from the given height.
	inline time time_of_free_fall(length height, acceleration gravity)
	{
		return sqrt((2. * height) / gravity);
	}

	/// @brief Calculates the braking distance to brake from v0 to v1 with the given deceleration.
	inline length braking_distance(velocity v0, velocity v1, acceleration deceleration)
	{
		return (square(v0) - square(v1)) / (2.0 * deceleration);
	}

	/// @brief Calculates the acceleration necessary to accelerate from v0 to v1 within the given distance.
	inline acceleration acceleration_for_distance(velocity v0, velocity v1, length distance)
	{
		return (square(v1) - square(v0)) / (2.0 * distance);
	}

	/// @brief Calculates the final velocity based on initial velocity (i) with acceleration (a) for time (t).
	inline velocity final_velocity(velocity i, acceleration a, time t)
	{
		return i + a * t;
	}

	/// @brief Calculates the acceleration from change in velocity (delta_v) and time interval (delta_t).
	inline acceleration acceleration_of(velocity delta_v, time delta_t)
	{
		return delta_v / delta_t;
	}

	// 4. Formulas for Vehicles
	// ------------------------
	/// @brief Calculates the turning radius of wheeled vehicles.
	inline length turning_radius_of_vehicle(length wheelbase, angle steering_angle, length tire_width)
	{
		return wheelbase / sin(steering_angle) + tire_width / 2.0;
	}

	/// @brief Calculates the G-force when accelerating from v0 to v1 within the given time.
	inline dimensionless g_force_of_acceleration(velocity v0, velocity v1, time t)
	{
		return (v1 - v0) / (t * constant::Earth_gravity);
	}

	// 5. Formulas for Aircraft
	// ------------------------
	/// @brief Calculates the true airspeed (TAS).
	inline velocity true_airspeed(force lift_force, dimensionless lift_coefficient, area wing_surface, density air_density)
	{
		return sqrt((2.0 * lift_force) / (lift_coefficient * wing_surface * air_density));
	}

	/// @brief Calculates the lift force of an aircraft wing.
	inline force lift_force_of_wing(dimensionless lift_coefficient, area wing_surface, density air_density, velocity true_air_speed)
	{
		return 0.5 * air_density * square(true_air_speed) * wing_surface * lift_coefficient;
	}

	/// @brief Calculates the Mach number from velocity (v) of moving aircraft at altitude's speed of sound.
	inline dimensionless Mach_number(velocity v, velocity speed_of_sound)
	{
		return v / speed_of_sound;
	}

	/// @brief Calculates the glide path from horizontal distance (h) and vertical change (v).
	inline angle glide_path(length h, length v)
	{
		return atan2(v, h);
	}

	/// @brief Calculates the glide ratio from horizontal distance (h) and altitude lost (a).
	inline dimensionless glide_ratio(length h, length a)
	{
		return h / a;
	}

	/// @brief Calculates the vertical height for the given glide path and horizontal distance.
	inline length vertical_height(angle glide_path, length horizontal_distance)
	{
		return horizontal_distance * tan(glide_path);
	}

	/// @brief Calculates the climb rate for the given speed and climb angle.
	inline velocity climb_rate(velocity ground_speed, angle climb_angle)
	{
		return sin(climb_angle) * ground_speed;
	}

	/// @brief Calculates the turn radius at the given speed and bank angle.
	inline length turn_radius(velocity ground_speed, angle bank_angle)
	{
		return (ground_speed * ground_speed) / (constant::Earth_gravity * tan(bank_angle));
	}

	// 6. Formulas for Gravitation
	// ---------------------------
	/// @brief Calculates the gravitational potential energy of a mass (m) at height (h) based on gravity (e.g. on Earth).
	inline energy gravitational_potential_energy(mass m, length h, acceleration gravity)
	{
		return m * h * gravity;
	}

	/// @brief Calculates the attractive force between two bodies of masses (m1) and (m2) with distance (d) between their centres of mass.
	inline force gravitational_attractive_force(mass m1, mass m2, length d)
	{
		return (constant::G * m1 * m2) / square(d);
	}

	/// @brief Calculates the escape velocity from a Mass (M) of body (e.g. a planet) with radius of body (r).
	inline velocity gravitational_escape_velocity(mass M, length r)
	{
		return sqrt((2.0 * constant::G * M) / r);
	}

	/// @brief Calculates the flattening factor (f) of an astronomical object from radius to equator (Re) and radius to pole (Rp).
	inline dimensionless flattening_factor(length Re, length Rp)
	{
		return (Re - Rp) / Re;
	}

	/// @brief Calculates the theoretical local gravity at latitude (lat) and height above MSL (h).
	inline acceleration local_gravity(angle lat, length h)
	{
		auto IGF = 9.780327_m_per_s² * (1.0 + 0.0053024 * sin2(lat) - 0.0000058 * sin2(2.0 * lat)); // International Gravity Formula
		auto FAC = -3.086e-6_m_per_s² * meters(h); // Free Air Correction
		return IGF + FAC;
	}

	// 7. Various Formulas
	// -------------------
	/// @brief Calculates the wavelength from velocity (v) and frequency (f).
	inline length wavelength(velocity v, frequency f)
	{
		return v / f;
	}

	/// @brief Calculates the speed of sound in air based on temperature (T).
	inline velocity speed_of_sound_in_air(temperature T)
	{
		double adiabatic_index = 1.4; // for air
		auto M = 0.0289645_kg_per_mol; // molar mass of the gas
		return sqrt((adiabatic_index * constant::R * T) / M);
	}

	/// @brief Calculates the drag force based on mass density of the fluid (p), flow velocity (u), drag coefficient (cd) and reference area (A).
	inline force drag_in_fluid(density p, velocity u, dimensionless cd, area A)
	{
		return 0.5 * p * (u * u) * cd * A;
	}

	/// @brief Calculates the frequency of a chromatic music note.
	inline frequency frequency_of_chromatic_note(int note, int reference_note, frequency reference_frequency)
	{
		return std::pow(std::pow(2., 1. / 12.), note - reference_note) * reference_frequency;
	}

	inline auto Newtons_motion(length s0, velocity v0, acceleration a, time t)
	{
		return s0 + v0 * t + 0.5 * a * t * t;
	}

	/// @brief Calculates the Lorentz force.
	inline auto Lorentz_force(double q, velocity v, double B)
	{
		return q * v * B;
	}

	/// @brief Calculates the windchill temperature.
	inline temperature windchill_temperature(temperature air_temperature, velocity wind_speed)
	{
		auto air_celsius = celsius(air_temperature);
		return celsius(13.12 + 0.6215 * air_celsius
		  + (0.3965 * air_celsius - 11.37) * std::pow(wind_speed / 1_km_per_h, 0.16));
	}

	/// @brief Returns the temperature gradient per kilometer for the given geopotential altitude.
	inline temperature temperature_gradient(length altitude)
	{
		if (altitude <= 11_km)
			return -6.5_K;
		if (altitude <= 20_km)
			return 0_K;
		if (altitude <= 32_km)
			return 1_K;
		if (altitude <= 37_km)
			return 2.8_K;
		if (altitude <= 51_km)
			return 0_K;
		if (altitude <= 71_km)
			return -2.8_K;
		return -2_K;
	}

	/// @brief Calculates the density of dry air.
	inline density density_of_dry_air(pressure air_pressure, temperature air_temperature)
	{
		return air_pressure / (constant::R_dry_air * air_temperature);
	}

	/// @brief Calculates the density from mass (m) and volume (V).
	inline density density_of(mass m, volume V)
	{
		return m / V;
	}

	/// @brief Calculates the mass from density (p) and volume (V).
	inline mass mass_of(density p, volume V)
	{
		return p * V;
	}

	/// @brief Calculates the volume from mass (m) and density (p).
	inline volume volume_of(mass m, density p)
	{
		return m / p;
	}

	/// @brief Calculates the body-mass index (BMI).
	inline dimensionless BMI(mass weight, length height)
	{
		return (weight / square(height)) / 1_kg_per_m²;
	}

	/// @brief Calculates the consumed electrical power of a current (I) and potential (U).
	inline auto consumed_electrical_power(electric_current I, electric_potential U)
	{
		return I * U;
	}

	/// @brief Calculates the sound intensity of a sound source from a distance.
	inline auto sound_intensity(power power_of_sound_source, length distance_from_sound_source)
	{
		return power_of_sound_source / (4.0 * constant::pi * square(distance_from_sound_source));
	}

	/// @brief Calculates the max height of a bullet (without force of drag, wind, etc.), based on:
	///        initial launch velocity (v0), initial height (h), launch angle (a), and gravitation (g).
	inline length ballistic_max_height(velocity v0, length h, angle a, acceleration g)
	{
		return h + square(v0 * sin(a)) / (2.0 * g);
	}

	/// @brief Calculates the max range of a bullet (without force of drag, wind, etc.), based on:
	///        initial launch velocity (v0), initial height (h), launch angle (a), and gravitation (g).
	inline length ballistic_max_range(velocity v0, length h, angle a, acceleration g)
	{
		return ((v0 * sin(a) + sqrt(square(v0 * sin(a)) + 2.0 * g * h)) / g) * cos(a) * v0;
	}

	/// @brief Calculates the flight time of a bullet (without force of drag, wind, etc.), based on:
	///        initial launch velocity (v0), initial height (h), launch angle (a), and gravitation (g).
	inline time ballistic_travel_time(velocity v0, length h, angle a, acceleration g)
	{
		return (v0 * sin(a) + sqrt(square(v0 * sin(a)) + 2.0 * g * h)) / g;
	}

	/// @brief Calculates the amount of energy absorbed (E) from a source of radiation by some material per mass (m)
	inline specific_energy absorbed_dose(energy E, mass m)
	{
		return E / m;
	}

	// 8. References
	// -------------
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

} } // namespace SI::formula
