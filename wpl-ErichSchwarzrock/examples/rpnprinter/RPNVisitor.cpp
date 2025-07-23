/**
 * @file RPNVisitor.cpp
 * @author gpollice
 * @brief Visitor that prints the expressions from a Calculator parse tree in
 *  Reverse Polish Notation (RPN)
 * @version 0.1
 * @date 2022-07-12
 */
#include <iostream>
#include "RPNVisitor.h"
// std::cout << "Here" << std::endl;

  std::any RPNVisitor::visitCompilationUnit(WPLParser::CompilationUnitContext *ctx) {
      std::cout << "Enetering" << std::endl;

      for (auto e : ctx->cuComponent()) {
        e->accept(this);
        std::cout << std::endl;
      }
      return NULL;

  }

  std::any RPNVisitor::visitScalarDeclaration(WPLParser::ScalarDeclarationContext *ctx) {
      for (auto e : ctx->scalars) {
        e->accept(this);
        std::cout << ',';
      }
    if(ctx->t != NULL){
      std::cout << ctx->t->getText();
    }else{
      std::cout << "var";
    }
    return NULL;
  }

  std::any RPNVisitor::visitScalar(WPLParser::ScalarContext *ctx) {
    if(ctx->varInitializer() != NULL){
      ctx->varInitializer()->accept(this);
    }
    std::cout << ctx->ID()->getText();
    return NULL;
  }

  std::any RPNVisitor::visitArrayDeclaration(WPLParser::ArrayDeclarationContext *ctx) {
    ctx->typename_->accept(this);
    std::cout << ctx->typename_->getText() << ' ' << ctx->ID()->getText() << ' ' << "[" << ctx->INTEGER()->getText() << "]" ;
    return NULL;
  }

  std::any RPNVisitor::visitVarInitializer(WPLParser::VarInitializerContext *ctx) {
    std::cout << ctx->c->getText() << "<-";
    return NULL;
  }

  std::any RPNVisitor::visitExternDeclaration(WPLParser::ExternDeclarationContext *ctx) {
    if(ctx->externProcHeader() != NULL){
      ctx->externProcHeader()->accept(this);
    }else if(ctx->externFuncHeader() != NULL){
      ctx->externFuncHeader()->accept(this);
    }
    return NULL;
  }

  std::any RPNVisitor::visitProcedure(WPLParser::ProcedureContext *ctx)  {
    ctx->procHeader()->accept(this);
    ctx->block()->accept(this);
    return NULL;
  }

  std::any  RPNVisitor::visitProcHeader(WPLParser::ProcHeaderContext *ctx)  {
    if(ctx->p != NULL){
      ctx->p->accept(this);
    }
    std::cout << ctx->id->getText() << " proc" << std::endl;
    return NULL;
  }

  std::any  RPNVisitor::visitExternProcHeader(WPLParser::ExternProcHeaderContext *ctx)  {
    if(ctx->params() != NULL){
        ctx->params()->accept(this);
    }
    if(ctx->ELLIPSIS() != NULL){
        ctx->ELLIPSIS()->accept(this);
    }
    std::cout << ctx->id->getText() << " proc extern";
    return NULL;
  }

  std::any  RPNVisitor::visitFunction(WPLParser::FunctionContext *ctx)  {
    ctx->funcHeader()->accept(this);
    ctx->block()->accept(this);
    return NULL;
  }

  std::any  RPNVisitor::visitFuncHeader(WPLParser::FuncHeaderContext *ctx)  {
    if(ctx->p != NULL){
      ctx->p->accept(this);
    }
    std::cout << ctx->t->getText() << ' ' << ctx->id->getText() << " func" << std::endl;
    return NULL;
  }

  std::any  RPNVisitor::visitExternFuncHeader(WPLParser::ExternFuncHeaderContext *ctx)  {
    if(ctx->params() != NULL){
        ctx->params()->accept(this);
    }
    if(ctx->ELLIPSIS() != NULL){
        ctx->ELLIPSIS()->accept(this);
    }
    std::cout << ctx->t->getText() << ' ' << ctx->id->getText() << " func extern";
    return NULL;
  }

  std::any  RPNVisitor::visitParams(WPLParser::ParamsContext *ctx)  {
    int i = 0;
    for (auto e : ctx->type()) {
        std::cout << e->getText() << ' ' << ctx->ID()[i]->getText() << ',';
        i++;
    }
    return NULL;
  }

  std::any  RPNVisitor::visitBlock(WPLParser::BlockContext *ctx)  {
    std::cout << '{' << std::endl;
    visitChildren(ctx);
    std::cout << '}' << std::endl;
    return NULL;
  }


  std::any  RPNVisitor::visitLoop(WPLParser::LoopContext *ctx)  {
    ctx->e->accept(this);
    ctx->block()->accept(this);
    std::cout << "while";
    return NULL;
  }

  std::any  RPNVisitor::visitConditional(WPLParser::ConditionalContext *ctx)  {
    ctx->e->accept(this);
    for (auto e : ctx->block()) {
        e->accept(this);
        std::cout << std::endl;
    }
    std::cout << "if";
    return NULL;
  }

  std::any  RPNVisitor::visitSelect(WPLParser::SelectContext *ctx)  {
    for (auto e : ctx->selectAlt()) {
        e->accept(this);
        std::cout << std::endl;
    }
    std::cout << "select" << std::endl;
    return NULL;
  }

  std::any  RPNVisitor::visitSelectAlt(WPLParser::SelectAltContext *ctx)  {
    ctx->e->accept(this);
    std::cout << ":";
    ctx->s->accept(this);
    return NULL;
  }

  std::any  RPNVisitor::visitCall(WPLParser::CallContext *ctx)  {
    ctx->arguments()->accept(this);
    std::cout << ")" << ctx->id->getText() << std::endl;
    return NULL;
  }

  std::any  RPNVisitor::visitArguments(WPLParser::ArgumentsContext *ctx)  {
    for (auto e : ctx->arg()) {
        e->accept(this);
        std::cout << ',';
    }
    return NULL;
  }

  std::any  RPNVisitor::visitArg(WPLParser::ArgContext *ctx)  {
    if(ctx->c != NULL){
      std::cout << ctx->c->getText();
    }else if(ctx->id != NULL){
      std::cout << ctx->id->getText();
    }
    return NULL;
  }

  std::any  RPNVisitor::visitReturn(WPLParser::ReturnContext *ctx)  {
    ctx->expr()->accept(this);
    std::cout << "return";
    return NULL;
  }

  std::any  RPNVisitor::visitAssignment(WPLParser::AssignmentContext *ctx)  {
    for (auto e : ctx->exprs) {
        e->accept(this);
        std::cout << ",";
    }
    std::cout << "->";
    for (auto e : ctx->targets) {
        std::cout << e->getText() << ",";
    }
    return NULL;
  }

  std::any  RPNVisitor::visitArrayIndex(WPLParser::ArrayIndexContext *ctx)  {
    ctx->expr()->accept(this);
    std::cout << ']' << ctx->id->getText();
    return NULL;
  }

  std::any  RPNVisitor::visitAndExpr(WPLParser::AndExprContext *ctx)  {
    ctx->left->accept(this);
    ctx->right->accept(this);
    std::cout << '&';
    return NULL;
  }

  std::any  RPNVisitor::visitSubscriptExpr(WPLParser::SubscriptExprContext *ctx)  {
    ctx->arrayIndex()->accept(this);
    return NULL;
  }

  std::any  RPNVisitor::visitRelExpr(WPLParser::RelExprContext *ctx)  {
    ctx->left->accept(this);
    ctx->right->accept(this);
    if( ctx->LESS() != NULL){
      std::cout << ctx->LESS()->getText();
    }else if(ctx->LEQ() != NULL){
      std::cout << ctx->LEQ()->getText();
    }else if(ctx->GTR() != NULL){
      std::cout << ctx->GTR()->getText();
    }else if(ctx->GEQ() != NULL){
      std::cout << ctx->GEQ()->getText();
    }
    return NULL;
  }

  std::any  RPNVisitor::visitMultExpr(WPLParser::MultExprContext *ctx)  {
    ctx->left->accept(this);
    ctx->right->accept(this);
    if( ctx->MUL() != NULL){
      std::cout << ctx->MUL()->getText();
    }else if(ctx->DIV() != NULL){
      std::cout << ctx->DIV()->getText();
    }
    return NULL;
  }

  std::any  RPNVisitor::visitAddExpr(WPLParser::AddExprContext *ctx)  {
    ctx->left->accept(this);
    ctx->right->accept(this);
    if( ctx->PLUS() != NULL){
      std::cout << ctx->PLUS()->getText();
    }else if(ctx->MINUS() != NULL){
      std::cout << ctx->MINUS()->getText();
    }
    return NULL;
  }

  std::any  RPNVisitor::visitArrayLengthExpr(WPLParser::ArrayLengthExprContext *ctx)  {
    std::cout << ctx->ID()->getText() << " length";
    return NULL;
  }

  std::any  RPNVisitor::visitUMinusExpr(WPLParser::UMinusExprContext *ctx)  {
    ctx->expr()->accept(this);
    std::cout << '-';
    return NULL;
  }

  std::any  RPNVisitor::visitOrExpr(WPLParser::OrExprContext *ctx)  {
    ctx->left->accept(this);
    ctx->right->accept(this);
    std::cout << '|';
    return NULL;
  }

  std::any  RPNVisitor::visitEqExpr(WPLParser::EqExprContext *ctx)  {
    ctx->left->accept(this);
    ctx->right->accept(this);
    if( ctx->EQUAL() != NULL){
      std::cout << ctx->EQUAL()->getText();
    }else if(ctx->NEQ() != NULL){
      std::cout << ctx->NEQ()->getText();
    }
    return NULL;
  }

  std::any  RPNVisitor::visitFuncProcCallExpr(WPLParser::FuncProcCallExprContext *ctx)  {
    for (auto e : ctx->args) {
        e->accept(this);
    }
    std::cout << ')' << ctx->fpname->getText();
    return NULL;
  }

  std::any  RPNVisitor::visitNotExpr(WPLParser::NotExprContext *ctx)  {
    ctx->expr()->accept(this);
    std::cout << '~';
    return NULL;
  }

  std::any  RPNVisitor::visitParenExpr(WPLParser::ParenExprContext *ctx)  {
    std::cout << '(';
    ctx->expr()->accept(this);
    std::cout << ')';
    return NULL;
  }
