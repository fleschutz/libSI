/// @file     SI/formulas.h
/// @brief    Provides 70 basic formulas based on SI datatypes, e.g. SI::formula::wavelength().
/// @details  Categories are: 2D, 3D, Moving Objects, Vehicles, Aircraft, Gravitation, Various, and References.

#pragma once
#include <SI/constants.h>
#define FUNC [[nodiscard]] inline

namespace SI { namespace formula {

	// 1. 2D Formulas
	// --------------
	/// @brief Calculates the hypotenuse in a right triangle, based on Pythagorean equation: a² + b² = c² 
	FUNC length hypotenuse_of_triangle(const length a, const length b)
	{
		return sqrt(a*a + b*b);
	}

	/// @brief Calculates the angle in a right triangle from opposite (o) and hypotenuse (h).
	FUNC angle angle1_in_triangle(const length o, const length h)
	{
		return radians(asin(o / h));
	}

	/// @brief Calculates the angle in a right triangle from adjacent (a) and hypotenuse (h).
	FUNC angle angle2_in_triangle(const length a, const length h)
	{
		return radians(acos(a / h));
	}

	/// @brief Calculates the angle in a right triangle from adjacent (a) and opposite (o).
	FUNC angle angle3_in_triangle(const length a, const length o)
	{
		return radians(atan(o / a));
	}

	/// @brief Calculates the area of a triangle from base (b) and height (h).
	FUNC area area_of_triangle(const length b, const length h)
	{
		return 0.5 * b * h;
	}

	/// @brief Calculates the perimeter of a rectangle from length (l) and base (b).
	FUNC length perimeter_of_rectangle(const length l, const length b)
	{
		return 2. * (l + b);
	}

	/// @brief Calculates the area of a rectangle from length (l) and base (b).
	FUNC area area_of_rectangle(const length l, const length b)
	{
		return l * b;
	}

	/// @brief Calculates the perimeter of a square from length (a).
	FUNC length perimeter_of_square(const length a)
	{
		return 4. * a;
	}

	/// @brief Calculates the area of a square from length (a).
	FUNC area area_of_square(const length a)
	{
		return a * a;
	}

	/// @brief Calculates the area of a trapezoid from base 1 (b1), base 2 (b2) and height (h).
	FUNC area area_of_trapezoid(const length b1, const length b2, const length h)
	{
		return 0.5 * (b1 + b2) * h;
	}

	/// @brief Calculates the circumference of a circle from radius (r).
	FUNC length circumference_of_circle(const length r)
	{
		return constant::tau * r;
	}

	/// @brief Calculates the radius of a circle from circumference (c).
	FUNC length radius_of_circumference(const length c)
	{
		return c / constant::tau;
	}

	/// @brief Calculates the area of a circle from radius (r).
	FUNC area area_of_circle(const length r)
	{
		return constant::pi * r * r;
	}

	/// @brief Calculates approximately(!) the perimeter of an ellipse from length of semi-major axis (a) and length of semi-minor axis (b).
	FUNC length perimeter_of_ellipse(const length a, const length b)
	{
		return constant::pi * sqrt(2.0 * (square(a) + square(b)));
	}

	/// @brief Calculates the area of an ellipse from radius (a) and (b).
	FUNC area area_of_ellipse(const length a, const length b)
	{
		return constant::pi * a * b;
	}

	/// @brief Calculates the eccentricity of an ellipse from radius (a) and (b).
	FUNC dimensionless eccentricity_of_ellipse(const length a, const length b)
	{
		return std::sqrt(1.0 - (square(b) / square(a)));
	}

	/// @brief Calculates the latus rectum of an ellipse from radius (a) and (b).
	FUNC length latus_rectum_of_ellipse(const length a, const length b)
	{
		return 2.0 * square(b) / a;
	}

	/// @brief Calculates the shortest distance between two points in 2D.
	FUNC length distance(const length x1, const length y1, const length x2, const length y2)
	{
		const length dx = x2 - x1;
		const length dy = y2 - y1;
		return sqrt((dx * dx) + (dy * dy));
	}

	// 2. 3D Formulas
	// --------------
	/// @brief Calculates the area of a cube from length (a).
	FUNC area area_of_cube(const length a)
	{
		return 6. * a * a;
	}

	/// @brief Calculates the volume of a cube from length (a).
	FUNC volume volume_of_cube(const length a)
	{
		return a * a * a;
	}

	/// @brief Calculates the area of a cylinder from radius (r) and height (h).
	FUNC area area_of_cylinder(const length r, const length h)
	{
		return constant::tau * r * (r + h);
	}

	/// @brief Calculates the volume of a cylinder based on radius (r) and height (h).
	FUNC volume volume_of_cylinder(const length r, const length h)
	{
		return constant::pi * square(r) * h;
	}

	/// @brief Calculates the area of a cone from radius (r) and height (h).
	FUNC area area_of_cone(const length r, const length h)
	{
		return constant::pi * r * (r + h);
	}

	/// @brief Calculates the volume of a cone from radius (r) and height (h).
	FUNC volume volume_of_cone(const length r, const length h)
	{
		return (1./3.) * constant::pi * square(r) * h;
	}

	/// @brief Calculates the area of a sphere from radius (r).
	FUNC area area_of_sphere(const length r)
	{
		return 4. * constant::pi * square(r);
	}

	/// @brief Calculates the volume of a sphere from radius (r).
	FUNC volume volume_of_sphere(const length r)
	{
		return (4. / 3.) * constant::pi * r * r * r;
	}

	/// @brief Calculates the volume of a prism from base area (A) and height (h).
	FUNC volume volume_of_prism(const area A, const length h)
	{
		return A * h;
	}

	// 3. Moving Objects
	// -----------------
	/// @brief Calculates the average speed from distance and duration.
	FUNC velocity average_speed(const length distance, const time duration)
	{
		return distance / duration;
	}

	/// @brief Calculates the kinetic energy of a non-rotating object of mass (m) traveling at velocity (v).
	FUNC energy kinetic_energy(const mass m, const velocity v)
	{
		return 0.5 * m * square(v);
	}

	/// @brief Calculates the free fall time from the given height.
	FUNC time time_of_free_fall(const length height, const acceleration gravity)
	{
		return sqrt((2. * height) / gravity);
	}

	/// @brief Calculates the braking distance to brake from v0 to v1 with the given deceleration.
	FUNC length braking_distance(const velocity v0, const velocity v1, const acceleration deceleration)
	{
		return (square(v0) - square(v1)) / (2.0 * deceleration);
	}

	/// @brief Calculates the acceleration necessary to accelerate from v0 to v1 within the given distance.
	FUNC acceleration acceleration_for_distance(const velocity v0, const velocity v1, const length distance)
	{
		return (square(v1) - square(v0)) / (2.0 * distance);
	}

	/// @brief Calculates the final velocity based on initial velocity (i) with acceleration (a) for time (t).
	FUNC velocity final_velocity(const velocity i, const acceleration a, const SI::time t)
	{
		return i + a * t;
	}

	/// @brief Calculates the acceleration from change in velocity (delta_v) and time interval (delta_t).
	FUNC acceleration acceleration_of(const velocity delta_v, const SI::time delta_t)
	{
		return delta_v / delta_t;
	}

	// 4. Formulas for Vehicles
	// ------------------------
	/// @brief Calculates the turning radius of wheeled vehicles.
	FUNC length turning_radius_of_vehicle(const length wheelbase, const angle steering_angle, const length tire_width)
	{
		return wheelbase / sin(steering_angle) + tire_width / 2.0;
	}

	/// @brief Calculates the G-force when accelerating from v0 to v1 within the given time.
	FUNC dimensionless g_force_of_acceleration(const velocity v0, const velocity v1, const time t)
	{
		return (v1 - v0) / (t * constant::Earth_gravity);
	}

	// 5. Formulas for Aircraft
	// ------------------------
	/// @brief Calculates the true airspeed (TAS).
	FUNC velocity true_airspeed(const force lift_force, const dimensionless lift_coefficient, const area wing_surface, const density air_density)
	{
		return sqrt((2.0 * lift_force) / (lift_coefficient * wing_surface * air_density));
	}

	/// @brief Calculates the lift force of an aircraft wing.
	FUNC force lift_force_of_wing(const dimensionless lift_coefficient, const area wing_surface, const density air_density, const velocity true_air_speed)
	{
		return 0.5 * air_density * square(true_air_speed) * wing_surface * lift_coefficient;
	}

	/// @brief Calculates the Mach number from velocity (v) of moving aircraft at altitude's speed of sound.
	FUNC dimensionless Mach_number(const velocity v, const velocity speed_of_sound)
	{
		return v / speed_of_sound;
	}

	/// @brief Calculates the glide path from horizontal distance (h) and vertical change (v).
	FUNC angle glide_path(const length h, const length v)
	{
		return atan2(v, h);
	}

	/// @brief Calculates the glide ratio from horizontal distance (h) and altitude lost (a).
	FUNC dimensionless glide_ratio(const length h, const length a)
	{
		return h / a;
	}

	/// @brief Calculates the vertical height for the given glide path and horizontal distance.
	FUNC length vertical_height(const angle glide_path, const length horizontal_distance)
	{
		return horizontal_distance * tan(glide_path);
	}

	/// @brief Calculates the climb rate for the given speed and climb angle.
	FUNC velocity climb_rate(const velocity ground_speed, const angle climb_angle)
	{
		return sin(climb_angle) * ground_speed;
	}

	/// @brief Calculates the turn radius at the given speed and bank angle.
	FUNC length turn_radius(const velocity ground_speed, const angle bank_angle)
	{
		return (ground_speed * ground_speed) / (constant::Earth_gravity * tan(bank_angle));
	}

	// 6. Formulas for Gravitation
	// ---------------------------
	/// @brief Calculates the gravitational potential energy of a mass (m) at height (h) based on gravity (e.g. on Earth).
	FUNC energy gravitational_potential_energy(const mass m, const length h, const acceleration gravity)
	{
		return m * h * gravity;
	}

	/// @brief Calculates the attractive force between two bodies of masses (m1) and (m2) with distance (d) between their centres of mass.
	FUNC force gravitational_attractive_force(const mass m1, const mass m2, const length d)
	{
		return (constant::G * m1 * m2) / square(d);
	}

	/// @brief Calculates the escape velocity from a Mass (M) of body (e.g. a planet) with radius of body (r).
	FUNC velocity gravitational_escape_velocity(const mass M, const length r)
	{
		return sqrt((2.0 * constant::G * M) / r);
	}

	/// @brief Calculates the flattening factor (f) of an astronomical object from radius to equator (Re) and radius to pole (Rp).
	FUNC dimensionless flattening_factor(const length Re, const length Rp)
	{
		return (Re - Rp) / Re;
	}

	/// @brief Calculates the theoretical local gravity at latitude (lat) and height above MSL (h).
	FUNC acceleration local_gravity(const angle lat, const length h)
	{
		auto IGF = 9.780327_m_per_s² * (1.0 + 0.0053024 * sin2(lat) - 0.0000058 * sin2(2.0 * lat)); // International Gravity Formula
		auto FAC = -3.086e-6_m_per_s² * meters(h); // Free Air Correction
		return IGF + FAC;
	}

	/// @brief Calculates the Schwarzschild radius (event horizon) of a black hole from it's mass (M).
	FUNC length Schwarzschild_radius(const mass M)
	{
		return (2.0 * constant::G * M) / square(constant::c);
	}

	// 7. Various Formulas
	// -------------------
	/// @brief Calculates the wavelength from velocity (v) and frequency (f).
	FUNC length wavelength(const velocity v, const frequency f)
	{
		return v / f;
	}

	/// @brief Calculates V(t) from peak voltage (V0), frequency (f), and time (t).
	FUNC electric_potential sine_wave(const electric_potential V0, const frequency f, const SI::time t)
	{
		return V0 * sin(constant::tau * f * t);
	}

	/// @brief Calculates the speed of sound in air based on temperature (T).
	FUNC velocity speed_of_sound_in_air(const temperature T)
	{
		double adiabatic_index = 1.4; // for air
		auto M = 0.0289645_kg_per_mol; // molar mass of the gas
		return sqrt((adiabatic_index * constant::R * T) / M);
	}

	/// @brief Calculates the drag force based on mass density of the fluid (p), flow velocity (u), drag coefficient (cd) and reference area (A).
	FUNC force drag_in_fluid(const density p, const velocity u, const dimensionless cd, const area A)
	{
		return 0.5 * p * (u * u) * cd * A;
	}

	/// @brief Calculates the frequency of a chromatic music note.
	FUNC frequency frequency_of_chromatic_note(const int note, const int reference_note, const frequency reference_frequency)
	{
		return std::pow(std::pow(2., 1. / 12.), note - reference_note) * reference_frequency;
	}

	FUNC auto Newtons_motion(const length s0, const velocity v0, const acceleration a, const time t)
	{
		return s0 + v0 * t + 0.5 * a * t * t;
	}

	/// @brief Calculates the Lorentz force.
	FUNC auto Lorentz_force(const double q, const velocity v, const double B)
	{
		return q * v * B;
	}

	/// @brief Calculates the windchill temperature.
	FUNC temperature windchill_temperature(const temperature air_temperature, const velocity wind_speed)
	{
		auto air_celsius = celsius(air_temperature);
		return celsius(13.12 + 0.6215 * air_celsius
		  + (0.3965 * air_celsius - 11.37) * std::pow(wind_speed / 1_km_per_h, 0.16));
	}

	/// @brief Returns the temperature gradient per kilometer for the given geopotential altitude.
	FUNC temperature temperature_gradient(const length altitude)
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
	FUNC density density_of_dry_air(const pressure air_pressure, const temperature air_temperature)
	{
		return air_pressure / (constant::R_dry_air * air_temperature);
	}

	/// @brief Calculates the density from mass (m) and volume (V).
	FUNC density density_of(const mass m, const volume V)
	{
		return m / V;
	}

	/// @brief Calculates the mass from density (p) and volume (V).
	FUNC mass mass_of(const density p, const volume V)
	{
		return p * V;
	}

	/// @brief Calculates the volume from mass (m) and density (p).
	FUNC volume volume_of(const mass m, const density p)
	{
		return m / p;
	}

	/// @brief Calculates the body-mass index (BMI).
	FUNC dimensionless BMI(const mass weight, const length height)
	{
		return (weight / square(height)) / 1_kg_per_m²;
	}

	/// @brief Calculates the consumed electrical power of a current (I) and potential (U).
	FUNC auto consumed_electrical_power(const electric_current I, const electric_potential U)
	{
		return I * U;
	}

	/// @brief Calculates the sound intensity of a sound source from a distance.
	FUNC auto sound_intensity(const power power_of_sound_source, const length distance_from_sound_source)
	{
		return power_of_sound_source / (4.0 * constant::pi * square(distance_from_sound_source));
	}

	/// @brief Calculates the max height of a bullet (without force of drag, wind, etc.), based on:
	///        initial launch velocity (v0), initial height (h), launch angle (a), and gravitation (g).
	FUNC length ballistic_max_height(const velocity v0, const length h, const angle a, const acceleration g)
	{
		return h + square(v0 * sin(a)) / (2.0 * g);
	}

	/// @brief Calculates the max range of a bullet (without force of drag, wind, etc.), based on:
	///        initial launch velocity (v0), initial height (h), launch angle (a), and gravitation (g).
	FUNC length ballistic_max_range(const velocity v0, const length h, const angle a, const acceleration g)
	{
		return ((v0 * sin(a) + sqrt(square(v0 * sin(a)) + 2.0 * g * h)) / g) * cos(a) * v0;
	}

	/// @brief Calculates the flight time of a bullet (without force of drag, wind, etc.), based on:
	///        initial launch velocity (v0), initial height (h), launch angle (a), and gravitation (g).
	FUNC time ballistic_travel_time(const velocity v0, const length h, const angle a, const acceleration g)
	{
		return (v0 * sin(a) + sqrt(square(v0 * sin(a)) + 2.0 * g * h)) / g;
	}

	/// @brief Calculates the amount of energy absorbed (E) from a source of radiation by some material per mass (m)
	FUNC specific_energy absorbed_dose(const energy E, const mass m)
	{
		return E / m;
	}

	// FUNC velocity min_of_array(velocity arr[], int n)
	// {
	//    if (n < 1)
        //	  return meters_per_second(0);
	//    velocity minimum = arr[0];
	//    for (int i = 1; i < n; ++i)
	//        if (arr[i] < minimum)
	//        	minimum = arr[i];
	//    return minimum;
	// }

	// FUNC velocity max_of_array(velocity arr[], int n)
	// {
	//    if (n < 1)
        //	  return meters_per_second(0);
	//    velocity maximum = arr[0];
	//    for (int i = 1; i < n; ++i)
	//        if (arr[i] > maximum)
	//        	maximum = arr[i];
	//    return maximum;
	// }

	// FUNC velocity avg_of_array(velocity arr[], int n)
	// {
	//    if (n < 1)
        //	  return meters_per_second(0);
	//    velocity sum = meters_per_second(0);
	//    for (int i = 0; i < n; ++i)
	//        sum += arr[i];
	//    return sum / n;
	// }

	// FUNC velocity sum_of_array(velocity arr[], int n)
	// {
	//    velocity sum = meters_per_second(0);
	//    for (int i = 0; i < n; ++i)
	//        sum += arr[i];
	//    return sum;
	// }

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
 
#undef FUNC
