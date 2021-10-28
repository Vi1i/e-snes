cmake_minimum_required(VERSION 3.7)
project(esnes-cli VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(esnes-cli
        src/cli.cc
        )

#Set target properties
target_include_directories(esnes-cli
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        src/
        )

target_link_libraries(esnes-cli
        PUBLIC
        PRIVATE
        esnes::ESNES
        )

install(TARGETS esnes-cli
        EXPORT esnes-cliTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
        )

write_basic_package_version_file(
        esnes-cliConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY AnyNewerVersion
)

install(EXPORT esnes-cliTargets
        FILE esnes-cliTargets.cmake
        NAMESPACE esnes::
        DESTINATION lib/cmake/esnes-cli
        )
