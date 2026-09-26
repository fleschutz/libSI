/// @file     examples/astronomy.cpp
/// @brief    Contains 13 examples for astronomy.

#include <SI/all.h> 
#include "datasets/all.h"
using namespace SI;

void astronomy_examples() {

    println("ASTRONOMY");

    auto H2_frequency  = 1420.4057517682_MHz;
    auto H2_wavelength = formula::wavelength(constant::speed_of_light_in_vacuum, H2_frequency);
    println("1. The wavelength of hydrogen (H2) in vacuum is: ", H2_wavelength, " or ", to_equivalent(H2_wavelength));


    print("2. Which moons are greater than Earth's moon? ");
    for (auto& moon : dataset::moons) {
        if (moon.mean_radius > 1737.5_km)
            printf("%s's %s (ø=%s), ", moon.planet, moon.name, to_string(2. * moon.mean_radius).c_str());
    }
    println("");


    print("3. What's the min speed required to escape from the planets? ");
    for (auto& planet : dataset::planets) {
        auto min_speed = formula::gravitational_escape_velocity(planet.mass, planet.diameter / 2.0);
        print(planet.name, "=", min_speed, " or ", to_equivalent(min_speed), ", ");
    }
    println("");


    print("4. Which exoplanets are life-friendly and quite near? ");
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


    print("5. What's the attractive force between Sun and Earth? ");
    auto Sun_mass              = 1.988416E30_kg;
    auto Earth_mass            = 5.9722E24_kg;
    auto Earth_to_Sun_distance = 149'597'870'691_m;
    println(formula::gravitational_attractive_force(Sun_mass, Earth_mass, Earth_to_Sun_distance));


    print("6. What's the attractive force between Earth and Moon? ");
    auto Moon_mass              = 7.346E22_kg;
    auto Earth_to_Moon_distance = 384'399_km;
    println(formula::gravitational_attractive_force(Earth_mass, Moon_mass, Earth_to_Moon_distance));


    print("7. What's the travel time of sun light to Earth? ");
    println(Earth_to_Sun_distance / constant::speed_of_light_in_vacuum);


    print("8. What's the impact energy of a 50m asteroid at 50,000km/h? ");
    auto asteroid_diameter = 50_m;
    auto asteroid_density  = 2500_kg_per_m³; // mostly estimated only 
    auto asteroid_velocity = 50'000_km_per_h; // range is usually 50,000..100.000km/h
    auto asteroid_volume   = formula::volume_of_sphere(asteroid_diameter / 2.0);
    auto asteroid_mass     = asteroid_volume * asteroid_density;
    auto impact_energy     = formula::kinetic_energy(asteroid_mass, asteroid_velocity);
    println(impact_energy, " or ", to_equivalent(impact_energy));


    print("9. What's the total distance the Earth has travelled so far? ");
    auto distance_Earth_to_Sun = constant::AU;
    auto distance_per_year     = formula::circumference_of_circle(distance_Earth_to_Sun);
    auto Earth_year            = 365.25_days;
    auto Earth_age             = Earth_year * 4.5e12;
    auto distance_total        = distance_per_year * (Earth_age / Earth_year);
    println(distance_total);


    print("10. What's the ballistic max height/range/flight time of a bullet fired 45° on Moon's surface? ");
    auto muzzle_velocity   = 1000_m_per_s;
    auto altitude          = 0_m;
    auto launch_angle      = 45_deg;
    auto bullet_max_height = formula::ballistic_max_height(muzzle_velocity, altitude, launch_angle, dataset::Moon.surface_gravity);
    auto bullet_max_range  = formula::ballistic_max_range(muzzle_velocity, altitude, launch_angle, dataset::Moon.surface_gravity);
    auto bullet_flight_time= formula::ballistic_travel_time(muzzle_velocity, altitude, launch_angle, dataset::Moon.surface_gravity);
    println(bullet_max_height, ", ", bullet_max_range, ", ", bullet_flight_time);


    print("11. What's the sum of the masses of all moons in the solar system? ");
    auto total_mass = 0_kg;
    for (auto& moon : dataset::moons) {
        auto volume = formula::volume_of_sphere(moon.mean_radius);
        total_mass += volume * moon.mean_density;
    }
    println(total_mass, " or ", to_equivalent(total_mass));


    print("12. How long takes a trip to Alpha Centauri at 10% the speed of light? ");
    auto distance_to_Alpha_Centauri = 4.37_ly;
    auto travel_speed               = 10_percent * constant::speed_of_light_in_vacuum;
    auto time_needed                = distance_to_Alpha_Centauri / travel_speed;
    println(time_needed);


    print("13. How large is the event horizon of our galaxy's black hole? ");
    auto Sagittarius_A_mass = 8.54e36_kg;
    auto radius = formula::Schwarzschild_radius(Sagittarius_A_mass);
    println("Sagittarius A* Schwarzschild radius is ", radius, " or ", to_equivalent(radius));
}
