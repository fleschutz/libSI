// SI/prefixes.h - contains the 24 SI prefixes as of 2022 
#pragma once

#include "units.h"

namespace si
{
	namespace prefix // (source: https://en.wikipedia.org/wiki/Metric_prefix)
	{
#define PREFIX(_name, _symbol, _value)  constexpr si::quantity _name = _value, _symbol = _value
		PREFIX( quetta, Q,  1e30);
		PREFIX( ronna,  R,  1e27);
		PREFIX( yotta,  Y,  1e24); 
		PREFIX( zetta,  Z,  1e21);
		PREFIX( exa,    E,  1e18);
		PREFIX( peta,   P,  1e15); 
		PREFIX( tera,   T,  1e12);
		PREFIX( giga,   G,   1e9);
		PREFIX( mega,   M,   1e6);
		PREFIX( kilo,   k,   1e3);
		PREFIX( hecto,  h,   1e2); 
		PREFIX( deca,  da,   1e1); 

		PREFIX( deci,   d,  1e-1); 
		PREFIX( centi,  c,  1e-2); 
		PREFIX( milli,  m,  1e-3);
		PREFIX( micro,  μ,  1e-6);
		PREFIX( nano,   n,  1e-9); 
		PREFIX( pico,   p, 1e-12);
		PREFIX( femto,  f, 1e-15);
		PREFIX( atto,   a, 1e-18); 
		PREFIX( zepto,  z, 1e-21); 
		PREFIX( yocto,  y, 1e-24); 
		PREFIX( ronto,  r, 1e-27);
		PREFIX( quecto, q, 1e-30);
#undef PREFIX
	}
}	

