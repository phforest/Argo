#ifndef HEADER_argo_action_Print_hpp_INCLUDE_GUARD
#define HEADER_argo_action_Print_hpp_INCLUDE_GUARD

#include "argo/Context.hpp"
#include "argo/action/IAction.hpp"
#include "argo/details/mss.hpp"
#include <iostream>

namespace argo { namespace action {

    class Print: public IAction
    {
    public:
        explicit Print(std::ostream &os = std::cout): os_(os) {}

        virtual Ptr clone() const override { return details::make_unique<Print>(os_); }
        virtual bool apply(Context &context, const std::string &value) override
        {
            MSS_BEGIN(bool);
            os_ << context.option() << ": " << value << std::endl;
            MSS_END();
        }

    private:
        std::ostream &os_;
    };

    template<typename... Args>
    Print print(Args &&... args) { return Print{std::forward<Args>(args)...}; }

} }

#endif

