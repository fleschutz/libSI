#pragma once

#include "types.hpp"

#define LITERAL(symbol_, unit_)	\
	constexpr auto operator "" _ ## symbol_(long double x) { return unit_(static_cast<double>(x)); }	\
	constexpr auto operator "" _ ## symbol_(unsigned long long x) { return unit_(static_cast<int>(x)); }

namespace si
{
	//   Symbol:  Unit:                     Example:    (sorted alphabetically)
	LITERAL(cm,   centimeter);		// 9_cm
	LITERAL(deg,  degree);			// 90_deg
	LITERAL(degC, celsius);			// 0_degC
	LITERAL(degF, fahrenheit);		// 32_degF
	LITERAL(ft,   feet);			// 10_ft
	LITERAL(GHz,  gigahertz);		// 18_GHz
	LITERAL(h,    hour);			// 24_h
	LITERAL(J,    joule);			// 1_J
	LITERAL(K,    kelvin);			// 273.15_K
	LITERAL(kg,   kilogram);		// 10_kg
	LITERAL(kHz,  kilohertz);		// 700_kHz
	LITERAL(km,   kilometer);		// 1.2_km
	LITERAL(kmh,  kilometers_per_hour);	// 100_kmh
	LITERAL(kn,   knots);			// 60_kn
	LITERAL(m,    meter);			// 1_m
	LITERAL(min,  minute);			// 60_min
	LITERAL(MHz,  megahertz);		// 128_MHz
	LITERAL(mm,   millimeter);		// 10_mm
	LITERAL(mph,  miles_per_hour);		// 50_mph
	LITERAL(mps,  meters_per_second);	// 10_mps
	LITERAL(mps2, meters_per_second2);	// 9.807_mps2
	LITERAL(NM,   nautical_mile);		// 1_NM
	LITERAL(s,    second);			// 60_s
	LITERAL(sec,  second);			// 60_sec
	LITERAL(N,    newton);			// 5.0_N
	LITERAL(Nm,   newtonmeter);		// 2.1_Nm
}

#undef LITERAL
