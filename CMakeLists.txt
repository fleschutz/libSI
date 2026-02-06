# Cross-platform CMake Instructions To Build libSI
# ================================================

cmake_minimum_required(VERSION 3.10)

project(examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif(MSVC)

include_directories(.)

add_executable(examples examples.cpp)

# add unit tests
enable_testing()
add_test(NAME examples COMMAND examples)

install(TARGETS examples DESTINATION . )

