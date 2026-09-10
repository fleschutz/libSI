libSI's CMake Support
=====================


Using `FetchContent` (option #1)
--------------------------------
Pull it at configure time — no vendored copy in your tree:

```cmake
include(FetchContent)
FetchContent_Declare(libSI
  GIT_REPOSITORY https://github.com/fleschutz/libSI.git
  GIT_TAG        v0.4)            # pin a release tag
FetchContent_MakeAvailable(libSI)

target_link_libraries(myapp PRIVATE libSI::libSI)
```


Using `add_subdirectory` (option #2)
------------------------------------
Vendor the project (a submodule or a copy) and add it:

```cmake
add_subdirectory(libSI)
target_link_libraries(myapp PRIVATE libSI::libSI)
```

Linking the target propagates the include directory, so you do not set either yourself.


Using `find_package` (option #3)
--------------------------------

If `libSI` is installed (via `cmake --install`, or a Linux package), consume it with `find_package`:

```cmake
find_package(libSI CONFIG REQUIRED)
target_link_libraries(myapp PRIVATE libSI::libSI)
```


Copy the headers (option #4, no CMake)
---------------------------------------
Put `include/` on your compiler's include path and build with C++23 (`-std=c++23` on GCC and Clang,
`/std:c++latest` on MSVC). Nothing else is required.

