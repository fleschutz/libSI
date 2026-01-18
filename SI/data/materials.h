// SI/data/materials.h - data of materials as of 2025
#pragma once

#include <SI/units.h>

namespace SI { namespace data {

typedef struct {
	std::string name;
	SI::density density;
} material_data;

//                                 NAME        DENSITY
const material_data Aluminium = { "Aluminium", 2700_kg_per_m³ };
const material_data Asphalt   = { "Asphalt",   2120_kg_per_m³ };
const material_data Concrete  = { "Concrete",  2200_kg_per_m³ };
const material_data Copper    = { "Copper",    8300_kg_per_m³ };
const material_data Gold      = { "Gold",     19300_kg_per_m³ };
const material_data Granite   = { "Granite",   2750_kg_per_m³ };
const material_data Paper     = { "Paper",      700_kg_per_m³ };
const material_data Tin       = { "Tin",       7304_kg_per_m³ };
const material_data Titanium  = { "Titanium",  4730_kg_per_m³ }; // Titanium Alloy (6% Al, 4% V)
const material_data Tungsten  = { "Tungsten", 19300_kg_per_m³ };
const material_data Zinc      = { "Zinc",      7144_kg_per_m³ };

const material_data materials[] = { Aluminium, Asphalt, Concrete, Copper, Gold, Granite, Paper, Tin, Titanium, Tungsten, Zinc };

} } // SI::data

// Sources
// -------
// 1. https://amesweb.info/Materials/Density-Materials.aspx
