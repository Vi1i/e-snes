cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(E-SNES VERSION 0.1.0.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(CMakeFindDependencyMacro)

add_subdirectory(modules/libESNES)
#add_subdirectory(test)
