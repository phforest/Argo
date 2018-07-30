#ifndef HEADER_argo_details_config_toolset_hpp_INCLUDE_GUARD
#define HEADER_argo_details_config_toolset_hpp_INCLUDE_GUARD

//Compiler
#if defined(__clang__)
#define ARGO_TOOLSET_COMPILER "clang"
#define ARGO_TOOLSET_COMPILER_CLANG 1
#define ARGO_TOOLSET_COMPILER_VERSION_MAJOR __clang_major__
#define ARGO_TOOLSET_COMPILER_VERSION_MINOR __clang_minor__
#define ARGO_TOOLSET_COMPILER_VERSION_PATCH __clang_patchlevel__
#elif defined(__GNUC__)
#define ARGO_TOOLSET_COMPILER "gcc"
#define ARGO_TOOLSET_COMPILER_GCC 1
#define ARGO_TOOLSET_COMPILER_VERSION_MAJOR __GNUC__
#define ARGO_TOOLSET_COMPILER_VERSION_MINOR __GNUC_MINOR__
#define ARGO_TOOLSET_COMPILER_VERSION_PATCH __GNUC_PATCHLEVEL__
#if ARGO_TOOLSET_COMPILER_VERSION_MAJOR < 5
#define ARGO_TOOLSET_COMPILER_GCC_OLD 1
#endif
#elif defined(_MSC_VER)
#define ARGO_TOOLSET_COMPILER "msvc"
#define ARGO_TOOLSET_COMPILER_MSVC 1
#if _MSC_VER >= 1910 // (MSVC++ 15.0 - Visual Studio 2017)
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2017 1
#elif _MSC_VER == 1900 // (MSVC++ 14.0 - Visual Studio 2015)
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2015 1
#elif _MSC_VER == 1800 // (MSVC++ 12.0 - Visual Studio 2013)
#define ARGO_TOOLSET_COMPILER_MSVC_VS_2013 1
#else
#error "Unsupported toolset: unsupported Visual Studio version"
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
