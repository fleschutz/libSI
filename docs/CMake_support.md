Using *si-lib* in Your Project with CMake
=========================================


Option 1: Using `FetchContent` 
--------------------------------
Pull it at configure time — no vendored copy in your tree:

```cmake
include(FetchContent)
FetchContent_Declare(si-lib
  GIT_REPOSITORY https://github.com/fleschutz/si-lib.git
  GIT_TAG        v0.6)            # pin a release tag
FetchContent_MakeAvailable(si-lib)

target_link_libraries(myapp PRIVATE si-lib::si-lib)
```


Option 2: Using `add_subdirectory`
----------------------------------
Vendor the project (a submodule or a copy) and add it:

```cmake
add_subdirectory(si-lib)
target_link_libraries(myapp PRIVATE si-lib::si-lib)
```

Linking the target propagates the include directory, so you do not set either yourself.


Option 3: Using `find_package`
------------------------------

If `si-lib` is installed (via `cmake --install`, or a Linux package), consume it with `find_package`:

```cmake
find_package(si-lib CONFIG REQUIRED)
target_link_libraries(myapp PRIVATE si-lib::si-lib)
```


Option 4: Copy the headers (no CMake)
--------------------------------------
Put `include/si/` on your compiler's include path and build with C++23 (`-std=c++23` on GCC and Clang,
`/std:c++latest` on MSVC). Nothing else is required.

