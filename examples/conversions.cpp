/// @file   examples/conversions.cpp
/// @brief  Contains 4 import and 5 export examples.

#include <iostream>
#include <SI/core> 
using namespace SI;

void conversion_examples() {

    // Import Options
    // --------------
    length distance = 42_m;   // <- use a user-defined literal

    distance = meters(42.0);  // <- cast a dimensionless number
    
    double x = 42;
    distance = x * 1_m;       // <- multiply a dimensionless number - doesn't work for celsius/fahrenheit due to the offset!

    bool is_valid = from_string("42m", distance); // <- string to length conversion


    // Export Options
    // --------------
    double y = meters(distance); // <- cast to a unit (=42)

    double z = distance / 1_m;   // <- divide to a dimensionless number (=42) - doesn't work for celsius/fahrenheit due to the offset!

    std::string str = to_string(distance); // <- length to string conversion (="42.0m")

    std::string equiv = to_equivalent(distance); // <- length to an equivalent string conversion (="45.93yd")

    std::string progress = to_percentage(distance, 420_m); // <- length to percentage string conversion (="10%")
}
