// SI/data/materials.h - data of materials as of 2025
#pragma once

#include "../../SI/units.h"

namespace SI { namespace data {

typedef struct {
	std::string name;
	SI::density density;
} material_data;

const material_data Aluminium = { "Aluminium", 2700_kg_per_m³ };
const material_data Asphalt = { "Asphalt", 2120_kg_per_m³ };
const material_data Copper = { "Copper", 8300_kg_per_m³ };
const material_data Gold = { "Gold", 19300_kg_per_m³ };
const material_data Zinc = { "Zinc", 7144_kg_per_m³ };

const material_data materials[] = {
	Aluminium, Asphalt, Copper, Gold, Zinc
};

} } // SI::data

// Sources
// -------
// 1. https://amesweb.info/Materials/Density-Materials.aspx
// 2. https://matmake.com/materials-data/aluminum-properties.html
