// SI/literals.h - contains type-safe literals, e.g. 12_km (requires C++11 or higher)
#pragma once

#include "units.h"

namespace si
{
#define LITERAL(_symbol, _factor, _baseUnit) \
  constexpr auto operator "" _ ## _symbol(long double x) { return _baseUnit(static_cast<double>(x) * static_cast<double>(_factor)); } \
  constexpr auto operator "" _ ## _symbol(unsigned long long x) { return _baseUnit(static_cast<double>(x) * _factor); }

// THE 7 SI BASE UNITS:
// Symbol:   Factor:  Base Unit:            Example:
LITERAL( m,        1, meter);               // 1_m
LITERAL( meter,    1, meter);               // 2_meter
LITERAL( dm,    1e-1, meter);               // 3_dm (decimeter)
LITERAL( cm,    1e-2, meter);               // 4_cm (centimeter)
LITERAL( mm,    1e-3, meter);               // 5_mm (millimeter)
LITERAL( μm,    1e-6, meter);               // 6_μm (micrometer)
LITERAL( km,     1e3, meter);               // 7_km (kilometer)

LITERAL( s,        1, second);              // 60_s
LITERAL( sec,      1, second);              // 60_sec
LITERAL( second,   1, second);              // 60_second
LITERAL( ms,    1e-3, second);              // 1_ms (millisecond)
LITERAL( μs,    1e-6, second);              // 2_μs (microsecond)
LITERAL( min,     60, second);              // 5_min
LITERAL( h,     3600, second);              // 24_h
LITERAL( day,24*3600,second);               // 1_day on Earth!
LITERAL( week,  7*24*3600,second);          // 1_week on Earth!
LITERAL( year,  365.25*24*3600,second);     // 1_year on Earth!

LITERAL( kg,       1, kilogram);            // 10_kg
LITERAL( g,     1e-3, kilogram);            // 3_g (gram)
LITERAL( mg,    1e-6, kilogram);            // 3_mg (milligram)
LITERAL( μg,    1e-9, kilogram);            // 3_μg (microgram)
LITERAL( t,      1e3, kilogram);            // 7_t (metric ton)

LITERAL( K,        1, kelvin);              // 100_K

LITERAL( A,        1, ampere);              // 1_A 
LITERAL( kA,     1e3, ampere);              // 2_kA (kiloampere)
LITERAL( MA,     1e6, ampere);              // 3_MA (megaampere)
LITERAL( mA,    1e-3, ampere);              // 4_mA (milliampere)
LITERAL( muA,   1e-6, ampere);              // 5_muA (microampere)
LITERAL( nA,    1e-9, ampere);              // 6_nA (nanoampere)
LITERAL( pA,   1e-12, ampere);              // 7_pA (picoampere)

// THE 22 SI DERIVED UNITS
//     Symbol: Factor: Base Unit:           Example: (sorted alphabetically)
LITERAL( Bq,       1, hertz);               // 100_Bq (Bequerel)
LITERAL( deg,      1, degree);              // 90_deg
LITERAL( J,        1, joule);               // 1_J
LITERAL( kBq,   1000, hertz);               // 2_kBq
LITERAL( kmh,      1, kilometers_per_hour); // 30_kmh
LITERAL( mps,      1, meters_per_second);   // 10_mps
LITERAL( mps2,     1, meters_per_second2);  // 9.807_mps2
LITERAL( N,        1, newton);              // 5.0_N
LITERAL( Nm,       1, newtonmeter);         // 2.1_Nm
LITERAL( ha,   10000, meter2);              // 3_ha
LITERAL( km2,      1, kilometer2);	    // 7_km2

LITERAL( Hz,       1, hertz);               // 1_Hz
LITERAL( kHz,    1e3, hertz);               // 2_kHz
LITERAL( MHz,    1e6, hertz);               // 3_MHz
LITERAL( GHz,    1e9, hertz);               // 4_GHz
LITERAL( THz,   1e12, hertz);               // 5_THz

LITERAL( V,        1, volt);                // 1_V 
LITERAL( kV,     1e3, volt);                // 2_kV (kilovolt)
LITERAL( MV,     1e6, volt);                // 3_MV (megavolt)
LITERAL( mV,    1e-3, volt);                // 4_mV (millivolt)
LITERAL( muV,   1e-6, volt);                // 5_muV (microvolt)
LITERAL( nV,    1e-9, volt);                // 6_nV (nanovolt)
LITERAL( pV,   1e-12, volt);                // 7_pV (picovolt)

LITERAL( Ohm,      1, ohm);                // 1_Ohm
LITERAL( kOhm,   1e3, ohm);                // 1_kOhm (kiloohm)
LITERAL( MOhm,   1e6, ohm);                // 1_MOhm (megaohm)
LITERAL( mOhm,  1e-3, ohm);                // 1_mOhm (milliohm)

LITERAL( W,        1, joules_per_second);  // 1_W (Watt)
LITERAL( kW,     1e3, joules_per_second);  // 1_kW (kilowatt)
LITERAL( MW,     1e6, joules_per_second);  // 1_MW (megawatt)
LITERAL( GW,     1e9, joules_per_second);  // 1_GW (gigawatt)
LITERAL( TW,    1e12, joules_per_second);  // 1_TW (terawatt)
LITERAL( mW,    1e-3, joules_per_second);  // 1_mW (milliwatt)

// DIGITAL UNITS
//     Symbol: Factor: Base Unit:           Example: (sorted alphabetically)
LITERAL( byte,     1, byte);                // 1_byte
LITERAL( kB,     1e3, byte);                // 1_kB (kilobyte)
LITERAL( MB,     1e6, byte);                // 2_MB (megabyte)
LITERAL( GB,     1e9, byte);                // 3_GB (gigabyte)
LITERAL( TB,    1e12, byte);                // 4_TB (terabyte)
LITERAL( PB,    1e15, byte);                // 5_PB (terabyte)
LITERAL( EB,    1e18, byte);                // 6_EB (exabyte)
LITERAL( ZB,    1e21, byte);                // 7_ZB (zettabyte)
LITERAL( YB,    1e24, byte);                // 8_ZY (yottabyte)
LITERAL( RB,    1e27, byte);                // 9_RY (ronnabyte)
LITERAL( QB,    1e30, byte);                //10_QY (quettabyte)

LITERAL( KBps,   1e3, bytes_per_second);    // 1_KBps (kilobyte/sec)
LITERAL( MBps,   1e6, bytes_per_second);    // 1_MBps (megabyte/sec)
LITERAL( GBps,   1e9, bytes_per_second);    // 1_GBps (gigabyte/sec)
LITERAL( TBps,  1e12, bytes_per_second);    // 1_TBps (terabyte/sec)

LITERAL( Kbps,  1e3/8, bytes_per_second);    // 1_Kbps (kilobit/sec)
LITERAL( Mbps,  1e6/8, bytes_per_second);    // 1_Mbps (megabit/sec)
LITERAL( Gbps,  1e9/8, bytes_per_second);    // 1_Gbps (gigabit/sec)
LITERAL( Tbps, 1e12/8, bytes_per_second);    // 1_Tbps (terabit/sec)

// IMPERIAL UNITS
//     Symbol: Factor: Base Unit:            Example: (sorted alphabetically)
LITERAL( degF,  1,     fahrenheit);          // 32_degF
LITERAL( degR,  5/9,   kelvin);              // 60_degR
LITERAL( ft,    .3048, meter);               // 5_ft
LITERAL( in,    0.0254,meter);               // 9_in
LITERAL( kn,    1'852.0, kilometers_per_hour); // 60_kn
LITERAL( kt,    1'852.0, kilometers_per_hour); // 10_kt
LITERAL( lb,    453.592'37, gram);           // 6_lb
LITERAL( oz,    28.349'523'125, gram);       // 13_oz
LITERAL( mi,    1'609.344, meter);           // 8_mi
LITERAL( mph,   .44704,meters_per_second);   // 50_mph
LITERAL( NM,    1852,  meter);               // 1_NM (nautical mile)
LITERAL( nmi,   1852,  meter);               // 1_nmi (nautical mile)
LITERAL( yd,    .9144, meter);               // 3_yd (yard)

// VARIOUS UNITS
LITERAL( degC,    1,   celsius);             // 0_degC (degree celsius)
LITERAL( Mach,  330,   meters_per_second);   // 6_Mach
LITERAL( pc,3.2*9460730472580.8, kilometer); // 8_pc (parsec)

#undef LITERAL
}
