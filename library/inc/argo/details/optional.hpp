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
