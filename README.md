[![CMake on multiple platforms](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml)

Type-safe SI Library in C++
===========================

This lib helps to apply math and physics correct, with high precision, and as easy as possible. It provides:

* **Strong type-safety** for SI datatypes, constants, formulas, and literals (can't add a mass to a length).
* **High precision** based on floating point 64-bit and **no runtime overhead** (compiles to nothing but simple doubles).
* **Convenient** literals (e.g. 24_h or 3_GWh), conversions, and I/O functions.
* **Supports** SI base units, derived SI units, Imperial units, and many more.
* **Modern C++ 17 lib**: header only, own namespace SI::, no external dependencies, with [unit tests](SI/tests.h).
* **Cross-platform** support for Linux (gcc & clang) and Windows (VS2017-VS2026).

🧱 Building Blocks
------------------
1. **Datatypes** such as SI::length or SI::time in [<SI/datatypes.h>](SI/datatypes.h).
2. **Units** such as SI::meters or SI::seconds in [<SI/units.h>](SI/units.h).
3. **Literals** such as 100_m or 60_sec in [<SI/literals.h>](SI/literals.h).
4. **Constants** such as SI::constant::speed_of_light in [<SI/constants.h>](SI/constants.h).
5. **Formulas** such as SI::formula::wavelength() in [<SI/formulas.h>](SI/formulas.h).
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
	energy E = m * c * c;
	print(E);
}
```
Please find a lot more examples in: [examples.cpp](examples.cpp). Executing: `cmake . && make && ./examples` generates this output:

```
 1. What's the potential energy of just 1g mass? 89.88TJ
 2. What was the average speed of Kelvin Kiptum's world record in Marathon? 21.00km/h
 3. What's the free fall time from Burj Khalifa tower in Dubai? 12.99s
 4. What's the kinetic energy of a car at 50 km/h? 125.39kJ
...
```

❔ FAQ
-------
* **What is SI?** It's the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units).
* **Why use libSI?** To avoid mistakes and for precision and convenience (see the constants, common formulas, literals, and datasets)
* **Where are the list of references?** References are listed at the end of each source code file.
* **What are numbers like 1.23e23?** This is the scientific notation in C/C++ for: 1.23 x 10²³ (the letter 'e' or 'E' represents the 'times 10 to the power of' part). 
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
