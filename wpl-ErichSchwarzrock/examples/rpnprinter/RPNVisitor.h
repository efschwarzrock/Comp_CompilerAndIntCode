/**
 * @file RPNVisitor.h
 * @author gpollice
 * @brief Header file for the RPN Visitor
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "antlr4-runtime.h"
#include "WPLBaseVisitor.h"

class RPNVisitor : WPLBaseVisitor {
  public :
      virtual std::any visitCompilationUnit(WPLParser::CompilationUnitContext *ctx)  override ;
      virtual std::any visitScalarDeclaration(WPLParser::ScalarDeclarationContext *ctx) override ;
      virtual std::any visitScalar(WPLParser::ScalarContext *ctx)  override ;
      virtual std::any visitArrayDeclaration(WPLParser::ArrayDeclarationContext *ctx)  override ;
      virtual std::any visitVarInitializer(WPLParser::VarInitializerContext *ctx)  override ;
      virtual std::any visitExternDeclaration(WPLParser::ExternDeclarationContext *ctx)  override ;
      virtual std::any visitProcedure(WPLParser::ProcedureContext *ctx) override ;
      virtual std::any visitProcHeader(WPLParser::ProcHeaderContext *ctx)  override ;
      virtual std::any visitExternProcHeader(WPLParser::ExternProcHeaderContext *ctx)  override ;
      virtual std::any visitFunction(WPLParser::FunctionContext *ctx)  override ;
      virtual std::any visitFuncHeader(WPLParser::FuncHeaderContext *ctx)  override ;
      virtual std::any visitExternFuncHeader(WPLParser::ExternFuncHeaderContext *ctx)  override ;
      virtual std::any visitParams(WPLParser::ParamsContext *ctx)  override ;
      virtual std::any visitBlock(WPLParser::BlockContext *ctx)  override ;
      virtual std::any visitLoop(WPLParser::LoopContext *ctx)  override ;
      virtual std::any visitConditional(WPLParser::ConditionalContext *ctx)  override ;
      virtual std::any visitSelect(WPLParser::SelectContext *ctx)  override ;
      virtual std::any visitSelectAlt(WPLParser::SelectAltContext *ctx)  override ;
      virtual std::any visitCall(WPLParser::CallContext *ctx)  override ;
      virtual std::any visitArguments(WPLParser::ArgumentsContext *ctx)  override ;
      virtual std::any visitArg(WPLParser::ArgContext *ctx)  override ;
      virtual std::any visitReturn(WPLParser::ReturnContext *ctx)  override ;
      virtual std::any visitAssignment(WPLParser::AssignmentContext *ctx) override ;
      virtual std::any visitArrayIndex(WPLParser::ArrayIndexContext *ctx)  override ;
      virtual std::any visitAndExpr(WPLParser::AndExprContext *ctx) override ;
      virtual std::any visitSubscriptExpr(WPLParser::SubscriptExprContext *ctx)  override ;
      virtual std::any visitRelExpr(WPLParser::RelExprContext *ctx)  override ;
      virtual std::any visitMultExpr(WPLParser::MultExprContext *ctx)  override ;
      virtual std::any visitAddExpr(WPLParser::AddExprContext *ctx)  override ;
      virtual std::any visitArrayLengthExpr(WPLParser::ArrayLengthExprContext *ctx)  override ;
      virtual std::any visitUMinusExpr(WPLParser::UMinusExprContext *ctx)  override ;
      virtual std::any visitOrExpr(WPLParser::OrExprContext *ctx)  override ;
      virtual std::any visitEqExpr(WPLParser::EqExprContext *ctx)  override ;
      virtual std::any visitFuncProcCallExpr(WPLParser::FuncProcCallExprContext *ctx)  override ;
      virtual std::any visitNotExpr(WPLParser::NotExprContext *ctx) override ;
      virtual std::any visitParenExpr(WPLParser::ParenExprContext *ctx) override ;

};