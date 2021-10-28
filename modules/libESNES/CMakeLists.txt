cmake_minimum_required(VERSION 3.7)
project(ESNES VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ESNES SHARED
    src/esnes.cc
)

#Set target properties
target_include_directories(ESNES
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
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
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

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
