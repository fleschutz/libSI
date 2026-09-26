#include <SI/all.h> 
using namespace SI;

void conversion_examples() {

    // Import a Literal
    // ----------------
    length distance = 42_m;
    SI::time day    = 24_h;
    mass weight     = 100_lb;

    // Import a Number
    // ---------------
    double x = 42;               // <- x now contains a dimensionless number without unit
    distance = x * 1_m;          // <- distance now contains 42m

    // Import a String
    // ---------------
    bool check = from_string("42m", distance);


    // Export a Number
    // ---------------
    double y = distance / 1_m;  // <- y again contains a dimensionless number (no unit)

    // Export a String
    // ---------------
    std::string result = to_string(distance); // <- result gets "42.00m" assigned

    // Export an Equivalent
    // --------------------
    std::string equiv = to_equivalent(distance); // <- equiv gets "45.93yd" assigned


    // NOTE: The above conversions don't work for celsius and fahrenheit due to the offset!
}
