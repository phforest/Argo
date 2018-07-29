#ifndef HEADER_argo_Context_hpp_INCLUDE_GUARD
#define HEADER_argo_Context_hpp_INCLUDE_GUARD

#include "argo/Configuration.hpp"
#include "argo/Result.hpp"
#include <cassert>
#include <functional>
#include <ostream>
#include <vector>

namespace argo {

    class Handlers;

    namespace handler {

        class IHandler;
        class Option;
        
        namespace group {

            class IGroup;
        
        }

    }

    namespace formatter {

        class IFormatter;
    
    }

}

namespace argo {

    namespace details {
    
        template<typename T>
        bool pass_through(const T &) { return true; }
    
    }

    class Context
    {
    public:
        using OptionFilter = std::function<bool(const handler::Option &)>;
        using GroupFilter = std::function<bool(const handler::group::IGroup &)>;

        explicit Context(const Configuration &config): program_(config.program) {}

        const program::Info &program() const { return program_; }
        handler::Option &option() { assert(!!poption_); return *poption_; }
        void set_option(handler::Option &option) { poption_ = &option; }
        Result &result() { return result_; }
        formatter::IFormatter &formatter() { assert(!!pformatter_); return *pformatter_; }
        void set_formatter(formatter::IFormatter &formatter) { pformatter_ = &formatter; }
        const Handlers &handlers() const { assert(!!phandlers_); return *phandlers_; }
        void set_handlers(Handlers &handlers) { phandlers_ = &handlers; }
        std::vector<handler::Option *> options_all(const OptionFilter &filter = details::pass_through<handler::Option>) const;
        std::vector<handler::Option *> options_standalone(const OptionFilter &filter = details::pass_through<handler::Option>) const;
        std::vector<handler::group::IGroup *> groups_all(const GroupFilter &filter = details::pass_through<handler::group::IGroup>) const;
        std::vector<handler::group::IGroup *> groups_standalone(const GroupFilter &filter = details::pass_through<handler::group::IGroup>) const;
        void error() { result_.success = false; }
        void error(const std::string &message);
        void abort() { is_aborted_ = true; result_.requested_abort = true; }
        bool is_aborted() const { return is_aborted_; }
        void set_guessing_allowed(const bool state = true) { is_guessing_allowed_ = state; }
        bool is_guessing_allowed() const { return is_guessing_allowed_; }

    private:
        program::Info program_;
        Result result_;
        handler::Option *poption_ = nullptr;
        formatter::IFormatter *pformatter_ = nullptr;
        Handlers *phandlers_ = nullptr;
        bool is_aborted_ = false;
        bool is_guessing_allowed_ = false;
    };

}

#endif

