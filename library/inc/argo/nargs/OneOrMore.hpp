#ifndef HEADER_argo_nargs_OneOrMore_hpp_INCLUDE_GUARD
#define HEADER_argo_nargs_OneOrMore_hpp_INCLUDE_GUARD

#include "argo/nargs/INArgs.hpp"

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

