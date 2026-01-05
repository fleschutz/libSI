// SI/data/Earth.h - data of planet Earth as of 2025
#pragma once

#include "../../SI/units.h"
#define SET(_name, _value, _unit)  const auto _name = _unit(_value ## L)

namespace SI { namespace Earth {

SET( surface_gravity,             9.80665, meters_per_second2); // standard gravitational acceleration (G) for the surface of the Earth, defined 1901 in the third General Conference on Weights and Measures.
SET( equatorial_radius,          6378.137, kilometer);      // denoted 'a'
SET( equatorial_diameter, equatorial_radius * 2, meter);
SET( equatorial_circumference, 40075.0167, kilometer); 
SET( polar_radius,               6356.752, kilometer);      // denoted 'b'
SET( polar_diameter,     polar_radius * 2, meter);
SET( polar_circumference,   40007.8629173, kilometer);
SET( mean_radius,                    6371, kilometer);      // (2*a+b) / 3
SET( mean_diameter,       mean_radius * 2, meter);
SET( surface_area,            510'072'000, kilometer2);
SET( land_area,               148'940'000, kilometer2);
SET( water_area,              361'132'000, kilometer2);
SET( volume,                   1.08321e12, kilometer3);
SET( mass,                      5.9723e24, kilogram);
SET( equatorial_rotation_velocity, 1674.4, kilometers_per_hour);
SET( natural_satellites,                1, dimensionless); // see Moon.h
SET( human_population,              8.2e9, dimensionless); 
SET( solar_constant,                 1361, watts_per_meter2); // amount of Sun energy per square meter
SET( magnetic_field,               3.2e-5, tesla); // strength of Earth's magnetic field at 0° lat, 0° long.
SET( day,                    24 * 60 * 60, second); 
SET( week,         second(Earth::day) * 7, second);
SET( year,    second(Earth::day) * 365.25, second); // (on average)
SET( age,    second(Earth::year) * 4.5e12, second);

// Mountains:  (heights above MSL, sorted by height)
SET( Mount_Everest_height,           8849, meter);
SET( K2_height,                      8611, meter);
SET( Kangchenjunga_height,           8586, meter);
SET( Lhotse_height,                  8516, meter);
SET( Makalu_height,                  8485, meter);
SET( Cho_Oyu_height,                 8188, meter);
SET( Dhaulagiri_1_height,            8167, meter);
SET( Manaslu_height,                 8163, meter);
SET( Nanga_Parbat_height,            8126, meter);
SET( Annapurna_1_height,             8091, meter);
SET( Gasherbrum_1_height,            8080, meter);
SET( Broad_Peak_height,              8051, meter);
SET( Gasherbrum_2_height,            8035, meter);
SET( Shishapangma_height,            8027, meter);
SET( Gyachung_Kang_height,           7952, meter);
SET( Gasherbrum_3_height,            7946, meter);
SET( Annapurna_2_height,             7937, meter);
SET( Zugspitze_height,               2962, meter);
// ...

// Buildings: (sorted by height)
SET( Burj_Khalifa_height,             828, meter);
SET( Merdeka_height,                  678.9, meter);
SET( Shangai_Tower_height,            632, meter);
SET( The_Clock_Towers_height,         601, meter);
SET( Ping_An_Tower_height,            599.1, meter);
SET( Lotte_World_Tower_height,        554.5, meter);
SET( One_World_Trade_Center_height,   541.3, meter);
SET( Guangzhou_CTF_height,            530, meter);
SET( Tianjin_CTF_height,              530, meter);
SET( China_Zun_height,                527.7, meter);
SET( Taipei_101_height,               508, meter);
SET( Eiffel_Tower_height,             330, meter);
// ...

// Walls:
SET( Great_Wall_in_China_length,     6430, kilometer); // (approximately)
// ...

} } // SI::Earth
#undef SET

// Sources
// -------
// 1. https://en.wikipedia.org/wiki/Earth
// 2. https://en.wikipedia.org/wiki/List_of_highest_mountains_on_Earth
// 3. https://en.wikipedia.org/wiki/List_of_tallest_buildings
