cmake_minimum_required (VERSION 2.6)

project (HEATSIM)
set (HEATSIM_VERSION_MAJOR 0)
set (HEATSIM_VERSION_MINOR 1)

configure_file (
  "${HEATSIM_SOURCE_DIR}/config.h.in"
  "${HEATSIM_BINARY_DIR}/config.h"
)

INCLUDE_DIRECTORIES(${HEATSIM_BINARY_DIR} ${HEATSIM_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${HEATSIM_BINARY_DIR}/bin)

add_subdirectory(src)
