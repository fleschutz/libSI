// SI/data/materials.h - data of materials as of 2025
#pragma once

#include "../../SI/units.h"

namespace SI { namespace material {

typedef struct {
	density dens;
} Material;

const Material Aluminium = { 2700_kg_per_m³ };
const Material Gold = { 3000_kg_per_m³ };

const Material materials[] = {
	Aluminium, Gold
};

} } // SI::Material

// Sources
// -------
// 1. https://matmake.com/materials-data/aluminum-properties.html
