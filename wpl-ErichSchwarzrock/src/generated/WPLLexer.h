
// Generated from WPL.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  WPLLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, BOOL = 3, INT = 4, STR = 5, VAR = 6, PROC = 7, FUNC = 8, 
    EXTERN = 9, RETURN = 10, WHILE = 11, SELECT = 12, END = 13, IF = 14, 
    THEN = 15, ELSE = 16, LENGTH = 17, AND = 18, ASSIGN = 19, EQUAL = 20, 
    GEQ = 21, GTR = 22, LEQ = 23, LESS = 24, MINUS = 25, NEQ = 26, OR = 27, 
    PLUS = 28, DIV = 29, MUL = 30, NOT = 31, COMMA = 32, SEMICOLON = 33, 
    ELLIPSIS = 34, DOT = 35, LBRACKET = 36, RBRACKET = 37, LPAR = 38, RPAR = 39, 
    LBRACE = 40, RBRACE = 41, WS = 42, INTEGER = 43, BOOLEAN = 44, ID = 45, 
    STRING = 46, COMMENT = 47
  };

  explicit WPLLexer(antlr4::CharStream *input);

  ~WPLLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

