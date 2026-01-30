// <SI/units.h> - type-safe SI units, e.g. meters or seconds
#pragma once
#include <SI/datatypes.h>

namespace SI
{
#define UNIT(_name) inline constexpr auto _name

	// ++ SI BASE UNITS +++
	UNIT(meters)       = unit<length>();
	UNIT(seconds)      = unit<time>();
	UNIT(kilograms)    = unit<mass>();
	UNIT(kelvins)      = unit<temperature>();
	UNIT(amperes)      = unit<electric_current>();
	UNIT(moles)        = unit<amount_of_substance>();
	UNIT(candelas)     = unit<luminous_intensity>();

	// ++ SI PREFIXES +++
	UNIT(exa)          = unit<detail::dimensionless, 1000000000000000000, 1>();
	UNIT(peta)         = unit<detail::dimensionless, 1000000000000000, 1>();
	UNIT(tera)         = unit<detail::dimensionless, 1000000000000, 1>();
	UNIT(giga)         = unit<detail::dimensionless, 1000000000, 1>();
	UNIT(mega)         = unit<detail::dimensionless, 1000000, 1>();
	UNIT(kilo)         = unit<detail::dimensionless, 1000, 1>();
	UNIT(hecto)        = unit<detail::dimensionless, 100, 1>();
	UNIT(centi)        = unit<detail::dimensionless, 1, 100>();
	UNIT(milli)        = unit<detail::dimensionless, 1, 1000>();
	UNIT(micro)        = unit<detail::dimensionless, 1, 1000000>();
	UNIT(nano)         = unit<detail::dimensionless, 1, 1000000000>();
	UNIT(pico)         = unit<detail::dimensionless, 1, 1000000000000>();
	UNIT(femto)        = unit<detail::dimensionless, 1, 1000000000000000>();
	UNIT(atto)         = unit<detail::dimensionless, 1, 1000000000000000000>();

	// ++ SI DERIVED/COMBINED UNITS +++
	UNIT(kilometers)   = kilo * meters; 
	UNIT(centimeters)  = centi * meters;
	UNIT(millimeters)  = milli * meters;
	UNIT(per_meter)    = unit<per_length>();
	UNIT(minutes)      = unit<time, 60>();
	UNIT(hours)        = unit<time, 60*60>();
	UNIT(grams)        = milli * kilograms;
	UNIT(hertz)        = unit<frequency>();
	// area in...
	UNIT(meters2)      = unit<area>(); // (square meter)
	UNIT(kilometers2)  = kilo * kilo * meters2;
	UNIT(per_meter2)   = unit<per_area>();
	UNIT(meter_kelvins)= meters * kelvins;
	UNIT(meters2_per_second) = meters2 / seconds;
	UNIT(kilograms_per_meter2) = kilograms / meters2;
	// volume in...
	UNIT(meters3)      = unit<volume>(); // (cubic meter)
	UNIT(kilometers3)  = kilo * kilo * kilo * meters3;
	UNIT(centimeters3) = centi * centi * centi * meters3;
	UNIT(meters3_per_second) = meters3 / seconds;
	UNIT(meters3_per_mol) = meters3 / moles;
	UNIT(meters3_per_second2) = meters3 / (seconds * seconds);
	UNIT(meters3_per_kilogram_per_second2) = meters3 / kilograms / (seconds * seconds);
	UNIT(kilograms_per_meter3) = kilograms / meters3;
	UNIT(grams_per_centimeter3) = grams / centimeters3;
	// velocity in...
	UNIT(meters_per_second) = unit<velocity>();
	UNIT(kilometers_per_hour) = kilometers / hours;
	UNIT(millimeters_per_hour) = millimeters / hours;
	// acceleration in...
	UNIT(meters_per_second2) = unit<acceleration>();
	// force in...
	UNIT(newtons)      = unit<force>();
	UNIT(newtonmeters) = newtons * meters;
	UNIT(newtonseconds) = newtons * seconds;
	UNIT(newtons_per_ampere2) = newtons / (amperes * amperes);
	// energy in...
	UNIT(joules)       = unit<energy>();
	UNIT(jouleseconds) = joules * seconds;
	UNIT(joules_per_second) =  joules / seconds;
	UNIT(joules_per_kelvin) = joules / kelvins;
	UNIT(joules_per_second_per_kilogram) = joules / seconds / kilograms;
	UNIT(joules_per_kilogram_per_kelvin) = joules / kilograms / kelvins;
	UNIT(joules_per_kelvin_per_mol) = joules / kelvins / moles;
	// pressure in...
	UNIT(pascals)      = unit<pressure>();

	UNIT(grays)        = joules / kilograms;
	UNIT(sieverts)     = joules / kilograms;

	UNIT(watts)        = unit<power>();
	UNIT(wattmeters2)  = watts * meters2;
	UNIT(watts_per_meter2) = watts / meters2;

	UNIT(amperes_per_meter) = amperes / meters;
	UNIT(amperes_per_meter2) = amperes / (meters * meters);
	UNIT(ampere_hours) = amperes * hours;

	UNIT(coulombs)     = unit<electric_charge>();
	UNIT(coulombs_per_mol) = coulombs / moles;

	UNIT(volts)        = unit<electric_potential>();
	UNIT(farads)       = coulombs / volts;
	UNIT(farads_per_meter) = farads / meters;
	UNIT(ohms)         = volts / amperes;
	UNIT(ohm_meters)   = ohms * meters;
	UNIT(siemens)      = amperes / volts;
	UNIT(siemens_per_meter) = siemens / meters;
	UNIT(henrys)       = volts * seconds / amperes;
	UNIT(webers)       = volts * seconds;
	UNIT(teslas)       = kilograms / (amperes * seconds * seconds);
	UNIT(joules_per_tesla) = joules / teslas;

	UNIT(steradians)   = unit<detail::dimensionless>();

	UNIT(lumens)       = candelas * steradians;
	UNIT(lumenseconds) = lumens * seconds;
	UNIT(lumens_per_watt) = lumens / watts;

	UNIT(kilograms_per_mol) = kilograms / moles;
	UNIT(mols_per_meter3) = moles / meters3;
	UNIT(mols_per_kilogram) = moles / kilograms;
	UNIT(mols_per_second) = moles / seconds;
	UNIT(per_mol)      = unit<per_amount_of_substance>();

	// +++ IMPERIAL UNITS +++
	UNIT(pounds)       = unit<mass, 45359237, 100000000>();
	UNIT(feet)         = unit<length, 3048, 10000>();
	UNIT(nautical_miles) = unit<length, 1852, 100>();
	UNIT(inches)       = unit<length, 254, 10000>();
	UNIT(statute_miles)= unit<length, 1609344, 1000>();
	UNIT(fahrenheit)   = detail::unit<detail::temperature_dimension, detail::tag_fahrenheit>();
	UNIT(miles_per_hour) = statute_miles / hours;
	UNIT(knots)        = nautical_miles / hours;

	// +++ VARIOUS UNITS +++
	UNIT(celsius)      = detail::unit<detail::temperature_dimension, detail::tag_celsius>();
	UNIT(bytes)        = unit<detail::dimensionless>();
	UNIT(bytes_per_second) = bytes / seconds;

	// +++ ANGLE +++ (DIMENSIONLESS)
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
		return std::atan2(meters(y), meters(x));
	}

	// +++ BASIC FUNCTIONS/TEMPLATES +++
	// Raise any number <x> to power of 2 (x² or x*x).
	template <typename T>
	[[nodiscard]] SI_INLINE_CONSTEXPR auto square(T x) { return x * x; }

	// Raise any number <x> to power of 3 (x³ or x*x*x).
	template <typename T>
	[[nodiscard]] SI_INLINE_CONSTEXPR auto cube(T x) { return x * x * x; }

	// Clamp any number <x> between min and max value.
	template <typename T>
	[[nodiscard]] SI_INLINE_CONSTEXPR auto clamp(T x, T min, T max) {
		if (x < min) x = min;
		if (x > max) x = max;
		return x;
	}

#undef UNIT
} // namespace SI

#undef SI_RETURN_QUANTITY
#undef SI_INLINE_CONSTEXPR
#undef SI_INLINE

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/International_System_of_Units
