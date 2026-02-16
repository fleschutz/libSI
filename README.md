[![CMake on multiple platforms](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml)

Type-safe SI Library in C++
===========================

This lib helps to apply math with physical units correct, with high precision, and as easy as possible. It provides:

- [x] **Strong type-safety** for datatypes, constants, formulas, and literals (can't add a mass to a length).
- [x] **High precision** based on floating point 64-bit and **no runtime overhead** (just compiles to simple doubles).
- [x] **Supports** SI units, Imperial units, Astronomical units, and many more.
- [x] **Convenient** literals (e.g. 24_h or 3_GWh), conversions, and I/O functions.
- [x] **Modern C++ 17 lib**: header only, no dependencies, own namespace SI::, with [unit tests](SI/tests.h).
- [x] **Cross-platform** support for Linux (clang/gcc, x86/arm) and Windows (VS2017-VS2026).

🧱 Building Blocks
------------------
1. **Datatypes** such as SI::length or SI::time in [<datatypes.h>](SI/datatypes.h).
2. **Units** such as SI::meters or SI::seconds in [<units.h>](SI/units.h).
3. **Literals** such as 100_m or 60_sec in [<literals.h>](SI/literals.h).
4. **Constants** such as SI::constant::speed_of_light in [<constants.h>](SI/constants.h).
5. **Formulas** such as SI::formula::wavelength() in [<formulas.h>](SI/formulas.h).
6. **Datasets** such as chemical elements, planets, moons, exoplanets in 📂[datasets](datasets/).

🔎 Example Code
----------------
```cpp
#include <SI/all.h>
using namespace SI;

int main() {	
	print("What's the potential energy of just 1g mass? ");
	mass m = 1_g;
	velocity c = constant::speed_of_light;
	energy E = m * c*c;
	print(E);
...
```
See [examples.cpp](examples.cpp) with 43 examples in total. Executing: `cmake . && make && ./examples` generates this output:

```
 1. What's the potential energy of just 1g mass? 89.88TJ
 2. What was the average speed of Kelvin Kiptum's world record in Marathon? 21.00km/h
 3. What's the free fall time from the Burj Khalifa tower in Dubai? 12.99s
 4. What's the fuel efficiency of a car driving 400 miles and consuming 15 US gallons? 10.59l per 100km
 5. What's the kinetic energy of a mid-size SUV at 30MPH? 566.55kJ
 6. What's the local gravity at Mount Everest's peak? 9.76m/s²
...
```

❔ FAQ
-------
* **What is SI?** It's the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units).
* **What are typical use-cases for libSI?** Simulators, games and complex math & physics in general.
* **Where are the list of references?** References are listed at the end of each source code file.
* **What are numbers like 1.2e23?** It's the scientific notation in C/C++ for: 1.2 x 10²³ (the letter 'e' or 'E' represents the 'times 10 to the power of' part). 
* **Where are libSI's files and folders?** Here is the project structure:
```
├📄CMakeLists.txt 
├📄examples.cpp 
├📄LICENSE 
├📄README.md
├📂SI
|  ├📄all.h 
|  ├📄constants.h
|  ├📄conversion.h
|  ├📄datatypes.h 
|  ├📄formulas.h
|  ├📄internal.h 
|  ├📄IO.h
|  ├📄literals.h 
|  ├📄tests.h
|  ├📄units.h
├📂datasets
   ├📄all.h
   ├📄chemical_elements.h 
   ├📄exoplanets.h
   ├📄ISO_standards.h 
   ├📄planets.h
   ├📄satellites.h
   ...
   (59 files, 3 folders, 19MB total)
```

🤝 Contributing
---------------
* Contributions, suggestions, and improvements are welcome!
* Open an Issue if you encounter bugs or have feature ideas.
* Create a Pull Request if you'd like to improve something.


📜 License & Copyright
-----------------------
This open source project is licensed under the CC0-1.0 license. All trademarks are the property of their respective owners.
