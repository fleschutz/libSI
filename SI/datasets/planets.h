// NOTE: This C/C++ header file has been converted from 'planets.csv'
//       on March 16, 2026 by using csv2hpp 0.7 with command-line:
//       /usr/local/bin/csv2hpp planets.csv planet
//       (more information at: https://github.com/fleschutz/csv2hpp)
// USAGE: #include "planets.hpp" ... for (auto& planet : dataset::planets) { ...
#pragma once
#include <SI/literals.h>
using namespace SI;

namespace dataset { 

struct planet_data {
	const char* name;                  // from column  1 (string)
	SI::mass mass;                     // from column  2 (kg)
	SI::length diameter;               // from column  3 (km)
	SI::density density;               // from column  4 (kg/m³)
	SI::acceleration gravity;          // from column  5 (m/s²)
	SI::velocity escape_velocity;      // from column  6 (m/s)
	SI::time rotation_period;          // from column  7 (h)
	SI::time length_of_day;            // from column  8 (h)
	SI::length distance_from_sun;      // from column  9 (km)
	float perihelion;                  // from column 10 (float)
	float aphelion;                    // from column 11 (float)
	SI::time orbital_period;           // from column 12 (h)
	SI::velocity orbital_velocity;     // from column 13 (m/s)
	float orbital_inclination;         // from column 14 (float)
	float orbital_eccentricity;        // from column 15 (float)
	double obliquity_to_orbit;         // from column 16 (double)
	SI::temperature mean_temperature;  // from column 17 (°C)
	SI::pressure surface_pressure;     // from column 18 (bar)
	unsigned char number_of_moons;     // from column 19 (byte)
	bool has_ring_system;              // from column 20 (bool)
	bool has_global_magnetic_field;    // from column 21 (bool)
};

const planet_data planets[] { // HINT: 00=empty or unknown field
{"Mercury",3.3e23_kg,4879_km,5427_kg_per_m³,3.7_m_per_s²,4.3_m_per_s,1407.6_h,4222.6_h,57.9_km,46.f,69.8f,88._h,47.4_m_per_s,7.f,0.205f,0.034,167_degC,0_bar,0,false,true},
{"Venus",4.87e24_kg,12104_km,5243_kg_per_m³,8.9_m_per_s²,10.4_m_per_s,-5832.5_h,2802._h,108.2_km,107.5f,108.9f,224.7_h,35._m_per_s,3.4f,0.007f,177.4,464_degC,92_bar,0,false,false},
{"Earth",5.97e24_kg,12756_km,5514_kg_per_m³,9.8_m_per_s²,11.2_m_per_s,23.9_h,24._h,149.6_km,147.1f,152.1f,365.2_h,29.8_m_per_s,0.f,0.017f,23.4,15_degC,1_bar,1,false,true},
{"Mars",6.42e23_kg,6792_km,3933_kg_per_m³,3.7_m_per_s²,5._m_per_s,24.6_h,24.7_h,227.9_km,206.6f,249.2f,687._h,24.1_m_per_s,1.9f,0.094f,25.2,-65_degC,0.01_bar,2,false,false},
{"Jupiter",1.8986e27_kg,142984_km,1326_kg_per_m³,23.1_m_per_s²,59.5_m_per_s,9.9_h,9.9_h,778.6_km,740.5f,816.6f,4331_h,13.1_m_per_s,1.3f,0.049f,3.1,-110_degC,00_bar,79,true,true},
{"Saturn",5.68e26_kg,120536_km,687_kg_per_m³,9._m_per_s²,35.5_m_per_s,10.7_h,10.7_h,1433.5_km,1352.6f,1514.5f,10747_h,9.7_m_per_s,2.5f,0.057f,26.7,-140_degC,00_bar,62,true,true},
{"Uranus",8.68e25_kg,51118_km,1271_kg_per_m³,8.7_m_per_s²,21.3_m_per_s,-17.2_h,17.2_h,2872.5_km,2741.3f,3003.6f,30589_h,6.8_m_per_s,0.8f,0.046f,97.8,-195_degC,00_bar,27,true,true},
{"Neptune",1.02e26_kg,49528_km,1638_kg_per_m³,11._m_per_s²,23.5_m_per_s,16.1_h,16.1_h,4495.1_km,4444.5f,4545.7f,59800_h,5.4_m_per_s,1.8f,0.011f,28.3,-200_degC,00_bar,14,true,true},
{"Pluto",1.30e22_kg,2370_km,2095_kg_per_m³,0.7_m_per_s²,1.3_m_per_s,-153.3_h,153.3_h,5906.4_km,4436.8f,7375.9f,90560_h,4.7_m_per_s,17.2f,0.244f,122.5,-225_degC,0.00001_bar,5,false,false},
}; // (21 columns x 9 rows = 189 cells)

} // namespace dataset

