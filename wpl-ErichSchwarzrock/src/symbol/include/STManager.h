#pragma once
#include "Scope.h"
#include <vector>

class STManager {
  public:
    STManager(){};
    Scope& enterScope();
    Scope& enterScope(int s);
    Scope& exitScope();

    // Pass through methods
    Symbol* addSymbol(Symbol& symbol);
    // Symbol* addSymbol(std::string id, SymType t);
    Symbol* findSymbol(std::string id);

    // Miscellaneous (useful for testing)
    Scope& getCurrentScope() { return *currentScope; }
    int scopeCount() { return scopes.size(); }
    std::string toString() const;
    std::string checkForUninitialized();
    Scope* currentScope = nullptr;

  private:
    std::vector<Scope*> scopes;
    int scopeNumber = 0;
};