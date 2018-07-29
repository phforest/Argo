#ifndef HEADER_argo_nargs_FixedNumber_hpp_INCLUDE_GUARD
#define HEADER_argo_nargs_FixedNumber_hpp_INCLUDE_GUARD

#include "argo/nargs/INArgs.hpp"
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

