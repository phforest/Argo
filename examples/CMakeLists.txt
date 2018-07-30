cmake_minimum_required(VERSION 3.0)

project(ArgoExamples)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_LIST_DIR}/*_*.cpp")
foreach(SOURCE ${SOURCES})
    get_filename_component(NAME ${SOURCE} NAME_WE)
    message(STATUS "Defining executable ${NAME}")
    add_executable(${NAME} ${SOURCE})
    target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../single_include)
endforeach()

