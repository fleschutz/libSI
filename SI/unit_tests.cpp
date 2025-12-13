// SI/test_literals.cpp - Unit tests of SI literals
#include <cassert>
#include "literals.hpp"
using namespace si;

namespace si
{
	void unit_tests()
	{
		// Let's check length usage:
		assert(1_km == 1000_m);
		assert(1_m == 10_dm);
		assert(1_m == 100_cm);
		assert(1_m == 1000_mm);
		assert(1_m == 0.001_km);
		// assert(1_m == 3.28084_ft);
		assert(1_dm == 0.1_m);
		assert(1_cm == 0.01_m);
		assert(1_mm == 0.001_m);
#ifdef WITH_IMPERIAL_UNITS
		assert(1_NM == 1852_m);
#endif

		// Let's check time usage:
		assert(1_min == 60_s);
		assert(1_h == 3600_s);
		assert(1_s == 1000_ms);
		assert(1_ms == 0.001_s);

		// Let's check the speed:
		assert(1_kmh == 3.6_mps);
		assert(1_Mach == 330_mps);

		// Let's check the temperature:
		// assert(0_K == -273.15_degC);

		// Let's check the frequency:
		assert(1_GHz == 1000000000_Hz);
		assert(1_GHz == 1000_MHz);
		assert(1_GHz == 1000000_kHz);
		assert(1_MHz == 1000000_Hz);
		assert(1_MHz == 1000_kHz);
		assert(1_kHz == 1000_Hz);
		assert(1_Hz  == 0.001_kHz);
		assert(1_Hz  == 0.000001_MHz);
		assert(1_Hz  == 0.000000001_GHz);

		// Let's check the digital units:
		assert(1_kB == 1000_byte);
		assert(1_MB == 1000_kB);
		assert(1_GB == 1000_MB);
		assert(1_TB == 1000_GB);
		assert(1_PB == 1000_TB);
		assert(1_EB == 1000_PB);
		//assert(1_ZB == 1000_EB);
		//assert(1_YB == 1000_ZB);
		//assert(1_RB == 1000_YB);
		//assert(1_QB == 1000_RB);
	}
}
