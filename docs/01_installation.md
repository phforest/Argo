# Installation

Argo consists of just a single header file without any external dependencies, __no building or installation is required__. Simply make the header file available to your project.

## Basic integration

Clone the repository:

```
git clone https://github.com/dgrine/Argo.git
```

Alternatively, you can [download the latest archive](...) directly.

Next, add the `Argo/single_include` directory as an include directory to your compiler flags when compiling. For example, with Clang or GCC simply add the `-I</path/to/Argo>/single_include` flag.

That's it! You can now include Argo in your C++ projects:

```C++
#include "argo/Argo.hpp"
```

## CMake integration

#### Using Git submodules

If your project makes use of Git submodules, you can simply add the Argo repository as a subdirectory in your `CMakeLists.txt`:

```CMake
add_subdirectory(argo)
```
This will create the target `Argo` as an `interface` library.

That's it! You can now link your targets against `Argo`:

```CMake
target_link_libraries(my-app PRIVATE Argo)
```

__Note__ If required, you can also build Argo as a static library by setting `ARGO_STATIC_LIB:BOOL=TRUE`. Aside from slightly reduced compilation times, there's no compelling reason in doing so. As such, the header-only approach is recommended.

#### Using ExternalProject_Add

The following shows integration via CMake's `ExternalProject_Add` command:

```CMake
cmake_minimum_required(VERSION 3.5)

project(App)

include(ExternalProject)
find_package(Git REQUIRED)
ExternalProject_Add(Argo
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/extern/argo
    GIT_REPOSITORY https://github.com/dgrine/Argo
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON)
ExternalProject_Get_Property(Argo SOURCE_DIR)
set(ARGO_ROOT ${SOURCE_DIR})

add_executable(app main.cpp)
add_dependencies(app Argo)
set_target_properties(app PROPERTIES CXX_STANDARD 11) #Your project should be C++ >= 11
target_include_directories(app PRIVATE ${ARGO_ROOT}/single_include)
```

## Requirements

A modern C++11 compliant compiler.

The library is tested on the following platforms:

* macOS 10.13 / Clang (Apple LLVM version 9.1.0)
* CentOS-7.5 / GCC-4.8.5
* Debian-8.11 / GCC-4.9.2
* Ubuntu-14.04 / GCC-4.8.4
* Ubuntu-16.04 / GCC-5.4.0
* Ubuntu-18.04 / GCC-7.3.0
* Ubuntu-18.10 / GCC-8.2.0

__Note__ Automatic testing on Windows will be added shortly.
