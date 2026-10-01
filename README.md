libSI - The Physical Units Library For C++
==========================================
[![CMake on multiple platforms](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml)

Apply math with this C++ physical units library correct, precise, and convenient. Features are: 

- **Strong type-safety** for datatypes, constants, formulas, and literals (can't add a mass to a length).
- **High precision** with 64-bit floating points containing SI base units and providing CODATA 2022 constants.
- **Maximum speed** without runtime overhead. It just compiles to simple doubles.
- **Supports** SI units, Imperial units, astronomical units, digital units, and a lot more.
- **Modern C++ 17:** header-only, own namespace, no external dependencies.
- **Cross-platform** support for Linux (clang/gcc, x86/arm) and Windows (VS2017-VS2026) with [CMake support](doc/CMake_support.md).

🔎 Usage Example
----------------
```cpp
#include <SI/core.h>
using namespace SI;

int main() {	
    mass m    = 1_oz;
    energy E  = m * square(constant::speed_of_light_in_vacuum);
    std::cout << "The potential energy of a single ounce is: " << E << std::endl;
}
```

🧱 Core Building Blocks
------------------------
- **Datatypes** in [SI/datatypes.h](SI/datatypes.h), e.g. *SI::length*
- **Units** in [SI/units.h](SI/units.h), e.g. *SI::meters*
- **Literals** in [SI/literals.h](SI/literals.h), e.g. *100_m*
- **Constants** in [SI/constants.h](SI/constants.h), e.g. *SI::constant::speed_of_light_in_vacuum*
- **Formulas** in [SI/formulas.h](SI/formulas.h), e.g. *SI::formula::wavelength()*
- **Conversions** in [SI/conversions.h](SI/conversions.h), e.g. *SI::to_string()*


🎁 Additional Components
-------------------------
- **47 Examples** in 📂[examples](examples/), writing this to the console: [console output](examples/console_output.txt)
- **13 Datasets** based on SI units in 📂[SI/datasets](SI/datasets/), e.g. *dataset::chemical_elements*
- **210 Unit tests** performed at compile-time in [SI/tests.h](SI/tests.h) and on each commit by [GitHub Actions](https://github.com/fleschutz/libSI/actions)


💡 Q & A
---------
**What is SI?** It's the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units) which is made up of 7 base units that define the 22 derived units.

**What is CODATA?** It's the [Committee On Data](https://codata.org/) of the International Science Council (ISC). It publishes fundamental physical constants on a four-year cycle. Latest update was CODATA 2022 which is equal to: NIST SP 961 (May 2024).

**What are use-cases for libSI?** Applied math such as simulations, simulators, scientific calculations, games, etc.

**What are numbers like 1.2e23?** It's the scientific notation in C/C++ for 1.2 x 10²³, the letter 'e' or 'E' represents the 'times 10 to the power of' part.

**How to import or export numbers and string?** See the code examples in [examples/conversions.cpp](examples/conversions.cpp).

**Where are the list of references?** References are always listed at the end of each source code file.


🤝 Contributing
---------------
* Contributions, suggestions, and improvements are welcome!
* Open an [Issue](https://github.com/fleschutz/libSI/issues) if you encounter bugs or have feature ideas.
* Create a [Pull Request](https://github.com/fleschutz/libSI/pulls) if you'd like to improve something.


📜 License & Copyright
-----------------------
This open source project is licensed under the CC0-1.0 license. All trademarks are the property of their respective owners.
