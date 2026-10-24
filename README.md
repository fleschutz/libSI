📐libSI - The Physical Units Library For C++
=============================================
[![CMake on multiple platforms](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml)

Apply math with libSI in C++ correct, precise, and convenient. Features are: 

- **Strong type-safety** for datatypes, constants, formulas, and literals (can't add a mass to a length).
- **Precision** by 64-bit FP datatypes, calculations on SI base units, and CODATA 2022 constants.
- **Maximum speed** without runtime overhead. It just compiles to simple doubles.
- **Supports** SI units, Imperial/US units, digital units, astronomical units, and a lot more.
- **Supports** implicit scale conversion when mixing different units, e.g. 1_km + 1_m + 1_ft + 1_in.
- **Modern C++ 17:** header-only, own namespace, no external dependencies.
- **Cross-platform** support for Linux (clang/gcc, x86/arm) and Windows (VS2017-VS2026) with [CMake support](docs/CMake_support.md).

🔎 Example
-----------
```cpp
#include <SI/core>
using namespace SI;

int main() {	
    mass m   = 1_oz;
    energy E = m * square(constant::speed_of_light_in_vacuum);
    std::cout << "The potential energy of a single ounce is: " << E << std::endl;
}
```

| 🧱 Building Blocks   | Example                                   | File to Include                        |
| --------------------- | ----------------------------------------- | -------------------------------------- |
| Datatypes             | *SI::mass*                                | [<SI/datatypes.h>](SI/datatypes.h)     |
| Units                 | *SI::ounces*                              | [<SI/units.h>](SI/units.h)             |
| User-defined literals | *1_oz*                                    | [<SI/literals.h>](SI/literals.h)       |
| Constants             | *SI::constant::speed_of_light_in_vacuum*  | [<SI/constants.h>](SI/constants.h)     |
| Formulas              | *SI::formula::wavelength()*               | [<SI/formulas.h>](SI/formulas.h)       |
| Conversions           | *SI::to_string()*                         | [<SI/conversions.h>](SI/conversions.h) |


📦 Components
--------------
- **Examples** in the 📂[examples](examples/) subfolder, writing this to the: [console output](docs/console_output.txt)
- **Unit tests** in [<SI/tests.h>](SI/tests.h), executed at compile-time and on each commit by [GitHub Actions](https://github.com/fleschutz/libSI/actions)
- **Datasets**  in the 📂[datasets](datasets/) subfolder, e.g. *chemical_elements*.
- **Documentation** in the [reference manual](https://fleschutz.github.io/libSI/docs/html/)


💡 Q & A
---------
**What is SI?** It's the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units) which is made up of 7 base units that define the 22 derived units.

**What is CODATA?** It's the [Committee On Data](https://codata.org/) of the International Science Council (ISC). It publishes fundamental physical constants on a four-year cycle. Latest update was CODATA 2022 which is equal to: NIST SP 961 (May 2024).

**What are use-cases for libSI?** Applied math such as simulations, simulators, scientific calculations, games, etc.

**What are numbers like 1.2e23?** It's the scientific notation in C/C++ for 1.2 x 10²³, the letter 'e' or 'E' represents the 'times 10 to the power of' part.

**Which #include to use?** Use the convenient *#include <SI/core>* to include the 6 core header files, <SI/all> to include all, otherwise pick the necessary header files.

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
