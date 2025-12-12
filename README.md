The International System of Units (SI) as C++ Lib
=================================================

This repo supports type-safe programming with SI units and easy conversion to and from them. The SI comprises a coherent system of units of measurement starting with 7 base units,
which are **second** (symbol s, the unit of time), **metre** (m, length), **kilogram** (kg, mass), **ampere** (A, electric current), **kelvin** (K, thermodynamic temperature),
**mole** (mol, amount of substance), and **candela** (cd, luminous intensity).

Code Example
------------
```
auto m = 1_kg;
auto c = constant::speed_of_light_in_vacuum;
auto E = m * c * c;
```

Features
--------
* Supports type checking: Can't add a mass to a length
* Supports convenient literals, e.g. 10_km
* Supports hundreds of constants
* No runtime overhead: Compiles to nothing but simple doubles
  
