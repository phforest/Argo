#ifndef HEADER_argo_utility_hpp_INCLUDE_GUARD
#define HEADER_argo_utility_hpp_INCLUDE_GUARD

#include "argo/Context.hpp"
#include "argo/details/config/toolset.hpp"
#include "argo/details/optional.hpp"
#include "argo/handler/Option.hpp"
#include "argo/handler/group/IGroup.hpp"
#include "argo/program/Info.hpp"
#include <algorithm>
#include <sstream>

namespace argo {

    template<typename Type, typename ConversionTraits>
    details::optional<Type> convert(Context &context, const std::string &value)
    {
        const details::optional<Type> res = ConversionTraits::run(value);
        if (!!res) return res;
        std::ostringstream os;
        os << "Option '" << context.option() << "' expects " << ConversionTraits::description << " (not '" << value << "')";
        context.error(os.str());
        return details::nullopt;
    }
    inline bool has_version(const program::Info &program) { return 0 != program.version.major + program.version.minor + program.version.patch; }
    inline unsigned int max_option_length(const std::vector<handler::Option *> &options)
    {
        unsigned int max = 0u;
        for (const auto &poption: options)
        {
            assert(!!poption);
            max = std::max<unsigned>(max, poption->name().str().size());
        }
        return max;
    }
    template<typename Handler>
    bool is_type(const handler::IHandler &handler)
    {
        const auto pb = &handler;
        return !!dynamic_cast<const Handler *>(pb);
    }
    inline std::string basename_of(const std::string &path)
    {
        return std::string(std::find_if(path.rbegin(), path.rend(), [](const char ch)
                    {
#if ARGO_TOOLSET_PLATFORM_WINDOWS
                    return '/' == ch || '\\' == ch;
#else
                    return '/' == ch;
#endif
                    }).base(), path.end());
    }

}

#endif

