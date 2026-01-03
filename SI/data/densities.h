// SI/data/densities.h - densities of various materials
#pragma once

#include "../../SI/literals.h"
#define SET(_name, _value) const auto _name = _value

namespace SI
{
	SET( Aluminium_density, 2700_kg_per_m³);
	SET( Asphalt_density,   2120_kg_per_m³);
	SET( Brick_density,     1800_kg_per_m³);
	SET( Coal_density,      1350_kg_per_m³); // (on average)
	SET( Concrete_density,  2200_kg_per_m³);
	SET( Copper_density,    8300_kg_per_m³);
	SET( Gold_density,     19300_kg_per_m³);
	SET( Granite_density,   2750_kg_per_m³);
	SET( Ice_density,        917_kg_per_m³); // (at 0°C)
	SET( Iron_density,      7272_kg_per_m³);
	SET( Lead_density,     11340_kg_per_m³);
	SET( Marble_density,    2770_kg_per_m³); // (average)
	SET( Nickel_density,    8666_kg_per_m³);
	SET( Paper_density,      700_kg_per_m³);
	SET( Plexiglas_density, 1180_kg_per_m³);
	SET( Sand_density,      1500_kg_per_m³); // (dry)
	SET( Sandstone_density, 2300_kg_per_m³); // (average)
	SET( Silicon_density,   2330_kg_per_m³);
	SET( Silver_density,   10524_kg_per_m³);
	SET( Snow_density,       560_kg_per_m³); // (firm)
	SET( Tin_density,       7304_kg_per_m³); 
	SET( Tunsten_density,  19300_kg_per_m³);
	SET( Wool_density,       100_kg_per_m³);
	SET( Zinc_density,      7144_kg_per_m³);
}
#undef SET

// Sources
// -------
// 1. https://amesweb.info/Materials/Density-Materials.aspx
