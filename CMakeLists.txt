cmake_minimum_required(VERSION 3.22)

# Top level CMake script for building CSTL.
# Author: Igor Lesik 2023

project(CSTL
    VERSION 0.1.0
    DESCRIPTION "C STL-like library"
    LANGUAGES C
)

#set(CMAKE_C_STANDARD 23)
#set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

#if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
#    # require at least gcc 13.1
#    set(GCC_MIN_VER "13.1")
#    if (CMAKE_C_COMPILER_VERSION VERSION_LESS GCC_MIN_VER)
#        message(FATAL_ERROR
#            "GCC version must be at least ${GCC_MIN_VER}! found ${CMAKE_C_COMPILER_VERSION}")
#    endif()
#endif()

set(CMAKE_C_FLAGS "-std=gnu17 -O3 -Wall -Werror")

include_directories(./include)

# Install inside the build directory.
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

enable_testing()

add_subdirectory(test)
