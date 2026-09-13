/// @file    datasets/Earth.h
/// @brief   Contains data of the Earth, e.g. SI::dataset::Earth.mass.
/// @details Categories are: Orbital characteristics, Physical characteristics, Atmosphere, Various, and References.

#pragma once
#include <SI/literals.h>
using namespace SI;

namespace dataset {

    const struct {

        // Orbital characteristics
        length aphelion =                152'097'597_km;
        length perihelion =              147'098'450_km;
        length semi_major_axis =         149'598'023_km;
        dimensionless eccentricity =     0.016'7086;
        SI::time sidereal_orbital_period = 365.256'363'004_day;
        velocity average_orbital_speed = 29.7827_km_per_s;
        angle mean_anomaly =             358.617_deg;

        // Physical characteristics
        length mean_radius =                 6'371.0_km;
        length equatorial_radius =         6'378.137_km;
        length polar_radius =              6'356.752_km;
        dimensionless flattening = 1.0/298.257'222'101;
        length equatorial_circumference = 40'075.017_km;
        length meridional_circumference = 40'007.863_km;
        area surface_area =              510'072'000_km²;
        area land_area =                 148'940'000_km²;
        area water_area =                361'132'000_km²;
        SI::volume volume =               1.08321e12_km³;
        SI::mass mass =                   5.97217e24_kg; // ±0.00028e24
        density mean_density =                 5.513_g_per_cm³;
        acceleration surface_gravity =       9.80665_m_per_s²; // exactly 1 g0
        dimensionless moment_of_inertia_factor = 0.3307;
        velocity escape_velocity =            11.186_km_per_s;
        SI::time synodic_rotation_period =        24_h;
        velocity equatorial_rotation_velocity = 1674.4_km_per_h;
        angle axial_tilt =               23.439'2811_deg;
        dimensionless geometric_albedo = 0.434;
        dimensionless bond_albedo =       0.294;
        temperature blackbody_temperature = 255_K;
        temperature min_surface_temperature = -89.2_degC;
        temperature mean_surface_temperature = 14.76_degC;
        temperature max_surface_temperature = 56.7_degC;

        // Atmosphere
        pressure surface_pressure = 101.325_kPa; // (at sea level)
        dimensionless nitrogen = 78.08_percent; // (dry air)
        dimensionless oxygen = 20.95_percent; // (dry air)
        dimensionless water_vapor = 1_percent; // (up to, variable)
        dimensionless argon = 0.9340_percent;
        dimensionless carbon_dioxide = 0.0430_percent;
        dimensionless neon = 0.00182_percent;
        dimensionless helium = 0.00052_percent;
        dimensionless methane = 0.00017_percent;
        dimensionless krypton = 0.00011_percent;
        dimensionless hydrogen = 0.00006_percent;

        // Various
        dimensionless population =           8.2e9;

        // References
        // ----------
        // 1. https://en.wikipedia.org/wiki/Earth
        // 2. https://en.wikipedia.org/wiki/List_of_gravitationally_rounded_objects_of_the_Solar_System

    } Earth;

} // namespace dataset

