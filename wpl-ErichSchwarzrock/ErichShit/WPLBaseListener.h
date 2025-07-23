
// Generated from WPL.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "WPLListener.h"


/**
 * This class provides an empty implementation of WPLListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  WPLBaseListener : public WPLListener {
public:

  virtual void enterCompilationUnit(WPLParser::CompilationUnitContext * /*ctx*/) override { }
  virtual void exitCompilationUnit(WPLParser::CompilationUnitContext * /*ctx*/) override { }

  virtual void enterCuComponent(WPLParser::CuComponentContext * /*ctx*/) override { }
  virtual void exitCuComponent(WPLParser::CuComponentContext * /*ctx*/) override { }

  virtual void enterVarDeclaration(WPLParser::VarDeclarationContext * /*ctx*/) override { }
  virtual void exitVarDeclaration(WPLParser::VarDeclarationContext * /*ctx*/) override { }

  virtual void enterScalarDeclaration(WPLParser::ScalarDeclarationContext * /*ctx*/) override { }
  virtual void exitScalarDeclaration(WPLParser::ScalarDeclarationContext * /*ctx*/) override { }

  virtual void enterScalar(WPLParser::ScalarContext * /*ctx*/) override { }
  virtual void exitScalar(WPLParser::ScalarContext * /*ctx*/) override { }

  virtual void enterArrayDeclaration(WPLParser::ArrayDeclarationContext * /*ctx*/) override { }
  virtual void exitArrayDeclaration(WPLParser::ArrayDeclarationContext * /*ctx*/) override { }

  virtual void enterType(WPLParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(WPLParser::TypeContext * /*ctx*/) override { }

  virtual void enterVarInitializer(WPLParser::VarInitializerContext * /*ctx*/) override { }
  virtual void exitVarInitializer(WPLParser::VarInitializerContext * /*ctx*/) override { }

  virtual void enterExternDeclaration(WPLParser::ExternDeclarationContext * /*ctx*/) override { }
  virtual void exitExternDeclaration(WPLParser::ExternDeclarationContext * /*ctx*/) override { }

  virtual void enterProcedure(WPLParser::ProcedureContext * /*ctx*/) override { }
  virtual void exitProcedure(WPLParser::ProcedureContext * /*ctx*/) override { }

  virtual void enterProcHeader(WPLParser::ProcHeaderContext * /*ctx*/) override { }
  virtual void exitProcHeader(WPLParser::ProcHeaderContext * /*ctx*/) override { }

  virtual void enterExternProcHeader(WPLParser::ExternProcHeaderContext * /*ctx*/) override { }
  virtual void exitExternProcHeader(WPLParser::ExternProcHeaderContext * /*ctx*/) override { }

  virtual void enterFunction(WPLParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(WPLParser::FunctionContext * /*ctx*/) override { }

  virtual void enterFuncHeader(WPLParser::FuncHeaderContext * /*ctx*/) override { }
  virtual void exitFuncHeader(WPLParser::FuncHeaderContext * /*ctx*/) override { }

  virtual void enterExternFuncHeader(WPLParser::ExternFuncHeaderContext * /*ctx*/) override { }
  virtual void exitExternFuncHeader(WPLParser::ExternFuncHeaderContext * /*ctx*/) override { }

  virtual void enterParams(WPLParser::ParamsContext * /*ctx*/) override { }
  virtual void exitParams(WPLParser::ParamsContext * /*ctx*/) override { }

  virtual void enterBlock(WPLParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(WPLParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatement(WPLParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(WPLParser::StatementContext * /*ctx*/) override { }

  virtual void enterLoop(WPLParser::LoopContext * /*ctx*/) override { }
  virtual void exitLoop(WPLParser::LoopContext * /*ctx*/) override { }

  virtual void enterConditional(WPLParser::ConditionalContext * /*ctx*/) override { }
  virtual void exitConditional(WPLParser::ConditionalContext * /*ctx*/) override { }

  virtual void enterSelect(WPLParser::SelectContext * /*ctx*/) override { }
  virtual void exitSelect(WPLParser::SelectContext * /*ctx*/) override { }

  virtual void enterSelectAlt(WPLParser::SelectAltContext * /*ctx*/) override { }
  virtual void exitSelectAlt(WPLParser::SelectAltContext * /*ctx*/) override { }

  virtual void enterCall(WPLParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(WPLParser::CallContext * /*ctx*/) override { }

  virtual void enterArguments(WPLParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(WPLParser::ArgumentsContext * /*ctx*/) override { }

  virtual void enterArg(WPLParser::ArgContext * /*ctx*/) override { }
  virtual void exitArg(WPLParser::ArgContext * /*ctx*/) override { }

  virtual void enterReturn(WPLParser::ReturnContext * /*ctx*/) override { }
  virtual void exitReturn(WPLParser::ReturnContext * /*ctx*/) override { }

  virtual void enterConstant(WPLParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(WPLParser::ConstantContext * /*ctx*/) override { }

  virtual void enterAssignment(WPLParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(WPLParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterArrayIndex(WPLParser::ArrayIndexContext * /*ctx*/) override { }
  virtual void exitArrayIndex(WPLParser::ArrayIndexContext * /*ctx*/) override { }

  virtual void enterAndExpr(WPLParser::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(WPLParser::AndExprContext * /*ctx*/) override { }

  virtual void enterIDExpr(WPLParser::IDExprContext * /*ctx*/) override { }
  virtual void exitIDExpr(WPLParser::IDExprContext * /*ctx*/) override { }

  virtual void enterConstExpr(WPLParser::ConstExprContext * /*ctx*/) override { }
  virtual void exitConstExpr(WPLParser::ConstExprContext * /*ctx*/) override { }

  virtual void enterSubscriptExpr(WPLParser::SubscriptExprContext * /*ctx*/) override { }
  virtual void exitSubscriptExpr(WPLParser::SubscriptExprContext * /*ctx*/) override { }

  virtual void enterRelExpr(WPLParser::RelExprContext * /*ctx*/) override { }
  virtual void exitRelExpr(WPLParser::RelExprContext * /*ctx*/) override { }

  virtual void enterMultExpr(WPLParser::MultExprContext * /*ctx*/) override { }
  virtual void exitMultExpr(WPLParser::MultExprContext * /*ctx*/) override { }

  virtual void enterAddExpr(WPLParser::AddExprContext * /*ctx*/) override { }
  virtual void exitAddExpr(WPLParser::AddExprContext * /*ctx*/) override { }

  virtual void enterArrayLengthExpr(WPLParser::ArrayLengthExprContext * /*ctx*/) override { }
  virtual void exitArrayLengthExpr(WPLParser::ArrayLengthExprContext * /*ctx*/) override { }

  virtual void enterUMinusExpr(WPLParser::UMinusExprContext * /*ctx*/) override { }
  virtual void exitUMinusExpr(WPLParser::UMinusExprContext * /*ctx*/) override { }

  virtual void enterOrExpr(WPLParser::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(WPLParser::OrExprContext * /*ctx*/) override { }

  virtual void enterEqExpr(WPLParser::EqExprContext * /*ctx*/) override { }
  virtual void exitEqExpr(WPLParser::EqExprContext * /*ctx*/) override { }

  virtual void enterFuncProcCallExpr(WPLParser::FuncProcCallExprContext * /*ctx*/) override { }
  virtual void exitFuncProcCallExpr(WPLParser::FuncProcCallExprContext * /*ctx*/) override { }

  virtual void enterNotExpr(WPLParser::NotExprContext * /*ctx*/) override { }
  virtual void exitNotExpr(WPLParser::NotExprContext * /*ctx*/) override { }

  virtual void enterParenExpr(WPLParser::ParenExprContext * /*ctx*/) override { }
  virtual void exitParenExpr(WPLParser::ParenExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

