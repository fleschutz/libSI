/// @file     SI/core.h
/// @brief    Includes all core header files of libSI.

#pragma once
#include "datatypes.h"    /// <-- datatypes like SI::length
#include "units.h"        /// <-- units such as SI::meters
#include "literals.h"     /// <-- literals like 100_m
#include "constants.h"    /// <-- constants such as SI::constant::speed_of_light_in_vacuum
#include "formulas.h"     /// <-- formulas such as SI::formula::wavelength()
#include "conversions.h"  /// <-- conversions such as SI::to_string()
#include "print.h"        /// <-- simple print to console functions 
#include "tests.h"        /// <-- unit tests at compile-time to verify everything
