#include "argo/Context.hpp"

#include "argo/Handlers.hpp"
#include "argo/details/config/build.hpp"
#include "argo/formatter/IFormatter.hpp"
#include "argo/handler/Option.hpp"
#include "argo/handler/group/IGroup.hpp"
#include "argo/utility.hpp"

namespace argo {

    namespace {

        std::vector<handler::Option *> collect_options(const Handlers &handlers)
        {
            auto options = handlers.filter<handler::Option>();
            const auto groups = handlers.filter<handler::group::IGroup>();
            for (const auto pgroup: groups)
            {
                assert(!!pgroup);
                const auto &group = *pgroup;
                const auto &subhandlers = group.handlers();
                const auto &suboptions = collect_options(subhandlers);
                std::copy(RANGE(suboptions), std::back_inserter(options));
            }
            std::sort(RANGE(options), [](const handler::Option *pleft, const handler::Option *pright)
                      {
                        assert(!!pleft && !!pright);
                        const auto &left = pleft->name().str();
                        const auto &right = pright->name().str();
                        return std::lexicographical_compare(RANGE(left), RANGE(right));
                      });
            return options;
        }
        std::vector<handler::group::IGroup *> collect_groups(const Handlers &handlers)
        {
            auto groups = handlers.filter<handler::group::IGroup>();
            for (const auto pgroup: groups)
            {
                assert(!!pgroup);
                const auto &group = *pgroup;
                const auto &subgroups = collect_groups(group.handlers());
                std::copy(RANGE(subgroups), std::back_inserter(groups));
            }
            return groups;
        }
        std::vector<handler::Option *> apply_filter(const std::vector<handler::Option *> &options, const Context::OptionFilter &option_filter)
        {
            std::vector<handler::Option *> selection;
            selection.reserve(options.size());
            std::copy_if(RANGE(options), std::back_inserter(selection), [&option_filter](const handler::Option *poption){ return option_filter(*poption); });
            return selection;
        }
        std::vector<handler::group::IGroup *> apply_filter(const std::vector<handler::group::IGroup *> &groups, const Context::GroupFilter &group_filter)
        {
            std::vector<handler::group::IGroup *> selection;
            selection.reserve(groups.size());
            std::copy_if(RANGE(groups), std::back_inserter(selection), [&group_filter](const handler::group::IGroup *pgroup){ return group_filter(*pgroup); });
            return selection;
        }

    }

    ARGO_INLINE void Context::error(const std::string &message)
    {
        error();
        if (result_.message.empty()) result_.message = formatter().format_error(*this, message);
    }
    ARGO_INLINE std::vector<handler::Option *> Context::options_standalone(const OptionFilter &option_filter) const { return apply_filter(handlers().filter<handler::Option>(), option_filter); }
    ARGO_INLINE std::vector<handler::Option *> Context::options_all(const OptionFilter &option_filter) const { return apply_filter(collect_options(handlers()), option_filter); }
    ARGO_INLINE std::vector<handler::group::IGroup *> Context::groups_all(const GroupFilter &group_filter) const { return apply_filter(collect_groups(handlers()), group_filter); }
    ARGO_INLINE std::vector<handler::group::IGroup *> Context::groups_standalone(const GroupFilter &group_filter) const { return apply_filter(handlers().filter<handler::group::IGroup>(), group_filter); }

}

