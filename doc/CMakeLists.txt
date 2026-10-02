cmake_minimum_required(VERSION 3.23)

# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

find_package(Doxygen)

if(NOT DOXYGEN_FOUND)
    message("Please install Doxygen to generate the doxygen documentation")
    return()
endif()

# set input and output files
set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${PROJECT_SOURCE_DIR}/../README.md")
set(DOXYGEN_PROJECT_LOGO "${PROJECT_SOURCE_DIR}/project_logo.jpg")

doxygen_add_docs(
  api_doc "${PROJECT_SOURCE_DIR}/../README.md" "${PROJECT_SOURCE_DIR}/../SI"
  WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/")
