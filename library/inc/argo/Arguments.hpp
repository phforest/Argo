#ifndef HEADER_argo_Arguments_hpp_INCLUDE_GUARD
#define HEADER_argo_Arguments_hpp_INCLUDE_GUARD

#include "argo/Configuration.hpp"
#include "argo/Handlers.hpp"
#include "argo/Name.hpp"
#include "argo/RawList.hpp"
#include "argo/ResponseFile.hpp"
#include "argo/action/Callback.hpp"
#include "argo/details/mss.hpp"
#include "argo/details/raii.hpp"
#include "argo/formatter/Default.hpp"
#include "argo/handler/Option.hpp"
#include "argo/utility.hpp"

namespace argo {

    class Arguments
    {
    public:
        explicit Arguments(const Configuration &config = Configuration{}): config_(config) 
        {
            if (config_.add_help)
            {
                const auto is_ok = add_help_();
                assert(!!is_ok);
            }
            if (config_.add_version)
            {
                const auto is_ok = add_version_();
                assert(!!is_ok);
            }
        }

        bool add(const handler::IHandler &handler) { return handlers_.add(handler); }
        bool add(const Arguments &arguments, const bool replace = true)
        {
            MSS_BEGIN(bool);
            for (const auto &handler: arguments.handlers_)
            {
                if (!replace && handlers_.has(handler)) continue;
                handlers_.add(handler);
            }
            MSS_END();
        }
        template<typename... Args>
        handler::Option &option(Args &&... args) { return static_cast<handler::Option &>(handlers_.put(handler::Option{std::forward<Args>(args)...})); }
        template<typename... Args>
        handler::Option &toggle(Args &&... args) { return option(std::forward<Args>(args)...).toggle(); }
        void set_formatter(formatter::Ptr &&formatter) { pformatter_ = std::move(formatter); }
        bool is_valid() const { return std::all_of(RANGE(handlers_), [](const handler::IHandler &handler){ return handler.is_valid(); }); }
        Result parse(RawList raw_arguments, const bool skip_first_argument = false)
        {
            S(false);
            L("Checking if processing is possible");
            if (!is_valid())
            {
                L("Invalid configuration");
                context_().error("Invalid configuration");
                return context_().result();
            }
            L("Preparing processing...");
            if (skip_first_argument && !raw_arguments.empty())
            {
                L("Attempting to complete the configuration");
                complete_configuration_(raw_arguments[0]);
                RawList tmp(std::begin(raw_arguments) + 1, std::end(raw_arguments));
                std::swap(tmp, raw_arguments);
            }
            auto begin = std::begin(raw_arguments);
            auto end = std::end(raw_arguments);
            auto current = begin;
            L("Processing...");
            while (current != end)
            {
                L("Analyzing '" << *current << "'");
                if (details::string::starts_with(*current, "@"))
                {
                    ResponseFile rsp;
                    std::string fn_response = *current;
                    fn_response.erase(0, 1);
                    if (!rsp.parse(fn_response))
                    {
                        std::ostringstream os;
                        os << "Could not parse response file '" << fn_response << "'";
                        context_().error(os.str());
                        return context_().result();
                    }
                    else
                    {
                        L("Inserting " << rsp.argc() << " new arguments");
                        const auto &argv = rsp.argv();
                        RawList tmp(begin, current);
                        const auto idx = tmp.size();
                        std::copy(RANGE(argv), std::back_inserter(tmp));
                        ++current;
                        std::copy(current, end, std::back_inserter(tmp));
                        swap(raw_arguments, tmp);
                        begin = std::begin(raw_arguments);
                        end = std::end(raw_arguments);
                        current = begin + idx;
                    }
                }
                L("Finding handler for option '" << *current << "'");
                if (!find_handler_(context_(), *current))
                {
                    L("No handler found");
                    std::ostringstream os;
                    os << "Unknown option '" << *current << "'";
                    if (!Name::is_valid(*current) && details::string::starts_with(*current, "-"))
                    {
                        const std::string alternative = "-" + *current;
                        os << ": ";
                        if (find_handler_(context_(), alternative))
                        {
                            os << "did you mean '-" << *current << "'?";
                        }
                        else
                        {
                            os << "invalid shorthand or longhand notation";
                        }
                    }
                    context_().error(os.str());
                    return context_().result();
                }
                ++context_().result().nr_options;
                L("Processing option '" << *current << "'");
                if (!context_().option().process(context_(), current, end))
                {
                    context_().error();
                    return context_().result();
                }
                if (context_().is_aborted())
                {
                    L("Option aborted the process");
                    return context_().result();
                }
                if (current != end && !Name::is_valid(*current))
                {
                    std::ostringstream os;
                    if (current == begin)
                    {
                        os << "Invalid option '" << *current << "'";
                    }
                    else
                    {
                        os << "Option '" << context_().option() << "' expects " << context_().option().nargs().description() << ": unexpected '" << *current << "'";
                    }
                    L(os.str());
                    context_().error(os.str());
                    return context_().result();
                }
            }
            L("No more raw arguments to process");
            for (const auto &handler: handlers_)
            {
                L("Checking handler satisfaction");
                L(C(handler.hash()));
                if (!handler.is_satisfied(context_()))
                {
                    context_().error();
                    return context_().result();
                }
            }
            L("Done");
            return context_().result();
        }
        template<typename CharArrayType>
        Result parse(unsigned int argc, CharArrayType argv, const bool skip_first_argument = true)
        {
            RawList raw_args;
            std::copy(argv, argv + argc, std::back_inserter(raw_args));
            return parse(raw_args, skip_first_argument);
        }
        bool print_help(std::ostream &os)
        {
            MSS_BEGIN(bool);
            MSS(!!os);
            os << context_().formatter().format_help(context_());
            MSS_END();
        }
        bool print_version(std::ostream &os)
        {
            MSS_BEGIN(bool);
            MSS(!!os);
            os << context_().formatter().format_version(context_());
            MSS_END();
        }

    private:
        Context &context_()
        {
            if (!pcontext_) context_init_();
            return *pcontext_;
        }
        void context_init_()
        {
            pcontext_ = details::make_unique<Context>(config_);
            if (!pformatter_) pformatter_ = details::make_unique<formatter::Default>();
            assert(!!pformatter_);
            context_().set_formatter(*pformatter_);
            context_().set_handlers(handlers_);
        }
        bool find_handler_(Context &context, const std::string &raw_arg)
        {
            S(false);
            const auto reset = make_raii([&context](){ context.set_guessing_allowed(false); });
            auto lookup = [&]()
            {
                for (auto &handler: handlers_) if (handler.can_handle(context, raw_arg)) return true;
                return false;
            };
            if (lookup()) return true;
            else
            {
                L("Allowing guessing");
                context.set_guessing_allowed(true);
                return lookup();
            }
        }
        bool add_help_()
        {
            MSS_BEGIN(bool);
            handler::Option option{"-h", "--help"};
            auto print = [this](const std::string &value) { return this->print_help(std::cout); };
            option.action(action::callback(print));
            auto abort = [](Context &context) { context.abort(); return true; };
            option.action(action::callback(abort));
            option.help("Prints out the help.");
            option.nargs(0);
            MSS(add(option));
            MSS_END();
        }
        bool add_version_()
        {
            MSS_BEGIN(bool);
            handler::Option option{"-v", "--version"};
            auto version = [this](const std::string &value) { return this->print_version(std::cout); };
            option.action(action::callback(version));
            auto abort = [](Context &context) { context.abort(); return true; };
            option.action(action::callback(abort));
            option.help("Prints out the version information.");
            option.nargs(0);
            MSS(add(option));
            MSS_END();
        }
        void complete_configuration_(const std::string &program)
        {
            const auto name = basename_of(program);
            if (config_.program.name.brief.empty()) config_.program.name.brief = name;
            if (config_.program.name.extended.empty()) config_.program.name.extended = name;
        }

        Configuration config_;
        Handlers handlers_;
        formatter::Ptr pformatter_ = nullptr;
        std::unique_ptr<Context> pcontext_ = nullptr;
    };

}

#endif

