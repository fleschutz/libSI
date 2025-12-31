// SI/to_string.h - converts SI units to a string 
#pragma once

#include "literals.h"
#include "values/Earth.h"

namespace SI
{
	// Internal function to join both quantity and unit.
	std::string _join(quantity value, const std::string& unit)
	{
		return std::to_string(value) + unit;
	}

	// The 7 SI Base Units
	// -------------------
	std::string to_string(length d)
	{
		if (abs(d) >= 1_Mly)
			return _join(d / 1_Mly, "Mly (megalight-years)");
		else if (abs(d) >= 1_pc)
			return _join(d / 1_pc, "pc (parsec)");
		else if (abs(d) >= 1_ly)
			return _join(d / 1_ly, "ly (light-years)");
		else if (abs(d) >= 1_au)
			return _join(d / 1_au, "au (astronomical unit)");
		else if (abs(d) >= 1_km)
			return _join(d / 1_km, "km");
		else if (abs(d) >= 1_m)
			return _join(d / 1_m, "m ");
		else if (abs(d) >= 1_cm)
			return _join(d / 1_cm, "cm");
		else if (abs(d) >= 1_mm)
			return _join(d / 1_mm, "mm");
		else
			return _join(d / 1_μm, "μm");
	}

	// The 22 Derived SI Units
	// -----------------------
	std::string to_string(velocity v)
	{
		if (abs(v) >= 1_km_per_h)
			return _join(v / 1_km_per_h, "km/h");
		else if (abs(v) >= 1_m_per_s)
			return _join(v / 1_m_per_s, "m/s");
		else
			return _join(v / 1_mm_per_h, "mm/h");
	}

}
