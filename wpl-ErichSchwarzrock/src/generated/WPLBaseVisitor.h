
// Generated from WPL.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "WPLVisitor.h"


/**
 * This class provides an empty implementation of WPLVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  WPLBaseVisitor : public WPLVisitor {
public:

  virtual std::any visitCompilationUnit(WPLParser::CompilationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCuComponent(WPLParser::CuComponentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDeclaration(WPLParser::VarDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScalarDeclaration(WPLParser::ScalarDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScalar(WPLParser::ScalarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayDeclaration(WPLParser::ArrayDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(WPLParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarInitializer(WPLParser::VarInitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExternDeclaration(WPLParser::ExternDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedure(WPLParser::ProcedureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcHeader(WPLParser::ProcHeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExternProcHeader(WPLParser::ExternProcHeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(WPLParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncHeader(WPLParser::FuncHeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExternFuncHeader(WPLParser::ExternFuncHeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParams(WPLParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(WPLParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(WPLParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoop(WPLParser::LoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConditional(WPLParser::ConditionalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelect(WPLParser::SelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectAlt(WPLParser::SelectAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall(WPLParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(WPLParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg(WPLParser::ArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn(WPLParser::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant(WPLParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(WPLParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayIndex(WPLParser::ArrayIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(WPLParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIDExpr(WPLParser::IDExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExpr(WPLParser::ConstExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubscriptExpr(WPLParser::SubscriptExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelExpr(WPLParser::RelExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultExpr(WPLParser::MultExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddExpr(WPLParser::AddExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayLengthExpr(WPLParser::ArrayLengthExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUMinusExpr(WPLParser::UMinusExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(WPLParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqExpr(WPLParser::EqExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncProcCallExpr(WPLParser::FuncProcCallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExpr(WPLParser::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenExpr(WPLParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

