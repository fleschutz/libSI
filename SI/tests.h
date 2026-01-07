// SI/tests.h - unit tests to check SI-lib's functionality.
#pragma once

#include <cassert>
#include "literals.h"

namespace SI
{
	// Let's begin with some sample checks to demonstrate what's possible: (the serious checks follow below)

	static_assert(1_km + 1_m + 1_dm + 1_cm + 1_mm == 1001.111_m);

	static_assert(1_km / 30_min == 2_km_per_h);

	static_assert(1_m * 2_m == 2_m²);

	static_assert(1_m * 2_m * 3_m == 6_m³);

	static_assert((1_m * 2_m * 3_m) / 2_s == 3_m³_per_s);

	static_assert(1000 / 1_s == 1_kHz);

	static_assert(1_Mach == 330_m_per_s);

	static_assert(1_Mach * 10_percent == 33_m_per_s);


	// Let's check the 7 SI base units:
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
	// time in...
	static_assert(1_h   == 60_min);
	static_assert(1_min == 60_s);
	static_assert(1_s   == 1000_ms);
	static_assert(1_ms  == 0.001_s);
	static_assert(1_us  == 0.001_ms);
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
	static_assert(1_kmol == 1000_mol);
	static_assert(1_mol  == 0.001_kmol);
	static_assert(1_mmol == 0.001_mol);
	static_assert(1_umol == 0.001_mmol);
	static_assert(1_nmol == 0.001_umol);
	// luminous intensity in...
	static_assert(1_kcd == 1000_cd);
	static_assert(1_cd == 0.001_kcd);

	// Let's check the 22 derived SI Units:
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
	static_assert(3.6_km_per_h == 1_m_per_s);
	// acceleration in...
	// TODO
	// frequency in :
	static_assert(1_THz == 1000_GHz);
	static_assert(1_GHz == 1000_MHz);
	static_assert(1_MHz == 1000_kHz);
	static_assert(1_kHz == 1000_Hz);
	static_assert(1_Hz  == 0.001_kHz);
	static_assert(1_Hz  == 0.000001_MHz);
	static_assert(1_Hz  == 0.000000001_GHz);
	// radioactivity in...
	// TODO
	// mass per area in...
	// TODO
	// mass per volume in...
	// TODO
	// electric potential in...
	// TODO
	// electric resistance in...
	// TODO
	// electric conductance in...
	// TODO
	// electric conductivity in...
	// TODO
	// electric charge in...
	// TODO
	// electric capacitance in...
	// TODO
	// electric inductance in...
	// TODO
	// magnetic flux in...
	// TODO
	// magnetic field in...
	// TODO
	// energy in...
	// TODO
	// active power in...
	// TODO
	// active power per mass in...
	// TODO
	// equivalent dose in...
	// TODO
	// absorbed dose in...
	// TODO
	// pressure in...
	// TODO
	// force in...
	// TODO
	// luminous flux in...
	// TODO
	// surface flow in...
	// TODO
	// volumetric flow in...
	// TODO
	// Imperial units in...
	static_assert(1_NM == 1852_m);
	static_assert(1_ft == 0.3048_m);
	// various units in...
	//static_assert(0_deg == 273.15_K);
	// digital units in...
	static_assert(1_ZB == 1000_EB);
	static_assert(1_EB == 1000_PB);
	static_assert(1_PB == 1000_TB);
	static_assert(1_TB == 1000_GB);
	static_assert(1_GB == 1000_MB);
	static_assert(1_MB == 1000_kB);
	static_assert(1_kB == 1000_byte);
}
