#ifndef HEADER_argo_details_mss_hpp_INCLUDE_GUARD
#define HEADER_argo_details_mss_hpp_INCLUDE_GUARD

#include "argo/details/config/toolset.hpp"
#include <iostream>

#define MSS_GET_ARG_1_(args) MSS_GET_ARG_1 args
#define MSS_GET_ARG_1(N, ...) N
#define MSS_GET_ARG_2_(args) MSS_GET_ARG_2 args
#define MSS_GET_ARG_2(_1, N, ...) N
#define MSS_GET_ARG_3_(args) MSS_GET_ARG_3 args
#define MSS_GET_ARG_3(_1, _2, N, ...) N

#ifdef MSS_BEGIN
#error "MSS_BEGIN already defined"
#endif
#define MSS_BEGIN(type) using mss_type = type

#ifdef MSS_RETURN_OK
#error "MSS_RETURN_OK already defined"
#endif
#define MSS_RETURN_OK() return true

#ifdef MSS_RETURN_ERROR
#error "MSS_RETURN_ERROR already defined"
#endif
#define MSS_RETURN_ERROR() return false

#ifdef MSS_END
#error "MSS_END already defined"
#endif
#define MSS_END() MSS_RETURN_OK();

//#define MSS_PRINT_TRACEBACK

#ifdef MSS
#error "MSS already defined"
#endif
#if MSS_PRINT_TRACEBACK
#define MSS_LOG_TRACEBACK(expr, file, line) std::cerr << "[MSS FAILURE] " << file << ":" << line << ": " << expr << std::endl;
#else
#define MSS_LOG_TRACEBACK(...) 
#endif
#define MSS_1(expr) \
    { \
        mss_type mss_res = (expr); \
        if (!mss_res) \
        { \
            MSS_LOG_TRACEBACK(#expr, __FILE__, __LINE__) \
            return false; \
        } \
    }
#define MSS_2(expr, block) \
    { \
        mss_type mss_res = (expr); \
        if (!mss_res) \
        { \
            MSS_LOG_TRACEBACK(#expr, __FILE__, __LINE__) \
            block; \
            return false; \
        } \
    }
#define MSS(...) MSS_GET_ARG_3_((__VA_ARGS__, MSS_2, MSS_1))(__VA_ARGS__)

#ifdef MSS_Q
#error "MSS_Q already defined"
#endif
#define MSS_Q_1(expr) \
    { \
        mss_type mss_res = (expr); \
        if (!mss_res) return false; \
    }
#define MSS_Q_2(expr, block) \
    { \
        mss_type mss_res = (expr); \
        if (!mss_res) \
        { \
            block; \
            return false; \
        } \
    }
#define MSS_Q(...) MSS_GET_ARG_3_((__VA_ARGS__, MSS_Q_2, MSS_Q_1))(__VA_ARGS__)

#endif
