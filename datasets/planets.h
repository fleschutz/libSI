// dataset from planets.csv (converted by csv2hpp 0.2 on 2026-02-01).
#pragma once
#include <SI/literals.h>
using namespace SI;

namespace dataset {

struct planet_data {
    const char* name;
    SI::mass mass;
    SI::length diameter;
    SI::density density;
    SI::acceleration gravity;
    SI::velocity escape_velocity;
    SI::time rotation_period;
    SI::time length_of_day;
    SI::length distance_from_sun;
    double perihelion;
    double aphelion;
    SI::time orbital_period;
    SI::velocity orbital_velocity;
    double orbital_inclination;
    double orbital_eccentricity;
    double obliquity_to_orbit;
    SI::temperature mean_temperature;
    SI::pressure surface_pressure;
    int number_of_moons;
    bool has_ring_system;
    bool has_global_magnetic_field;
};

const planet_data planets[] { // NOTE: 00=empty or unknown field
{"Mercury",0.33_kg,4879_km,5427_kg_per_m³,3.7_m_per_s²,4.3_m_per_s,1407.6_h,4222.6_h,57.9_km,46.,69.8,88._h,47.4_m_per_s,7.,0.205,0.034,167_degC,0_bar,0,false,true,},
{"Venus",4.87_kg,12104_km,5243_kg_per_m³,8.9_m_per_s²,10.4_m_per_s,-5832.5_h,2802._h,108.2_km,107.5,108.9,224.7_h,35._m_per_s,3.4,0.007,177.4,464_degC,92_bar,0,false,false,},
{"Earth",5.97_kg,12756_km,5514_kg_per_m³,9.8_m_per_s²,11.2_m_per_s,23.9_h,24._h,149.6_km,147.1,152.1,365.2_h,29.8_m_per_s,0.,0.017,23.4,15_degC,1_bar,1,false,true,},
{"Mars",0.642_kg,6792_km,3933_kg_per_m³,3.7_m_per_s²,5._m_per_s,24.6_h,24.7_h,227.9_km,206.6,249.2,687._h,24.1_m_per_s,1.9,0.094,25.2,-65_degC,0.01_bar,2,false,false,},
{"Jupiter",1898_kg,142984_km,1326_kg_per_m³,23.1_m_per_s²,59.5_m_per_s,9.9_h,9.9_h,778.6_km,740.5,816.6,4331_h,13.1_m_per_s,1.3,0.049,3.1,-110_degC,00_bar,79,true,true,},
{"Saturn",568_kg,120536_km,687_kg_per_m³,9._m_per_s²,35.5_m_per_s,10.7_h,10.7_h,1433.5_km,1352.6,1514.5,10747_h,9.7_m_per_s,2.5,0.057,26.7,-140_degC,00_bar,62,true,true,},
{"Uranus",86.8_kg,51118_km,1271_kg_per_m³,8.7_m_per_s²,21.3_m_per_s,-17.2_h,17.2_h,2872.5_km,2741.3,3003.6,30589_h,6.8_m_per_s,0.8,0.046,97.8,-195_degC,00_bar,27,true,true,},
{"Neptune",102_kg,49528_km,1638_kg_per_m³,11._m_per_s²,23.5_m_per_s,16.1_h,16.1_h,4495.1_km,4444.5,4545.7,59800_h,5.4_m_per_s,1.8,0.011,28.3,-200_degC,00_bar,14,true,true,},
{"Pluto",0.0146_kg,2370_km,2095_kg_per_m³,0.7_m_per_s²,1.3_m_per_s,-153.3_h,153.3_h,5906.4_km,4436.8,7375.9,90560_h,4.7_m_per_s,17.2,0.244,122.5,-225_degC,0.00001_bar,5,false,false,},
};

} // namespace dataset

