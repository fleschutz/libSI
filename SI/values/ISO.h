// SI/values/ISO.h - International ISO standards in SI units as of 2025
#pragma once

#include "../../SI/units.h"

namespace SI
{
	namespace ISO 
	{
#define SET(_name, _value, _unit) const auto _name = _unit(_value)

// ISO 216 - Paper Sizes
SET( paper_A0_with,              841, millimeter);
SET( paper_A0_height,           1189, millimeter);
SET( paper_A1_with,              594, millimeter);
SET( paper_A1_height,            841, millimeter);
SET( paper_A2_with,              420, millimeter);
SET( paper_A2_height,            594, millimeter);
SET( paper_A3_with,              297, millimeter);
SET( paper_A3_height,            420, millimeter);
SET( paper_A4_with,              210, millimeter);
SET( paper_A4_height,            297, millimeter);
SET( paper_A5_with,              148, millimeter);
SET( paper_A5_height,            210, millimeter);
SET( paper_A6_with,              105, millimeter);
SET( paper_A6_height,            148, millimeter);
SET( paper_A7_with,               74, millimeter);
SET( paper_A7_height,            105, millimeter);
SET( paper_A8_with,               52, millimeter);
SET( paper_A8_height,             74, millimeter);
SET( paper_A9_with,               37, millimeter);
SET( paper_A9_height,             52, millimeter);
SET( paper_A10_width,             26, millimeter);
SET( paper_A10_height,            37, millimeter);
//...

// ISO 668 - Series 1 freight containers
SET( container_1AA_ext_length,     12.192, meter); // (aka 40-foot standard)
SET( container_1AA_ext_height,      2.591, meter);
SET( container_1AA_ext_width,       2.438, meter);
SET( container_1AA_max_gross_mass, 36'000, kilogram);
//...

#undef SET
	}
}

