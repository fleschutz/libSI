#include <SI/all.h> 
using namespace SI;

void conversions() {

    // Import a number:
    double x = 42;               // <- x now contains a dimensionless number without unit
    length distance = x * 1_m;   // <- distance now contains 42m

    // Import a string:
    bool check = from_string("42m", distance);

    // Export a number:
    double y = distance / 1_m;  // <- y again contains a dimensionless number (no unit)

    // Export a string:
    std::string result = to_string(distance);


    // NOTE: The above doesn't work for celsius and fahrenheit due to the offset!
}
