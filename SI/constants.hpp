#pragma once

#include "types.hpp"

namespace si
{
	namespace constant
	{
		// Physical constants: (source: https://en.wikipedia.org/wiki/List_of_physical_constants)
		const auto speed_of_light = meters_per_second(299792458); // speed of light in vacuum (c)

		const auto speed_of_sound = meters_per_second(343); // speed of sound in air at 20 °C (68 °F)

		const auto standard_gravity = meters_per_second2(9.80665); // standard gravitational acceleration (G) for the surface of the Earth, defined in the third General Conference on Weights and Measures (1901, CR 70).

		// const auto Gravitational_constant = 6.6743015×10−11 m3⋅kg−1⋅s−2

		const auto electron_mass = kilogram(9.1093837139 * 10E-31);
		const auto muon_mass = kilogram(1.883531627 * 10E-28);
		const auto tau_mass = kilogram(3.16754 * 10E-27);
		const auto proton_mass = kilogram(1.67262192595 * 10E-27);
		const auto neutron_mass = kilogram(1.67492750056 * 10E-27);

		const auto Marathon_length = kilometer(42.195);

		// Mathematical constants: (source: https://en.wikipedia.org/wiki/List_of_mathematical_constants)
		const auto pi = degree(180);
		const auto half_pi = degree(90);
		const auto tau = degree(360);
	}
}	
