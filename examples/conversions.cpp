/// @file   examples/conversions.cpp
/// @brief  Contains 4 import and 5 export examples.

#include <iostream>
#include <SI/core> 
using namespace SI;

void conversion_examples() {

    // ** IMPORT **
    length distance = 42_m;  // <- use a literal

    distance = meters(42.0); // <- cast a dimensionless number
    
    double x = 42;
    distance = x * 1_m;      // <- multiply a dimensionless number - doesn't work for celsius/fahrenheit due to the offset!

    bool is_valid = from_string("42m", distance); // <- convert from a string


    // ** EXPORT **
    double y = meters(distance); // <- cast to a unit (=42)

    double z = distance / 1_m;   // <- divide to a dimensionless number (=42) - doesn't work for celsius/fahrenheit due to the offset!

    std::string str = to_string(distance); // <- convert length to a string (="42.0m")

    std::string equiv = to_equivalent(distance); // <- convert length to an equivalent string (="45.93yd")

    std::string progress = to_percentage(distance, 420_m); // <- convert length to percentage string (="10%")
}
