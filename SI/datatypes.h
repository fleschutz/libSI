// SI/datatypes.h - type-safe SI datatypes such as SI::length or SI::time
#pragma once

#include <limits>
#include <utility>
#include <algorithm>
#include "internal.h"

namespace SI
{
#define DATATYPE(name_, length_, mass_, time_, temperature_, current_, substance_, intensity_)                     \
	namespace detail { using name_ ## _dimension = dimension<length_, mass_, time_, temperature_, current_>; } \
	template <class T> using name_ ## _t = detail::quantity<detail:: name_ ## _dimension, T>;                  \
	using name_ = name_ ## _t<SIfloat>;                                                                        \
	using name_ ## 2 = name_ ## _t<detail::vec2<SIfloat>>;                                                     \
	using name_ ## 3 = name_ ## _t<detail::vec3<SIfloat>>

	// The 7 Base SI Datatypes
	// -----------------------          l  m  t  T  A  s  i
	DATATYPE(length,                 1, 0, 0, 0, 0, 0, 0); // in m
	DATATYPE(mass,                   0, 1, 0, 0, 0, 0, 0); // in kg
	DATATYPE(time,                   0, 0, 1, 0, 0, 0, 0); // in s
	DATATYPE(temperature,            0, 0, 0, 1, 0, 0, 0); // in K (thermodynamic temperature)
	DATATYPE(electric_current,       0, 0, 0, 0, 1, 0, 0); // in A
	DATATYPE(amount_of_substance,    0, 0, 0, 0, 1, 1, 0); // in mol
	DATATYPE(luminous_intensity,     0, 0, 0, 0, 1, 0, 1); // in cal

	// The Derived SI Datatypes
	// ------------------------
	DATATYPE(per_length,            -1, 0,  0, 0, 0, 0, 0); // per m (reciprocal)
	DATATYPE(area,                   2, 0,  0, 0, 0, 0, 0); // in m²
	DATATYPE(per_area,              -2, 0,  0, 0, 0, 0, 0); // per m² (reciprocal)
	DATATYPE(volume,                 3, 0,  0, 0, 0, 0, 0); // in m³
	DATATYPE(frequency,              0, 0, -1, 0, 0, 0, 0); // per s (reciprocal)
	DATATYPE(velocity,               1, 0, -1, 0, 0, 0, 0); // in m/s
	DATATYPE(acceleration,           1, 0, -2, 0, 0, 0, 0); // in m/s²
	DATATYPE(jerk,                   1, 0, -3, 0, 0, 0, 0); // in m/s³
	DATATYPE(force,                  1, 1, -2, 0, 0, 0, 0); // in N
	DATATYPE(energy,                 2, 1, -2, 0, 0, 0, 0); // in Nm
	DATATYPE(impulse,                1, 1, -1, 0, 0, 0, 0); // in kg*m/s
	DATATYPE(pressure,              -1, 1, -2, 0, 0, 0, 0); // in Pa
	DATATYPE(torque,                 2, 1, -2, 0, 0, 0, 0); // in kg*m²/s²
	DATATYPE(power,                  2, 1, -3, 0, 0, 0, 0); // in W
	DATATYPE(power_intensity,        0, 1, -3, 0, 0, 0, 0); // in W/m²
	DATATYPE(density,               -3, 1,  0, 0, 0, 0, 0); // in kg/m³
	DATATYPE(electric_potential,     2, 1, -3, 0,-1, 0, 0); // in V
	DATATYPE(electric_charge,        0, 0,  1, 0, 1, 0, 0); // (electric current and time)
	DATATYPE(mass_per_area,         -2, 1,  0, 0, 0, 0, 0); // in kg/m²)
	DATATYPE(per_amount_of_substance,0, 0,  0, 0,-1, 0, 0); // per mol (reciprocal)
	DATATYPE(angular_speed,          0, 0, -1, 0, 1, 0, 0); // in °/s

#undef DATATYPE
}
