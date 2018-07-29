#ifndef HEADER_argo_Configuration_hpp_INCLUDE_GUARD
#define HEADER_argo_Configuration_hpp_INCLUDE_GUARD

#include "argo/program/Info.hpp"

namespace argo {

    struct Configuration
    {
        program::Info program{};
        bool add_help = true;
        bool add_version = true;
    };

}

#endif

