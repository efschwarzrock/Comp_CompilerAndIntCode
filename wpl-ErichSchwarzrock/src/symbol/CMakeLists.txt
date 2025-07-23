# symbol listfile
#
##############################################
# Modify for your implementation.
##############################################
include(Symbol)
include(LLVM)
find_package(LLVM REQUIRED CONFIG)
list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include(AddLLVM)
include(HandleLLVMOptions)

add_library(sym_lib OBJECT
  ${SYMBOL_SOURCES}
)
include_directories(sym_lib
  ${SYMBOL_INCLUDE}
  ${LLVM_BINARY_DIR}/include
  ${LLVM_INCLUDE_DIR}
)

add_dependencies(parser_lib sym_lib)
target_include_directories(sym_lib PUBLIC ${ANTLR_INCLUDE} ${ANTLR_GENERATED_DIR})

