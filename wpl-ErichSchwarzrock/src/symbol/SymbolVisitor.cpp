#include "SymbolVisitor.h"


  STManager manager;
  SymType curType;
  SymType initializerType;
  std::list<SymType> emptyList;
  std::list<SymType> * fullList;
  std::list<Symbol *> symList;
  std::string curFunc;
  int scopeID;

  SymbolVisitor::SymbolVisitor(STManager m){
    manager = m;
    scopeID = -1;
  }

 std::any SymbolVisitor::visitCompilationUnit(WPLParser::CompilationUnitContext *ctx) {
      //std::cout << "Enetering" << std::endl;
      manager.enterScope();
      for (auto e : ctx->cuComponent()) {
        e->accept(this);
      }

      manager.checkForUninitialized();

      return NULL;

  }

  std::any SymbolVisitor::visitScalarDeclaration(WPLParser::ScalarDeclarationContext *ctx) {
    std::string strType = "";
    if(ctx->t != NULL){
      strType = ctx->t->getText();
    }else{
      strType = "var";
    }

    if(strType == "var"){
      curType = UNDEFINED;
    }else if(strType == "int"){
      curType = INT;
    }else if(strType == "str"){
      curType = STRING;
    }else if(strType == "boolean"){
      curType = BOOL;
    }

    for (auto e : ctx->scalars) {
        e->accept(this);
    }
    curType = ERROR;
    return NULL;
  }

  std::any SymbolVisitor::visitScalar(WPLParser::ScalarContext *ctx) {
    if(ctx->varInitializer() != NULL){
        initializerType = ERROR;
        ctx->varInitializer()->accept(this);
        if(initializerType != curType && curType != UNDEFINED && initializerType != UNDEFINED){
            throw std::logic_error( "incompatible types for " + ctx->ID()->getText() );
        }
        Symbol * s = new Symbol(ctx->ID()->getText(), initializerType, 0, emptyList, VAR);
        Symbol* ns = manager.addSymbol(*s);

        if(ns == nullptr){
          throw std::logic_error( "redeclared variable " + ctx->ID()->getText() );
        }
        initializerType = ERROR;
        return NULL;

    }

    Symbol * s = new Symbol(ctx->ID()->getText(), curType, 0, emptyList, VAR);
    Symbol* ns = manager.addSymbol(*s);

    if(ns == nullptr){
      throw std::logic_error( "redeclared variable " + ctx->ID()->getText() );
    }

    return NULL;
  }

  std::any SymbolVisitor::visitArrayDeclaration(WPLParser::ArrayDeclarationContext *ctx) {
    std::string strType = ctx->typename_->getText();
    if(strType == "var"){
      curType = UNDEFINED;
    }else if(strType == "int"){
      curType = INT;
    }else if(strType == "str"){
      curType = STRING;
    }else if(strType == "boolean"){
      curType = BOOL;
    }

    Symbol * s = new Symbol(ctx->ID()->getText(), curType, stoi(ctx->INTEGER()->getText()), emptyList, ARR);

    Symbol* ns = manager.addSymbol(*s);
    if(ns == nullptr){
      throw std::logic_error( "redeclared variable " + ctx->ID()->getText() );
    }
    curType = ERROR;
    return NULL;
  }

  std::any SymbolVisitor::visitVarInitializer(WPLParser::VarInitializerContext *ctx) {
    if(ctx->c->INTEGER() != NULL){
      initializerType = INT;
    }else if(ctx->c->STRING() != NULL){
      initializerType = STRING;
    }else if(ctx->c->BOOLEAN() != NULL){
      initializerType = BOOL;
    }

    return NULL;
  }

  std::any SymbolVisitor::visitExternDeclaration(WPLParser::ExternDeclarationContext *ctx) {
    if(ctx->externProcHeader() != NULL){
      ctx->externProcHeader()->accept(this);
    }else if(ctx->externFuncHeader() != NULL){
      ctx->externFuncHeader()->accept(this);
    }
    return NULL;
  }

  std::any SymbolVisitor::visitProcedure(WPLParser::ProcedureContext *ctx) {
    ctx->procHeader()->accept(this);
    ctx->block()->accept(this);
    curFunc = "";
    return NULL;
  }

   std::any  SymbolVisitor::visitProcHeader(WPLParser::ProcHeaderContext *ctx) {
    fullList = new std::list<SymType>();
    if(ctx->p != NULL){
      ctx->p->accept(this);
    }

    Symbol * s = new Symbol(ctx->id->getText(), NA, 0, *fullList, FUNC);

    Symbol* ns = manager.addSymbol(*s);
    if(ns == nullptr){
      throw std::logic_error( "redeclared variable " + ctx->ID()->getText() );
    }

    manager.enterScope();
    scopeID = manager.currentScope->getId();
    for (auto e : symList) {
        Symbol* ns = manager.addSymbol(*e);
        if(ns == nullptr){
          throw std::logic_error( "redeclared variable " + ctx->ID()->getText() );
        }
    }

    symList.clear();
    curFunc = ctx->id->getText();
    return NULL;
  }

  std::any  SymbolVisitor::visitExternProcHeader(WPLParser::ExternProcHeaderContext *ctx) {
    fullList = new std::list<SymType>();
    if(ctx->params() != NULL){
      ctx->params()->accept(this);
    }

    Symbol * s = new Symbol(ctx->id->getText(), NA, 0, *fullList, XFUNC);

    Symbol* ns = manager.addSymbol(*s);
    if(ns == nullptr){
      throw std::logic_error( "redeclared variable " + ctx->ID()->getText() );
    }

    if(ctx->ELLIPSIS() != NULL){
        s->elips = true;
    }

    manager.enterScope();
    for (auto e : symList) {
        Symbol* ns = manager.addSymbol(*e);
        if(ns == nullptr){
          throw std::logic_error( "redeclared variable " + ctx->ID()->getText() );
        }
    }
    manager.exitScope();
    symList.clear();
    return NULL;
  }

  std::any  SymbolVisitor::visitFunction(WPLParser::FunctionContext *ctx) {
    ctx->funcHeader()->accept(this);
    ctx->block()->accept(this);
    curFunc=  "";
    return NULL;
  }

  std::any  SymbolVisitor::visitFuncHeader(WPLParser::FuncHeaderContext *ctx) {
    fullList = new std::list<SymType>();
    if(ctx->p != NULL){
      ctx->p->accept(this);
    }

    std::string strType = ctx->t->getText();
    SymType tempType;
    if(strType == "var"){
      tempType = UNDEFINED;
    }else if(strType == "int"){
      tempType = INT;
    }else if(strType == "str"){
      tempType = STRING;
    }else if(strType == "boolean"){
      tempType = BOOL;
    }

    Symbol * s = new Symbol(ctx->id->getText(), tempType, 0, *fullList, FUNC);

    Symbol* ns = manager.addSymbol(*s);
    if(ns == nullptr){
      throw std::logic_error( "redeclared variable " + ctx->ID()->getText() );
    }

    manager.enterScope();
    scopeID = manager.currentScope->getId();
    for (auto e : symList) {
        Symbol* ns = manager.addSymbol(*e);
        if(ns == nullptr){
          throw std::logic_error( "redeclared variable " + ctx->ID()->getText() );
        }
    }
    symList.clear();
    curFunc = ctx->id->getText();
    return NULL;
  }

  std::any  SymbolVisitor::visitExternFuncHeader(WPLParser::ExternFuncHeaderContext *ctx) {
    fullList = new std::list<SymType>();
    if(ctx->params() != NULL){
        ctx->params()->accept(this);
    }

    std::string strType = ctx->t->getText();
    SymType tempType;
    if(strType == "var"){
      tempType = UNDEFINED;
    }else if(strType == "int"){
      tempType = INT;
    }else if(strType == "str"){
      tempType = STRING;
    }else if(strType == "boolean"){
      tempType = BOOL;
    }

    Symbol * s = new Symbol(ctx->id->getText(), tempType, 0, *fullList, XFUNC);

    Symbol* ns = manager.addSymbol(*s);
    if(ns == nullptr){
      throw std::logic_error( "redeclared variable " + ctx->ID()->getText() );
    }

    if(ctx->ELLIPSIS() != NULL){
        s->elips = true;
    }

    manager.enterScope();
    for (auto e : symList) {
        Symbol* ns = manager.addSymbol(*e);
        if(ns == nullptr){
          throw std::logic_error( "redeclared variable " + ctx->ID()->getText() );
        }
    }
    manager.exitScope();
    symList.clear();

    return NULL;
  }

  std::any  SymbolVisitor::visitParams(WPLParser::ParamsContext *ctx) {
    int i = 0;
    for (auto e : ctx->type()) {
        if(e->INT() != NULL){
          fullList->push_back(INT);
          Symbol * s = new Symbol(ctx->ID()[i]->getText(), INT, 0, emptyList, VAR);
          symList.push_back(s);
        }else if(e->STR() != NULL){
          fullList->push_back(STRING);
          Symbol * s = new Symbol(ctx->ID()[i]->getText(), STRING, 0, emptyList, VAR);
          symList.push_back(s);
        }else if(e->BOOL() != NULL){
          fullList->push_back(BOOL);
          Symbol * s = new Symbol(ctx->ID()[i]->getText(), BOOL, 0, emptyList, VAR);
          symList.push_back(s);
        }
        i++;
    }
    return NULL;
  }
//will allready be in a new scope
  std::any  SymbolVisitor::visitBlock(WPLParser::BlockContext *ctx) {
    if(scopeID == -1){
        manager.enterScope();
    }else{
        manager.enterScope(scopeID);
        scopeID = -1;
    }
    visitChildren(ctx);
    manager.exitScope();
    return NULL;
  }


  std::any  SymbolVisitor::visitLoop(WPLParser::LoopContext *ctx) {
    curType = BOOL; //make sure the expression is a boolean
    ctx->e->accept(this);
    curType = ERROR;
    ctx->block()->accept(this);
    return NULL;
  }

  std::any  SymbolVisitor::visitConditional(WPLParser::ConditionalContext *ctx) {
    curType = BOOL; //make sure the expression is a boolean
    ctx->e->accept(this);
    curType = ERROR;
    for (auto e : ctx->block()) {
        e->accept(this);
    }
    return NULL;
  }

  std::any  SymbolVisitor::visitSelect(WPLParser::SelectContext *ctx) {
    for (auto e : ctx->selectAlt()) {
        e->accept(this);
    }
    return NULL;
  }

  std::any  SymbolVisitor::visitSelectAlt(WPLParser::SelectAltContext *ctx) {
    curType = BOOL; //make sure the expression is a boolean
    ctx->e->accept(this);
    curType = ERROR;
    ctx->s->accept(this);
    return NULL;
  }

  std::any  SymbolVisitor::visitCall(WPLParser::CallContext *ctx) { //func(a, 3);

    Symbol* ns = manager.findSymbol(ctx->id->getText());//check if the func is defined
    funcName = ctx->id->getText();
    if(ns == nullptr){
      throw std::logic_error( "undeclared function or procedure " + ctx->ID()->getText() );
    }
    if(ns->clss != FUNC && ns->clss != XFUNC){
        throw std::logic_error( ctx->ID()->getText() + " is not a function or procedure" );
    }
    fullList = &(ns->params);
    if(ctx->arguments() != NULL){
        ctx->arguments()->accept(this);
    }
    fullList = nullptr;
    funcName = "";
    return NULL;
  }

  std::any  SymbolVisitor::visitArguments(WPLParser::ArgumentsContext *ctx) {

    Symbol* ns = manager.findSymbol(funcName);//check if the var exists


    if(ctx->arg().size() != fullList->size() && !ns->elips){
      throw std::logic_error("Improper amount of arguments");
    }


    std::list<SymType>::iterator types = fullList->begin();
    int i = 0;
     for (auto e : ctx->arg()) {
        if( i >= fullList->size()){
            break;
        }
        curType = *types;
        e->accept(this);
        curType = ERROR;
        types++;
        i++;
    }

    return NULL;
  }

  std::any  SymbolVisitor::visitArg(WPLParser::ArgContext *ctx) {
    SymType typ;
    if(ctx->c != NULL){
        if(ctx->c->INTEGER() != nullptr){
          typ = INT;
        }else if(ctx->c->STRING() != nullptr){
          typ = STRING;
        }else if(ctx->c->BOOLEAN() != nullptr){
          typ = BOOL;
        }
    }else if(ctx->id != NULL){
        Symbol* ns = manager.findSymbol(ctx->id->getText());//check if the func is defined
        if(ns == nullptr){
          throw std::logic_error( "undeclared variable " + ctx->ID()->getText() );
        }
        if(ns->type == UNDEFINED){
            ns->type = curType;
        }
        typ = ns->type;
    }

    if(typ != curType){
      throw std::logic_error( "Types don't match");
    }
    return NULL;
  }

  std::any  SymbolVisitor::visitReturn(WPLParser::ReturnContext *ctx) {
    Symbol* ns = manager.findSymbol(curFunc);//check if the func is defined
    if(ns == nullptr){
       throw std::logic_error( "Compiler error at SymbolVisitor.visitReturn ");
    }
    curType = ns->type;
    if(ctx->expr() != NULL){
        ctx->expr()->accept(this);
    }
    curType = ERROR;
    return NULL;
  }

  std::any  SymbolVisitor::visitAssignment(WPLParser::AssignmentContext *ctx) {

    if(ctx->arrayIndex() == nullptr){  //variable assign
        if(ctx->exprs.size() != ctx->targets.size()){
          throw std::logic_error("Improper amount of assignments");
        }
        std::vector<antlr4::Token *>::iterator ids = ctx->targets.begin();
        std::vector<WPLParser::ExprContext *>::iterator eps = ctx->exprs.begin();
        while (ids != ctx->targets.end() && eps != ctx->exprs.end()){
            Symbol* ns = manager.findSymbol((*ids)->getText());//check if the var
            if(ns == nullptr){
              throw std::logic_error( "undeclared variable " + (*ids)->getText() );
            }
            if(ns->clss != VAR){
              throw std::logic_error( (*ids)->getText() + " is not a variable" );
            }
            curType = ns->type;
            (*eps)->accept(this);
            //Adjust type of symbol if it is set to undefined
            if(ns->type == UNDEFINED){
                ns->type = initializerType;
            }
            initializerType = ERROR;
            curType = ERROR;
            ids++;
            eps++;
        }
    }else{ //array assign
      ctx->arrayIndex()->accept(this);//we set initializerType here
      curType = initializerType;
      for (auto e : ctx->e) {
        e->accept(this);
      }
      curType = ERROR;
      initializerType = ERROR;

    }
    return NULL;
  }

  std::any  SymbolVisitor::visitArrayIndex(WPLParser::ArrayIndexContext *ctx) {
    SymType temp = curType;
    curType = INT;
    ctx->expr()->accept(this);
    curType = temp;
    Symbol* ns = manager.findSymbol(ctx->id->getText());//check if the var exists
    if(ns == nullptr){
      throw std::logic_error( "undeclared variable " + ctx->id->getText() );
    }
    if(ns->length <= 0){
      throw std::logic_error( "variable not an array " + ctx->id->getText() );
    }
    initializerType = ns->type;//set the type

    return NULL;
  }

  std::any  SymbolVisitor::visitAndExpr(WPLParser::AndExprContext *ctx) {
    if(curType != BOOL && curType != UNDEFINED){
      throw std::logic_error( "improper type");
    }
    SymType temp = curType;
    curType = BOOL;
    ctx->left->accept(this);
    ctx->right->accept(this);
    initializerType = BOOL;
    curType = temp;
    return NULL;
  }

  std::any SymbolVisitor::visitIDExpr(WPLParser::IDExprContext *ctx){
    Symbol* ns = manager.findSymbol(ctx->ID()->getText());//check if the var exists
    if(ns == nullptr){
      throw std::logic_error( "undeclared variable " + ctx->ID()->getText() );
    }
    if(ns->type != curType && ns->type != UNDEFINED  && curType != UNDEFINED){
      throw std::logic_error( "improper type");
    }
    if( ns->clss != VAR){
        throw std::logic_error( ctx->ID()->getText() + " is not a variable");
    }
    if(ns->type == UNDEFINED){
        ns->type = curType;
    }
    initializerType = ns->type;
    return NULL;
  }

  std::any SymbolVisitor::visitConstExpr(WPLParser::ConstExprContext *ctx){
    SymType typ;
    if(ctx->constant()->INTEGER() != nullptr){
      typ = INT;
    }else if(ctx->constant()->STRING() != nullptr){
      typ = STRING;
    }else if(ctx->constant()->BOOLEAN() != nullptr){
      typ = BOOL;
    }
    if(typ != curType && typ != UNDEFINED  && curType != UNDEFINED){
      throw std::logic_error( "improper type");
    }
    initializerType = typ;
    return NULL;
  }

  std::any  SymbolVisitor::visitSubscriptExpr(WPLParser::SubscriptExprContext *ctx) {
    ctx->arrayIndex()->accept(this);//this sets the initializer type to they type of the array
    if(initializerType != curType && initializerType != UNDEFINED && curType != UNDEFINED){
        throw std::logic_error( "improper type");
    }
    //initalizertype = initializertype
    return NULL;
  }

  std::any  SymbolVisitor::visitRelExpr(WPLParser::RelExprContext *ctx) {
    if(curType != BOOL && curType != UNDEFINED){
      throw std::logic_error( "improper type");
    }
    SymType temp = curType;
    curType = INT;
    ctx->left->accept(this);
    ctx->right->accept(this);
    curType = temp;
    initializerType = BOOL;
    return NULL;
  }

  std::any  SymbolVisitor::visitMultExpr(WPLParser::MultExprContext *ctx) {
    if(curType != INT && curType != UNDEFINED){
        throw std::logic_error( "improper type");
    }
    SymType temp = curType;
    curType = INT;
    ctx->left->accept(this);
    ctx->right->accept(this);
    curType = temp;
    initializerType = INT;
    return NULL;
  }

  std::any  SymbolVisitor::visitAddExpr(WPLParser::AddExprContext *ctx) {
    if(curType != INT && curType != UNDEFINED){
        throw std::logic_error( "improper type");
    }
    SymType temp = curType;
    curType = INT;
    ctx->left->accept(this);
    ctx->right->accept(this);
    curType = temp;
    initializerType = INT;
    return NULL;
  }

  std::any  SymbolVisitor::visitArrayLengthExpr(WPLParser::ArrayLengthExprContext *ctx) {
    if(curType != INT && curType != UNDEFINED){
        throw std::logic_error( "improper type");
    }
    SymType temp = curType;
    curType = INT;
    Symbol* ns = manager.findSymbol(ctx->ID()->getText());//check if the var exists
    if(ns == nullptr){
      throw std::logic_error( "undeclared variable " + ctx->ID()->getText() );
    }
    if(ns->clss != ARR ){
        throw std::logic_error( "variable not an array " + ctx->ID()->getText() );
    }
    curType = temp;
    initializerType = INT;
    return NULL;
  }

  std::any  SymbolVisitor::visitUMinusExpr(WPLParser::UMinusExprContext *ctx) {
    if(curType != INT && curType != UNDEFINED){
        throw std::logic_error( "improper type");
    }
    SymType temp = curType;
    curType = INT;
    ctx->expr()->accept(this);
    curType = temp;
    initializerType = INT;
    return NULL;
  }

  std::any  SymbolVisitor::visitOrExpr(WPLParser::OrExprContext *ctx) {
    if(curType != BOOL && curType != UNDEFINED){
      throw std::logic_error( "improper type");
    }
    SymType temp = curType;
    curType = BOOL;
    ctx->left->accept(this);
    ctx->right->accept(this);
    initializerType = BOOL;
    curType = temp;
    return NULL;
  }

  std::any  SymbolVisitor::visitEqExpr(WPLParser::EqExprContext *ctx) {
    if(curType != BOOL && curType != UNDEFINED){
      throw std::logic_error( "improper type");
    }
    SymType temp = curType;
    curType = UNDEFINED;//the first one can be any type
    ctx->left->accept(this);
    if(initializerType == UNDEFINED){ //if the left on is undefined see if right has a type and see if we can set left's type
        curType = UNDEFINED;//the right one can be any type
        ctx->right->accept(this);
        curType = initializerType;//get right's type and make sure right has that type
        ctx->left->accept(this);
    }else{
        curType = initializerType;//get left's type and make sure right has that type
        ctx->right->accept(this);
    }
    initializerType = BOOL;
    curType = temp;
    return NULL;
  }

  std::any  SymbolVisitor::visitFuncProcCallExpr(WPLParser::FuncProcCallExprContext *ctx) {
    Symbol* ns = manager.findSymbol(ctx->fpname->getText());//check if the var exists
    if(ns == nullptr){
      throw std::logic_error( "undeclared function " + ctx->fpname->getText() );
    }
    initializerType = ns->type;//set the type
    SymType temp = curType;
    if(initializerType != curType && curType != UNDEFINED && initializerType != UNDEFINED){
       throw std::logic_error( "Incompatible types");
    }
    if(ns->clss != FUNC && ns->clss != XFUNC){
        throw std::logic_error( ctx->fpname->getText() + " is not a function");
    }
    fullList = &(ns->params);
    if(ctx->args.size() != fullList->size() && !ns->elips){
      throw std::logic_error("Improper amount of arguments");
    }

    std::vector<WPLParser::ExprContext *>::iterator eps = ctx->args.begin();
    std::list<SymType>::iterator types = fullList->begin();
    int i = 0;
    while (i < fullList->size()) {
        curType = *types;
        (*eps)->accept(this);
        curType = ERROR;
        eps++;
        types++;
        i++;
    }

    curType = temp;
    initializerType = ns->type;//set the type
    return NULL;
  }

  std::any  SymbolVisitor::visitNotExpr(WPLParser::NotExprContext *ctx) {
    if(curType != BOOL && curType != UNDEFINED){
      throw std::logic_error( "improper type");
    }
    SymType temp = curType;
    curType = BOOL;
    ctx->expr()->accept(this);
    initializerType = BOOL;
    curType = temp;
    return NULL;
  }

  std::any  SymbolVisitor::visitParenExpr(WPLParser::ParenExprContext *ctx) {
    ctx->expr()->accept(this);
    return NULL;
  }
