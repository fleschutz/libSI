/// @file     si/literals.h
/// @brief    Defines 300+ user-defined literals (UDL), e.g. 24_h (supported since C++11)
/// @details  Categories are: SI base units, SI derived units, Imperial units, astronomical units, digital units, various units, and references.

#pragma once
#include <si/units.h>
#define UDL(_literal, _factor, _unit)                                                                                \
  constexpr auto operator "" _literal(long double q) { return _unit(static_cast<SIdouble>(q * _factor ## L)); }      \
  constexpr auto operator "" _literal(unsigned long long q) { return _unit(static_cast<SIdouble>(q * _factor ## L)); }

namespace si {

  // SI Base Units
  // -------------

  // SYMBOL FACTOR  BASE UNIT             EXAMPLE (sorted from big units to small one)
  // -------------------------------------------------------------
  // length in...
  UDL(_Pm,    1e15, meters);              // 1_Pm (petameter)
  UDL(_Tm,    1e12, meters);              // 1_Tm (terameter)
  UDL(_Gm,     1e9, meters);              // 1_Gm (gigameter)
  UDL(_Mm,     1e6, meters);              // 1_Mm (megameter)
  UDL(_km,     1e3, meters);              // 1_km (kilometer)
  UDL( _m,       1, meters);              // 1_m  (meter)
  UDL(_dm,    1e-1, meters);              // 1_dm (decimeter)
  UDL(_cm,    1e-2, meters);              // 1_cm (centimeter)
  UDL(_mm,    1e-3, meters);              // 1_mm (millimeter)
  UDL(_um,    1e-6, meters);              // 1_um (micrometer)
  UDL(_nm,    1e-9, meters);              // 1_nm (nanometer)
  UDL(_pm,   1e-12, meters);              // 1_pm (picometer)
  // time in...
  UDL(_w,  604'800, seconds);             // 1_w   (Earth week)
  UDL(_d,    86400, seconds);             // 1_d   (Earth day)
  UDL(_days, 86400, seconds);             // 2_days(Earth days)
  UDL(_h,     3600, seconds);             // 1_h   (hour)
  UDL(_min,     60, seconds);             // 1_min (minute)
  UDL( _s,       1, seconds);             // 1_s   (second)
  UDL(_ms,    1e-3, seconds);             // 1_ms  (millisecond)
  UDL(_us,    1e-6, seconds);             // 1_us  (microsecond)
  UDL(_ns,    1e-9, seconds);             // 1_ns  (nanosecond)
  UDL(_ps,   1e-12, seconds);             // 1_ps  (picosecond)
  // mass in...
  UDL(_Pt,    1e18, kilograms);           // 1_Pt (metric petaton)
  UDL(_Tt,    1e15, kilograms);           // 1_Tt (metric teraton)
  UDL(_Gt,    1e12, kilograms);           // 1_Gt (metric gigaton)
  UDL(_Mt,     1e9, kilograms);           // 1_Mt (metric megaton)
  UDL(_kt,     1e6, kilograms);           // 1_kt (metric kiloton)
  UDL( _t,     1e3, kilograms);           // 1_t  (metric ton)
  UDL(_kg,       1, kilograms);           // 1_kg (kilogram)
  UDL( _g,    1e-3, kilograms);           // 1_g  (gram)
  UDL(_mg,    1e-6, kilograms);           // 1_mg (milligram)
  UDL(_ug,    1e-9, kilograms);           // 1_ug (microgram)
  UDL(_ng,   1e-12, kilograms);           // 1_ng (nanogram)
  // thermodynamic temperature in...
  UDL(_GK,     1e9, kelvins);             // 1_GK (gigakelvin)
  UDL(_MK,     1e6, kelvins);             // 1_MK (megakelvin)
  UDL(_kK,     1e3, kelvins);             // 1_kK (kilokelvin)
  UDL( _K,       1, kelvins);             // 1_K  (kelvin)
  UDL(_mK,    1e-3, kelvins);             // 1_mK (millikelvin)
  UDL(_uK,    1e-6, kelvins);             // 1_uK (microkelvin)
  UDL(_nK,    1e-9, kelvins);             // 1_nK (nanokelvin)
  // electric current in...
  UDL(_GA,     1e9, amperes);             // 1_GA  (gigaampere)
  UDL(_MA,     1e6, amperes);             // 1_MA  (megaampere)
  UDL(_kA,     1e3, amperes);             // 1_kA  (kiloampere)
  UDL( _A,       1, amperes);             // 1_A   (ampere)
  UDL(_mA,    1e-3, amperes);             // 1_mA  (milliampere)
  UDL(_uA,    1e-6, amperes);             // 1_uA  (microampere)
  UDL(_nA,    1e-9, amperes);             // 1_nA  (nanoampere)
  UDL(_pA,   1e-12, amperes);             // 1_pA  (picoampere)
  // amount of substance in...
  UDL(_Gmol,   1e9, moles);               // 1_Gmol (gigamole)
  UDL(_Mmol,   1e6, moles);               // 1_Mmol (megamole)
  UDL(_kmol,   1e3, moles);               // 1_kmol (kilomole)
  UDL( _mol,     1, moles);               // 1_mol  (mole)
  UDL(_mmol,  1e-3, moles);               // 1_mmol (millimole)
  UDL(_umol,  1e-6, moles);               // 1_umol (micromole)
  UDL(_nmol,  1e-9, moles);               // 1_nmol (nanomole)
  UDL(_pmol, 1e-12, moles);               // 1_pmol (picomole)
  UDL(_fmol, 1e-15, moles);               // 1_fmol (femtomole)
  // luminous intensity in...
  UDL(_kcd,    1e3, candelas);            // 1_kcd (kilocandela)
  UDL( _cd,      1, candelas);            // 1_cd  (candela)

  // SI Derived Units
  // ----------------
  // area in...
  UDL(_km²,    1e6, meters2);             // 1_km² (square kilometer)
  UDL(_hm²,    1e4, meters2);             // 1_hm² (hectare)
  UDL( _m²,      1, meters2);             // 1_m²  (square meter)
  UDL(_cm²,   1e-4, meters2);             // 1_cm² (square centimeter)
  UDL(_mm²,   1e-6, meters2);             // 1_mm² (square millimeter)
  UDL(_um²,  1e-12, meters2);             // 1_um² (square micrometer)
  // per area in...
  UDL(_per_km²,1e-6, per_meter2);         // 1_per_km² (per square kilometer)
  UDL(_per_hm²,1e-4, per_meter2);         // 1_per_hm² (per hectare)
  UDL(_per_m²,    1, per_meter2);         // 1_per_m²  (per square meter)
  UDL(_per_cm², 1e4, per_meter2);         // 1_per_cm² (per square centimeter)
  UDL(_per_mm², 1e6, per_meter2);         // 1_per_mm² (per square millimeter)
  UDL(_per_μm²,1e12, per_meter2);         // 1_per μm² (per square micrometer)
  // surface flow in...
  UDL(_m²_per_s, 1, meters2_per_second);  // 1_m²/s (square meter per second)
  // volume in cubic meter in...
  UDL(_km³,    1e9, meters3);             // 1_km³ (cubic kilometer)
  UDL( _m³,      1, meters3);             // 1_m³  (cubic meter)
  UDL(_dm³,   1e-3, meters3);             // 1_dm³ (cubic decimeter)
  UDL(_cm³,   1e-6, meters3);             // 1_cm³ (cubic centimeter, aka ccm)
  UDL(_mm³,   1e-9, meters3);             // 1_mm³ (cubic millimeter)
  UDL(_um³,  1e-18, meters3);             // 1_um³ (cubic micrometer)
  // volume in liter in...
  UDL(_Ml,     1e3, meters3);             // 1_Ml (megaliter)
  UDL(_kl,       1, meters3);             // 1_kl (kiloliter)
  UDL(_hl,     0.1, meters3);             // 1_hl (hectoliter)
  UDL( _l,    1e-3, meters3);             // 1_l  (liter)
  UDL(_ml,    1e-6, meters3);             // 1_ml (milliliter)
  UDL(_ul,    1e-9, meters3);             // 1_ul (microliter)
  UDL(_nl,   1e-12, meters3);             // 1_nl (nanoliter)
  UDL(_pl,   1e-15, meters3);             // 1_pl (picoliter)
  // volumetric flow in...
  UDL(_m³_per_s, 1, meters3_per_second);   // 1_m³/s (cubic meter per second)
  UDL(_l_per_min,1.0/60000.0, meters3_per_second);   // 1_l_per_min (liter per minute)
  UDL(_l_per_s, 1e-3, meters3_per_second); // 1_l_per_s (liter per second)
  // velocity per second in...
  UDL(_km_per_s, 1e3, meters_per_second); // 1_km_per_s (km/s)
  UDL(_m_per_s,  1, meters_per_second);   // 1_m_per_s  (m/s)
  UDL(_mm_per_s, 1e-3, meters_per_second);// 1_mm_per_s (mm/s)
  // velocity per hour in...
  UDL(_km_per_h, 1e3, meters_per_hour);   // 1_km_per_h (km/h)
  UDL(_m_per_h,  1, meters_per_hour);     // 1_m_per_h  (m/h)
  UDL(_mm_per_h, 1e-3, meters_per_hour);  // 1_mm_per_h (mm/h)
  // acceleration in...
  UDL(_km_per_s²,1e3, meters_per_second2);// 1_km_per_s² (km/s²)
  UDL(_m_per_s², 1, meters_per_second2);  // 1_m_per_s²  (m/s²)
  // frequency in...
  UDL(_PHz,   1e15, hertz);               // 1_PHz (petahertz)
  UDL(_THz,   1e12, hertz);               // 1_THz (terahertz)
  UDL(_GHz,    1e9, hertz);               // 1_GHz (gigahertz)
  UDL(_MHz,    1e6, hertz);               // 1_MHz (megahertz)
  UDL(_kHz,    1e3, hertz);               // 1_kHz (kilohertz)
  UDL( _Hz,      1, hertz);               // 1_Hz  (hertz)
  UDL(_mHz,   1e-3, hertz);               // 1_mHz (millihertz)
  UDL(_uHz,   1e-6, hertz);               // 1_uHz (microhertz)
  // radioactive activity in...
  UDL(_TBq,   1e12, hertz);               // 1_TBq (terabecquerel)
  UDL(_GBq,    1e9, hertz);               // 1_GBq (gigabecquerel)
  UDL(_MBq,    1e6, hertz);               // 1_MBq (megabecquerel)
  UDL(_kBq,    1e3, hertz);               // 1_kBq (kilobecquerel)
  UDL( _Bq,      1, hertz);               // 1_Bq  (becquerel)
  // absorbed dose in...
  UDL( _Gy,      1, grays);               // 1_Gy  (gray)
  UDL(_mGy,   1e-3, grays);               // 1_mGy (milligray)
  UDL(_uGy,   1e-6, grays);               // 1_uGy (microgray)
  // equivalent dose and effective dose in...
  UDL( _Sv,      1, sieverts);            // 1_Sv  (sievert)
  UDL(_mSv,   1e-3, sieverts);            // 1_mSv (millisievert)
  UDL(_uSv,   1e-6, sieverts);            // 1_uSv (microsievert)
  // mass per area in...
  UDL(_t_per_m², 1e3, kilograms_per_meter2);// 1_t_per_m²
  UDL(_kg_per_m²,  1, kilograms_per_meter2);// 1_kg_per_m²
  // density in...
  UDL(_t_per_m³, 1e3, kilograms_per_meter3);   // 1_t_per_m³
  UDL(_kg_per_m³,  1, kilograms_per_meter3);   // 1_kg_per_m³
  UDL(_g_per_m³,1e-3, kilograms_per_meter3);   // 1_g_per_m³
  UDL(_mg_per_m³,1e-9, kilograms_per_meter3);  // 1_mg_per_m³
  UDL(_kg_per_cm³,1e-6, kilograms_per_meter3); // 1_kg_per_cm³
  UDL(_g_per_cm³,1e3, kilograms_per_meter3);   // 1_g_per_cm³
  // electric potential in...
  UDL(_GV,     1e9, volts);               // 1_GV (gigavolt)
  UDL(_MV,     1e6, volts);               // 1_MV (megavolt)
  UDL(_kV,     1e3, volts);               // 1_kV (kilovolt)
  UDL( _V,       1, volts);               // 1_V 
  UDL(_mV,    1e-3, volts);               // 1_mV (millivolt)
  UDL(_uV,    1e-6, volts);               // 1_uV (microvolt)
  UDL(_nV,    1e-9, volts);               // 1_nV (nanovolt)
  UDL(_pV,   1e-12, volts);               // 1_pV (picovolt)
  // electric resistance in...
  UDL(_GOhm,   1e9, ohms);                // 1_GOhm (gigaohm)
  UDL(_MOhm,   1e6, ohms);                // 1_MOhm (megaohm)
  UDL(_kOhm,   1e3, ohms);                // 1_kOhm (kiloohm)
  UDL( _Ohm,     1, ohms);                // 1_Ohm
  UDL(_mOhm,  1e-3, ohms);                // 1_mOhm (milliohm)
  UDL(_uOhm,  1e-6, ohms);                // 1_uOhm (microohm)
  // electric resistance meter in...
  UDL(_Ohm_m,    1, ohm_meters);          // 1_Ohm_m (ohm meter)
  // electric conductance in...
  UDL(_GS,     1e9, siemens);             // 1_GS (gigasiemens)
  UDL(_MS,     1e6, siemens);             // 1_MS (megasiemens)
  UDL(_kS,     1e3, siemens);             // 1_kS (kilosiemens)
  UDL( _S,       1, siemens);             // 1_S  (siemens)
  UDL(_mS,    1e-3, siemens);             // 1_mS (millisiemens)
  UDL(_uS,    1e-6, siemens);             // 1_uS (microsiemens)
  UDL(_nS,    1e-9, siemens);             // 1_nS (nanosiemens)
  // electric conductivity in...
  UDL(_MS_per_m,1e6, siemens_per_meter);  // 1_MS_per_m (MS/m, megasiemens per meter)
  UDL(_kS_per_m,1e3, siemens_per_meter);  // 1_kS_per_m (kS/m, kilosiemens per meter)
  UDL( _S_per_m,  1, siemens_per_meter);   // 1_S_per_m (S/m, siemens per meter)
  // electric charge in coulombs in...
  UDL(_GC,     1e9, coulombs);            // 1_GC (gigaoulomb)
  UDL(_MC,     1e6, coulombs);            // 1_MC (megaoulomb)
  UDL(_kC,     1e3, coulombs);            // 1_kC (kilocoulomb)
  UDL( _C,       1, coulombs);            // 1_C  (coulomb)
  UDL(_mC,    1e-3, coulombs);            // 1_mC (millicoulomb)
  UDL(_uC,    1e-6, coulombs);            // 1_uC (microcoulomb)
  UDL(_nC,    1e-9, coulombs);            // 1_nC (nanocoulomb)
  UDL(_pC,   1e-12, coulombs);            // 1_pC (picocoulomb)
  // electric charge in ampere-hours in...
  UDL(_GAh,    1e9, ampere_hours);        // 1_GAh (gigaampere-hours)
  UDL(_MAh,    1e6, ampere_hours);        // 1_MAh (megaampere-hours)
  UDL(_kAh,    1e3, ampere_hours);        // 1_kAh (kiloampere-hours)
  UDL( _Ah,      1, ampere_hours);        // 1_Ah  (ampere-hours)
  UDL(_mAh,   1e-3, ampere_hours);        // 1_mAh (milliampere-hours)
  UDL(_uAh,   1e-6, ampere_hours);        // 1_uAh (microampere-hours)
  UDL(_nAh,   1e-9, ampere_hours);        // 1_nAh (nanoampere-hours)
  UDL(_pAh,  1e-12, ampere_hours);        // 1_pAh (picoampere-hours)
  // electric capacitance in...
  UDL( _F,       1, farads);              // 1_F  (farad)
  UDL(_mF,    1e-3, farads);              // 1_mF (millifarad)
  UDL(_uF,    1e-6, farads);              // 1_uF (microfarad)
  UDL(_nF,    1e-9, farads);              // 1_nF (nanofarad)
  UDL(_pF,   1e-12, farads);              // 1_pF (picofarad)
  // electric inductance in...
  UDL( _H,       1, henrys);              // 1_H   (henry)
  UDL(_mH,    1e-3, henrys);              // 1_mH  (millihenry)
  UDL(_uH,    1e-6, henrys);              // 1_uH  (microhenry)
  UDL(_nH,    1e-9, henrys);              // 1_nH  (nanohenry)
  // magnetic flux in...
  UDL(_Wb,       1, webers);              // 1_Wb  (weber)
  // magnetic field in...
  UDL(_kT,     1e3, teslas);              // 1_kT  (kilotesla)
  UDL( _T,       1, teslas);              // 1_T   (tesla)
  UDL(_mT,    1e-3, teslas);              // 1_mT  (millitesla)
  UDL(_uT,    1e-6, teslas);              // 1_uT  (microtesla)
  UDL(_nT,    1e-9, teslas);              // 1_nT  (nanotesla)
  // energy in...
  UDL(_PJ,    1e15, joules);              // 1_PJ  (petajoule)
  UDL(_TJ,    1e12, joules);              // 1_TJ  (terajoule)
  UDL(_GJ,     1e9, joules);              // 1_GJ  (gigajoule)
  UDL(_MJ,     1e6, joules);              // 1_MJ  (megajoule)
  UDL(_kJ,     1e3, joules);              // 1_kJ  (kilojoule)
  UDL( _J,       1, joules);              // 1_J   (joule)
  UDL(_mJ,    1e-3, joules);              // 1_mJ  (millijoule)
  UDL(_kJ_per_mol,1e3,joules_per_mol);    // 1_kJ_per_mol (kJ/mol)
  // or in...
  UDL(_Mcal,4186800,joules);              // 1_Mcal (megacalorie)
  UDL(_kcal,4186.8, joules);              // 1_kcal (kilocalorie)
  UDL( _cal, 4.1868,joules);              // 1_cal  (calorie)
  // active power in...
  UDL(_TW,    1e12, watts);               // 1_TW  (terawatt)
  UDL(_GW,     1e9, watts);               // 1_GW  (gigawatt)
  UDL(_MW,     1e6, watts);               // 1_MW  (megawatt)
  UDL(_kW,     1e3, watts);               // 1_kW  (kilowatt)
  UDL( _W,       1, watts);               // 1_W   (watt)
  UDL(_mW,    1e-3, watts);               // 1_mW  (milliwatt)
  UDL(_uW,    1e-6, watts);               // 1_uW  (microwatt)
  UDL(_TWh, 3.6e15, watts);               // 1_TWh (terawatt-hour)
  UDL(_GWh, 3.6e12, watts);               // 1_GWh (gigawatt-hour)
  UDL(_MWh,  3.6e9, watts);               // 1_MWh (megawatt-hour)
  UDL(_kWh,  3.6e6, watts);               // 1_kWh (kilowatt-hour)
  UDL( _Wh,  3.6e3, watts);               // 1_Wh  (watt-hour)
  // active power per mass in...
  UDL(_kWh_per_kg, 3.6e6, joules_per_second_per_kilogram);  // 1_kWh_per_kg (kilowatt-hour per kilogram)
  UDL(_Wh_per_kg,  3.6e3, joules_per_second_per_kilogram);  // 1_Wh_per_kg (watt-hour per kilogram)
  // power intensity in...
  UDL(_MW_per_m²,1e6, watts_per_meter2);  // 1_MW_per_m² (kilowatt per square metre)
  UDL(_kW_per_m²,1e3, watts_per_meter2);  // 1_kW_per_m² (kilowatt per square metre)
  UDL(_W_per_m², 1, watts_per_meter2);    // 1_W_per_m² (watt per square metre)
  UDL(_mW_per_m²,1e-3, watts_per_meter2); // 1_mW_per_m² (milliwatt per square metre)
  UDL(_uW_per_m²,1e-6, watts_per_meter2); // 1_uW_per_m² (milliwatt per square metre)
  // pressure in...
  UDL(_GPa,    1e9, pascals);             // 1_GPa (gigapascal) 
  UDL(_MPa,    1e6, pascals);             // 1_MPa (megapascal) 
  UDL(_kPa,    1e3, pascals);             // 1_kPa (kilopascal) 
  UDL(_hPa,    100, pascals);             // 1_hPa (hectopascal) 
  UDL( _Pa,      1, pascals);             // 1_Pa  (pascal) 
  UDL(_mPa,   1e-3, pascals);             // 1_mPa (millipascal) 
  UDL(_uPa,   1e-6, pascals);             // 1_uPa (micropascal) 
  // force in...
  UDL(_ZN,    1e21, newtons);             // 1_ZN (zettanewton)
  UDL(_EN,    1e18, newtons);             // 1_EN (exanewton)
  UDL(_PN,    1e15, newtons);             // 1_PN (petanewton)
  UDL(_TN,    1e12, newtons);             // 1_TN (teranewton)
  UDL(_GN,     1e9, newtons);             // 1_GN (giganewton)
  UDL(_MN,     1e6, newtons);             // 1_MN (meganewton)
  UDL(_kN,     1e3, newtons);             // 1_kN (kilonewton)
  UDL( _N,       1, newtons);             // 1_N  (newton)
  UDL(_mN,    1e-3, newtons);             // 1_mN (millinewton)
  UDL(_uN,    1e-6, newtons);             // 1_uN (micronewton)
  UDL(_nN,    1e-9, newtons);             // 1_nN (nanonewton)
  UDL(_pN,   1e-12, newtons);             // 1_pN (piconewton)
  // luminous flux in...
  UDL(_lm,       1, lumens);              // 1_lm       (lumen)
  UDL(_lm_s,     1, lumenseconds);        // 1_lm_s     (lumen second)
  UDL(_lm_per_W, 1, lumens_per_watt);     // 1_lm_per_W (lumen per watt)
  // luminous flux per area in...
  UDL(_klx,    1e3, lux);                 // 1_klx (kilolux)
  UDL( _lx,      1, lux);                 // 1_lx  (lux)
  UDL(_mlx,   1e-3, lux);                 // 1_mlx (millilux)
  UDL(_ulx,   1e-6, lux);                 // 1_ulx (microlux)
  UDL(_nlx,   1e-9, lux);                 // 1_nlx (nanolux)
  UDL(_plx,  1e-12, lux);                 // 1_plx (picolux)
  // catalytic activity in...
  UDL( _kat,     1, mols_per_second);     // 1_kat   (katal)
  UDL(_mkat,  1e-3, mols_per_second);     // 1_mkat  (millikatal)
  UDL(_ukat,  1e-6, mols_per_second);     // 1_mukat (microkatal)
  UDL(_nkat,  1e-9, mols_per_second);     // 1_nkat  (nanokatal)
  // other...
  UDL(_Nm,       1, newtonmeters);        // 1_Nm  (newtonmeter)
  UDL(_sr,       1, steradians);          // 1_sr  (steradian)
  UDL(_km³_per_s²,1e9, meters3_per_second2);// 1_km³_per_s² (km³/s²)
  UDL(_kg_per_mol,1,kilograms_per_mol);   // 1_kg_per_mol (kg/mol)
  UDL(_kg_per_W, 1,kilograms_per_watt);   // 1_kg_per_W (kg/W)
  UDL(_kg_per_kW,1e-3,kilograms_per_watt);   // 1_kg_per_kW (kg/kW)
  UDL(_rad,      1, radians);             // 1_rad  (radian)
  UDL(_mrad,  1e-3, radians);             // 1_mrad (milliradians)
  UDL(_deg,0.01745329251994329576923690768489, radians); // 1_deg  (angle degree)

  // Imperial / US Units
  // -------------------
  // length in...
  UDL(_in,                        0.0254, meters); // 1_in    (inch)
  UDL(_ft,                        0.3048, meters); // 1_ft    (feet, 12 inches)
  UDL(_yd,                        0.9144, meters); // 1_yd    (yard)
  UDL(_ch,                       20.1168, meters); // 1_ch    (chain)
  UDL(_mi,                     1'609.344, meters); // 1_mi    (statute mile, 1760 yd or 80 chains)
  UDL(_cable,                      185.2, meters); // 1_cable (one tenth of a nautical mile)
  UDL(_nmi,                         1852, meters); // 1_nmi   (nautical mile, about one arc minute)
  UDL(_NM,                          1852, meters); // 1_NM    (nautical mile, about one arc minute)
  // mass in...
  UDL(_oz,             0.028'349'523'125, kilograms); // 1_oz (ounce, 1/16 of a pound)
  UDL(_lb,                  0.453'592'37, kilograms); // 1_lb (pound)
  // Imperial volume in...
  UDL(_Imp_gal,               4.54609e-3, meters3); // 1_Imp_gal   (Imperial gallon)
  UDL(_Imp_qt,                 1.1365e-3, meters3); // 1_Imp_qt    (Imperial quart)
  UDL(_Imp_pt,                 0.5683e-3, meters3); // 1_Imp_pt    (Imperial pint)
  UDL(_Imp_cup,     0.284130642624675e-3, meters3); // 1_Imp_cup   (Imperial cup)
  UDL(_Imp_gi,         0.142065312500e-3, meters3); // 1_Imp_gi    (Imperial gill)
  UDL(_Imp_fl_oz,  0.0284130642624675e-3, meters3); // 1_Imp_fl_oz (Imperial fluid ounce)
  // US volume in...
  UDL(_US_gal,            3.785411784e-3, meters3); // 1_US_gal   (US gallon)
  UDL(_US_li_qt,                1.101e-3, meters3); // 1_US_qt    (US liquid quart)
  UDL(_US_li_pt,          0.473176473e-3, meters3); // 1_US_qt    (US liquid pint)
  UDL(_US_cup,           0.2365882365e-3, meters3); // 1_US_cup   (US cup)
  UDL(_US_li_gi,       0.118294118250e-3, meters3); // 1_US_gi    (US liquid gill)
  UDL(_US_fl_oz,      0.0295735295625e-3, meters3); // 1_US_fl_oz (US fluid ounce)
  // velocity in...
  UDL(_kn,                          1852, meters_per_hour);   // 1_kn (knots)
  UDL(_ft_per_min,               0.00508, meters_per_second); // 1_ft_per_min (feet/min)
  UDL(_in_per_s,                  0.0254, meters_per_second); // 1_in_per_s (inch/sec)
  UDL(_in_per_h,            0.0000070556, meters_per_second); // 1_in_per_h (inch/hour)
  UDL(_mph,                       .44704, meters_per_second); // 1_mph (miles/hour)
  // temperature in...
  UDL(_degF,                           1, fahrenheit); // 1_degF (°Fahrenheit)

  // Astronomical Units (as of IAU 2012)
  // ------------------
  UDL(_Gpc,     30'856'775'814'913'673e9, meters);   // 1_Gpc    (gigaparsec)
  UDL(_Mpc,     30'856'775'814'913'673e6, meters);   // 1_Mpc    (megaparsec)
  UDL(_kpc,     30'856'775'814'913'673e3, meters);   // 1_kpc    (kiloparsec)
  UDL(_pc,      30'856'775'814'913'673e0, meters);   // 1_pc     (parsec)
  UDL(_ly,         9'460'730'472'580'800, meters);   // 1_ly     (light-year)
  UDL(_au,               149'597'870'700, meters);   // 1_au     (astronomical unit, Earth-Sun distance)
  UDL(_ls,                   299'792'458, meters);   // 1_ls     (light-second)
  UDL(_Msun,                  1.98892e30, kilograms);// 1_Msun   (solar mass, ~1 Sun mass)
  UDL(_Mjup,                    1.898e27, kilograms);// 1_Mjup   (Jupiter mass)
  UDL(_Mearth,                 5.9742e24, kilograms);// 1_Mearth (Earth mass)
  UDL(_Mmoon,              7.34767309e22, kilograms);// 1_Mmoon  (Moon mass)

  // Digital Units
  // -------------
  // bits...
  UDL(_bit,                            1, bits);   // 1_bit
  UDL(_bits,                           1, bits);   // 2_bits
  UDL(_kBit,                         1e3, bits);   // 1_kBit (kilobit)
  UDL(_MBit,                         1e6, bits);   // 1_MBit (megabit)
  UDL(_GBit,                         1e9, bits);   // 1_GBit (gigabit)
  UDL(_TBit,                        1e12, bits);   // 1_TBit (terabit)
  // bits per second...
  UDL(_Kbps,                         1e3, bits_per_second); // 1_Kbps (kilobit/sec)
  UDL(_Mbps,                         1e6, bits_per_second); // 1_Mbps (megabit/sec)
  UDL(_Gbps,                         1e9, bits_per_second); // 1_Gbps (gigabit/sec)
  UDL(_Tbps,                        1e12, bits_per_second); // 1_Tbps (terabit/sec)
  // bytes in metric prefixes...
  UDL(_byte,                           1, bytes);   // 1_byte
  UDL(_bytes,                          1, bytes);   // 2_bytes
  UDL(_kB,                           1e3, bytes);   // 1_kB  (kilobyte)
  UDL(_MB,                           1e6, bytes);   // 1_MB  (megabyte)
  UDL(_GB,                           1e9, bytes);   // 1_GB  (gigabyte)
  UDL(_TB,                          1e12, bytes);   // 1_TB  (terabyte)
  UDL(_PB,                          1e15, bytes);   // 1_PB  (petabyte)
  UDL(_EB,                          1e18, bytes);   // 1_EB  (exabyte)
  UDL(_ZB,                          1e21, bytes);   // 1_ZB  (zettabyte)
  UDL(_YB,                          1e24, bytes);   // 1_ZY  (yottabyte)
  UDL(_RB,                          1e27, bytes);   // 1_RY  (ronnabyte)
  UDL(_QB,                          1e30, bytes);   // 1_QY  (quettabyte)
  // bytes in binary prefixes...
  UDL(_KiB,                         1024, bytes);   // 1_KiB (kibibyte)
  UDL(_MiB,                    1'048'576, bytes);   // 1_MiB (mibibyte)
  UDL(_GiB,                1'073'741'824, bytes);   // 1_GiB (gibibyte)
  UDL(_TiB,            1'099'511'627'776, bytes);   // 1_TiB (tebibyte)
  UDL(_PiB,        1'125'899'906'842'624, bytes);   // 1_PiB (pebibyte)
  // bytes per second...
  UDL(_bytes_per_s,                    1, bytes_per_second); // 1_bytes_per_s
  UDL(_KBps,                         1e3, bytes_per_second); // 1_KBps  (kilobyte/sec)
  UDL(_KiBps,                       1024, bytes_per_second); // 1_KiBps (kibibyte/sec)
  UDL(_MBps,                         1e6, bytes_per_second); // 1_MBps  (megabyte/sec)
  UDL(_MiBps,                  1'048'576, bytes_per_second); // 1_MiBps (mibibyte/sec)
  UDL(_GBps,                         1e9, bytes_per_second); // 1_GBps  (gigabyte/sec)
  UDL(_GiBps,              1'073'741'824, bytes_per_second); // 1_GiBps (gibibyte/sec)
  UDL(_TBps,                        1e12, bytes_per_second); // 1_TBps  (terabyte/sec)
  UDL(_TiBps,          1'099'511'627'776, bytes_per_second); // 1_TiBps (tebibyte/sec)
  UDL(_PBps,                        1e15, bytes_per_second); // 1_PBps  (petabyte/sec)

  // Various Units
  // -------------
  UDL(_Gbar,                        1e14, pascals);  // 1_Gbar (gigabar)
  UDL(_Mbar,                        1e11, pascals);  // 1_Mbar (megabar)
  UDL(_kbar,                         1e8, pascals);  // 1_kbar (kilobar)
  UDL(_bar,                          1e5, pascals);  // 1_bar 
  UDL(_mbar,                         1e2, pascals);  // 1_mbar (millibar)
  UDL(_psi,                     6'894.76, pascals);  // 1_psi  (pound per square inch)
  UDL(_atm,                      101'325, pascals);  // 1_atm  (atmosphere)
  UDL(_inHg,                    3'386.39, pascals);  // 1_inHg (inch of mercury)
  UDL(_mmHg,           101'325.0 / 760.0, pascals);  // 1_mmHg (millimetre of mercury)
  UDL(_Torr,           101'325.0 / 760.0, pascals);  // 1_Torr (same as mmHg)
  UDL(_degC,                           1, celsius);  // 1_degC (°Celsius)
  UDL(_degR,                     5.0/9.0, kelvins);  // 1_degR (°Rankine)
  UDL(_Mach,                         330, meters_per_second); // 1_Mach
  UDL(_Da,        1.660'539'068'9252e-27, kilograms);// 1_Da   (dalton, or unified atomic mass unit)
  UDL(_eV,             1.602'176'634e-19, joules);   // 1_eV   (electronvolt, as of 2019 SI)
  UDL(_hp,            745.69987158227022, watts);    // 1_hp   (horsepower)
  UDL(_shp,           745.69987158227022, watts);    // 1_shp  (shaft horsepower)
  UDL(_PS,                     735.49875, watts);    // 1_PS   ('Pferdestärke', german horsepower)
  UDL(_Ang,                        1e-10, meters);   // 1_Ang  (angstrom)
  UDL(_percent,                     0.01, dimensionless); // 1_percent (%, per hundred)
  UDL(_bpm,                     1.0/60.0, hertz);    // 1_bpm  (beats per minute)
  UDL(_smoot,                     1.7018, meters);   // 1_smoot (one Oliver R. Smoot height, fun unit)

  // References
  // -------------
  // 1. https://en.wikipedia.org/wiki/International_System_of_Units
  // 2. https://en.wikipedia.org/wiki/Astronomical_system_of_units
  // 3. https://en.wikipedia.org/wiki/Imperial_units

} // end of namespace

#undef UDL
