/// @file   examples/speeds.cpp
/// @brief  Contains 9 speed examples using libSI

#include <iostream>
#include <SI/core> 

void speed_examples() {

    using namespace std;
    using namespace SI;
    cout << "    === SPEED EXAMPLES ===" << endl;
    to_string_format = to_equivalent_format = "%.1Lf%s"; // one decimal place, no space between quantity and unit


    cout << " 1. The average speed of Kelvin Kiptum's Marathon world record was... ";
    auto Marathon_distance  = 42.195_km;
    auto Kelvins_duration   = 2_h + 35_s;
    auto Kelvins_average    = Marathon_distance / Kelvins_duration;
    cout << Kelvins_average << " or " << to_equivalent(Kelvins_average) << endl;


    cout << " 2. The average speed to travel around the Earth in 80 days has to be... ";
    auto equatorial_circumference = 40'075.017_km;
    auto travel_time              = 80_days;
    auto avg_travel_speed         = equatorial_circumference / travel_time;
    cout << avg_travel_speed << " or " << to_equivalent(avg_travel_speed) << endl;


    cout << " 3. The free fall time from Burj Khalifa tower (828m) is... ";
    auto tower_height    = 828_m;
    auto free_fall_time  = formula::time_of_free_fall(tower_height, constant::Earth_gravity);
    cout << free_fall_time << endl;


    cout << " 4. A flight non-stop around the Earth at Mach 1 would take... ";
    auto flight_time     = equatorial_circumference / 1_Mach;
    cout << flight_time << endl;


    cout << " 5. A car's braking distance from 100km/h on dry asphalt is... ";
    auto braking_on_dry_asphalt = 8_m_per_s²;
    auto dry_distance           = formula::braking_distance(100_km_per_h, 0_km_per_h, braking_on_dry_asphalt);
    cout << dry_distance << " or " << to_equivalent(dry_distance) << endl;


    cout << " 6. A car's braking distance from 100km/h on wet asphalt is... ";
    auto braking_on_wet_asphalt = 6_m_per_s²;
    auto wet_distance           = formula::braking_distance(100_km_per_h, 0_km_per_h, braking_on_wet_asphalt);
    cout << wet_distance << " or " << to_equivalent(wet_distance) << endl;


    cout << " 7. The download of 10TB at 1000MBit/s takes... ";
    auto file_size      = 10_TB;
    auto download_speed = 1000_Mbps;
    cout << file_size / download_speed << endl;


    cout << " 8. The sum of 1m/s + 1km/s + 1km/h + 1Mach + 1kn + 1mph + 1ft/min is... ";
    velocity sum = 1_m_per_s + 1_km_per_s + 1_km_per_h + 1_Mach + 1_kn + 1_mph + 1_ft_per_min;
    cout << sum << " or " << to_equivalent(sum) << endl;


    cout << " 9. The min/max/average/sum of an array of speeds is...";
    velocity speeds[] = { 1_m_per_s, 1_km_per_s, 1_km_per_h, 1_Mach, 1_kn, 1_mph, 1_ft_per_min };
    int n = sizeof(speeds) / sizeof(speeds[0]);
    cout << " min=" << formula::min_of_array(speeds, n) << " max=" << formula::max_of_array(speeds, n)
         << " avg=" << formula::avg_of_array(speeds, n) << " sum=" << formula::sum_of_array(speeds, n)
         << endl << endl;
}
