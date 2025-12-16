// SI/Earth.hpp - contains data of planet Earth
#pragma once
#include "types.hpp"
#define CONST(_name, _value, _unit)  static constexpr auto _name = _unit(_value)

namespace si
{
	namespace Earth // source: https://en.wikipedia.org/wiki/Earth
	{
CONST( gravity,                     9.80665, meters_per_second2); // standard gravitational acceleration (G) for the surface of the Earth, defined 1901 in the third General Conference on Weights and Measures.
CONST( equatorial_radius,          6378.137, kilometer);      // denoted 'a'
CONST( equatorial_diameter, equatorial_radius * 2, meter);
CONST( equatorial_circumference, 40075.0167, kilometer); 
CONST( polar_radius,               6356.752, kilometer);      // denoted 'b'
CONST( polar_diameter,     polar_radius * 2, meter);
CONST( polar_circumference,   40007.8629173, kilometer);
CONST( radius,                         6371, kilometer);      // (2*a+b) / 3
CONST( diameter,                 radius * 2, meter);
CONST( surface_area,            510'072'000, kilometer2);
CONST( land_area,               148'940'000, kilometer2);
CONST( water_area,              361'132'000, kilometer2);
CONST( volume,                   1.08321e12, kilometer3);
CONST( mass,                      5.9723e24, kilogram);
CONST( equatorial_rotation_velocity, 1674.4, kilometers_per_hour);
CONST( age,                          4.5e12, year);
CONST( satellites,                        1, quantity); // the Moon
CONST( human_population,              8.2e9, quantity); // as of 2024

// Mountains:  (source: https://en.wikipedia.org/wiki/List_of_highest_mountains_on_Earth, heights above MSL, sorted by height)
CONST( Mount_Everest_height,           8849, meter);
CONST( K2_height,                      8611, meter);
CONST( Kangchenjunga_height,           8586, meter);
CONST( Lhotse_height,                  8516, meter);
CONST( Makalu_height,                  8485, meter);
CONST( Cho_Oyu_height,                 8188, meter);
CONST( Dhaulagiri_1_height,            8167, meter);
CONST( Manaslu_height,                 8163, meter);
CONST( Nanga_Parbat_height,            8126, meter);
CONST( Annapurna_1_height,             8091, meter);
CONST( Gasherbrum_1_height,            8080, meter);
CONST( Broad_Peak_height,              8051, meter);
CONST( Gasherbrum_2_height,            8035, meter);
CONST( Shishapangma_height,            8027, meter);
CONST( Gyachung_Kang_height,           7952, meter);
CONST( Gasherbrum_3_height,            7946, meter);
CONST( Annapurna_2_height,             7937, meter);
// ...
CONST(Zugspitze_height,                2962, meter);

// Buildings: (source: https://en.wikipedia.org/wiki/List_of_tallest_buildings, sorted by height)
CONST( Burj_Khalifa_height,             828, meter);
CONST( Merdeka_height,                  678.9, meter);
CONST( Shangai_Tower_height,            632, meter);
CONST( The_Clock_Towers_height,         601, meter);
CONST( Ping_An_Tower_height,            599.1, meter);
const auto Lotte_World_Tower_height      = meter(554.5);
const auto One_World_Trade_Center_height = meter(541.3);
const auto Guangzhou_CTF_height          = meter(530);
const auto Tianjin_CTF_height            = meter(530);
const auto China_Zun_height              = meter(527.7);
const auto Taipei_101_height             = meter(508);
// ...
const auto Eiffel_Tower_height           = meter(330);
const auto Great_Wall_length             = kilometer(6430); // (approximately)

// City distances: (source: distancecalculator.net, sorted alphabetically)
const auto Boston_to_NewYorkCity = kilometer(306);
const auto Berlin_to_Paris = kilometer(878.080);
// ...
const auto NewYorkCity_to_Boston = kilometer(306);
const auto Paris_to_Berlin = kilometer(878.080);
	}
}

#undef CONST
