cmake_minimum_required (VERSION 2.6)

project (HEATSIM)
set (HEATSIM_VERSION_MAJOR 0)
set (HEATSIM_VERSION_MINOR 1)

find_library(LAPACK_LIB
NAMES
    lapack
PATHS
    ENV LAPACK
    /usr/lib
    /usr/local/lib
    c:/libraries/lib
    ENV LAPACK
)

if(NOT EXISTS ${LAPACK_LIB})
    message("** Error finding heatSim required library:")
    message("**   Try setting the LAPACK environtment variable")
    message("**   to the directory containing lapack")
    message(FATAL_ERROR "** heatSim requires the LAPACK libary")
endif()

find_library(BLAS_LIB
NAMES
    blas
PATHS
    /usr/lib
    /usr/local/lib
    c:/libraries/lib
    ENV BLAS
PATHS_SUFFIXES
    lib
)

if(NOT EXISTS ${BLAS_LIB})
    message("** Error finding heatSim required library:")
    message("**   Try setting the BLAS environtment variable")
    message("**   to the directory containing blas")
    message(FATAL_ERROR "** heatSim requires the BLAS libary")
endif()

find_library(LIBF2C_LIB
NAMES
    libf2c
PATHS
    /usr/lib
    /usr/local/lib
    c:/libraries/lib
    ENV BLAS
PATHS_SUFFIXES
    lib
)


configure_file (
  "${HEATSIM_SOURCE_DIR}/config.h.in"
  "${HEATSIM_BINARY_DIR}/config.h"
)

INCLUDE_DIRECTORIES(${HEATSIM_BINARY_DIR} ${HEATSIM_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${HEATSIM_BINARY_DIR}/bin)

add_subdirectory(src)
