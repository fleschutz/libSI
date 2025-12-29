// SI/literals.h - type-safe literals, e.g. 7_km (requires C++11 or higher)
#pragma once

#include "units.h"

namespace SI
{
#define LITERAL(_symbol, _factor, _baseUnit) \
  constexpr auto operator "" _ ## _symbol(long double x) { return _baseUnit(static_cast<double_t>(x) * static_cast<double_t>(_factor)); } \
  constexpr auto operator "" _ ## _symbol(unsigned long long x) { return _baseUnit(static_cast<double_t>(x) * static_cast<double_t>(_factor)); }

// THE 7 SI BASE UNITS
// -------------------
// SYMBOL     FACTOR  BASE UNIT                EXAMPLE      
// Length in...                                     (sorted from big to small)
LITERAL( Mm,     1e6, meter);               // 1_Mm (megameter)
LITERAL( km,     1e3, meter);               // 1_km (kilometer)
LITERAL( m,        1, meter);               // 1_m
LITERAL( meter,    1, meter);               // 1_meter
LITERAL( dm,    1e-1, meter);               // 1_dm (decimeter)
LITERAL( cm,    1e-2, meter);               // 1_cm (centimeter)
LITERAL( mm,    1e-3, meter);               // 1_mm (millimeter)
LITERAL( μm,    1e-6, meter);               // 1_μm (micrometer)
// Time in...
LITERAL( h,     3600, second);              // 1_h   (hour)
LITERAL( min,     60, second);              // 1_min (minute)
LITERAL( s,        1, second);              // 1_s   (second)
LITERAL( sec,      1, second);              // 1_sec
LITERAL( second,   1, second);              // 1_second
LITERAL( ms,    1e-3, second);              // 1_ms  (millisecond)
LITERAL( μs,    1e-6, second);              // 1_μs  (microsecond)
// Mass in...
LITERAL( mt,     1e9, kilogram);            // 1_mt (megaton)
LITERAL( kt,     1e6, kilogram);            // 1_kt (kiloton)
LITERAL( t,      1e3, kilogram);            // 1_t (metric ton)
LITERAL( kg,       1, kilogram);            // 1_kg
LITERAL( g,     1e-3, kilogram);            // 1_g (gram)
LITERAL( mg,    1e-6, kilogram);            // 1_mg (milligram)
LITERAL( μg,    1e-9, kilogram);            // 1_μg (microgram)
// Thermodynamic temperature in...
LITERAL( GK,     1e9, kelvin);              // 1_GK (gigakelvin)
LITERAL( MK,     1e6, kelvin);              // 1_MK (megakelvin)
LITERAL( kK,     1e3, kelvin);              // 1_kK (kilokelvin)
LITERAL( K,        1, kelvin);              // 1_K
LITERAL( mK,    1e-3, kelvin);              // 1_mK (millikelvin)
LITERAL( μK,    1e-6, kelvin);              // 1_μK (microkelvin)
LITERAL( nK,    1e-9, kelvin);              // 1_nK (nanokelvin)
// Electric current (I) in...
LITERAL( MA,     1e6, ampere);              // 1_MA  (megaampere)
LITERAL( kA,     1e3, ampere);              // 1_kA  (kiloampere)
LITERAL( A,        1, ampere);              // 1_A 
LITERAL( mA,    1e-3, ampere);              // 1_mA  (milliampere)
LITERAL( μA,    1e-6, ampere);              // 1_μA (microampere)
LITERAL( nA,    1e-9, ampere);              // 1_nA  (nanoampere)
LITERAL( pA,   1e-12, ampere);              // 1_pA  (picoampere)
// Amount of substance (N_A) in...
LITERAL( mol,      1, mol);                // 1_mol 
// Luminous intensity in...
LITERAL( cd,       1, candela);             // 1_cd

// THE 22 DERIVED SI UNITS
// -----------------------
// SYMBOL     FACTOR  BASE UNIT                EXAMPLE
// Area in...
LITERAL( km²,    1e6, meter2);              // 1_km² (square kilometer)
LITERAL( hm²,    1e4, meter2);              // 1_hm² (hectare)
LITERAL( m²,       1, meter2);              // 1_m²  (square meter)
LITERAL( cm²,   1e-4, meter2);              // 1_cm² (square centimeter)
LITERAL( mm²,   1e-6, meter2);              // 1_mm² (square millimeter)
LITERAL( μm²,   1e-9, meter2);              // 1_μm² (square micrometer)
// Volume in...
LITERAL( km³,    1e9, meter3);              // 1_km³ (cubic kilometer)
LITERAL( m³,       1, meter3);              // 1_m³  (cubic meter)
LITERAL( dm³,   1e-3, meter3);              // 1_dm³ (cubic decimeter)
LITERAL( cm³,   1e-6, meter3);              // 1_cm³ (cubic centimeter)
LITERAL( mm³,   1e-9, meter3);              // 1_mm³ (cubic millimeter)
LITERAL( μm³,  1e-12, meter3);              // 1_μm³ (cubic micrometer)
LITERAL( l,     1e-3, meter3);              // 1_l   (liter)
LITERAL( ml,    1e-6, meter3);              // 1_ml  (milliliter)
LITERAL( μl,    1e-9, meter3);              // 1_μl  (microliter)
// Velocity (v) in...
LITERAL( km_per_h, 1, kilometers_per_hour); // 1_km_per_h (km/h)
LITERAL( m_per_s,  1, meters_per_second);   // 1_m_per_s (m/s)
LITERAL( mm_per_h, 1, millimeters_per_hour);// 1_mm_per_h (mm/h)
// Acceleration (a) in...
LITERAL( m_per_s², 1, meters_per_second2);  // 1_m_per_s² (m/s²)
// Frequency (f) in...
LITERAL( THz,   1e12, hertz);               // 1_THz (terahertz)
LITERAL( GHz,    1e9, hertz);               // 1_GHz (gigahertz)
LITERAL( MHz,    1e6, hertz);               // 1_MHz (megahertz)
LITERAL( kHz,    1e3, hertz);               // 1_kHz (kilohertz)
LITERAL( Hz,       1, hertz);               // 1_Hz  (hertz)
// Radioactivity (A) in...
LITERAL( kBq,    1e3, hertz);               // 1_kBq
LITERAL( Bq,       1, hertz);               // 1_Bq (Bequerel)
// Mass per area in...
LITERAL( t_per_m², 1e3, kilograms_per_meter2);// 1_t_per_m²
LITERAL( kg_per_m²,  1, kilograms_per_meter2);// 1_kg_per_m²
// Mass per volume in...
LITERAL( kg_per_m³,  1, kilograms_per_meter3);// 1_kg_per_m³
LITERAL( t_per_m³, 1e3, kilograms_per_meter3);// 1_t_per_m³
// Electric potential (U) in...
LITERAL( GV,     1e9, volt);                // 1_GV (gigavolt)
LITERAL( MV,     1e6, volt);                // 1_MV (megavolt)
LITERAL( kV,     1e3, volt);                // 1_kV (kilovolt)
LITERAL( V,        1, volt);                // 1_V 
LITERAL( mV,    1e-3, volt);                // 1_mV (millivolt)
LITERAL( μV,    1e-6, volt);                // 1_μV (microvolt)
LITERAL( nV,    1e-9, volt);                // 1_nV (nanovolt)
LITERAL( pV,   1e-12, volt);                // 1_pV (picovolt)
// Electric resistance (R) in...
LITERAL( GOhm,   1e9, ohm);                 // 1_GOhm (gigaohm)
LITERAL( MOhm,   1e6, ohm);                 // 1_MOhm (megaohm)
LITERAL( kOhm,   1e3, ohm);                 // 1_kOhm (kiloohm)
LITERAL( Ohm,      1, ohm);                 // 1_Ohm
LITERAL( mOhm,  1e-3, ohm);                 // 1_mOhm (milliohm)
LITERAL( μOhm,  1e-6, ohm);                 // 1_μOhm (microohm)
// Electric resistance meter in...
LITERAL( Ohm_m,    1, ohm_meter);           // 1_Ohm_m (ohm meter)
// Electric conductance (G) in...
LITERAL( kS,     1e3, siemens);             // 1_kS   (kilosiemens)
LITERAL( S,        1, siemens);             // 1_S    (siemens)
LITERAL( mS,    1e-3, siemens);             // 1_mS   (millisiemens)
LITERAL( μS,    1e-6, siemens);             // 1_μS   (microsiemens)
// Electric conductivity (σ) in...
LITERAL( MS_per_m,1e6, siemens_per_meter);  // 1_MS_per_m (MS/m, megasiemens per meter)
LITERAL( kS_per_m,1e3, siemens_per_meter);  // 1_kS_per_m (kS/m, kilosiemens per meter)
LITERAL( S_per_m,  1, siemens_per_meter);   // 1_S_per_m (S/m, siemens per meter)
// Electric charge (Q) in...
LITERAL( C,        1, coulomb);             // 1_C   (coulomb)
LITERAL( Ah,       1, ampere_hours);        // 1_Ah  (ampere-hours)
LITERAL( mAh,   1e-3, ampere_hours);        // 1_mAh (milliampere-hours)
// Electric capacitance (C) in...
LITERAL( F,        1, farad);               // 1_F   (farad)
LITERAL( mF,    1e-3, farad);               // 1_mF  (millifarad)
LITERAL( μF,    1e-6, farad);               // 1_μF  (microfarad)
LITERAL( nF,    1e-9, farad);               // 1_nF  (nanofarad)
LITERAL( pF,   1e-12, farad);               // 1_pF  (picofarad)
// Electric inductance (L) in...
LITERAL( H,        1, henry);               // 1_H   (henry)
LITERAL( mH,    1e-3, henry);               // 1_mH  (millihenry)
LITERAL( μH,    1e-6, henry);               // 1_μH  (microhenry)
// Magnetic flux in...
LITERAL( Wb,       1, weber);               // 1_Wb  (weber)
// Magnetic field (B) in...
LITERAL( T,        1, tesla);               // 1_T  (tesla)
LITERAL( mT,    1e-3, tesla);               // 1_mT (millitesla)
LITERAL( μT,    1e-6, tesla);               // 1_μT (microtesla)
LITERAL( nT,    1e-9, tesla);               // 1_nT (nanotesla)
// Energy (E) in...
LITERAL( TJ,    1e12, joule);               // 1_TJ  (terajoule)
LITERAL( GJ,     1e9, joule);               // 1_GJ  (gigajoule)
LITERAL( MJ,     1e6, joule);               // 1_MJ  (megajoule)
LITERAL( kJ,     1e3, joule);               // 1_kJ  (kilojoule)
LITERAL( J,        1, joule);               // 1_J   (joule)
LITERAL( cal, 4.1868, joule);               // 1_cal (calorie)
LITERAL( kcal,4186.8, joule);               // 1_kcal (kilocalorie)
// Active power (P) in...
LITERAL( TW,    1e12, watt);                // 1_TW  (terawatt)
LITERAL( GW,     1e9, watt);                // 1_GW  (gigawatt)
LITERAL( MW,     1e6, watt);                // 1_MW  (megawatt)
LITERAL( kW,     1e3, watt);                // 1_kW  (kilowatt)
LITERAL( W,        1, watt);                // 1_W   (Watt)
LITERAL( mW,    1e-3, watt);                // 1_mW  (milliwatt)
LITERAL( μW,    1e-6, watt);                // 1_μW  (microwatt)
LITERAL( TWh, 3.6e15, watt);                // 1_TWh (terawatt-hour)
LITERAL( GWh, 3.6e12, watt);                // 1_GWh (gigawatt-hour)
LITERAL( MWh,  3.6e9, watt);                // 1_MWh (megawatt-hour)
LITERAL( kWh,  3.6e6, watt);                // 1_kWh (kilowatt-hour)
LITERAL( Wh,   3.6e3, watt);                // 1_Wh  (watt-hour)
LITERAL( hp, 745.69987158227022, watt);     // 1_hp  (horsepower)
LITERAL( PS, 735.49875, watt);              // 1_PS  ('Pferdestärke', german horsepower)
// Active power per mass in...
LITERAL( kWh_per_kg, 3.6e6, joules_per_second_per_kilogram);  // 1_kWh_per_kg (kilowatt-hour per kilogram)
LITERAL( Wh_per_kg,  3.6e3, joules_per_second_per_kilogram);  // 1_Wh_per_kg (watt-hour per kilogram)
// Equivalent dose (H) in...
LITERAL( Sv,       1, sievert);             // 1_Sv  (sievert)
LITERAL( mSv,   1e-3, sievert);             // 1_mSv (millisievert)
LITERAL( μSv,   1e-6, sievert);             // 1_μSv (microsievert)
// Absorbed dose (D) in...
LITERAL( Gy,       1, gray);                // 1_Gy (gray)
// Pressure (p) in...
LITERAL( MPa,    1e6, pascal_);             // 1_MPa  (megapascal) 
LITERAL( kPa,    1e3, pascal_);             // 1_kPa  (kilopascal) 
LITERAL( hPa,    1e2, pascal_);             // 1_hPa  (hectopascal) 
LITERAL( Pa,       1, pascal_);             // 1_Pa   (pascal) 
LITERAL( at,98'066.5, pascal_);             // 1_at   (atmosphere)
LITERAL( bar,    1e5, pascal_);             // 1_bar 
LITERAL( mmHg,133.3224, pascal_);           // 1_mmHg (millimeter mercury)
// Force (F) in...
LITERAL( GN,     1e9, newton);              // 1_GN (giganewton)
LITERAL( MN,     1e6, newton);              // 1_MN (meganewton)
LITERAL( kN,     1e3, newton);              // 1_kN (kilonewton)
LITERAL( N,        1, newton);              // 1_N
LITERAL( mN,    1e-3, newton);              // 1_mN (millinewton)
LITERAL( μN,    1e-6, newton);              // 1_μN (micronewton)
// Luminous flux (m) in...
LITERAL( lm,       1, lumen);               // 1_lm (lumen)
LITERAL( lm_s,     1, lumen_second);        // 1_lm_s (lumen second)
LITERAL( lm_per_W, 1, lumens_per_watt);     // 1_lm_per_W (lumen per watt)
// Surface flow (s) in...
LITERAL( m²_per_s, 1, meter2_per_second);   // 1_m²/s (square meter per second)
// Volumetric flow (V) in...
LITERAL( m³_per_s, 1, meter3_per_second);   // 1_m³/s (cubic meter per second)
					   
LITERAL( Nm,       1, newtonmeter);         // 1_Nm  (newtonmeter)
LITERAL( W_per_m², 1, watt_per_meter2);     // 1_W/m² (watt per square metre)

#define CARDINAL(_symbol, _factor, _baseUnit) \
  constexpr auto operator "" _ ## _symbol(unsigned long long x) { return _baseUnit(static_cast<long long>(x) * _factor); }

// NON-SI UNITS
// ------------
//       SYMBOL           FACTOR                  BASE UNIT   EXAMPLE
// astronomical distances in...
LITERAL( Mly,        9'460'730'472'580'800 * 1e6, meter);  // 1_Mly (megalight-year)
LITERAL( ly,               9'460'730'472'580'800, meter);  // 1_ly (light-year)
LITERAL( au,                     149'597'870'700, meter);  // 1_au (astronomical unit)
LITERAL( pc,              30'856'775'814'913'700, meter);  // 1_pc (parsec)
// Imperial units in...
LITERAL( degF,                                 1, fahrenheit); // 1_degF (°Fahrenheit)
LITERAL( ft,                               .3048, meter);  // 1_ft (feet)
LITERAL( in,                              0.0254, meter);  // 1_in (inch)
LITERAL( kn,                               1.852, kilometers_per_hour); // 1_kn (knots)
LITERAL( lb,                          453.592'37, gram);   // 1_lb
LITERAL( oz,                      28.349'523'125, gram);   // 1_oz
LITERAL( mi,                           1'609.344, meter);  // 1_mi (statute mile)
LITERAL( mph,                             .44704, meters_per_second); // 1_mph (miles per hour)
LITERAL( NM,                               1'852, meter);  // 1_NM (nautical mile)
LITERAL( nmi,                              1'852, meter);  // 1_nmi (nautical mile)
LITERAL( yd,                               .9144, meter);  // 1_yd (yard)
// digital units in...
CARDINAL( byte,                               1, byte);    // 1_byte
CARDINAL( kB,                               1e3, byte);    // 1_kB (kilobyte)
CARDINAL( MB,                               1e6, byte);    // 1_MB (megabyte)
CARDINAL( GB,                               1e9, byte);    // 1_GB (gigabyte)
CARDINAL( TB,                              1e12, byte);    // 1_TB (terabyte)
CARDINAL( PB,                              1e15, byte);    // 1_PB (terabyte)
CARDINAL( EB,                              1e18, byte);    // 1_EB (exabyte)
CARDINAL( ZB,                              1e21, byte);    // 1_ZB (zettabyte)
CARDINAL( YB,                              1e24, byte);    // 1_ZY (yottabyte)
CARDINAL( RB,                              1e27, byte);    // 1_RY (ronnabyte)
CARDINAL( QB,                              1e30, byte);    // 1_QY (quettabyte)
LITERAL( KBps,                              1e3, bytes_per_second); // 1_KBps (kilobyte/sec)
LITERAL( MBps,                              1e6, bytes_per_second); // 1_MBps (megabyte/sec)
LITERAL( GBps,                              1e9, bytes_per_second); // 1_GBps (gigabyte/sec)
LITERAL( TBps,                             1e12, bytes_per_second); // 1_TBps (terabyte/sec)
LITERAL( Kbps,                          1e3 / 8, bytes_per_second); // 1_Kbps (kilobit/sec)
LITERAL( Mbps,                          1e6 / 8, bytes_per_second); // 1_Mbps (megabit/sec)
LITERAL( Gbps,                          1e9 / 8, bytes_per_second); // 1_Gbps (gigabit/sec)
LITERAL( Tbps,                         1e12 / 8, bytes_per_second); // 1_Tbps (terabit/sec)
// various units in...
LITERAL( rad,                                 1, radian); // 1_rad (radian)
LITERAL( deg,0.01745329251994329576923690768489, radian); // 1_deg  (angle degree)
LITERAL( sr,                                  1, steradian);// 1_sr  (steradian)
LITERAL( degC,                                1, celsius);// 1_degC (°Celsius)
LITERAL( degR,                          5.0/9.0, kelvin); // 1_degR (°Rankine)
LITERAL( Mach,                              330, meters_per_second); // 1_Mach
LITERAL( Da,                1.6605390689252e-27, kilogram);//1_Da (dalton)
LITERAL( eV,                    1.602176634e-19, joule);  // 1_eV (electronvolt)

#undef LITERAL
#undef CARDINAL
}
