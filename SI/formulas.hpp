#pragma once

#include "types.hpp"

namespace si
{
	namespace formula
	{
		si::length wavelength(si::speed v, si::frequency f)
		{
			return v / f;
		}

		si::length motion(si::length s0, si::speed v0, si::acceleration a, si::time t)
		{
			return s0 + v0 * t + .5 * a * t * t;
		}
	}
}
