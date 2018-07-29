#ifndef HEADER_argo_Handlers_hpp_INCLUDE_GUARD
#define HEADER_argo_Handlers_hpp_INCLUDE_GUARD

#include "argo/details/mss.hpp"
#include "argo/details/range.hpp"
#include "argo/details/transform_iterator.hpp"
#include "argo/handler/IHandler.hpp"
#include <algorithm>
#include <map>
#include <string>
#include <vector>

namespace argo {

    class Handlers
    {
        using data_type = std::map<std::string, handler::Ptr>;

    public:
        using value_type = handler::IHandler &;
        using reference = value_type;
        using const_iterator = details::transform_iterator<reference, typename data_type::const_iterator>;
        using iterator = details::transform_iterator<reference, typename data_type::iterator>;

        Handlers() = default;
        Handlers(const Handlers &handlers)
        {
            for (const auto &handler: handlers)
            {
                const auto is_ok = add(handler);
                assert(!!is_ok);
            }
        }
        Handlers (Handlers &&handlers): handlers_(std::move(handlers.handlers_)) {}
        Handlers &operator=(Handlers handlers)
        {
            using namespace std;

            if (this != &handlers)
            {
                swap(handlers_, handlers.handlers_);
            }
            return *this;
        }
        Handlers &operator=(Handlers &&handlers)
        {
            if (this != &handlers)
            {
                handlers_ = std::move(handlers.handlers_);
            }
            return *this;
        }

        const_iterator begin() const { return details::make_transform_iterator<reference>(details::transformation::dereference_mapped_type<reference>{}, std::begin(handlers_)); }
        iterator begin() { return details::make_transform_iterator<reference>(details::transformation::dereference_mapped_type<reference>{}, std::begin(handlers_)); }
        const_iterator end() const { return details::make_transform_iterator<reference>(details::transformation::dereference_mapped_type<reference>{}, std::end(handlers_)); }
        iterator end() { return details::make_transform_iterator<reference>(details::transformation::dereference_mapped_type<reference>{}, std::end(handlers_)); }

        bool empty() const { return handlers_.empty(); }
        std::size_t size() const { return handlers_.size(); }
        bool has(const handler::IHandler &handler) const { return handlers_.count(handler.hash()); }

        bool add(const handler::IHandler &handler)
        {
            MSS_BEGIN(bool);
            MSS(handler.is_valid());
            handlers_[handler.hash()] = handler.clone();
            MSS_END();
        }
        handler::IHandler &put(const handler::IHandler &handler)
        {
            const auto is_ok = add(handler);
            assert(!!is_ok);
            return *handlers_[handler.hash()];
        }
        template<typename T>
        std::vector<T *> filter() const
        {
            std::vector<T *> selection;
            std::for_each(RANGE(handlers_), [&selection](const data_type::value_type &kv) { if (T *pd = dynamic_cast<T *>(kv.second.get())) selection.push_back(pd); });
            return selection;
        }

    private:
        data_type handlers_;
    };

}

#endif

