# Top-level CMake file for this the Calculator example

cmake_minimum_required(VERSION 3.20.0)
project(WPL_COMPILER 
  LANGUAGES CXX C
  VERSION 0.1
  DESCRIPTION "Compiler to compile the WPL source to LLVM IR"
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(NoInSourceBuilds)

include(ProjectGlobals)         # Platform independent variables
include(platform_settings)      # Platform specific variables

add_subdirectory(src bin)
add_subdirectory(examples)

set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
install(
   TARGETS
     wplc
   DESTINATION install
)
#include(Install)
