/*
MIT License

Copyright (c) 2018 D. Grine

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef HEADER_argo_Context_hpp_INCLUDE_GUARD
#define HEADER_argo_Context_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_Configuration_hpp_INCLUDE_GUARD
#define HEADER_argo_Configuration_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_program_Info_hpp_INCLUDE_GUARD
#define HEADER_argo_program_Info_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_program_Description_hpp_INCLUDE_GUARD
#define HEADER_argo_program_Description_hpp_INCLUDE_GUARD

#include <string>

namespace argo { namespace program {

    struct Description
    {
        std::string brief;
        std::string extended;
        std::string usage;
    };

} }

#endif

#ifndef HEADER_argo_program_Name_hpp_INCLUDE_GUARD
#define HEADER_argo_program_Name_hpp_INCLUDE_GUARD

#include <string>

namespace argo { namespace program {

    struct Name
    {
        std::string brief;
        std::string extended;
    };

} }

#endif

#ifndef HEADER_argo_program_Version_hpp_INCLUDE_GUARD
#define HEADER_argo_program_Version_hpp_INCLUDE_GUARD

#include <string>

namespace argo { namespace program {

    struct Version
    {
        unsigned major;
        unsigned minor;
        unsigned patch;
        std::string githash;
    };

} }

#endif


namespace argo { namespace program {

    struct Info
    {
        Name name;
        Description description;
        Version version;
    };

} }

#endif


namespace argo {

    struct Configuration
    {
        program::Info program{};
        bool add_help = true;
        bool add_version = true;
    };

}

#endif

#ifndef HEADER_argo_Result_hpp_INCLUDE_GUARD
#define HEADER_argo_Result_hpp_INCLUDE_GUARD

#include <ostream>
#include <string>

namespace argo {

    struct Result
    {
        bool success = true;
        bool requested_abort = false;
        std::string message;
        unsigned int nr_options = 0;
        unsigned int nr_args = 0;
    };

    inline std::ostream &operator<<(std::ostream &os, const Result &result)
    {
        os << "{\n";
        os << "  success: " << result.success << ",\n";
        os << "  message: \"" << result.message << "\",\n";
        os << "  nr_options: \"" << result.nr_options << "\",\n";
        os << "  nr_args: \"" << result.nr_args << "\"\n";
        os << "}";
        return os;
    }

}

#endif

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


#ifndef HEADER_argo_Handlers_hpp_INCLUDE_GUARD
#define HEADER_argo_Handlers_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_details_mss_hpp_INCLUDE_GUARD
#define HEADER_argo_details_mss_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_details_config_toolset_hpp_INCLUDE_GUARD
#define HEADER_argo_details_config_toolset_hpp_INCLUDE_GUARD

//Compiler
#if defined(__clang__)
#define ARGO_TOOLSET_COMPILER "clang"
#define ARGO_TOOLSET_COMPILER_CLANG 1
#define ARGO_TOOLSET_COMPILER_VERSION_MAJOR __clang_major__
#define ARGO_TOOLSET_COMPILER_VERSION_MINOR __clang_minor__
#define ARGO_TOOLSET_COMPILER_VERSION_PATCH __clang_patchlevel__
#elif defined(__GNUC__)
#define ARGO_TOOLSET_COMPILER "gcc"
#define ARGO_TOOLSET_COMPILER_GCC 1
#define ARGO_TOOLSET_COMPILER_VERSION_MAJOR __GNUC__
#define ARGO_TOOLSET_COMPILER_VERSION_MINOR __GNUC_MINOR__
#define ARGO_TOOLSET_COMPILER_VERSION_PATCH __GNUC_PATCHLEVEL__
#if ARGO_TOOLSET_COMPILER_VERSION_MAJOR < 5
#define ARGO_TOOLSET_COMPILER_GCC_OLD 1
#endif
#elif defined(_MSC_VER)
#define ARGO_TOOLSET_COMPILER "msvc"
#define ARGO_TOOLSET_COMPILER_MSVC 1
#if _MSC_VER >= 1910 // (MSVC++ 15.0 - Visual Studio 2017)
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2017 1
#elif _MSC_VER == 1900 // (MSVC++ 14.0 - Visual Studio 2015)
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2015 1
#elif _MSC_VER == 1800 // (MSVC++ 12.0 - Visual Studio 2013)
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2013 1
#else
#error "Unsupported toolset: unsupported Visual Studio version"
#endif
#else
#error "Unsupported toolset: unknown compiler"
#endif

//Platform
#if defined(__ANDROID__)
#define ARGO_TOOLSET_PLATFORM "android"
#define ARGO_TOOLSET_PLATFORM_ANDROID 1
#elif defined(__linux__)
#define ARGO_TOOLSET_PLATFORM "linux"
#define ARGO_TOOLSET_PLATFORM_LINUX 1
#define ARGO_TOOLSET_PLATFORM_POSIX 1
#elif defined(__APPLE__)  
#define ARGO_TOOLSET_PLATFORM "apple"
#define ARGO_TOOLSET_PLATFORM_APPLE 1
#define ARGO_TOOLSET_PLATFORM_POSIX 1
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__) 
#define ARGO_TOOLSET_PLATFORM "windows"
#define ARGO_TOOLSET_PLATFORM_WINDOWS 1
#else
#error "Unsupported toolset: unknown platform"
#endif 

//C++ Standard
#if ARGO_TOOLSET_COMPILER_GCC || ARGO_TOOLSET_COMPILER_CLANG
#if __cplusplus == 199711L
#define ARGO_TOOLSET_CPP_STD 3
#define ARGO_TOOLSET_CPP_STD_03 1
#elif __cplusplus == 201402L
#define ARGO_TOOLSET_CPP_STD 14
#define ARGO_TOOLSET_CPP_STD_14 1
#elif __cplusplus == 201703L
#define ARGO_TOOLSET_CPP_STD 17
#define ARGO_TOOLSET_CPP_STD_17 1
#elif __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X)
#define ARGO_TOOLSET_CPP_STD 11
#define ARGO_TOOLSET_CPP_STD_11 1
#elif ARGO_TOOLSET_COMPILER_MSVC
#if ARGO_TOOLSET_COMPILER_MSVC_VS_2017
#if _MSVC_LANG == 201703
#define ARGO_TOOLSET_CPP_STD 17
#define ARGO_TOOLSET_CPP_STD_17 1
#else
#define ARGO_TOOLSET_CPP_STD 14
#define ARGO_TOOLSET_CPP_STD_14 1
#endif
#elif ARGO_TOOLSET_COMPILER_MSVC_VS_2015
#define ARGO_TOOLSET_CPP_STD 11
#define ARGO_TOOLSET_CPP_STD_11 1
#elif ARGO_TOOLSET_COMPILER_MSVC_VS_2013
#define ARGO_TOOLSET_CPP_STD 11
#define ARGO_TOOLSET_CPP_STD_11 1
#elif ARGO_TOOLSET_COMPILER_MSVC_VS_2010
#define ARGO_TOOLSET_CPP_STD 3
#define ARGO_TOOLSET_CPP_STD_03 1
#elif ARGO_TOOLSET_COMPILER_MSVC_VS_2008
#define ARGO_TOOLSET_CPP_STD 3
#define ARGO_TOOLSET_CPP_STD_03 1
#else
#define ARGO_TOOLSET_CPP_STD 3
#define ARGO_TOOLSET_CPP_STD_03 1
#endif
#else
#error "Unsupported toolset: unknown C++ standard"
#endif
#endif

//Debug/Release
#if !defined(NDEBUG)
#define ARGO_TOOLSET_DEBUG 1
#else
#define ARGO_TOOLSET_RELEASE 1
#endif

#endif
#include <iostream>

#define MSS_GET_ARG_1_(args) MSS_GET_ARG_1 args
#define MSS_GET_ARG_1(N, ...) N
#define MSS_GET_ARG_2_(args) MSS_GET_ARG_2 args
#define MSS_GET_ARG_2(_1, N, ...) N
#define MSS_GET_ARG_3_(args) MSS_GET_ARG_3 args
#define MSS_GET_ARG_3(_1, _2, N, ...) N

#ifdef MSS_BEGIN
#error "MSS_BEGIN already defined"
#endif
#define MSS_BEGIN(type) using mss_type = type

#ifdef MSS_RETURN_OK
#error "MSS_RETURN_OK already defined"
#endif
#define MSS_RETURN_OK() return true

#ifdef MSS_RETURN_ERROR
#error "MSS_RETURN_ERROR already defined"
#endif
#define MSS_RETURN_ERROR() return false

#ifdef MSS_END
#error "MSS_END already defined"
#endif
#define MSS_END() MSS_RETURN_OK();

//#define MSS_PRINT_TRACEBACK

#ifdef MSS
#error "MSS already defined"
#endif
#if MSS_PRINT_TRACEBACK
#define MSS_LOG_TRACEBACK(expr, file, line) std::cerr << "[MSS FAILURE] " << file << ":" << line << ": " << expr << std::endl;
#else
#define MSS_LOG_TRACEBACK(...) 
#endif
#define MSS_1(expr) \
    { \
        mss_type mss_res = (expr); \
        if (!mss_res) \
        { \
            MSS_LOG_TRACEBACK(#expr, __FILE__, __LINE__) \
            return false; \
        } \
    }
#define MSS_2(expr, block) \
    { \
        mss_type mss_res = (expr); \
        if (!mss_res) \
        { \
            MSS_LOG_TRACEBACK(#expr, __FILE__, __LINE__) \
            block; \
            return false; \
        } \
    }
#define MSS(...) MSS_GET_ARG_3_((__VA_ARGS__, MSS_2, MSS_1))(__VA_ARGS__)

#ifdef MSS_Q
#error "MSS_Q already defined"
#endif
#define MSS_Q_1(expr) \
    { \
        mss_type mss_res = (expr); \
        if (!mss_res) return false; \
    }
#define MSS_Q_2(expr, block) \
    { \
        mss_type mss_res = (expr); \
        if (!mss_res) \
        { \
            block; \
            return false; \
        } \
    }
#define MSS_Q(...) MSS_GET_ARG_3_((__VA_ARGS__, MSS_Q_2, MSS_Q_1))(__VA_ARGS__)

#endif
#ifndef HEADER_argo_details_range_hpp_INCLUDE_GUARD
#define HEADER_argo_details_range_hpp_INCLUDE_GUARD

#ifdef RANGE
#error RANGE macro already defined
#endif
#define RANGE(container) (std::begin(container)), (std::end(container))

#endif
#ifndef HEADER_argo_transform_iterator_hpp_INCLUDE_GUARD
#define HEADER_argo_transform_iterator_hpp_INCLUDE_GUARD

#include <cassert>
#include <functional>
#include <iterator>
#include <type_traits>

namespace argo { namespace details {

    namespace transformation {
    
        template<typename ReturnType>
        struct dereference
        {
            template<typename It>
            ReturnType operator()(It it) const
            {
                const auto &ptr = *it;
                assert(!!ptr);
                return *ptr;
            }
        };

        template<typename ReturnType>
        struct mapped_type
        {
            template<typename It>
            ReturnType operator()(It it) const { return it->second; }
        };

        template<typename ReturnType>
        struct dereference_mapped_type
        {
            template<typename It>
            ReturnType operator()(It it) const { return *it->second; }
        };

    }
    
    //Transforms the underlying iterator upon dereferencing
    template<typename ResultType, typename It>
    class transform_iterator
    {
    public:
        using difference_type = std::ptrdiff_t;
        using value_type = ResultType;
        using pointer = value_type;
        using reference = value_type;
        using iterator_category = typename std::iterator_traits<It>::iterator_category;

        using transformation_type = std::function<ResultType(It)>;
        
        explicit transform_iterator(const transformation_type &f, It iterator):
            f_(f),
            iterator_(iterator)
        {}
        explicit transform_iterator(It iterator):
            f_(transformation_type{}),
            iterator_(iterator)
        {}
        
        value_type operator*() const { return f_(iterator_); }
        
        pointer operator->() const { return &f_(iterator_); }
        
        transform_iterator &operator++()
        {
            ++iterator_;
            return *this;
        }
        
        transform_iterator operator++(int)
        {
            transform_iterator tmp{*this};
            this->operator++();
            return tmp;
        }
        
        transform_iterator &operator--()
        {
            --iterator_;
            return *this;
        }
        
        transform_iterator operator--(int)
        {
            transform_iterator tmp{*this};
            this->operator--();
            return tmp;
        }
        
        transform_iterator &operator+=(const unsigned int n)
        {
            iterator_ += n;
            return *this;
        }
        
        transform_iterator &operator-=(const unsigned int n)
        {
            iterator_ -= n;
            return *this;
        }
        
        transform_iterator operator+(const unsigned int n) const
        {
            transform_iterator tmp{*this};
            tmp += n;
            return tmp;
        }
        
        transform_iterator operator-(const unsigned int n) const
        {
            transform_iterator tmp{*this};
            tmp -= n;
            return tmp;
        }
        
        difference_type operator-(const transform_iterator &other) const { return iterator_ - other.iterator_; }
        
        bool operator==(const transform_iterator &other) const { return iterator_ == other.iterator_; }
        
        bool operator!=(const transform_iterator &other) const { return !this->operator==(other); }

        bool operator<(const transform_iterator &other) const { return iterator_ < other.iterator_; }

        It iterator() const { return iterator_; }
        
    private:
        transformation_type f_;
        It iterator_;
    };
    
    template<typename ResultType, typename It>
    transform_iterator<ResultType, It> make_transform_iterator(typename transform_iterator<ResultType, It>::transformation_type f, It iterator) { return transform_iterator<ResultType, It>{f, iterator}; }
    
} }

#endif
#ifndef HEADER_argo_handler_IHandler_hpp_INCLUDE_GUARD
#define HEADER_argo_handler_IHandler_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_RawList_hpp_INCLUDE_GUARD
#define HEADER_argo_RawList_hpp_INCLUDE_GUARD

#include <string>
#include <vector>

namespace argo {

    using RawList = std::vector<std::string>;

}

#endif

#ifndef HEADER_argo_details_memory_hpp_INCLUDE_GUARD
#define HEADER_argo_details_memory_hpp_INCLUDE_GUARD

#include <memory>

namespace argo { namespace details {

    template <typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args &&... args) { return std::unique_ptr<T>(new T(std::forward<Args>(args)...)); }

} }

#endif

namespace argo { namespace handler {

    class IHandler;
    using Ptr = std::unique_ptr<IHandler>;

    enum class Confidence
    {
        Zero = 0,
        Maybe = 1,
        Definitely = 2
    };

    class IHandler
    {
    public:
        virtual ~IHandler() = default;

        unsigned int nr_selected() const { return nr_selected_; }
        bool can_handle(Context &context, const std::string &raw_arg)
        {
            MSS_BEGIN(bool);
            MSS(recognizes(context, raw_arg));
            ++nr_selected_;
            //L(C(nr_selected_));
            MSS_END();
        }

        virtual Ptr clone() const = 0;
        //!Returns whether the handler has been correctly configured by the user
        virtual bool is_valid() const = 0;
        virtual std::string hash() const = 0;
        //!Returns whether the handler recognizes the raw argument. If it does, it is required
        //to update the context accordingly
        virtual bool recognizes(Context &context, const std::string &raw_arg) = 0;
        //!Returns whether the handler is satisfied: has it been able to fulfill its configuration
        virtual bool is_satisfied(Context &context) const = 0;

    protected:
        unsigned int nr_selected_ = 0;
    };

} }

#endif

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

#ifndef HEADER_argo_details_config_build_hpp_INCLUDE_GUARD
#define HEADER_argo_details_config_build_hpp_INCLUDE_GUARD

#ifdef ARGO_BUILD_STATIC_LIBRARY
#define ARGO_INLINE 
#else
#define ARGO_INLINE inline
#endif

#endif
#ifndef HEADER_argo_formatter_IFormatter_hpp_INCLUDE_GUARD
#define HEADER_argo_formatter_IFormatter_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_details_string_Text_hpp_INCLUDE_GUARD
#define HEADER_argo_details_string_Text_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_details_string_utility_hpp_INCLUDE_GUARD
#define HEADER_argo_details_string_utility_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_details_optional_hpp_INCLUDE_GUARD
#define HEADER_argo_details_optional_hpp_INCLUDE_GUARD

#include <array>
#include <cassert>
#include <cstddef>
#include <type_traits>

namespace argo { namespace details {

    struct nullopt_t { nullopt_t(int) {} };

    const auto nullopt = nullopt_t{0};

    template<typename T>
    class optional
    {
    public:
        using value_type = T;

        optional() = default;
        optional(const T &t) { set(t); }
        optional(T &&t) { set(std::forward<T>(t)); }
        optional(const optional &other) { if (other) set(*other); }
        optional(optional &&other) { if (other) set(std::move(*other.ptr_())); }
        optional(const nullopt_t &null) {}
        optional(const std::nullptr_t &null) {}
        optional &operator=(const optional &other)
        {
            if (this != &other)
            {
                if (other) set(*other);
                else reset();
            }
            return *this;
        }
        optional &operator=(const T &other) { set(other); return *this; }
        optional &operator=(T &&other) { set(std::move(other)); return *this; }
        optional &operator=(optional &&other)
        {
            if (other) set(std::move(*other.ptr_()));
            else reset();
            return *this;
        }
        optional &operator=(const nullopt_t &null) { reset(); return *this; }
        ~optional() { reset(); }

        bool equal(const optional &other) const
        {
            if (valid() && other.valid()) return *get() == *other.get();
            return valid() == other.valid();
        }
        bool valid() const { return is_valid_; }
        explicit operator bool() const { return valid(); }
        void reset()
        {
            if (is_valid_) ptr_()->~T();
            is_valid_ = false;
        }
        T &emplace()
        {
            reset();
            new(ptr_()) T();
            is_valid_ = true;
            return *ptr_();
        }
        void set(const T &v)
        {
            reset();
            new(ptr_()) T(v);
            is_valid_ = true;
        }
        void set(T &&v)
        {
            reset();
            new(ptr_()) T(std::move(v));
            is_valid_ = true;
        }
        void set_if_unset(const T &v)
        {
            if (is_valid_) return;
            set(v);
        }
        const T *get() const
        {
            if (!is_valid_) return nullptr;
            return ptr_();
        }
        const T &operator*() const { assert(is_valid_); return *ptr_(); }
        T &operator*() { assert(is_valid_); return *ptr_(); }
        const T *operator->() const { assert(is_valid_); return ptr_(); }
        T *operator->() { assert(is_valid_); return ptr_(); }
        const T &value_or(const T &v) const { if (is_valid_) return *ptr_(); return v; }

    private:
        using Block = std::array<std::uint8_t, sizeof(T)>;

        T *ptr_() { return reinterpret_cast<T *>(&storage_.block[0]); }
        const T *ptr_() const { return reinterpret_cast<const T *>(&storage_.block[0]); }

        union Storage
        {
            max_align_t align_{};
            Block block;
        };
        Storage storage_;
        bool is_valid_ = false;
    };

    template<typename T>
    inline bool operator==(const optional<T> &lhs, const optional<T> &rhs)
    {
        if (static_cast<bool>(lhs) != static_cast<bool>(rhs)) return false;
        if (!static_cast<bool>(lhs)) return true;
        return *lhs == *rhs;
    }
    template<typename T>
    inline bool operator!=(const optional<T> &lhs, const optional<T> &rhs) { return !(lhs == rhs); }
    template<typename T>
    inline bool operator<(const optional<T> &lhs, const optional<T> &rhs)
    {
        if (!static_cast<bool>(rhs)) return false;
        if (!static_cast<bool>(lhs)) return true;
        return *lhs < *rhs;
    }
    template<typename T>
    inline bool operator>(const optional<T> &lhs, const optional<T> &rhs) { return rhs < lhs; }
    template<typename T>
    inline bool operator<=(const optional<T> &lhs, const optional<T> &rhs) { return !(rhs < lhs); }
    template<typename T>
    inline bool operator>=(const optional<T> &lhs, const optional<T> &rhs) { return !(lhs < rhs); }
    template<typename T>
    inline bool operator==(const optional<T> &lhs, nullopt_t) noexcept { return !static_cast<bool>(lhs); }
    template<typename T>
    inline bool operator==(nullopt_t, const optional<T> &rhs) noexcept { return !static_cast<bool>(rhs); }
    template<typename T>
    inline bool operator!=(const optional<T> &lhs, nullopt_t) noexcept { return static_cast<bool>(lhs); }
    template<typename T>
    inline bool operator!=(nullopt_t, const optional<T> &rhs) noexcept { return static_cast<bool>(rhs); }
    template<typename T>
    inline bool operator<(const optional<T> &, nullopt_t) noexcept { return false; }
    template<typename T>
    inline bool operator<(nullopt_t, const optional<T> &rhs) noexcept { return static_cast<bool>(rhs); }
    template<typename T>
    inline bool operator<=(const optional<T> &lhs, nullopt_t) noexcept { return !static_cast<bool>(lhs); }
    template<typename T>
    inline bool operator<=(nullopt_t, const optional<T> &) noexcept { return true; }
    template<typename T>
    inline bool operator>(const optional<T> &lhs, nullopt_t) noexcept { return static_cast<bool>(lhs); }
    template<typename T>
    inline bool operator>(nullopt_t, const optional<T> &) noexcept { return false; }
    template<typename T>
    inline bool operator>=(const optional<T> &, nullopt_t) noexcept { return true; }
    template<typename T>
    inline bool operator>=(nullopt_t, const optional<T> &rhs) noexcept { return !static_cast<bool>(rhs); }
    template<typename T>
    inline bool operator==(const optional<T> &lhs, const T &rhs) { return static_cast<bool>(lhs) ? *lhs == rhs : false; }
    template<typename T>
    inline bool operator==(const T &lhs, const optional<T> &rhs) { return static_cast<bool>(rhs) ? *rhs == lhs : false; }
    template<typename T>
    inline bool operator!=(const optional<T> &lhs, const T &rhs) { return static_cast<bool>(lhs) ? !(*lhs == rhs) : true; }
    template<typename T>
    inline bool operator!=(const T &lhs, const optional<T> &rhs) { return static_cast<bool>(rhs) ? !(*rhs == lhs) : true; }
    template<typename T>
    inline bool operator<(const optional<T> &lhs, const T &rhs) { return static_cast<bool>(lhs) ? std::less<T>{}(*lhs, rhs) : true; }
    template<typename T>
    inline bool operator<(const T &lhs, const optional<T> &rhs) { return static_cast<bool>(rhs) ? std::less<T>{}(lhs, *rhs) : false; }
    template<typename T>
    inline bool operator<=(const optional<T> &lhs, const T &rhs) { return !(lhs > rhs); }
    template<typename T>
    inline bool operator<=(const T &lhs, const optional<T> &rhs) { return !(lhs > rhs); }
    template<typename T>
    inline bool operator>(const optional<T> &lhs, const T &rhs) { return static_cast<bool>(lhs) ? rhs < lhs : false; }
    template<typename T>
    inline bool operator>(const T &lhs, const optional<T> &rhs) { return static_cast<bool>(rhs) ? rhs < lhs : true; }
    template<typename T>
    inline bool operator>=(const optional<T> &lhs, const T &rhs) { return !(lhs < rhs); }
    template<typename T>
    inline bool operator>=(const T &lhs, const optional<T> &rhs) { return !(lhs < rhs); }
    template<typename T>

    inline void swap(optional<T> &lhs, optional<T> &rhs) noexcept(noexcept(lhs.swap(rhs))) { lhs.swap(rhs); }
    template<typename T>
    inline optional<typename std::decay<T>::type> make_optional(T &&value) { return optional<typename std::decay<T>::type>(std::forward<T>(value)); }

} }

#endif
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
#include <string>

namespace argo {

    class Context;

}

namespace argo { namespace formatter {

    //!Formatter interface. The convention is for all output to end with a newline, except for
    //format_error
    class IFormatter
    {
    public:
        explicit IFormatter() = default;
        virtual ~IFormatter() = default;

        virtual std::string format_error(Context &context, const std::string &message) = 0;
        virtual std::string format_help(Context &context) = 0;
        virtual std::string format_version(Context &context) = 0;

    protected:
        using Txt = details::string::Text;
    };

    using Ptr = std::unique_ptr<IFormatter>;

} }

#endif

#ifndef HEADER_argo_handler_Option_hpp_INCLUDE_GUARD
#define HEADER_argo_handler_Option_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_Name_hpp_INCLUDE_GUARD
#define HEADER_argo_Name_hpp_INCLUDE_GUARD

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

#ifndef HEADER_argo_action_IAction_hpp_INCLUDE_GUARD
#define HEADER_argo_action_IAction_hpp_INCLUDE_GUARD

#include <string>

namespace argo {

    class Context;

}

namespace argo { namespace action {

    class IAction;
    using Ptr = std::unique_ptr<IAction>;

    class IAction
    {
    public:
        virtual ~IAction() = default;
        virtual Ptr clone() const = 0;
        virtual bool apply(Context &, const std::string &) = 0;
    };

} }

#endif

#ifndef HEADER_argo_details_log_hpp_INCLUDE_GUARD
#define HEADER_argo_details_log_hpp_INCLUDE_GUARD

#define C(expr) "(" << #expr << ":" << (expr) << ")"
#define S(state) static bool log_enabled_ = state
#define L(expr) if (log_enabled_) std::cout << "[TRACE] " << expr << std::endl;

#endif
#ifndef HEADER_argo_nargs_FixedNumber_hpp_INCLUDE_GUARD
#define HEADER_argo_nargs_FixedNumber_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_nargs_INArgs_hpp_INCLUDE_GUARD
#define HEADER_argo_nargs_INArgs_hpp_INCLUDE_GUARD

#include <string>

namespace argo { namespace nargs {

    class INargs;
    using Ptr = std::unique_ptr<INargs>;

    class INargs
    {
    public:
        virtual ~INargs() = default;

        unsigned int count() const { return count_; }
        void next() { ++count_; }
        virtual Ptr clone() const = 0;
        virtual bool must_have_next() = 0;
        virtual bool may_have_next() = 0;
        virtual std::string description() const = 0;

    protected:
        unsigned int count_ = 0;
    };

} }

#endif

#include <sstream>

namespace argo { namespace nargs {

    class FixedNumber: public INargs
    {
    public:
        explicit FixedNumber(const unsigned int max_count): max_count_(max_count) {}
        virtual Ptr clone() const override { return details::make_unique<FixedNumber>(max_count_); }
        virtual bool must_have_next() override { return count_ < max_count_; };
        virtual bool may_have_next() override { return must_have_next(); }
        virtual std::string description() const override
        {
            std::ostringstream os;
            if (0 == max_count_) os << "no arguments";
            else os << max_count_ << " argument" << (max_count_ > 1 ? "s" : "");
            return os.str();
        }

    private:
        unsigned int max_count_;
    };

} }

#endif

#ifndef HEADER_argo_nargs_OneOrMore_hpp_INCLUDE_GUARD
#define HEADER_argo_nargs_OneOrMore_hpp_INCLUDE_GUARD


namespace argo { namespace nargs {

    class OneOrMore: public INargs
    {
    public:
        virtual Ptr clone() const override { return details::make_unique<OneOrMore>(); }
        virtual bool must_have_next() override { return count_ == 0; };
        virtual bool may_have_next() override { return true; }
        virtual std::string description() const override { return "one or more arguments"; }
    };

} }

#endif

#ifndef HEADER_argo_nargs_Optional_hpp_INCLUDE_GUARD
#define HEADER_argo_nargs_Optional_hpp_INCLUDE_GUARD


namespace argo { namespace nargs {

    class Optional: public INargs
    {
    public:
        virtual Ptr clone() const override { return details::make_unique<Optional>(); }
        virtual bool must_have_next() override { return false; };
        virtual bool may_have_next() override { return count_ == 0; }
        virtual std::string description() const override { return "an optional argument"; }
    };

} }

#endif

#ifndef HEADER_argo_nargs_ZeroOrMore_hpp_INCLUDE_GUARD
#define HEADER_argo_nargs_ZeroOrMore_hpp_INCLUDE_GUARD


namespace argo { namespace nargs {

    class ZeroOrMore: public INargs
    {
    public:
        virtual Ptr clone() const override { return details::make_unique<ZeroOrMore>(); }
        virtual bool must_have_next() override { return false; };
        virtual bool may_have_next() override { return true; }
        virtual std::string description() const override { return "zero or more arguments"; }
    };

} }

#endif


namespace argo { namespace handler {

    //!Options are the final handlers of arguments
    class Option: public IHandler
    {
    public:
        explicit Option(const std::string &shorthand, const std::string &longhand) { is_valid_ = name_.shorthand(shorthand) && name_.longhand(longhand); }
        explicit Option(const std::string &short_or_longhand)
        {
            assert(short_or_longhand.size() >= 2);
            const auto first_char = short_or_longhand[0];
            const auto second_char = short_or_longhand[1];
            is_valid_ = (first_char == second_char) ? name_.longhand(short_or_longhand) : name_.shorthand(short_or_longhand);
            assert(!!is_valid_);
        }

        Name name() const { return name_; }
        const std::vector<action::Ptr> &actions() const { return actions_; }
        Option &action(const action::IAction &action) { actions_.push_back(action.clone()); return self_(true); }
        Option &nargs(nargs::Ptr &&ptr) { pnargs_ = std::move(ptr); return self_(true); }
        Option &nargs(const unsigned int count)
        {
            pnargs_ = details::make_unique<nargs::FixedNumber>(count);
            if (0 == count) is_toggle_ = true;
            return self_(true);
        }
        Option &nargs(const std::string &type)
        {
            S(false);
            const bool is_ok = true;
            if ("+" == type) pnargs_ = details::make_unique<nargs::OneOrMore>();
            else if ("*" == type) pnargs_ = details::make_unique<nargs::ZeroOrMore>();
            else if ("?" == type) pnargs_ = details::make_unique<nargs::Optional>();
            if (!!pnargs_) L(nargs().description());
            return self_(is_ok);
        }
        const nargs::INargs &nargs() const
        {
            S(false);
            if (!pnargs_)
            {
                L("Setting default nargs");
                pnargs_ = details::make_unique<nargs::FixedNumber>(1);
            }
            return *pnargs_;
        }
        nargs::INargs &nargs()
        {
            const auto &self = *this;
            return const_cast<nargs::INargs &>(self.nargs());
        }
        Option &toggle(const bool state = true)
        {
            is_toggle_ = state;
            if (state) return nargs(0);
            else return self_(true);
        }
        std::string help() const { return help_; }
        Option &help(const std::string &description) { help_ = description; return self_(true); }
        Option &required(const bool state = true) { is_required_ = state; return self_(true); }
        bool is_required() const { return is_required_; }

        virtual Ptr clone() const override
        {
            auto ptr = details::make_unique<Option>("", "");
            ptr->nr_selected_ = nr_selected_;
            ptr->is_valid_ = is_valid_;
            ptr->name_ = name_;
            for (const auto &paction: actions_)
            {
                assert(!!paction);
                ptr->actions_.push_back(paction->clone());
            }
            ptr->pnargs_ = pnargs_ ? pnargs_->clone() : nullptr;
            ptr->is_toggle_ = is_toggle_;
            ptr->help_ = help_;
            ptr->is_required_ = is_required_;
            return std::move(ptr);
        }
        virtual bool is_valid() const override
        {
            //L("Option valid?");
            //L(C(name()));
            //L(C(is_valid_));
            return is_valid_;
        }
        std::string hash() const override { return name_.hash(); }
        virtual bool recognizes(Context &context, const std::string &raw_arg) override
        {
            S(false);
            bool can_handle = false;
            if (!!name().shorthand() && *name().shorthand() == raw_arg) can_handle = true;
            else if (!!name().longhand())
            {
                if (*name().longhand() == raw_arg) can_handle = true;
                else if (context.is_guessing_allowed() && Name::guess_shorthand(*name().longhand()) == raw_arg) can_handle = true;
            }
            if (can_handle) context.set_option(*this);
            L("Option recognizes?");
            L(C(name()));
            L(C(can_handle));
            return can_handle;
        }
        virtual bool is_satisfied(Context &context) const override
        {
            MSS_BEGIN(bool);
            if (is_required())
            {
                MSS(!!nr_selected(),
                    {
                        std::ostringstream os;
                        os << "Option '" << name() << "' is required";
                        context.error(os.str());
                    });
            }
            MSS_END();
        }

        bool process(Context &context, RawList::iterator &current, RawList::iterator end)
        {
            MSS_BEGIN(bool);
            S(false);
            L("Processing argument");
            L(C(*current));
            ++current;
            while (true)
            {
                if (is_toggle_)
                {
                    L("Option is a toggle");
                    auto previous = current;
                    --previous;
                    MSS(action_apply_(context, *previous));
                    MSS_RETURN_OK();
                }
                else
                {
                    L("Checking if there must be a next value");
                    L(C(nargs().description()));
                    if (nargs().must_have_next())
                    {
                        L("Yes, there must be");
                        if (current == end)
                        {
                            L("But we reached the end!");
                            std::ostringstream os;
                            os << "Option '" << context.option().name() << "' expects " << context.option().nargs().description();
                            context.error(os.str());
                            MSS_RETURN_ERROR();
                        }
                        L("Let's apply the action");
                        MSS(action_apply_(context, current));
                    }
                    else if (nargs().may_have_next())
                    {
                        L("A next value is not mandatory, but allowed");
                        if (current == end)
                        {
                            L("But we reached the end!");
                            MSS_RETURN_OK();
                        }
                        if (Name::is_valid(*current)) MSS_RETURN_OK();
                        MSS(action_apply_(context, current));
                    }
                    else
                    {
                        L("A next value is not allowed");
                        MSS_RETURN_OK();
                    }
                }
            }
            L("Finished handling argument");
            MSS_END();
        }

    private:
        Option &self_(const bool is_valid)
        {
            is_valid_ = is_valid;
            return *this;
        }
        bool action_apply_(Context &context, const std::string &arg)
        {
            MSS_BEGIN(bool);
            S(false);
            L("Applying actions on argument");
            L(C(arg));
            for (const auto &paction: actions_)
            {
                MSS(paction->apply(context, arg));
            }
            ++context.result().nr_args;
            nargs().next();
            MSS_END();
        }
        bool action_apply_(Context &context, RawList::iterator &current)
        {
            MSS_BEGIN(bool);
            MSS(action_apply_(context, *current));
            ++current;
            MSS_END();
        }

        bool is_valid_ = true;
        Name name_;
        std::vector<action::Ptr> actions_;
        mutable nargs::Ptr pnargs_ = nullptr;
        bool is_toggle_ = false;
        std::string help_;
        bool is_required_ = false;
    };

    inline std::ostream &operator<<(std::ostream &os, const Option &option) { return option.name().print(os); }

} }

#endif

#ifndef HEADER_argo_handler_group_IGroup_hpp_INCLUDE_GUARD
#define HEADER_argo_handler_group_IGroup_hpp_INCLUDE_GUARD


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

#ifndef HEADER_argo_utility_hpp_INCLUDE_GUARD
#define HEADER_argo_utility_hpp_INCLUDE_GUARD

#include <algorithm>
#include <sstream>

namespace argo {

    template<typename Type, typename ConversionTraits>
    details::optional<Type> convert(Context &context, const std::string &value)
    {
        const details::optional<Type> res = ConversionTraits::run(value);
        if (!!res) return res;
        std::ostringstream os;
        os << "Option '" << context.option() << "' expects " << ConversionTraits::description << " (not '" << value << "')";
        context.error(os.str());
        return details::nullopt;
    }
    inline bool has_version(const program::Info &program) { return 0 != program.version.major + program.version.minor + program.version.patch; }
    inline unsigned int max_option_length(const std::vector<handler::Option *> &options)
    {
        unsigned int max = 0u;
        for (const auto &poption: options)
        {
            assert(!!poption);
            max = std::max<unsigned>(max, poption->name().str().size());
        }
        return max;
    }
    template<typename Handler>
    bool is_type(const handler::IHandler &handler)
    {
        const auto pb = &handler;
        return !!dynamic_cast<const Handler *>(pb);
    }
    inline std::string basename_of(const std::string &path)
    {
        return std::string(std::find_if(path.rbegin(), path.rend(), [](const char ch)
                    {
#if ARGO_TOOLSET_PLATFORM_WINDOWS
                    return '/' == ch || '\\' == ch;
#else
                    return '/' == ch;
#endif
                    }).base(), path.end());
    }

}

#endif


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

#ifndef HEADER_argo_ResponseFile_hpp_INCLUDE_GUARD
#define HEADER_argo_ResponseFile_hpp_INCLUDE_GUARD

#include <fstream>
#include <vector>

namespace argo {

    class ResponseFile
    {
    public:
        bool parse(const std::string &filename)
        {
            MSS_BEGIN(bool);
            filename_ = filename;
            std::ifstream stream(filename, std::ios_base::in);
            MSS(!stream.fail());
            std::string line;
            while (std::getline(stream, line))
            {
                details::string::ltrim(line);
                if (details::string::starts_with(line, "#")) continue;
                const auto args = details::string::split(line);
                std::copy(RANGE(args), std::back_inserter(argv_));
            }
            MSS_END();
        }
        std::string filename() const { return filename_; }
        int argc() const { return argv_.size(); }
        std::vector<std::string> argv() const { return argv_; }

    private:
        std::string filename_;
        std::vector<std::string> argv_;
    };

}

#endif

#ifndef HEADER_argo_Arguments_hpp_INCLUDE_GUARD
#define HEADER_argo_Arguments_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_action_Callback_hpp_INCLUDE_GUARD
#define HEADER_argo_action_Callback_hpp_INCLUDE_GUARD

#ifndef HEADER_argo_traits_conversion_hpp_INCLUDE_GUARD
#define HEADER_argo_traits_conversion_hpp_INCLUDE_GUARD

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

#include <functional>

namespace argo { namespace action {

    template<typename Type, typename ConversionTraits = traits::conversion<Type>>
    class Callback: public IAction
    {
    public:
        using callback_type = std::function<bool(const Type &)>;
        using callback_with_context_type = std::function<bool(Context &, const Type &)>;

        explicit Callback(const callback_type &callback): simple_(callback) {}
        explicit Callback(const callback_with_context_type &callback): extended_(callback) {}

        virtual Ptr clone() const override
        {
            if (!!simple_) return details::make_unique<Callback>(*simple_);
            assert(!!extended_);
            return details::make_unique<Callback>(*extended_);
        }
        virtual bool apply(Context &context, const std::string &value) override
        {
            MSS_BEGIN(bool);
            //if (!!simple_) L("Invoking simple callback");
            //else trace("Invoking extended callback");
            //trace(C(value));
            const auto res = convert<Type, ConversionTraits>(context, value);
            MSS(!!res);
            MSS(!!simple_ ? (*simple_)(*res) : (*extended_)(context, *res),
                {
                    std::ostringstream os;
                    os << "Could not process '" << context.option() << "'";
                    context.error(os.str());
                });
            MSS_END();
        }

    private:
        details::optional<callback_type> simple_;
        details::optional<callback_with_context_type> extended_;
    };

    template<typename Type, typename ConversionTraits = traits::conversion<Type>>
    Callback<Type, ConversionTraits> callback(typename Callback<Type, ConversionTraits>::callback_type &cb) { return Callback<Type, ConversionTraits>{cb}; }
    inline Callback<std::string> callback(const std::function<bool(const std::string &)> &cb) { return Callback<std::string>{cb}; }
    inline Callback<std::string> callback(const std::function<bool()> &cb)
    {
        auto wrapper = [cb](const std::string &){ return cb(); };
        return Callback<std::string>{wrapper};
    }

    template<typename Type, typename ConversionTraits = traits::conversion<Type>>
    Callback<Type, ConversionTraits> callback(typename Callback<Type, ConversionTraits>::callback_type_with_context &cb) { return Callback<Type, ConversionTraits>{cb}; }
    inline Callback<std::string> callback(const std::function<bool(Context &, const std::string &)> &cb) { return Callback<std::string>{cb}; }
    inline Callback<std::string> callback(const std::function<bool(Context &)> &cb)
    {
        auto wrapper = [cb](Context &context, const std::string &) { return cb(context); };
        return Callback<std::string>{wrapper};
    }

} }

#endif

#ifndef HEADER_argo_details_raii_hpp_INCLUDE_GUARD
#define HEADER_argo_details_raii_hpp_INCLUDE_GUARD

#include <functional>

namespace argo {
    
    namespace details {

        template<typename ConstructionCB, typename DestructionCB>
        class raii
        {
        public:
            explicit raii(const ConstructionCB on_construction, const DestructionCB on_destruction): on_destruction_(on_destruction) { on_construction(); }
            raii(const raii &) = delete;
            raii &operator=(const raii &) = delete;
            raii(raii &&other): on_destruction_(other.on_destruction_) { other.run_destruction_ = false; }
            raii &operator=(raii &&) = delete;
            ~raii() { if (run_destruction_) on_destruction_(); }

        private:
            bool run_destruction_ = true;
            DestructionCB on_destruction_;
        };

    }

    template<typename ConstructionCB, typename DestructionCB>
    details::raii<ConstructionCB, DestructionCB> make_raii(const ConstructionCB &on_construction, const DestructionCB &on_destruction) { return details::raii<ConstructionCB, DestructionCB>(on_construction, on_destruction); }

    template<typename DestructionCB>
    details::raii<std::function<void()>, DestructionCB> make_raii(const DestructionCB &on_destruction) { return details::raii<std::function<void()>, DestructionCB>([](){}, on_destruction); }

}

#endif
#ifndef HEADER_argo_formatter_Default_hpp_INCLUDE_GUARD
#define HEADER_argo_formatter_Default_hpp_INCLUDE_GUARD

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

#ifndef HEADER_argo_handler_group_Plain_hpp_INCLUDE_GUARD
#define HEADER_argo_handler_group_Plain_hpp_INCLUDE_GUARD


namespace argo { namespace handler { namespace group {

    //!Group that merely serves as a collection of options, with no additional properties
    class Plain: public IGroup
    {
    public:
        explicit Plain(const std::string &group_name): IGroup(group_name) {}

        virtual Ptr clone() const override
        {
            auto ptr = details::make_unique<Plain>(name_);
            ptr->nr_selected_ = nr_selected_;
            ptr->hash_ = hash_;
            ptr->help_ = help_;
            ptr->is_required_ = is_required_;
            ptr->handlers_ = handlers_;
#if ARGO_TOOLSET_COMPILER_GCC_OLD
            return std::move(ptr);
#else
            return ptr;
#endif
        }
        virtual bool recognizes(Context &context, const std::string &raw_arg) override { return std::any_of(RANGE(handlers_), [&](handler::IHandler &handler){ return handler.can_handle(context, raw_arg); }); }
        virtual std::string description() const override { return ""; }
    };

} } }

#endif

#ifndef HEADER_argo_handler_group_Exclusive_hpp_INCLUDE_GUARD
#define HEADER_argo_handler_group_Exclusive_hpp_INCLUDE_GUARD

#include <string>

namespace argo { namespace handler { namespace group {

    //!Exclusive groups: the presence of any one option/group within it, excludes the presence of the others
    class Exclusive: public IGroup
    {
    public:
        explicit Exclusive(const std::string &group_name): IGroup(group_name) {}

        virtual Ptr clone() const override
        {
            auto ptr = details::make_unique<Exclusive>(name_);
            ptr->nr_selected_ = nr_selected_;
            ptr->hash_ = hash_;
            ptr->help_ = help_;
            ptr->is_required_ = is_required_;
            ptr->handlers_ = handlers_;
            ptr->previous_option_name_ = previous_option_name_;
#if ARGO_TOOLSET_COMPILER_GCC_OLD
            return std::move(ptr);
#else
            return ptr;
#endif
        }
        virtual bool recognizes(Context &context, const std::string &raw_arg) override 
        {
            MSS_BEGIN(bool);
            S(false);
            L("Recognizing?");
            L(C(raw_arg));
            L(C(name()));
            if (!std::any_of(RANGE(handlers_), [&](handler::IHandler &handler){ return handler.can_handle(context, raw_arg); })) MSS_RETURN_ERROR();
            if (!!previous_option_name_)
            {
                L("Yes, but this conflicts!");
                std::ostringstream os;
                os << "Previously used option '" << *previous_option_name_ << "' excludes use of '" << raw_arg << "'";
                context.error(os.str());
                MSS_RETURN_ERROR();
            }
            previous_option_name_ = context.option().name();
            MSS_END();
        }
        virtual std::string description() const override { return "mutually exclusive"; }

    private:
        details::optional<Name> previous_option_name_;
    };

} } }

#endif


#ifndef HEADER_argo_handler_group_Inclusive_hpp_INCLUDE_GUARD
#define HEADER_argo_handler_group_Inclusive_hpp_INCLUDE_GUARD


namespace argo { namespace handler { namespace group {

    //!Inclusive groups: the presence of any one option/group within it, forces the presence of the others
    class Inclusive: public IGroup
    {
    public:
        explicit Inclusive(const std::string &group_name): IGroup(group_name) {}

        virtual Ptr clone() const override
        {
            auto ptr = details::make_unique<Inclusive>(name_);
            ptr->nr_selected_ = nr_selected_;
            ptr->hash_ = hash_;
            ptr->help_ = help_;
            ptr->is_required_ = is_required_;
            ptr->handlers_ = handlers_;
#if ARGO_TOOLSET_COMPILER_GCC_OLD
            return std::move(ptr);
#else
            return ptr;
#endif
        }
        virtual bool recognizes(Context &context, const std::string &raw_arg) override { return std::any_of(RANGE(handlers_), [&](handler::IHandler &handler){ return handler.can_handle(context, raw_arg); }); }
        virtual bool is_satisfied(Context &context) const override
        {
            MSS_BEGIN(bool);
            S(false);
            L("Satisfied?");
            L(C(name()));
            std::ostringstream os;
            if (0 == nr_selected()) MSS_RETURN_OK();
            for (const auto &handler: handlers_)
            {
                if (is_type<handler::Option>(handler))
                {
                    const auto &option = static_cast<const handler::Option &>(handler);
                    if (1 == option.nr_selected()) continue;
                    os << "Missing option '" << option << "'";
                    context.error(os.str());
                    MSS_RETURN_ERROR();
                }
                else if (is_type<handler::group::Plain>(handler))
                {
                    const auto &group = static_cast<const handler::group::Plain &>(handler);
                    if (group.size() == group.nr_selected()) continue;
                    os << "Missing an option from group '" << group.name() << "'";
                    context.error(os.str());
                    MSS_RETURN_ERROR();
                }
                else if (is_type<handler::group::Exclusive>(handler))
                {
                    const auto &group = static_cast<const handler::group::Exclusive &>(handler);
                    if (1 == group.nr_selected()) continue;
                    L(C(group.nr_selected()));
                    os << "Missing an option from group '" << group.name() << "'";
                    context.error(os.str());
                    MSS_RETURN_ERROR();
                }
                else if (is_type<handler::group::Inclusive>(handler))
                {
                    const auto &inclusive = static_cast<const handler::group::Inclusive &>(handler);
                    MSS(inclusive.is_satisfied(context));
                }
            }
            MSS_END();
        }
        virtual std::string description() const override { return "mutually inclusive"; }
    };

} } }

#endif


#ifndef HEADER_argo_action_Store_hpp_INCLUDE_GUARD
#define HEADER_argo_action_Store_hpp_INCLUDE_GUARD


namespace argo { namespace action {

    template<typename Type, typename ConversionTraits = traits::conversion<Type>>
    Callback<Type, ConversionTraits> store(Type &destination) { return Callback<Type, ConversionTraits>([&destination](const Type &value){ destination = value; return true; }); }
    template<typename Type, typename ConversionTraits = traits::conversion<Type>>
    Callback<Type, ConversionTraits> store(std::vector<Type> &destination) { return Callback<Type, ConversionTraits>([&destination](const Type &value){ destination.push_back(value); return true; }); }
    template<typename Type, typename ConstType, typename ConversionTraits = traits::conversion<std::string>, typename = typename std::enable_if<std::is_convertible<ConstType, Type>::value>::type>
    Callback<std::string, ConversionTraits> store_const(Type &destination, ConstType value) { return Callback<std::string, ConversionTraits>{[&destination, value](const std::string &){ destination = static_cast<Type>(value); return true; }}; }

} }

#endif

#ifndef HEADER_argo_action_Print_hpp_INCLUDE_GUARD
#define HEADER_argo_action_Print_hpp_INCLUDE_GUARD

#include <iostream>

namespace argo { namespace action {

    class Print: public IAction
    {
    public:
        explicit Print(std::ostream &os = std::cout): os_(os) {}

        virtual Ptr clone() const override { return details::make_unique<Print>(os_); }
        virtual bool apply(Context &context, const std::string &value) override
        {
            MSS_BEGIN(bool);
            os_ << context.option() << ": " << value << std::endl;
            MSS_END();
        }

    private:
        std::ostream &os_;
    };

    template<typename... Args>
    Print print(Args &&... args) { return Print{std::forward<Args>(args)...}; }

} }

#endif

#ifndef HEADER_argo_details_config_version_hpp_INCLUDE_GUARD
#define HEADER_argo_details_config_version_hpp_INCLUDE_GUARD

//This file is generated by CMake

namespace argo { namespace details { namespace config {

    static constexpr char version[] = "0.1.0";

} } }

#endif
