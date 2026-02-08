// <SI/datatypes.h> - type-safe SI datatypes, e.g. SI::length or SI::time
#pragma once
#include <SI/internal.h>

namespace SI
{
#define DATATYPE(_name, _lengthExp, _massExp, _timeExp, _TemperatureExp, _currentExp, _substanceExp, _intensityExp) \
    namespace detail { using _name ## _dimension = dimension<_lengthExp, _massExp, _timeExp, _TemperatureExp,       \
	                                                     _currentExp, _substanceExp, _intensityExp>; }          \
    template <class T> using _name ## _t = detail::quantity<detail:: _name ## _dimension, T>;                       \
    using _name = _name ## _t<SIdouble>;                                                                            \
    using _name ## 2 = _name ## _t<detail::vec2<SIdouble>>;                                                         \
    using _name ## 3 = _name ## _t<detail::vec3<SIdouble>>

	// +++ SI BASE DATATYPES +++     Exponents:
	//                               l  m  t  T  c  s  i  
	DATATYPE(length,                 1, 0, 0, 0, 0, 0, 0); // in meters
	DATATYPE(mass,                   0, 1, 0, 0, 0, 0, 0); // in kilograms
	DATATYPE(time,                   0, 0, 1, 0, 0, 0, 0); // in seconds
	DATATYPE(temperature,            0, 0, 0, 1, 0, 0, 0); // in Kelvins (thermodynamic temperature)
	DATATYPE(electric_current,       0, 0, 0, 0, 1, 0, 0); // in Amperes
	DATATYPE(amount_of_substance,    0, 0, 0, 0, 0, 1, 0); // in moles
	DATATYPE(luminous_intensity,     0, 0, 0, 0, 0, 0, 1); // in candelas

	// +++ DERIVED SI DATATYPES +++
	DATATYPE(per_length,            -1, 0,  0, 0, 0, 0, 0); // per m (reciprocal)
	DATATYPE(area,                   2, 0,  0, 0, 0, 0, 0); // in square meters
	DATATYPE(per_area,              -2, 0,  0, 0, 0, 0, 0); // per square meter (reciprocal)
	DATATYPE(volume,                 3, 0,  0, 0, 0, 0, 0); // in cubic meter
	DATATYPE(frequency,              0, 0, -1, 0, 0, 0, 0); // per second (reciprocal)
	DATATYPE(velocity,               1, 0, -1, 0, 0, 0, 0); // in meter per second
	DATATYPE(acceleration,           1, 0, -2, 0, 0, 0, 0); // in m/s²
	DATATYPE(jerk,                   1, 0, -3, 0, 0, 0, 0); // in m/s³
	DATATYPE(force,                  1, 1, -2, 0, 0, 0, 0); // in Newton
	DATATYPE(energy,                 2, 1, -2, 0, 0, 0, 0); // in Newtonmeter
	DATATYPE(impulse,                1, 1, -1, 0, 0, 0, 0); // in kg*m/s
	DATATYPE(pressure,              -1, 1, -2, 0, 0, 0, 0); // in Pascals
	DATATYPE(torque,                 2, 1, -2, 0, 0, 0, 0); // in kg*m²/s²
	DATATYPE(power,                  2, 1, -3, 0, 0, 0, 0); // in Watts
	DATATYPE(power_intensity,        0, 1, -3, 0, 0, 0, 0); // in W/m²
	DATATYPE(density,               -3, 1,  0, 0, 0, 0, 0); // in kg/m³
	DATATYPE(electric_potential,     2, 1, -3, 0,-1, 0, 0); // in volts
	DATATYPE(electric_charge,        0, 0,  1, 0, 1, 0, 0); // (electric current and time)
	DATATYPE(mass_per_area,         -2, 1,  0, 0, 0, 0, 0); // in kg/m²)
	DATATYPE(per_amount_of_substance,0, 0,  0, 0,-1, 0, 0); // per mol (reciprocal)
	DATATYPE(angular_speed,          0, 0, -1, 0, 1, 0, 0); // in degrees per second
	DATATYPE(specific_energy,        2, 0, -2, 0, 0, 0, 0); // in J/kg (or energy per mass or massic energy or gravimetric energy density)
	DATATYPE(energy_per_mol,         2, 1, -2, 0, 0, 1, 0); // in J/mol
	DATATYPE(volume_per_time_squared,3, 0, -2, 0, 0, 0, 0); // in m³/s²

#undef DATATYPE
} // namespace SI

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/International_System_of_Units
