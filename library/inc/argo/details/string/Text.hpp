#ifndef HEADER_argo_details_string_Text_hpp_INCLUDE_GUARD
#define HEADER_argo_details_string_Text_hpp_INCLUDE_GUARD

#include "argo/details/range.hpp"
#include "argo/details/string/utility.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define ARGO_DETAILS_STRING_TEXT_DEBUG 0

namespace argo { namespace details { namespace string {

    class Text
    {
        struct Endline {};
        struct Indent {};
        struct Outdent {};
        struct Boolalpha {};

    public:
        static const Endline &endl() { static const Endline endl_; return endl_; }
        static const Indent &indent() { static const Indent indent_; return indent_; }
        static const Outdent &outdent() { static const Outdent outdent_; return outdent_; }
        static const Boolalpha &boolalpha() { static const Boolalpha boolalpha_; return boolalpha_; }
        static const std::string &tab() { static const std::string tab_{"    "}; return tab_; }
        
        struct Color
        {
            struct Code
            {
                std::vector<unsigned int> sequence;
            };

            static constexpr unsigned BlackForeground = 30;
            static constexpr unsigned BlackBackground = 40;
            static constexpr unsigned RedForeground = 31;
            static constexpr unsigned RedBackground = 41;
            static constexpr unsigned GreenForeground = 32;
            static constexpr unsigned GreenBackground = 42;
            static constexpr unsigned YellowForeground = 33;
            static constexpr unsigned YellowBackground = 43;
            static constexpr unsigned BlueForeground = 34;
            static constexpr unsigned BlueBackground = 44;
            static constexpr unsigned MagentaForeground = 35;
            static constexpr unsigned MagentaBackground = 45;
            static constexpr unsigned CyanForeground = 36;
            static constexpr unsigned CyanBackground = 46;
            static constexpr unsigned WhiteForeground = 37;
            static constexpr unsigned WhiteBackground = 47;
            static constexpr unsigned Reset = 0;
            static constexpr unsigned BoldBrightOn = 1;
            static constexpr unsigned Underline = 4;
            static constexpr unsigned Inverse = 7;
            static constexpr unsigned BoldBrightOff = 21;
            static constexpr unsigned UnderlineOff = 24;
            static constexpr unsigned InverseOff = 27;
        };
        static const Color::Code color_set(const std::vector<unsigned int> &colors) { return Color::Code{colors}; }
        static const Color::Code color_reset() { return Color::Code{{Color::Reset}}; }

        template<typename T>
        Text &operator<<(const T &element);
        Text &operator<<(std::string str);
        Text &operator<<(const Endline &tag);
        Text &operator<<(const Indent &tag);
        Text &operator<<(const Outdent &tag);
        Text &operator<<(const Boolalpha &tag);
        Text &operator<<(const Color::Code &tag);
        Text &operator<<(const Text &txt);

        std::string str() const;
        void clear();

    private:
        std::ostringstream ss_;
        std::size_t indent_level_ = 0;
        bool is_newline_ = true;

        std::string indent_(bool update_is_newline = true);
    };

    inline Text &Text::operator<<(std::string str)
    {
        const std::string from = "\n";
        const std::string to = from + indent_(false);
        string::replace_all(str, from, to);
#if ARGO_DETAILS_STRING_TEXT_DEBUG
        std::ostringstream os;
        os << indent_() << str;
        std::cout << os.str();
        ss_ << os.str();
#else
        ss_ << indent_() << str;
#endif
        return *this;
    }
    inline Text &Text::operator<<(const Endline &tag)
    {
        ss_ << "\n";
#if ARGO_DETAILS_STRING_TEXT_DEBUG
        std::cout << std::endl;
#endif
        is_newline_ = true;
        return *this;
    }
    inline Text &Text::operator<<(const Indent &tag)
    {
        ++indent_level_;
        return *this;
    }
    inline Text &Text::operator<<(const Outdent &tag)
    {
        if (indent_level_ > 0) --indent_level_;
        return *this;
    }
    inline Text &Text::operator<<(const Boolalpha &tag)
    {
        ss_ << std::boolalpha;
        return *this;
    }
    inline Text &Text::operator<<(const Color::Code &tag)
    {
#if ARGO_TOOLSET_PLATFORM_POSIX
        ss_ << "\033[";
        ss_ << string::join(RANGE(tag.sequence), ";");
        ss_ << "m";
#endif
        return *this;
    }
    inline Text &Text::operator<<(const Text &txt) { return *this << txt.str(); }

    inline std::string Text::str() const { return ss_.str(); }

    inline void Text::clear() 
    { 
        ss_.str("");
        ss_.clear();
        indent_level_ = 0; 
    }

    inline std::string Text::indent_(bool update_is_newline)
    {
        std::string result;
        if (is_newline_)
        {
            for (auto n = 0u; n < indent_level_; ++n) result += tab();
            if (update_is_newline) is_newline_ = false;
        }
        return result;
    }

    template<typename T>
    Text &Text::operator<<(const T &element)
    {
#if ARGO_DETAILS_STRING_TEXT_DEBUG
        std::ostringstream os;
        os << indent_() << element;
        ss_ << os.str();
        std::cout << os.str();
#else
        ss_ << indent_() << element;
#endif
        return *this;
    }

} } }

#endif
