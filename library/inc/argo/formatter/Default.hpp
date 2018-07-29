#ifndef HEADER_argo_formatter_Default_hpp_INCLUDE_GUARD
#define HEADER_argo_formatter_Default_hpp_INCLUDE_GUARD

#include "argo/Context.hpp"
#include "argo/details/string/utility.hpp"
#include "argo/formatter/IFormatter.hpp"
#include "argo/utility.hpp"
#include <iomanip>

namespace argo { namespace formatter {

    inline std::string format(const std::string &text, const unsigned int width, const unsigned int left_margin)
    {
        auto find_word_boundary = [](const std::string &line, const unsigned int width)
        {
            if (line.size() <= width) return width;
            auto idx = width;
            while (!std::isspace(line[idx])) --idx;
            return idx;
        };

        const std::string prefix(left_margin, ' ');
        std::string line;
        const auto lines = details::string::split(text, "\n");
        std::vector<std::string> result;
        result.reserve(lines.size());
        auto idx = 0u;
        do
        {
            if (idx < lines.size()) line += lines[idx];
            ++idx;
            line = prefix + line;
            if (line.size() > width)
            {
                const auto pivot_idx = find_word_boundary(line, width);
                result.push_back(line.substr(0, pivot_idx));
                line = line.substr(pivot_idx, line.size() - pivot_idx);
                details::string::ltrim(line);
            }
            else
            {
                result.push_back(line);
                line.clear();
            }
        } while (!line.empty() || idx < lines.size());
        const auto res = details::string::join(RANGE(result), "\n");
        return res;
    }

    class Default: public IFormatter
    {
    public:
        Default(): window_size_(80) {}

        virtual std::string format_error(Context &context, const std::string &message) override { return message; }
        virtual std::string format_help(Context &context) override
        {
            std::ostringstream help;
            help << format_heading_(context);
            help << format_usage_(context);
            help << format_description_(context);
            return help.str();
        }
        virtual std::string format_version(Context &context) override
        {
            const auto &program = context.program();
            std::ostringstream version;
            version << program.name.extended << std::endl;
            version << version_info_(program.version) << std::endl;
            return version.str();
        }

    private:
        std::string format_heading_(Context &context)
        {
            const auto &program = context.program();
            std::ostringstream heading;
            heading << std::endl;
            {
                std::string title = program.name.extended;
                std::for_each(RANGE(title), [](char &c){ c = std::toupper(c); });
                std::string shift((window_size_ - title.size())/2, ' ');
                heading << shift << title << std::endl << std::endl;
            }
            if (!program.name.brief.empty())
            {
                heading << format_title_("NAME");
                std::ostringstream tmp;
                tmp << program.name.brief;
                if (!program.description.brief.empty()) tmp << " -- " + program.description.brief;
                heading << format_content_(tmp.str());
            }
            if (has_version(program))
            {
                heading << format_title_("VERSION");
                heading << format_content_(version_info_(program.version));
            }
            return heading.str();
        }
        std::string format_usage_(Context &context)
        {
            const auto &program = context.program();
            std::ostringstream usage;
            usage << format_title_("USAGE");
            if (!program.description.usage.empty()) usage << format_content_(program.description.usage);
            else
            {
                const auto &text = generate_usage_(context);
                usage << format_content_(text);
            }
            usage << format_legend_(context);
            return usage.str();
        }
        std::string format_legend_(Context &context)
        {
            std::ostringstream legend;
            Txt note;
            {
                note << Txt::color_set({Txt::Color::Underline}) << "Note:" << Txt::color_reset();
            }
            legend << note.str() << std::endl;
            legend << "Groups are indicated with <>" << std::endl;
            legend << "Optional groups and options are indicated with ()" << std::endl;
            return format_content_(legend.str());
        }

        std::string format_description_(Context &context)
        {
            const auto &program = context.program();
            std::ostringstream description;
            if (!program.description.extended.empty())
            {
                description << format_title_("DESCRIPTION");
                description << format_content_(program.description.extended);
            }
            description << format_groups_(context);
            description << format_options_(context);
            description << std::endl;
            return description.str();
        }
        std::string format_groups_(Context &context)
        {
            const auto &groups = context.groups_all();
            std::ostringstream description;
            if (!groups.empty()) description << format_content_("The groups are as follows:");
            for (const auto pgroup: groups)
            {
                assert(!!pgroup);
                const auto &group = *pgroup;
                Txt tmp;
                tmp << Txt::color_set({Txt::Color::BoldBrightOn});
                tmp << group.name();
                tmp << Txt::color_reset();
                const auto sgroup = tmp.str();

                const std::string is_required = group.is_required() ? "[required]" : "";
                const std::string descr = group.description().empty() ? "" : "[" + group.description() + "]";
                const std::string attributes = is_required + descr;
                {
                    std::ostringstream os;
                    os << std::left << spacer() << sgroup;
                    os << std::setw(window_size_ - spacer().size() - group.name().size()) << std::right << attributes;
                    description << os.str() << std::endl;
                    if (!group.help().empty()) description << format_content_(group.help(), 8);
                    else description << std::endl;
                }
                {
                    std::ostringstream os;
                    for (const auto &handler: group.handlers())
                    {
                        os << spacer();
                        if (is_type<handler::Option>(handler))
                        {
                            const auto &option = static_cast<const handler::Option &>(handler);
                            os << option << std::endl;
                        }
                        else
                        {
                            const auto &group = static_cast<const handler::group::IGroup &>(handler);
                            os << "Group " << group.name() << std::endl;
                        }
                    }
                    description << format_content_(os.str());
                }
            }
            return description.str();
        }
        std::string format_options_(Context &context)
        {
            const auto &options = context.options_all();
            std::ostringstream description;
            description << format_content_("The options are as follows:");
            for (const auto poption: options)
            {
                assert(!!poption);
                const auto &option = *poption;
                Txt tmp;
                tmp << Txt::color_set({Txt::Color::BoldBrightOn});
                tmp << option;
                tmp << Txt::color_reset();
                const auto soption = tmp.str();
                
                const std::string is_required = option.is_required() ? "[required]" : "";
                const std::string nargs = "[" + option.nargs().description() + "]";
                const std::string attributes = is_required + nargs;
                std::ostringstream os;
                os << std::left << spacer() << soption;
                os << std::setw(window_size_ - spacer().size() - option.name().str().size()) << std::right << attributes;
                description << os.str() << std::endl;
                if (!option.help().empty()) description << format_content_(option.help(), 8);
                else description << std::endl;
            }
            return description.str();
        }
        
        std::string format_title_(const std::string &title) const
        {
            Txt txt;
            txt << Txt::color_set({Txt::Color::BoldBrightOn}) << title << Txt::endl() << Txt::color_reset();
            return txt.str();
        }
        std::string format_content_(const std::string &text, const unsigned int left_margin = 4) const
        {
            Txt txt;
            txt << format(text, window_size_, left_margin) << Txt::endl() << Txt::endl();
            return txt.str();
        }

        template<typename Version>
        std::string version_info_(const Version &version) const
        {
            std::ostringstream info;
            std::vector<unsigned int> numbers = {version.major,version.minor};
            if (!!version.patch) numbers.push_back(version.patch);
            info << "Release:  " + details::string::join(RANGE(numbers), ".");
            const auto githash = std::string(version.githash);
            if (!githash.empty())
            {
                info << std::endl;
                info << "Revision: " + githash;
            }
            return info.str();
        }
        std::string spacer() const { return "    "; }
        std::string generate_usage_(Context &context) const
        {
            std::ostringstream usage;
            {
                const auto &program = context.program();
                usage << program.name.brief << " ";
            }
            std::vector<std::string> opts;
            {
                auto add_options = [&opts](const std::vector<handler::Option *> &options, const std::string &delimiters = "")
                {
                    assert(delimiters.empty() ? true : 2 == delimiters.size());
                    for (const auto poption: options)
                    {
                        assert(!!poption);
                        const auto &option = *poption;
                        std::ostringstream os;
                        if (!delimiters.empty()) os << delimiters[0];
                        if (!option.name().longhand()) os << *option.name().shorthand();
                        else
                        {
                            assert(!!option.name().longhand());
                            os << *option.name().longhand();
                        }
                        if (!delimiters.empty()) os << delimiters[1];
                        opts.push_back(os.str());
                    }
                };
                {
                    const auto &options = context.options_standalone([](const handler::Option &option){ return option.is_required(); });
                    add_options(options);
                }
                {
                    const auto &options = context.options_standalone([](const handler::Option &option){ return !option.is_required(); });
                    add_options(options, "()");
                }
            }

            std::vector<std::string> grps;
            {
                auto add_groups = [&grps](const std::vector<handler::group::IGroup *> &groups, const std::string &delimiters = "")
                {
                    assert(delimiters.empty() ? true : 2 == delimiters.size());
                    for (const auto pgroup: groups)
                    {
                        assert(!!pgroup);
                        const auto &group = *pgroup;
                        std::ostringstream os;
                        if (!delimiters.empty()) os << delimiters[0];
                        os << "<" << group.name() << ">";
                        if (!delimiters.empty()) os << delimiters[1];
                        grps.push_back(os.str());
                    }
                };
                {
                    const auto &groups = context.groups_standalone([](const handler::group::IGroup &group){ return group.is_required(); });
                    add_groups(groups);
                }
                {
                    const auto &groups = context.groups_standalone([](const handler::group::IGroup &group){ return !group.is_required(); });
                    add_groups(groups, "()");
                }
            }
            usage << details::string::join(RANGE(opts), " ");
            if (!grps.empty()) usage << " ";
            usage << details::string::join(RANGE(grps), " ");
            return usage.str();
        }

        unsigned int window_size_;
    };

} }

#endif

