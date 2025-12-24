// SI/literals.h - type-safe literals, e.g. 12_km (requires C++11 or higher)
#pragma once

#include "units.h"

namespace si
{
#define LITERAL(_symbol, _factor, _baseUnit) \
  constexpr auto operator "" _ ## _symbol(long double x) { return _baseUnit(static_cast<double>(x) * static_cast<double>(_factor)); } \
  constexpr auto operator "" _ ## _symbol(unsigned long long x) { return _baseUnit(static_cast<double>(x) * _factor); }
#define CARDINAL(_symbol, _factor, _baseUnit) \
  constexpr auto operator "" _ ## _symbol(unsigned long long x) { return _baseUnit(static_cast<long long>(x) * _factor); }

// THE 7 SI BASE UNITS:
// Symbol:   Factor:  Base Unit:            Example:
// length in...
LITERAL( km,     1e3, meter);               // 1_km (kilometer)
LITERAL( m,        1, meter);               // 1_m
LITERAL( meter,    1, meter);               // 1_meter
LITERAL( dm,    1e-1, meter);               // 1_dm (decimeter)
LITERAL( cm,    1e-2, meter);               // 1_cm (centimeter)
LITERAL( mm,    1e-3, meter);               // 1_mm (millimeter)
LITERAL( μm,    1e-6, meter);               // 1_μm (micrometer)
// time in...
LITERAL( s,        1, second);              // 1_s
LITERAL( sec,      1, second);              // 1_sec
LITERAL( second,   1, second);              // 1_second
LITERAL( ms,    1e-3, second);              // 1_ms (millisecond)
LITERAL( mus,   1e-6, second);              // 1_mus (microsecond)
LITERAL( min,     60, second);              // 1_min
LITERAL( h,     3600, second);              // 1_h
LITERAL( day,24*3600,second);               // 1_day (on Earth)
LITERAL( week,  7*24*3600,second);          // 1_week (on Earth)
LITERAL( year,  365.25*24*3600,second);     // 1_year (on Earth)
// mass in...
LITERAL( mt,     1e9, kilogram);            // 1_mt (megaton)
LITERAL( kt,     1e6, kilogram);            // 1_kt (kiloton)
LITERAL( t,      1e3, kilogram);            // 1_t (metric ton)
LITERAL( kg,       1, kilogram);            // 1_kg
LITERAL( g,     1e-3, kilogram);            // 1_g (gram)
LITERAL( mg,    1e-6, kilogram);            // 1_mg (milligram)
LITERAL( mug,   1e-9, kilogram);            // 1_mug (microgram)
// temperature in...
LITERAL( GK,     1e9, kelvin);              // 1_GK (gigakelvin)
LITERAL( MK,     1e6, kelvin);              // 1_MK (megakelvin)
LITERAL( kK,     1e3, kelvin);              // 1_kK (kilokelvin)
LITERAL( K,        1, kelvin);              // 1_K
LITERAL( mK,    1e-3, kelvin);              // 1_mK (millikelvin)
LITERAL( μK,    1e-6, kelvin);              // 1_μK (microkelvin)
LITERAL( nK,    1e-9, kelvin);              // 1_nK (nanokelvin)
// electrical current in...
LITERAL( MA,     1e6, ampere);              // 1_MA (megaampere)
LITERAL( kA,     1e3, ampere);              // 1_kA (kiloampere)
LITERAL( A,        1, ampere);              // 1_A 
LITERAL( mA,    1e-3, ampere);              // 1_mA (milliampere)
LITERAL( muA,   1e-6, ampere);              // 1_muA (microampere)
LITERAL( nA,    1e-9, ampere);              // 1_nA (nanoampere)
LITERAL( pA,   1e-12, ampere);              // 1_pA (picoampere)
//...

// THE 22 SI DERIVED UNITS
//    Symbol: Factor: Base Unit:            Example:
// area in...
LITERAL( km²,    1e6, meter2);              // 1_km² (square kilometer)
LITERAL( m²,       1, meter2);              // 1_m²  (square meter)
LITERAL( cm²,   1e-4, meter2);              // 1_cm² (square centimeter)
LITERAL( mm²,   1e-6, meter2);              // 1_mm² (square millimeter)
LITERAL( ha,   10000, meter2);              // 1_ha
// volume in...
LITERAL( km³,    1e9, meter3);              // 1_km³ (cubic kilometer)
LITERAL( m³,       1, meter3);              // 1_m³  (cubic meter)
LITERAL( dm³,   1e-3, meter3);              // 1_dm³ (cubic decimeter)
LITERAL( cm³,   1e-6, meter3);              // 1_cm³ (cubic centimeter)
LITERAL( mm³,   1e-9, meter3);              // 1_mm³ (cubic millimeter)
LITERAL( l,     1e-3, meter3);              // 1_l  (liter)
LITERAL( ml,    1e-6, meter3);              // 1_ml (milliliter)
LITERAL( μl,    1e-9, meter3);              // 1_μl (microliter)
// speed in...
LITERAL( kmh,      1, kilometers_per_hour); // 1_kmh
LITERAL( mmh,      1, millimeters_per_hour);// 1_mmh
LITERAL( mps,      1, meters_per_second);   // 1_mps
// acceleration in...
LITERAL( mps²,     1, meters_per_second2);  // 1_mps²
// frequency in...
LITERAL( Hz,       1, hertz);               // 1_Hz
LITERAL( kHz,    1e3, hertz);               // 1_kHz
LITERAL( MHz,    1e6, hertz);               // 1_MHz
LITERAL( GHz,    1e9, hertz);               // 1_GHz
LITERAL( THz,   1e12, hertz);               // 1_THz
LITERAL( Bq,       1, hertz);               // 1_Bq (Bequerel)
LITERAL( kBq,   1000, hertz);               // 1_kBq
// eletrical potential in...
LITERAL( V,        1, volt);                // 1_V 
LITERAL( kV,     1e3, volt);                // 1_kV (kilovolt)
LITERAL( MV,     1e6, volt);                // 1_MV (megavolt)
LITERAL( mV,    1e-3, volt);                // 1_mV (millivolt)
LITERAL( muV,   1e-6, volt);                // 1_muV (microvolt)
LITERAL( nV,    1e-9, volt);                // 1_nV (nanovolt)
LITERAL( pV,   1e-12, volt);                // 1_pV (picovolt)
// electrical resistance in...
LITERAL( Ohm,      1, ohm);                // 1_Ohm
LITERAL( kOhm,   1e3, ohm);                // 1_kOhm (kiloohm)
LITERAL( MOhm,   1e6, ohm);                // 1_MOhm (megaohm)
LITERAL( mOhm,  1e-3, ohm);                // 1_mOhm (milliohm)
// energy in...
LITERAL( TJ,    1e12, joule);              // 1_TJ (terajoule)
LITERAL( GJ,     1e9, joule);              // 1_GJ (gigajoule)
LITERAL( MJ,     1e6, joule);              // 1_MJ (megajoule)
LITERAL( kJ,     1e3, joule);              // 1_kJ (kilojoule)
LITERAL( J,        1, joule);              // 1_J (joule)

LITERAL( TW,    1e12, watt);               // 1_TW (terawatt)
LITERAL( GW,     1e9, watt);               // 1_GW (gigawatt)
LITERAL( MW,     1e6, watt);               // 1_MW (megawatt)
LITERAL( kW,     1e3, watt);               // 1_kW (kilowatt)
LITERAL( W,        1, watt);               // 1_W (Watt)
LITERAL( mW,    1e-3, watt);               // 1_mW (milliwatt)
LITERAL( muW,   1e-6, watt);               // 1_muW (microwatt)

LITERAL( TWh, 3.6e15, watt);               // 1_TWh (terawatt-hour)
LITERAL( GWh, 3.6e12, watt);               // 1_GWh (gigawatt-hour)
LITERAL( MWh,  3.6e9, watt);               // 1_MWh (megawatt-hour)
LITERAL( kWh,  3.6e6, watt);               // 1_kWh (kilowatt-hour)
LITERAL( Wh,   3.6e3, watt);               // 1_Wh (watt-hour)

LITERAL( kWh_per_kg, 3.6e6, joules_per_second_per_kilogram);  // 1_kWh_per_kg (kilowatt-hour per kilogram)
LITERAL( Wh_per_kg,  3.6e3, joules_per_second_per_kilogram);  // 1_Wh_per_kg (watt-hour per kilogram)

LITERAL( MN,     1e6, newton);             // 1_MN (meganewton)
LITERAL( kN,     1e3, newton);             // 1_kN (kilonewton)
LITERAL( N,        1, newton);             // 1_N
	
LITERAL( Nm,       1, newtonmeter);         // 1_Nm

LITERAL( kg_per_m²,  1, kilograms_per_meter2);// 1_kg_per_m²
LITERAL( kg_per_m³,  1, kilograms_per_meter3);// 1_kg_per_m³
LITERAL( t_per_m³, 1e3, kilograms_per_meter3);// 1_t_per_m³

LITERAL( deg,      1, degree);              // 1_deg

// astronomical units in...
LITERAL( ly, 9'460'730'777'119'564, meter); // 1_ly (light-year)
LITERAL( AU, 149'597'870'691, meter);       // 1_AU (astronomical unit)
LITERAL( pc, 30'856'775'814'913'700, meter);// 1_pc (parsec)
//...

// IMPERIAL UNITS
//     Symbol: Factor: Base Unit:          Example:
LITERAL( degF,            1, fahrenheit);  // 1_degF (°Fahrenheit)
LITERAL( ft,          .3048, meter);       // 1_ft
LITERAL( in,         0.0254, meter);       // 1_in
LITERAL( kn,          1.852, kilometers_per_hour); // 1_kn
LITERAL( lb,     453.592'37, gram);        // 1_lb
LITERAL( oz, 28.349'523'125, gram);        // 1_oz
LITERAL( mi,      1'609.344, meter);       // 1_mi
LITERAL( mph,        .44704, meters_per_second); // 1_mph
LITERAL( NM,          1'852, meter);       // 1_NM (nautical mile)
LITERAL( nmi,         1'852, meter);       // 1_nmi (nautical mile)
LITERAL( yd,          .9144, meter);       // 1_yd (yard)

// VARIOUS UNITS
//     Symbol: Factor: Base Unit:           Example:
LITERAL( degC,    1,   celsius);            // 1_degC (°Celsius)
LITERAL( degR, 5.0/9.0,kelvin);             // 1_degR (°Rankine)
LITERAL( Mach,  330,   meters_per_second);  // 1_Mach

CARDINAL( byte,    1, byte);                // 1_byte
CARDINAL( kB,    1e3, byte);                // 1_kB (kilobyte)
CARDINAL( MB,    1e6, byte);                // 1_MB (megabyte)
CARDINAL( GB,    1e9, byte);                // 1_GB (gigabyte)
CARDINAL( TB,   1e12, byte);                // 1_TB (terabyte)
CARDINAL( PB,   1e15, byte);                // 1_PB (terabyte)
CARDINAL( EB,   1e18, byte);                // 1_EB (exabyte)
CARDINAL( ZB,   1e21, byte);                // 1_ZB (zettabyte)
CARDINAL( YB,   1e24, byte);                // 1_ZY (yottabyte)
CARDINAL( RB,   1e27, byte);                // 1_RY (ronnabyte)
CARDINAL( QB,   1e30, byte);                // 1_QY (quettabyte)

LITERAL( KBps,   1e3, bytes_per_second);    // 1_KBps (kilobyte/sec)
LITERAL( MBps,   1e6, bytes_per_second);    // 1_MBps (megabyte/sec)
LITERAL( GBps,   1e9, bytes_per_second);    // 1_GBps (gigabyte/sec)
LITERAL( TBps,  1e12, bytes_per_second);    // 1_TBps (terabyte/sec)

LITERAL( Kbps, 1e3/8, bytes_per_second);    // 1_Kbps (kilobit/sec)
LITERAL( Mbps, 1e6/8, bytes_per_second);    // 1_Mbps (megabit/sec)
LITERAL( Gbps, 1e9/8, bytes_per_second);    // 1_Gbps (gigabit/sec)
LITERAL( Tbps,1e12/8, bytes_per_second);    // 1_Tbps (terabit/sec)

#undef LITERAL
#undef CARDINAL
}
