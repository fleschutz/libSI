// SI/tests.h - unit tests for safety
#pragma once

#include <cassert>
#include "literals.h"
#include "values/Earth.h"

namespace SI
{
	void tests()
	{
		// THE 7 SI BASE UNITS:

		// SI meter:
		static_assert(1_km == 1000_m);
		static_assert(1_m == 10_dm);
		static_assert(1_m == 100_cm);
		static_assert(1_m == 1000_mm);
		static_assert(1_m == 0.001_km);
		static_assert(1_dm == 0.1_m);
		static_assert(1_cm == 0.01_m);
		static_assert(1_mm == 0.001_m);

		// SI second:
		static_assert(1_h == 60_min);
		static_assert(1_min == 60_s);
		static_assert(1_s == 1000_ms);
		static_assert(1_ms == 0.001_s);

		// SI kilogram:
		static_assert(1_t  == 1000_kg);
		static_assert(1_kg == 1000_g);
		static_assert(1_g  == 1000_mg);

		// SI ampere:
		static_assert(1_MA == 1000_kA);
		static_assert(1_kA == 1000_A);
		static_assert(1_A == 1000_mA);
		static_assert(1_mA == 1000_muA);

		// THE 22 SI DERIVED UNITS:

		// SI area checks:
		// static_assert(Earth::land_area + Earth::water_area == Earth::surface_area);
		// Speed checks:
		//static_assert(1_kmh == 3.6_mps);

		// SI frequency:
		static_assert(1_THz == 1000_GHz);
		static_assert(1_GHz == 1000_MHz);
		static_assert(1_MHz == 1000_kHz);
		static_assert(1_kHz == 1000_Hz);
		static_assert(1_Hz  == 0.001_kHz);
		static_assert(1_Hz  == 0.000001_MHz);
		static_assert(1_Hz  == 0.000000001_GHz);

		// IMPERIAL UNITS:
		static_assert(1_NM == 1852_m);
		static_assert(1_ft == 0.3048_m);

		// VARIOUS UNITS:
		static_assert(1_Mach == 330_mps);
		//static_assert(0_deg == 273.15_K);

		// Digital units:
		static_assert(1_ZB == 1000_EB);
		static_assert(1_EB == 1000_PB);
		static_assert(1_PB == 1000_TB);
		static_assert(1_TB == 1000_GB);
		static_assert(1_GB == 1000_MB);
		static_assert(1_MB == 1000_kB);
		static_assert(1_kB == 1000_byte);
	}
}
