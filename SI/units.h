/// @file     SI/units.h
/// @brief    Defines 103 type-safe units, e.g. SI::meters
/// @details  Categories are: SI Base Units, SI Derived Units, Imperial Units, Various Units, and References.

#pragma once
#include <SI/datatypes.h>
#define UNIT(_name) inline constexpr auto _name

namespace SI {

	// SI Base Units
	// -------------
	UNIT(meters)        = unit<length>();
	UNIT(seconds)       = unit<time>();
	UNIT(kilograms)     = unit<mass>();
	UNIT(kelvins)       = unit<temperature>();
	UNIT(amperes)       = unit<current>();
	UNIT(moles)         = unit<substance>();
	UNIT(candelas)      = unit<luminous_intensity>();

	// Derived SI Units
	// ----------------
	UNIT(kilometers)    = unit<length, 1000>();
	UNIT(millimeters)   = unit<length, 1, 1000>();
	UNIT(per_meter)     = unit<per_length>();
	UNIT(minutes)       = unit<time, 60>();
	UNIT(hours)         = unit<time, 3600>();
	UNIT(hertz)         = unit<frequency>();
	// area in...
	UNIT(meters2)       = unit<area>(); // (square meter)
	UNIT(kilometers2)   = unit<area, 1000*1000>();
	UNIT(per_meter2)    = unit<per_area>();
	UNIT(meter_kelvins) = meters * kelvins;
	UNIT(meters2_per_second) = meters2 / seconds;
	UNIT(kilograms_per_meter2) = kilograms / meters2;
	// volume in...
	UNIT(meters3)       = unit<volume>(); // (cubic meter)
	UNIT(kilometers3)   = unit<volume, 1000*1000*1000>();
	UNIT(meters3_per_second) = meters3 / seconds;
	UNIT(meters3_per_mol) = meters3 / moles;
	UNIT(meters3_per_second2) = meters3 / (seconds * seconds);
	UNIT(meters3_per_kilogram_per_second2) = meters3 / kilograms / (seconds * seconds);
	UNIT(kilograms_per_meter3) = kilograms / meters3;
	// velocity in...
	UNIT(meters_per_second) = unit<velocity>();
	UNIT(meters_per_hour)   = meters / hours;
	// acceleration in...
	UNIT(meters_per_second2) = unit<acceleration>();
	// force in...
	UNIT(newtons)       = unit<force>();
	UNIT(newtonmeters)  = newtons * meters;
	UNIT(newtonseconds) = newtons * seconds;
	UNIT(newtons_per_ampere2) = newtons / (amperes * amperes);
	// energy in...
	UNIT(joules)        = unit<energy>();
	UNIT(jouleseconds)  = joules * seconds;
	UNIT(joules_per_second) =  joules / seconds;
	UNIT(joules_per_kelvin) = joules / kelvins;
	UNIT(joules_per_second_per_kilogram) = joules / seconds / kilograms;
	UNIT(joules_per_kilogram_per_kelvin) = joules / kilograms / kelvins;
	UNIT(joules_per_mol) = unit<energy_per_mol>();
	UNIT(joules_per_kelvin_per_mol) = joules / kelvins / moles;
	// pressure in...
	UNIT(pascals)       = unit<pressure>();
	// absorbed dose in...
	UNIT(grays)         = joules / kilograms;
	UNIT(sieverts)      = joules / kilograms;

	UNIT(watts)         = unit<power>();
	UNIT(wattmeters2)   = watts * meters2;
	UNIT(watts_per_meter2) = watts / meters2;

	UNIT(amperes_per_meter) = amperes / meters;
	UNIT(amperes_per_meter2) = amperes / (meters * meters);
	UNIT(ampere_hours)  = amperes * hours;

	UNIT(coulombs)      = unit<electric_charge>();
	UNIT(coulombs_per_mol) = coulombs / moles;

	UNIT(volts)         = unit<electric_potential>();
	UNIT(farads)        = coulombs / volts;
	UNIT(hertz_per_volt) = hertz / volts;
	UNIT(farads_per_meter) = farads / meters;
	UNIT(ohms)          = volts / amperes;
	UNIT(ohm_meters)    = ohms * meters;
	UNIT(siemens)       = amperes / volts;
	UNIT(siemens_per_meter) = siemens / meters;
	UNIT(henrys)        = volts * seconds / amperes;
	UNIT(webers)        = volts * seconds;
	UNIT(teslas)        = kilograms / (amperes * seconds * seconds);
	UNIT(joules_per_tesla) = joules / teslas;

	UNIT(steradians)    = unit<detail::dimensionless>();

	UNIT(lumens)        = candelas * steradians;
	UNIT(lumenseconds)  = lumens * seconds;
	UNIT(lumens_per_watt) = lumens / watts;
	UNIT(lux)           = lumens / meters2;

	UNIT(kilograms_per_mol) = kilograms / moles;
	UNIT(mols_per_meter3) = moles / meters3;
	UNIT(mols_per_kilogram) = moles / kilograms;
	UNIT(mols_per_second) = moles / seconds;
	UNIT(per_mol)        = unit<per_substance>();

	UNIT(kilograms_per_watt) = kilograms / watts;

	// Imperial Units
	// --------------
	UNIT(pounds)         = unit<mass, 45359237, 100000000>();
	UNIT(feet)           = unit<length, 3048, 10000>();
	UNIT(nautical_miles) = unit<length, 1852, 100>();
	UNIT(inches)         = unit<length, 254, 10000>();
	UNIT(statute_miles)  = unit<length, 1609344, 1000>();
	UNIT(fahrenheit)     = detail::unit<detail::temperature_dimension, detail::tag_fahrenheit>();
	UNIT(miles_per_hour) = statute_miles / hours;
	UNIT(knots)          = nautical_miles / hours;

	// Various Units
	// -------------
	UNIT(celsius)          = detail::unit<detail::temperature_dimension, detail::tag_celsius>();
	UNIT(bytes)            = unit<detail::dimensionless>();
	UNIT(bytes_per_second) = bytes / seconds;

	// Basic Functions and Templates
	// -----------------------------
	/// @brief Calculates the sinus of an angle (a).
	[[nodiscard]] inline angle sin(const angle a)
	{
		return std::sin(radians(a));
	}

	/// @brief Calculates the cosinus of an angle (a).
	[[nodiscard]] inline angle cos(const angle a)
	{
		return std::cos(radians(a));
	}

	/// @brief Calculates the tangens of an angle (a).
	[[nodiscard]] inline angle tan(const angle a)
	{
		return std::tan(radians(a));
	}

	/// @brief Calculates sin²x
	[[nodiscard]] inline angle sin2(const angle x)
	{
		return 0.5 * (1. - std::cos(2. * x));
	}

	/// @brief Calculates cos²x
	[[nodiscard]] inline angle cos2(const angle x)
	{
		return 0.5 * (1. + std::cos(2. * x));
	}

	/// @brief Calculates the square root of an angle (a).
	[[nodiscard]] inline angle sqrt(const angle a)
	{
		return std::sqrt(radians(a));
	}

	/// @brief Calculates the atangens of two angles.
	[[nodiscard]] inline angle atan2(const angle y, const angle x)
	{
		return std::atan2(radians(y), radians(x));
	}

	/// @brief Calculates the angle between the positive x-axis and a point (x, y).
	[[nodiscard]] inline angle atan2(const length y, const length x)
	{
		return std::atan2(meters(y), meters(x));
	}
	/// @brief Raise any number <x> to power of 2 (x² or x*x).
	template <typename T>
	[[nodiscard]] SI_INLINE_CONSTEXPR auto square(T x) { return x * x; }

	/// @brief Raise any number <x> to power of 3 (x³ or x*x*x).
	template <typename T>
	[[nodiscard]] SI_INLINE_CONSTEXPR auto cube(T x) { return x * x * x; }

	/// @brief Clamp any number <x> between <min> and <max> value.
	template <typename T>
	[[nodiscard]] SI_INLINE_CONSTEXPR auto clamp(T x, T min, T max) {
		if (x < min) return min;
		if (x > max) return max;
		return x;
	}

	// 7. References
	// -------------
	// 1. https://en.wikipedia.org/wiki/International_System_of_Units

} // end of namespace

#undef UNIT
#undef SI_RETURN_QUANTITY
#undef SI_INLINE_CONSTEXPR
