#ifndef HEADER_argo_handler_group_IGroup_hpp_INCLUDE_GUARD
#define HEADER_argo_handler_group_IGroup_hpp_INCLUDE_GUARD

#include "argo/Handlers.hpp"
#include "argo/handler/Option.hpp"

namespace argo { namespace handler { namespace group {

    //!Base class of group handlers
    class IGroup: public IHandler
    {
    public:
        explicit IGroup(const std::string &name): name_(name) {}

        virtual bool is_valid() const override
        {
            S(false);
            const auto res = std::all_of(RANGE(handlers_), [&](const handler::IHandler &handler){ return handler.is_valid(); });
            L("Group valid?");
            L(C(hash()));
            L(C(res));
            return res;
        }
        virtual std::string hash() const override
        {
            S(false);
            if (hash_.empty())
            {
                std::ostringstream os;
                for (const auto &handler: handlers_) os << "[" << handler.hash() << "]";
                hash_ = os.str();
                L("Constructing hash for plain group");
                L(C(hash_));
            }
            return hash_;
        }
        virtual bool is_satisfied(Context &context) const override
        {
            MSS_BEGIN(bool);
            MSS(std::any_of(RANGE(handlers_), [&](const handler::IHandler &handler){ return handler.is_satisfied(context); }));
            if (is_required())
            {
                MSS(!!nr_selected(),
                    {
                        std::ostringstream os;
                        os << "Group '" << name() << "' is required";
                        context.error(os.str());
                    });
            }
            MSS_END(); 
        }

        std::string name() const { return name_; }
        bool empty() const { return handlers_.empty(); }
        std::size_t size() const { return handlers_.size(); }
        bool add(const handler::IHandler &handler)
        {
            S(false);
            const bool res = handlers_.add(handler);
            L("Added handler to plain group");
            L(C(hash()));
            return res;
        }
        template<typename... Args>
        handler::Option &option(Args &&... args) { return static_cast<handler::Option &>(handlers_.put(handler::Option{std::forward<Args>(args)...})); }
        template<typename... Args>
        handler::Option &toggle(Args &&... args) { return option(std::forward<Args>(args)...).toggle(); }
        IGroup &help(const std::string &description) { help_ = description; return *this; }
        std::string help() const { return help_; }
        IGroup &required(const bool state = true) { is_required_ = state; return *this; }
        bool is_required() const { return is_required_; }
        const Handlers &handlers() const { return handlers_; }

        virtual std::string description() const = 0;

    protected:
        std::string name_;
        mutable std::string hash_;
        std::string help_;
        bool is_required_ = false;
        Handlers handlers_;
    };

} } }

#endif

