/// @file    dataset/Moon.h
/// @brief   Contains physical data of the Moon, e.g. Moon.mass.

#pragma once
#include <SI/literals.h>
using namespace SI;

namespace dataset {

    const struct {

        // Orbital characteristics
        length        average_perigee =            362'600_km;
        length        average_apogee =             405'400_km;
        length        semi_major_axis =            384'399_km;
        length        mean_orbit_radius =          384'784_km;
        dimensionless eccentricity =                0.0549;
        SI::time      sidereal_orbital_period = 27.321'661_day;
        SI::time      synodic_orbital_period =  29.530'589_day;
        velocity      average_orbital_speed =        1'022_km_per_s;
        angle         inclination =                  5.145_deg; // to the ecliptic

        // Physical characteristics
        length        mean_radius =                1'737.4_km;
        length        equatorial_radius =          1'738.1_km;
        length        polar_radius =               1'736.0_km;
        dimensionless flattening =                     0.0012;
        length        equatorial_circumference =    10'921_km;
        area          surface_area =               3.793e7_km²;
        SI::volume    volume =                   2.1958e10_km³;
        SI::mass      mass =                      7.346e22_kg;
        density       mean_density =                 3.344_g_per_cm³; 
        acceleration  surface_gravity =              1.622_m_per_s²;
        velocity      escape_velocity =               2.38_km_per_s;
        velocity      equatorial_rotation_velocity = 4.627_m_per_s;
        dimensionless albedo =                       0.136;

        // Atmosphere
        pressure      surface_pressure_day  =        10e-7_Pa;
        pressure      surface_pressure_night  =     10e-10_Pa;

        // References
        // ----------
        // 1. https://en.wikipedia.org/wiki/Moon (as of 2026)
    } Moon;

} // namespace dataset
