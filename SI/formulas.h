/// @file     SI/formulas.h
/// @brief    Defines 77 formulas based on SI datatypes, e.g. SI::area_of_circle().
/// @details  Categories are: 2D, 3D, Moving Objects, Vehicle, Aircraft, Gravitation, Various, and References.

#pragma once
#include <SI/constants.h>
#define FUNC [[nodiscard]] inline

namespace SI { 

	// Formulas for 2D
	// ---------------
	/// @brief Calculates the hypotenuse in a right triangle, based on Pythagorean equation: a² + b² = c² 
	FUNC length hypotenuse_of_triangle_formula(length a, length b)
	{
		return sqrt(a*a + b*b);
	}

	/// @brief Calculates the angle in a right triangle from opposite (o) and hypotenuse (h).
	FUNC angle angle1_in_triangle_formula(length o, length h)
	{
		return radians(asin(o / h));
	}

	/// @brief Calculates the angle in a right triangle from adjacent (a) and hypotenuse (h).
	FUNC angle angle2_in_triangle_formula(length a, length h)
	{
		return radians(acos(a / h));
	}

	/// @brief Calculates the angle in a right triangle from adjacent (a) and opposite (o).
	FUNC angle angle3_in_triangle_formula(length a, length o)
	{
		return radians(atan(o / a));
	}

	/// @brief Calculates the area of a triangle from base (b) and height (h).
	FUNC area area_of_triangle_formula(length b, length h)
	{
		return 0.5 * b * h;
	}

	/// @brief Calculates the perimeter of a rectangle from length (l) and base (b).
	FUNC length perimeter_of_rectangle_formula(length l, length b)
	{
		return 2. * (l + b);
	}

	/// @brief Calculates the area of a rectangle from length (l) and base (b).
	FUNC area area_of_rectangle_formula(length l, length b)
	{
		return l * b;
	}

	/// @brief Calculates the perimeter of a square from length (a).
	FUNC length perimeter_of_square_formula(length a)
	{
		return 4. * a;
	}

	/// @brief Calculates the area of a square from length (a).
	FUNC area area_of_square_formula(length a)
	{
		return a * a;
	}

	/// @brief Calculates the area of a trapezoid from base 1 (b1), base 2 (b2) and height (h).
	FUNC area area_of_trapezoid_formula(length b1, length b2, length h)
	{
		return 0.5 * (b1 + b2) * h;
	}

	/// @brief Calculates the circumference of a circle from radius (r).
	FUNC length circumference_of_circle_formula(length r)
	{
		return Math.tau * r;
	}

	/// @brief Calculates the radius of a circle from circumference (c).
	FUNC length radius_of_circumference_formula(length c)
	{
		return c / Math.tau;
	}

	/// @brief Calculates the area of a circle from radius (r).
	FUNC area area_of_circle_formula(length r)
	{
		return Math.pi * r * r;
	}

	/// @brief Calculates approximately(!) the perimeter of an ellipse from length of semi-major axis (a) and length of semi-minor axis (b).
	FUNC length perimeter_of_ellipse_formula(length a, length b)
	{
		return Math.pi * sqrt(2.0 * (square(a) + square(b)));
	}

	/// @brief Calculates the area of an ellipse from radius (a) and (b).
	FUNC area area_of_ellipse_formula(length a, length b)
	{
		return Math.pi * a * b;
	}

	/// @brief Calculates the eccentricity of an ellipse from radius (a) and (b).
	FUNC dimensionless eccentricity_of_ellipse_formula(length a, length b)
	{
		return std::sqrt(1.0 - (square(b) / square(a)));
	}

	/// @brief Calculates the latus rectum of an ellipse from radius (a) and (b).
	FUNC length latus_rectum_of_ellipse_formula(length a, length b)
	{
		return 2.0 * square(b) / a;
	}

	/// @brief Calculates the shortest distance between two points in 2D.
	FUNC length distance_formula(length x1, length y1, length x2, length y2)
	{
		const length dx = x2 - x1;
		const length dy = y2 - y1;
		return sqrt((dx * dx) + (dy * dy));
	}

	// Formulas for 3D
	// ---------------
	/// @brief Calculates the area of a cube from length (a).
	FUNC area area_of_cube_formula(length a)
	{
		return 6. * a * a;
	}

	/// @brief Calculates the volume of a cube from length (a).
	FUNC volume volume_of_cube_formula(length a)
	{
		return a * a * a;
	}

	/// @brief Calculates the area of a cylinder from radius (r) and height (h).
	FUNC area area_of_cylinder_formula(length r, length h)
	{
		return Math.tau * r * (r + h);
	}

	/// @brief Calculates the volume of a cylinder based on radius (r) and height (h).
	FUNC volume volume_of_cylinder_formula(length r, length h)
	{
		return Math.pi * square(r) * h;
	}

	/// @brief Calculates the area of a cone from radius (r) and height (h).
	FUNC area area_of_cone_formula(length r, length h)
	{
		return Math.pi * r * (r + h);
	}

	/// @brief Calculates the volume of a cone from radius (r) and height (h).
	FUNC volume volume_of_cone_formula(length r, length h)
	{
		return (1./3.) * Math.pi * square(r) * h;
	}

	/// @brief Calculates the area of a sphere from radius (r).
	FUNC area area_of_sphere_formula(length r)
	{
		return 4. * Math.pi * square(r);
	}

	/// @brief Calculates the volume of a sphere from radius (r).
	FUNC volume volume_of_sphere_formula(length r)
	{
		return (4. / 3.) * Math.pi * r * r * r;
	}

	/// @brief Calculates the volume of a prism from base area (A) and height (h).
	FUNC volume volume_of_prism_formula(area A, length h)
	{
		return A * h;
	}

	/// @brief Calculates the distance between two lat/long coordinates on Earth (haversine formula).
	FUNC length distance_on_sphere_formula(angle lat1, angle long1, angle lat2, angle long2,
			                       length radius = 6371.0088_km) // mean Earth radius, recommended by NOAA
	{
		angle dLat = lat1 - lat2;    // difference in latitude
		angle dLong = long1 - long2; // difference in longitude

		angle a = sin2(dLat / 2.) + cos(lat1) * cos(lat2) * sin2(dLong / 2.); // Haversine intermediate
		auto  c = 2. * atan2(sqrt(a), sqrt(1. - a)); // central angle 

		return c * radius;
	}

	// Formulas for Moving Objects
	// ---------------------------
	/// @brief Calculates the average speed from distance and duration.
	FUNC velocity average_speed_formula(length distance, time duration)
	{
		return distance / duration;
	}

	/// @brief Calculates the kinetic energy of a non-rotating object of mass (m) traveling at velocity (v).
	FUNC energy kinetic_energy_formula(mass m, velocity v)
	{
		return 0.5 * m * square(v);
	}

	/// @brief Calculates the free fall time from the given height.
	FUNC time free_fall_time_formula(length height, acceleration gravity)
	{
		return sqrt((2. * height) / gravity);
	}

	/// @brief Calculates the braking distance to brake from v0 to v1 with the given deceleration.
	FUNC length braking_distance_formula(velocity v0, velocity v1, acceleration deceleration)
	{
		return (square(v0) - square(v1)) / (2.0 * deceleration);
	}

	/// @brief Calculates the acceleration necessary to accelerate from v0 to v1 within the given distance.
	FUNC acceleration acceleration_for_distance_formula(velocity v0, velocity v1, length distance)
	{
		return (square(v1) - square(v0)) / (2.0 * distance);
	}

	/// @brief Calculates the acceleration from change in velocity (delta_v) and time interval (delta_t).
	FUNC acceleration acceleration_for_speed_formula(velocity delta_v, SI::time delta_t)
	{
		return delta_v / delta_t;
	}

	/// @brief Calculates the final velocity based on initial velocity (i) with acceleration (a) for time (t).
	FUNC velocity final_velocity_formula(velocity i, acceleration a, SI::time t)
	{
		return i + a * t;
	}

	// Formulas for Vehicles
	// ---------------------
	/// @brief Calculates the revolutions per minute (RPM) from velocity (v) and wheel radius (r).
	FUNC dimensionless wheel_rpm_formula(velocity v, length r)
	{
		return v / (Math.tau * r) * 60_s;
	}

	/// @brief Calculates the wheel speed from wheel radius (r) and revolutions per minute (RPM).
	FUNC velocity wheel_speed_formula(length r, dimensionless RPM)
	{
		return Math.tau * r * (RPM / 60_s);
	}

	/// @brief Calculates the turning radius of wheeled vehicles.
	FUNC length turning_radius_of_vehicle_formula(length wheelbase, angle steering_angle, length tire_width)
	{
		return wheelbase / sin(steering_angle) + tire_width / 2.0;
	}

	/// @brief Calculates the G-force when accelerating from v0 to v1 within the given time.
	FUNC dimensionless acceleration_g_force_formula(velocity v0, velocity v1, time t)
	{
		return (v1 - v0) / (t * CODATA.g_n);
	}

	// Formulas for Aircraft
	// ---------------------
	/// @brief Calculates the true airspeed (TAS).
	FUNC velocity true_airspeed_formula(force lift_force, dimensionless lift_coefficient, area wing_surface, density air_density)
	{
		return sqrt((2.0 * lift_force) / (lift_coefficient * wing_surface * air_density));
	}

	/// @brief Calculates the lift force of an aircraft wing.
	FUNC force lift_force_of_wing_formula(dimensionless lift_coefficient, area wing_surface, density air_density, velocity true_air_speed)
	{
		return 0.5 * air_density * square(true_air_speed) * wing_surface * lift_coefficient;
	}

	/// @brief Calculates the Mach number from velocity (v) of moving aircraft at altitude's speed of sound.
	FUNC dimensionless Mach_number_formula(velocity v, velocity speed_of_sound)
	{
		return v / speed_of_sound;
	}

	/// @brief Calculates the glide path from horizontal distance (h) and vertical height change (v).
	FUNC angle glide_path_formula(length h, length v)
	{
		return atan2(v, h);
	}

	/// @brief Calculates the glide ratio from horizontal distance (h) and altitude lost (a).
	FUNC dimensionless glide_ratio_formula(length h, length a)
	{
		return h / a;
	}

	/// @brief Calculates the vertical height for the given glide path and horizontal distance.
	FUNC length vertical_height_formula(angle glide_path, length horizontal_distance)
	{
		return horizontal_distance * tan(glide_path);
	}

	/// @brief Calculates the climb rate for the given speed and climb angle.
	FUNC velocity climb_rate_formula(velocity ground_speed, angle climb_angle)
	{
		return sin(climb_angle) * ground_speed;
	}

	/// @brief Calculates the turn radius at the given speed and bank angle.
	FUNC length turn_radius_formula(velocity ground_speed, angle bank_angle)
	{
		return (ground_speed * ground_speed) / (CODATA.g_n * tan(bank_angle));
	}

	// Formulas for Gravitation
	// ------------------------
	/// @brief Calculates the gravitational potential energy of a mass (m) at height (h) based on gravity (e.g. on Earth).
	FUNC energy gravitational_potential_energy_formula(mass m, length h, acceleration gravity)
	{
		return m * h * gravity;
	}

	/// @brief Calculates the attractive force between two bodies of masses (m1) and (m2) with distance (d) between their centres of mass.
	FUNC force gravitational_attractive_force_formula(mass m1, mass m2, length d)
	{
		return (constant::G * m1 * m2) / square(d);
	}

	/// @brief Calculates the escape velocity from a Mass (M) of body (e.g. a planet) with radius of body (r).
	FUNC velocity gravitational_escape_velocity_formula(mass M, length r)
	{
		return sqrt((2.0 * constant::G * M) / r);
	}

	/// @brief Calculates the flattening factor (f) of an astronomical object from radius to equator (Re) and radius to pole (Rp).
	FUNC dimensionless flattening_factor_formula(length Re, length Rp)
	{
		return (Re - Rp) / Re;
	}

	/// @brief Calculates the theoretical local gravity at latitude (lat) and height above MSL (h).
	FUNC acceleration local_gravity_formula(angle lat, length h)
	{
		auto IGF = 9.780327_m_per_s² * (1.0 + 0.0053024 * sin2(lat) - 0.0000058 * sin2(2.0 * lat)); // International Gravity Formula
		auto FAC = -3.086e-6_m_per_s² * meters(h); // Free Air Correction
		return IGF + FAC;
	}

	/// @brief Calculates the Schwarzschild radius of a black hole from it's mass (M).
	FUNC length Schwarzschild_radius_formula(mass M)
	{
		return (2.0 * constant::G * M) / square(CODATA.c);
	}

	// Various Formulas
	// ----------------
	/// @brief Calculates the wavelength from velocity (v) and frequency (f).
	FUNC length wavelength_formula(velocity v, frequency f)
	{
		return v / f;
	}

	/// @brief Calculates V(t) from peak voltage (V0), frequency (f), and time (t).
	FUNC electric_potential sine_wave_formula(electric_potential V0, frequency f, SI::time t)
	{
		return V0 * sin(Math.tau * f * t);
	}

	/// @brief Calculates the speed of sound in air based on temperature (T).
	FUNC velocity speed_of_sound_in_air_formula(temperature T)
	{
		double adiabatic_index = 1.4; // for air
		auto M = 0.0289645_kg_per_mol; // molar mass of the gas
		return sqrt((adiabatic_index * constant::R * T) / M);
	}

	/// @brief Calculates the drag force based on mass density of the fluid (p), flow velocity (u), drag coefficient (cd) and reference area (A).
	FUNC force drag_in_fluid_formula(density p, velocity u, dimensionless cd, area A)
	{
		return 0.5 * p * (u * u) * cd * A;
	}

	/// @brief Calculates the frequency of a chromatic music note.
	FUNC frequency frequency_of_chromatic_note_formula(int note, int reference_note, frequency reference_frequency)
	{
		return std::pow(std::pow(2., 1. / 12.), note - reference_note) * reference_frequency;
	}

	FUNC auto Newtons_motion_formula(length s0, velocity v0, acceleration a, time t)
	{
		return s0 + v0 * t + 0.5 * a * t * t;
	}

	/// @brief Calculates the Lorentz force.
	FUNC auto Lorentz_force_formula(double q, velocity v, double B)
	{
		return q * v * B;
	}

	/// @brief Calculates the windchill temperature.
	FUNC temperature windchill_temperature_formula(temperature air_temperature, velocity wind_speed)
	{
		auto air_celsius = celsius(air_temperature);
		return celsius(13.12 + 0.6215 * air_celsius
		  + (0.3965 * air_celsius - 11.37) * std::pow(wind_speed / 1_km_per_h, 0.16));
	}

	/// @brief Returns the temperature gradient per kilometer for the given geopotential altitude.
	FUNC temperature temperature_gradient_formula(length altitude)
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
	FUNC density density_of_dry_air_formula(pressure air_pressure, temperature air_temperature)
	{
		return air_pressure / (constant::R_dry_air * air_temperature);
	}

	/// @brief Calculates the density from mass (m) and volume (V).
	FUNC density density_formula(mass m, volume V)
	{
		return m / V;
	}

	/// @brief Calculates the mass from density (p) and volume (V).
	FUNC mass mass_formula(density p, volume V)
	{
		return p * V;
	}

	/// @brief Calculates the volume from mass (m) and density (p).
	FUNC volume volume_formula(mass m, density p)
	{
		return m / p;
	}

	/// @brief Calculates the human body-mass index (BMI) from weight (w) and height (h).
	FUNC dimensionless BMI_formula(mass w, length h)
	{
		return (w / square(h)) / 1_kg_per_m²;
	}

	/// @brief Calculates the consumed electrical power of a current (I) and potential (U).
	FUNC auto consumed_electrical_power_formula(current I, electric_potential U)
	{
		return I * U;
	}

	/// @brief Calculates the sound intensity of a sound source from a distance.
	FUNC auto sound_intensity_formula(power power_of_sound_source, length distance_from_sound_source)
	{
		return power_of_sound_source / (4.0 * Math.pi * square(distance_from_sound_source));
	}

	/// @brief Calculates the max height of a bullet (without force of drag, wind, etc.), based on:
	///        initial launch velocity (v0), initial height (h), launch angle (a), and gravitation (g).
	FUNC length ballistic_max_height_formula(velocity v0, length h, angle a, acceleration g)
	{
		return h + square(v0 * sin(a)) / (2.0 * g);
	}

	/// @brief Calculates the max range of a bullet (without force of drag, wind, etc.), based on:
	///        initial launch velocity (v0), initial height (h), launch angle (a), and gravitation (g).
	FUNC length ballistic_max_range_formula(velocity v0, length h, angle a, acceleration g)
	{
		return ((v0 * sin(a) + sqrt(square(v0 * sin(a)) + 2.0 * g * h)) / g) * cos(a) * v0;
	}

	/// @brief Calculates the flight time of a bullet (without force of drag, wind, etc.), based on:
	///        initial launch velocity (v0), initial height (h), launch angle (a), and gravitation (g).
	FUNC time ballistic_travel_time_formula(velocity v0, length h, angle a, acceleration g)
	{
		return (v0 * sin(a) + sqrt(square(v0 * sin(a)) + 2.0 * g * h)) / g;
	}

	/// @brief Calculates the amount of energy absorbed (E) from a source of radiation by some material per mass (m)
	FUNC specific_energy absorbed_dose_formula(energy E, mass m)
	{
		return E / m;
	}

	/// @brief Returns the minimum velocity in the given array.
	FUNC velocity min_of_array(velocity arr[], int n)
	{
		if (n < 1)
			return meters_per_second(0);
		velocity minimum = arr[0];
		for (int i = 1; i < n; ++i)
			if (arr[i] < minimum)
				minimum = arr[i];
		return minimum;
	}

	/// @brief Returns the maximum velocity in the given array.
	FUNC velocity max_of_array(velocity arr[], int n)
	{
		if (n < 1)
			return meters_per_second(0);
		velocity maximum = arr[0];
		for (int i = 1; i < n; ++i)
			if (arr[i] > maximum)
				maximum = arr[i];
		return maximum;
	}

	/// @brief Returns the average velocity in the given array.
	FUNC velocity avg_of_array(velocity arr[], int n)
	{
		if (n < 1)
			return meters_per_second(0);
		velocity sum = meters_per_second(0);
		for (int i = 0; i < n; ++i)
			sum += arr[i];
		return sum / n;
	}

	/// @brief Returns the sum of all velocities in the given array.
	FUNC velocity sum_of_array(velocity arr[], int n)
	{
		velocity sum = meters_per_second(0);
		for (int i = 0; i < n; ++i)
			sum += arr[i];
		return sum;
	}

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
	// 11. https://best-calculators.com/tools/latitude-longitude-distance-calculator/

} // end of namespace
 
#undef FUNC
