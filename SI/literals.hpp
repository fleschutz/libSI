// SI/literals.hpp - contains literals, e.g. 12_km (requires C++11 or higher)
#pragma once

#include "types.hpp"

namespace si
{
#define MAP(_symbol, _factor, _baseUnit) \
  constexpr auto operator "" _ ## _symbol(long double x) { return _baseUnit(static_cast<double>(x) * _factor); } \
  constexpr auto operator "" _ ## _symbol(unsigned long long x) { return _baseUnit(static_cast<double>(x) * _factor); }

// SI BASE UNITS
// Symbol: Factor: Base Unit:            Example: (sorted alphabetically)
MAP( A,     1,     ampere);              // 5_A 
MAP( Bq,    1,     hertz);               // 100_Bq (Bequerel)
MAP( cm,    .01,   meter);               // 9_cm 
MAP( day,   24*3600,second);             // 1_day
MAP( deg,   1,     degree);              // 90_deg
MAP( dm,    .1,    meter);               // 7_dm
MAP( GHz,   1000000000, hertz);          // 1.3 GHz
MAP( h,     3600,  second);              // 24_h
MAP( Hz,    1,     hertz);               // 4_Hz
MAP( J,     1,     joule);               // 1_J
MAP( K,     1,     kelvin);              // 100_K
MAP( kBq,   1000,  hertz);               // 2_kBq
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
MAP( week,  7*24*3600,second);           // 1_week

// SI DERIVED UNITS
// Symbol: Factor: Base Unit:            Example: 
MAP( ha,    10000, meter2);              // 3_ha
MAP( kA,    1000,  ampere);              // 1_kA
MAP( km2,   1,     kilometer2);	         // 7_km2
MAP( mA,    .001,  ampere);              // 5_mA 

// DIGITAL UNITS
// Symbol: Factor: Base Unit:            Example:
MAP( byte,    1,   byte);                // 1_byte
MAP( kB,    1e3,   byte);                // 1_kB (kilobyte)
MAP( MB,    1e6,   byte);                // 2_MB (megabyte)
MAP( GB,    1e9,   byte);                // 3_GB (gigabyte)
MAP( TB,   1e12,   byte);                // 4_TB (terabyte)
MAP( PB,   1e15,   byte);                // 5_PB (terabyte)
MAP( EB,   1e18,   byte);                // 6_EB (exabyte)
MAP( ZB,   1e21,   byte);                // 7_ZB (zettabyte)
MAP( YB,   1e24,   byte);                // 8_YB (yottabyte)
MAP( RB,   1e27,   byte);                // 9_RB (ronnabyte)
MAP( QB,   1e30,   byte);                // 10_QB (ronnabyte)

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

// VARIOUS UNITS
MAP( degC,  1,     celsius);             // 0_degC
MAP( Mach,  330,   meters_per_second);   // 6_Mach

#undef MAP
}
