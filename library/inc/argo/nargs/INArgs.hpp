#ifndef HEADER_argo_nargs_INArgs_hpp_INCLUDE_GUARD
#define HEADER_argo_nargs_INArgs_hpp_INCLUDE_GUARD

#include "argo/details/memory.hpp"
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

