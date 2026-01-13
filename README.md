[![CMake on multiple platforms](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml)

Type-safe SI Library in C++
===========================

Apply math based on SI units correct, with high precision, and as easy as possible. This SI library provides the following features:

* **Type-safe** [units](SI/units.h) (can't add a mass to a length), [constants](SI/constants.h) (e.g. constant::sigma), and [formulas](SI/formulas.h) (e.g. formula::wavelength())
* **Convenient** [literals](SI/literals.h) (e.g. 24_h or 3_GWh), [from_string()](SI/from_string.h), [to_string()](SI/to_string.h), and [print()](SI/print.h) functions.
* **High precision** by using 'double' internally, **without runtime overhead** (compiles to nothing but simple doubles).
* **With data** in SI units: [stars](SI/data/stars.h), [planets](SI/data/planets.h), [moons](SI/data/moons.h), [materials](SI/data/materials.h), [ISO standards](SI/data/ISO.h), and [more...](SI/data/)
* **Supports** SI base units, derived SI units, Imperial units, and many more.
* **Wide compatibility** (just requires C++17 or higher) with **cross-platform** support (e.g. Linux gcc & clang, Windows VS2017-VS2026).
* **Modern C++ lib**: header only, compact, own namespace ("SI::"), no external dependencies, with [unit tests](SI/tests.h).

🔎 Code Example
---------------
```cpp
#include <SI/all.h>
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
Please find 34 more examples in: [examples.cpp](examples.cpp). Executing: `cmake . && make && ./examples` generates this output:

```
1. What's the potential energy of just 1g mass? 89.88TJ
2. What's the free fall time from Burj Khalifa tower in Dubai? 12.99sec
3. What's the average speed of Kiptum's world record in Marathon? 21.10km/h
4. What's the kinetic energy of a car at 50 km/h? 125.39kJ
5. What's the wavelength of hydrogen (H2) in vacuum? 21.11cm
6. What's the frequency and wavelength of the high 'c' music note? 1.05kHz, 32.78cm
7. What's the population density on Earth (people per km² of land area)? 55.06/km²
8. How much land area would be available for each person on Earth? 1.82hm²
9. How long takes a 1TB download at 100MBit speed? 22.22h
10. What's an aircraft's glide path on final at 10NM distance in 3000ft height? 2.83°
11. What's the min speed required to escape from the Moon? 8552.41km/h
12. What's the average speed to travel around the Earth in 80 days? 20.87km/h
...
```

🧱 The 8 Layers of libSI
-------------------------
1. **SI datatypes** such as SI::length, SI::mass or SI::time (-> [units.h](SI/units.h))
2. **Units** such as SI::meters, SI::kilograms or SI::seconds (-> [units.h](SI/units.h))
3. **Literals** such as 100_m, 50_kg or 60_sec (-> [literals.h](SI/literals.h))
4. **Constants** such as SI::constant::speed_of_light (-> [constants.h](SI/constants.h))
5. **Formulas** such as SI::formula::wavelength() (-> [formulas.h](SI/formulas.h))
6. **Import/export** with print(), from_string(), to_string() (-> [print.h](SI/print.h)
7. **Big data** such as SI::data::planets (-> [data/](SI/data/))
8. **Unit tests** at compile-time (-> [tests.h](SI/tests.h)

📁 Project Structure
--------------------
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
    ├📄ISO.h
    ├📄materials.h 
    ├📄moons.h 
    ├📄music.h
    ├📄planets.h
    ├📄stars.h
    (21 files, 3 folders, 112K total)
```

❔ FAQ
-------
* **What is SI?** It's the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units).
* **Is libSI feature-complete?** Not yet, but the base work has been done. Please help if you find something's missing.

🤝 Contributing
---------------
* Contributions, suggestions, and improvements are welcome!
* Open an Issue if you encounter bugs or have feature ideas.
* Create a Pull Request if you'd like to improve something.


📜 License & Copyright
-----------------------
This open source project is licensed under the CC0-1.0 license. All trademarks are the property of their respective owners.
