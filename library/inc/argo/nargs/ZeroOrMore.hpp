#ifndef HEADER_argo_nargs_ZeroOrMore_hpp_INCLUDE_GUARD
#define HEADER_argo_nargs_ZeroOrMore_hpp_INCLUDE_GUARD

#include "argo/nargs/INArgs.hpp"

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

