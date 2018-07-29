#ifndef HEADER_argo_traits_conversion_hpp_INCLUDE_GUARD
#define HEADER_argo_traits_conversion_hpp_INCLUDE_GUARD

#include "argo/details/optional.hpp"
#include "argo/details/range.hpp"
#include <string>
#include <type_traits>

namespace argo { namespace traits {

    template<typename T, typename = void>
    struct conversion;

    template<>
    struct conversion<std::string>
    {
        static constexpr const char *description = "a string";
        static details::optional<std::string> run(const std::string &value) { return value; }
    };
    template<>
    struct conversion<unsigned int>
    {
        static constexpr const char *description = "an unsigned integer";
        static details::optional<unsigned int> run(const std::string &value)
        {
            try { return std::stoi(value); }
            catch (const std::invalid_argument &) { return details::nullopt; }
        }
    };
    template<>
    struct conversion<float>
    {
        static constexpr const char *description = "a float";
        static details::optional<float> run(const std::string &value)
        {
            try { return std::stof(value); }
            catch (const std::invalid_argument &) { return details::nullopt; }
        }
    };
    template<>
    struct conversion<double>
    {
        static constexpr const char *description = "a double";
        static details::optional<double> run(const std::string &value)
        {
            try { return std::stod(value); }
            catch (const std::invalid_argument &) { return details::nullopt; }
        }
    };
    template<>
    struct conversion<bool>
    {
        static constexpr const char *description = "a boolean";
        static details::optional<bool> run(const std::string &value)
        {
            static const auto negative = {"0", "false", "no", "NO", "n", "N"};
            static const auto positive = {"1", "true", "yes", "YES", "y", "Y"};
            if (std::end(negative) != std::find(RANGE(negative), value)) return false;
            else if (std::end(positive) != std::find(RANGE(positive), value)) return true;
            return details::nullopt;
        }
    };
    template<typename T>
    struct conversion<T, typename std::enable_if<std::is_enum<T>::value>::type>
    {
        static constexpr const char *description = "an unsigned integer mapped to an enumeration";
        static details::optional<T> run(const std::string &value)
        {
            const auto converted = conversion<unsigned int>::run(value);
            if (!converted) return details::nullopt;
            const auto number = *converted;
            if (number >= static_cast<unsigned int>(T::Nr_)) return details::nullopt;
            return static_cast<T>(number);
        }
    };

    template<typename T>
    struct no_conversion
    {
        static constexpr const char *description = "no conversion required";
        static details::optional<std::string> run(const std::string &value) { return value; }
    };

} }

#endif

