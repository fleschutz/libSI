// SI/all.h - includes all header files (for convenience)
#pragma once

#include "units.h"      // <-- type-safe SI datatypes & units, e.g. SI::mass
#include "constants.h"  // <-- type-safe constants, e.g. SI::constant::light_speed
#include "literals.h"   // <-- convenient literals for SI units, e.g. 3_km
#include "formulas.h"   // <-- common formulas, e.g. SI::formula::wavelength()
#include "from_string.h"// <-- convert string -> SI datatype
#include "to_string.h"  // <-- convert SI datatype -> string
#include "print.h"      // <-- simple print to the console interface
#include "tests.h"      // <-- units tests
#include "data/all.h"   // <-- real-world data 
