#ifndef HEADER_argo_details_memory_hpp_INCLUDE_GUARD
#define HEADER_argo_details_memory_hpp_INCLUDE_GUARD

#include <memory>

namespace argo { namespace details {

    template <typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args &&... args) { return std::unique_ptr<T>(new T(std::forward<Args>(args)...)); }

} }

#endif
