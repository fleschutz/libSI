/// @file     examples/conversions.cpp
/// @brief    Contains 6 conversion examples.

#include <SI/all.h> 
using namespace SI;

void conversion_examples() {

    // Import from a Literal
    // ---------------------
    length distance = 42_m;
    SI::time day    = 24_h;
    mass weight     = 100_lb;

    // Import from a Dimensionless Number (option #1)
    // ----------------------------------------------
    distance = meters(42);
    
    // Import from a Dimensionless Number (option #2)
    // ----------------------------------------------
    double x = 42;               // <- x now contains a dimensionless number without unit
    distance = x * 1_m;          // <- distance now contains 42m

    // Import from a String
    // ---------------------
    bool check = from_string("42m", distance);


    // Export to a Number
    // ------------------
    double y = distance / 1_m;  // <- y again contains a dimensionless number (no unit)

    // Export to a String
    // ------------------
    std::string result = to_string(distance); // <- result gets "42.00m" assigned

    // Export to an Equivalent String
    // ------------------------------
    std::string equiv = to_equivalent(distance); // <- equiv gets "45.93yd" assigned


    // NOTE: The above conversions don't work for celsius and fahrenheit due to the offset!
}
