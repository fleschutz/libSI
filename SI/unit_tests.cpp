// SI/test_literals.cpp - Unit tests of SI literals
#include <cassert>
#include "literals.hpp"
using namespace si;

namespace si
{
	void unit_tests()
	{
		// Let's check the SI length:
		static_assert(1_km == 1000_m);
		static_assert(1_m == 10_dm);
		static_assert(1_m == 100_cm);
		static_assert(1_m == 1000_mm);
		static_assert(1_m == 0.001_km);
		// static_assert(1_m == 3.28084_ft);
		static_assert(1_dm == 0.1_m);
		static_assert(1_cm == 0.01_m);
		static_assert(1_mm == 0.001_m);
#ifdef WITH_IMPERIAL_UNITS
		static_assert(1_NM == 1852_m);
#endif

		// Let's check the SI time:
		static_assert(1_min == 60_s);
		static_assert(1_h == 3600_s);
		static_assert(1_s == 1000_ms);
		static_assert(1_ms == 0.001_s);

		// Let's check the speed:
		static_assert(1_kmh == 3.6_mps);
		static_assert(1_Mach == 330_mps);

		// Let's check the temperature:
		// assert(0_K == -273.15_degC);

		// Let's check the SI frequency:
		static_assert(1_GHz == 1000000000_Hz);
		static_assert(1_GHz == 1000_MHz);
		static_assert(1_GHz == 1000000_kHz);
		static_assert(1_MHz == 1000000_Hz);
		static_assert(1_MHz == 1000_kHz);
		static_assert(1_kHz == 1000_Hz);
		static_assert(1_Hz  == 0.001_kHz);
		static_assert(1_Hz  == 0.000001_MHz);
		static_assert(1_Hz  == 0.000000001_GHz);

		// Let's check the digital units:
		static_assert(1_kB == 1000_byte);
		static_assert(1_MB == 1000_kB);
		static_assert(1_GB == 1000_MB);
		static_assert(1_TB == 1000_GB);
		static_assert(1_PB == 1000_TB);
		static_assert(1_EB == 1000_PB);
		static_assert(1_ZB == 1000_EB);
		// static_assert(1_YB == 1000_ZB); (too big yet)
		// static_assert(1_RB == 1000_YB); (too big yet)
		// static_assert(1_QB == 1000_RB); (too big yet)
	}
}
