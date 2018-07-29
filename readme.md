![logo](data/argo.png)

Argo is a single header C++11 library for argument parsing. It is light-weight, flexible, and easy-to-use.

## Features

Out-of-the-box support for:

* Long-hand and short-hand notation
* Required arguments
* Optional arguments
* Automatic short-hand generation and guessing of undefined short-hands
* Automatic generation of `--help`, `--version` options
* Grouping of options, including inclusive and exclusive groups
* Cardinality: fixed number, one or more, zero or more
* Beautiful output (__`man`__-style)

A basic example:

```
#include "argo/Argo.hpp"
#include <iostream>

using namespace argo;

void count(unsigned int max)
{
    for (unsigned int idx = 1u; idx <= max; ++idx) std::cout << idx << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    unsigned int max;
    
    argo::Arguments args;
    argo::handler::Option option{"--number"}.help("Numbers to count");
    option.required().action(argo::action::store(max));
    args.add(option);
    const auto result = args.parse(argc, argv);
    if (!result.success)
    {
        std::cerr << "Error: " << result.message << std::endl;
        return 1;
    }
    else
    {
        count(max);
    }
    return 0;
}
```

Results in the following interaction:

![logo](data/demo.gif)


## Integration

Since Argo consists of just a single header file without any external dependencies, no special building or installation steps are required. Simply make the header file available to your project.

### Option 1: Simple

For those wanting to start straight away: clone this repository (or if you're old school you can [download an archive](...) directly). Next, add the `argo/single_include` directory as an include directory to your compiler flags. That's it! You can now include Argo in your C++ projects:

```
#include "argo/Argo.hpp"
```

### Option 2: Integration in CMake

#### Using Git submodules

When adding the Argo repository as a Git submodule, it suffices to add the Argo repository as a subdirectory in your project:

```
add_subdirectory(argo)
```
This will create the target `Argo` as an `interface` library.

That's it! You can now link your targets against `Argo`. For example:

```
target_link_libraries(my-app PRIVATE Argo)
```

__Note__ If required, you can also build Argo as a static library by setting `ARGO_STATIC_LIB:BOOL=TRUE`. Aside from slightly reduced compilation times, there's no compelling reason in doing so. As such, the header-only approach is recommended.

#### Using ExternalProject_Add

Coming soon

