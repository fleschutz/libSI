/// @file   examples/speeds.cpp
/// @brief  Contains 5 speed examples using libSI.

#include <iostream>
#include <SI/core.h> 
using namespace std;
using namespace SI;

void speed_examples() {

    cout << "    === SPEED EXAMPLES ===" << endl;
    to_string_formatting     = "%.1Lf%s"; // (one decimal place, no space between quantity and unit)
    to_equivalent_formatting = "%.1Lf%s"; // (one decimal place, no space between quantity and unit)


    cout << " 1. The average speed of Kelvin Kiptum's Marathon world record was... ";
    auto Marathon_distance = 42.195_km;
    auto Kelvins_duration  = 2_h + 35_s;
    auto Kelvins_average   = Marathon_distance / Kelvins_duration;
    cout << Kelvins_average << " or " << to_equivalent(Kelvins_average) << endl;


    cout << " 2. The average speed to travel around the Earth in 80 days has to be... ";
    auto equatorial_circumference = 40'075.017_km;
    auto travel_time              = 80_days;
    auto avg_travel_speed         = equatorial_circumference / travel_time;
    cout << avg_travel_speed << " or " << to_equivalent(avg_travel_speed) << endl;


    cout << " 3. A flight non-stop around the Earth at Mach 1 would take... ";
    auto flight_time     = equatorial_circumference / 1_Mach;
    cout << flight_time << endl;


    cout << " 4. The sum of 7 different speeds is... ";
    velocity sum = 1_m_per_s + 1_km_per_s + 1_km_per_h + 1_Mach + 1_kn + 1_mph + 1_ft_per_min;
    cout << sum << endl;


    cout << " 5. The min/max/average/sum of an array of speeds is...";
    velocity speeds[] = { 1_m_per_s, 1_km_per_s, 1_km_per_h, 1_Mach, 1_kn, 1_mph, 1_ft_per_min };
    int n = sizeof(speeds) / sizeof(speeds[0]);
    cout << " min=" << formula::min_of_array(speeds, n) << " max=" << formula::max_of_array(speeds, n)
         << " avg=" << formula::avg_of_array(speeds, n) << " sum=" << formula::sum_of_array(speeds, n)
         << endl << endl;
}
