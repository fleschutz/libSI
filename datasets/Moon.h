/// @file    dataset/Moon.h
/// @brief   Contains physical data of the Moon, e.g. Moon.mass.
/// @details Data as of 2026.

#pragma once
#include <SI/literals.h>
using namespace SI;

namespace dataset {

    const struct {
        SI::mass      mass =                      7.346e22_kg;
        SI::volume    volume =                   2.1958e10_km³;
        length        equatorial_radius =          1'738.1_km;
        length        polar_radius =               1'736.0_km;
        length        mean_radius =                1'737.4_km;
        dimensionless flattening =                  0.0012;
        length        equatorial_circumference =    10'921_km;
        area          surface_area =               3.793e7_km²;
        acceleration  surface_gravity =              1.622_m_per_s²;
        velocity      equatorial_rotation_velocity = 4.627_m_per_s;
        SI::time      day =                708.7 * 60 * 60_s;
    } Moon;
 
    // References
    // ----------
    // 1. https://en.wikipedia.org/wiki/Moon

} // namespace dataset

