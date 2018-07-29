#ifndef HEADER_argo_program_Version_hpp_INCLUDE_GUARD
#define HEADER_argo_program_Version_hpp_INCLUDE_GUARD

#include <string>

namespace argo { namespace program {

    struct Version
    {
        unsigned major;
        unsigned minor;
        unsigned patch;
        std::string githash;
    };

} }

#endif

