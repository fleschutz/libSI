// SI/all.h - includes all header files (for convenience)
#pragma once

#include "units.h"      // <-- defines type-safe SI units, e.g. SI::time
#include "constants.h"  // <-- constants based on SI units, e.g. SI::constant::light_speed
#include "literals.h"   // <-- literals based on SI units, e.g. 3_km
#include "formulas.h"   // <-- formulas based on SI units, e.g. SI::formula::wavelength()
#include "print.h"      // <-- simple output interface
#include "tests.h"      // <-- units tests
#include "values/all.h" // <-- real-world values in SI units
