/// @file     examples/speeds.cpp
/// @brief    Contains 4 speed examples using libSI.

#include <SI/core.h> 
using namespace SI;

void speed_examples() {

    std::cout << "    === SPEED EXAMPLES ===" << std::endl;
    to_string_formatting     = "%.1Lf%s"; // (one decimal place, no space between quantity and unit)
    to_equivalent_formatting = "%.1Lf%s"; // (one decimal place, no space between quantity and unit)


    std::cout << " 1. The average speed of Kelvin Kiptum's Marathon world record was... ";
    auto Marathon_distance = 42.195_km;
    auto Kelvins_duration  = 2_h + 35_s;
    auto Kelvins_average   = Marathon_distance / Kelvins_duration;
    std::cout << Kelvins_average << " or " << to_equivalent(Kelvins_average) << std::endl;


    std::cout << " 2. The average speed to travel around the Earth in 80 days has to be... ";
    auto equatorial_circumference = 40'075.017_km;
    auto travel_time              = 80_days;
    auto avg_travel_speed         = equatorial_circumference / travel_time;
    std::cout << avg_travel_speed << " or " << to_equivalent(avg_travel_speed) << std::endl;


    std::cout << " 3. The sum of 7 different speeds is... ";
    velocity sum = 1_m_per_s + 1_km_per_s + 1_km_per_h + 1_Mach + 1_kn + 1_mph + 1_ft_per_min;
    std::cout << sum << std::endl;


    std::cout << " 4. The min/max/average/sum of an array of speeds is...";
    velocity speeds[] = { 1_m_per_s, 1_km_per_s, 1_km_per_h, 1_Mach, 1_kn, 1_mph, 1_ft_per_min };
    int n = sizeof(speeds) / sizeof(speeds[0]);
    std::cout << " min=" << formula::min_of_array(speeds, n) << " max=" << formula::max_of_array(speeds, n)
              << " avg=" << formula::avg_of_array(speeds, n) << " sum=" << formula::sum_of_array(speeds, n)
              << std::endl << std::endl;
}
