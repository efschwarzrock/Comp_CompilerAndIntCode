# src listfile
########################################################
# Initially you do not need all of these, but it doesn't
# hurt if you keep them in. I have commented these out and
# you can add them as your development progresses. I assume
# that you will start with the scanner and parser.
########################################################
include (ANTLR)
# include (Utility)
# include(Semantic)
include(Symbol)
include(Codegen)
include(LLVM)
# include(Runtime)

####################################################################
# See: https://cmake.org/cmake/help/latest/command/find_package.html
####################################################################
find_package(LLVM REQUIRED CONFIG)
list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})
include(AddLLVM)
include(HandleLLVMOptions)

add_subdirectory(lexparse)
add_subdirectory(symbol)
add_subdirectory(codegen)

###############################################
# Uncomment the following as you develop them
# Add others as your design evolves
#
#add_subdirectory(symbol)
# add_subdirectory(semantic)
# add_subdirectory(utility)
# add_subdirectory(codegen)
# add_subdirectory(runtime)

add_executable(wplc wplc.cpp)

# add dependencies as you need them

add_dependencies(
   wplc
   parser_lib
   sym_lib
   codegen_lib
 #  semantic_lib
 #  utility_lib
 #  wpl_runtime
  )

#target_include_directories(
#wplc PUBLIC
# ${ANTLR_INCLUDE} ${ANTLR_GENERATED_DIR}
# ${SYMBOL_INCLUDE}
#  # ${SEMANTIC_INCLUDE}
#  # ${UTILITY_INCLUDE}
# ${CODEGEN_INCLUDE}
#  ${LLVM_BINARY_DIR}/include
#  ${LLVM_INCLUDE_DIR}
#)



#target_link_libraries(
#wplc
#  PRIVATE
# ${ANTLR_RUNTIME_LIB}
#  lexparse_lib
# sym_lib
# codegen_lib
#  # semantic_lib
#  # utility_lib
#  ${LLVM_LIBS}
#)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(wplc
      PRIVATE
      ${ANTLR_RUNTIME_LIB}
      ${LLVM_LIBS}
      lexparse_lib
      parser_lib
      sym_lib
      codegen_lib
      Threads::Threads)

target_include_directories(wplc PUBLIC
  ${ANTLR_INCLUDE} ${ANTLR_GENERATED_DIR}
  ${SYMBOL_INCLUDE} ${CODEGEN_INCLUDE} ${LLVM_DIR}
  ${LLVM_INCLUDE_DIR}
  )