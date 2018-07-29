#ifndef HEADER_argo_program_Description_hpp_INCLUDE_GUARD
#define HEADER_argo_program_Description_hpp_INCLUDE_GUARD

#include <string>

namespace argo { namespace program {

    struct Description
    {
        std::string brief;
        std::string extended;
        std::string usage;
    };

} }

#endif

