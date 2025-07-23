/**
 * @file Scope.cpp
 * @author gpollice
 * @brief Scope (symbol table) implementation
 * @version 0.1
 * @date 2022-07-17
 */

#include "Symbol.h"
#include "Scope.h"
#include <iostream>

std::list<SymType> emptyList2;
/**
 * @brief add a symbol
 *
 * @param id
 * @param t
 * @return Symbol* the symbol added if there was not already one with the
 *  same key; otherwise, returns the original symbol and does not add the
 *  new one.
 */
Symbol* Scope::addSymbol(std::string id, SymType t, int l, std::list<SymType> p, SymClass c) {
  Symbol* s = new Symbol(id, t, l, p, c);
  auto ret = (symbols.insert(std::pair(id, s))).first;
  return ret->second;
}

/**
 * @brief add a symbol
 *
 * @param symbol
 * @return Symbol& Symbol* the symbol added if there was not already one with the
 *  same key; otherwise, returns the original symbol and does not add the
 *  new one.
 */
Symbol& Scope::addSymbol(Symbol& symbol) {
  auto ret = (symbols.insert(std::pair(symbol.identifier, &symbol))).first;
  return *(ret->second);
  }

/**
 * @brief Find a symbol in this scope
 *
 * @param id the key for the symbol
 * @return Symbol* (nullptr if the symbol is not there)
 */
Symbol* Scope::findSymbol(std::string id) {
  Symbol* s;
  std::map<std::string, Symbol*>::const_iterator i = symbols.find(id);
  if (i == symbols.end()) {
    s = nullptr;
  } else {
    s = i->second;
  }
  return s;
}

 std::string Scope::checkForUninitializedSym() {
    for(auto symbol : symbols){
        if(symbol.second->type == UNDEFINED){
            throw std::logic_error( "Uninitialized var variable " + symbol.second->identifier);
        }
    }
    return "NULL";

  }

std::string Scope::toString() const {
  std::ostringstream description;
  description << std::endl << "-------------------" << std::endl
    << "SCOPE: " << scopeId;
  if (parent != nullptr) {
    description << " PARENT: " << parent->scopeId;
  }
  description << std::endl << '{';
  for (auto sym : symbols) {
    description << std::endl << "    " << sym.second->toString();
  }
  description << std:: endl << '}' << std::endl;

  return description.str();
}
