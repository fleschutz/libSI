#
# Platform-independent CMakefile to build SI lib
# -----------------------------------------------

cmake_minimum_required(VERSION 3.10)

project(main)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main main.cpp)

install(TARGETS main DESTINATION . )

