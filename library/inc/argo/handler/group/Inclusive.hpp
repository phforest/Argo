#ifndef HEADER_argo_handler_group_Inclusive_hpp_INCLUDE_GUARD
#define HEADER_argo_handler_group_Inclusive_hpp_INCLUDE_GUARD

#include "argo/details/optional.hpp"
#include "argo/handler/Option.hpp"
#include "argo/handler/group/Exclusive.hpp"
#include "argo/handler/group/Plain.hpp"
#include "argo/utility.hpp"

namespace argo { namespace handler { namespace group {

    //!Inclusive groups: the presence of any one option/group within it, forces the presence of the others
    class Inclusive: public IGroup
    {
    public:
        explicit Inclusive(const std::string &group_name): IGroup(group_name) {}

        virtual Ptr clone() const override
        {
            auto ptr = details::make_unique<Inclusive>(name_);
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
        virtual bool is_satisfied(Context &context) const override
        {
            MSS_BEGIN(bool);
            S(false);
            L("Satisfied?");
            L(C(name()));
            std::ostringstream os;
            if (0 == nr_selected()) MSS_RETURN_OK();
            for (const auto &handler: handlers_)
            {
                if (is_type<handler::Option>(handler))
                {
                    const auto &option = static_cast<const handler::Option &>(handler);
                    if (1 == option.nr_selected()) continue;
                    os << "Missing option '" << option << "'";
                    context.error(os.str());
                    MSS_RETURN_ERROR();
                }
                else if (is_type<handler::group::Plain>(handler))
                {
                    const auto &group = static_cast<const handler::group::Plain &>(handler);
                    if (group.size() == group.nr_selected()) continue;
                    os << "Missing an option from group '" << group.name() << "'";
                    context.error(os.str());
                    MSS_RETURN_ERROR();
                }
                else if (is_type<handler::group::Exclusive>(handler))
                {
                    const auto &group = static_cast<const handler::group::Exclusive &>(handler);
                    if (1 == group.nr_selected()) continue;
                    L(C(group.nr_selected()));
                    os << "Missing an option from group '" << group.name() << "'";
                    context.error(os.str());
                    MSS_RETURN_ERROR();
                }
                else if (is_type<handler::group::Inclusive>(handler))
                {
                    const auto &inclusive = static_cast<const handler::group::Inclusive &>(handler);
                    MSS(inclusive.is_satisfied(context));
                }
            }
            MSS_END();
        }
        virtual std::string description() const override { return "mutually inclusive"; }
    };

} } }

#endif


