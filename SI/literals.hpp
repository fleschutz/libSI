#pragma once

#include "types.hpp"

namespace si
{

#define SI_LITERAL(symbol_, unit_)	\
	constexpr auto operator "" _ ## symbol_(long double x) { return unit_(static_cast<double>(x)); }	\
	constexpr auto operator "" _ ## symbol_(unsigned long long x) { return unit_(static_cast<int>(x)); }

	//      Symbol:  Unit:                  Example:    (sorted alphabetically)
	SI_LITERAL(cm,   centimeter);		// 9_cm
	SI_LITERAL(deg,  degree);		// 90_deg
	SI_LITERAL(degC, celsius);		// 0_degC
	SI_LITERAL(degF, fahrenheit);		// 32_degF
	SI_LITERAL(ft,   feet);			// 10_ft
	SI_LITERAL(h,    hour);			// 24_h
	SI_LITERAL(J,    joule);		// 1_J
	SI_LITERAL(K,    kelvin);		// 273.15_K
	SI_LITERAL(kg,   kilogram);		// 10_kg
	SI_LITERAL(km,   kilometer);		// 1.2_km
	SI_LITERAL(kmh,  kilometers_per_hour);	// 100_kmh
	SI_LITERAL(kn,   knots);		// 60_kn
	SI_LITERAL(m,    meter);		// 1_m
	SI_LITERAL(min,  minute);		// 60_min
	SI_LITERAL(MHz,  megahertz);		// 128_MHz
	SI_LITERAL(mm,   millimeter);		// 10_mm
	SI_LITERAL(mph,  miles_per_hour);	// 50_mph
	SI_LITERAL(mps,  meters_per_second);	// 10_mps
	SI_LITERAL(mps2, meters_per_second2);	// 9.807_mps2
	SI_LITERAL(NM,   nautical_mile);	// 1_NM
	SI_LITERAL(s,    second);		// 60_s
	SI_LITERAL(sec,  second);		// 60_sec
	SI_LITERAL(N,    newton);		// 5.0_N
	SI_LITERAL(Nm,   newtonmeter);		// 2.1_Nm

}
