#ifndef HEADER_argo_handler_Option_hpp_INCLUDE_GUARD
#define HEADER_argo_handler_Option_hpp_INCLUDE_GUARD

#include "argo/Context.hpp"
#include "argo/Name.hpp"
#include "argo/action/IAction.hpp"
#include "argo/details/log.hpp"
#include "argo/handler/IHandler.hpp"
#include "argo/nargs/FixedNumber.hpp"
#include "argo/nargs/INArgs.hpp"
#include "argo/nargs/OneOrMore.hpp"
#include "argo/nargs/Optional.hpp"
#include "argo/nargs/ZeroOrMore.hpp"

namespace argo { namespace handler {

    //!Options are the final handlers of arguments
    class Option: public IHandler
    {
    public:
        explicit Option(const std::string &shorthand, const std::string &longhand) { is_valid_ = name_.shorthand(shorthand) && name_.longhand(longhand); }
        explicit Option(const std::string &short_or_longhand)
        {
            assert(short_or_longhand.size() >= 2);
            const auto first_char = short_or_longhand[0];
            const auto second_char = short_or_longhand[1];
            is_valid_ = (first_char == second_char) ? name_.longhand(short_or_longhand) : name_.shorthand(short_or_longhand);
            assert(!!is_valid_);
        }

        Name name() const { return name_; }
        const std::vector<action::Ptr> &actions() const { return actions_; }
        Option &action(const action::IAction &action) { actions_.push_back(action.clone()); return self_(true); }
        Option &nargs(nargs::Ptr &&ptr) { pnargs_ = std::move(ptr); return self_(true); }
        Option &nargs(const unsigned int count)
        {
            pnargs_ = details::make_unique<nargs::FixedNumber>(count);
            if (0 == count) is_toggle_ = true;
            return self_(true);
        }
        Option &nargs(const std::string &type)
        {
            S(false);
            const bool is_ok = true;
            if ("+" == type) pnargs_ = details::make_unique<nargs::OneOrMore>();
            else if ("*" == type) pnargs_ = details::make_unique<nargs::ZeroOrMore>();
            else if ("?" == type) pnargs_ = details::make_unique<nargs::Optional>();
            if (!!pnargs_) L(nargs().description());
            return self_(is_ok);
        }
        const nargs::INargs &nargs() const
        {
            S(false);
            if (!pnargs_)
            {
                L("Setting default nargs");
                pnargs_ = details::make_unique<nargs::FixedNumber>(1);
            }
            return *pnargs_;
        }
        nargs::INargs &nargs()
        {
            const auto &self = *this;
            return const_cast<nargs::INargs &>(self.nargs());
        }
        Option &toggle(const bool state = true)
        {
            is_toggle_ = state;
            if (state) return nargs(0);
            else return self_(true);
        }
        std::string help() const { return help_; }
        Option &help(const std::string &description) { help_ = description; return self_(true); }
        Option &required(const bool state = true) { is_required_ = state; return self_(true); }
        bool is_required() const { return is_required_; }

        virtual Ptr clone() const override
        {
            auto ptr = details::make_unique<Option>("", "");
            ptr->nr_selected_ = nr_selected_;
            ptr->is_valid_ = is_valid_;
            ptr->name_ = name_;
            for (const auto &paction: actions_)
            {
                assert(!!paction);
                ptr->actions_.push_back(paction->clone());
            }
            ptr->pnargs_ = pnargs_ ? pnargs_->clone() : nullptr;
            ptr->is_toggle_ = is_toggle_;
            ptr->help_ = help_;
            ptr->is_required_ = is_required_;
            return std::move(ptr);
        }
        virtual bool is_valid() const override
        {
            //L("Option valid?");
            //L(C(name()));
            //L(C(is_valid_));
            return is_valid_;
        }
        std::string hash() const override { return name_.hash(); }
        virtual bool recognizes(Context &context, const std::string &raw_arg) override
        {
            S(false);
            bool can_handle = false;
            if (!!name().shorthand() && *name().shorthand() == raw_arg) can_handle = true;
            else if (!!name().longhand())
            {
                if (*name().longhand() == raw_arg) can_handle = true;
                else if (context.is_guessing_allowed() && Name::guess_shorthand(*name().longhand()) == raw_arg) can_handle = true;
            }
            if (can_handle) context.set_option(*this);
            L("Option recognizes?");
            L(C(name()));
            L(C(can_handle));
            return can_handle;
        }
        virtual bool is_satisfied(Context &context) const override
        {
            MSS_BEGIN(bool);
            if (is_required())
            {
                MSS(!!nr_selected(),
                    {
                        std::ostringstream os;
                        os << "Option '" << name() << "' is required";
                        context.error(os.str());
                    });
            }
            MSS_END();
        }

        bool process(Context &context, RawList::iterator &current, RawList::iterator end)
        {
            MSS_BEGIN(bool);
            S(false);
            L("Processing argument");
            L(C(*current));
            ++current;
            while (true)
            {
                if (is_toggle_)
                {
                    L("Option is a toggle");
                    auto previous = current;
                    --previous;
                    MSS(action_apply_(context, *previous));
                    MSS_RETURN_OK();
                }
                else
                {
                    L("Checking if there must be a next value");
                    L(C(nargs().description()));
                    if (nargs().must_have_next())
                    {
                        L("Yes, there must be");
                        if (current == end)
                        {
                            L("But we reached the end!");
                            std::ostringstream os;
                            os << "Option '" << context.option().name() << "' expects " << context.option().nargs().description();
                            context.error(os.str());
                            MSS_RETURN_ERROR();
                        }
                        L("Let's apply the action");
                        MSS(action_apply_(context, current));
                    }
                    else if (nargs().may_have_next())
                    {
                        L("A next value is not mandatory, but allowed");
                        if (current == end)
                        {
                            L("But we reached the end!");
                            MSS_RETURN_OK();
                        }
                        if (Name::is_valid(*current)) MSS_RETURN_OK();
                        MSS(action_apply_(context, current));
                    }
                    else
                    {
                        L("A next value is not allowed");
                        MSS_RETURN_OK();
                    }
                }
            }
            L("Finished handling argument");
            MSS_END();
        }

    private:
        Option &self_(const bool is_valid)
        {
            is_valid_ = is_valid;
            return *this;
        }
        bool action_apply_(Context &context, const std::string &arg)
        {
            MSS_BEGIN(bool);
            S(false);
            L("Applying actions on argument");
            L(C(arg));
            for (const auto &paction: actions_)
            {
                MSS(paction->apply(context, arg));
            }
            ++context.result().nr_args;
            nargs().next();
            MSS_END();
        }
        bool action_apply_(Context &context, RawList::iterator &current)
        {
            MSS_BEGIN(bool);
            MSS(action_apply_(context, *current));
            ++current;
            MSS_END();
        }

        bool is_valid_ = true;
        Name name_;
        std::vector<action::Ptr> actions_;
        mutable nargs::Ptr pnargs_ = nullptr;
        bool is_toggle_ = false;
        std::string help_;
        bool is_required_ = false;
    };

    inline std::ostream &operator<<(std::ostream &os, const Option &option) { return option.name().print(os); }

} }

#endif

