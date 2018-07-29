#ifndef HEADER_argo_formatter_IFormatter_hpp_INCLUDE_GUARD
#define HEADER_argo_formatter_IFormatter_hpp_INCLUDE_GUARD

#include "argo/details/memory.hpp"
#include "argo/details/string/Text.hpp"
#include <string>

namespace argo {

    class Context;

}

namespace argo { namespace formatter {

    //!Formatter interface. The convention is for all output to end with a newline, except for
    //format_error
    class IFormatter
    {
    public:
        explicit IFormatter() = default;
        virtual ~IFormatter() = default;

        virtual std::string format_error(Context &context, const std::string &message) = 0;
        virtual std::string format_help(Context &context) = 0;
        virtual std::string format_version(Context &context) = 0;

    protected:
        using Txt = details::string::Text;
    };

    using Ptr = std::unique_ptr<IFormatter>;

} }

#endif

