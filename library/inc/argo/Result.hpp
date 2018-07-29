#ifndef HEADER_argo_Result_hpp_INCLUDE_GUARD
#define HEADER_argo_Result_hpp_INCLUDE_GUARD

#include <ostream>
#include <string>

namespace argo {

    struct Result
    {
        bool success = true;
        bool requested_abort = false;
        std::string message;
        unsigned int nr_options = 0;
        unsigned int nr_args = 0;
    };

    inline std::ostream &operator<<(std::ostream &os, const Result &result)
    {
        os << "{\n";
        os << "  success: " << result.success << ",\n";
        os << "  message: \"" << result.message << "\",\n";
        os << "  nr_options: \"" << result.nr_options << "\",\n";
        os << "  nr_args: \"" << result.nr_args << "\"\n";
        os << "}";
        return os;
    }

}

#endif

