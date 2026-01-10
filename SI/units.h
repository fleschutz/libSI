// SI/units.h - defines type-safe SI units
#pragma once

#include <type_traits>
#include <limits>
#include <utility>
#include <cmath>
#include <algorithm>
#include <charconv>
#include "internal.h"
#define SI_INLINE inline 
#define SI_INLINE_CONSTEXPR constexpr SI_INLINE

namespace SI
{
	SI_INLINE_CONSTEXPR detail::zero_t zero;

	template <class Dimension, long Numerator = 1, long Denumerator = 1>
	using unit = detail::unit<detail::dimension_of_t<Dimension>, detail::ratio<Numerator, Denumerator>>;

	using detail::abs;
	using detail::normalize;
	using detail::norm;
	using detail::distance;
	using detail::pow;
	using detail::root;
	using detail::sqrt;
	using detail::dot;
	using detail::clamp;
	using detail::deangle;
	using detail::is_si;
	using detail::is_si_v;

#define DATATYPE(name_, length_, mass_, time_, temperature_, current_, substance_, intensity_)		\
	namespace detail { using name_ ## _dimension = dimension<length_, mass_, time_, temperature_, current_>; }\
	template <class T> using name_ ## _t = detail::quantity<detail:: name_ ## _dimension, T>;		\
	using name_ = name_ ## _t<SIfloat>;									\
	using name_ ## 2 = name_ ## _t<detail::vec2<SIfloat>>;							\
	using name_ ## 3 = name_ ## _t<detail::vec3<SIfloat>>

	// The 7 SI Base Datatypes
	// -----------------------    l  m  t  T  A  s  i
	DATATYPE(length,              1, 0, 0, 0, 0, 0, 0); // in m
	DATATYPE(mass,                0, 1, 0, 0, 0, 0, 0); // in kg
	DATATYPE(time,                0, 0, 1, 0, 0, 0, 0); // in s
	DATATYPE(temperature,         0, 0, 0, 1, 0, 0, 0); // in K (thermodynamic temperature)
	DATATYPE(electric_current,    0, 0, 0, 0, 1, 0, 0); // in A
	DATATYPE(amount_of_substance, 0, 0, 0, 0, 1, 1, 0); // in mol
	DATATYPE(luminous_intensity,  0, 0, 0, 0, 1, 0, 1); // in cal

	// The 22 Derived SI Datatypes
	// ---------------------------
	DATATYPE(per_length,         -1, 0,  0, 0, 0, 0, 0); // per m (reciprocal)
	DATATYPE(area,                2, 0,  0, 0, 0, 0, 0); // in m²
	DATATYPE(per_area,           -2, 0,  0, 0, 0, 0, 0); // per m² (reciprocal)
	DATATYPE(volume,              3, 0,  0, 0, 0, 0, 0); // in m³
	DATATYPE(frequency,           0, 0, -1, 0, 0, 0, 0); // per s (reciprocal)
	DATATYPE(velocity,            1, 0, -1, 0, 0, 0, 0); // in m/s
	DATATYPE(acceleration,        1, 0, -2, 0, 0, 0, 0); // in m/s²
	DATATYPE(jerk,                1, 0, -3, 0, 0, 0, 0);
	DATATYPE(force,               1, 1, -2, 0, 0, 0, 0); // in N
	DATATYPE(energy,              2, 1, -2, 0, 0, 0, 0); // in Nm
	DATATYPE(impulse,             1, 1, -1, 0, 0, 0, 0);
	DATATYPE(pressure,           -1, 1, -2, 0, 0, 0, 0); // in Pa
	DATATYPE(torque,              2, 1, -2, 0, 0, 0, 0);
	DATATYPE(power,               2, 1, -3, 0, 0, 0, 0); // in W
	DATATYPE(power_intensity,     0, 1, -3, 0, 0, 0, 0); // in W/m²
	DATATYPE(density,            -3, 1,  0, 0, 0, 0, 0); // in kg/m³
	DATATYPE(electric_potential,  2, 1, -3, 0,-1, 0, 0); // in V
	DATATYPE(electric_charge,     0, 0,  1, 0, 1, 0, 0); // (electric current and time)
	DATATYPE(mass_per_area,      -2, 1,  0, 0, 0, 0, 0); // in kg/m²)
	DATATYPE(per_amount_of_substance,0, 0,  0, 0,-1, 0, 0);// per mol (reciprocal)
	DATATYPE(angular_speed,       0, 0, -1, 0, 1, 0, 0); // in °/s

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

	// The 7 SI Base Units
	// -------------------
	// length in...
	SI_INLINE_CONSTEXPR auto meter       = unit<length>();
	SI_INLINE_CONSTEXPR auto kilometer   = kilo * meter; 
	SI_INLINE_CONSTEXPR auto centimeter  = centi * meter;
	SI_INLINE_CONSTEXPR auto millimeter  = milli * meter;
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
	SI_INLINE_CONSTEXPR auto kelvin      = unit<temperature>();
	// electric current in...
	SI_INLINE_CONSTEXPR auto ampere      = unit<electric_current>();
	// amount of substance in...
	SI_INLINE_CONSTEXPR auto mol         = unit<amount_of_substance>(); 
	// luminous intensity in...
	SI_INLINE_CONSTEXPR auto candelas    = unit<luminous_intensity>();

	// The 22 SI Derived Units
	// -----------------------
	SI_INLINE_CONSTEXPR auto hertz       = unit<frequency>();

	SI_INLINE_CONSTEXPR auto meter2      = unit<area>(); // (square meter)
	SI_INLINE_CONSTEXPR auto kilometers2  = kilo * kilo * meter2;
	SI_INLINE_CONSTEXPR auto per_meter2  = unit<per_area>();

	SI_INLINE_CONSTEXPR auto meters2_per_second = meter2 / second;
	SI_INLINE_CONSTEXPR auto kilograms_per_meter2 = kilogram / meter2;

	SI_INLINE_CONSTEXPR auto meters3     = unit<volume>(); // (cubic meter)
	SI_INLINE_CONSTEXPR auto kilometers3 = kilo * kilo * kilo * meters3;
	SI_INLINE_CONSTEXPR auto centimeters3 = centi * centi * centi * meters3;

	SI_INLINE_CONSTEXPR auto meters3_per_second = meters3 / second;
	SI_INLINE_CONSTEXPR auto meters3_per_kilogram_per_second2 = meters3 / kilogram / (second * second);
	SI_INLINE_CONSTEXPR auto kilograms_per_meter3 = kilogram / meters3;
	SI_INLINE_CONSTEXPR auto grams_per_centimeter3 = gram / centimeters3;

	SI_INLINE_CONSTEXPR auto meters_per_second = unit<velocity>();
	SI_INLINE_CONSTEXPR auto kilometers_per_hour = kilometer / hour;
	SI_INLINE_CONSTEXPR auto millimeters_per_hour = millimeter / hour;

	SI_INLINE_CONSTEXPR auto meters_per_second2 = unit<acceleration>();

	SI_INLINE_CONSTEXPR auto newtons     = unit<force>();
	SI_INLINE_CONSTEXPR auto newtonmeters = newtons * meter;
	SI_INLINE_CONSTEXPR auto newtonseconds= newtons * second;

	SI_INLINE_CONSTEXPR auto joules     = unit<energy>();
	SI_INLINE_CONSTEXPR auto jouleseconds = joules * second;
	SI_INLINE_CONSTEXPR auto joules_per_second = joules / second;
	SI_INLINE_CONSTEXPR auto joules_per_kelvin = joules / kelvin;
	SI_INLINE_CONSTEXPR auto joules_per_second_per_kilogram = joules / second / kilogram;
	SI_INLINE_CONSTEXPR auto joules_per_kilogram_per_kelvin = joules / kilogram / kelvin;
	SI_INLINE_CONSTEXPR auto joules_per_kelvin_per_mol = joules / kelvin / mol;

	SI_INLINE_CONSTEXPR auto gray = joules / kilogram;
	SI_INLINE_CONSTEXPR auto sievert = joules / kilogram;

	SI_INLINE_CONSTEXPR auto watts       = unit<power>();
	SI_INLINE_CONSTEXPR auto wattmeters2 = watts * meter2;
	SI_INLINE_CONSTEXPR auto watts_per_meter2 = watts / meter2;

	SI_INLINE_CONSTEXPR auto pascals     = unit<pressure>();

	SI_INLINE_CONSTEXPR auto amperes_per_meter = ampere / meter;
	SI_INLINE_CONSTEXPR auto amperes_per_meter2 = ampere / (meter * meter);
	SI_INLINE_CONSTEXPR auto ampere_hours= ampere * hour;

	SI_INLINE_CONSTEXPR auto coulombs     = unit<electric_charge>();
	SI_INLINE_CONSTEXPR auto coulombs_per_mol = coulombs / mol;

	SI_INLINE_CONSTEXPR auto volt        = unit<electric_potential>();
	SI_INLINE_CONSTEXPR auto farad       = coulombs / volt;
	SI_INLINE_CONSTEXPR auto farads_per_meter = farad / meter;
	SI_INLINE_CONSTEXPR auto ohm         = volt / ampere;
	SI_INLINE_CONSTEXPR auto ohm_meter   = ohm * meter;
	SI_INLINE_CONSTEXPR auto siemens     = ampere / volt;
	SI_INLINE_CONSTEXPR auto siemens_per_meter = siemens / meter;
	SI_INLINE_CONSTEXPR auto henry       = volt * second / ampere;
	SI_INLINE_CONSTEXPR auto weber       = volt * second;
	SI_INLINE_CONSTEXPR auto tesla       = kilogram / (ampere * second * second);
	SI_INLINE_CONSTEXPR auto joules_per_tesla = joules / tesla;

	SI_INLINE_CONSTEXPR auto steradians  = unit<detail::dimensionless>();

	SI_INLINE_CONSTEXPR auto lumens      = candelas * steradians; 
	SI_INLINE_CONSTEXPR auto lumenseconds= lumens * second;
	SI_INLINE_CONSTEXPR auto lumens_per_watt = lumens / watts; 

	SI_INLINE_CONSTEXPR auto kilograms_per_mol = kilogram / mol;
	SI_INLINE_CONSTEXPR auto mols_per_meter3 = mol / meters3;
	SI_INLINE_CONSTEXPR auto mols_per_kilogram = mol / kilogram;
	SI_INLINE_CONSTEXPR auto mols_per_second = mol / second;
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

#undef DATATYPE
#undef SI_RETURN_QUANTITY
#undef SI_INLINE_CONSTEXPR
#undef SI_INLINE
