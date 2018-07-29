#ifndef HEADER_argo_test_utility_hpp_INCLUDE_GUARD
#define HEADER_argo_test_utility_hpp_INCLUDE_GUARD

#include "argo/test/reflection.hpp"
#include <string>

namespace argo { namespace test {

    inline std::string data_file(const std::string &name, const std::string &ext, const bool platform_dependent = true)
    {
        std::string fn(argo::test::data_dir);
        fn += "/test_" + name;
        if (platform_dependent)
        {
#if ARGO_TOOLSET_PLATFORM_POSIX
            fn += "_posix";
#elif ARGO_TOOLSET_PLATFORM_WINDOWS
            fn += "_windows";
#endif
        }
        fn += ext;
        return fn;
    }

} }

#endif
