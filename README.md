Type-safe Math in C++
=====================

This repo provides type-safe computations on arbitrary units and easy conversion to and from them.

Features
--------
* Type-safe [units](SI/units.h): Can't add a mass to a length
* Type-safe [literals](SI/literals.h), e.g. 5_km or 24_h
* Type-safe [constants](SI/constants.h), e.g. constant::sigma
* Type-safe [formulas](SI/formulas.h), e.g. formula::circumference()
* With all 24 [SI prefixes](SI/prefixes.h), e.g. prefix::tera
* With hundreds of [examples](main.cpp)
* With hundreds of [unit tests](SI/tests.h) for safety
* Supports SI base and derived units, Imperial units, and various more
* Header only, own namespace, no runtime overhead (compiles to nothing but simple doubles)

Code Example
------------
```
auto m = 1_kg;
auto c = constant::speed_of_light;
auto E = m * c * c;
```

Program Output
--------------
```
What's the average speed of Kiptum's world record in Marathon? It's...21.0975 km/h
What's the potential energy of 1kg mass? It's... 8.98755e+07 GJ
What's the kinetic energy of a car at 50 km/h? It's... 125.386 kJ
What's the average speed here? It's... 185765 km/h
What's the average temperature of 0°C, 32°F, 491.67°R, and 273.15K? It's... 0°C
What's the wavelength of H2 in vacuum? It's... 21.1061 cm
What's the free fall time from Eiffel Tower in Paris? It's... 8.20374 sec
What's Markus BMI? OMG, it's... 24.9307
What's a radar's geometrical horizon (the distance it can see)? It's... 10.7941 km
What's the time needed to fly non-stop around the Earth at Mach 1? It's... 33h 43min
What's the travel time of sun light to Earth? It's... 8.31675 min
What's the sum of 1 byte + 1kB + 1GB...(and so on)? It's... 1.001e+30
What's the sum of 1m + 1NM + 1ft? It's... 1.8533 km
What's the population density on Earth (people per km² of land area)? It's... 55.0557
How much land area would be available for each person on Earth? It's... 18163.4 m²
What's the surface area of a soccer ball (in FIFA size 5)? It's... 779.859 cm²
What's the volume of a soccer ball (in FIFA size 5)? It's... 5792.19 cm³
What's the surface area of a 30cm pizza? It's... 706.858 cm²
What's the volume of a 30cm x 1cm pizza? It's... 706.858 cm³
What's the distance the Earth has travelled so far? It's... 446.782 megalight-year(s)
What's a car's braking distance on dry asphalt from 100km/h? It's... 48.2253m
What's a car's braking distance on wet asphalt from 100km/h? It's... 64.3004m
What's the 1TB file download time via 100MBit? It's... 22h 13min
What's an aircraft's glide path on final at 10NM in 3000ft height? It's... 2.82661°
```


Folder Structure
----------------
```
  ├📂SI
  │  ├📄all.h - includes any .h header file (for convenience)
  │  ├📄constants.h - provides universal constants 
  │  ├📄Earth.h - with characteristics of planet Earth
  │  ├📄formulas.h - with common formulas
  │  ├📄Jupiter.h - with physical characteristics of planet Jupiter
  │  ├📄literals.h - with SI literals for convenience
  │  ├📄Mars.h - with physical characteristics of planet Mars
  │  ├📄Mercury.h - with physical characteristics of planet Mercury
  │  ├📄Moon.h - with physical characteristics of the Moon
  │  ├📄prefixes.h - with the SI prefixes
  │  ├📄print.h - with a simple print to console interface 
  │  ├📄Sun.h - with physical characteristics of the Sun
  │  ├📄tests.h - with unit tests for basic tests
  │  ├📄units.h - the SI units
  ├📄CMakeLists.txt - the Makefile for cmake
  ├📄LICENSE - the CC0 license
  ├📄README.md - this README
  ├📄main.cpp - with hundreds of usage example
```
