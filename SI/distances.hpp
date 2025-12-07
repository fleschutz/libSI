#pragma once

#include "types.hpp"

namespace si
{
	namespace dist
	{
		const length Marathon = kilometer(42.195);
		const length Great_Wall_of_China = kilometer(6430); // (approximately)

		// diameters:
		const length Sun_diameter = kilometer(1390176);
		const length Jupiter_diameter = kilometer(152800);
		const length Moon_diameter = kilometer(3476);

		// city distances: (source: distancecalculator.net, sorted alphabetically)
		const length Boston_to_NewYorkCity = kilometer(306);
		const length Berlin_to_Paris = kilometer(878.080);
		const length NewYorkCity_to_Boston = kilometer(306);
		const length Paris_to_Berlin = kilometer(878.080);
	}
}
