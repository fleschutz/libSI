// Literals for comfort, e.g. 12_km (requires C++11 or higher)
#pragma once

#include "types.hpp"

#define MAP(_symbol, _factor, _baseUnit) \
 constexpr auto operator "" _ ## _symbol(long double x) { return _baseUnit(static_cast<double>(x) * _factor); } \
 constexpr auto operator "" _ ## _symbol(unsigned long long x) { return _baseUnit(static_cast<double>(x) * _factor); }

namespace si
{
	// Symbol: #: Base Unit:            Example: (sorted alphabetically)
	//MAP( A,  1, ampere);              // 5_A
	MAP( cm,   .01, meter);             // 9_cm 
	MAP( deg,  1, degree);              // 90_deg
	MAP( degC, 1, celsius);             // 0_degC
	MAP( degF, 1, fahrenheit);          // 32_degF
	MAP( dm,   .1, meter);              // 7_dm
	MAP( ft,   1, feet);                // 10_ft
	MAP( GHz,  1, gigahertz);           // 18_GHz
	MAP( h,    1, hour);                // 24_h
	MAP( J,    1, joule);               // 1_J
	MAP( K,    1, kelvin);              // 100_K
	MAP( kg,   1, kilogram);            // 10_kg
	MAP( kHz,  1000, hertz);            // 700_kHz
	MAP( km,   1000, meter);	     // 1.2_km
	MAP( kmh,  1, kilometers_per_hour); // 100_kmh
	MAP( kn,   1, knots);               // 60_kn
	MAP( m,    1, meter);               // 1_m
	MAP( Mach, 330, meters_per_second); // 6_Mach
	MAP( min,  60, second);             // 5_min
	MAP( MHz,  1000000, hertz);         // 128_MHz
	MAP( mm,   .001, meter);            // 4_mm
	MAP( mph,  .44704, meters_per_second); // 50_mph
	MAP( mps,  1, meters_per_second);   // 10_mps
	MAP( mps2, 1, meters_per_second2);  // 9.807_mps2
	MAP( NM,   1852, meter);            // 1_NM
	MAP( nmi,  1852, meter);            // 1_nmi
	MAP( s,    1, second);              // 60_s
	MAP( sec,  1, second);              // 60_sec
	MAP( N,    1, newton);              // 5.0_N
	MAP( Nm,   1, newtonmeter);         // 2.1_Nm
}

#undef MAP
