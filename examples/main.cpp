/// @file     examples/main.cpp
/// @brief    Contains the main function which calls all the examples

#include <SI/tests.h>  // perform unit tests at compile-time to verify everything

extern void astronomy_examples(), speed_examples(), conversion_examples(), various_examples();

int main() {

    astronomy_examples();

    speed_examples();

    conversion_examples();

    various_examples();

    return 0;
}
