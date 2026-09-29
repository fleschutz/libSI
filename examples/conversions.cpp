/// @file     examples/conversions.cpp
/// @brief    Contains 4 examples for import and 3 examples for export.

#include <SI/core.h> 
using namespace SI;

void conversion_examples() {

    // Import by using a Literal
    // -------------------------
    length distance = 42_m;

    // Import by Casting a Dimensionless Number
    // ----------------------------------------
    distance = meters(42);
    
    // Import by Multiplying a Dimensionless Number
    // --------------------------------------------
    double x = 42;
    distance = x * 1_m; 
    // IMPORTANT NOTE: This doesn't work for celsius and fahrenheit due to the offset!

    // Import from a String
    // ---------------------
    bool is_valid = from_string("42m", distance);


    // Export to a Number
    // ------------------
    double y = distance / 1_m;

    // Export to a String
    // ------------------
    std::string result = to_string(distance);

    // Export to an Equivalent String
    // ------------------------------
    std::string equiv = to_equivalent(distance); // <- equiv gets "45.93yd" assigned    
}
