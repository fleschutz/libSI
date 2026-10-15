/// @file   examples/main.cpp
/// @brief  The main() function, calling all examples

#include <SI/tests.h>  // perform unit tests at compile-time to verify everything
#ifdef _WIN32
#include <Windows.h>
#endif

extern void speed_examples(), astronomy_examples(), conversion_examples(), various_examples();

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // switch to UTF-8 console output
#endif

    speed_examples();            // see speeds.cpp

    astronomy_examples();        // see astronomy.cpp

    conversion_examples();       // see conversions.cpp

    various_examples();          // see various.cpp
}
