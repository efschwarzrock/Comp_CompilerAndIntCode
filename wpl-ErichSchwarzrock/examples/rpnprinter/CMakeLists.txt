# examples listfile
include(Semantic)
include(Symbol)
include(ANTLR)
include(Utility)
include(Codegen)
include(LLVM)

find_package(LLVM REQUIRED CONFIG)
list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})
include(AddLLVM)
include(HandleLLVMOptions)

add_executable(rpnprinter 
  rpnprinter.cpp
  RPNVisitor.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(rpnprinter
      PRIVATE
      ${ANTLR_RUNTIME_LIB}
      ${LLVM_LIBS}
      lexparse_lib
      parser_lib
      sym_lib
      codegen_lib
      Threads::Threads)

target_include_directories(rpnprinter PUBLIC
  ${ANTLR_INCLUDE} ${ANTLR_GENERATED_DIR}
  ${SYMBOL_INCLUDE} ${CODEGEN_INCLUDE} ${LLVM_DIR}
  ${LLVM_INCLUDE_DIR}
  )

add_dependencies(
   rpnprinter
   codegen_lib
)





