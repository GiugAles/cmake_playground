cmake_minimum_required(VERSION 3.0)
project(Foo)

add_library(Foo 
  src/Foo.cpp
)

## The `EXPORT` "This option associates the installed target files with an export called <export-name>. 
## It must appear before any target options. To actually install the export file itself, call install(EXPORT), "
## https://cmake.org/cmake/help/v3.16/command/install.html#installing-targets

install(TARGETS Foo EXPORT FooTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

## This one generates the FooConfigVersion.cmake

include(CMakePackageConfigHelpers)
write_basic_package_version_file("FooConfigVersion.cmake"
  VERSION 2.0
  COMPATIBILITY SameMajorVersion
)

## The `EXPORT` form generates and installs a CMake file containing code to import targets
## from the installation tree into another project.
## https://cmake.org/cmake/help/v3.16/command/install.html#installing-exports

install(EXPORT FooTargets
  FILE FooTargets.cmake
  NAMESPACE Foo::
  DESTINATION lib/cmake/Foo
)

install(FILES "cmake/FooConfig.cmake" "${CMAKE_BINARY_DIR}/FooConfigVersion.cmake"
  DESTINATION lib/cmake/Foo
)