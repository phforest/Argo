cmake_minimum_required(VERSION 3.5)

#TODO: Add EnableSanitizers.cmake

project(Argo LANGUAGES CXX VERSION 0.1.0)

option(ARGO_SKIP_TESTS "Skips unit-tests" FALSE)
option(ARGO_STATIC_LIBRARY "Builds a static library instead of a header-only library" FALSE)

set(ARGO_CXX_STANDARD 11)

configure_file(${CMAKE_CURRENT_LIST_DIR}/cmake/version.hpp.in ${CMAKE_CURRENT_LIST_DIR}/library/inc/argo/details/config/version.hpp)
if(ARGO_STATIC_LIBRARY)
    add_library(Argo STATIC ${CMAKE_CURRENT_LIST_DIR}/library/src/argo/Context.cpp)
    target_include_directories(Argo PUBLIC ${CMAKE_CURRENT_LIST_DIR}/library/inc/)
    set_target_properties(Argo PROPERTIES CXX_STANDARD ${ARGO_CXX_STANDARD})
    target_compile_definitions(Argo PRIVATE ARGO_BUILD_STATIC_LIBRARY=1)
else()
    add_library(Argo INTERFACE)
    target_include_directories(Argo INTERFACE ${CMAKE_CURRENT_LIST_DIR}/single_include/)
endif()

if(NOT ARGO_SKIP_TESTS)
    include(ExternalProject)
    find_package(Git REQUIRED)
    ExternalProject_Add(Catch2
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/extern/Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        TIMEOUT 10
        UPDATE_COMMAND ${GIT_EXECUTABLE} pull
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        LOG_DOWNLOAD ON
    )

    configure_file(${CMAKE_CURRENT_LIST_DIR}/cmake/reflection.hpp.in ${CMAKE_CURRENT_LIST_DIR}/test/argo/test/reflection.hpp)
    file(GLOB_RECURSE SOURCES test/*.cpp test/*.hpp)
    add_executable(Argo-tests ${SOURCES})
    add_dependencies(Argo-tests Catch2)
    target_include_directories(Argo-tests PRIVATE test/ ${CMAKE_CURRENT_BINARY_DIR}/extern/Catch2/src/Catch2/single_include)
    target_link_libraries(Argo-tests PRIVATE Argo)
    set_target_properties(Argo-tests PROPERTIES CXX_STANDARD ${ARGO_CXX_STANDARD})
endif()
