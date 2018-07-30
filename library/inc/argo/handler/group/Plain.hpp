#ifndef HEADER_argo_handler_group_Plain_hpp_INCLUDE_GUARD
#define HEADER_argo_handler_group_Plain_hpp_INCLUDE_GUARD

#include "argo/handler/group/IGroup.hpp"

namespace argo { namespace handler { namespace group {

    //!Group that merely serves as a collection of options, with no additional properties
    class Plain: public IGroup
    {
    public:
        explicit Plain(const std::string &group_name): IGroup(group_name) {}

        virtual Ptr clone() const override
        {
            auto ptr = details::make_unique<Plain>(name_);
            ptr->nr_selected_ = nr_selected_;
            ptr->hash_ = hash_;
            ptr->help_ = help_;
            ptr->is_required_ = is_required_;
            ptr->handlers_ = handlers_;
#if ARGO_TOOLSET_COMPILER_GCC_OLD
            return std::move(ptr);
#else
            return ptr;
#endif
        }
        virtual bool recognizes(Context &context, const std::string &raw_arg) override { return std::any_of(RANGE(handlers_), [&](handler::IHandler &handler){ return handler.can_handle(context, raw_arg); }); }
        virtual std::string description() const override { return ""; }
    };

} } }

#endif

