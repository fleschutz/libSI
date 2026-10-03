/// @file   examples/main.cpp
/// @brief  The main() function calling all other example functions

#include <SI/tests.h>  // perform unit tests at compile-time to verify everything

extern void astronomy_examples(), speed_examples(), conversion_examples(), various_examples();

int main() {

    astronomy_examples();    // in astronomy.cpp

    speed_examples();        // in speeds.cpp

    conversion_examples();   // in conversions.cpp

    various_examples();      // in various.cpp

    return 0;
}
