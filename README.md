[![CMake on multiple platforms](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml)

Type-safe SI Library in C++
===========================

Apply math based on SI units correct, with high precision, and as easy as possible. This SI library provides the following features:

* **Type-safe** [units](SI/units.h) (can't add a mass to a length), [constants](SI/constants.h) (e.g. constant::sigma), and [formulas](SI/formulas.h) (e.g. formula::wavelength())
* **Convenient** [literals](SI/literals.h) (e.g. 24_h or 3_GWh), [from_string()](SI/from_string.h), [to_string()](SI/to_string.h), and [print()](SI/print.h) functions.
* **High precision** by using 'double' in SI base units internally, **without runtime overhead** (compiles to nothing but simple doubles).
* **With [real-world data](SI/data/)** in SI units, e.g. [ISO standards](SI/data/ISO.h) or planet [Earth](SI/data/Earth.h)
* **Supports** SI base units, derived SI units, Imperial units, and many more.
* **Wide compatibility** (just requires C++17 or higher) with **cross-platform** support (e.g. Linux gcc & clang, Windows VS2017-VS2026).
* **Modern C++ lib**: header only, compact, own namespace ("SI::"), no external dependencies, with [unit tests](SI/tests.h).

🔎 Code Example
---------------
```cpp
#include "SI/all.h"
using namespace SI;

int main()
{	
	print("What's the potential energy of just 1g mass? ");
	auto m = 1_g;
	auto c = constant::speed_of_light;
	auto E = m * c * c;
	print(E);
}
```
Please find all 37 examples in: [examples.cpp](examples.cpp). Executing: `cmake . && make && ./examples` generates the output:

```
1) What's the potential energy of just 1g mass? 89.88TJ
2) What's the average speed of Kiptum's world record in Marathon? 21.10km/h
3) What's the free fall time from Burj Khalifa tower in Dubai? 12.99sec
4) What's the kinetic energy of a car at 50 km/h? 125.39kJ
5) What's the average temperature of 0°C, 32°F, 491.67°R, and 273.15K? 0.00°C (32.00°F)
6) What's the average speed here? 1002.02km/h
7) What's the wavelength of H2 in vacuum? 21.11cm
8) What's the frequency and wavelength of the high 'c' music note? 1.05kHz, 32.78cm
9) What's a radar's geometrical horizon (the distance it can see)? 10.79km
10) What's the time needed to fly non-stop around the Earth at Mach 1? 1.41days
11) What's the travel time of sun light to Earth? 8.32min
12) What's the sum of 1 byte + 1kB + 1GB...(and so on)? 1.001e+30
13) What's the sum of 1m + 1NM + 1ft? 1.85km
14) What's the population density on Earth (people per km² of land area)? 55.06/km²
15) How much land area would be available for each person on Earth? 1.82hm²
...
```


📁 File Structure
------------------
```
├📄CMakeLists.txt 
├📄examples.cpp 
├📄LICENSE 
├📄README.md
├📂SI
  ├📄all.h 
  ├📄constants.h 
  ├📄formulas.h
  ├📄internal.h 
  ├📄literals.h 
  ├📄print.h
  ├📄tests.h
  ├📄units.h
  ├📂data
    ├📄densities.h
    ├📄Earth.h
    ├📄ISO.h
    ├📄Jupiter.h
    ├📄Mars.h
    ├📄Mercury.h
    ├📄Moon.h 
    ├📄music.h
    ├📄Sun.h
    (21 files, 3 folders, 112K total)
```

❔ FAQ
-------
* **What is SI?** It's the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units).
* **Is SI-lib feature-complete?** Not yet, but the base work has been done. Please help if you find something's missing.

🤝 Contributing
---------------
* Contributions, suggestions, and improvements are welcome!
* Open an Issue if you encounter bugs or have feature ideas.
* Create a Pull Request if you'd like to improve something.


📜 License & Copyright
-----------------------
This open source project is licensed under the CC0-1.0 license. All trademarks are the property of their respective owners.
