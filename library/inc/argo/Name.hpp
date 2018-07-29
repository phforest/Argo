#ifndef HEADER_argo_Name_hpp_INCLUDE_GUARD
#define HEADER_argo_Name_hpp_INCLUDE_GUARD

#include "argo/details/mss.hpp"
#include "argo/details/optional.hpp"
#include "argo/details/string/Text.hpp"
#include "argo/details/string/utility.hpp"
#include <cassert>
#include <ostream>

namespace argo {

    struct Name
    {
    public:
        static std::string guess_shorthand(const std::string &longhand)
        {
            assert(is_valid_longhand_(longhand));
            return std::string("-") + longhand[2];
        }
        static bool is_valid(const std::string &name) { return is_valid_shorthand_(name) || is_valid_longhand_(name); }

        std::string hash() const
        {
            if (!!shorthand_ && longhand_) return *shorthand_ + *longhand_;
            else if (!!shorthand_) return *shorthand_;
            else if (!!longhand_) return *longhand_;
            assert(false);
            return "";
        }
        details::optional<std::string> shorthand() const { return shorthand_; }
        bool shorthand(const std::string &name)
        {
            MSS_BEGIN(bool);
            MSS_Q(is_valid_shorthand_(name));
            shorthand_ = name;
            MSS_END();
        }
        details::optional<std::string> longhand() const { return longhand_; }
        bool longhand(const std::string &name)
        {
            MSS_BEGIN(bool);
            MSS_Q(is_valid_longhand_(name));
            longhand_ = name;
            MSS_END();
        }
        std::string str() const
        {
            std::ostringstream os;
            print(os);
            return os.str();
        }
        template<typename T>
        T &print(T &t) const
        {
            std::ostringstream os;
            if (!!longhand() && !!shorthand()) os << *longhand() << " (" << *shorthand() << ")";
            else if (!!shorthand()) os << *shorthand();
            else if (!!longhand()) os << *longhand();
            else assert(false);
            t << os.str();
            return t;
        }

    private:
        static bool is_valid_shorthand_(const std::string &shorthand)
        {
            MSS_BEGIN(bool);
            MSS_Q(2 == shorthand.size());
            MSS_Q(details::string::starts_with(shorthand, "-"));
            MSS_END();
        }
        static bool is_valid_longhand_(const std::string &longhand)
        {
            MSS_BEGIN(bool);
            MSS_Q(2 < longhand.size());
            MSS_Q(details::string::starts_with(longhand, "--"));
            MSS_END();
        }

        details::optional<std::string> shorthand_;
        details::optional<std::string> longhand_;
    };

    inline std::ostream &operator<<(std::ostream &os, const Name &name) { return name.print(os); }

}

#endif

