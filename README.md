📐libSI - The Physical Units Library For C++
=============================================
[![CMake on multiple platforms](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml)

Apply math with libSI in C++ correct, precise, and convenient. Top features are: 

- **Type-safety** for datatypes, constants, formulas, literals, etc. (e.g. mass + length = error).
- **Test-safety** by 200+ unit tests (executed at compile-time and on each commit by [GitHub Actions](https://github.com/fleschutz/libSI/actions)).
- **Precision** by 64-bit floating point, calculations on SI base units, and CODATA constants.
- **Full speed:** no runtime overhead and implicit compile-time conversions whenever possible.
- **Support** for SI/Imperial/US/digital/astronomical units, and a lot more.
- **Modern C++ 17:** header-only, own namespace, light-weight, no external dependencies.
- **Cross-platform** support for Linux (clang/gcc, x86/arm) and Windows (VS2017-VS2026) with [CMake support](docs/CMake_support.md).

🔎 Example
-----------
```cpp
#include <SI/core>

int main() { using namespace SI;
    mass m   = 1_kg;
    energy E = m * square(CODATA.c);
    std::cout << "The potential energy of a single kilogram is: " << E << std::endl;
}
```

🧱 Building Blocks
-------------------

| Component             | Example                                   | Location                               |
| --------------------- | ----------------------------------------- | -------------------------------------- |
| Namespace             | *SI*                                      | (for SI components)                    |
| Datatypes             | *mass*                                    | [<SI/datatypes.h>](SI/datatypes.h)     |
| Units                 | *kilograms*                               | [<SI/units.h>](SI/units.h)             |
| User-defined literals | *1_kg*                                    | [<SI/literals.h>](SI/literals.h)       |
| Constants             | *CODATA.c* (speed of light)               | [<SI/constants.h>](SI/constants.h)     |
| Formulas              | *kinetic_energy_formula()*                | [<SI/formulas.h>](SI/formulas.h)       |
| Conversions           | *to_equivalent()*                         | [<SI/conversions.h>](SI/conversions.h) |
| Unit tests            | *static_assert(1_kg == 1000_g);*          | [<SI/tests.h>](SI/tests.h)             | 
| Datasets              | *Earth.mass*                              | 📂[datasets](datasets/)                |
| Examples              | [console output](examples/console_output.txt) | 📂[examples](examples/)            |
| Documentation         |                                           | 📓 [reference manual](https://fleschutz.github.io/libSI/docs/html/) |


💡 Q & A
---------
**What's SI?** It's the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units) which is made up of 7 base units that define the 22 derived units.

**What's CODATA?** It's the [Committee On Data](https://codata.org/) of the International Science Council (ISC). It publishes fundamental physical constants on a four-year cycle - the latest update was CODATA 2022.

**What's IAU?** It's the [International Astronomical Union](https://www.iau.org/), which defines the astronomical units.

**What are use-cases of libSI?** Applied math such as simulations, simulators, scientific calculations, games, etc.

**What are numbers like 1.2e23?** It's the scientific notation in C/C++ for 1.2 x 10²³, the letter 'e' or 'E' represents the 'times 10 to the power of' part.

**Which #include to use?** Use the convenient *#include <SI/core>* to include the 6 core header files (datatypes.h, units.h, literals.h, constants.h, formulas.h, conversions.h), #include <SI/all> for all header files, otherwise pick the necessary ones only.

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
