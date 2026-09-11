libSI - C++ Library of Type-safe SI Units
=========================================
[![CMake on multiple platforms](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml)

A units library to apply math with physical units correct, convenient and with high precision. 

- **Strong type-safety** for datatypes, constants, formulas, and literals (can't add a mass to a length).
- **High precision:** 64-bit floating point variables containing SI base units and CODATA 2022 constants.
- **Supports** SI units, Imperial units, astronomical units, various units, and convenient literals (e.g. 24_h).
- **No runtime overhead:** just compiles to simple doubles for maximum performance.
- **Modern C++ 17:** header-only, own namespace, no external dependencies.
- **Cross-platform** support for Linux (clang/gcc, x86/arm) and Windows (VS2017-VS2026) with [CMake support](SI/CMake_support.md).

🧱 Building Blocks
------------------
- **Datatypes** like *SI::length* in [SI/datatypes.h](SI/datatypes.h) (32 in total)
- **Units** such as *SI::meters* in [SI/units.h](SI/units.h) (105)
- **Literals** such as *100_m* in [SI/literals.h](SI/literals.h) (297)
- **Constants** such as *SI::constant::speed_of_light* in [SI/constants.h](SI/constants.h) (77)
- **Formulas** such as *SI::formula::wavelength()* in [SI/formulas.h](SI/formulas.h) (65)
- **Conversions** such as *SI::to_string()*  and *SI::to_equivalent()* in [SI/conversions.h](SI/conversions.h)
- **Unit tests** performed at compile-time in [SI/tests.h](SI/tests.h) and also performed on each commit by [GitHub Actions](https://github.com/fleschutz/libSI/actions) (207)
- **Datasets**, e.g. *dataset::chemical_elements* in 📂[datasets](datasets/) (optional, 12 in total)


🔎 Example
----------
```cpp
#include <SI/all.h>
using namespace SI;

int main() {	
    mass m = 1_oz;
    velocity c = constant::speed_of_light;
    energy E = m * c * c;
    println("The potential energy of a single ounce is: ", E);
}
```
Executing: `cd examples && cmake . && make && ./examples` writes to the console:
```
The potential energy of a single ounce is: 2.55PJ
```
**45 further examples** can be found in [examples.cpp](examples/examples.cpp) which writes this [output](examples/output.txt) to the console.


💡 Q & A
---------
**What is SI?** It's the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units) which is made up of 7 base units that define the 22 derived units.

**What is CODATA?** It's the [Committee On Data](https://codata.org/) of the International Science Council (ISC). It publishes fundamental physical constants on a four-year cycle. Latest update was CODATA 2022 which is equal to: NIST SP 961 (May 2024).

**What are use-cases for libSI?** Applied math such as simulations, simulators, astronomy/physics calculations, games, etc.

**What are numbers like 1.2e23?** It's the scientific notation in C/C++ for 1.2 x 10²³, the letter 'e' or 'E' represents the 'times 10 to the power of' part.

**How to import or export numbers and string?** See the examples in [conversions.cpp](examples/conversions.cpp).

**Where are the list of references?** References are always listed at the end of each source code file.


🤝 Contributing
---------------
* Contributions, suggestions, and improvements are welcome!
* Open an [Issue](https://github.com/fleschutz/libSI/issues) if you encounter bugs or have feature ideas.
* Create a [Pull Request](https://github.com/fleschutz/libSI/pulls) if you'd like to improve something.


📜 License & Copyright
-----------------------
This open source project is licensed under the CC0-1.0 license. All trademarks are the property of their respective owners.
