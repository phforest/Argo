#ifndef HEADER_argo_program_Info_hpp_INCLUDE_GUARD
#define HEADER_argo_program_Info_hpp_INCLUDE_GUARD

#include "argo/program/Description.hpp"
#include "argo/program/Name.hpp"
#include "argo/program/Version.hpp"

namespace argo { namespace program {

    struct Info
    {
        Name name;
        Description description;
        Version version;
    };

} }

#endif

