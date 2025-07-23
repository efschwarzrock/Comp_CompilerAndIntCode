
// Generated from WPL.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "WPLParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by WPLParser.
 */
class  WPLListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompilationUnit(WPLParser::CompilationUnitContext *ctx) = 0;
  virtual void exitCompilationUnit(WPLParser::CompilationUnitContext *ctx) = 0;

  virtual void enterCuComponent(WPLParser::CuComponentContext *ctx) = 0;
  virtual void exitCuComponent(WPLParser::CuComponentContext *ctx) = 0;

  virtual void enterVarDeclaration(WPLParser::VarDeclarationContext *ctx) = 0;
  virtual void exitVarDeclaration(WPLParser::VarDeclarationContext *ctx) = 0;

  virtual void enterScalarDeclaration(WPLParser::ScalarDeclarationContext *ctx) = 0;
  virtual void exitScalarDeclaration(WPLParser::ScalarDeclarationContext *ctx) = 0;

  virtual void enterScalar(WPLParser::ScalarContext *ctx) = 0;
  virtual void exitScalar(WPLParser::ScalarContext *ctx) = 0;

  virtual void enterArrayDeclaration(WPLParser::ArrayDeclarationContext *ctx) = 0;
  virtual void exitArrayDeclaration(WPLParser::ArrayDeclarationContext *ctx) = 0;

  virtual void enterType(WPLParser::TypeContext *ctx) = 0;
  virtual void exitType(WPLParser::TypeContext *ctx) = 0;

  virtual void enterVarInitializer(WPLParser::VarInitializerContext *ctx) = 0;
  virtual void exitVarInitializer(WPLParser::VarInitializerContext *ctx) = 0;

  virtual void enterExternDeclaration(WPLParser::ExternDeclarationContext *ctx) = 0;
  virtual void exitExternDeclaration(WPLParser::ExternDeclarationContext *ctx) = 0;

  virtual void enterProcedure(WPLParser::ProcedureContext *ctx) = 0;
  virtual void exitProcedure(WPLParser::ProcedureContext *ctx) = 0;

  virtual void enterProcHeader(WPLParser::ProcHeaderContext *ctx) = 0;
  virtual void exitProcHeader(WPLParser::ProcHeaderContext *ctx) = 0;

  virtual void enterExternProcHeader(WPLParser::ExternProcHeaderContext *ctx) = 0;
  virtual void exitExternProcHeader(WPLParser::ExternProcHeaderContext *ctx) = 0;

  virtual void enterFunction(WPLParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(WPLParser::FunctionContext *ctx) = 0;

  virtual void enterFuncHeader(WPLParser::FuncHeaderContext *ctx) = 0;
  virtual void exitFuncHeader(WPLParser::FuncHeaderContext *ctx) = 0;

  virtual void enterExternFuncHeader(WPLParser::ExternFuncHeaderContext *ctx) = 0;
  virtual void exitExternFuncHeader(WPLParser::ExternFuncHeaderContext *ctx) = 0;

  virtual void enterParams(WPLParser::ParamsContext *ctx) = 0;
  virtual void exitParams(WPLParser::ParamsContext *ctx) = 0;

  virtual void enterBlock(WPLParser::BlockContext *ctx) = 0;
  virtual void exitBlock(WPLParser::BlockContext *ctx) = 0;

  virtual void enterStatement(WPLParser::StatementContext *ctx) = 0;
  virtual void exitStatement(WPLParser::StatementContext *ctx) = 0;

  virtual void enterLoop(WPLParser::LoopContext *ctx) = 0;
  virtual void exitLoop(WPLParser::LoopContext *ctx) = 0;

  virtual void enterConditional(WPLParser::ConditionalContext *ctx) = 0;
  virtual void exitConditional(WPLParser::ConditionalContext *ctx) = 0;

  virtual void enterSelect(WPLParser::SelectContext *ctx) = 0;
  virtual void exitSelect(WPLParser::SelectContext *ctx) = 0;

  virtual void enterSelectAlt(WPLParser::SelectAltContext *ctx) = 0;
  virtual void exitSelectAlt(WPLParser::SelectAltContext *ctx) = 0;

  virtual void enterCall(WPLParser::CallContext *ctx) = 0;
  virtual void exitCall(WPLParser::CallContext *ctx) = 0;

  virtual void enterArguments(WPLParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(WPLParser::ArgumentsContext *ctx) = 0;

  virtual void enterArg(WPLParser::ArgContext *ctx) = 0;
  virtual void exitArg(WPLParser::ArgContext *ctx) = 0;

  virtual void enterReturn(WPLParser::ReturnContext *ctx) = 0;
  virtual void exitReturn(WPLParser::ReturnContext *ctx) = 0;

  virtual void enterConstant(WPLParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(WPLParser::ConstantContext *ctx) = 0;

  virtual void enterAssignment(WPLParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(WPLParser::AssignmentContext *ctx) = 0;

  virtual void enterArrayIndex(WPLParser::ArrayIndexContext *ctx) = 0;
  virtual void exitArrayIndex(WPLParser::ArrayIndexContext *ctx) = 0;

  virtual void enterAndExpr(WPLParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(WPLParser::AndExprContext *ctx) = 0;

  virtual void enterIDExpr(WPLParser::IDExprContext *ctx) = 0;
  virtual void exitIDExpr(WPLParser::IDExprContext *ctx) = 0;

  virtual void enterConstExpr(WPLParser::ConstExprContext *ctx) = 0;
  virtual void exitConstExpr(WPLParser::ConstExprContext *ctx) = 0;

  virtual void enterSubscriptExpr(WPLParser::SubscriptExprContext *ctx) = 0;
  virtual void exitSubscriptExpr(WPLParser::SubscriptExprContext *ctx) = 0;

  virtual void enterRelExpr(WPLParser::RelExprContext *ctx) = 0;
  virtual void exitRelExpr(WPLParser::RelExprContext *ctx) = 0;

  virtual void enterMultExpr(WPLParser::MultExprContext *ctx) = 0;
  virtual void exitMultExpr(WPLParser::MultExprContext *ctx) = 0;

  virtual void enterAddExpr(WPLParser::AddExprContext *ctx) = 0;
  virtual void exitAddExpr(WPLParser::AddExprContext *ctx) = 0;

  virtual void enterArrayLengthExpr(WPLParser::ArrayLengthExprContext *ctx) = 0;
  virtual void exitArrayLengthExpr(WPLParser::ArrayLengthExprContext *ctx) = 0;

  virtual void enterUMinusExpr(WPLParser::UMinusExprContext *ctx) = 0;
  virtual void exitUMinusExpr(WPLParser::UMinusExprContext *ctx) = 0;

  virtual void enterOrExpr(WPLParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(WPLParser::OrExprContext *ctx) = 0;

  virtual void enterEqExpr(WPLParser::EqExprContext *ctx) = 0;
  virtual void exitEqExpr(WPLParser::EqExprContext *ctx) = 0;

  virtual void enterFuncProcCallExpr(WPLParser::FuncProcCallExprContext *ctx) = 0;
  virtual void exitFuncProcCallExpr(WPLParser::FuncProcCallExprContext *ctx) = 0;

  virtual void enterNotExpr(WPLParser::NotExprContext *ctx) = 0;
  virtual void exitNotExpr(WPLParser::NotExprContext *ctx) = 0;

  virtual void enterParenExpr(WPLParser::ParenExprContext *ctx) = 0;
  virtual void exitParenExpr(WPLParser::ParenExprContext *ctx) = 0;


};

