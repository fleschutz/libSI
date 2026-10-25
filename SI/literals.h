/// @file     SI/literals.h
/// @brief    Defines 297 user-defined literals (since C++11), e.g. 24_h
/// @details  Categories are: SI Base Units, SI Derived Units, Imperial Units, Astronomical Units,
///                           Digital Units, Various Units, and References.

#pragma once
#include <SI/units.h>
#define SET(_literal, _factor, _unit)                                                                                \
  constexpr auto operator "" _literal(long double q) { return _unit(static_cast<SIdouble>(q * _factor ## L)); }      \
  constexpr auto operator "" _literal(unsigned long long q) { return _unit(static_cast<SIdouble>(q * _factor ## L)); }

namespace SI {

  // SI Base Units
  // -------------
  //
  // SYMBOL FACTOR  BASE UNIT             EXAMPLE (sorted from big units to small one)
  // -------------------------------------------------------------
  // length in...
  SET(_Pm,    1e15, meters);              // 1_Pm (petameter)
  SET(_Tm,    1e12, meters);              // 1_Tm (terameter)
  SET(_Gm,     1e9, meters);              // 1_Gm (gigameter)
  SET(_Mm,     1e6, meters);              // 1_Mm (megameter)
  SET(_km,     1e3, meters);              // 1_km (kilometer)
  SET( _m,       1, meters);              // 1_m  (meter)
  SET(_dm,    1e-1, meters);              // 1_dm (decimeter)
  SET(_cm,    1e-2, meters);              // 1_cm (centimeter)
  SET(_mm,    1e-3, meters);              // 1_mm (millimeter)
  SET(_um,    1e-6, meters);              // 1_um (micrometer)
  SET(_nm,    1e-9, meters);              // 1_nm (nanometer)
  SET(_pm,   1e-12, meters);              // 1_pm (picometer)
  // time in...
  SET(_w,  604'800, seconds);             // 1_w   (Earth week)
  SET(_d,    86400, seconds);             // 1_d   (Earth day)
  SET(_days, 86400, seconds);             // 2_days(Earth days)
  SET(_h,     3600, seconds);             // 1_h   (hour)
  SET(_min,     60, seconds);             // 1_min (minute)
  SET( _s,       1, seconds);             // 1_s   (second)
  SET(_ms,    1e-3, seconds);             // 1_ms  (millisecond)
  SET(_us,    1e-6, seconds);             // 1_us  (microsecond)
  SET(_ns,    1e-9, seconds);             // 1_ns  (nanosecond)
  SET(_ps,   1e-12, seconds);             // 1_ps  (picosecond)
  // mass in...
  SET(_Pt,    1e18, kilograms);           // 1_Pt (metric petaton)
  SET(_Tt,    1e15, kilograms);           // 1_Tt (metric teraton)
  SET(_Gt,    1e12, kilograms);           // 1_Gt (metric gigaton)
  SET(_Mt,     1e9, kilograms);           // 1_Mt (metric megaton)
  SET(_kt,     1e6, kilograms);           // 1_kt (metric kiloton)
  SET( _t,     1e3, kilograms);           // 1_t  (metric ton)
  SET(_kg,       1, kilograms);           // 1_kg (kilogram)
  SET( _g,    1e-3, kilograms);           // 1_g  (gram)
  SET(_mg,    1e-6, kilograms);           // 1_mg (milligram)
  SET(_ug,    1e-9, kilograms);           // 1_ug (microgram)
  SET(_ng,   1e-12, kilograms);           // 1_ng (nanogram)
  // thermodynamic temperature in...
  SET(_GK,     1e9, kelvins);             // 1_GK (gigakelvin)
  SET(_MK,     1e6, kelvins);             // 1_MK (megakelvin)
  SET(_kK,     1e3, kelvins);             // 1_kK (kilokelvin)
  SET( _K,       1, kelvins);             // 1_K  (kelvin)
  SET(_mK,    1e-3, kelvins);             // 1_mK (millikelvin)
  SET(_uK,    1e-6, kelvins);             // 1_uK (microkelvin)
  SET(_nK,    1e-9, kelvins);             // 1_nK (nanokelvin)
  // electric current in...
  SET(_GA,     1e9, amperes);             // 1_GA  (gigaampere)
  SET(_MA,     1e6, amperes);             // 1_MA  (megaampere)
  SET(_kA,     1e3, amperes);             // 1_kA  (kiloampere)
  SET( _A,       1, amperes);             // 1_A   (ampere)
  SET(_mA,    1e-3, amperes);             // 1_mA  (milliampere)
  SET(_uA,    1e-6, amperes);             // 1_uA  (microampere)
  SET(_nA,    1e-9, amperes);             // 1_nA  (nanoampere)
  SET(_pA,   1e-12, amperes);             // 1_pA  (picoampere)
  // amount of substance in...
  SET(_Gmol,   1e9, moles);               // 1_Gmol (gigamole)
  SET(_Mmol,   1e6, moles);               // 1_Mmol (megamole)
  SET(_kmol,   1e3, moles);               // 1_kmol (kilomole)
  SET( _mol,     1, moles);               // 1_mol  (mole)
  SET(_mmol,  1e-3, moles);               // 1_mmol (millimole)
  SET(_umol,  1e-6, moles);               // 1_umol (micromole)
  SET(_nmol,  1e-9, moles);               // 1_nmol (nanomole)
  SET(_pmol, 1e-12, moles);               // 1_pmol (picomole)
  SET(_fmol, 1e-15, moles);               // 1_fmol (femtomole)
  // luminous intensity in...
  SET(_kcd,    1e3, candelas);            // 1_kcd (kilocandela)
  SET( _cd,      1, candelas);            // 1_cd  (candela)

  // SI Derived Units
  // ----------------
  // area in...
  SET(_km²,    1e6, meters2);             // 1_km² (square kilometer)
  SET(_hm²,    1e4, meters2);             // 1_hm² (hectare)
  SET( _m²,      1, meters2);             // 1_m²  (square meter)
  SET(_cm²,   1e-4, meters2);             // 1_cm² (square centimeter)
  SET(_mm²,   1e-6, meters2);             // 1_mm² (square millimeter)
  SET(_um²,   1e-9, meters2);             // 1_um² (square micrometer)
  // per area in...
  SET(_per_km²,1e-6, per_meter2);         // 1_per_km² (per square kilometer)
  SET(_per_hm²,1e-4, per_meter2);         // 1_per_hm² (per hectare)
  SET(_per_m²,    1, per_meter2);         // 1_per_m²  (per square meter)
  SET(_per_cm², 1e4, per_meter2);         // 1_per_cm² (per square centimeter)
  SET(_per_mm², 1e6, per_meter2);         // 1_per_mm² (per square millimeter)
  SET(_per_μm², 1e9, per_meter2);         // 1_per μm² (per square micrometer)
  // surface flow in...
  SET(_m²_per_s, 1, meters2_per_second);  // 1_m²/s (square meter per second)
  // volume in cubic meter in...
  SET(_km³,    1e9, meters3);             // 1_km³ (cubic kilometer)
  SET( _m³,      1, meters3);             // 1_m³  (cubic meter)
  SET(_dm³,   1e-3, meters3);             // 1_dm³ (cubic decimeter)
  SET(_cm³,   1e-6, meters3);             // 1_cm³ (cubic centimeter, aka ccm)
  SET(_mm³,   1e-9, meters3);             // 1_mm³ (cubic millimeter)
  SET(_um³,  1e-12, meters3);             // 1_um³ (cubic micrometer)
  // volume in liter in...
  SET(_Ml,     1e3, meters3);             // 1_Ml (megaliter)
  SET(_kl,       1, meters3);             // 1_kl (kiloliter)
  SET(_hl,     0.1, meters3);             // 1_hl (hectoliter)
  SET( _l,    1e-3, meters3);             // 1_l  (liter)
  SET(_ml,    1e-6, meters3);             // 1_ml (milliliter)
  SET(_ul,    1e-9, meters3);             // 1_ul (microliter)
  SET(_nl,   1e-12, meters3);             // 1_nl (nanoliter)
  SET(_pl,   1e-15, meters3);             // 1_pl (picoliter)
  // volumetric flow in...
  SET(_m³_per_s, 1, meters3_per_second);   // 1_m³/s (cubic meter per second)
  SET(_l_per_min,1.0/60000.0, meters3_per_second);   // 1_l_per_min (liter per minute)
  SET(_l_per_s, 1e-3, meters3_per_second); // 1_l_per_s (liter per second)
  // velocity per second in...
  SET(_km_per_s, 1e3, meters_per_second); // 1_km_per_s (km/s)
  SET(_m_per_s,  1, meters_per_second);   // 1_m_per_s  (m/s)
  SET(_mm_per_s, 1e-3, meters_per_second);// 1_mm_per_s (mm/s)
  // velocity per hour in...
  SET(_km_per_h, 1e3, meters_per_hour);   // 1_km_per_h (km/h)
  SET(_m_per_h,  1, meters_per_hour);     // 1_m_per_h  (m/h)
  SET(_mm_per_h, 1e-3, meters_per_hour);  // 1_mm_per_h (mm/h)
  // acceleration in...
  SET(_km_per_s²,1e3, meters_per_second2);// 1_km_per_s² (km/s²)
  SET(_m_per_s², 1, meters_per_second2);  // 1_m_per_s²  (m/s²)
  // frequency in...
  SET(_PHz,   1e15, hertz);               // 1_PHz (petahertz)
  SET(_THz,   1e12, hertz);               // 1_THz (terahertz)
  SET(_GHz,    1e9, hertz);               // 1_GHz (gigahertz)
  SET(_MHz,    1e6, hertz);               // 1_MHz (megahertz)
  SET(_kHz,    1e3, hertz);               // 1_kHz (kilohertz)
  SET( _Hz,      1, hertz);               // 1_Hz  (hertz)
  SET(_mHz,   1e-3, hertz);               // 1_mHz (millihertz)
  SET(_uHz,   1e-6, hertz);               // 1_uHz (microhertz)
  // radioactive activity in...
  SET(_TBq,   1e12, hertz);               // 1_TBq (terabecquerel)
  SET(_GBq,    1e9, hertz);               // 1_GBq (gigabecquerel)
  SET(_MBq,    1e6, hertz);               // 1_MBq (megabecquerel)
  SET(_kBq,    1e3, hertz);               // 1_kBq (kilobecquerel)
  SET( _Bq,      1, hertz);               // 1_Bq  (becquerel)
  // absorbed dose in...
  SET( _Gy,      1, grays);               // 1_Gy  (gray)
  SET(_mGy,   1e-3, grays);               // 1_mGy (milligray)
  SET(_uGy,   1e-6, grays);               // 1_uGy (microgray)
  // equivalent dose and effective dose in...
  SET( _Sv,      1, sieverts);            // 1_Sv  (sievert)
  SET(_mSv,   1e-3, sieverts);            // 1_mSv (millisievert)
  SET(_uSv,   1e-6, sieverts);            // 1_uSv (microsievert)
  // mass per area in...
  SET(_t_per_m², 1e3, kilograms_per_meter2);// 1_t_per_m²
  SET(_kg_per_m²,  1, kilograms_per_meter2);// 1_kg_per_m²
  // density in...
  SET(_t_per_m³, 1e3, kilograms_per_meter3);   // 1_t_per_m³
  SET(_kg_per_m³,  1, kilograms_per_meter3);   // 1_kg_per_m³
  SET(_g_per_m³,1e-3, kilograms_per_meter3);   // 1_g_per_m³
  SET(_mg_per_m³,1e-9, kilograms_per_meter3);  // 1_mg_per_m³
  SET(_kg_per_cm³,1e-6, kilograms_per_meter3); // 1_kg_per_cm³
  SET(_g_per_cm³,1e3, kilograms_per_meter3);   // 1_g_per_cm³
  // electric potential in...
  SET(_GV,     1e9, volts);               // 1_GV (gigavolt)
  SET(_MV,     1e6, volts);               // 1_MV (megavolt)
  SET(_kV,     1e3, volts);               // 1_kV (kilovolt)
  SET( _V,       1, volts);               // 1_V 
  SET(_mV,    1e-3, volts);               // 1_mV (millivolt)
  SET(_uV,    1e-6, volts);               // 1_uV (microvolt)
  SET(_nV,    1e-9, volts);               // 1_nV (nanovolt)
  SET(_pV,   1e-12, volts);               // 1_pV (picovolt)
  // electric resistance in...
  SET(_GOhm,   1e9, ohms);                // 1_GOhm (gigaohm)
  SET(_MOhm,   1e6, ohms);                // 1_MOhm (megaohm)
  SET(_kOhm,   1e3, ohms);                // 1_kOhm (kiloohm)
  SET( _Ohm,     1, ohms);                // 1_Ohm
  SET(_mOhm,  1e-3, ohms);                // 1_mOhm (milliohm)
  SET(_uOhm,  1e-6, ohms);                // 1_uOhm (microohm)
  // electric resistance meter in...
  SET(_Ohm_m,    1, ohm_meters);          // 1_Ohm_m (ohm meter)
  // electric conductance in...
  SET(_GS,     1e9, siemens);             // 1_GS (gigasiemens)
  SET(_MS,     1e6, siemens);             // 1_MS (megasiemens)
  SET(_kS,     1e3, siemens);             // 1_kS (kilosiemens)
  SET( _S,       1, siemens);             // 1_S  (siemens)
  SET(_mS,    1e-3, siemens);             // 1_mS (millisiemens)
  SET(_uS,    1e-6, siemens);             // 1_uS (microsiemens)
  SET(_nS,    1e-9, siemens);             // 1_nS (nanosiemens)
  // electric conductivity in...
  SET(_MS_per_m,1e6, siemens_per_meter);  // 1_MS_per_m (MS/m, megasiemens per meter)
  SET(_kS_per_m,1e3, siemens_per_meter);  // 1_kS_per_m (kS/m, kilosiemens per meter)
  SET( _S_per_m,  1, siemens_per_meter);   // 1_S_per_m (S/m, siemens per meter)
  // electric charge in coulombs in...
  SET(_GC,     1e9, coulombs);            // 1_GC (gigaoulomb)
  SET(_MC,     1e6, coulombs);            // 1_MC (megaoulomb)
  SET(_kC,     1e3, coulombs);            // 1_kC (kilocoulomb)
  SET( _C,       1, coulombs);            // 1_C  (coulomb)
  SET(_mC,    1e-3, coulombs);            // 1_mC (millicoulomb)
  SET(_uC,    1e-6, coulombs);            // 1_uC (microcoulomb)
  SET(_nC,    1e-9, coulombs);            // 1_nC (nanocoulomb)
  SET(_pC,   1e-12, coulombs);            // 1_pC (picocoulomb)
  // electric charge in ampere-hours in...
  SET(_GAh,    1e9, ampere_hours);        // 1_GAh (gigaampere-hours)
  SET(_MAh,    1e6, ampere_hours);        // 1_MAh (megaampere-hours)
  SET(_kAh,    1e3, ampere_hours);        // 1_kAh (kiloampere-hours)
  SET( _Ah,      1, ampere_hours);        // 1_Ah  (ampere-hours)
  SET(_mAh,   1e-3, ampere_hours);        // 1_mAh (milliampere-hours)
  SET(_uAh,   1e-6, ampere_hours);        // 1_uAh (microampere-hours)
  SET(_nAh,   1e-9, ampere_hours);        // 1_nAh (nanoampere-hours)
  SET(_pAh,  1e-12, ampere_hours);        // 1_pAh (picoampere-hours)
  // electric capacitance in...
  SET( _F,       1, farads);              // 1_F  (farad)
  SET(_mF,    1e-3, farads);              // 1_mF (millifarad)
  SET(_uF,    1e-6, farads);              // 1_uF (microfarad)
  SET(_nF,    1e-9, farads);              // 1_nF (nanofarad)
  SET(_pF,   1e-12, farads);              // 1_pF (picofarad)
  // electric inductance in...
  SET( _H,       1, henrys);              // 1_H   (henry)
  SET(_mH,    1e-3, henrys);              // 1_mH  (millihenry)
  SET(_uH,    1e-6, henrys);              // 1_uH  (microhenry)
  SET(_nH,    1e-9, henrys);              // 1_nH  (nanohenry)
  // magnetic flux in...
  SET(_Wb,       1, webers);              // 1_Wb  (weber)
  // magnetic field in...
  SET(_kT,     1e3, teslas);              // 1_kT  (kilotesla)
  SET( _T,       1, teslas);              // 1_T   (tesla)
  SET(_mT,    1e-3, teslas);              // 1_mT  (millitesla)
  SET(_uT,    1e-6, teslas);              // 1_uT  (microtesla)
  SET(_nT,    1e-9, teslas);              // 1_nT  (nanotesla)
  // energy in...
  SET(_PJ,    1e15, joules);              // 1_PJ  (petajoule)
  SET(_TJ,    1e12, joules);              // 1_TJ  (terajoule)
  SET(_GJ,     1e9, joules);              // 1_GJ  (gigajoule)
  SET(_MJ,     1e6, joules);              // 1_MJ  (megajoule)
  SET(_kJ,     1e3, joules);              // 1_kJ  (kilojoule)
  SET( _J,       1, joules);              // 1_J   (joule)
  SET(_mJ,    1e-3, joules);              // 1_mJ  (millijoule)
  SET(_kJ_per_mol,1e3,joules_per_mol);    // 1_kJ_per_mol (kJ/mol)
  // or in...
  SET(_Mcal,4186800,joules);              // 1_Mcal (megacalorie)
  SET(_kcal,4186.8, joules);              // 1_kcal (kilocalorie)
  SET( _cal, 4.1868,joules);              // 1_cal  (calorie)
  // active power in...
  SET(_TW,    1e12, watts);               // 1_TW  (terawatt)
  SET(_GW,     1e9, watts);               // 1_GW  (gigawatt)
  SET(_MW,     1e6, watts);               // 1_MW  (megawatt)
  SET(_kW,     1e3, watts);               // 1_kW  (kilowatt)
  SET( _W,       1, watts);               // 1_W   (watt)
  SET(_mW,    1e-3, watts);               // 1_mW  (milliwatt)
  SET(_uW,    1e-6, watts);               // 1_uW  (microwatt)
  SET(_TWh, 3.6e15, watts);               // 1_TWh (terawatt-hour)
  SET(_GWh, 3.6e12, watts);               // 1_GWh (gigawatt-hour)
  SET(_MWh,  3.6e9, watts);               // 1_MWh (megawatt-hour)
  SET(_kWh,  3.6e6, watts);               // 1_kWh (kilowatt-hour)
  SET( _Wh,  3.6e3, watts);               // 1_Wh  (watt-hour)
  // active power per mass in...
  SET(_kWh_per_kg, 3.6e6, joules_per_second_per_kilogram);  // 1_kWh_per_kg (kilowatt-hour per kilogram)
  SET(_Wh_per_kg,  3.6e3, joules_per_second_per_kilogram);  // 1_Wh_per_kg (watt-hour per kilogram)
  // power intensity in...
  SET(_MW_per_m²,1e6, watts_per_meter2);  // 1_MW_per_m² (kilowatt per square metre)
  SET(_kW_per_m²,1e3, watts_per_meter2);  // 1_kW_per_m² (kilowatt per square metre)
  SET(_W_per_m², 1, watts_per_meter2);    // 1_W_per_m² (watt per square metre)
  SET(_mW_per_m²,1e-3, watts_per_meter2); // 1_mW_per_m² (milliwatt per square metre)
  SET(_uW_per_m²,1e-6, watts_per_meter2); // 1_uW_per_m² (milliwatt per square metre)
  // pressure in...
  SET(_GPa,    1e9, pascals);             // 1_GPa (gigapascal) 
  SET(_MPa,    1e6, pascals);             // 1_MPa (megapascal) 
  SET(_kPa,    1e3, pascals);             // 1_kPa (kilopascal) 
  SET(_hPa,    100, pascals);             // 1_hPa (hectopascal) 
  SET( _Pa,      1, pascals);             // 1_Pa  (pascal) 
  SET(_mPa,   1e-3, pascals);             // 1_mPa (millipascal) 
  SET(_uPa,   1e-6, pascals);             // 1_uPa (micropascal) 
  // force in...
  SET(_ZN,    1e21, newtons);             // 1_ZN (zettanewton)
  SET(_EN,    1e18, newtons);             // 1_EN (exanewton)
  SET(_PN,    1e15, newtons);             // 1_PN (petanewton)
  SET(_TN,    1e12, newtons);             // 1_TN (teranewton)
  SET(_GN,     1e9, newtons);             // 1_GN (giganewton)
  SET(_MN,     1e6, newtons);             // 1_MN (meganewton)
  SET(_kN,     1e3, newtons);             // 1_kN (kilonewton)
  SET( _N,       1, newtons);             // 1_N  (newton)
  SET(_mN,    1e-3, newtons);             // 1_mN (millinewton)
  SET(_uN,    1e-6, newtons);             // 1_uN (micronewton)
  SET(_pN,    1e-9, newtons);             // 1_pN (piconewton)
  // luminous flux in...
  SET(_lm,       1, lumens);              // 1_lm       (lumen)
  SET(_lm_s,     1, lumenseconds);        // 1_lm_s     (lumen second)
  SET(_lm_per_W, 1, lumens_per_watt);     // 1_lm_per_W (lumen per watt)
  // luminous flux per area in...
  SET(_klx,    1e3, lux);                 // 1_klx (kilolux)
  SET( _lx,      1, lux);                 // 1_lx  (lux)
  SET(_mlx,   1e-3, lux);                 // 1_mlx (millilux)
  SET(_ulx,   1e-6, lux);                 // 1_ulx (microlux)
  SET(_plx,   1e-9, lux);                 // 1_plx (picolux)
  // catalytic activity in...
  SET( _kat,     1, mols_per_second);     // 1_kat   (katal)
  SET(_mkat,  1e-3, mols_per_second);     // 1_mkat  (millikatal)
  SET(_ukat,  1e-6, mols_per_second);     // 1_mukat (microkatal)
  SET(_nkat,  1e-9, mols_per_second);     // 1_nkat  (nanokatal)
  // other...
  SET(_Nm,       1, newtonmeters);        // 1_Nm  (newtonmeter)
  SET(_sr,       1, steradians);          // 1_sr  (steradian)
  SET(_km³_per_s²,1e9, meters3_per_second2);// 1_km³_per_s² (km³/s²)
  SET(_kg_per_mol,1,kilograms_per_mol);   // 1_kg_per_mol (kg/mol)
  SET(_kg_per_W, 1,kilograms_per_watt);   // 1_kg_per_W (kg/W)
  SET(_kg_per_kW,1e-3,kilograms_per_watt);   // 1_kg_per_kW (kg/kW)
  SET(_rad,      1, radians);             // 1_rad  (radian)
  SET(_mrad,  1e-3, radians);             // 1_mrad (milliradians)
  SET(_deg,0.01745329251994329576923690768489, radians); // 1_deg  (angle degree)

  // Imperial / US Units
  // -------------------
  // length in...
  SET(_in,                        0.0254, meters); // 1_in    (inch)
  SET(_ft,                        0.3048, meters); // 1_ft    (feet, 12 inches)
  SET(_yd,                        0.9144, meters); // 1_yd    (yard)
  SET(_ch,                       20.1168, meters); // 1_ch    (chain)
  SET(_mi,                     1'609.344, meters); // 1_mi    (statute mile, 1760 yd or 80 chains)
  SET(_cable,                      185.2, meters); // 1_cable (one tenth of a nautical mile)
  SET(_nmi,                         1852, meters); // 1_nmi   (nautical mile, about one arc minute)
  SET(_NM,                          1852, meters); // 1_NM    (nautical mile, about one arc minute)
  // mass in...
  SET(_oz,             0.028'349'523'125, kilograms); // 1_oz (ounce, 1/16 of a pound)
  SET(_lb,                  0.453'592'37, kilograms); // 1_lb (pound)
  // Imperial volume in...
  SET(_Imp_gal,               4.54609e-3, meters3); // 1_Imp_gal   (Imperial gallon)
  SET(_Imp_qt,                 1.1365e-3, meters3); // 1_Imp_qt    (Imperial quart)
  SET(_Imp_pt,                 0.5683e-3, meters3); // 1_Imp_pt    (Imperial pint)
  SET(_Imp_cup,     0.284130642624675e-3, meters3); // 1_Imp_cup   (Imperial cup)
  SET(_Imp_gi,         0.142065312500e-3, meters3); // 1_Imp_gi    (Imperial gill)
  SET(_Imp_fl_oz,  0.0284130642624675e-3, meters3); // 1_Imp_fl_oz (Imperial fluid ounce)
  // US volume in...
  SET(_US_gal,            3.785411784e-3, meters3); // 1_US_gal   (US gallon)
  SET(_US_li_qt,                1.101e-3, meters3); // 1_US_qt    (US liquid quart)
  SET(_US_li_pt,          0.473176473e-3, meters3); // 1_US_qt    (US liquid pint)
  SET(_US_cup,           0.2365882365e-3, meters3); // 1_US_cup   (US cup)
  SET(_US_li_gi,       0.118294118250e-3, meters3); // 1_US_gi    (US liquid gill)
  SET(_US_fl_oz,      0.0295735295625e-3, meters3); // 1_US_fl_oz (US fluid ounce)
  // velocity in...
  SET(_kn,                          1852, meters_per_hour);   // 1_kn (knots)
  SET(_ft_per_min,               0.00508, meters_per_second); // 1_ft_per_min (feet/min)
  SET(_in_per_s,                  0.0254, meters_per_second); // 1_in_per_s (inch/sec)
  SET(_in_per_h,            0.0000070556, meters_per_second); // 1_in_per_h (inch/hour)
  SET(_mph,                       .44704, meters_per_second); // 1_mph (miles/hour)
  // temperature in...
  SET(_degF,                           1, fahrenheit); // 1_degF (°Fahrenheit)

  // Astronomical Units (as of IAU 2012)
  // ------------------
  SET(_Gpc,     30'856'775'814'913'673e9, meters);   // 1_Gpc    (gigaparsec)
  SET(_Mpc,     30'856'775'814'913'673e6, meters);   // 1_Mpc    (megaparsec)
  SET(_kpc,     30'856'775'814'913'673e3, meters);   // 1_kpc    (kiloparsec)
  SET(_pc,      30'856'775'814'913'673e0, meters);   // 1_pc     (parsec)
  SET(_ly,         9'460'730'472'580'800, meters);   // 1_ly     (light-year)
  SET(_au,               149'597'870'700, meters);   // 1_au     (astronomical unit, Earth-Sun distance)
  SET(_ls,                   299'792'458, meters);   // 1_ls     (light-second)
  SET(_Msun,                  1.98892e30, kilograms);// 1_Msun   (solar mass, ~1 Sun mass)
  SET(_Mjup,                    1.898e27, kilograms);// 1_Mjup   (Jupiter mass)
  SET(_Mearth,                 5.9742e24, kilograms);// 1_Mearth (Earth mass)
  SET(_Mmoon,              7.34767309e22, kilograms);// 1_Mmoon  (Moon mass)

  // Digital Units
  // -------------
  // bits absolute...
  SET(_bit,                            1, bits);   // 1_bit
  SET(_bits,                           1, bits);   // 2_bits
  SET(_kBit,                         1e3, bits);   // 1_kBit (kilobit)
  SET(_MBit,                         1e6, bits);   // 1_MBit (megabit)
  SET(_GBit,                         1e9, bits);   // 1_GBit (gigabit)
  SET(_TBit,                        1e12, bits);   // 1_TBit (terabit)
  // bits per second...
  SET(_Kbps,                         1e3, bits_per_second); // 1_Kbps (kilobit/sec)
  SET(_Mbps,                         1e6, bits_per_second); // 1_Mbps (megabit/sec)
  SET(_Gbps,                         1e9, bits_per_second); // 1_Gbps (gigabit/sec)
  SET(_Tbps,                        1e12, bits_per_second); // 1_Tbps (terabit/sec)
  // bytes absolute...
  SET(_byte,                           1, bytes);   // 1_byte
  SET(_bytes,                          1, bytes);   // 2_bytes
  SET(_kB,                           1e3, bytes);   // 1_kB  (kilobyte)
  SET(_kiB,                         1024, bytes);   // 1_kiB (kibibyte)
  SET(_MB,                           1e6, bytes);   // 1_MB  (megabyte)
  SET(_MiB,                    1'048'576, bytes);   // 1_MiB (mibibyte)
  SET(_GB,                           1e9, bytes);   // 1_GB  (gigabyte)
  SET(_GiB,                1'073'741'824, bytes);   // 1_GiB (gibibyte)
  SET(_TB,                          1e12, bytes);   // 1_TB  (terabyte)
  SET(_TiB,            1'099'511'627'776, bytes);   // 1_TiB (tebibyte)
  SET(_PB,                          1e15, bytes);   // 1_PB  (petabyte)
  SET(_PiB,        1'125'899'906'842'624, bytes);   // 1_PiB (pebibyte)
  SET(_EB,                          1e18, bytes);   // 1_EB  (exabyte)
  SET(_ZB,                          1e21, bytes);   // 1_ZB  (zettabyte)
  SET(_YB,                          1e24, bytes);   // 1_ZY  (yottabyte)
  SET(_RB,                          1e27, bytes);   // 1_RY  (ronnabyte)
  SET(_QB,                          1e30, bytes);   // 1_QY  (quettabyte)
  // bytes per second...
  SET(_bytes_per_s,                    1, bytes_per_second); // 1_bytes_per_s
  SET(_KBps,                         1e3, bytes_per_second); // 1_KBps  (kilobyte/sec)
  SET(_KiBps,                       1024, bytes_per_second); // 1_KiBps (kibibyte/sec)
  SET(_MBps,                         1e6, bytes_per_second); // 1_MBps  (megabyte/sec)
  SET(_MiBps,                  1'048'576, bytes_per_second); // 1_MiBps (mibibyte/sec)
  SET(_GBps,                         1e9, bytes_per_second); // 1_GBps  (gigabyte/sec)
  SET(_GiBps,              1'073'741'824, bytes_per_second); // 1_GiBps (gibibyte/sec)
  SET(_TBps,                        1e12, bytes_per_second); // 1_TBps  (terabyte/sec)
  SET(_TiBps,          1'099'511'627'776, bytes_per_second); // 1_TiBps (tebibyte/sec)
  SET(_PBps,                        1e15, bytes_per_second); // 1_PBps  (petabyte/sec)

  // Various Units
  // -------------
  SET(_Gbar,                        1e14, pascals);  // 1_Gbar (gigabar)
  SET(_Mbar,                        1e11, pascals);  // 1_Mbar (megabar)
  SET(_kbar,                         1e8, pascals);  // 1_kbar (kilobar)
  SET(_bar,                          1e5, pascals);  // 1_bar 
  SET(_mbar,                         1e2, pascals);  // 1_mbar (millibar)
  SET(_psi,                     6'894.76, pascals);  // 1_psi  (pound per square inch)
  SET(_atm,                      101'325, pascals);  // 1_atm  (atmosphere)
  SET(_inHg,                    3'386.39, pascals);  // 1_inHg (inch of mercury)
  SET(_mmHg,           101'325.0 / 760.0, pascals);  // 1_mmHg (millimetre of mercury)
  SET(_Torr,           101'325.0 / 760.0, pascals);  // 1_Torr (same as mmHg)
  SET(_degC,                           1, celsius);  // 1_degC (°Celsius)
  SET(_degR,                     5.0/9.0, kelvins);  // 1_degR (°Rankine)
  SET(_Mach,                         330, meters_per_second); // 1_Mach
  SET(_Da,        1.660'539'068'9252e-27, kilograms);// 1_Da   (dalton, or unified atomic mass unit)
  SET(_eV,             1.602'176'634e-19, joules);   // 1_eV   (electronvolt, as of 2019 SI)
  SET(_hp,            745.69987158227022, watts);    // 1_hp   (horsepower)
  SET(_shp,           745.69987158227022, watts);    // 1_shp  (shaft horsepower)
  SET(_PS,                     735.49875, watts);    // 1_PS   ('Pferdestärke', german horsepower)
  SET(_Ang,                        1e-10, meters);   // 1_Ang  (angstrom)
  SET(_percent,                     0.01, dimensionless); // 1_percent (%, per hundred)
  SET(_bpm,                     1.0/60.0, hertz);    // 1_bpm  (beats per minute)
  SET(_smoot,                     1.7018, meters);   // 1_smoot (one Oliver R. Smoot height, fun unit)

  // References
  // -------------
  // 1. https://en.wikipedia.org/wiki/International_System_of_Units
  // 2. https://en.wikipedia.org/wiki/Astronomical_system_of_units
  // 3. https://en.wikipedia.org/wiki/Imperial_units

} // end of namespace

#undef SET
