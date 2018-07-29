#ifndef HEADER_argo_action_Callback_hpp_INCLUDE_GUARD
#define HEADER_argo_action_Callback_hpp_INCLUDE_GUARD

#include "argo/Context.hpp"
#include "argo/action/IAction.hpp"
#include "argo/details/log.hpp"
#include "argo/details/mss.hpp"
#include "argo/details/optional.hpp"
#include "argo/traits/conversion.hpp"
#include "argo/utility.hpp"
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

