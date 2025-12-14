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
* Supports SI base and derived units, digital units, and Imperial units
* Supports hundreds of usage examples
* Supports unit tests to check everything
* No runtime overhead: Compiles to nothing but simple doubles
  
Folder Structure
----------------
```
  ├📂SI
  │  ├📄constants.hpp - with constants in SI units
  │  ├📄Earth.hpp - with physical characteristics of planet Earth
  │  ├📄everything.hpp - contains everything for convenience
  │  ├📄formulas.hpp - with common formulas
  │  ├📄Jupiter.hpp - with physical characteristics of planet Jupiter
  │  ├📄literals.hpp - with SI literals for convenience
  │  ├📄Mars.hpp - with physical characteristics of planet Mars
  │  ├📄Mercury.hpp - with physical characteristics of planet Mercury
  │  ├📄Moon.hpp - with physical characteristics of the Moon
  │  ├📄prefixes.hpp - with the SI prefixes
  │  ├📄printer.hpp - with a simple output interface 
  │  ├📄Sun.hpp - with physical characteristics of the Sun
  │  ├📄types.hpp - with basic SI types
  │  ├📄unit_tests.cpp - with unit tests for basic tests
  ├📄CMakeLists.txt - the Makefile for cmake
  ├📄LICENSE - the CC0 license
  ├📄README.md - this README
  ├📄main.cpp - with hundreds of usage example
```

Program Output
--------------
```
What's the average speed of Kiptum's world record in Marathon? It's...21.0975 km/h
What's the potential energy of 1kg mass? It's... 8.98755e+10 GJ
What's the kinetic energy of a car at 50 km/h? It's... 21.06 MJ
What's the average speed here? It's... 187758 km/h
What's the average temperature here? It's... 0°C
What's the wavelength of H2 in vacuum? It's... 21.1061 cm
What's the free fall time from Eiffel Tower in Paris? It's... 8.20374 sec
What's Markus BMI? OMG, it's... 24.9307
What's a radar's geometrical horizon (the distance it can see)? It's... 10.7941 km
What's the time needed to fly non-stop around the Earth at Mach 1? It's... 33.7332 h
What's the travel time of sun light to Earth? It's... 8.31675 min
What's the sum of 1 byte + 1kB + 1GB...(and so on)? It's... 1.001e+30
What's the population density on Earth (people per km² of land area)? It's... 55.0557
How much land area would be available for each person on Earth? It's... 18163.4 m²
What's the surface area of a soccer ball (FIFA size 5)? It's... 776.521 cm²
What's the volume of a soccer ball (FIFA size 5)? It's... 5755.04 cm³
```
