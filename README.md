[![CMake on multiple platforms](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml)

Type-safe SI Math in C++
========================

Apply math based on SI units correct, with high precision and as easy as possible. This math lib provides the following features:

* **Type-safe** [units](SI/units.h) (can't add a mass to a length), [constants](SI/constants.h) (e.g. constant::sigma), and [formulas](SI/formulas.h) (e.g. formula::wavelength())
* **Convenient** [literals](SI/literals.h) (e.g. 24_h or 3_GWh) and based on [KISS principle](https://en.wikipedia.org/wiki/KISS_principle).
* Type-safe [values](SI/values/), e.g. [ISO standards](SI/values/ISO.h) or planet [Earth](SI/values/Earth.h)
* Supports SI base units, derived units, Imperial units, and many more.
* **Platform-independent** (requires C++11 or higher), tested on Linux with gcc 15.2 & clang 20.1.8 and on Windows with VS2017 & VS2026.
* Header only, own namespace ("SI::"), with [unit tests](SI/tests.h), and no runtime overhead (compiles to nothing but simple doubles)

Code Example
------------
```
auto m = 1_g;
auto c = constant::speed_of_light;
auto E = m * c * c;
print(E);
```
More examples in [examples.cpp](examples.cpp). Executing: `cmake . && make && ./examples` generates the following output:

```
What's the potential energy of just 1g mass? It's... 89.876TJ
What's the average speed of Kiptum's world record in Marathon? It's...21.098km/h
What's the free fall time from Burj Khalifa tower in Dubai? It's... 12.995sec
What's the kinetic energy of a car at 50 km/h? It's... 125.386kJ
What's the average temperature of 0°C, 32°F, 491.67°R, and 273.15K? It's... 0.000°C (32.000°F)
What's the average speed here? It's... 1002.017km/h
What's the wavelength of H2 in vacuum? It's... 21.106cm
What's the wavelength of the high 'c' music note? It's... 32.776cm
What's a radar's geometrical horizon (the distance it can see)? It's... 10.794km
What's the time needed to fly non-stop around the Earth at Mach 1? It's... 1.406 days
What's the travel time of sun light to Earth? It's... 8.317min
What's the sum of 1 byte + 1kB + 1GB...(and so on)? It's... 1.001e+30
What's the sum of 1m + 1NM + 1ft? It's... 1.853km
What's the population density on Earth (people per km² of land area)? It's... 55.056/km²
How much land area would be available for each person on Earth? It's... 1.816hm²
What's the surface area of a soccer ball? It's... 1559.718cm²
What's the volume of a soccer ball? It's... 5.792l
What's the surface area of a 30cm pizza? It's... 706.858cm²
What's the volume of a 30cm x 1cm pizza? It's... 706.858cm³
What's the distance the Earth has travelled so far? It's... 447.088Mly (megalight-years)
What's a car's braking distance on dry asphalt from 100km/h? It's... 48.225m
What's a car's braking distance on wet asphalt from 100km/h? It's... 64.300m
How long takes a 1TB download at 100MBit speed? It's... 22.222h
What's the aircraft's glide path on final at 10NM distance in 3000ft height? It's... 2.827°
What's Donald Trump's body-mass index (BMI)? It's... 28.255kg/m²
What are the details of a 10m x 1m oak timber log? It's... 32.987m², 7.854m³, 5.576t, 23.421MWh
What's the min cable wire size for 100m copper, 230V, 30A max? It's... 10.345mm²
What's the windchill temperature of 5°C air temperature at 55km/h wind? It's... -1.597°C (29.126°F)
What's the lift force of an A380 wing on sea level at 284km/h rotation speed? It's... 4.490MN
What's the impact energy of a 50m asteroid at 50,000km/h? It's... 15.782PJ (=3.772Mt TNT, 254.543 Hiroshima bombs)
```


File Structure
--------------
```
 📂SI-math
  ├📄CMakeLists.txt (360 bytes)
  ├📄examples.cpp (6K)
  ├📄LICENSE (7K)
  ├📄README.md (5K)
  ├📂SI
     ├📄all.h (446 bytes)
     ├📄constants.h (8K)
     ├📄formulas.h (4K)
     ├📄internal.h (18K)
     ├📄literals.h (14K)
     ├📄print.h (5K)
     ├📄tests.h (2K)
     ├📄units.h (31K)
     ├📂values
        ├📄densities.h (1K)
        ├📄Earth.h (4K)
        ├📄ISO.h (2K)
        ├📄Jupiter.h (912 bytes)
        ├📄Mars.h (787 bytes)
        ├📄Mercury.h (801 bytes)
        ├📄Moon.h (984 bytes)
        ├📄music.h (535 bytes)
        ├📄Sun.h (1K)
(21 files, 3 folders, 112K total)
```

Frequently Asked Questions
--------------------------
* **What's this SI?** It's the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units).
* **Is this repo feature-complete?** No, not yet. Please help to add missing parts.

🤝 Contributing
---------------
* Contributions, suggestions, and improvements are always welcome!
* Open an Issue if you encounter bugs or have feature ideas.
* Create a Pull Request if you'd like to improve something.


📜 License & Copyright
-----------------------
This open source project is licensed under the CC0-1.0 license. All trademarks are the property of their respective owners.
