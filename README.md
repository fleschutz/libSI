[![CMake on multiple platforms](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml)

Type-safe SI Library in C++
===========================

Apply math based on SI units correct, with high precision, and as easy as possible. This SI library for C++ provides the following features:

* **Type-safe** [units](SI/units.h) (can't add a mass to a length), [constants](SI/constants.h) (e.g. constant::sigma), and [formulas](SI/formulas.h) (e.g. formula::wavelength())
* **Convenient** [literals](SI/literals.h) (e.g. 24_h or 3_GWh), [from_string()](SI/from_string.h), [to_string()](SI/to_string.h), and [print()](SI/print.h) functions.
* **High precision** by using 'double' in SI base units internally, **without runtime overhead** (compiles to nothing but simple doubles).
* **With [real-world data](SI/data/)** in SI units, e.g. [ISO standards](SI/data/ISO.h) or planet [Earth](SI/data/Earth.h)
* **Supports** SI base units, derived SI units, Imperial units, and many more.
* **Wide compatibility** for C++11 or higher and **platform-independent** for Linux (gcc & clang) and Windows (Visual Studio).
* **Modern C++ lib**: compact, header only, own namespace ("SI::"), no external dependencies, with [unit tests](SI/tests.h).

Code Example
------------
```
auto m = 1_g;
auto c = constant::speed_of_light;
auto E = m * c * c;
print(E);
```
See all 35 examples in [examples.cpp](examples.cpp). Executing: `cmake . && make && ./examples` generates the following:

```
1) What's the potential energy of just 1g mass? It's... 89.9 TJ
2) What's the average speed of Kiptum's world record in Marathon? It's...21.1 km/h
3) What's the free fall time from Burj Khalifa tower in Dubai? It's... 13.0 sec
4) What's the kinetic energy of a car at 50 km/h? It's... 125.4 kJ
5) What's the average temperature of 0°C, 32°F, 491.67°R, and 273.15K? It's... 0.0 °C (32.0 °F)
6) What's the average speed here? It's... 1002.0 km/h
7) What's the wavelength of H2 in vacuum? It's... 21.1 cm
8) What's the wavelength of the high 'c' music note? It's... 32.8 cm
9) What's a radar's geometrical horizon (the distance it can see)? It's... 10.8 km
10) What's the time needed to fly non-stop around the Earth at Mach 1? It's... 1.4 days
11) What's the travel time of sun light to Earth? It's... 8.3 min
12) What's the sum of 1 byte + 1kB + 1GB...(and so on)? It's... 1.001e+30
13) What's the sum of 1m + 1NM + 1ft? It's... 1.9 km
14) What's the population density on Earth (people per km² of land area)? It's... 55.1 /km²
15) How much land area would be available for each person on Earth? It's... 1.8 hm²
...
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
     ├📂data
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
