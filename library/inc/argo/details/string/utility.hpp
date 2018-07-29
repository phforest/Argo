#ifndef HEADER_argo_details_string_utility_hpp_INCLUDE_GUARD
#define HEADER_argo_details_string_utility_hpp_INCLUDE_GUARD

#include "argo/details/optional.hpp"
#include "argo/details/range.hpp"
#include <algorithm>
#include <cctype>
#include <initializer_list>
#include <sstream>
#include <string>
#include <vector>

namespace argo { namespace details { namespace string {

    template<typename T>
    struct from
    {
        static std::string run(const T &t) { return std::to_string(t); }
    };
    template<>
    struct from<std::string>
    {
        static std::string run(const std::string &t) { return t; }
    };
    template<>
    struct from<const char *>
    {
        static std::string run(const char *cstr) { return cstr; }
    };

    template<typename It, typename value_type = typename std::iterator_traits<It>::value_type>
    std::string join(It begin, It end, const std::string &separator = " ")
    {
        if (begin == end) return {};

        auto it = begin;
        std::string result = from<value_type>::run(*it++);
        for(; it != end; ++it) result += separator + from<value_type>::run(*it);
        return result;
    }
    template<typename T>
    std::string join(const std::initializer_list<T> &list, const std::string &separator = " ") { return join(RANGE(list), separator); }
    inline std::vector<std::string> split(std::string str, std::string delimiter = " ")
    {
        std::size_t pos = 0;
        std::vector<std::string> result;
        while ((pos = str.find(delimiter)) != std::string::npos) 
        {
            const auto token = str.substr(0, pos);
            result.push_back(std::move(token));
            str.erase(0, pos + delimiter.length());
        }
        if (!str.empty()) result.push_back(str);
        return result;
    }
    inline void replace_all(std::string &str, const std::string &from, const std::string &to)
    {
        std::size_t start_pos = 0u;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.size(), to);
            start_pos += to.size();
        }
    }
    inline bool starts_with(const std::string &input, const std::string &test) { return test.size() <= input.size() && input.compare(0, test.size(), test) == 0; }
    inline bool ends_with(const std::string &input, const std::string &test) { return input.size() >= test.size() && input.compare(input.size() - test.size(), test.size(), test) == 0; } 
    inline void ltrim(std::string &input) { input.erase(input.begin(), std::find_if(RANGE(input), [](int ch) { return !std::isspace(ch); })); }
    inline void rtrim(std::string &input) { input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) { return !std::isspace(ch); }).base(), input.end()); }
    inline void trim(std::string &input) { ltrim(input); rtrim(input); }
    inline std::string surround(const std::string &input, const std::string &left, details::optional<std::string> right = details::nullopt)
    {
        if (!right)
        {
            if ("(" == left) right = ")";
            else if ("[" == left) right = "]";
            else if ("{" == left) right = "}";
            else if ("<" == left) right = ">";
            else right = left;
        }
        assert(!!right);
        return left + input + *right;
    }
    template<typename Out>
    void split(const std::string &input, const char delimiter, Out out)
    {
        std::istringstream ss{input};
        std::string part;
        while (std::getline(ss, part, delimiter)) *(out++) = part;
    }
    inline std::vector<std::string> split(const std::string &input, const char delimiter)
    {
        std::vector<std::string> result;
        split(input, delimiter, std::back_inserter(result));
        return result;
    }

} } }

#endif

