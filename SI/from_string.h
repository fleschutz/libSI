// SI/from_string.h - converts a string into a SI unit, e.g. from_string("12m", my_length); 
#pragma once

#include <string>
#include "units.h"

namespace SI
{
	bool from_string(const std::string& str, length& result)
	{
		double value;
		if (std::sscanf(str.c_str(), "%lfm", &value) == 1)
			result = value * meter(1.0);
		else
			return false; // string not recognized

		return true;
	}

	bool from_string(const std::string& str, time& result)
	{
		double value;
		if (std::sscanf(str.c_str(), "%lfs", &value) == 1)
			result = value * second(1.0);
		else
			return false; // string not recognized

		return true;
	}

	// ... (TODO)
}
