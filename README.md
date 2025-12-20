Type-safe Math in C++
=====================

This repo provides type-safe computations on arbitrary units and easy conversion to and from them.

Features
--------
* Type-safe [units](SI/units.h): Can't add a mass to a length
* Type-safe [literals](SI/literals.h), e.g. 5_km or 24_h
* Type-safe [constants](SI/constants.h), e.g. constant::sigma
* Type-safe [formulas](SI/formulas.h), e.g. formula::circumference()
* Type-safe [values](SI/values/), e.g. for planet [Earth](SI/Earth.h) or the [Moon](SI/Moon.h).
* Supports SI base units, SI derived units, Imperial units, and many more.
* Header only, own namespace, with [unit tests](SI/tests.h), no runtime overhead (compiles to nothing but simple doubles)

Code Example
------------
```
auto m = 1_kg;
auto c = constant::speed_of_light;
auto E = m * c * c;
```
See all examples in [examples.cpp](examples.cpp). Executing: `cmake . && make && ./examples` produces the following output:

```
What's the average speed of Kiptum's world record in Marathon? It's...21.0975km/h
What's the potential energy of 1kg mass? It's... 8.98755e+07 GJ
What's the kinetic energy of a car at 50 km/h? It's... 125.386 kJ
What's the average speed here? It's... 185765km/h
What's the average temperature of 0°C, 32°F, 491.67°R, and 273.15K? It's... 204.862°K
What's the wavelength of H2 in vacuum? It's... 21.1061cm
What's the free fall time from Burj Khalifa tower in Dubai? It's... 12.9948sec
What's Markus BMI? OMG, it's... 24.9307
What's a radar's geometrical horizon (the distance it can see)? It's... 10.7941km
What's the time needed to fly non-stop around the Earth at Mach 1? It's... 33h 43min
What's the travel time of sun light to Earth? It's... 8.31675min
What's the sum of 1 byte + 1kB + 1GB...(and so on)? It's... 1.001e+30
What's the sum of 1m + 1NM + 1ft? It's... 1.8533km
What's the population density on Earth (people per km² of land area)? It's... 55.0557
How much land area would be available for each person on Earth? It's... 18163.4m²
What's the surface area of a soccer ball? It's... 779.859cm²
What's the volume of a soccer ball? It's... 5792.19cm³
What's the surface area of a 30cm pizza? It's... 706.858cm²
What's the volume of a 30cm x 1cm pizza? It's... 706.858cm³
What's the distance the Earth has travelled so far? It's... 446.782 megalight-year(s)
What's a car's braking distance on dry asphalt from 100km/h? It's... 48.2253m
What's a car's braking distance on wet asphalt from 100km/h? It's... 64.3004m
How long takes a 1TB download at 100MBit speed? It's... 22h 13min
What's the aircraft's glide path on final at 10NM distance in 3000ft height? It's... 2.82661°
```


Folder Structure
----------------
```
  ├📂SI
  │  ├📄all.h (388 bytes)
  │  ├📄constants.h (7K)
  │  ├📄formulas.h (2K)
  │  ├📄literals.h (7K)
  │  ├📄print.h (3K)
  │  ├📄tests.h (3K)
  │  ├📄units.h (32K)
  │  ├📂values
  │  │  ├📄Earth.h (3K)
  │  │  ├📄Jupiter.h (954 bytes)
  │  │  ├📄Mars.h (828 bytes)
  │  │  ├📄Mercury.h (834 bytes)
  │  │  ├📄Moon.h (1K)
  │  │  ├📄music.h (480 bytes)
  │  │  ├📄Sun.h (1K)
  ├📄CMakeLists.txt (318 bytes)
  ├📄LICENSE (7K)
  ├📄examples.cpp (5K)
  ├📄README.md (4K)
     (24 files, 5 folders, 5MB in total)

```

🤝 Contributing
---------------
* Contributions, suggestions, and improvements are welcome!
* Open an Issue if you encounter bugs or have feature ideas.
* Create a Pull Request if you'd like to improve something.


📜 License & Copyright
-----------------------
This open source project is licensed under the CC0-1.0 license. All trademarks are the property of their respective owners.
