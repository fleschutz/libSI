/// @file   examples/speeds.cpp
/// @brief  Contains 10 speed examples using libSI.

#include <iostream>
#include <SI/core> 
using namespace std;
using namespace SI;

void speed_examples() {

    cout << "    === SPEED EXAMPLES ===" << endl;
    cout << " 1. What was the average speed of Kelvin Kiptum's Marathon world record? ";
    auto Marathon_distance  = 42.195_km;
    auto Kelvins_duration   = 2_h + 35_s;
    auto Kelvins_average    = Marathon_distance / Kelvins_duration;
    cout << Kelvins_average << " or " << to_equivalent(Kelvins_average) << endl;


    cout << " 2. Which average speed is needed to travel around the Earth in 80 days? ";
    auto equatorial_circumference = 40'075.017_km;
    auto travel_time              = 80_days;
    auto avg_travel_speed         = equatorial_circumference / travel_time;
    cout << avg_travel_speed << " or " << to_equivalent(avg_travel_speed) << endl;


    cout << " 3. What's the free fall time from Burj Khalifa tower (828m or 2716ft)? ";
    auto tower_height    = 828_m;
    auto free_fall_time  = free_fall_time_formula(tower_height, CODATA.g_n);
    cout << free_fall_time << endl;


    cout << " 4. A flight non-stop around the Earth at Mach 1 would take... ";
    auto flight_time     = equatorial_circumference / 1_Mach;
    cout << flight_time << endl;


    cout << " 5. A car's braking distance from 100km/h on dry asphalt is... ";
    auto braking_on_dry_asphalt = 8_m_per_s²;
    auto dry_distance           = braking_distance_formula(100_km_per_h, 0_km_per_h, braking_on_dry_asphalt);
    cout << dry_distance << " or " << to_equivalent(dry_distance) << endl;


    cout << " 6. A car's braking distance from 100km/h on wet asphalt is... ";
    auto braking_on_wet_asphalt = 6_m_per_s²;
    auto wet_distance           = braking_distance_formula(100_km_per_h, 0_km_per_h, braking_on_wet_asphalt);
    cout << wet_distance << " or " << to_equivalent(wet_distance) << endl;


    cout << " 7. The sum of 1m/s + 1km/s + 1km/h + 1Mach + 1kn + 1mph + 1ft/min is... ";
    velocity sum = 1_m_per_s + 1_km_per_s + 1_km_per_h + 1_Mach + 1_kn + 1_mph + 1_ft_per_min;
    cout << sum << " or " << to_equivalent(sum) << endl;


    cout << " 8. The min/max/average/sum of an array of speeds is...";
    velocity speeds[] = { 1_m_per_s, 1_km_per_s, 1_km_per_h, 1_Mach, 1_kn, 1_mph, 1_ft_per_min };
    int n = sizeof(speeds) / sizeof(speeds[0]);
    cout << " min=" << min_of_array(speeds, n) << " max=" << max_of_array(speeds, n)
         << " avg=" << avg_of_array(speeds, n) << " sum=" << sum_of_array(speeds, n)
         << endl;


    cout << " 9. The download of 10TB at 1GBit/s takes... ";
    auto file_size      = 10_TB;
    auto download_speed = 1_Gbps;
    auto download_time  = file_size / download_speed;
    cout << download_time << endl;


    cout << "10. Simulate a 1GB download at 100MB/s...";
    auto downloaded = 0_byte, total = 1_GB;
    auto duration   = 0_s;
    for (; downloaded < total; downloaded += 100_MB, duration += 1_s) {
	    cout << to_percentage(downloaded, total) << ", ";
    }
    cout << downloaded << " downloaded in " << duration << endl << endl;

}
