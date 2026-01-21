// <SI/literals.h> - convenient literals for SI units, e.g. 7_km (requires C++11 or higher)
#pragma once

#include "units.h"

namespace SI {

#define LITERAL(_symbol, _factor, _base_unit) \
constexpr auto operator "" _symbol(long double x) { return _base_unit(static_cast<double_t>(_factor ## L * x)); } \
constexpr auto operator "" _symbol(unsigned long long x) { return _base_unit(static_cast<double_t>(_factor ## L * x)); }

// The 7 SI Base Units
// -------------------
//     SYMBOL FACTOR  BASE UNIT                EXAMPLE
// length in...                                     (sorted from big to small unit)
LITERAL(_Gm,     1e9, meters);              // 1_Gm (gigameter)
LITERAL(_Mm,     1e6, meters);              // 1_Mm (megameter)
LITERAL(_km,     1e3, meters);              // 1_km (kilometer)
LITERAL(_m,        1, meters);              // 1_m  (meter)
LITERAL(_dm,    1e-1, meters);              // 1_dm (decimeter)
LITERAL(_cm,    1e-2, meters);              // 1_cm (centimeter)
LITERAL(_mm,    1e-3, meters);              // 1_mm (millimeter)
LITERAL(_um,    1e-6, meters);              // 1_um (micrometer)
LITERAL(_nm,    1e-9, meters);              // 1_nm (nanometer)
LITERAL(_pm,   1e-12, meters);              // 1_pm (picometer)
// time in...
LITERAL(_day,  86400, seconds);             // 1_day (day on Earth)
LITERAL(_days, 86400, seconds);             // 2_days(day on Earth)
LITERAL(_h,     3600, seconds);             // 1_h   (hour)
LITERAL(_min,     60, seconds);             // 1_min (minute)
LITERAL(_s,        1, seconds);             // 1_s   (second)
LITERAL(_ms,    1e-3, seconds);             // 1_ms  (millisecond)
LITERAL(_us,    1e-6, seconds);             // 1_us  (microsecond)
LITERAL(_ns,    1e-9, seconds);             // 1_ns  (nanosecond)
LITERAL(_ps,   1e-12, seconds);             // 1_ps  (picosecond)
// mass in...
LITERAL(_Gt,    1e12, kilograms);           // 1_Gt (metric gigaton)
LITERAL(_Mt,     1e9, kilograms);           // 1_Mt (metric megaton)
LITERAL(_kt,     1e6, kilograms);           // 1_kt (metric kiloton)
LITERAL(_t,      1e3, kilograms);           // 1_t  (metric ton)
LITERAL(_kg,       1, kilograms);           // 1_kg
LITERAL(_g,     1e-3, kilograms);           // 1_g  (gram)
LITERAL(_mg,    1e-6, kilograms);           // 1_mg (milligram)
LITERAL(_ug,    1e-9, kilograms);           // 1_ug (microgram)
LITERAL(_ng,   1e-12, kilograms);           // 1_ng (nanogram)
// thermodynamic temperature in...
LITERAL(_GK,     1e9, kelvins);             // 1_GK (gigakelvin)
LITERAL(_MK,     1e6, kelvins);             // 1_MK (megakelvin)
LITERAL(_kK,     1e3, kelvins);             // 1_kK (kilokelvin)
LITERAL(_K,        1, kelvins);             // 1_K
LITERAL(_mK,    1e-3, kelvins);             // 1_mK (millikelvin)
LITERAL(_uK,    1e-6, kelvins);             // 1_uK (microkelvin)
LITERAL(_nK,    1e-9, kelvins);             // 1_nK (nanokelvin)
// electric current (I) in...
LITERAL(_GA,     1e9, amperes);             // 1_GA  (gigaampere)
LITERAL(_MA,     1e6, amperes);             // 1_MA  (megaampere)
LITERAL(_kA,     1e3, amperes);             // 1_kA  (kiloampere)
LITERAL(_A,        1, amperes);             // 1_A 
LITERAL(_mA,    1e-3, amperes);             // 1_mA  (milliampere)
LITERAL(_uA,    1e-6, amperes);             // 1_uA  (microampere)
LITERAL(_nA,    1e-9, amperes);             // 1_nA  (nanoampere)
LITERAL(_pA,   1e-12, amperes);             // 1_pA  (picoampere)
// amount of substance (N_A) in...
LITERAL(_Mmol,   1e6, moles);               // 1_Mmol (megamole)
LITERAL(_kmol,   1e3, moles);               // 1_kmol (kilomole)
LITERAL(_mol,      1, moles);               // 1_mol
LITERAL(_mmol,  1e-3, moles);               // 1_mmol (millimole)
LITERAL(_umol,  1e-6, moles);               // 1_umol (micromole)
LITERAL(_nmol,  1e-9, moles);               // 1_nmol (nanomole)
LITERAL(_pmol, 1e-12, moles);               // 1_pmol (picomole)
LITERAL(_fmol, 1e-15, moles);               // 1_fmol (femtomole)
// luminous intensity (J) in...
LITERAL(_kcd,    1e3, candelas);            // 1_kcd (kilocandela)
LITERAL(_cd,       1, candelas);            // 1_cd  (candela)

// The Derived SI Units
// --------------------
// SYMBOL FACTOR  BASE UNIT                EXAMPLE
// area in...
LITERAL(_km²,    1e6, meters2);             // 1_km² (square kilometer)
LITERAL(_hm²,    1e4, meters2);             // 1_hm² (hectare)
LITERAL(_m²,       1, meters2);             // 1_m²  (square meter)
LITERAL(_cm²,   1e-4, meters2);             // 1_cm² (square centimeter)
LITERAL(_mm²,   1e-6, meters2);             // 1_mm² (square millimeter)
LITERAL(_um²,   1e-9, meters2);             // 1_um² (square micrometer)
// per area in...
LITERAL(_per_km²,1e-6, per_meter2);         // 1_per_km² (per square kilometer)
LITERAL(_per_hm²,1e-4, per_meter2);         // 1_per_hm² (per hectare)
LITERAL(_per_m²,    1, per_meter2);         // 1_per_m²  (per square meter)
LITERAL(_per_cm², 1e4, per_meter2);         // 1_per_cm² (per square centimeter)
LITERAL(_per_mm², 1e6, per_meter2);         // 1_per_mm² (per square millimeter)
LITERAL(_per_μm², 1e9, per_meter2);         // 1_per μm² (per square micrometer)
// surface flow (s) in...
LITERAL(_m²_per_s, 1, meters2_per_second);  // 1_m²/s (square meter per second)
// volume in...
LITERAL(_km³,    1e9, meters3);             // 1_km³ (cubic kilometer)
LITERAL(_m³,       1, meters3);             // 1_m³  (cubic meter)
LITERAL(_dm³,   1e-3, meters3);             // 1_dm³ (cubic decimeter)
LITERAL(_cm³,   1e-6, meters3);             // 1_cm³ (cubic centimeter)
LITERAL(_mm³,   1e-9, meters3);             // 1_mm³ (cubic millimeter)
LITERAL(_um³,  1e-12, meters3);             // 1_um³ (cubic micrometer)
// or in...
LITERAL(_hl,     0.1, meters3);             // 1_hl  (hectoliter)
LITERAL(_l,     1e-3, meters3);             // 1_l   (liter)
LITERAL(_ml,    1e-6, meters3);             // 1_ml  (milliliter)
LITERAL(_ul,    1e-9, meters3);             // 1_ul  (microliter)
LITERAL(_nl,   1e-12, meters3);             // 1_nl  (nanoliter)
LITERAL(_pl,   1e-15, meters3);             // 1_pl  (picoliter)
// volumetric flow (V) in...
LITERAL(_m³_per_s, 1, meters3_per_second);   // 1_m³/s (cubic meter per second)
LITERAL(_l_per_min,1.0/60000.0, meters3_per_second);   // 1_l_per_min (liter per minute)
LITERAL(_l_per_s, 1e-3, meters3_per_second); // 1_l_per_s (liter per second)
// velocity (v) in...
LITERAL(_km_per_s, 1e3, meters_per_second); // 1_km_per_s (km/s)
LITERAL(_m_per_s,  1, meters_per_second);   // 1_m_per_s (m/s)
LITERAL(_km_per_h, 1, kilometers_per_hour); // 1_km_per_h (km/h)
LITERAL(_mm_per_h, 1, millimeters_per_hour);// 1_mm_per_h (mm/h)
// acceleration (a) in...
LITERAL(_km_per_s²,1e3, meters_per_second2);// 1_km_per_s² (km/s²)
LITERAL(_m_per_s², 1, meters_per_second2);  // 1_m_per_s² (m/s²)
// frequency (f) in...
LITERAL(_THz,   1e12, hertz);               // 1_THz (terahertz)
LITERAL(_GHz,    1e9, hertz);               // 1_GHz (gigahertz)
LITERAL(_MHz,    1e6, hertz);               // 1_MHz (megahertz)
LITERAL(_kHz,    1e3, hertz);               // 1_kHz (kilohertz)
LITERAL(_Hz,       1, hertz);               // 1_Hz  (hertz)
LITERAL(_mHz,   1e-3, hertz);               // 1_mHz (millihertz)
// radioactive activity (A) in...
LITERAL(_TBq,   1e12, hertz);               // 1_TBq (terabecquerel)
LITERAL(_GBq,    1e9, hertz);               // 1_GBq (gigabecquerel)
LITERAL(_MBq,    1e6, hertz);               // 1_MBq (megabecquerel)
LITERAL(_kBq,    1e3, hertz);               // 1_kBq (kilobecquerel)
LITERAL(_Bq,       1, hertz);               // 1_Bq  (becquerel)
// absorbed dose (D) in...
LITERAL(_Gy,       1, grays);               // 1_Gy  (gray)
LITERAL(_mGy,   1e-3, grays);               // 1_mGy (milligray)
LITERAL(_uGy,   1e-6, grays);               // 1_uGy (microgray)
// equivalent dose (H) and effective dose (E) in...
LITERAL(_Sv,       1, sieverts);            // 1_Sv  (sievert)
LITERAL(_mSv,   1e-3, sieverts);            // 1_mSv (millisievert)
LITERAL(_uSv,   1e-6, sieverts);            // 1_uSv (microsievert)
// mass per area in...
LITERAL(_t_per_m², 1e3, kilograms_per_meter2);// 1_t_per_m²
LITERAL(_kg_per_m²,  1, kilograms_per_meter2);// 1_kg_per_m²
// mass per volume in...
LITERAL(_t_per_m³, 1e3, kilograms_per_meter3);// 1_t_per_m³
LITERAL(_kg_per_m³,  1, kilograms_per_meter3);// 1_kg_per_m³
LITERAL(_kg_per_cm³,1e-6, kilograms_per_meter3);// 1_kg_per_cm³
LITERAL(_g_per_cm³,1e3, kilograms_per_meter3);// 1_g_per_cm³
// electric potential (U) in...
LITERAL(_GV,     1e9, volts);               // 1_GV (gigavolt)
LITERAL(_MV,     1e6, volts);               // 1_MV (megavolt)
LITERAL(_kV,     1e3, volts);               // 1_kV (kilovolt)
LITERAL(_V,        1, volts);               // 1_V 
LITERAL(_mV,    1e-3, volts);               // 1_mV (millivolt)
LITERAL(_uV,    1e-6, volts);               // 1_uV (microvolt)
LITERAL(_nV,    1e-9, volts);               // 1_nV (nanovolt)
LITERAL(_pV,   1e-12, volts);               // 1_pV (picovolt)
// electric resistance (R) in...
LITERAL(_GOhm,   1e9, ohms);                // 1_GOhm (gigaohm)
LITERAL(_MOhm,   1e6, ohms);                // 1_MOhm (megaohm)
LITERAL(_kOhm,   1e3, ohms);                // 1_kOhm (kiloohm)
LITERAL(_Ohm,      1, ohms);                // 1_Ohm
LITERAL(_mOhm,  1e-3, ohms);                // 1_mOhm (milliohm)
LITERAL(_uOhm,  1e-6, ohms);                // 1_uOhm (microohm)
// electric resistance meter in...
LITERAL(_Ohm_m,    1, ohm_meters);          // 1_Ohm_m (ohm meter)
// electric conductance (G) in...
LITERAL(_MS,     1e6, siemens);             // 1_MS   (megasiemens)
LITERAL(_kS,     1e3, siemens);             // 1_kS   (kilosiemens)
LITERAL(_S,        1, siemens);             // 1_S    (siemens)
LITERAL(_mS,    1e-3, siemens);             // 1_mS   (millisiemens)
LITERAL(_uS,    1e-6, siemens);             // 1_uS   (microsiemens)
// electric conductivity (σ) in...
LITERAL(_MS_per_m,1e6, siemens_per_meter);  // 1_MS_per_m (MS/m, megasiemens per meter)
LITERAL(_kS_per_m,1e3, siemens_per_meter);  // 1_kS_per_m (kS/m, kilosiemens per meter)
LITERAL(_S_per_m,  1, siemens_per_meter);   // 1_S_per_m (S/m, siemens per meter)
// electric charge (Q) in...
LITERAL(_C,        1, coulombs);            // 1_C   (coulomb)
LITERAL(_GAh,    1e9, ampere_hours);        // 1_GAh (gigaampere-hours)
LITERAL(_MAh,    1e6, ampere_hours);        // 1_MAh (megaampere-hours)
LITERAL(_kAh,    1e3, ampere_hours);        // 1_kAh (kiloampere-hours)
LITERAL(_Ah,       1, ampere_hours);        // 1_Ah  (ampere-hours)
LITERAL(_mAh,   1e-3, ampere_hours);        // 1_mAh (milliampere-hours)
LITERAL(_uAh,   1e-6, ampere_hours);        // 1_uAh (microampere-hours)
// electric capacitance (C) in...
LITERAL(_F,        1, farads);              // 1_F   (farad)
LITERAL(_mF,    1e-3, farads);              // 1_mF  (millifarad)
LITERAL(_uF,    1e-6, farads);              // 1_uF  (microfarad)
LITERAL(_nF,    1e-9, farads);              // 1_nF  (nanofarad)
LITERAL(_pF,   1e-12, farads);              // 1_pF  (picofarad)
// electric inductance (L) in...
LITERAL(_H,        1, henrys);              // 1_H   (henry)
LITERAL(_mH,    1e-3, henrys);              // 1_mH  (millihenry)
LITERAL(_uH,    1e-6, henrys);              // 1_uH  (microhenry)
LITERAL(_nH,    1e-9, henrys);              // 1_nH  (nanohenry)
// magnetic flux in...
LITERAL(_Wb,       1, webers);              // 1_Wb  (weber)
// magnetic field (B) in...
LITERAL(_kT,     1e3, teslas);              // 1_kT  (kilotesla)
LITERAL(_T,        1, teslas);              // 1_T   (tesla)
LITERAL(_mT,    1e-3, teslas);              // 1_mT  (millitesla)
LITERAL(_uT,    1e-6, teslas);              // 1_uT  (microtesla)
LITERAL(_nT,    1e-9, teslas);              // 1_nT  (nanotesla)
// energy (E) in...
LITERAL(_PJ,    1e15, joules);              // 1_PJ  (petajoule)
LITERAL(_TJ,    1e12, joules);              // 1_TJ  (terajoule)
LITERAL(_GJ,     1e9, joules);              // 1_GJ  (gigajoule)
LITERAL(_MJ,     1e6, joules);              // 1_MJ  (megajoule)
LITERAL(_kJ,     1e3, joules);              // 1_kJ  (kilojoule)
LITERAL(_J,        1, joules);              // 1_J   (joule)
LITERAL(_mJ,    1e-3, joules);              // 1_mJ  (millijoule)
// or in...
LITERAL(_cal, 4.1868, joules);              // 1_cal (calorie)
LITERAL(_kcal,4186.8, joules);              // 1_kcal (kilocalorie)
// active power (P) in...
LITERAL(_TW,    1e12, watts);               // 1_TW  (terawatt)
LITERAL(_GW,     1e9, watts);               // 1_GW  (gigawatt)
LITERAL(_MW,     1e6, watts);               // 1_MW  (megawatt)
LITERAL(_kW,     1e3, watts);               // 1_kW  (kilowatt)
LITERAL(_W,        1, watts);               // 1_W   (Watt)
LITERAL(_mW,    1e-3, watts);               // 1_mW  (milliwatt)
LITERAL(_uW,    1e-6, watts);               // 1_uW  (microwatt)
LITERAL(_TWh, 3.6e15, watts);               // 1_TWh (terawatt-hour)
LITERAL(_GWh, 3.6e12, watts);               // 1_GWh (gigawatt-hour)
LITERAL(_MWh,  3.6e9, watts);               // 1_MWh (megawatt-hour)
LITERAL(_kWh,  3.6e6, watts);               // 1_kWh (kilowatt-hour)
LITERAL(_Wh,   3.6e3, watts);               // 1_Wh  (watt-hour)
// active power per mass in...
LITERAL(_kWh_per_kg, 3.6e6, joules_per_second_per_kilogram);  // 1_kWh_per_kg (kilowatt-hour per kilogram)
LITERAL(_Wh_per_kg,  3.6e3, joules_per_second_per_kilogram);  // 1_Wh_per_kg (watt-hour per kilogram)
// power intensity (I) in...
LITERAL(_MW_per_m²,1e6, watts_per_meter2);  // 1_MW_per_m² (kilowatt per square metre)
LITERAL(_kW_per_m²,1e3, watts_per_meter2);  // 1_kW_per_m² (kilowatt per square metre)
LITERAL(_W_per_m², 1, watts_per_meter2);    // 1_W_per_m² (watt per square metre)
LITERAL(_mW_per_m²,1e-3, watts_per_meter2); // 1_mW_per_m² (milliwatt per square metre)
LITERAL(_uW_per_m²,1e-6, watts_per_meter2); // 1_uW_per_m² (milliwatt per square metre)
// pressure (p) in...
LITERAL(_MPa,    1e6, pascals);             // 1_MPa  (megapascal) 
LITERAL(_kPa,    1e3, pascals);             // 1_kPa  (kilopascal) 
LITERAL(_hPa,    100, pascals);             // 1_hPa  (hectopascal) 
LITERAL(_Pa,       1, pascals);             // 1_Pa   (pascal) 
LITERAL(_mPa,   1e-3, pascals);             // 1_mPa  (millipascal) 
LITERAL(_uPa,   1e-6, pascals);             // 1_uPa  (micropascal) 
// force (F) in...
LITERAL(_GN,     1e9, newtons);             // 1_GN (giganewton)
LITERAL(_MN,     1e6, newtons);             // 1_MN (meganewton)
LITERAL(_kN,     1e3, newtons);             // 1_kN (kilonewton)
LITERAL(_N,        1, newtons);             // 1_N
LITERAL(_mN,    1e-3, newtons);             // 1_mN (millinewton)
LITERAL(_uN,    1e-6, newtons);             // 1_uN (micronewton)
LITERAL(_pN,    1e-9, newtons);             // 1_pN (piconewton)
// luminous flux (m) in...
LITERAL(_lm,       1, lumens);              // 1_lm (lumen)
LITERAL(_lm_s,     1, lumenseconds);        // 1_lm_s (lumen second)
LITERAL(_lm_per_W, 1, lumens_per_watt);     // 1_lm_per_W (lumen per watt)
// other...
LITERAL(_Nm,       1, newtonmeters);        // 1_Nm  (newtonmeter)
// SI supplementary units in...
LITERAL(_rad,      1, radians);             // 1_rad (radian)
LITERAL(_deg,0.01745329251994329576923690768489, radians); // 1_deg  (angle degree)
LITERAL(_sr,       1, steradians);          // 1_sr  (steradian)

// Non-SI Units
// ------------
//   SYMBOL           FACTOR                  BASE UNIT   EXAMPLE
// astronomical units in...
LITERAL(_Gpc,           30'856'775'814'913'673e9, meters); // 1_Gpc (gigaparsec, as of IAU 2012)
LITERAL(_Mpc,           30'856'775'814'913'673e6, meters); // 1_Mpc (megaparsec, as of IAU 2012)
LITERAL(_kpc,           30'856'775'814'913'673e3, meters); // 1_kpc (kiloparsec, as of IAU 2012)
LITERAL(_pc,            30'856'775'814'913'673e0, meters); // 1_pc  (parsec, as of IAU 2012)
LITERAL(_ly,               9'460'730'472'580'800, meters); // 1_ly  (light-year)
LITERAL(_au,                     149'597'870'700, meters); // 1_au  (astronomical unit)
// imperial units in...
LITERAL(_degF,                                 1, fahrenheit); // 1_degF (°Fahrenheit)
LITERAL(_ft,                               .3048, meters); // 1_ft (feet)
LITERAL(_ft_per_min,                     0.00508, meters_per_second); // 1_ft_per_min (feet/min)
LITERAL(_in,                              0.0254, meters); // 1_in (inch)
LITERAL(_in_per_s,                        0.0254, meters_per_second); // 1_in_per_s (inch/sec)
LITERAL(_in_per_h,                  0.0000070556, meters_per_second); // 1_in_per_h (inch/hour)
LITERAL(_kn,                               1.852, kilometers_per_hour); // 1_kn (knots)
LITERAL(_lb,                          453.592'37, grams);  // 1_lb
LITERAL(_oz,                      28.349'523'125, grams);  // 1_oz
LITERAL(_mi,                           1'609.344, meters); // 1_mi (statute mile)
LITERAL(_mph,                             .44704, meters_per_second); // 1_mph (miles per hour)
LITERAL(_NM,                               1'852, meters); // 1_NM (nautical mile)
LITERAL(_nmi,                              1'852, meters); // 1_nmi (nautical mile)
LITERAL(_yd,                               .9144, meters); // 1_yd (yard)
// digital units in...
LITERAL(_byte,                                 1, bytes);   // 1_byte
LITERAL(_kB,                                 1e3, bytes);   // 1_kB (kilobyte)
LITERAL(_MB,                                 1e6, bytes);   // 1_MB (megabyte)
LITERAL(_GB,                                 1e9, bytes);   // 1_GB (gigabyte)
LITERAL(_TB,                                1e12, bytes);   // 1_TB (terabyte)
LITERAL(_PB,                                1e15, bytes);   // 1_PB (terabyte)
LITERAL(_EB,                                1e18, bytes);   // 1_EB (exabyte)
LITERAL(_ZB,                                1e21, bytes);   // 1_ZB (zettabyte)
LITERAL(_YB,                                1e24, bytes);   // 1_ZY (yottabyte)
LITERAL(_RB,                                1e27, bytes);   // 1_RY (ronnabyte)
LITERAL(_QB,                                1e30, bytes);   // 1_QY (quettabyte)
LITERAL(_KBps,                               1e3, bytes_per_second); // 1_KBps (kilobyte/sec)
LITERAL(_MBps,                               1e6, bytes_per_second); // 1_MBps (megabyte/sec)
LITERAL(_GBps,                               1e9, bytes_per_second); // 1_GBps (gigabyte/sec)
LITERAL(_TBps,                              1e12, bytes_per_second); // 1_TBps (terabyte/sec)
LITERAL(_Kbps,                           1e3 / 8, bytes_per_second); // 1_Kbps (kilobit/sec)
LITERAL(_Mbps,                           1e6 / 8, bytes_per_second); // 1_Mbps (megabit/sec)
LITERAL(_Gbps,                           1e9 / 8, bytes_per_second); // 1_Gbps (gigabit/sec)
LITERAL(_Tbps,                          1e12 / 8, bytes_per_second); // 1_Tbps (terabit/sec)
// pressure in...
LITERAL(_Mbar,                              1e11, pascals);  // 1_Mbar (megabar)
LITERAL(_kbar,                               1e8, pascals);  // 1_kbar (kilobar)
LITERAL(_bar,                                1e5, pascals);  // 1_bar 
LITERAL(_mbar,                               1e2, pascals);  // 1_mbar (millibar)
LITERAL(_at,                            98'066.5, pascals);  // 1_at   (atmosphere)
LITERAL(_mmHg,                          133.3224, pascals);  // 1_mmHg (millimeter mercury)
// various units in...
LITERAL(_degC,                                 1, celsius);  // 1_degC (°Celsius)
LITERAL(_degR,                           5.0/9.0, kelvins);  // 1_degR (°Rankine)
LITERAL(_Mach,                               330, meters_per_second); // 1_Mach
LITERAL(_Da,                 1.6605390689252e-27, kilograms);// 1_Da   (dalton)
LITERAL(_eV,                     1.602176634e-19, joules);   // 1_eV   (electronvolt)
LITERAL(_hp,                  745.69987158227022, watts);    // 1_hp   (horsepower)
LITERAL(_PS,                           735.49875, watts);    // 1_PS   ('Pferdestärke', german horsepower)
LITERAL(_Ang,                              1e-10, meters);   // 1_Ang  (angstrom)
LITERAL(_smoot,                           1.7018, meters);   // 1_smoot (one Oliver R. Smoot height, fun unit)
LITERAL(_percent,                           0.01, dimensionless); // 1_percent

#undef LITERAL
} // SI::

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/International_System_of_Units
