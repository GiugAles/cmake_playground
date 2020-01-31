
# INTRODUCTION

These are some notes extracted from to talks on CppCon2017 and BoostCon 2018. The purpose of these notes is to explain as short as possbile to the developer, what he or she has to do to provide an usable library. For more detailes information, please refer to the videos.

# CMAKE BASICS

 * CMake is no build system.
   - [Ropert2017] - 00:03:25
 * Not a build system!
   - [Pusz2018] - 00:06:45
 * CMake is a "cross-plattform C++ build generator"
   - [Ropert2017] - 00:03:25
   - [Pusz2018] - 00:06:45
 * CMake is code, hence treate it accordingly, e.g. DRY
   - [Pfeifer2017] - 00:03:30

---

The following are from [Pfeifer2017] [2] - 03:45 :

*CMake Directories*
 * Every directory, that contains CMakeLists.txt
 * Hence, directories added with add\_subdirectory() must also contain a CMakeLists.txt

*Scripts*
 * has extension .cmake
 * can be excuted with cmake -P
 * Not all commands are supported
 * HelloWorld
   * create a file and name it hello.cmake 
   * paste message("----- Hello World! Bests, CMake -----")
   * run with cmake -P hello.cmake

*Module*
 * scripts located in CMAKE\_MODULE\_PATH
 * can be loaded with _include()_

*Targets*
 * If you compare CMake usage to OOP ([Pfeifer2017] - 17:20) then
   * *Targets* compare to objects
   * *add\_executable()* and *add\_library()* compare to thier respective constructors
   * *properties* compare to thier respective member variables
   * and e.g. *target\_link\_library()* compate to member functions

---


# EXPORTING AND IMPORTING

## FIND AND CONFIG

*Find-Module:*
 * Use when 3rd-Party-Libraries do not support CMake

*Config-Module:*
 * Provided by developer of library

## KEYWORDS

e.g. for:

~~~cmake
 targe_link_library(<target>
   <PRIVAT|PUBLIC|INTERFACE> <item>
 )
~~~
we should use the following keywords:


|                          | NEEDED BY ME  | NOT NEEDED BY ME  |
| ------------------------ |:-------------:| :----------------:|
| NEEDED BY DEPENDENCY     | PUBLIC        | INTERFACE         |
| NOT NEEDED BY DEPENDENCY | PRIVATE       |   :-)             |
|- [Pusz2018] - 00:11:30                                       |
||

Alternative Explanation:

|                          | Keyword       |
| ------------------------ |:-------------:|
| Usage Requirement        | INTERFACE     |
| Build Requirement        | PRIVATE       |
| Build & Usage Requirement| PUBLIC        |
|- [Bahadir2018] - 00:08:40                |
||


---

# CMAKE APPLIED

In the following, some basic CMake concepts are applied to an upstream (provided) library 'Foo' and a downstream (consumed) app 'Bar'.

## UPSTREAM LIBRARY

### CMAKE STRUCTURE

This is an example for the structure of a CMakeLists.txt from [Pfeifer2017] - 43:06
~~~
toplevel
|
|-- CMakeLists.txt
    |-- add_library and correponding install
    |-- install
    |   |-- FooConfig.cmake
    |   |-- FooConfigVersion.cmake
    |   |-- FooTargets.cmake
    |-- include
    |   |-- CMakePackageConfigHelpers
            |-- generates FooTargets.cmake
~~~


*FooConfig.cmake* - manually written and installed

*FooTagets.cmake* 
 * generaed by cmake ([Pfeifer2017] - 40:25) with `install(EXPORT)`: _The `EXPORT` form generates and installs a CMake file containing code to import targets from the installation tree into another project."_ - [CMakeDocInstall]

### FOLDER STRUCTURE

~~~
|-- buil_helloCMake
└───helloCMake
    └───Foo
        ├───cmake
        └───src

~~~

### INVOKING
~~~
cmake ..\helloCMake\Foo\ -DCMAKE_INSTALL_PREFIX="install"
cmake --build . --target install
~~~

## DOWNSTREAM APP

YET TO COME

# REFERENCES

[Ropert2017]: https://www.youtube.com/watch?v=eC9-iRN2b04 "Using Modern CMake Patterns to Enforce a Good Modular Design"

[Pfeifer2017]: https://www.youtube.com/watch?v=bsXLMQ6WgIk "Effective CMake"

[Pusz2018]: https://www.youtube.com/watch?v=S4QSKLXdTtA "Git, CMake, Conan - How to ship and reuse our C++ projects"

[CMakeDocInstall]: https://cmake.org/cmake/help/v3.16/command/install.html "CMake Install"

[Bahadir2018]: https://www.youtube.com/watch?v=y7ndUhdQuU8 "More Modern CMake"
 
---

# NOT COVERED (YET)
* generator expressions
* macros and functions
* cpack
* ctest

---

# CONAN AND CMAKE
* 


---
