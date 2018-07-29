#ifndef HEADER_argo_nargs_Optional_hpp_INCLUDE_GUARD
#define HEADER_argo_nargs_Optional_hpp_INCLUDE_GUARD

#include "argo/nargs/INArgs.hpp"

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

