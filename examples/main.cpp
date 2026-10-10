/// @file   examples/main.cpp
/// @brief  The main() function calling all other example functions

#include <SI/tests.h>  // perform unit tests at compile-time to verify everything
#ifdef _WIN32
#include <Windows.h>
#endif

extern void speed_examples(), astronomy_examples(), conversion_examples(), various_examples();

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    speed_examples();        // in speeds.cpp

    astronomy_examples();    // in astronomy.cpp

    conversion_examples();   // in conversions.cpp

    various_examples();      // in various.cpp

    return 0;
}
