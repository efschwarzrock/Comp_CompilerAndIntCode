#pragma once
#include<string>
#include<sstream>
#include <list>
#include "llvm/IR/Value.h"
#include "llvm/IR/Function.h"

enum SymType {INT, BOOL, STRING, UNDEFINED, ERROR, NA};
enum SymClass {VAR, ARR, FUNC, XFUNC};

struct Symbol
{
  std::string identifier;
  SymType type;
  SymClass clss;
  int length;
  std::list<SymType> params;
  bool elips;
  bool defined;
  llvm::Value* val;
  llvm::FunctionCallee* func;



  Symbol(std::string id, SymType t, int l, std::list<SymType> p, SymClass c) {
    identifier = id;
    type = t;
    length = l;
    params = p;
    clss = c;
    defined = false;
    val = nullptr;
    func = nullptr;
    elips = false;
  }

  Symbol() {
  }

  std::string toString() const {
    std::ostringstream description;
    std::string typeName = type == INT ? "INT"
      : type == BOOL ? "BOOL" :
       type == STRING ? "STRING" :
       type == ERROR ? "ERROR" :
       type == NA ? "NULL" :"UNDEFINED";
     std::string className = clss == VAR ? "VAR"
      : clss == ARR ? "ARR" :
       clss == FUNC ? "FUNC" :"XFUNC";
    description << '[' << className << "," << identifier << ", " << typeName << ", " << length << ']';
    return description.str();
  }
};