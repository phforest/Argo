#ifndef HEADER_argo_details_raii_hpp_INCLUDE_GUARD
#define HEADER_argo_details_raii_hpp_INCLUDE_GUARD

#include <functional>

namespace argo {
    
    namespace details {

        template<typename ConstructionCB, typename DestructionCB>
        class raii
        {
        public:
            explicit raii(const ConstructionCB on_construction, const DestructionCB on_destruction): on_destruction_(on_destruction) { on_construction(); }
            raii(const raii &) = delete;
            raii &operator=(const raii &) = delete;
            raii(raii &&other): on_destruction_(other.on_destruction_) { other.run_destruction_ = false; }
            raii &operator=(raii &&) = delete;
            ~raii() { if (run_destruction_) on_destruction_(); }

        private:
            bool run_destruction_ = true;
            DestructionCB on_destruction_;
        };

    }

    template<typename ConstructionCB, typename DestructionCB>
    details::raii<ConstructionCB, DestructionCB> make_raii(const ConstructionCB &on_construction, const DestructionCB &on_destruction) { return details::raii<ConstructionCB, DestructionCB>(on_construction, on_destruction); }

    template<typename DestructionCB>
    details::raii<std::function<void()>, DestructionCB> make_raii(const DestructionCB &on_destruction) { return details::raii<std::function<void()>, DestructionCB>([](){}, on_destruction); }

}

#endif
