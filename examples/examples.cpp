#include <SI/all.h> 
#include "datasets/all.h"
using namespace SI;

int main() {

    mass m = 1_oz;
    velocity c = constant::speed_of_light;
    energy E = m * c * c;
    println(" 1. The potential energy of a single ounce is: ", E);


    auto file_size      = 1_TB;
    auto download_speed = 100_Mbps;
    auto download_time  = file_size / download_speed;
    println(" 2. The download of 1TB at 100MBit/s takes: ", download_time);


    auto Marathon_distance = 42.195_km;
    auto Kelvins_time      = 2_h + 35_s;
    auto avg_speed         = Marathon_distance / Kelvins_time;
    println(" 3. The average speed of Kelvin Kiptum's Marathon world record was: ", avg_speed, " or ", to_equivalent(avg_speed));


    auto tower_height   = 828_m;
    auto free_fall_time = formula::time_of_free_fall(tower_height, constant::Earth_gravity);
    println(" 4. The free fall time from Burj Khalifa tower (828m) is: ", free_fall_time);


    auto SUV_mass   = 5000_lb; 
    auto SUV_speed  = 30_mph;
    auto SUV_energy = formula::kinetic_energy(SUV_mass, SUV_speed);
    println(" 5. The kinetic energy of a mid-size SUV at 30MPH is: ", SUV_energy, " or ", to_equivalent(SUV_energy));


    auto Everest_latitude = 27.986065_deg;
    auto Everest_height   = 8848_m;
    auto local_gravity    = formula::local_gravity(Everest_latitude, Everest_height);
    println(" 6. The local gravity at Mount Everest's peak is: ", local_gravity);


    auto Donalds_weight = 102_kg;
    auto Donalds_height = 190_cm;
    auto Donalds_BMI    = formula::BMI(Donalds_weight, Donalds_height);
    println(" 7. The body-mass index (BMI) of Donald Trump is: ", Donalds_BMI);


    print(" 8. What's the fuel efficiency of a car driving 400 miles and consuming 15 US gallons? ");
    auto distance_driven = 400_mi;
    auto fuel_consumed   = 15_gal;
    auto fuel_efficiency = (fuel_consumed * 100_km) / distance_driven;
    println(fuel_efficiency, " (per 100km)");


    print(" 9. What's a car's braking distance from 100km/h on dry asphalt? ");
    auto braking_on_dry_asphalt = 8_m_per_s²;
    auto dry_distance           = formula::braking_distance(100_km_per_h, 0_km_per_h, braking_on_dry_asphalt);
    println(dry_distance, " or ", to_equivalent(dry_distance));


    print("10. What's a car's braking distance from 100km/h on wet asphalt? ");
    auto braking_on_wet_asphalt = 6_m_per_s²;
    auto wet_distance           = formula::braking_distance(100_km_per_h, 0_km_per_h, braking_on_wet_asphalt);
    println(wet_distance, " or ", to_equivalent(wet_distance));


    auto H2_frequency  = 1420.4057517682_MHz;
    auto H2_wavelength = formula::wavelength(constant::speed_of_light, H2_frequency);
    println("11. The wavelength of hydrogen (H2) in vacuum is: ", H2_wavelength, " or ", to_equivalent(H2_wavelength));


    print("12. What's the frequency and wavelength of the high 'c' music note? ");
    auto high_c_frequency = 1046.5_Hz;
    auto wavelength = formula::wavelength(constant::speed_of_sound, high_c_frequency);
    println(high_c_frequency, " and ", wavelength, " (", to_equivalent(wavelength), ")");


    print("13. What's the population density on Earth (people per km² of land area)? ");
    dimensionless Earth_population = 8.2e9;
    auto Earth_land_area           = 148'940'000_km²;
    auto population_density        = Earth_population / Earth_land_area;
    println(population_density);


    print("14. How much land area would be available for each person on Earth? ");
    auto per_person = Earth_land_area / Earth_population;
    println(per_person);


    print("15. Which chemical elements melt above 2500K and are radioactive? ");
    for (auto& element : dataset::chemical_elements) {
        if (element.melting_point > 2500_K && element.radioactive)
            printf("%s at %s, ", element.name, to_string(element.melting_point).c_str());
    }
    println("");


    print("16. Which moons are greater than Earth's moon? ");
    for (auto& moon : dataset::moons) {
        if (moon.mean_radius > 1737.5_km)
            printf("%s's %s (ø=%s), ", moon.planet, moon.name, to_string(2. * moon.mean_radius).c_str());
    }
    println("");


    print("17. What's an aircraft's glide path on final at 10NM distance in 3000ft height? ");
    auto distance_on_final = 10_nmi;
    auto height_on_final   = 3000_ft;
    auto glide_path        = formula::glide_path(distance_on_final, height_on_final);
    println(glide_path);


    print("18. What's the min speed required to escape from the planets? ");
    for (auto& planet : dataset::planets) {
        auto min_speed = formula::gravitational_escape_velocity(planet.mass, planet.diameter / 2.0);
        print(planet.name, "=", min_speed, " or ", to_equivalent(min_speed), ", ");
    }
    println("");


    print("19. What's the windchill temperature of 5°C air temperature at 55km/h wind? ");
    auto air_temperature = 5_degC;
    auto wind_speed      = 55_km_per_h;
    auto windchill_temp  = formula::windchill_temperature(air_temperature, wind_speed);
    println(windchill_temp, " or ", to_equivalent(windchill_temp));


    print("20. What's the average speed to travel around the Earth in 80 days? ");
    auto travel_distance  = dataset::Earth.equatorial_circumference;
    auto travel_time      = 80_days;
    auto avg_travel_speed = travel_distance / travel_time;
    println(avg_travel_speed, " or ", to_equivalent(avg_travel_speed));


    print("21. What's the surface area and volume of a 30cm x 1cm pizza? ");
    auto pizza_radius = 30_cm / 2;
    auto pizza_height = 1_cm;
    auto pizza_area   = formula::area_of_circle(pizza_radius);
    auto pizza_volume = formula::volume_of_cylinder(pizza_radius, pizza_height);
    println(pizza_area, " and ", pizza_volume);


    print("22. Which exoplanets are life-friendly and quite near? ");
    for (auto& exoplanet : dataset::exoplanets) {
        if (exoplanet.number_of_stars == 0)
            continue; // too cold without a star
        if (exoplanet.equilibrium_temperature < -40_degC || exoplanet.equilibrium_temperature > 40_degC)
            continue; // too cold or too hot
        if (exoplanet.eccentricity >= 0.02)
            continue; // orbit too elliptic or even parabolic 
        if (exoplanet.distance > 3_pc || exoplanet.distance == 0_m)
            continue; // too far away or distance unknown yet
        print("'", exoplanet.name, "' @ ", exoplanet.hostname, " in ", exoplanet.distance, ", ");
    }
    println("");


    print("23. What's the attractive force between Sun and Earth? ");
    auto Sun_mass              = 1.988416E30_kg;
    auto Earth_mass            = 5.9722E24_kg;
    auto Earth_to_Sun_distance = 149'597'870'691_m;
    println(formula::gravitational_attractive_force(Sun_mass, Earth_mass, Earth_to_Sun_distance));


    print("24. What's the attractive force between Earth and Moon? ");
    auto Moon_mass              = 7.346E22_kg;
    auto Earth_to_Moon_distance = 384'399_km;
    println(formula::gravitational_attractive_force(Earth_mass, Moon_mass, Earth_to_Moon_distance));


    print("25. What's the filament length of a 750g PLA roll with 2.85mm diameter? ");
    auto filament_weight   = 750_g;
    auto filament_diameter = 2.85_mm;
    auto density_of_PLA    = 1.24_g_per_cm³;
    auto filament_volume   = filament_weight / density_of_PLA;
    auto filament_length   = filament_volume / (constant::pi * square(filament_diameter / 2.0));
    println(filament_length, " or ", to_equivalent(filament_length));


    print("26. How long takes a flight non-stop around the Earth at Mach 1? ");
    auto flight_distance = dataset::Earth.equatorial_circumference;
    auto flight_time     = flight_distance / 1_Mach;
    println(flight_time);


    print("27. What's the surface area and volume of a soccer ball? ");
    auto ball_circumference = 70_cm; // (69-71cm for FIFA ball size 5)
    auto ball_radius        = formula::radius_of_circumference(ball_circumference);
    auto ball_area          = formula::area_of_sphere(ball_radius);
    auto ball_volume        = formula::volume_of_sphere(ball_radius);
    println(ball_area, " and ", ball_volume);


    print("28. What's the travel time of sun light to Earth? ");
    println(Earth_to_Sun_distance / constant::speed_of_light);


    print("29. What's the lift force of an A380 wing at sea level with 284km/h rotation speed? ");
    auto wing_surface              = 845_m²;
    dimensionless lift_coefficient = 1.3939;
    auto air_density               = 1.2250_kg_per_m³; // at sea level at 15°C (59°F)
    auto air_speed                 = 284_km_per_h;
    auto lift_force                = formula::lift_force_of_wing(lift_coefficient, wing_surface, air_density, air_speed);
    println(lift_force);


    print("30. What's the impact energy of a 50m asteroid at 50,000km/h? ");
    auto asteroid_diameter = 50_m;
    auto asteroid_density  = 2500_kg_per_m³; // mostly estimated only 
    auto asteroid_velocity = 50'000_km_per_h; // range is usually 50,000..100.000km/h
    auto asteroid_volume   = formula::volume_of_sphere(asteroid_diameter / 2.0);
    auto asteroid_mass     = asteroid_volume * asteroid_density;
    auto impact_energy     = formula::kinetic_energy(asteroid_mass, asteroid_velocity);
    println(impact_energy, " or ", to_equivalent(impact_energy));


    print("31. What's the sound intensity of a 1W loudspeaker in 1m distance? ");
    auto loudspeaker_power    = 1_W;
    auto loudspeaker_distance = 1_m;
    auto sound_intensity      = formula::sound_intensity(loudspeaker_power, loudspeaker_distance);
    println(sound_intensity, " or ", to_equivalent(sound_intensity));


    print("32. What's the max diving time in salt water in 10m depth using a 10l bottle? ");
    auto average_breathing  = 20_l_per_min;
    auto bottle_volume      = 10_l;
    auto bottle_pressure    = 150_bar;
    auto dive_depth         = 10_m;
    auto salt_water_density = 1033.23_kg_per_m³;
    auto air_pressure       = 1013.25_hPa;
    auto water_pressure     = salt_water_density * constant::g_n * dive_depth + air_pressure;
    auto max_time           = (bottle_volume * bottle_pressure) / (average_breathing * water_pressure);
    println(max_time);


    print("33. What's the sum of 1m + 1nmi + 1ft + 1in? ");
    auto length_sum = 1_m + 1_nmi + 1_ft + 1_in;
    println(length_sum);


    print("34. What's the sum of 1 byte + 1kB + 1GB...(and so on)? ");
    auto byte_sum = 1_byte + 1_kB + 1_MB + 1_GB + 1_TB + 1_PB + 1_EB + 1_ZB + 1_YB + 1_RB + 1_QB;
    println(byte_sum);


    print("35. What's the speed sum here? ");
    auto speed_sum = 278_m_per_s + 1000_km_per_h + 540_kn + 621_mph + 0.85_Mach;
    println(speed_sum);


    print("36. What's a radar's geometrical horizon from 30ft height? ");
    auto Earth_radius         = 6371.009_km;
    auto Radar_station_height = 30_ft;
    auto distance             = sqrt((Earth_radius + Radar_station_height) * (Earth_radius + Radar_station_height) - Earth_radius * Earth_radius);
    println(distance, " or ", to_equivalent(distance));


    print("37. What's the distance the Earth has travelled so far? ");
    auto distance_Earth_to_Sun = constant::AU;
    auto distance_per_year     = formula::circumference_of_circle(distance_Earth_to_Sun);
    auto Earth_year            = 365.25_days;
    auto Earth_age             = Earth_year * 4.5e12;
    auto distance_total        = distance_per_year * (Earth_age / Earth_year);
    println(distance_total);


    print("38. What are the details of a 10m x 1m oak timber log? ");
    auto log_length     = 10_m;
    auto log_diameter   = 1_m;
    auto dry_oak_weight = 710_kg_per_m³; 
    auto dry_oak_power  = 4.2_kWh_per_kg;
    auto area           = formula::area_of_cylinder(log_diameter / 2, log_length);
    auto volume         = formula::volume_of_cylinder(log_diameter / 2, log_length);
    auto weight         = volume * dry_oak_weight;
    auto power          = weight * dry_oak_power;
    println(area, ", ", volume, ", ", weight, ", ", power);


    print("39. What's the min cable wire size for 100m copper, 230V, 30A max? ");
    auto conductor_resistivity  = 1.7241e-8_Ohm_m; // for copper
    auto cable_length           = 100_m;
    auto max_current            = 30_A;
    auto allowable_voltage_drop = 10_V; 
    auto A = (2.0 * conductor_resistivity * cable_length * max_current) / allowable_voltage_drop;
    println(A);


    print("40. What's the voltage of a capacitor (5V, 0.47µF, 4.7KOhm) after 10ms? ");
    auto CC   = 0.47_uF;
    auto V0   = 5_V;
    auto RR   = 4.7_kOhm;
    auto time = 10_ms;
    auto V1   = V0 * exp(-time / (RR * CC));
    println(V1);


    print("41. What's the ballistic max height/range/flight time of a bullet fired 45° on Moon's surface? ");
    auto muzzle_velocity   = 1000_m_per_s;
    auto altitude          = 0_m;
    auto launch_angle      = 45_deg;
    auto bullet_max_height = formula::ballistic_max_height(muzzle_velocity, altitude, launch_angle, dataset::Moon.surface_gravity);
    auto bullet_max_range  = formula::ballistic_max_range(muzzle_velocity, altitude, launch_angle, dataset::Moon.surface_gravity);
    auto bullet_flight_time= formula::ballistic_travel_time(muzzle_velocity, altitude, launch_angle, dataset::Moon.surface_gravity);
    println(bullet_max_height, ", ", bullet_max_range, ", ", bullet_flight_time);


    print("42. What are the frequencies and wavelengths of all musical notes? ");
    for (auto& note : dataset::musical_notes)
    {
        auto wavelength = formula::wavelength(constant::speed_of_sound, note.frequency);
        print(note.name, note.octave, "=", note.frequency, ",", wavelength, " ");
    }
    println("");


    print("43. What's the power of a 15PS motorcycle with 200kg weight? ");
    auto engine_power          = 15_PS;
    auto motorcycle_mass       = 200_kg;
    auto power_to_weight_ratio = motorcycle_mass / engine_power;
    println(engine_power, " and ", power_to_weight_ratio);


    print("44. What's the sum of the masses of all moons in the solar system? ");
    auto total_mass = 0_kg;
    for (auto& moon : dataset::moons)
    {
        auto volume = formula::volume_of_sphere(moon.mean_radius);
        total_mass += volume * moon.mean_density;
    }
    println(total_mass, " or ", to_equivalent(total_mass));


    print("45. How long takes a trip to Alpha Centauri at 25km/s? ");
    auto distance_Earth_to_Alpha_Centauri = 4.3_ly;
    auto travel_speed                     = 25_km_per_s;
    auto time_needed                      = distance_Earth_to_Alpha_Centauri / travel_speed;
    println(time_needed);


    print("46. How many wine bottles are needed for 1 hectoliter? ");
    auto total_volume      = 1_hl;
    auto volume_per_bottle = 750_ml;
    auto number_of_bottles = total_volume / volume_per_bottle;
    println(number_of_bottles);

    return 0;
}
