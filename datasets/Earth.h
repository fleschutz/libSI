/// @file     datasets/Earth.h
/// @brief    Contains data of our Earth, e.g. Earth.mass
/// @details  Source: https://en.wikipedia.org/wiki/Earth (as of 2026)
///           Categories are: Orbital characteristics, Physical characteristics, Atmosphere, and Various.

#pragma once
#include <SI/literals.h>

namespace Earth {
  using namespace SI;

  // Orbital characteristics
  const length        aphelion =        152'097'597_km;
  const length        perihelion =      147'098'450_km;
  const length        semi_major_axis = 149'598'023_km;
  const dimensionless eccentricity =              0.016'7086;
  const SI::time      sidereal_orbital_period = 365.256'363'004_day;
  const velocity      average_orbital_speed =    29.7827_km_per_s;
  const angle         mean_anomaly =            358.617_deg;

  // Physical characteristics
  const length        mean_radius =           6'371.0_km;
  const length        equatorial_radius = 6'378.137_km;
  const length        polar_radius =      6'356.752_km;
  const dimensionless flattening =            1.0/298.257'222'101;
  const length        equatorial_circumference = 40'075.017_km;
  const length        meridional_circumference = 40'007.863_km;
  const area          surface_area = 510'072'000_km²;
  const area          land_area =    148'940'000_km²;
  const area          water_area =   361'132'000_km²;
  const SI::volume    volume =                1.08321e12_km³;
  const SI::mass      mass =                  5.97217e24_kg; // ±0.00028e24
  const density       mean_density =          5.513_g_per_cm³;
  const acceleration  surface_gravity =       9.80665_m_per_s²; ///< exactly 1 g0
  const dimensionless moment_of_inertia_factor = 0.3307;
  const velocity      escape_velocity =      11.186_km_per_s;
  const SI::time      synodic_rotation_period = 24_h;
  const velocity      equatorial_rotation_velocity = 1674.4_km_per_h;
  const angle         axial_tilt =           23.439'2811_deg;
  const dimensionless geometric_albedo =      0.434;
  const dimensionless bond_albedo =           0.294;
  const temperature   blackbody_temperature = 255_K;
  const temperature   min_surface_temperature = -89.2_degC;
  const temperature   mean_surface_temperature = 14.76_degC;
  const temperature   max_surface_temperature = 56.7_degC;

  // Atmosphere
  const pressure      surface_pressure =    101.325_kPa; ///< at sea level
  const dimensionless nitrogen =             78.08_percent;  ///< dry air
  const dimensionless oxygen =               20.95_percent;    ///< dry air
  const dimensionless water_vapor =           1_percent;   ///< up to 1%, is variable
  const dimensionless argon =                 0.9340_percent;
  const dimensionless carbon_dioxide =        0.0430_percent;
  const dimensionless neon =                  0.00182_percent;
  const dimensionless helium =                0.00052_percent;
  const dimensionless methane =               0.00017_percent;
  const dimensionless krypton =               0.00011_percent;
  const dimensionless hydrogen =              0.00006_percent;

  // Various
  const dimensionless population =            8.2e9;

} // end of namespace Earth

