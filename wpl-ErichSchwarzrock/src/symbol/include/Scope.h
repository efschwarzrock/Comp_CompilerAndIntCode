#pragma once
#include "Symbol.h"
#include <list>
#include <map>

class Scope {
  public:
    Scope() { parent = nullptr; }
    Scope(Scope* p) { parent = p; }
    Symbol& addSymbol(Symbol& symbol);
    Symbol* addSymbol(std::string id, SymType t, int l, std::list<SymType> p, SymClass c);
    Symbol* findSymbol(std::string id);
    Scope* getParent() { return parent; }
    void setId(int id) { scopeId = id; }  // used by STManager
    int getId() { return scopeId; }
    std::string toString() const;
    std::string checkForUninitializedSym();

  private:
    int scopeId = -1;    // The index in the symbol table manager.
    Scope* parent;
    std::map<std::string, Symbol*> symbols;
};