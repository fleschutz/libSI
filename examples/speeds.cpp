/// @file     examples/speeds.cpp
/// @brief    Contains 3 speed examples using libSI.

#include <SI/all.h> 
#include "datasets/Earth.h"
using namespace SI;

void speed_examples() {

    println("");
    println("    === SPEED EXAMPLES ===");
    to_string_formatting     = "%.1Lf%s"; // one decimal place, no space between quantity and unit
    to_equivalent_formatting = "%.1Lf%s"; // one decimal place, no space between quantity and unit

    print(" 1. The average speed of Kelvin Kiptum's Marathon world record was... ");
    auto Marathon_distance = 42.195_km;
    auto Kelvins_duration  = 2_h + 35_s;
    auto avg_speed         = Marathon_distance / Kelvins_duration;
    println(avg_speed, " or ", to_equivalent(avg_speed));


    print(" 2. The average speed to travel around the Earth in 80 days must be... ");
    auto travel_distance  = dataset::Earth.equatorial_circumference;
    auto travel_time      = 80_days;
    auto avg_travel_speed = travel_distance / travel_time;
    println(avg_travel_speed, " or ", to_equivalent(avg_travel_speed));


    print(" 3. What's the speed sum here? ");
    auto speed_sum = 278_m_per_s + 1000_km_per_h + 540_kn + 621_mph + 0.85_Mach;
    println(speed_sum);
}
