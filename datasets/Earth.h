/// @file     datasets/Earth.h
/// @brief    Contains data of our Earth, e.g. Earth::mass
/// @details  Source: https://en.wikipedia.org/wiki/Earth (as of 2026)
///           Categories are: Orbital characteristics, Physical characteristics, Atmosphere, and Various.

#pragma once
#include <SI/literals.h>

namespace Earth {
  using namespace SI;

  // Orbital characteristics
  constexpr length        aphelion =        152'097'597_km;
  constexpr length        perihelion =      147'098'450_km;
  constexpr length        semi_major_axis = 149'598'023_km;
  constexpr dimensionless eccentricity =              0.016'7086;
  constexpr SI::time      sidereal_orbital_period = 365.256'363'004_days;
  constexpr velocity      average_orbital_speed =    29.7827_km_per_s;
  constexpr angle         mean_anomaly =            358.617_deg;

  // Physical characteristics
  constexpr length        mean_radius =           6'371.0_km;
  constexpr length        equatorial_radius = 6'378.137_km;
  constexpr length        polar_radius =      6'356.752_km;
  constexpr dimensionless flattening =                1.0/298.257'222'101;
  constexpr length        equatorial_circumference = 40'075.017_km;
  constexpr length        meridional_circumference = 40'007.863_km;
  constexpr area          surface_area =    510'072'000_km²;
  constexpr area          land_area =       148'940'000_km²;
  constexpr area          water_area =      361'132'000_km²;
  constexpr SI::volume    volume =           1.08321e12_km³;
  constexpr SI::mass      mass =             5.97217e24_kg; // ±0.00028e24
  constexpr density       mean_density =              5.513_g_per_cm³;
  constexpr acceleration  surface_gravity =           9.80665_m_per_s²; ///< exactly 1 g0
  constexpr dimensionless moment_of_inertia_factor =  0.3307;
  constexpr velocity      escape_velocity =          11.186_km_per_s;
  constexpr SI::time      synodic_rotation_period =  24_h;
  constexpr velocity      equatorial_rotation_velocity = 1674.4_km_per_h;
  constexpr angle         axial_tilt =               23.439'2811_deg;
  constexpr dimensionless geometric_albedo =          0.434;
  constexpr dimensionless bond_albedo =               0.294;
  constexpr temperature   blackbody_temperature =   255_K;
  constexpr temperature   min_surface_temperature = -89.2_degC;
  constexpr temperature   mean_surface_temperature = 14.76_degC;
  constexpr temperature   max_surface_temperature =  56.7_degC;

  // Atmosphere
  constexpr pressure      surface_pressure =    101.325_kPa; ///< at sea level
  constexpr dimensionless nitrogen =             78.08_percent;  ///< dry air
  constexpr dimensionless oxygen =               20.95_percent;    ///< dry air
  constexpr dimensionless water_vapor =           1_percent;   ///< up to 1%, is variable
  constexpr dimensionless argon =                 0.9340_percent;
  constexpr dimensionless carbon_dioxide =        0.0430_percent;
  constexpr dimensionless neon =                  0.00182_percent;
  constexpr dimensionless helium =                0.00052_percent;
  constexpr dimensionless methane =               0.00017_percent;
  constexpr dimensionless krypton =               0.00011_percent;
  constexpr dimensionless hydrogen =              0.00006_percent;

  // Various
  constexpr dimensionless population =            8.2e9;

} // end of namespace

