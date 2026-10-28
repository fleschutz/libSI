/// @file     datasets/Moon.h
/// @brief    Contains data of our Moon, e.g. Moon::mass
/// @details  Source: https://en.wikipedia.org/wiki/Moon (as of 2026)

#pragma once
#include <SI/literals.h>

namespace Moon {
  using namespace SI;

  // Orbital characteristics
  constexpr length        average_perigee =            362'600_km;
  constexpr length        average_apogee =             405'400_km;
  constexpr length        semi_major_axis =            384'399_km;
  constexpr length        mean_orbit_radius =          384'784_km;
  constexpr dimensionless eccentricity =                     0.0549;
  constexpr SI::time      sidereal_orbital_period = 27.321'661_days;
  constexpr SI::time      synodic_orbital_period =  29.530'589_days;
  constexpr velocity      average_orbital_speed =        1'022_km_per_s;
  constexpr angle         inclination =                  5.145_deg; // to the ecliptic

  // Physical characteristics
  constexpr length        mean_radius =                1'737.4_km;
  constexpr length        equatorial_radius =          1'738.1_km;
  constexpr length        polar_radius =               1'736.0_km;
  constexpr dimensionless flattening =                       0.0012;
  constexpr length        equatorial_circumference =    10'921_km;
  constexpr area          surface_area =               3.793e7_km²;
  constexpr SI::volume    volume =                   2.1958e10_km³;
  constexpr SI::mass      mass =                      7.346e22_kg;
  constexpr density       mean_density =                 3.344_g_per_cm³; 
  constexpr acceleration  surface_gravity =              1.622_m_per_s²;
  constexpr velocity      escape_velocity =               2.38_km_per_s;
  constexpr velocity      equatorial_rotation_velocity = 4.627_m_per_s;
  constexpr dimensionless albedo =                           0.136;

  // Atmosphere
  constexpr pressure      surface_pressure_day  =        10e-7_Pa;
  constexpr pressure      surface_pressure_night  =     10e-10_Pa;

} // end of namespace 
