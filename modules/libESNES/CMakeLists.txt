cmake_minimum_required(VERSION 3.7)
project(ESNES VERSION 0.1.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(version.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/esnes/version.h @ONLY)
#include_directories(${PROJECT_BINARY_BIN})

add_library(ESNES STATIC
    src/esnes.cc
)

#Set target properties
target_include_directories(ESNES
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        src/
)

target_link_libraries(ESNES
  PUBLIC
  PRIVATE
)

install (TARGETS ESNES
    EXPORT ESNESTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

write_basic_package_version_file(
    ESNESConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(EXPORT ESNESTargets
    FILE ESNESTargets.cmake
    NAMESPACE esnes::
    DESTINATION lib/cmake/ESNES
)

add_library(esnes::ESNES ALIAS ESNES)
