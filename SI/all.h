// SI/all.h - includes all header files (for convenience)
#pragma once

#include "datatypes.h"  // <-- type-safe SI datatypes, e.g. SI::mass
#include "units.h"      // <-- type-safe SI units, e.g. SI::kilograms
#include "constants.h"  // <-- type-safe constants, e.g. SI::constant::light_speed
#include "literals.h"   // <-- convenient literals for SI units, e.g. 3_km
#include "formulas.h"   // <-- common formulas, e.g. SI::formula::wavelength()
#include "IO.h"         // <-- input/output functions
#include "unit_tests.h" // <-- units tests
#include "data/all.h"   // <-- real-world data 
