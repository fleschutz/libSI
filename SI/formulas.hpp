#pragma once

#include <cmath>
#include "types.hpp"

namespace si
{
	namespace formula
	{
		auto Pythagoras(si::length a, si::length b)
		{
			return sqrt(a*a + b*b);
		}

		auto wavelength(si::speed v, si::frequency f)
		{
			return v / f;
		}

		auto Newtons_motion(si::length s0, si::speed v0, si::acceleration a, si::time t)
		{
			return s0 + v0 * t + .5 * a * t * t;
		}

		auto Lorentz_force(double q, speed v, double B)
		{
			return q * v * B;
		}

		si::time free_fall_time(si::height h, si::acceleration gravity)
		{
			return sqrt((2.0 * h) / gravity);
		}

		si::angle glide_path(si::length horizontalDistance, si::height verticalChange)
		{
			return atan2(horizontalDistance, verticalChange);
		}

		si::height vertical_height(si::angle glidePath, si::length horizontalDistance)
		{
			return horizontalDistance * tan(glidePath);
		}
	}
}
