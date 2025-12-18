// SI/tests.hpp - Unit tests of SI literals
#include <cassert>
#include "literals.hpp"
#include "prefixes.hpp"
#include "Earth.hpp"
using namespace si;

namespace si
{
	void unit_tests()
	{
		// SI length checks:
		static_assert(1_km == 1000_m);
		static_assert(1_m == 10_dm);
		static_assert(1_m == 100_cm);
		static_assert(1_m == 1000_mm);
		static_assert(1_m == 0.001_km);
		static_assert(1_dm == 0.1_m);
		static_assert(1_cm == 0.01_m);
		static_assert(1_mm == 0.001_m);
		static_assert(1_NM == 1852_m);
		// static_assert(1_m == 3.28084_ft);

		// SI time checks:
		static_assert(1_week == 7_day);
		static_assert(1_day == 24_h);
		static_assert(1_h == 60_min);
		static_assert(1_min == 60_s);
		static_assert(1_s == 1000_ms);
		static_assert(1_ms == 0.001_s);

		// SI area checks:
		static_assert(Earth::land_area + Earth::water_area == Earth::surface_area);

		// Speed checks:
		//static_assert(1_kmh == 3.6_mps);
		static_assert(1_Mach == 330_mps);

		// Temperature checks:
		// assert(0_K == -273.15_degC);

		// SI frequency checks:
		static_assert(1_GHz == 1000000000_Hz);
		static_assert(1_GHz == 1000_MHz);
		static_assert(1_GHz == 1000000_kHz);
		static_assert(1_MHz == 1000000_Hz);
		static_assert(1_MHz == 1000_kHz);
		static_assert(1_kHz == 1000_Hz);
		static_assert(1_Hz  == 0.001_kHz);
		static_assert(1_Hz  == 0.000001_MHz);
		static_assert(1_Hz  == 0.000000001_GHz);

		// Digital units checks:
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

		// SI Prefix checks:
		static_assert(prefix::quetta > prefix::yotta); // (too big yet)
		static_assert(prefix::ronna > prefix::yotta); // (too big yet)
		static_assert(prefix::yotta > prefix::zetta); // (too big yet)
		static_assert(prefix::zetta == 1000 * prefix::exa);
		static_assert(prefix::exa == 1000 * prefix::peta);
		static_assert(prefix::peta == 1000 * prefix::tera);
		static_assert(prefix::tera == 1000 * prefix::giga);
		static_assert(prefix::giga == 1000 * prefix::mega);
		static_assert(prefix::mega == 1000 * prefix::kilo);
		static_assert(prefix::kilo == 10 * prefix::hecto);
		static_assert(prefix::hecto == 10 * prefix::deca);
		static_assert(prefix::deca > prefix::deci);
		static_assert(prefix::deci > prefix::centi);
		static_assert(prefix::centi > prefix::milli);
		static_assert(prefix::milli > prefix::micro);
		static_assert(prefix::micro > prefix::nano);
		static_assert(prefix::nano > prefix::pico);
		static_assert(prefix::pico > prefix::femto);
		static_assert(prefix::femto > prefix::atto);
		static_assert(prefix::atto > prefix::zepto);
		static_assert(prefix::zepto > prefix::yocto);
		static_assert(prefix::yocto > prefix::ronto);
		static_assert(prefix::ronto > prefix::quecto);
	}
}
