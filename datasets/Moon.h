/// @file     datasets/Moon.h
/// @brief    Contains data of our Moon, e.g. Moon.mass
/// @details  Source: https://en.wikipedia.org/wiki/Moon (as of 2026)

#pragma once
#include <SI/literals.h>

namespace Moon {
  using namespace SI;

  // Orbital characteristics
  const length        average_perigee =            362'600_km;
  const length        average_apogee =             405'400_km;
  const length        semi_major_axis =            384'399_km;
  const length        mean_orbit_radius =          384'784_km;
  const dimensionless eccentricity =                0.0549;
  const SI::time      sidereal_orbital_period = 27.321'661_day;
  const SI::time      synodic_orbital_period =  29.530'589_day;
  const velocity      average_orbital_speed =        1'022_km_per_s;
  const angle         inclination =                  5.145_deg; // to the ecliptic

  // Physical characteristics
  const length        mean_radius =                1'737.4_km;
  const length        equatorial_radius =          1'738.1_km;
  const length        polar_radius =               1'736.0_km;
  const dimensionless flattening =                     0.0012;
  const length        equatorial_circumference =    10'921_km;
  const area          surface_area =               3.793e7_km²;
  const SI::volume    volume =                   2.1958e10_km³;
  const SI::mass      mass =                      7.346e22_kg;
  const density       mean_density =                 3.344_g_per_cm³; 
  const acceleration  surface_gravity =              1.622_m_per_s²;
  const velocity      escape_velocity =               2.38_km_per_s;
  const velocity      equatorial_rotation_velocity = 4.627_m_per_s;
  const dimensionless albedo =                       0.136;

  // Atmosphere
  const pressure      surface_pressure_day  =        10e-7_Pa;
  const pressure      surface_pressure_night  =     10e-10_Pa;

} // end of namespace Moon
