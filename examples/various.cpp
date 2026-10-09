/// @file   examples/various.cpp
/// @brief  Provides 34 various examples using libSI

#include <iostream>
using namespace std;

#include <SI/core.h> 
#include <datasets/all.h>
using namespace SI;

void various_examples() {

    cout << "    === VARIOUS EXAMPLES ===" << endl;
    to_string_format = to_equivalent_format = "%.1Lf%s"; // one decimal place, no space between quantity and unit


    mass m   = 1_oz;
    energy E = m * square(constant::speed_of_light_in_vacuum);
    cout << " 1. The potential energy of a single ounce is: " << E << endl;


    cout << " 2. The download of 1TB at 100MBit/s takes... ";
    auto file_size      = 1_TB;
    auto download_speed = 100_Mbps;
    cout << file_size / download_speed << endl;


    cout << " 3. The free fall time from Burj Khalifa tower (828m) is... ";
    auto tower_height   = 828_m;
    auto free_fall_time = formula::time_of_free_fall(tower_height, constant::Earth_gravity);
    cout << free_fall_time << endl;


    cout << " 4. The kinetic energy of a mid-size SUV at 30mph is... ";
    auto SUV_mass   = 5000_lb; 
    auto SUV_speed  = 30_mph;
    auto SUV_energy = formula::kinetic_energy(SUV_mass, SUV_speed);
    cout << SUV_energy << " or " << to_equivalent(SUV_energy) << endl;


    cout << " 5. The local gravity at Mount Everest's peak is... ";
    auto Everest_latitude = 27.986065_deg;
    auto Everest_height   = 8848_m;
    auto local_gravity    = formula::local_gravity(Everest_latitude, Everest_height);
    cout << local_gravity << endl;


    cout << " 6. Donald Trump's body-mass index (BMI) is... ";
    auto Donalds_weight = 102_kg;
    auto Donalds_height = 190_cm;
    cout << formula::BMI(Donalds_weight, Donalds_height) << endl;


    cout << " 7. The fuel efficiency of a car driving 400 miles and consuming 15 US gallons is... ";
    auto distance_driven = 400_mi;
    auto fuel_consumed   = 15_gal;
    auto fuel_efficiency = (fuel_consumed * 100_km) / distance_driven;
    cout << fuel_efficiency << " (per 100km)" << endl;


    cout << " 8. A car's braking distance from 100km/h on dry asphalt is... ";
    auto braking_on_dry_asphalt = 8_m_per_s²;
    auto dry_distance           = formula::braking_distance(100_km_per_h, 0_km_per_h, braking_on_dry_asphalt);
    cout << dry_distance << " or " << to_equivalent(dry_distance) << endl;


    cout << " 9. A car's braking distance from 100km/h on wet asphalt is... ";
    auto braking_on_wet_asphalt = 6_m_per_s²;
    auto wet_distance           = formula::braking_distance(100_km_per_h, 0_km_per_h, braking_on_wet_asphalt);
    cout << wet_distance << " or " << to_equivalent(wet_distance) << endl;


    cout << "10. The frequency and wavelength of the high 'c' music note is...";
    auto high_c_frequency = 1046.5_Hz;
    auto wavelength = formula::wavelength(constant::speed_of_sound, high_c_frequency);
    cout << high_c_frequency << " and " << wavelength << " (" << to_equivalent(wavelength) << ")" << endl;


    cout << "11. The population density on Earth (people per km² of land area) is... ";
    dimensionless Earth_population = 8.2e9;
    auto Earth_land_area           = 148'940'000_km²;
    auto population_density        = Earth_population / Earth_land_area;
    cout << population_density << endl;


    cout << "12. How much land area would be available for each person on Earth? ";
    auto per_person = Earth_land_area / Earth_population;
    cout << per_person << endl;


    cout << "13. Radioactive chemical elements that melt above 2500K are... ";
    for (auto& element : dataset::chemical_elements) {
        if (element.melting_point > 2500_K && element.radioactive)
            cout << element.name << " at " << element.melting_point << ", ";
    }
    cout << endl;


    cout << "14. An aircraft glide path on final at 10NM distance in 3000ft height is... ";
    auto distance_on_final = 10_nmi;
    auto height_on_final   = 3000_ft;
    auto glide_path        = formula::glide_path(distance_on_final, height_on_final);
    cout << glide_path << endl;


    cout << "15. The windchill temperature of 5°C air temperature at 55km/h wind is... ";
    auto air_temperature  = 5_degC;
    auto wind_speed       = 55_km_per_h;
    auto windchill_temp   = formula::windchill_temperature(air_temperature, wind_speed);
    cout << windchill_temp << " or " << to_equivalent(windchill_temp) << endl;


    cout << "16. The surface area and volume of a 30cm x 1cm pizza is... ";
    auto pizza_radius  = 30_cm / 2;
    auto pizza_height  = 1_cm;
    auto pizza_area    = formula::area_of_circle(pizza_radius);
    auto pizza_volume  = formula::volume_of_cylinder(pizza_radius, pizza_height);
    cout << pizza_area << " and " << pizza_volume << endl;


    cout << "17. The filament length of a 750g PLA roll with 2.85mm diameter is... ";
    auto filament_weight    = 750_g;
    auto filament_diameter  = 2.85_mm;
    auto density_of_PLA     = 1.24_g_per_cm³;
    auto filament_volume    = filament_weight / density_of_PLA;
    auto filament_length    = filament_volume / (constant::pi * square(filament_diameter / 2.0));
    cout << filament_length << " or " << to_equivalent(filament_length) << endl;


    cout << "18. The surface area and volume of a soccer ball is... ";
    auto ball_circumference  = 70_cm; // (69-71cm for FIFA ball size 5)
    auto ball_radius         = formula::radius_of_circumference(ball_circumference);
    auto ball_area           = formula::area_of_sphere(ball_radius);
    auto ball_volume         = formula::volume_of_sphere(ball_radius);
    cout << ball_area << " and " << ball_volume << endl;


    cout << "19. The lift force of an A380 wing at sea level with 284km/h rotation speed is... ";
    auto wing_surface              = 845_m²;
    dimensionless lift_coefficient = 1.3939;
    auto air_density               = 1.2250_kg_per_m³; // at sea level at 15°C (59°F)
    auto air_speed                 = 284_km_per_h;
    auto lift_force                = formula::lift_force_of_wing(lift_coefficient, wing_surface, air_density, air_speed);
    cout << lift_force << endl;


    cout << "20. The sound intensity of a 1W loudspeaker in 1m distance is... ";
    auto loudspeaker_power     = 1_W;
    auto loudspeaker_distance  = 1_m;
    auto sound_intensity       = formula::sound_intensity(loudspeaker_power, loudspeaker_distance);
    cout << sound_intensity << " or " << to_equivalent(sound_intensity) << endl;


    cout << "21. The max diving time in salt water in 10m depth using a 10l bottle is... ";
    auto average_breathing  = 20_l_per_min;
    auto bottle_volume      = 10_l;
    auto bottle_pressure    = 150_bar;
    auto dive_depth         = 10_m;
    auto salt_water_density = 1033.23_kg_per_m³;
    auto air_pressure       = 1013.25_hPa;
    auto water_pressure     = salt_water_density * constant::g_n * dive_depth + air_pressure;
    auto max_time           = (bottle_volume * bottle_pressure) / (average_breathing * water_pressure);
    cout << max_time << endl;


    cout << "22. The sum of 1m + 1km + 1nmi + 1ft + 1in is... ";
    auto length_sum = 1_m + 1_km + 1_nmi + 1_ft + 1_in;
    cout << length_sum << endl;


    cout << "23. The sum of 1 byte + 1kB + 1MB + ... + 1QB is... ";
    auto byte_sum = 1_byte + 1_kB + 1_MB + 1_GB + 1_TB + 1_PB + 1_EB + 1_ZB + 1_YB + 1_RB + 1_QB;
    cout << byte_sum << endl;


    cout << "24. The radar's geometrical horizon from 30ft height is... ";
    auto Earth_radius         = 6371.009_km;
    auto Radar_station_height = 30_ft;
    auto distance             = sqrt((Earth_radius + Radar_station_height) * (Earth_radius + Radar_station_height) - Earth_radius * Earth_radius);
    cout << distance << " or " << to_equivalent(distance) << endl;


    cout << "25. The details of a 10m x 1m oak timber log are... ";
    auto log_length     = 10_m;
    auto log_diameter   = 1_m;
    auto dry_oak_weight = 710_kg_per_m³; 
    auto dry_oak_power  = 4.2_kWh_per_kg;
    auto area           = formula::area_of_cylinder(log_diameter / 2, log_length);
    auto volume         = formula::volume_of_cylinder(log_diameter / 2, log_length);
    auto weight         = volume * dry_oak_weight;
    auto power          = weight * dry_oak_power;
    cout << area << " area, " << volume << " volume, " << weight << " weight, " << power << endl;


    cout << "26. The min cable wire size for 100m copper, 230V, 30A max are... ";
    auto conductor_resistivity  = 1.7241e-8_Ohm_m; // for copper
    auto cable_length           = 100_m;
    auto max_current            = 30_A;
    auto allowable_voltage_drop = 10_V; 
    auto A = (2.0 * conductor_resistivity * cable_length * max_current) / allowable_voltage_drop;
    cout << A << endl;


    cout << "27. The voltage of a capacitor (5V, 0.47µF, 4.7KOhm) after 10ms is... ";
    auto CC   = 0.47_uF;
    auto V0   = 5_V;
    auto RR   = 4.7_kOhm;
    auto time = 10_ms;
    auto V1   = V0 * exp(-time / (RR * CC));
    cout << V1 << endl;


    cout << "28. The frequencies and wavelengths of all musical notes are... ";
    for (auto& note : dataset::musical_notes) {
        auto wavelength = formula::wavelength(constant::speed_of_sound, note.frequency);
        cout << note.name << note.octave << "=" << note.frequency << "," << wavelength << " ";
    }
    cout << endl;


    cout << "29. The power of a 15PS motorcycle with 200kg weight is... ";
    auto engine_power           = 15_PS;
    auto motorcycle_mass        = 200_kg;
    auto power_to_weight_ratio  = motorcycle_mass / engine_power;
    cout << engine_power << " and " << power_to_weight_ratio << endl;


    cout << "30. How many wine bottles are needed for 1 hectoliter? ";
    auto total_volume       = 1_hl;
    auto volume_per_bottle  = 750_ml;
    auto number_of_bottles  = total_volume / volume_per_bottle;
    cout << number_of_bottles << endl;


    cout << "31. The AC voltages within a tenth second are... ";
    for (auto time = 0.0_s; time < 0.1_s; time += 0.005_s) {
        auto peak_voltage = 220_V;
        auto sample_rate  = 50_Hz;
        cout << formula::sine_wave(peak_voltage, sample_rate, time) << ", ";
    }
    cout << endl;


    cout << "32. Applying a perpendicular force of 500N to a 20cm long lever results in... ";
    auto lever_arm     = 20_cm;
    auto force_applied = 500_N;
    auto angle         = 90_deg;
    auto torque = lever_arm * force_applied * SI::sin(angle);
    cout << torque << " of torque" << endl;


    cout << "33. The direct distance between Singapore and Tokyo is...";
    auto Singapore_lat  = 1.3521_deg;
    auto Singapore_long = 103.8198_deg;
    auto Tokyo_lat  = 35.6762_deg;
    auto Tokyo_long = 139.6503_deg;
    cout << formula::distance_on_Earth(Singapore_lat, Singapore_long, Tokyo_lat, Tokyo_long) << endl;


    cout << "34. The nearest airport neighbours are...";
    length nearestDistance = 999999_km;
    std::string nearest1 = "";
    std::string nearest2 = "";
    for (auto& airport1 : dataset::airports) { 
        for (auto& airport2 : dataset::airports) { 
            if (&airport1 == &airport2)
                continue;
            auto distance = formula::distance_on_Earth(airport1.latitude, airport1.longitude, airport2.latitude, airport2.longitude);
	    if (distance < nearestDistance) {
		    nearestDistance = distance;
		    nearest1 = airport1.name;
		    nearest2 = airport2.name;
            }
        }
    }
    cout << nearest1 << " and " << nearest2 << " with only " << nearestDistance << " in between" << endl << endl;
}
