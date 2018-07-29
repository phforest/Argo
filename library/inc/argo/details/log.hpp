#ifndef HEADER_argo_details_log_hpp_INCLUDE_GUARD
#define HEADER_argo_details_log_hpp_INCLUDE_GUARD

#define C(expr) "(" << #expr << ":" << (expr) << ")"
#define S(state) static bool log_enabled_ = state
#define L(expr) if (log_enabled_) std::cout << "[TRACE] " << expr << std::endl;

#endif
