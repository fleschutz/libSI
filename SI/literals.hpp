// literals.hpp - Supports convenient literals, e.g. 12_km
// (requires C++11 or higher, all are mapped to the 7 base SI units)
#pragma once

#include "types.hpp"

#define MAP(_symbol, _factor, _baseUnit) \
 constexpr auto operator "" _ ## _symbol(long double x) { return _baseUnit(static_cast<double>(x) * _factor); } \
 constexpr auto operator "" _ ## _symbol(unsigned long long x) { return _baseUnit(static_cast<double>(x) * _factor); }

namespace si
{
// SI UNITS
// Symbol: Factor: Base Unit:            Example: (sorted alphabetically)
MAP( cm,    .01,   meter);               // 9_cm 
MAP( deg,   1,     degree);              // 90_deg
MAP( dm,    .1,    meter);               // 7_dm
MAP( GHz,   1000000000, hertz);          // 1.3 GHz
MAP( h,     3600,  second);              // 24_h
MAP( Hz,    1,     hertz);               // 4_Hz
MAP( J,     1,     joule);               // 1_J
MAP( K,     1,     kelvin);              // 100_K
MAP( kg,    1,     kilogram);            // 10_kg
MAP( kHz,   1000,  hertz);               // 700_kHz
MAP( km,    1000,  meter);	         // 1.2_km
MAP( kmh,   3.6,   meters_per_second);   // 30_kmh
MAP( m,     1,     meter);               // 1_m
MAP( meter, 1,     meter);               // 1_meter
MAP( min,   60,    second);              // 5_min
MAP( MHz,   1000000, hertz);             // 128_MHz
MAP( mm,    .001,  meter);               // 4_mm
MAP( mps,   1,     meters_per_second);   // 10_mps
MAP( mps2,  1,     meters_per_second2);  // 9.807_mps2
MAP( ms,    .001,  second);              // 1_ms
MAP( s,     1,     second);              // 60_s
MAP( sec,   1,     second);              // 60_sec
MAP( second,1,     second);              // 60_second
MAP( N,     1,     newton);              // 5.0_N
MAP( Nm,    1,     newtonmeter);         // 2.1_Nm

// DIGITAL UNITS

// IMPERIAL UNITS
// Symbol: Factor: Base Unit:            Example: (sorted alphabetically)
MAP( degF,  1,     fahrenheit);          // 32_degF
MAP( degR,  5/9,   kelvin);              // 60_degR
MAP( ft,    .3048, meter);               // 5_ft
MAP( in,    0.0254,meter);               // 9_in
MAP( kn,    1'852.0, kilometers_per_hour); // 60_kn
MAP( kt,    1'852.0, kilometers_per_hour); // 10_kt
MAP( lb,    453.592'37, gram);		 // 6_lb
MAP( oz,    28.349'523'125, gram);       // 13_oz
MAP( mi,    1'609.344, meter);           // 8_mi
MAP( mph,   .44704,meters_per_second);   // 50_mph
MAP( NM,    1852,  meter);               // 1_NM
MAP( nmi,   1852,  meter);               // 1_nmi
MAP( yd,    .9144, meter);               // 3_yd

MAP( degC,  1,     celsius);             // 0_degC
MAP( Mach,  330,   meters_per_second);   // 6_Mach

	void test_literals(); // Unit tests (in SI/test_literals.cpp)
}

#undef MAP
