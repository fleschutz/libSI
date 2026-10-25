📐libSI - The Physical Units Library For C++
=============================================
[![CMake on multiple platforms](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/fleschutz/Math/actions/workflows/cmake-multi-platform.yml)

Apply math with libSI in C++ correct, precise, and convenient. Top features are: 

- **Type-safety** for datatypes, constants, formulas, literals, etc. (e.g. mass + length = error).
- **Test-safety** by unit tests executed at compile-time and on each libSI's commit by [GitHub Actions](https://github.com/fleschutz/libSI/actions).
- **Precision** by 64-bit floating points, calculations on SI base units, and CODATA 2022 constants.
- **Full speed:** no runtime overhead and implicit compile-time conversions whenever possible.
- **Support** for SI/Imperial/US/digital/astronomical units, and a lot more.
- **Modern C++ 17:** header-only, own namespace, light-weight, no external dependencies.
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

🧱 Building Blocks
-------------------

| Component             | Example                                   | Location                               |
| --------------------- | ----------------------------------------- | -------------------------------------- |
| Datatypes             | *mass*                                    | [<SI/datatypes.h>](SI/datatypes.h)     |
| Units                 | *ounces*                                  | [<SI/units.h>](SI/units.h)             |
| User-defined literals | *1_oz*                                    | [<SI/literals.h>](SI/literals.h)       |
| Constants             | *constant::speed_of_light_in_vacuum*      | [<SI/constants.h>](SI/constants.h)     |
| Formulas              | *formula::wavelength()*                   | [<SI/formulas.h>](SI/formulas.h)       |
| Conversions           | *to_string()*                             | [<SI/conversions.h>](SI/conversions.h) |
| Unit tests            | *static_assert(1_km == 1000_m);*          | [<SI/tests.h>](SI/tests.h)             | 
| Datasets              | *Earth::surface_gravity*                  | 📂[datasets](datasets/) subfolder     |
| Examples              | [console output](examples/console_output.txt) | 📂[examples](examples/) subfolder     |
| Documentation         |                                           | 📓 [reference manual](https://fleschutz.github.io/libSI/docs/html/) |


💡 Q & A
---------
**What is SI?** It's the [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units) which is made up of 7 base units that define the 22 derived units.

**What is CODATA?** It's the [Committee On Data](https://codata.org/) of the International Science Council (ISC). It publishes fundamental physical constants on a four-year cycle. Latest update was CODATA 2022 which is equal to: NIST SP 961 (May 2024).

**What is IAU?** It's the [International Astronomical Union](https://www.iau.org/). It defines the astronomical units.

**What are use-cases for libSI?** Applied math such as simulations, simulators, scientific calculations, games, etc.

**What are numbers like 1.2e23?** It's the scientific notation in C/C++ for 1.2 x 10²³, the letter 'e' or 'E' represents the 'times 10 to the power of' part.

**Which #include to use?** Use the convenient *#include <SI/core>* for the 6 core header files, <SI/all> to include all header files, otherwise pick the necessary one only.

**How to import or export numbers and string?** See the code examples in [examples/conversions.cpp](examples/conversions.cpp).

**Why is there no datatype like meters or feets?** Those are units and the correct datatype is: length

**Where are the list of references?** References are always listed at the end of each source code file.


🤝 Contributing
---------------
* Contributions, suggestions, and improvements are welcome!
* Open an [Issue](https://github.com/fleschutz/libSI/issues) if you encounter bugs or have feature ideas.
* Create a [Pull Request](https://github.com/fleschutz/libSI/pulls) if you'd like to improve something.


📜 License & Copyright
-----------------------
This open source project is licensed under the CC0-1.0 license. All trademarks are the property of their respective owners.
