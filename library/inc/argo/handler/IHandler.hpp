#ifndef HEADER_argo_handler_IHandler_hpp_INCLUDE_GUARD
#define HEADER_argo_handler_IHandler_hpp_INCLUDE_GUARD

#include "argo/Context.hpp"
#include "argo/RawList.hpp"
#include "argo/details/memory.hpp"
#include "argo/details/mss.hpp"

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

