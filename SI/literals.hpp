// literals.hpp - Supports convenient literals, e.g. 12_km (requires C++11 or higher)
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
					 //
					 //
#define BYTE(_symbol, _factor, _baseUnit) \
 constexpr auto operator "" _ ## _symbol(unsigned long long x) { return _baseUnit(static_cast<byte>(_factor) * static_cast<byte>(x)); }

// DIGITAL UNITS
// Symbol: Factor: Base Unit:            Example:
BYTE( byte,   1,   byte);                // 1_byte
BYTE( kB,   1e3,   byte);                // 1_kB (kilobyte)
BYTE( MB,   1e6,   byte);                // 2_MB (megabyte)
BYTE( GB,   1e9,   byte);                // 3_GB (gigabyte)
BYTE( TB,  1e12,   byte);                // 4_TB (terabyte)
BYTE( PB,  1e15,   byte);                // 5_PB (terabyte)
BYTE( EB,  1e18,   byte);                // 6_EB (exabyte)
BYTE( ZB,  1e21,   byte);                // 7_ZB (zettabyte)
BYTE( YB,  1e24,   byte);                // 8_YB (yottabyte)
BYTE( RB,  1e27,   byte);                // 9_RB (ronnabyte)
BYTE( QB,  1e30,   byte);                // 10_QB (ronnabyte)
}
#undef BYTE
#undef MAP
