// SI/datatypes.h - type-safe SI datatypes, e.g. SI::length, SI::mass or SI::time
#pragma once

#include <limits>
#include <utility>
#include <algorithm>
#include "internal.h"

namespace SI
{
	// The 7 Base SI Datatypes
	// -----------------------          l  m  t  T  A  s  i
	SI_DATATYPE(length,                 1, 0, 0, 0, 0, 0, 0); // in m
	SI_DATATYPE(mass,                   0, 1, 0, 0, 0, 0, 0); // in kg
	SI_DATATYPE(time,                   0, 0, 1, 0, 0, 0, 0); // in s
	SI_DATATYPE(temperature,            0, 0, 0, 1, 0, 0, 0); // in K (thermodynamic temperature)
	SI_DATATYPE(electric_current,       0, 0, 0, 0, 1, 0, 0); // in A
	SI_DATATYPE(amount_of_substance,    0, 0, 0, 0, 1, 1, 0); // in mol
	SI_DATATYPE(luminous_intensity,     0, 0, 0, 0, 1, 0, 1); // in cal

	// The Derived SI Datatypes
	// ------------------------
	SI_DATATYPE(per_length,            -1, 0,  0, 0, 0, 0, 0); // per m (reciprocal)
	SI_DATATYPE(area,                   2, 0,  0, 0, 0, 0, 0); // in m²
	SI_DATATYPE(per_area,              -2, 0,  0, 0, 0, 0, 0); // per m² (reciprocal)
	SI_DATATYPE(volume,                 3, 0,  0, 0, 0, 0, 0); // in m³
	SI_DATATYPE(frequency,              0, 0, -1, 0, 0, 0, 0); // per s (reciprocal)
	SI_DATATYPE(velocity,               1, 0, -1, 0, 0, 0, 0); // in m/s
	SI_DATATYPE(acceleration,           1, 0, -2, 0, 0, 0, 0); // in m/s²
	SI_DATATYPE(jerk,                   1, 0, -3, 0, 0, 0, 0); // in m/s³
	SI_DATATYPE(force,                  1, 1, -2, 0, 0, 0, 0); // in N
	SI_DATATYPE(energy,                 2, 1, -2, 0, 0, 0, 0); // in Nm
	SI_DATATYPE(impulse,                1, 1, -1, 0, 0, 0, 0); // in kg*m/s
	SI_DATATYPE(pressure,              -1, 1, -2, 0, 0, 0, 0); // in Pa
	SI_DATATYPE(torque,                 2, 1, -2, 0, 0, 0, 0); // in kg*m²/s²
	SI_DATATYPE(power,                  2, 1, -3, 0, 0, 0, 0); // in W
	SI_DATATYPE(power_intensity,        0, 1, -3, 0, 0, 0, 0); // in W/m²
	SI_DATATYPE(density,               -3, 1,  0, 0, 0, 0, 0); // in kg/m³
	SI_DATATYPE(electric_potential,     2, 1, -3, 0,-1, 0, 0); // in V
	SI_DATATYPE(electric_charge,        0, 0,  1, 0, 1, 0, 0); // (electric current and time)
	SI_DATATYPE(mass_per_area,         -2, 1,  0, 0, 0, 0, 0); // in kg/m²)
	SI_DATATYPE(per_amount_of_substance,0, 0,  0, 0,-1, 0, 0); // per mol (reciprocal)
	SI_DATATYPE(angular_speed,          0, 0, -1, 0, 1, 0, 0); // in °/s

}
