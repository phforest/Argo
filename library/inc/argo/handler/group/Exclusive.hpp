#ifndef HEADER_argo_handler_group_Exclusive_hpp_INCLUDE_GUARD
#define HEADER_argo_handler_group_Exclusive_hpp_INCLUDE_GUARD

#include "argo/details/memory.hpp"
#include "argo/details/optional.hpp"
#include "argo/handler/Option.hpp"
#include "argo/handler/group/IGroup.hpp"
#include <string>

namespace argo { namespace handler { namespace group {

    //!Exclusive groups: the presence of any one option/group within it, excludes the presence of the others
    class Exclusive: public IGroup
    {
    public:
        explicit Exclusive(const std::string &group_name): IGroup(group_name) {}

        virtual Ptr clone() const override
        {
            auto ptr = details::make_unique<Exclusive>(name_);
            ptr->nr_selected_ = nr_selected_;
            ptr->hash_ = hash_;
            ptr->help_ = help_;
            ptr->is_required_ = is_required_;
            ptr->handlers_ = handlers_;
            ptr->previous_option_name_ = previous_option_name_;
#if ARGO_TOOLSET_COMPILER_GCC_OLD
            return std::move(ptr);
#else
            return ptr;
#endif
        }
        virtual bool recognizes(Context &context, const std::string &raw_arg) override 
        {
            MSS_BEGIN(bool);
            S(false);
            L("Recognizing?");
            L(C(raw_arg));
            L(C(name()));
            if (!std::any_of(RANGE(handlers_), [&](handler::IHandler &handler){ return handler.can_handle(context, raw_arg); })) MSS_RETURN_ERROR();
            if (!!previous_option_name_)
            {
                L("Yes, but this conflicts!");
                std::ostringstream os;
                os << "Previously used option '" << *previous_option_name_ << "' excludes use of '" << raw_arg << "'";
                context.error(os.str());
                MSS_RETURN_ERROR();
            }
            previous_option_name_ = context.option().name();
            MSS_END();
        }
        virtual std::string description() const override { return "mutually exclusive"; }

    private:
        details::optional<Name> previous_option_name_;
    };

} } }

#endif


