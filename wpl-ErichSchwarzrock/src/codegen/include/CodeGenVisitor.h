#pragma once
#include "antlr4-runtime.h"
#include "WPLBaseVisitor.h"
#include "STManager.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/NoFolder.h"
#include "llvm/IR/Value.h"
#include <list>



using namespace llvm;
class CodeGenVisitor : WPLBaseVisitor {
    private:

      LLVMContext *context;
      IRBuilder<NoFolder> *builder;

      // Cache commonly used types
      Type *VoidTy;
      Type *Int1Ty;
      Type *Int8Ty;
      Type *Int32Ty;
      Type * i8p;
      Type *Int8PtrPtrTy;
      Constant *Int32Zero;
      Constant *Int32One;
      Constant *Int1One;
      STManager manager;
      int scope;
      void enterScope();
      Type* getType(Symbol s);
      Type* getType(SymType s);
      Type* getArrayType(SymType s);
      Constant* getGlobalVarInitializer(Symbol s, Value* v);
      bool globalVars;
      std::string glbVarName;
      Function* curGlobalFunction;
      BasicBlock* selectBlockGlobal;
      BasicBlock* fSelectBlockGlobal;
      BasicBlock* continueBlock;
      Value* arrayElePtr;
      std::list<Symbol*> arrayGlobalStrings;
      std::list<Value*> arrayGlobalStringsValues;
      std::string fName;

  public:
  Module *module;
      CodeGenVisitor(std::string moduleName, STManager m);
      virtual std::any visitCompilationUnit(WPLParser::CompilationUnitContext *ctx) override;
      virtual std::any visitScalar(WPLParser::ScalarContext *ctx) override;
      virtual std::any visitConstant(WPLParser::ConstantContext *ctx) override;
      virtual std::any visitExternDeclaration(WPLParser::ExternDeclarationContext *ctx) override;
     virtual std::any visitProcedure(WPLParser::ProcedureContext *ctx) override;
      virtual std::any visitFunction(WPLParser::FunctionContext *ctx) override;

     virtual std::any visitArguments(WPLParser::ArgumentsContext *ctx) override;
      virtual std::any visitArg(WPLParser::ArgContext *ctx) override;
      virtual std::any visitReturn(WPLParser::ReturnContext *ctx) override;
      virtual std::any visitAssignment(WPLParser::AssignmentContext *ctx) override;
      virtual std::any visitAndExpr(WPLParser::AndExprContext *ctx) override;
      virtual std::any visitIDExpr(WPLParser::IDExprContext *context) override;
      virtual std::any visitRelExpr(WPLParser::RelExprContext *ctx) override;
      virtual std::any visitMultExpr(WPLParser::MultExprContext *ctx) override;
      virtual std::any visitAddExpr(WPLParser::AddExprContext *ctx) override;
      virtual std::any visitUMinusExpr(WPLParser::UMinusExprContext *ctx) override;
      virtual std::any visitOrExpr(WPLParser::OrExprContext *ctx) override;
      virtual std::any visitEqExpr(WPLParser::EqExprContext *ctx) override;
      virtual std::any visitNotExpr(WPLParser::NotExprContext *ctx) override;

//array shit
      virtual std::any visitArrayLengthExpr(WPLParser::ArrayLengthExprContext *ctx) override;
      virtual std::any visitArrayDeclaration(WPLParser::ArrayDeclarationContext *ctx) override;
      virtual std::any visitArrayIndex(WPLParser::ArrayIndexContext *ctx) override;

//string shit - done


//conditionals
      virtual std::any visitLoop(WPLParser::LoopContext *ctx) override;
      virtual std::any visitConditional(WPLParser::ConditionalContext *ctx) override;
      virtual std::any visitSelect(WPLParser::SelectContext *ctx) override;
      virtual std::any visitSelectAlt(WPLParser::SelectAltContext *ctx) override;
      virtual std::any visitCall(WPLParser::CallContext *ctx) override;
      virtual std::any visitFuncProcCallExpr(WPLParser::FuncProcCallExprContext *ctx) override;


//      virtual std::any visitParams(WPLParser::ParamsContext *ctx) override;
//      virtual std::any visitFuncHeader(WPLParser::FuncHeaderContext *ctx) ;
//      virtual std::any visitProcHeader(WPLParser::ProcHeaderContext *ctx) ;
//      virtual std::any visitScalarDeclaration(WPLParser::ScalarDeclarationContext *ctx);
//      virtual std::any visitVarInitializer(WPLParser::VarInitializerContext *ctx) ;
      virtual std::any visitBlock(WPLParser::BlockContext *ctx) override;
//      virtual std::any visitConstExpr(WPLParser::ConstExprContext *context);
      virtual std::any visitParenExpr(WPLParser::ParenExprContext *ctx) override;
//virtual std::any visitSubscriptExpr(WPLParser::SubscriptExprContext *ctx) override;


};
