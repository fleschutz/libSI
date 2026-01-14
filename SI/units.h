// SI/units.h - type-safe SI datatypes & units, e.g. SI::mass
#pragma once

#include <type_traits>
#include <limits>
#include <utility>
#include <cmath>
#include <algorithm>
#include <charconv>
#include "datatypes.h"

namespace SI
{
	// The SI Prefixes
	// ---------------
	//SI_INLINE_CONSTEXPR auto exa   = unit<detail::dimensionless, 1000000000000000000>();
	//SI_INLINE_CONSTEXPR auto peta  = unit<detail::dimensionless, 1000000000000000>();
	//SI_INLINE_CONSTEXPR auto tera  = unit<detail::dimensionless, 1000000000000>();
	SI_INLINE_CONSTEXPR auto giga  = unit<detail::dimensionless, 1000000000>();
	SI_INLINE_CONSTEXPR auto mega  = unit<detail::dimensionless, 1000000>();
	SI_INLINE_CONSTEXPR auto kilo  = unit<detail::dimensionless, 1000>();
	SI_INLINE_CONSTEXPR auto hecto = unit<detail::dimensionless, 100>();

	SI_INLINE_CONSTEXPR auto centi = unit<detail::dimensionless, 1, 100>();
	SI_INLINE_CONSTEXPR auto milli = unit<detail::dimensionless, 1, 1000>();
	SI_INLINE_CONSTEXPR auto micro = unit<detail::dimensionless, 1, 1000000>();
	SI_INLINE_CONSTEXPR auto nano  = unit<detail::dimensionless, 1, 1000000000>();
	//SI_INLINE_CONSTEXPR auto pico  = unit<detail::dimensionless, 1, 1000000000000>();
	//SI_INLINE_CONSTEXPR auto femto = unit<detail::dimensionless, 1, 1000000000000000>();

	// The 7 Base SI Units
	// -------------------
	// length in...
	SI_INLINE_CONSTEXPR auto meter       = unit<length>();
	SI_INLINE_CONSTEXPR auto kilometers  = kilo * meter; 
	SI_INLINE_CONSTEXPR auto centimeters = centi * meter;
	SI_INLINE_CONSTEXPR auto millimeters = milli * meter;
	SI_INLINE_CONSTEXPR auto per_meter   = unit<per_length>(); 
	// time in...
	SI_INLINE_CONSTEXPR auto second      = unit<time>();
	SI_INLINE_CONSTEXPR auto minute      = unit<time, 60>();
	SI_INLINE_CONSTEXPR auto hour        = unit<time, 3600>();
	SI_INLINE_CONSTEXPR auto day         = unit<time, 24*3600>();
	// mass in...
	SI_INLINE_CONSTEXPR auto kilogram    = unit<mass>();
	SI_INLINE_CONSTEXPR auto gram        = milli * kilogram;
	// thermodynamic temperature in...
	SI_INLINE_CONSTEXPR auto kelvins     = unit<temperature>();
	// electric current in...
	SI_INLINE_CONSTEXPR auto amperes     = unit<electric_current>();
	// amount of substance in...
	SI_INLINE_CONSTEXPR auto moles       = unit<amount_of_substance>(); 
	// luminous intensity in...
	SI_INLINE_CONSTEXPR auto candelas    = unit<luminous_intensity>();

	// The Derived SI Units
	// --------------------
	SI_INLINE_CONSTEXPR auto hertz       = unit<frequency>();

	SI_INLINE_CONSTEXPR auto meters2     = unit<area>(); // (square meter)
	SI_INLINE_CONSTEXPR auto kilometers2  = kilo * kilo * meters2;
	SI_INLINE_CONSTEXPR auto per_meter2  = unit<per_area>();

	SI_INLINE_CONSTEXPR auto meters2_per_second = meters2 / second;
	SI_INLINE_CONSTEXPR auto kilograms_per_meter2 = kilogram / meters2;

	SI_INLINE_CONSTEXPR auto meters3     = unit<volume>(); // (cubic meter)
	SI_INLINE_CONSTEXPR auto kilometers3 = kilo * kilo * kilo * meters3;
	SI_INLINE_CONSTEXPR auto centimeters3 = centi * centi * centi * meters3;

	SI_INLINE_CONSTEXPR auto meters3_per_second = meters3 / second;
	SI_INLINE_CONSTEXPR auto meters3_per_kilogram_per_second2 = meters3 / kilogram / (second * second);
	SI_INLINE_CONSTEXPR auto kilograms_per_meter3 = kilogram / meters3;
	SI_INLINE_CONSTEXPR auto grams_per_centimeter3 = gram / centimeters3;

	SI_INLINE_CONSTEXPR auto meters_per_second = unit<velocity>();
	SI_INLINE_CONSTEXPR auto kilometers_per_hour = kilometers / hour;
	SI_INLINE_CONSTEXPR auto millimeters_per_hour = millimeters / hour;

	SI_INLINE_CONSTEXPR auto meters_per_second2 = unit<acceleration>();

	SI_INLINE_CONSTEXPR auto newtons     = unit<force>();
	SI_INLINE_CONSTEXPR auto newtonmeters = newtons * meter;
	SI_INLINE_CONSTEXPR auto newtonseconds= newtons * second;

	SI_INLINE_CONSTEXPR auto joules     = unit<energy>();
	SI_INLINE_CONSTEXPR auto jouleseconds = joules * second;
	SI_INLINE_CONSTEXPR auto joules_per_second = joules / second;
	SI_INLINE_CONSTEXPR auto joules_per_kelvin = joules / kelvins;
	SI_INLINE_CONSTEXPR auto joules_per_second_per_kilogram = joules / second / kilogram;
	SI_INLINE_CONSTEXPR auto joules_per_kilogram_per_kelvin = joules / kilogram / kelvins;
	SI_INLINE_CONSTEXPR auto joules_per_kelvin_per_mol = joules / kelvins / moles;

	SI_INLINE_CONSTEXPR auto grays = joules / kilogram;
	SI_INLINE_CONSTEXPR auto sieverts = joules / kilogram;

	SI_INLINE_CONSTEXPR auto watts       = unit<power>();
	SI_INLINE_CONSTEXPR auto wattmeters2 = watts * meters2;
	SI_INLINE_CONSTEXPR auto watts_per_meter2 = watts / meters2;

	SI_INLINE_CONSTEXPR auto pascals     = unit<pressure>();

	SI_INLINE_CONSTEXPR auto amperes_per_meter = amperes / meter;
	SI_INLINE_CONSTEXPR auto amperes_per_meter2 = amperes / (meter * meter);
	SI_INLINE_CONSTEXPR auto ampere_hours= amperes * hour;

	SI_INLINE_CONSTEXPR auto coulombs     = unit<electric_charge>();
	SI_INLINE_CONSTEXPR auto coulombs_per_mol = coulombs / moles;

	SI_INLINE_CONSTEXPR auto volts       = unit<electric_potential>();
	SI_INLINE_CONSTEXPR auto farads      = coulombs / volts;
	SI_INLINE_CONSTEXPR auto farads_per_meter = farads / meter;
	SI_INLINE_CONSTEXPR auto ohms        = volts / amperes;
	SI_INLINE_CONSTEXPR auto ohm_meters  = ohms * meter;
	SI_INLINE_CONSTEXPR auto siemens     = amperes / volts;
	SI_INLINE_CONSTEXPR auto siemens_per_meter = siemens / meter;
	SI_INLINE_CONSTEXPR auto henrys      = volts * second / amperes;
	SI_INLINE_CONSTEXPR auto webers      = volts * second;
	SI_INLINE_CONSTEXPR auto teslas      = kilogram / (amperes * second * second);
	SI_INLINE_CONSTEXPR auto joules_per_tesla = joules / teslas;

	SI_INLINE_CONSTEXPR auto steradians  = unit<detail::dimensionless>();

	SI_INLINE_CONSTEXPR auto lumens      = candelas * steradians; 
	SI_INLINE_CONSTEXPR auto lumenseconds= lumens * second;
	SI_INLINE_CONSTEXPR auto lumens_per_watt = lumens / watts; 

	SI_INLINE_CONSTEXPR auto kilograms_per_mol = kilogram / moles;
	SI_INLINE_CONSTEXPR auto mols_per_meter3 = moles / meters3;
	SI_INLINE_CONSTEXPR auto mols_per_kilogram = moles / kilogram;
	SI_INLINE_CONSTEXPR auto mols_per_second = moles / second;
	SI_INLINE_CONSTEXPR auto per_mol      = unit<per_amount_of_substance>(); 

	// IMPERIAL UNITS
	SI_INLINE_CONSTEXPR auto pounds       = unit<mass, 45359237, 100000000>();
	SI_INLINE_CONSTEXPR auto feet         = unit<length, 3048, 10000>();
	SI_INLINE_CONSTEXPR auto nautical_miles = unit<length, 1852, 100>();
	SI_INLINE_CONSTEXPR auto inches       = unit<length, 254, 10000>();
	SI_INLINE_CONSTEXPR auto statute_miles = unit<length, 1609344, 1000>();
	SI_INLINE_CONSTEXPR auto fahrenheit   = detail::unit<detail::temperature_dimension, detail::tag_fahrenheit>();
	SI_INLINE_CONSTEXPR auto miles_per_hour = statute_miles / hour;
	SI_INLINE_CONSTEXPR auto knots        = nautical_miles / hour;

	// VARIOUS UNITS
	SI_INLINE_CONSTEXPR auto celsius     = detail::unit<detail::temperature_dimension, detail::tag_celsius>();

	SI_INLINE_CONSTEXPR auto bytes       = unit<detail::dimensionless>();
	SI_INLINE_CONSTEXPR auto bytes_per_second = bytes / second;

	// ANGLE (DIMENSIONLESS)
	typedef long double angle;
	typedef angle radians;

	SI_INLINE angle sin(angle a)
	{
		return std::sin(radians(a));
	}

	SI_INLINE angle cos(angle a)
	{
		return std::cos(radians(a));
	}

	SI_INLINE angle tan(angle a)
	{
		return std::tan(radians(a));
	}

	SI_INLINE angle atan2(length y, length x)
	{
		return std::atan2(meter(y), meter(x));
	}

	// Raise any number to power of 2 (x² or x*x).
	template <typename T>
	[[nodiscard]] SI_INLINE_CONSTEXPR auto square(T x) { return x * x; }

	// Raise any number to power of 3 (x³ or x*x*x).
	template <typename T>
	[[nodiscard]] SI_INLINE_CONSTEXPR auto cube(T x) { return x * x * x; }
}

#undef SI_DATATYPE
#undef SI_RETURN_QUANTITY
#undef SI_INLINE_CONSTEXPR
#undef SI_INLINE
