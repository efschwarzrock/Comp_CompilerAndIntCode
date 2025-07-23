#include "CodeGenVisitor.h"
#include "llvm/IR/Value.h"


CodeGenVisitor::CodeGenVisitor(std::string moduleName, STManager m)
{

    context = new LLVMContext();
    module = new Module(moduleName, *context);
    // Use the NoFolder to turn off constant folding
    builder = new IRBuilder<NoFolder>(module->getContext());
    manager = m;
    // cached types
    VoidTy = Type::getVoidTy(module->getContext());
    Int32Ty = Type::getInt32Ty(module->getContext());
    Int1Ty = Type::getInt1Ty(module->getContext());
    Int8Ty = Type::getInt8Ty(module->getContext());
    Int1One = ConstantInt::get(Int1Ty, 1, true);
    Int32Zero = ConstantInt::get(Int32Ty, 0, true);
    Int32One = ConstantInt::get(Int32Ty, 1, true);
    i8p = Type::getInt8PtrTy(module->getContext());
    Int8PtrPtrTy = i8p->getPointerTo();
    scope = 1;
    globalVars = true;
    glbVarName = "";
    curGlobalFunction = nullptr;
    selectBlockGlobal = nullptr;
    fSelectBlockGlobal = nullptr;
    continueBlock = nullptr;
    arrayElePtr = nullptr;
}

void CodeGenVisitor::enterScope(){
    manager.enterScope(scope);
    scope = scope + 1;
}

Type* CodeGenVisitor::getType(Symbol s){
    if(s.type == INT){
        return Int32Ty;
    }else if(s.type == BOOL){
        return Int32Ty;
    }else if(s.type == STRING){
        return i8p;
    }else if(s.type == NA){
        return VoidTy;
    }
    return NULL;
}

Type* CodeGenVisitor::getType(SymType s){
    if(s == INT){
        return Int32Ty;
    }else if(s == BOOL){
        return Int32Ty;
    }else if(s == STRING){
        return i8p;
    }else if(s == NA){
        return VoidTy;
    }
    return NULL;
}

Type* CodeGenVisitor::getArrayType(SymType s){
    if(s == INT){
        return Int32Ty->getPointerTo();
    }else if(s == BOOL){
        return Int32Ty->getPointerTo();
    }else if(s == STRING){
        return i8p->getPointerTo();
    }else if(s == NA){
        return VoidTy;
    }
    return NULL;
}

Constant* CodeGenVisitor::getGlobalVarInitializer(Symbol s, Value* v){

    if(s.type == INT || s.type == BOOL){
        int constIntValue;
        if (ConstantInt* CI = dyn_cast<ConstantInt>(v)) {
              if (CI->getBitWidth() <= 32) {
                constIntValue = CI->getSExtValue();
              }
        }
        return ConstantInt::get(Int32Ty, APInt(32,constIntValue));
    }else if(s.type == STRING){
        return ConstantInt::get(i8p, APInt(8,0));;
    }else if(s.type == NA){
        return nullptr;
    }
    return NULL;
}

std::any CodeGenVisitor::visitCompilationUnit(WPLParser::CompilationUnitContext *ctx){

    // 4. Generate the globalVariables.
    for (auto e : ctx->cuComponent()) {
        e->accept(this);
    }
    this->globalVars = false;
    // 4. Generate the code for all of the expression in the block.
    for (auto e : ctx->cuComponent()) {
        e->accept(this);
    }





    // 5. output the code.
    //module->print(llvm::errs(),nullptr,false,true);
    return nullptr;

}

std::any CodeGenVisitor::visitScalar(WPLParser::ScalarContext *ctx){
    if(this->globalVars){
          std::string varName = ctx->ID()->getText();
          Symbol *sym = manager.findSymbol(varName);
          Type *type = this->getType(*sym);
          module->getOrInsertGlobal(varName, type);
          GlobalVariable *gVar = module->getNamedGlobal(varName);
          gVar->setDSOLocal(true);
          sym->defined = true;
          sym->val = gVar;
          if(ctx->varInitializer() != NULL){
                if(sym->type != STRING){
                    Value* glblVarVal = std::any_cast<Value *>(ctx->varInitializer()->accept(this));
                    gVar->setInitializer(getGlobalVarInitializer(*sym, glblVarVal));
                }else{
                    glbVarName = varName;
                    Value* glblVarVal = std::any_cast<Value *>(ctx->varInitializer()->accept(this));
                    gVar->setInitializer(getGlobalVarInitializer(*sym, glblVarVal));
                    glbVarName = "";
                    arrayGlobalStrings.push_back(sym);
                    arrayGlobalStringsValues.push_back(glblVarVal);
                    std::cout<<arrayGlobalStrings.size();
                }
          }
    }else{
          std::string varName = ctx->ID()->getText();
          Symbol *sym = manager.findSymbol(varName);
          Value *v = nullptr;
          if(!sym->defined){
                // Define the symbol and allocate memory.
              v = builder->CreateAlloca(this->getType(*sym), 0, varName);
              sym->defined = true;
              sym->val = v;
              if(ctx->varInitializer() != NULL){

                    glbVarName = varName;
                    builder->CreateStore(std::any_cast<Value *>(ctx->varInitializer()->accept(this)), v);
                    glbVarName = "";

              }
          }else{
              v = sym->val;
          }

          return v;
    }
    return nullptr;
}

std::any  CodeGenVisitor::visitAssignment(WPLParser::AssignmentContext *ctx) {
    if(ctx->arrayIndex() == nullptr){  //variable assign
        if(ctx->exprs.size() != ctx->targets.size()){
          throw std::logic_error("Improper amount of assignments");
        }
        std::vector<antlr4::Token *>::iterator ids = ctx->targets.begin();
        std::vector<WPLParser::ExprContext *>::iterator eps = ctx->exprs.begin();
        while (ids != ctx->targets.end() && eps != ctx->exprs.end()){
            Symbol* sym = manager.findSymbol((*ids)->getText());//check if the var
            glbVarName = (*ids)->getText();
            builder->CreateStore(std::any_cast<Value *>((*eps)->accept(this)), sym->val);

            glbVarName = "";
            ids++;
            eps++;
        }
    }else{ //array assign
        ctx->arrayIndex()->accept(this);
        std::vector<WPLParser::ExprContext *>::iterator eps = ctx->e.begin();
        builder->CreateStore(std::any_cast<Value *>((*eps)->accept(this)), arrayElePtr);
    }
    return NULL;
  }

std::any CodeGenVisitor::visitConstant(WPLParser::ConstantContext *ctx){
    if(ctx->INTEGER() != NULL){
        int i = std::stoi(ctx->INTEGER()->getText());
        Value *v = builder->getInt32(i);
        return v;
    }else if(ctx->STRING() != NULL){
        Constant *v = builder->CreateGlobalStringPtr(ctx->STRING()->getText(), glbVarName, 0, module);
        Value *var = v;
        return var;
    }else if(ctx->BOOLEAN() != NULL){
        if(ctx->BOOLEAN()->getText() == "true"){
            Value *v = builder->getInt32(1);

            return v;
        }else{
            Value *v = builder->getInt32(0);
            return v;
        }
    }

    return nullptr;
}

std::any CodeGenVisitor::visitExternDeclaration(WPLParser::ExternDeclarationContext *ctx) {
    if(this->globalVars){
        return nullptr;
    }
    // 1. Declare external functions.
    std::string exName = "";
    bool elips = false;
    if(ctx->externProcHeader() != NULL){
      exName = ctx->externProcHeader()->ID()->getText();
      elips = ctx->externProcHeader()->ELLIPSIS() != NULL;
    }else if(ctx->externFuncHeader() != NULL){
      exName = ctx->externFuncHeader()->ID()->getText();
      elips = ctx->externFuncHeader()->ELLIPSIS() != NULL;
    }

    Symbol *sym = manager.findSymbol(exName);
    Type *returnType = this->getType(*sym);
    std::vector< Type* > *typeVec = new std::vector<Type*>();
    for(auto param: sym->params){
        typeVec->push_back(this->getType(param));
    }
    ArrayRef< Type * > *params = new ArrayRef< Type * >(*typeVec);

    auto ExFunc_prototype = FunctionType::get(returnType, *params, elips);
    auto extern_fn = Function::Create(ExFunc_prototype, Function::ExternalLinkage, exName, module);
    FunctionCallee *externExpr = new FunctionCallee(ExFunc_prototype, extern_fn);
    sym->func = externExpr;
    this->enterScope();
    manager.exitScope();
    return nullptr;
}

std::any CodeGenVisitor::visitProcedure(WPLParser::ProcedureContext *ctx){

    if(this->globalVars){
        return nullptr;
    }
    std::string procName = ctx->procHeader()->ID()->getText();

    Symbol *sym = manager.findSymbol(procName);
    std::vector< Type* > *typeVec = new std::vector<Type*>();
    for(auto param: sym->params){
        typeVec->push_back(this->getType(param));
    }
    ArrayRef< Type * > *params = new ArrayRef< Type * >(*typeVec);
    //Define a proc
    FunctionType *procType = FunctionType::get(VoidTy, *params, false);
    Function *proc = Function::Create(procType,     GlobalValue::ExternalLinkage,
    procName, module);
    FunctionCallee *procCallee = new FunctionCallee(procType, proc);
    sym->func = procCallee;
    // 3. Create a basic block and attach it to the builder.
    BasicBlock *bBlock = BasicBlock::Create(module->getContext(), "entry", proc);
    builder->SetInsertPoint(bBlock);

    this->enterScope();
    Function* tempFunc = curGlobalFunction;
    curGlobalFunction = proc;

    if(ctx->procHeader()->params() != NULL){
        Argument* llvmArgs = proc->args().begin();
        for( auto paramID: ctx->procHeader()->params()->ID()){
            Symbol* sym = manager.findSymbol((paramID)->getText());//get var
            Value* v = builder->CreateAlloca(this->getType(*sym), 0, (paramID)->getText());
            builder->CreateStore(llvmArgs, v);
            sym->defined = true;
            sym->val = v;

            llvmArgs++;
        }
    }
    scope = scope - 1;
    ctx->block()->accept(this);
    curGlobalFunction = tempFunc;

    return nullptr;
}

std::any CodeGenVisitor::visitFunction(WPLParser::FunctionContext *ctx){

    if(this->globalVars){
        return nullptr;
    }
    std::string funcName = ctx->funcHeader()->ID()->getText();
    fName = funcName;
    Symbol *sym = manager.findSymbol(funcName);
    Type *returnType = this->getType(*sym);
    std::vector< Type* > *typeVec = new std::vector<Type*>();
    for(auto param: sym->params){
        typeVec->push_back(this->getType(param));
    }
    ArrayRef< Type * > *params = new ArrayRef< Type * >(*typeVec);
    //Define a func
    FunctionType *funcType = FunctionType::get(returnType, *params, false);
    Function *func = Function::Create(funcType,     GlobalValue::ExternalLinkage,
    funcName, module);
    FunctionCallee *funcCallee = new FunctionCallee(funcType, func);
    sym->func = funcCallee;
    // 3. Create a basic block and attach it to the builder.
    BasicBlock *bBlock = BasicBlock::Create(module->getContext(), "entry", func);
    builder->SetInsertPoint(bBlock);

    // set the parameters
    this->enterScope();
    Function* tempFunc = curGlobalFunction;
    curGlobalFunction = func;
    if(ctx->funcHeader()->params() != NULL){
        Argument* llvmArgs = func->args().begin();
        for( auto paramID: ctx->funcHeader()->params()->ID()){
            Symbol* sym = manager.findSymbol((paramID)->getText());//get var
            Value* v = builder->CreateAlloca(this->getType(*sym), 0, (paramID)->getText());
            builder->CreateStore(llvmArgs, v);
            sym->defined = true;
            sym->val = v;

            llvmArgs++;
        }
    }
    scope = scope - 1;
    // 4. Generate code for all expressions in the block.
    ctx->block()->accept(this);
    curGlobalFunction = tempFunc;

    return nullptr;

}

std::any CodeGenVisitor::visitReturn(WPLParser::ReturnContext *ctx){
    if(ctx->expr() != NULL){
        auto acceptRet = ctx->expr()->accept(this);
        Value* val = nullptr;
        try {
          // Block of code to try
          val = std::any_cast<Value *>(acceptRet);
        }
        catch (const std::exception& ex) {
          // Block of code to handle errors
          val = std::any_cast<Constant *>(acceptRet);
        }
        builder->CreateRet(val);
    }else{
        builder->CreateRetVoid();
    }
    return nullptr;
}

std::any CodeGenVisitor::visitIDExpr(WPLParser::IDExprContext *ctx){
    Symbol *sym = manager.findSymbol(ctx->ID()->getText());
    Value* v = nullptr;
    v = builder->CreateLoad(CodeGenVisitor::getType(*sym), sym->val, sym->identifier);


    return v;
}

std::any CodeGenVisitor::visitAddExpr(WPLParser::AddExprContext *ctx){

    Value* v = nullptr;
    Value* left = std::any_cast<Value *>(ctx->left->accept(this));
    Value* right = std::any_cast<Value *>(ctx->right->accept(this));
    if(ctx->PLUS() != NULL){
        v = builder->CreateNSWAdd(left, right);
    }else{
        v = builder->CreateNSWSub(left, right);
    }
    return v;
}

std::any CodeGenVisitor::visitMultExpr(WPLParser::MultExprContext *ctx){
    Value* v = nullptr;
    Value* left = std::any_cast<Value *>(ctx->left->accept(this));
    Value* right = std::any_cast<Value *>(ctx->right->accept(this));
    if(ctx->MUL() != NULL){
        v = builder->CreateNSWMul(left, right);
    }else{
        v = builder->CreateSDiv(left, right);
    }
    return v;
}

std::any CodeGenVisitor::visitUMinusExpr(WPLParser::UMinusExprContext *ctx){
    Value* v = std::any_cast<Value *>(ctx->expr()->accept(this));
    v = builder->CreateNSWSub(builder->getInt32(0), v);
    return v;
}

std::any CodeGenVisitor::visitRelExpr(WPLParser::RelExprContext *ctx){
    Value* v1 = nullptr;
    Value* left = std::any_cast<Value *>(ctx->left->accept(this));
    Value* right = std::any_cast<Value *>(ctx->right->accept(this));

    if(ctx->LESS() != NULL){
        v1 = builder->CreateICmpSLT(left, right);
    }else if(ctx->LEQ() != NULL){
        v1 = builder->CreateICmpSLE(left, right);
    }else if(ctx->GTR() != NULL){
        v1 = builder->CreateICmpSGT(left, right);
    }else if(ctx->GEQ() != NULL){
        v1 = builder->CreateICmpSGE(left, right);
    }
    Value *v = builder->CreateZExtOrTrunc(v1, CodeGenVisitor::Int32Ty);

    return v;

}

std::any CodeGenVisitor::visitNotExpr(WPLParser::NotExprContext *ctx){
    Value *v = std::any_cast<Value *>(ctx->expr()->accept(this));
  v = builder->CreateZExtOrTrunc(v, CodeGenVisitor::Int1Ty);
  v = builder->CreateXor(v, CodeGenVisitor::Int1One);
  v = builder->CreateZExtOrTrunc(v, CodeGenVisitor::Int32Ty);

    return v;

}

std::any CodeGenVisitor::visitAndExpr(WPLParser::AndExprContext *ctx){
    Value *vl = std::any_cast<Value *>(ctx->left->accept(this));
    Value *vr = std::any_cast<Value *>(ctx->right->accept(this));
  vl = builder->CreateZExtOrTrunc(vl, CodeGenVisitor::Int1Ty);
  vr = builder->CreateZExtOrTrunc(vr, CodeGenVisitor::Int1Ty);
  Value* v = builder->CreateAnd(vl, vr);
  v = builder->CreateZExtOrTrunc(v, CodeGenVisitor::Int32Ty);

    return v;


}

std::any CodeGenVisitor::visitOrExpr(WPLParser::OrExprContext *ctx){
    Value *vl = std::any_cast<Value *>(ctx->left->accept(this));
    Value *vr = std::any_cast<Value *>(ctx->right->accept(this));
  vl = builder->CreateZExtOrTrunc(vl, CodeGenVisitor::Int1Ty);
  vr = builder->CreateZExtOrTrunc(vr, CodeGenVisitor::Int1Ty);
  Value* v = builder->CreateOr(vl, vr);
  v = builder->CreateZExtOrTrunc(v, CodeGenVisitor::Int32Ty);

    return v;


}

std::any CodeGenVisitor::visitEqExpr(WPLParser::EqExprContext *ctx){
    Value* v1 = nullptr;
    Value* left = std::any_cast<Value *>(ctx->left->accept(this));
    Value* right = std::any_cast<Value *>(ctx->right->accept(this));
    if(ctx->EQUAL() != NULL){
        v1 = builder->CreateICmpEQ(left, right);
    }else{
        v1 = builder->CreateICmpNE(left, right);
    }

    Value *v = builder->CreateZExtOrTrunc(v1, CodeGenVisitor::Int32Ty);
    return v;
}

std::any CodeGenVisitor::visitParenExpr(WPLParser::ParenExprContext *ctx){


    Value *v = std::any_cast<Value *>(ctx->expr()->accept(this));
    return v;
}

std::any CodeGenVisitor::visitFuncProcCallExpr(WPLParser::FuncProcCallExprContext *ctx){

    std::vector<Value*> args;
    for (auto e : ctx->expr()) {
        auto acceptRet = e->accept(this);
        Value* val = nullptr;
        try {
          // Block of code to try
          val = std::any_cast<Value *>(acceptRet);
        }
        catch (const std::exception& ex) {
          // Block of code to handle errors
          val = std::any_cast<Constant *>(acceptRet);
        }

        args.push_back(val);
    }
    Symbol *sym = manager.findSymbol(ctx->fpname->getText());
    FunctionCallee *func = sym->func;
    Value* v = builder->CreateCall(*func, makeArrayRef(args));

    return v;

}

std::any CodeGenVisitor::visitCall(WPLParser::CallContext *ctx){

    std::vector<Value*> args;
    if(ctx->arguments() != NULL){
        args = std::any_cast<std::vector<Value*>>(ctx->arguments()->accept(this));
    }
    Symbol *sym = manager.findSymbol(ctx->id->getText());
    FunctionCallee *func = sym->func;
     Value* v = builder->CreateCall(*func, makeArrayRef(args));

    return v;

}

std::any CodeGenVisitor::visitArguments(WPLParser::ArgumentsContext *ctx){

    std::vector<Value*> *args = new std::vector<Value*>();

    for (auto e : ctx->arg()) {
        args->push_back(std::any_cast<Value *>(e->accept(this)));
    }
    return *args;

}

std::any CodeGenVisitor::visitArg(WPLParser::ArgContext *ctx){
    if(ctx->c != NULL){
        if(ctx->c->STRING() != NULL){
            Value *v = std::any_cast<Value *>(ctx->c->accept(this));
            return v;
        }else{
            return ctx->c->accept(this);
        }
    }else if(ctx->id != NULL){
        Symbol *sym = manager.findSymbol(ctx->id->getText());
        Value* v = nullptr;
        v = builder->CreateLoad(CodeGenVisitor::getType(*sym), sym->val, sym->identifier);
        return v;
    }

    return nullptr;

}

std::any CodeGenVisitor::visitArrayLengthExpr(WPLParser::ArrayLengthExprContext *ctx){

     Symbol *sym = manager.findSymbol(ctx->ID()->getText());
     Value *v = builder->getInt32(sym->length);
     return v;

}

std::any CodeGenVisitor::visitArrayDeclaration(WPLParser::ArrayDeclarationContext *ctx){

    if(this->globalVars){
        Symbol *sym = manager.findSymbol(ctx->ID()->getText());
        ArrayType *arr = ArrayType::get(this->getType(*sym), sym->length);
        module->getOrInsertGlobal(ctx->ID()->getText(), arr);
        GlobalVariable *gVar = module->getNamedGlobal(ctx->ID()->getText());
        gVar->setLinkage(GlobalValue::CommonLinkage);

        sym->val = gVar;
        sym->defined = true;
        return gVar;
    }else{

        Symbol *sym = manager.findSymbol(ctx->ID()->getText());
        Value *aPtr;
        if(!sym->defined){
             ArrayType *arr = ArrayType::get(this->getType(*sym), sym->length);

              // alocate memeory for array
              Value *aPtr = builder->CreateAlloca(arr, 0, ctx->ID()->getText());


              sym->val = aPtr;
              sym->defined = true;
      }else{
          aPtr = sym->val;
      }



        return aPtr;
    }
    return NULL;
}

std::any CodeGenVisitor::visitArrayIndex(WPLParser::ArrayIndexContext *ctx){

    std::string id = ctx->ID()->getText();
    Value *index = std::any_cast<Value *>(ctx->expr()->accept(this));
     Symbol *sym = manager.findSymbol(id);
     std::vector<Value *> myVector = {Int32Zero, index};
    ArrayRef<Value *> arrRef = makeArrayRef(myVector);

    Value *elePtr = builder->CreateGEP( sym->val, arrRef);
    arrayElePtr = elePtr;
    Value *v = builder->CreateLoad(CodeGenVisitor::getType(*sym), elePtr);
    //efs
    return v;

}

std::any CodeGenVisitor::visitBlock(WPLParser::BlockContext *ctx){
    this->enterScope();
    if(fName.compare("program") == 0){

        while(arrayGlobalStringsValues.size() > 0){
            Symbol *sym = arrayGlobalStrings.front();
            Value *val = arrayGlobalStringsValues.front();
            arrayGlobalStringsValues.pop_front();
            arrayGlobalStrings.pop_front();
            builder->CreateStore(val, sym->val);
        }
    }
    std::any ret = visitChildren(ctx);
    manager.exitScope();
    return ret;
}

std::any CodeGenVisitor::visitConditional(WPLParser::ConditionalContext *ctx) {
  // Create the basic block for the "true" path
  BasicBlock *trueBlock = BasicBlock::Create(module->getContext(), "bTrue", curGlobalFunction);
  // Create the "false" path basic block if needed
  BasicBlock *falseBlock = nullptr;
  if (ctx->block().size() > 1) {
    falseBlock = BasicBlock::Create(module->getContext(), "bFalse", curGlobalFunction);
  }
  // Create the basic block following the condition.
  BasicBlock *continueBlock = BasicBlock::Create(module->getContext(), "bContinue", curGlobalFunction);

  if(falseBlock == nullptr){
    falseBlock = continueBlock;
  }

  // Evaluate the expression (true or false).
  Value* eResult = std::any_cast<Value *>(ctx->expr()->accept(this));

  //translate it into i1
  eResult = builder->CreateZExtOrTrunc(eResult, CodeGenVisitor::Int1Ty);
  // Jump to the appropriate block
  builder->CreateCondBr(eResult, trueBlock, falseBlock);

  // Generate the true block
  builder->SetInsertPoint(trueBlock);
  (ctx->block().front())->accept(this);
  builder->CreateBr(continueBlock);   // go to the continuation

  // If if-then-else generate the false block
  if (falseBlock != continueBlock) {
    builder->SetInsertPoint(falseBlock);
    (ctx->block().back())->accept(this);
    builder->CreateBr(continueBlock); // go to the continuation

  }

  builder->SetInsertPoint(continueBlock);

  return NULL;
  // Continue
}

std::any CodeGenVisitor::visitLoop(WPLParser::LoopContext *ctx) {
  // Create the basic block for the "true" path
  BasicBlock *trueBlock = BasicBlock::Create(module->getContext(), "lTrue", curGlobalFunction);

  // Create the basic block following the condition.
  BasicBlock *continueBlock = BasicBlock::Create(module->getContext(), "lContinue", curGlobalFunction);
  // Evaluate the expression (true or false).
  Value* eResult = std::any_cast<Value *>(ctx->expr()->accept(this));
  //translate it into i1
  eResult = builder->CreateZExtOrTrunc(eResult, CodeGenVisitor::Int1Ty);
  // Jump to the appropriate block
  builder->CreateCondBr(eResult, trueBlock, continueBlock);

  // Generate the true block
  builder->SetInsertPoint(trueBlock);
  ctx->block()->accept(this);
  // Evaluate the expression (true or false).
  Value* eResult2 = std::any_cast<Value *>(ctx->expr()->accept(this));
  //translate it into i1
  eResult2 = builder->CreateZExtOrTrunc(eResult2, CodeGenVisitor::Int1Ty);
  builder->CreateCondBr(eResult2, trueBlock, continueBlock);




  builder->SetInsertPoint(continueBlock);

  return NULL;
  // Continue
}

std::any CodeGenVisitor::visitSelect(WPLParser::SelectContext *ctx) {

    int statementNum = 0;
    BasicBlock* blockArr[ctx->selectAlt().size()];
    BasicBlock* fBlockArr[ctx->selectAlt().size()];
    for(auto s : ctx->selectAlt()){
        blockArr[statementNum] = BasicBlock::Create(module->getContext(), "SelectPt" + std::to_string(statementNum), curGlobalFunction);
        fBlockArr[statementNum] = BasicBlock::Create(module->getContext(), "FSelectPt" + std::to_string(statementNum), curGlobalFunction);

        statementNum = statementNum + 1;
    }

    continueBlock = BasicBlock::Create(module->getContext(), "bContinue", curGlobalFunction);

    statementNum = 0;
    for(auto s : ctx->selectAlt()){
        selectBlockGlobal = blockArr[statementNum];
        fSelectBlockGlobal = fBlockArr[statementNum];
        s->accept(this);
        statementNum = statementNum + 1;
    }
    builder->CreateBr(continueBlock);

    builder->SetInsertPoint(continueBlock);


  return NULL;
  // Continue
}

std::any CodeGenVisitor::visitSelectAlt(WPLParser::SelectAltContext *ctx) {


  // Evaluate the expression (true or false).
  Value* eResult = std::any_cast<Value *>(ctx->expr()->accept(this));
  //translate it into i1
  eResult = builder->CreateZExtOrTrunc(eResult, CodeGenVisitor::Int1Ty);
  // Jump to the appropriate block
  builder->CreateCondBr(eResult, selectBlockGlobal, fSelectBlockGlobal);

  // Generate the true block
  builder->SetInsertPoint(selectBlockGlobal);
  ctx->statement()->accept(this);
  builder->CreateBr(continueBlock);

  //check the next statement
  builder->SetInsertPoint(fSelectBlockGlobal);


  return NULL;
  // Continue
}

//std::any_cast<Value *>(