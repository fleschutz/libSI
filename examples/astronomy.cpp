/// @file     examples/astronomy.cpp
/// @brief    Contains 13 astronomy examples using libSI.

#include <SI/core.h> 
#include <SI/datasets/astronomy.h>
using namespace SI;

void astronomy_examples() {

    std::cout << "    === ASTRONOMY EXAMPLES ===" << std::endl;
    to_string_formatting     = "%.1Lf%s"; // <-- one decimal place, no space between quantity and unit
    to_equivalent_formatting = "%.1Lf %s";// <-- one decimal place, with space between quantity and unit


    std::cout << " 1. The travel time of sun light to Earth is... ";
    auto Earth_to_Sun_distance = 149'597'870'691_m;
    std::cout << (Earth_to_Sun_distance / constant::speed_of_light_in_vacuum) << std::endl;


    std::cout << " 2. The travel time to Alpha Centauri at 10% the speed of light takes... ";
    auto distance_to_Alpha_Centauri = 4.37_ly;
    auto travel_speed               = 10_percent * constant::speed_of_light_in_vacuum;
    auto travel_time                = distance_to_Alpha_Centauri / travel_speed;
    std::cout << travel_time << std::endl;


    std::cout << " 3. The attractive force between Sun and Earth is... ";
    auto Sun_mass    = 1.988416E30_kg;
    auto Earth_mass  = 5.9722E24_kg;
    std::cout << formula::gravitational_attractive_force(Sun_mass, Earth_mass, Earth_to_Sun_distance) << std::endl;


    std::cout << " 4. The attractive force between Earth and Moon is... ";
    auto Moon_mass              = 7.346E22_kg;
    auto Earth_to_Moon_distance = 384'399_km;
    std::cout << formula::gravitational_attractive_force(Earth_mass, Moon_mass, Earth_to_Moon_distance) << std::endl;


    std::cout << " 5. The wavelength of hydrogen (H2) in vacuum is... ";
    auto H2_frequency  = 1420.4057517682_MHz;
    auto H2_wavelength = formula::wavelength(constant::speed_of_light_in_vacuum, H2_frequency);
    std::cout << H2_wavelength << " or " << to_equivalent(H2_wavelength) << std::endl;


    print(" 6. Greater moons than Earth's moon are... ");
    for (auto& moon : dataset::moons) {
        if (moon.mean_radius > 1737.5_km)
            printf("%s's %s (ø=%s), ", moon.planet, moon.name, to_string(2. * moon.mean_radius).c_str());
    }
    println("");


    print(" 7. The min speed required to escape from the planets are... ");
    for (auto& planet : dataset::planets) {
        auto min_speed = formula::gravitational_escape_velocity(planet.mass, planet.diameter / 2.0);
        print(planet.name, "=", min_speed, " or ", to_equivalent(min_speed), ", ");
    }
    println("");


    print(" 8. Exoplanets that are life-friendly and quite near are... ");
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


    std::cout << " 9. The impact energy of a 50m asteroid at 50,000km/h is... ";
    auto asteroid_diameter = 50_m;
    auto asteroid_density  = 2500_kg_per_m³; // mostly estimated only 
    auto asteroid_velocity = 50'000_km_per_h; // range is usually 50,000..100.000km/h
    auto asteroid_volume   = formula::volume_of_sphere(asteroid_diameter / 2.0);
    auto asteroid_mass     = asteroid_volume * asteroid_density;
    auto impact_energy     = formula::kinetic_energy(asteroid_mass, asteroid_velocity);
    std::cout << impact_energy << " or " << to_equivalent(impact_energy) << std::endl;


    std::cout << "10. The estimated total distance the Earth has travelled is... ";
    auto distance_Earth_to_Sun = constant::AU;
    auto distance_per_year     = formula::circumference_of_circle(distance_Earth_to_Sun);
    auto Earth_year            = 365.25_days;
    auto Earth_age             = Earth_year * 4.5e12;
    auto distance_total        = distance_per_year * (Earth_age / Earth_year);
    std::cout << distance_total << std::endl;


    print("11. The ballistic max height/range/flight time of a bullet fired 45° on Moon's surface is... ");
    auto muzzle_velocity   = 1000_m_per_s;
    auto altitude          = 0_m;
    auto launch_angle      = 45_deg;
    auto bullet_max_height = formula::ballistic_max_height(muzzle_velocity, altitude, launch_angle, dataset::Moon.surface_gravity);
    auto bullet_max_range  = formula::ballistic_max_range(muzzle_velocity, altitude, launch_angle, dataset::Moon.surface_gravity);
    auto bullet_flight_time= formula::ballistic_travel_time(muzzle_velocity, altitude, launch_angle, dataset::Moon.surface_gravity);
    println(bullet_max_height, ", ", bullet_max_range, ", ", bullet_flight_time);


    std::cout << "12. The sum of the masses of all moons in the solar system is... ";
    auto total_mass = 0_kg;
    for (auto& moon : dataset::moons) {
        auto volume = formula::volume_of_sphere(moon.mean_radius);
        total_mass += volume * moon.mean_density;
    }
    std::cout << total_mass << " or " << to_equivalent(total_mass) << std::endl;


    std::cout << "13. The event horizon of our galaxy's black hole (Sagittarius A*) is... ";
    auto Sagittarius_A_mass = 8.54e36_kg;
    auto radius             = formula::Schwarzschild_radius(Sagittarius_A_mass);
    std::cout << radius << " or " << to_equivalent(radius) << " (Schwarzschild radius)" << std::endl << std::endl;
}
