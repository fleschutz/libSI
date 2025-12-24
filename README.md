[![CMake on multiple platforms](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml)

Type-safe Math in C++
=====================

This Math lib helps to apply mathematics correct, with high precision and as easy as possible. It provides type-safe computations on arbitrary units and easy conversion to and from them.

Features
--------
* Type-safe [units](SI/units.h): Can't add a mass to a length
* Type-safe and prefix-safe [literals](SI/literals.h), e.g. 24_h or 3_GWh
* Type-safe [constants](SI/constants.h), e.g. constant::sigma
* Type-safe [formulas](SI/formulas.h), e.g. formula::wavelength()
* Type-safe [ISO standards](ISO.h) and [values](SI/values/), e.g. for planet [Earth](SI/values/Earth.h)
* Supports SI base units, SI derived units, Imperial units, and many more.
* Platform-independant, requires C++11 or higher, tested with VS2017, gcc 15.2, and clang 20.1.8.
* Header only, own namespace, with [unit tests](SI/tests.h), no runtime overhead (compiles to nothing but simple doubles)

Code Example
------------
```
auto m = 1_kg;
auto c = constant::speed_of_light;
auto E = m * c * c;
```
See all examples in [examples.cpp](examples.cpp). Executing: `cmake . && make && ./examples` generates the following output:

```
What's the average speed of Kiptum's world record in Marathon? It's...21.0975km/h
What's the potential energy of 1kg mass? It's... 89875.5TJ
What's the kinetic energy of a car at 50 km/h? It's... 125.386kJ
What's the average speed here? It's... 1002km/h
What's the average temperature of 0°C, 32°F, 491.67°R, and 273.15K? It's... 273.15K
What's the wavelength of H2 in vacuum? It's... 21.1061cm
What's the wavelength of the high 'c' music note? It's... 32.7759cm
What's the free fall time from Burj Khalifa tower in Dubai? It's... 12.9948sec
What's a radar's geometrical horizon (the distance it can see)? It's... 10.7941km
What's the time needed to fly non-stop around the Earth at Mach 1? It's... 33h 43min
What's the travel time of sun light to Earth? It's... 8.31675min
What's the sum of 1 byte + 1kB + 1GB...(and so on)? It's... 1.001e+30
What's the sum of 1m + 1NM + 1ft? It's... 1.8533km
What's the population density on Earth (people per km² of land area)? It's... 55.0557
How much land area would be available for each person on Earth? It's... 18163.4m²
What's the surface area of a soccer ball? It's... 1559.72cm²
What's the volume of a soccer ball? It's... 5792.19cm³
What's the surface area of a 30cm pizza? It's... 706.858cm²
What's the volume of a 30cm x 1cm pizza? It's... 706.858cm³
What's the distance the Earth has travelled so far? It's... 4.46782e+08 light-year(s)
What's a car's braking distance on dry asphalt from 100km/h? It's... 48.2253m
What's a car's braking distance on wet asphalt from 100km/h? It's... 64.3004m
How long takes a 1TB download at 100MBit speed? It's... 22h 13min
What's the aircraft's glide path on final at 10NM distance in 3000ft height? It's... 2.82661°
What's Donald Trump's body-mass index (BMI)? It's... 28.2548
What are the details of a 10m x 1m oak tree log? It's... 32.9867m² 7.85398m³ 5.57633t 23.4206MWh
```


Folder Structure
----------------
```
 📂Math
  ├📄CMakeLists.txt (301 bytes)
  ├📄examples.cpp (5K)
  ├📄LICENSE (7K)
  ├📄README.md (4K)
  ├📂SI
  │  ├📄all.h (392 bytes)
  │  ├📄constants.h (7K)
  │  ├📄formulas.h (2K)
  │  ├📄internal.h (18K)
  │  ├📄literals.h (7K)
  │  ├📄print.h (3K)
  │  ├📄tests.h (2K)
  │  ├📄units.h (32K)
  │  ├📂values
  │  │  ├📄Earth.h (3K)
  │  │  ├📄Jupiter.h (954 bytes)
  │  │  ├📄Mars.h (828 bytes)
  │  │  ├📄Mercury.h (834 bytes)
  │  │  ├📄Moon.h (1K)
  │  │  ├📄music.h (480 bytes)
  │  │  ├📄Sun.h (1K)
(19 files, 3 folders, 97K in total)
```

Frequently Asked Questions
--------------------------
* **Isn't math boring?** No, everything is applied math: the Nature, cars, planes, rockets, smartphones, even music.
* **What is SI?** It's the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units).
* **Is this repo feature-complete?** No, not yet. Please help to add missing parts.

🤝 Contributing
---------------
* Contributions, suggestions, and improvements are welcome!
* Open an Issue if you encounter bugs or have feature ideas.
* Create a Pull Request if you'd like to improve something.


📜 License & Copyright
-----------------------
This open source project is licensed under the CC0-1.0 license. All trademarks are the property of their respective owners.
