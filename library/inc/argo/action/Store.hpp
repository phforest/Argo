#ifndef HEADER_argo_action_Store_hpp_INCLUDE_GUARD
#define HEADER_argo_action_Store_hpp_INCLUDE_GUARD

#include "argo/action/Callback.hpp"

namespace argo { namespace action {

    template<typename Type, typename ConversionTraits = traits::conversion<Type>>
    Callback<Type, ConversionTraits> store(Type &destination) { return Callback<Type, ConversionTraits>([&destination](const Type &value){ destination = value; return true; }); }
    template<typename Type, typename ConversionTraits = traits::conversion<Type>>
    Callback<Type, ConversionTraits> store(std::vector<Type> &destination) { return Callback<Type, ConversionTraits>([&destination](const Type &value){ destination.push_back(value); return true; }); }
    template<typename Type, typename ConstType, typename ConversionTraits = traits::conversion<std::string>, typename = typename std::enable_if<std::is_convertible<ConstType, Type>::value>::type>
    Callback<std::string, ConversionTraits> store_const(Type &destination, ConstType value) { return Callback<std::string, ConversionTraits>{[&destination, value](const std::string &){ destination = static_cast<Type>(value); return true; }}; }

} }

#endif

