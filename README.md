The International System of Units (SI) in C++
=============================================

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
* Supports SI units, digital units, and Imperial units
* No runtime overhead: Compiles to nothing but simple doubles
  
Directory Tree
--------------
```
  ├📂SI
  │  ├📄constants.hpp (7K)
  │  ├📄Earth.hpp (893 bytes)
  │  ├📄everything.hpp (346 bytes)
  │  ├📄formulas.hpp (2K)
  │  ├📄Jupiter.hpp (121 bytes)
  │  ├📄literals.hpp (3K)
  │  ├📄Mars.hpp (144 bytes)
  │  ├📄Mercury.hpp (145 bytes)
  │  ├📄Moon.hpp (166 bytes)
  │  ├📄printer.hpp (2K)
  │  ├📄Sun.hpp (823 bytes)
  │  ├📄test_literals.cpp (1K)
  │  ├📄types.hpp (31K)
  ├📄CMakeLists.txt (339 bytes)
  ├📄LICENSE (7K)
  ├📄main.cpp (2K)
  ├📄README.md (952 bytes)
```
