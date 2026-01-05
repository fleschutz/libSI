// SI/from_string.h - converts a string into a SI unit, e.g. from_string("12m", my_length); 
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

		if (unit == "m")
			result = 1_m * value;
		else if (unit == "km")
			result = 1_km * value;
		else if (unit == "cm")
			result = 1_cm * value;
		else if (unit == "mm")
			result = 1_mm * value;
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

		if (unit == "s")
			result = 1_sec * value;
		else if (unit == "sec")
			result = 1_sec * value;
		else if (unit == "m")
			result = 1_min * value;
		else if (unit == "min")
			result = 1_min * value;
		else if (unit == "h")
			result = 1_h * value;
		else if (unit == "hrs")
			result = 1_h * value;
		else
			return false; // unknown unit

		return true;
	}

	// ... (TODO)
}
