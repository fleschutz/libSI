/// @file	SI/datatypes.h
/// @brief	Defines 32 type-safe SI datatypes such as SI::length.
/// @details	Contains: 1. SI Base Datatypes, 2. Derived SI datatypes, 3. References

#pragma once
#include <SI/internal.h>
#define DATATYPE(_name, _lengthExp, _massExp, _timeExp, _temperatureExp, _currentExp, _substanceExp, _intensityExp) \
    namespace detail { using _name ## _dimension = dimension<_lengthExp, _massExp, _timeExp, _temperatureExp,       \
                                                             _currentExp, _substanceExp, _intensityExp>; }          \
    template <class T> using _name ## _t = detail::quantity<detail:: _name ## _dimension, T>;                       \
    using _name = _name ## _t<SIdouble>;                                                                            \
    using _name ## 2 = _name ## _t<detail::vec2<SIdouble>>;                                                         \
    using _name ## 3 = _name ## _t<detail::vec3<SIdouble>>

namespace SI {

	// 1. SI Base Datatypes
	// --------------------
	//                               l  m  t  T  c  s  i      (exponents for length,mass,time,temperature,..)
	DATATYPE(length,                 1, 0, 0, 0, 0, 0, 0); // in meters
	DATATYPE(mass,                   0, 1, 0, 0, 0, 0, 0); // in kilograms
	DATATYPE(time,                   0, 0, 1, 0, 0, 0, 0); // in seconds
	DATATYPE(temperature,            0, 0, 0, 1, 0, 0, 0); // in kelvins
	DATATYPE(electric_current,       0, 0, 0, 0, 1, 0, 0); // in amperes
	DATATYPE(amount_of_substance,    0, 0, 0, 0, 0, 1, 0); // in moles
	DATATYPE(luminous_intensity,     0, 0, 0, 0, 0, 0, 1); // in candelas

	// 2. Derived SI Datatypes
	// -----------------------
	DATATYPE(per_length,            -1, 0, 0, 0, 0, 0, 0); // per meter (reciprocal)
	DATATYPE(area,                   2, 0, 0, 0, 0, 0, 0); // in square meters
	DATATYPE(per_area,              -2, 0, 0, 0, 0, 0, 0); // per square meter (reciprocal)
	DATATYPE(volume,                 3, 0, 0, 0, 0, 0, 0); // in cubic meter
	DATATYPE(frequency,              0, 0,-1, 0, 0, 0, 0); // per second (reciprocal)
	DATATYPE(velocity,               1, 0,-1, 0, 0, 0, 0); // in meter per second
	DATATYPE(acceleration,           1, 0,-2, 0, 0, 0, 0); // in meter per square meter
	DATATYPE(jerk,                   1, 0,-3, 0, 0, 0, 0); // in meter per cubic meter
	DATATYPE(force,                  1, 1,-2, 0, 0, 0, 0); // in newtons
	DATATYPE(energy,                 2, 1,-2, 0, 0, 0, 0); // in newtonmeter
	DATATYPE(impulse,                1, 1,-1, 0, 0, 0, 0); // in kilogram meter per second
	DATATYPE(torque,                 2, 1,-2, 0, 0, 0, 0); // in kilogram square meter per square second
	DATATYPE(pressure,              -1, 1,-2, 0, 0, 0, 0); // in pascals
	DATATYPE(power,                  2, 1,-3, 0, 0, 0, 0); // in watts
	DATATYPE(power_intensity,        0, 1,-3, 0, 0, 0, 0); // in watts per square meter
	DATATYPE(density,               -3, 1, 0, 0, 0, 0, 0); // in kilograms per cubic meter
	DATATYPE(electric_potential,     2, 1,-3, 0,-1, 0, 0); // in volts
	DATATYPE(electric_charge,        0, 0, 1, 0, 1, 0, 0); // in amperes per second
	DATATYPE(mass_per_area,         -2, 1, 0, 0, 0, 0, 0); // in kilograms per square meter
	DATATYPE(mass_per_power,        -2, 0, 3, 0, 0, 0, 0); // in kilograms per watt
	DATATYPE(per_amount_of_substance,0, 0, 0, 0,-1, 0, 0); // per mol (reciprocal)
	DATATYPE(angular_speed,          0, 0,-1, 0, 1, 0, 0); // in degrees per second
	DATATYPE(specific_energy,        2, 0,-2, 0, 0, 0, 0); // in joules per kilogram
	DATATYPE(energy_per_mol,         2, 1,-2, 0, 0, 1, 0); // in joules per mol
	DATATYPE(volume_per_time_squared,3, 0,-2, 0, 0, 0, 0); // in cubic meter per square second

	// 3. References
	// -------------
	// 1. https://en.wikipedia.org/wiki/International_System_of_Units

} // namespace SI

#undef DATATYPE
