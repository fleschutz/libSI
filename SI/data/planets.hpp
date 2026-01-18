// dataset converted from planets.csv by csv2hpp (000=unknown)
#pragma once

#include <string>
#include <SI/literals.h>

namespace SI { namespace dataset { 

struct planet_data {
    std::string planet_name;
    SI::mass mass;
    SI::length diameter;
    SI::density density;
    SI::acceleration gravity;
    SI::velocity escape_velocity;
    SI::time rotation_period;
    SI::time length_of_day;
    SI::mass distance_from_sun;
    float perihelion;
    float aphelion;
    SI::time orbital_period;
    SI::velocity orbital_velocity;
    float orbital_inclination;
    float orbital_eccentricity;
    float obliquity_to_orbit;
    SI::temperature mean_temperature;
    SI::pressure surface_pressure;
    int number_of_moons;
    bool has_ring_system;
    bool has_global_magnetic_field;
};

const planet_data planets[] {
 { "Mercury", 0.330000_kg, 4879.000000_km, 5427.000000_kg_per_m³, 3.700000_m_per_s², 4.300000_m_per_s, 1407.600000_h, 4222.600000_h, 57.900000_kg, 46.000000, 69.800000, 88.000000_h, 47.400000_m_per_s, 7.000000, 0.205000, 0.034000, 167.000000_degC, 0.000000_bar, 0, false, true, },
 { "Venus", 4.870000_kg, 12104.000000_km, 5243.000000_kg_per_m³, 8.900000_m_per_s², 10.400000_m_per_s, -5832.500000_h, 2802.000000_h, 108.200000_kg, 107.500000, 108.900000, 224.700000_h, 35.000000_m_per_s, 3.400000, 0.007000, 177.400000, 464.000000_degC, 92.000000_bar, 0, false, false, },
 { "Earth", 5.970000_kg, 12756.000000_km, 5514.000000_kg_per_m³, 9.800000_m_per_s², 11.200000_m_per_s, 23.900000_h, 24.000000_h, 149.600000_kg, 147.100000, 152.100000, 365.200000_h, 29.800000_m_per_s, 0.000000, 0.017000, 23.400000, 15.000000_degC, 1.000000_bar, 1, false, true, },
 { "Mars", 0.642000_kg, 6792.000000_km, 3933.000000_kg_per_m³, 3.700000_m_per_s², 5.000000_m_per_s, 24.600000_h, 24.700000_h, 227.900000_kg, 206.600000, 249.200000, 687.000000_h, 24.100000_m_per_s, 1.900000, 0.094000, 25.200000, -65.000000_degC, 0.010000_bar, 2, false, false, },
 { "Jupiter", 1898.000000_kg, 142984.000000_km, 1326.000000_kg_per_m³, 23.100000_m_per_s², 59.500000_m_per_s, 9.900000_h, 9.900000_h, 778.600000_kg, 740.500000, 816.600000, 4331.000000_h, 13.100000_m_per_s, 1.300000, 0.049000, 3.100000, -110.000000_degC, 000_bar, 79, true, true, },
 { "Saturn", 568.000000_kg, 120536.000000_km, 687.000000_kg_per_m³, 9.000000_m_per_s², 35.500000_m_per_s, 10.700000_h, 10.700000_h, 1433.500000_kg, 1352.600000, 1514.500000, 10747.000000_h, 9.700000_m_per_s, 2.500000, 0.057000, 26.700000, -140.000000_degC, 000_bar, 62, true, true, },
 { "Uranus", 86.800000_kg, 51118.000000_km, 1271.000000_kg_per_m³, 8.700000_m_per_s², 21.300000_m_per_s, -17.200000_h, 17.200000_h, 2872.500000_kg, 2741.300000, 3003.600000, 30589.000000_h, 6.800000_m_per_s, 0.800000, 0.046000, 97.800000, -195.000000_degC, 000_bar, 27, true, true, },
 { "Neptune", 102.000000_kg, 49528.000000_km, 1638.000000_kg_per_m³, 11.000000_m_per_s², 23.500000_m_per_s, 16.100000_h, 16.100000_h, 4495.100000_kg, 4444.500000, 4545.700000, 59800.000000_h, 5.400000_m_per_s, 1.800000, 0.011000, 28.300000, -200.000000_degC, 000_bar, 14, true, true, },
 { "Pluto", 0.014600_kg, 2370.000000_km, 2095.000000_kg_per_m³, 0.700000_m_per_s², 1.300000_m_per_s, -153.300000_h, 153.300000_h, 5906.400000_kg, 4436.800000, 7375.900000, 90560.000000_h, 4.700000_m_per_s, 17.200000, 0.244000, 122.500000, -225.000000_degC, 0.000010_bar, 5, false, false, },
 { },
};

} } // SI::dataset

