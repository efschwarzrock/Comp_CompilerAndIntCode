
// Generated from WPL.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "WPLParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by WPLParser.
 */
class  WPLVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by WPLParser.
   */
    virtual std::any visitCompilationUnit(WPLParser::CompilationUnitContext *context) = 0;

    virtual std::any visitCuComponent(WPLParser::CuComponentContext *context) = 0;

    virtual std::any visitVarDeclaration(WPLParser::VarDeclarationContext *context) = 0;

    virtual std::any visitScalarDeclaration(WPLParser::ScalarDeclarationContext *context) = 0;

    virtual std::any visitScalar(WPLParser::ScalarContext *context) = 0;

    virtual std::any visitArrayDeclaration(WPLParser::ArrayDeclarationContext *context) = 0;

    virtual std::any visitType(WPLParser::TypeContext *context) = 0;

    virtual std::any visitVarInitializer(WPLParser::VarInitializerContext *context) = 0;

    virtual std::any visitExternDeclaration(WPLParser::ExternDeclarationContext *context) = 0;

    virtual std::any visitProcedure(WPLParser::ProcedureContext *context) = 0;

    virtual std::any visitProcHeader(WPLParser::ProcHeaderContext *context) = 0;

    virtual std::any visitExternProcHeader(WPLParser::ExternProcHeaderContext *context) = 0;

    virtual std::any visitFunction(WPLParser::FunctionContext *context) = 0;

    virtual std::any visitFuncHeader(WPLParser::FuncHeaderContext *context) = 0;

    virtual std::any visitExternFuncHeader(WPLParser::ExternFuncHeaderContext *context) = 0;

    virtual std::any visitParams(WPLParser::ParamsContext *context) = 0;

    virtual std::any visitBlock(WPLParser::BlockContext *context) = 0;

    virtual std::any visitStatement(WPLParser::StatementContext *context) = 0;

    virtual std::any visitLoop(WPLParser::LoopContext *context) = 0;

    virtual std::any visitConditional(WPLParser::ConditionalContext *context) = 0;

    virtual std::any visitSelect(WPLParser::SelectContext *context) = 0;

    virtual std::any visitSelectAlt(WPLParser::SelectAltContext *context) = 0;

    virtual std::any visitCall(WPLParser::CallContext *context) = 0;

    virtual std::any visitArguments(WPLParser::ArgumentsContext *context) = 0;

    virtual std::any visitArg(WPLParser::ArgContext *context) = 0;

    virtual std::any visitReturn(WPLParser::ReturnContext *context) = 0;

    virtual std::any visitConstant(WPLParser::ConstantContext *context) = 0;

    virtual std::any visitAssignment(WPLParser::AssignmentContext *context) = 0;

    virtual std::any visitArrayIndex(WPLParser::ArrayIndexContext *context) = 0;

    virtual std::any visitAndExpr(WPLParser::AndExprContext *context) = 0;

    virtual std::any visitIDExpr(WPLParser::IDExprContext *context) = 0;

    virtual std::any visitConstExpr(WPLParser::ConstExprContext *context) = 0;

    virtual std::any visitSubscriptExpr(WPLParser::SubscriptExprContext *context) = 0;

    virtual std::any visitRelExpr(WPLParser::RelExprContext *context) = 0;

    virtual std::any visitMultExpr(WPLParser::MultExprContext *context) = 0;

    virtual std::any visitAddExpr(WPLParser::AddExprContext *context) = 0;

    virtual std::any visitArrayLengthExpr(WPLParser::ArrayLengthExprContext *context) = 0;

    virtual std::any visitUMinusExpr(WPLParser::UMinusExprContext *context) = 0;

    virtual std::any visitOrExpr(WPLParser::OrExprContext *context) = 0;

    virtual std::any visitEqExpr(WPLParser::EqExprContext *context) = 0;

    virtual std::any visitFuncProcCallExpr(WPLParser::FuncProcCallExprContext *context) = 0;

    virtual std::any visitNotExpr(WPLParser::NotExprContext *context) = 0;

    virtual std::any visitParenExpr(WPLParser::ParenExprContext *context) = 0;


};

