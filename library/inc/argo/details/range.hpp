#ifndef HEADER_argo_details_range_hpp_INCLUDE_GUARD
#define HEADER_argo_details_range_hpp_INCLUDE_GUARD

#ifdef RANGE
#error RANGE macro already defined
#endif
#define RANGE(container) (std::begin(container)), (std::end(container))

#endif
