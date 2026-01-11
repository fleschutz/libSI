// SI/literals.h - convenient literals for SI units, e.g. 7_km (requires C++11 or higher)
#pragma once

#include "units.h"
#define SET(_symbol, _factor, _baseUnit) \
constexpr auto operator "" _ ## _symbol(long double x) { return _baseUnit(static_cast<double_t>(_factor ## L * x)); } \
constexpr auto operator "" _ ## _symbol(unsigned long long x) { return _baseUnit(static_cast<double_t>(_factor ## L * x)); }

namespace SI {

// The 7 SI Base Units
// -------------------
// SYMBOL FACTOR  BASE UNIT                EXAMPLE  (units sorted from big to small)
// length in...
SET( Gm,     1e9, meter);               // 1_Gm (gigameter)
SET( Mm,     1e6, meter);               // 1_Mm (megameter)
SET( km,     1e3, meter);               // 1_km (kilometer)
SET( m,        1, meter);               // 1_m
SET( meter,    1, meter);               // 1_meter
SET( dm,    1e-1, meter);               // 1_dm (decimeter)
SET( cm,    1e-2, meter);               // 1_cm (centimeter)
SET( mm,    1e-3, meter);               // 1_mm (millimeter)
SET( um,    1e-6, meter);               // 1_um (micrometer)
SET( nm,    1e-9, meter);               // 1_nm (nanometer)
SET( pm,   1e-12, meter);               // 1_pm (picometer)
// time in...
SET( day,  86400, second);              // 1_day (day on Earth)
SET( days, 86400, second);              // 2_days(day on Earth)
SET( h,     3600, second);              // 1_h   (hour)
SET( min,     60, second);              // 1_min (minute)
SET( s,        1, second);              // 1_s   (second)
SET( sec,      1, second);              // 1_sec
SET( second,   1, second);              // 1_second
SET( ms,    1e-3, second);              // 1_ms  (millisecond)
SET( us,    1e-6, second);              // 1_us  (microsecond)
SET( ns,    1e-9, second);              // 1_ns  (nanosecond)
SET( ps,   1e-12, second);              // 1_ps  (picosecond)
// mass in...
SET( Gt,    1e12, kilogram);            // 1_Gt (metric gigaton)
SET( Mt,     1e9, kilogram);            // 1_Mt (metric megaton)
SET( kt,     1e6, kilogram);            // 1_kt (metric kiloton)
SET( t,      1e3, kilogram);            // 1_t  (metric ton)
SET( kg,       1, kilogram);            // 1_kg
SET( g,     1e-3, kilogram);            // 1_g  (gram)
SET( mg,    1e-6, kilogram);            // 1_mg (milligram)
SET( ug,    1e-9, kilogram);            // 1_ug (microgram)
SET( ng,   1e-12, kilogram);            // 1_ng (nanogram)
// thermodynamic temperature in...
SET( GK,     1e9, kelvin);              // 1_GK (gigakelvin)
SET( MK,     1e6, kelvin);              // 1_MK (megakelvin)
SET( kK,     1e3, kelvin);              // 1_kK (kilokelvin)
SET( K,        1, kelvin);              // 1_K
SET( mK,    1e-3, kelvin);              // 1_mK (millikelvin)
SET( uK,    1e-6, kelvin);              // 1_uK (microkelvin)
SET( nK,    1e-9, kelvin);              // 1_nK (nanokelvin)
// electric current (I) in...
SET( GA,     1e9, ampere);              // 1_GA  (gigaampere)
SET( MA,     1e6, ampere);              // 1_MA  (megaampere)
SET( kA,     1e3, ampere);              // 1_kA  (kiloampere)
SET( A,        1, ampere);              // 1_A 
SET( mA,    1e-3, ampere);              // 1_mA  (milliampere)
SET( uA,    1e-6, ampere);              // 1_uA  (microampere)
SET( nA,    1e-9, ampere);              // 1_nA  (nanoampere)
SET( pA,   1e-12, ampere);              // 1_pA  (picoampere)
// amount of substance (N_A) in...
SET( Mmol,   1e6, moles);               // 1_Mmol (megamole)
SET( kmol,   1e3, moles);               // 1_kmol (kilomole)
SET( mol,      1, moles);               // 1_mol
SET( mmol,  1e-3, moles);               // 1_mmol (millimole)
SET( umol,  1e-6, moles);               // 1_umol (micromole)
SET( nmol,  1e-9, moles);               // 1_nmol (nanomole)
SET( pmol, 1e-12, moles);               // 1_pmol (picomole)
SET( fmol, 1e-15, moles);               // 1_fmol (femtomole)
// luminous intensity (J) in...
SET( kcd,    1e3, candelas);            // 1_kcd (kilocandela)
SET( cd,       1, candelas);            // 1_cd  (candela)

// The Derived SI Units
// --------------------
// SYMBOL FACTOR  BASE UNIT                EXAMPLE
// area in...
SET( km²,    1e6, meters2);             // 1_km² (square kilometer)
SET( hm²,    1e4, meters2);             // 1_hm² (hectare)
SET( m²,       1, meters2);             // 1_m²  (square meter)
SET( cm²,   1e-4, meters2);             // 1_cm² (square centimeter)
SET( mm²,   1e-6, meters2);             // 1_mm² (square millimeter)
SET( um²,   1e-9, meters2);             // 1_um² (square micrometer)
// per area in...
SET( per_km²,1e-6, per_meter2);         // 1_per_km² (per square kilometer)
SET( per_hm²,1e-4, per_meter2);         // 1_per_hm² (per hectare)
SET( per_m²,    1, per_meter2);         // 1_per_m²  (per square meter)
SET( per_cm², 1e4, per_meter2);         // 1_per_cm² (per square centimeter)
SET( per_mm², 1e6, per_meter2);         // 1_per_mm² (per square millimeter)
SET( per_μm², 1e9, per_meter2);         // 1_per μm² (per square micrometer)
// surface flow (s) in...
SET( m²_per_s, 1, meters2_per_second);  // 1_m²/s (square meter per second)
// volume in...
SET( km³,    1e9, meters3);             // 1_km³ (cubic kilometer)
SET( m³,       1, meters3);             // 1_m³  (cubic meter)
SET( dm³,   1e-3, meters3);             // 1_dm³ (cubic decimeter)
SET( cm³,   1e-6, meters3);             // 1_cm³ (cubic centimeter)
SET( mm³,   1e-9, meters3);             // 1_mm³ (cubic millimeter)
SET( um³,  1e-12, meters3);             // 1_um³ (cubic micrometer)
// or in...
SET( hl,     0.1, meters3);             // 1_hl  (hectoliter)
SET( l,     1e-3, meters3);             // 1_l   (liter)
SET( ml,    1e-6, meters3);             // 1_ml  (milliliter)
SET( ul,    1e-9, meters3);             // 1_ul  (microliter)
SET( nl,   1e-12, meters3);             // 1_nl  (nanoliter)
SET( pl,   1e-15, meters3);             // 1_pl  (picoliter)
// volumetric flow (V) in...
SET( m³_per_s, 1, meters3_per_second);   // 1_m³/s (cubic meter per second)
SET( l_per_min,1.0/60000.0, meters3_per_second);   // 1_l_per_min (liter per minute)
SET( l_per_s, 1e-3, meters3_per_second); // 1_l_per_s (liter per second)
// velocity (v) in...
SET( km_per_s, 1e3, meters_per_second); // 1_km_per_s (km/s)
SET( m_per_s,  1, meters_per_second);   // 1_m_per_s (m/s)
SET( km_per_h, 1, kilometers_per_hour); // 1_km_per_h (km/h)
SET( mm_per_h, 1, millimeters_per_hour);// 1_mm_per_h (mm/h)
// acceleration (a) in...
SET( km_per_s²,1e3, meters_per_second2);// 1_km_per_s² (km/s²)
SET( m_per_s², 1, meters_per_second2);  // 1_m_per_s² (m/s²)
// frequency (f) in...
SET( THz,   1e12, hertz);               // 1_THz (terahertz)
SET( GHz,    1e9, hertz);               // 1_GHz (gigahertz)
SET( MHz,    1e6, hertz);               // 1_MHz (megahertz)
SET( kHz,    1e3, hertz);               // 1_kHz (kilohertz)
SET( Hz,       1, hertz);               // 1_Hz  (hertz)
SET( mHz,   1e-3, hertz);               // 1_mHz (millihertz)
// radioactive activity (A) in...
SET( TBq,   1e12, hertz);               // 1_TBq (terabecquerel)
SET( GBq,    1e9, hertz);               // 1_GBq (gigabecquerel)
SET( MBq,    1e6, hertz);               // 1_MBq (megabecquerel)
SET( kBq,    1e3, hertz);               // 1_kBq (kilobecquerel)
SET( Bq,       1, hertz);               // 1_Bq  (becquerel)
// absorbed dose (D) in...
SET( Gy,       1, gray);                // 1_Gy (gray)
// equivalent dose (H) and effective dose (E) in...
SET( Sv,       1, sievert);             // 1_Sv  (sievert)
SET( mSv,   1e-3, sievert);             // 1_mSv (millisievert)
SET( uSv,   1e-6, sievert);             // 1_uSv (microsievert)
// mass per area in...
SET( t_per_m², 1e3, kilograms_per_meter2);// 1_t_per_m²
SET( kg_per_m²,  1, kilograms_per_meter2);// 1_kg_per_m²
// mass per volume in...
SET( t_per_m³, 1e3, kilograms_per_meter3);// 1_t_per_m³
SET( kg_per_m³,  1, kilograms_per_meter3);// 1_kg_per_m³
SET( kg_per_cm³,1e-6, kilograms_per_meter3);// 1_kg_per_cm³
SET( g_per_cm³,1e3, kilograms_per_meter3);// 1_g_per_cm³
// electric potential (U) in...
SET( GV,     1e9, volt);                // 1_GV (gigavolt)
SET( MV,     1e6, volt);                // 1_MV (megavolt)
SET( kV,     1e3, volt);                // 1_kV (kilovolt)
SET( V,        1, volt);                // 1_V 
SET( mV,    1e-3, volt);                // 1_mV (millivolt)
SET( uV,    1e-6, volt);                // 1_uV (microvolt)
SET( nV,    1e-9, volt);                // 1_nV (nanovolt)
SET( pV,   1e-12, volt);                // 1_pV (picovolt)
// electric resistance (R) in...
SET( GOhm,   1e9, ohm);                 // 1_GOhm (gigaohm)
SET( MOhm,   1e6, ohm);                 // 1_MOhm (megaohm)
SET( kOhm,   1e3, ohm);                 // 1_kOhm (kiloohm)
SET( Ohm,      1, ohm);                 // 1_Ohm
SET( mOhm,  1e-3, ohm);                 // 1_mOhm (milliohm)
SET( uOhm,  1e-6, ohm);                 // 1_uOhm (microohm)
// electric resistance meter in...
SET( Ohm_m,    1, ohm_meter);           // 1_Ohm_m (ohm meter)
// electric conductance (G) in...
SET( MS,     1e6, siemens);             // 1_MS   (megasiemens)
SET( kS,     1e3, siemens);             // 1_kS   (kilosiemens)
SET( S,        1, siemens);             // 1_S    (siemens)
SET( mS,    1e-3, siemens);             // 1_mS   (millisiemens)
SET( uS,    1e-6, siemens);             // 1_uS   (microsiemens)
// electric conductivity (σ) in...
SET( MS_per_m,1e6, siemens_per_meter);  // 1_MS_per_m (MS/m, megasiemens per meter)
SET( kS_per_m,1e3, siemens_per_meter);  // 1_kS_per_m (kS/m, kilosiemens per meter)
SET( S_per_m,  1, siemens_per_meter);   // 1_S_per_m (S/m, siemens per meter)
// electric charge (Q) in...
SET( C,        1, coulombs);            // 1_C   (coulomb)
SET( GAh,    1e9, ampere_hours);        // 1_GAh (gigaampere-hours)
SET( MAh,    1e6, ampere_hours);        // 1_MAh (megaampere-hours)
SET( kAh,    1e3, ampere_hours);        // 1_kAh (kiloampere-hours)
SET( Ah,       1, ampere_hours);        // 1_Ah  (ampere-hours)
SET( mAh,   1e-3, ampere_hours);        // 1_mAh (milliampere-hours)
SET( uAh,   1e-6, ampere_hours);        // 1_uAh (microampere-hours)
// electric capacitance (C) in...
SET( F,        1, farad);               // 1_F   (farad)
SET( mF,    1e-3, farad);               // 1_mF  (millifarad)
SET( uF,    1e-6, farad);               // 1_uF  (microfarad)
SET( nF,    1e-9, farad);               // 1_nF  (nanofarad)
SET( pF,   1e-12, farad);               // 1_pF  (picofarad)
// electric inductance (L) in...
SET( H,        1, henry);               // 1_H   (henry)
SET( mH,    1e-3, henry);               // 1_mH  (millihenry)
SET( uH,    1e-6, henry);               // 1_uH  (microhenry)
// magnetic flux in...
SET( Wb,       1, weber);               // 1_Wb  (weber)
// magnetic field (B) in...
SET( T,        1, tesla);               // 1_T  (tesla)
SET( mT,    1e-3, tesla);               // 1_mT (millitesla)
SET( uT,    1e-6, tesla);               // 1_uT (microtesla)
SET( nT,    1e-9, tesla);               // 1_nT (nanotesla)
// energy (E) in...
SET( PJ,    1e15, joules);              // 1_PJ  (petajoule)
SET( TJ,    1e12, joules);              // 1_TJ  (terajoule)
SET( GJ,     1e9, joules);              // 1_GJ  (gigajoule)
SET( MJ,     1e6, joules);              // 1_MJ  (megajoule)
SET( kJ,     1e3, joules);              // 1_kJ  (kilojoule)
SET( J,        1, joules);              // 1_J   (joule)
SET( mJ,    1e-3, joules);              // 1_mJ  (millijoule)
// or in...
SET( cal, 4.1868, joules);              // 1_cal (calorie)
SET( kcal,4186.8, joules);              // 1_kcal (kilocalorie)
// active power (P) in...
SET( TW,    1e12, watts);               // 1_TW  (terawatt)
SET( GW,     1e9, watts);               // 1_GW  (gigawatt)
SET( MW,     1e6, watts);               // 1_MW  (megawatt)
SET( kW,     1e3, watts);               // 1_kW  (kilowatt)
SET( W,        1, watts);               // 1_W   (Watt)
SET( mW,    1e-3, watts);               // 1_mW  (milliwatt)
SET( uW,    1e-6, watts);               // 1_uW  (microwatt)
SET( TWh, 3.6e15, watts);               // 1_TWh (terawatt-hour)
SET( GWh, 3.6e12, watts);               // 1_GWh (gigawatt-hour)
SET( MWh,  3.6e9, watts);               // 1_MWh (megawatt-hour)
SET( kWh,  3.6e6, watts);               // 1_kWh (kilowatt-hour)
SET( Wh,   3.6e3, watts);               // 1_Wh  (watt-hour)
// active power per mass in...
SET( kWh_per_kg, 3.6e6, joules_per_second_per_kilogram);  // 1_kWh_per_kg (kilowatt-hour per kilogram)
SET( Wh_per_kg,  3.6e3, joules_per_second_per_kilogram);  // 1_Wh_per_kg (watt-hour per kilogram)
// power intensity (I) in...
SET( MW_per_m²,1e6, watts_per_meter2);  // 1_MW_per_m² (kilowatt per square metre)
SET( kW_per_m²,1e3, watts_per_meter2);  // 1_kW_per_m² (kilowatt per square metre)
SET( W_per_m², 1, watts_per_meter2);    // 1_W_per_m² (watt per square metre)
SET( mW_per_m²,1e-3, watts_per_meter2); // 1_mW_per_m² (milliwatt per square metre)
SET( uW_per_m²,1e-6, watts_per_meter2); // 1_uW_per_m² (milliwatt per square metre)
// pressure (p) in...
SET( MPa,    1e6, pascals);             // 1_MPa  (megapascal) 
SET( kPa,    1e3, pascals);             // 1_kPa  (kilopascal) 
SET( hPa,    100, pascals);             // 1_hPa  (hectopascal) 
SET( Pa,       1, pascals);             // 1_Pa   (pascal) 
SET( mPa,   1e-3, pascals);             // 1_mPa  (millipascal) 
SET( uPa,   1e-6, pascals);             // 1_uPa  (micropascal) 
// force (F) in...
SET( GN,     1e9, newtons);             // 1_GN (giganewton)
SET( MN,     1e6, newtons);             // 1_MN (meganewton)
SET( kN,     1e3, newtons);             // 1_kN (kilonewton)
SET( N,        1, newtons);             // 1_N
SET( mN,    1e-3, newtons);             // 1_mN (millinewton)
SET( uN,    1e-6, newtons);             // 1_uN (micronewton)
SET( pN,    1e-9, newtons);             // 1_pN (piconewton)
// luminous flux (m) in...
SET( lm,       1, lumens);              // 1_lm (lumen)
SET( lm_s,     1, lumenseconds);        // 1_lm_s (lumen second)
SET( lm_per_W, 1, lumens_per_watt);     // 1_lm_per_W (lumen per watt)
// other...
SET( Nm,       1, newtonmeters);        // 1_Nm  (newtonmeter)
// SI supplementary units in...
SET( rad,      1, radians);             // 1_rad (radian)
SET( deg,0.01745329251994329576923690768489, radians); // 1_deg  (angle degree)
SET( sr,       1, steradians);          // 1_sr  (steradian)

// Non-SI Units
// ------------
//   SYMBOL           FACTOR                  BASE UNIT   EXAMPLE
// astronomical units in...
SET( Gpc,           30'856'775'814'913'673e9, meter);  // 1_Gpc (gigaparsec, as of IAU 2012)
SET( Mpc,           30'856'775'814'913'673e6, meter);  // 1_Mpc (megaparsec, as of IAU 2012)
SET( kpc,           30'856'775'814'913'673e3, meter);  // 1_kpc (kiloparsec, as of IAU 2012)
SET( pc,            30'856'775'814'913'673e0, meter);  // 1_pc  (parsec, as of IAU 2012)
SET( ly,               9'460'730'472'580'800, meter);  // 1_ly  (light-year)
SET( au,                     149'597'870'700, meter);  // 1_au  (astronomical unit)
// imperial units in...
SET( degF,                                 1, fahrenheit); // 1_degF (°Fahrenheit)
SET( ft,                               .3048, meter);  // 1_ft (feet)
SET( ft_per_min,                     0.00508, meters_per_second); // 1_ft_per_min (feet/min)
SET( in,                              0.0254, meter);  // 1_in (inch)
SET( in_per_s,                        0.0254, meters_per_second); // 1_in_per_s (inch/sec)
SET( in_per_h,                  0.0000070556, meters_per_second); // 1_in_per_h (inch/hour)
SET( kn,                               1.852, kilometers_per_hour); // 1_kn (knots)
SET( lb,                          453.592'37, gram);   // 1_lb
SET( oz,                      28.349'523'125, gram);   // 1_oz
SET( mi,                           1'609.344, meter);  // 1_mi (statute mile)
SET( mph,                             .44704, meters_per_second); // 1_mph (miles per hour)
SET( NM,                               1'852, meter);  // 1_NM (nautical mile)
SET( nmi,                              1'852, meter);  // 1_nmi (nautical mile)
SET( yd,                               .9144, meter);  // 1_yd (yard)
// digital units in...
SET( byte,                                 1, bytes);   // 1_byte
SET( kB,                                 1e3, bytes);   // 1_kB (kilobyte)
SET( MB,                                 1e6, bytes);   // 1_MB (megabyte)
SET( GB,                                 1e9, bytes);   // 1_GB (gigabyte)
SET( TB,                                1e12, bytes);   // 1_TB (terabyte)
SET( PB,                                1e15, bytes);   // 1_PB (terabyte)
SET( EB,                                1e18, bytes);   // 1_EB (exabyte)
SET( ZB,                                1e21, bytes);   // 1_ZB (zettabyte)
SET( YB,                                1e24, bytes);   // 1_ZY (yottabyte)
SET( RB,                                1e27, bytes);   // 1_RY (ronnabyte)
SET( QB,                                1e30, bytes);   // 1_QY (quettabyte)
SET( KBps,                               1e3, bytes_per_second); // 1_KBps (kilobyte/sec)
SET( MBps,                               1e6, bytes_per_second); // 1_MBps (megabyte/sec)
SET( GBps,                               1e9, bytes_per_second); // 1_GBps (gigabyte/sec)
SET( TBps,                              1e12, bytes_per_second); // 1_TBps (terabyte/sec)
SET( Kbps,                           1e3 / 8, bytes_per_second); // 1_Kbps (kilobit/sec)
SET( Mbps,                           1e6 / 8, bytes_per_second); // 1_Mbps (megabit/sec)
SET( Gbps,                           1e9 / 8, bytes_per_second); // 1_Gbps (gigabit/sec)
SET( Tbps,                          1e12 / 8, bytes_per_second); // 1_Tbps (terabit/sec)
// pressure in...
SET( Mbar,                              1e11, pascals);  // 1_Mbar (megabar)
SET( kbar,                               1e8, pascals);  // 1_kbar (kilobar)
SET( bar,                                1e5, pascals);  // 1_bar 
SET( mbar,                               1e2, pascals);  // 1_mbar (millibar)
SET( at,                            98'066.5, pascals);  // 1_at   (atmosphere)
SET( mmHg,                          133.3224, pascals);  // 1_mmHg (millimeter mercury)
// various units in...
SET( degC,                                 1, celsius);  // 1_degC (°Celsius)
SET( degR,                           5.0/9.0, kelvin);   // 1_degR (°Rankine)
SET( Mach,                               330, meters_per_second); // 1_Mach
SET( Da,                 1.6605390689252e-27, kilogram); // 1_Da   (dalton)
SET( eV,                     1.602176634e-19, joules);   // 1_eV   (electronvolt)
SET( hp,                  745.69987158227022, watts);    // 1_hp   (horsepower)
SET( PS,                           735.49875, watts);    // 1_PS   ('Pferdestärke', german horsepower)
SET( Ang,                              1e-10, meter);    // 1_Ang  (angstrom)
SET( smoot,                           1.7018, meter);    // 1_smoot (one Oliver R. Smoot height, fun unit)
SET( percent,                           0.01, dimensionless); // 1_percent

} // SI::
#undef SET

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/International_System_of_Units
