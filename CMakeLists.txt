#
# Platform-independent CMakefile
# ------------------------------

cmake_minimum_required(VERSION 3.10)

project(examples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(examples examples.cpp)

enable_testing()
add_test(NAME examples COMMAND examples)

install(TARGETS examples DESTINATION . )

