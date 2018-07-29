#ifndef HEADER_argo_details_config_toolset_hpp_INCLUDE_GUARD
#define HEADER_argo_details_config_toolset_hpp_INCLUDE_GUARD

//Compiler
#if defined(__clang__)
#define ARGO_TOOLSET_COMPILER "clang"
#define ARGO_TOOLSET_COMPILER_CLANG 1
#elif defined(__GNUC__)
#define ARGO_TOOLSET_COMPILER "gcc"
#define ARGO_TOOLSET_COMPILER_GCC 1
#elif defined(_MSC_VER)
#define ARGO_TOOLSET_COMPILER "msvc"
#define ARGO_TOOLSET_COMPILER_MSVC 1
#if _MSC_VER >= 1910 // (MSVC++ 15.0 - Visual Studio 2017)
#define ARGO_TOOLSET_COMPILER_MSVC_1910 1
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2017 1
#elif _MSC_VER == 1900 // (MSVC++ 14.0 - Visual Studio 2015)
#define ARGO_TOOLSET_COMPILER_MSVC_1900 1
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2015 1
#elif _MSC_VER == 1800 // (MSVC++ 12.0 - Visual Studio 2013)
#define ARGO_TOOLSET_COMPILER_MSVC_1800 1
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2013 1
#elif _MSC_VER == 1700 // (MSVC++ 11.0 - Visual Studio 2012)
#define ARGO_TOOLSET_COMPILER_MSVC_1700 1
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2012 1
#elif _MSC_VER == 1600 // (MSVC++ 10.0 - Visual Studio 2010)
#define ARGO_TOOLSET_COMPILER_MSVC_1600 1
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2010 1
#elif _MSC_VER == 1500 // (MSVC++  9.0 - Visual Studio 2008)
#define ARGO_TOOLSET_COMPILER_MSVC_1500 1
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2008 1
#elif _MSC_VER == 1400 // (MSVC++  8.0 - Visual Studio 2005)
#define ARGO_TOOLSET_COMPILER_MSVC_1400 1
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2005 1
#elif _MSC_VER == 1310 // (MSVC++  7.1 - Visual Studio 2003)
#define ARGO_TOOLSET_COMPILER_MSVC_1310 1
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2003 1
#elif _MSC_VER == 1300 // (MSVC++  7.0)
#define ARGO_TOOLSET_COMPILER_MSVC_1300 1
#elif _MSC_VER == 1200 // (MSVC++  6.0)
#define ARGO_TOOLSET_COMPILER_MSVC_1200 1
#elif _MSC_VER == 1100 // (MSVC++  5.0)
#define ARGO_TOOLSET_COMPILER_MSVC_1100 1
#else
#error "Unsupported toolset: unexpected _MSC_VER value"
#endif
#else
#error "Unsupported toolset: unknown compiler"
#endif

//Platform
#if defined(__ANDROID__)
#define ARGO_TOOLSET_PLATFORM "android"
#define ARGO_TOOLSET_PLATFORM_ANDROID 1
#elif defined(__linux__)
#define ARGO_TOOLSET_PLATFORM "linux"
#define ARGO_TOOLSET_PLATFORM_LINUX 1
#define ARGO_TOOLSET_PLATFORM_POSIX 1
#elif defined(__APPLE__)  
#define ARGO_TOOLSET_PLATFORM "apple"
#define ARGO_TOOLSET_PLATFORM_APPLE 1
#define ARGO_TOOLSET_PLATFORM_POSIX 1
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__) 
#define ARGO_TOOLSET_PLATFORM "windows"
#define ARGO_TOOLSET_PLATFORM_WINDOWS 1
#else
#error "Unsupported toolset: unknown platform"
#endif 

//C++ Standard
#if ARGO_TOOLSET_COMPILER_GCC || ARGO_TOOLSET_COMPILER_CLANG
#if __cplusplus == 199711L
#define ARGO_TOOLSET_CPP_STD 3
#define ARGO_TOOLSET_CPP_STD_03 1
#elif __cplusplus == 201402L
#define ARGO_TOOLSET_CPP_STD 14
#define ARGO_TOOLSET_CPP_STD_14 1
#elif __cplusplus == 201703L
#define ARGO_TOOLSET_CPP_STD 17
#define ARGO_TOOLSET_CPP_STD_17 1
#elif __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X)
#define ARGO_TOOLSET_CPP_STD 11
#define ARGO_TOOLSET_CPP_STD_11 1
#elif ARGO_TOOLSET_COMPILER_MSVC
#if ARGO_TOOLSET_COMPILER_MSVC_VS_2017
#if _MSVC_LANG == 201703
#define ARGO_TOOLSET_CPP_STD 17
#define ARGO_TOOLSET_CPP_STD_17 1
#else
#define ARGO_TOOLSET_CPP_STD 14
#define ARGO_TOOLSET_CPP_STD_14 1
#endif
#elif ARGO_TOOLSET_COMPILER_MSVC_VS_2015
#define ARGO_TOOLSET_CPP_STD 11
#define ARGO_TOOLSET_CPP_STD_11 1
#elif ARGO_TOOLSET_COMPILER_MSVC_VS_2013
#define ARGO_TOOLSET_CPP_STD 11
#define ARGO_TOOLSET_CPP_STD_11 1
#elif ARGO_TOOLSET_COMPILER_MSVC_VS_2010
#define ARGO_TOOLSET_CPP_STD 3
#define ARGO_TOOLSET_CPP_STD_03 1
#elif ARGO_TOOLSET_COMPILER_MSVC_VS_2008
#define ARGO_TOOLSET_CPP_STD 3
#define ARGO_TOOLSET_CPP_STD_03 1
#else
#define ARGO_TOOLSET_CPP_STD 3
#define ARGO_TOOLSET_CPP_STD_03 1
#endif
#else
#error "Unsupported toolset: unknown C++ standard"
#endif
#endif

//Debug/Release
#if !defined(NDEBUG)
#define ARGO_TOOLSET_DEBUG 1
#else
#define ARGO_TOOLSET_RELEASE 1
#endif

#endif
