// <SI/all.h> - includes all other header files (for convenience)
#pragma once

#include "datatypes.h" // <-- type-safe SI datatypes such as SI::length or SI::time
#include "units.h"     // <-- type-safe units such as SI::meters or SI::seconds
#include "constants.h" // <-- type-safe constants such as SI::constant::speed_of_light
#include "literals.h"  // <-- convenient literals such as 100_m or 60_sec
#include "formulas.h"  // <-- common formulas such as SI::formula::wavelength()
#include "IO.h"        // <-- input/output functions such as SI::print()
#include "tests.h"     // <-- unit tests at compile-time to verify everything
