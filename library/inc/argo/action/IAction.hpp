#ifndef HEADER_argo_action_IAction_hpp_INCLUDE_GUARD
#define HEADER_argo_action_IAction_hpp_INCLUDE_GUARD

#include "argo/details/memory.hpp"
#include <string>

namespace argo {

    class Context;

}

namespace argo { namespace action {

    class IAction;
    using Ptr = std::unique_ptr<IAction>;

    class IAction
    {
    public:
        virtual ~IAction() = default;
        virtual Ptr clone() const = 0;
        virtual bool apply(Context &, const std::string &) = 0;
    };

} }

#endif

