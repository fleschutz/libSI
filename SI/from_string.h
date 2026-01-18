// <SI/from_string.h> - convert a string into a SI datatype, e.g. from_string("12m", my_length); 
#pragma once

#include <string>
#include "literals.h"

namespace SI
{
	bool from_string(const std::string& str, length& result)
	{
		double value;
		char unit[1024];
		if (std::sscanf(str.c_str(), "%lf%s", &value, unit) != 2)
			return false; // not recognized

		if (unit == "Gm")
			result = 1_Gm * value;
		else if (unit == "Mm")
			result = 1_Mm * value;
		else if (unit == "km")
			result = 1_km * value;
		else if (unit == "m")
			result = 1_m * value;
		else if (unit == "dm")
			result = 1_dm * value;
		else if (unit == "cm")
			result = 1_cm * value;
		else if (unit == "mm")
			result = 1_mm * value;
		else if (unit == "um")
			result = 1_um * value;
		else if (unit == "nm")
			result = 1_nm * value;
		else if (unit == "pm")
			result = 1_pm * value;
		else
			return false; // unknown unit

		return true;
	}

	bool from_string(const std::string& str, time& result)
	{
		double value;
		char unit[1024];
		if (std::sscanf(str.c_str(), "%lf%s", &value, unit) != 2)
			return false; // not recognized

		if (unit == "day" || unit == "days")
			result = 1_day * value;
		else if (unit == "h" || unit == "hrs")
			result = 1_h * value;
		else if (unit == "m" || unit == "min")
			result = 1_min * value;
		else if (unit == "s" || unit == "sec" || unit == "seconds")
			result = 1_s * value;
		else if (unit == "ms")
			result = 1_ms * value;
		else if (unit == "us")
			result = 1_us * value;
		else if (unit == "ns")
			result = 1_ns * value;
		else if (unit == "ps")
			result = 1_ps * value;
		else
			return false; // unknown unit

		return true;
	}

	bool from_string(const std::string& str, mass& result)
	{
		double value;
		char unit[1024];
		if (std::sscanf(str.c_str(), "%lf%s", &value, unit) != 2)
			return false; // not recognized

		if (unit == "Gt")
			result = 1_Gt * value;
		else if (unit == "Mt")
			result = 1_Mt * value;
		else if (unit == "kt")
			result = 1_kt * value;
		else if (unit == "t")
			result = 1_t * value;
		else if (unit == "kg")
			result = 1_kg * value;
		else if (unit == "g")
			result = 1_g * value;
		else if (unit == "mg")
			result = 1_mg * value;
		else if (unit == "ug")
			result = 1_ug * value;
		else if (unit == "ng")
			result = 1_ng * value;
		else
			return false; // unknown unit
	}

	// ... (TODO)
}
