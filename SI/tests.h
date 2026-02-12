// <SI/tests.h> - unit tests at compile-time to verify everything.
//                (sorted by: demo checks, basic C++, SI base units, SI derived units, astronomical units, Imperial units, digital units, various units, function checks)
#pragma once
#include <cassert>
#include <SI/literals.h>

namespace SI { namespace tests {

	// +++ DEMO CHECKS +++ (to show what's possible, the serious checks follow below)
	static_assert(3_m == meters(3));

	static_assert(1_km + 1_m + 1_dm + 1_cm + 1_mm == 1001.111_m);

	static_assert(1_km / 30_min == 2_km_per_h);

	static_assert(1_m * 2_m == 2_m²);

	static_assert(1_m * 2_m * 3_m == 6_m³);

	static_assert((1_m * 2_m * 3_m) / 2_s == 3_m³_per_s);

	static_assert(1000 / 1_s == 1_kHz);

	static_assert(1_Mach == 330_m_per_s);

	static_assert(1_Mach * 10_percent == 33_m_per_s);

	static_assert((0_degC + 32_degF + 491.67_degR + 273.15_K) / 4 == 273.15_K);

	// +++ BASIC C++ +++
	static_assert(sizeof(char) <= sizeof(short));
	static_assert(sizeof(short) <= sizeof(int));
	static_assert(sizeof(int) <= sizeof(long));
	static_assert(sizeof(long) <= sizeof(long long));
	static_assert(sizeof(float) <= sizeof(double));
	static_assert(sizeof(double) <= sizeof(long double));

	static_assert(sizeof(char) == sizeof(unsigned char));
	static_assert(sizeof(short) == sizeof(unsigned short));
	static_assert(sizeof(int) == sizeof(unsigned int));
	static_assert(sizeof(long) == sizeof(unsigned long));

	// +++ SI BASE UNITS +++
	// length in...
	static_assert(1_Gm == 1000_Mm);
	static_assert(1_Mm == 1000_km);
	static_assert(1_km == 1000_m);
	static_assert(1_m  == 10_dm);
	static_assert(1_m  == 100_cm);
	static_assert(1_m  == 1000_mm);
	static_assert(1_m  == 0.001_km);
	static_assert(1_dm == 0.1_m);
	static_assert(1_cm == 0.01_m);
	static_assert(1_mm == 0.001_m);
	static_assert(1_um == 0.001_mm);
	static_assert(1_nm == 0.001_um);
	// time in...
	static_assert(1_day == 24_h);
	static_assert(1_h   == 60_min);
	static_assert(1_min == 60_s);
	static_assert(1_s   == 1000_ms);
	static_assert(1_ms  == 0.001_s);
	static_assert(1_us  == 0.001_ms);
	static_assert(1_ns  == 0.001_us);
	// mass in...
	static_assert(1_Gt == 1000_Mt);
	static_assert(1_Mt == 1000_kt);
	static_assert(1_kt == 1000_t);
	static_assert(1_t  == 1000_kg);
	static_assert(1_kg == 1000_g);
	static_assert(1_g  == 0.001_kg);
	static_assert(1_mg == 0.001_g);
	static_assert(1_ug == 0.001_mg);
	// thermodynamic temperature in...
	static_assert(1_GK == 1000_MK);
	static_assert(1_MK == 1000_kK);
	static_assert(1_kK == 1000_K);
	static_assert(1_mK == 0.001_K);
	static_assert(1_uK == 0.001_mK);
	static_assert(1_nK == 0.001_uK);
	// electric current in...
	static_assert(1_MA == 1000_kA);
	static_assert(1_kA == 1000_A);
	static_assert(1_A  == 1000_mA);
	static_assert(1_mA == 0.001_A);
	static_assert(1_uA == 0.001_mA);
	static_assert(1_nA == 0.001_uA);
	// amount of substance in...
	static_assert(1_Mmol == 1000_kmol);
	static_assert(1_kmol == 1000_mol);
	static_assert(1_mol  == 0.001_kmol);
	static_assert(1_mmol == 0.001_mol);
	static_assert(1_umol == 0.001_mmol);
	static_assert(1_nmol == 0.001_umol);
	// luminous intensity in...
	static_assert(1_kcd == 1000_cd);
	static_assert(1_cd == 0.001_kcd);

	// +++ SI DERIVED UNITS +++
	// area in...
	static_assert(1_km² == 100_hm²);
	static_assert(1_hm² == 10000_m²);
	static_assert(1_m²  == 10000_cm²);
	static_assert(1_cm² == 0.0001_m²);
	static_assert(1_km² == 1_km * 1_km);
	static_assert(1_hm² == 100_m * 100_m);
	static_assert(1_m²  == 1_m * 1_m);
	static_assert(1_cm² == 1_cm * 1_cm);
	static_assert(1_mm² == 1_mm * 1_mm);
	// volume in...
	static_assert(1_m³  == 1'000'000_cm³);
	static_assert(1_cm³ == 0.000'001_m³);
	static_assert(1_km³ == 1_km * 1_km * 1_km);
	static_assert(1_m³  == 1_m * 1_m * 1_m);
	// velocity in...
	static_assert(1_km_per_s == 1000_m_per_s);
	static_assert(3.6_km_per_h == 1_m_per_s);
	static_assert(1_km_per_h == 1_km / 1_h);
	static_assert(1_km_per_h == 1000_m / 1_h);
	static_assert(1_km_per_h == 1_km / 60_min);
	static_assert(1_km_per_h == 1000_m / 60_min);
	static_assert(1_km_per_h == 1_km / 3600_s);
	static_assert(1_km_per_h == 1000_m / 3600_s);
	static_assert(1_km_per_h == 500_m / 1800_s);
	// acceleration in...
	static_assert(1_km_per_s² == 1000_m_per_s²);
	static_assert(0.001_km_per_s² == 1_m_per_s²);
	// frequency in :
	static_assert(1_THz == 1000_GHz);
	static_assert(1_GHz == 1000_MHz);
	static_assert(1_MHz == 1000_kHz);
	static_assert(1_kHz == 1000_Hz);
	static_assert(1_Hz  == 0.001_kHz);
	static_assert(1_Hz  == 0.000001_MHz);
	static_assert(1_Hz  == 0.000000001_GHz);
	static_assert(1_mHz == 0.001_Hz);
	// radioactive activity (A) in...
	static_assert(1_TBq == 1000_GBq);
	static_assert(1_GBq == 1000_MBq);
	static_assert(1_MBq == 1000_kBq);
	static_assert(1_kBq == 1000_Bq);
	// equivalent dose (H) and effective dose (E) in...
	static_assert(1_Sv  == 1000_mSv);
	static_assert(1_mSv == 1000_uSv);
	// mass per area in...
	static_assert(1_t_per_m² == 1000_kg_per_m²);
	// mass per volume in...
	static_assert(1_t_per_m³ == 1000_kg_per_m³);
	// electric potential (U) in...
	static_assert(1_GV == 1000_MV);
	static_assert(1_MV == 1000_kV);
	static_assert(1_kV == 1000_V);
	static_assert(1_V  == 1000_mV);
	static_assert(1_mV == 1000_uV);
	// electric resistance (R) in...
	static_assert(1_GOhm == 1000_MOhm);
	static_assert(1_MOhm == 1000_kOhm);
	static_assert(1_kOhm == 1000_Ohm);
	static_assert(1_Ohm  == 1000_mOhm);
	static_assert(1_mOhm == 1000_uOhm);
	// electric conductance (G) in...
	static_assert(1_MS == 1000_kS);
	static_assert(1_kS == 1000_S);
	static_assert(1_S  == 1000_mS);
	static_assert(1_mS == 1000_uS);
	// electric conductivity (σ) in...
	static_assert(1_MS_per_m == 1000_kS_per_m);
	static_assert(1_kS_per_m == 1000_S_per_m);
	// electric charge (Q) in...
	static_assert(1_GAh == 1000_MAh);
	static_assert(1_MAh == 1000_kAh);
	static_assert(1_kAh == 1000_Ah);
	static_assert(1_Ah  == 1000_mAh);
	static_assert(1_mAh == 1000_uAh);
	// electric capacitance (C) in...
	static_assert(1_F  == 1000_mF);
	static_assert(1_mF == 1000_uF);
	static_assert(1_nF == 1000_pF);
	// electric inductance (L) in...
	static_assert(1_H   == 1000_mH);
	static_assert(1_mH  == 1000_uH);
	// magnetic flux in...
	// magnetic field (B) in...
	static_assert(1_T  == 1000_mT);
	static_assert(1_mT == 1000_uT);
	// energy (E) in...
	static_assert(1_PJ == 1000_TJ);
	static_assert(1_TJ == 1000_GJ);
	static_assert(1_GJ == 1000_MJ);
	static_assert(1_MJ == 1000_kJ);
	static_assert(1_kJ == 1000_J);
	static_assert(1_J  == 1000_mJ);
	// active power (P) in...
	static_assert(1_TW == 1000_GW);
	static_assert(1_GW == 1000_MW);
	static_assert(1_MW == 1000_kW);
	static_assert(1_kW == 1000_W);
	static_assert(1_W  == 1000_mW);
	static_assert(1_mW == 1000_uW);
	// pressure (p) in...
	static_assert(1_MPa == 1000_kPa);
	static_assert(1_kPa == 1000_Pa);
	static_assert(1_Pa  == 1000_mPa);
	static_assert(1_mPa == 1000_uPa);
	// force (F) in...
	static_assert(1_GN == 1000_MN);
	static_assert(1_MN == 1000_kN);
	static_assert(1_kN == 1000_N);
	static_assert(1_N  == 1000_mN);
	static_assert(1_mN == 1000_uN);
	// luminous flux per area in...
	static_assert(1_klx == 1000_lx);
	static_assert(1_lx  == 1000_mlx);
	static_assert(1_mlx == 1000_ulx);
	static_assert(1_ulx == 1000_plx);
	// +++ ASTRONOMICAL UNITS +++
	static_assert(1_Gpc == 1000_Mpc);
	static_assert(1_Mpc == 1000_kpc);
	static_assert(1_kpc == 1000_pc);
	// +++ IMPERIAL UNITS +++
	//static_assert(1_ft == 12_in);
	static_assert(1_nmi == 10_cable);
	static_assert(1_nmi == 1852_m);
	static_assert(1_ft == 0.3048_m);
	// +++ DIGITAL UNITS +++
	static_assert(1_ZB == 1000_EB);
	static_assert(1_EB == 1000_PB);
	static_assert(1_PB == 1000_TB);
	static_assert(1_TB == 1000_GB);
	static_assert(1_GB == 1000_MB);
	static_assert(1_MB == 1000_kB);
	static_assert(1_kB == 1000_byte);

	// +++ VARIOUS UNITS +++
	//static_assert(0_deg == 273.15_K);
	// pressure in...
	static_assert(1_Mbar == 1000_kbar);
	static_assert(1_kbar == 1000_bar);
	static_assert(1_bar  == 1000_mbar);

	// +++ FUNCTION CHECKS +++
	static_assert(abs(-3.5_m) == 3.5_m);
	static_assert(abs(-1_m) == 1_m);
	static_assert(abs(0_m) == 0_m);
	static_assert(abs(1_m) == 1_m);
	static_assert(abs(5.6_m) == 5.6_m);

	static_assert(square(0_m) == 0_m²);
	static_assert(square(1_m) == 1_m²);
	static_assert(square(3_m) == 9_m²);

	// static_assert(sqrt(9_m²) == 3_m); (TODO)

	static_assert(cube(0_m) == 0_m³);
	static_assert(cube(1_m) == 1_m³);
	static_assert(cube(3_m) == 27_m³);

	// static_assert(cbrt(27_m³) == 3_m); (TODO)

	static_assert(clamp(-3_m, 4_m,5_m) == 4_m);
	static_assert(clamp(3_m, 4_m,5_m) == 4_m);
	static_assert(clamp(3_m, 1_m,2_m) == 2_m);
	static_assert(clamp(0_m, -1_m,2_m) == 0_m);

} } // namespace SI::tests
 
// References
// ----------
// 1. https://en.wikipedia.org/wiki/International_System_of_Units
