/**
 * @file rpmprinter.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 */

#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "WPLLexer.h"
#include "WPLParser.h"
#include "RPNVisitor.h"
#include "Scope.h"
#include "Symbol.h"
#include "SymbolVisitor.h"
#include "STManager.h"
#include "CodeGenVisitor.h"



int main(int argc, const char* argv[]) {

    std::string file;
    std::ifstream newfile;
    newfile.open("examples/rpnprinter/Test.txt"); //open a file to perform read operation using file object
    if (newfile.is_open()){ //checking whether the file is open
      std::string tp;
      while(getline(newfile, tp)){ //read data from file object and put it into string.
         file = file + tp + "\n"; //add line to string
      }
      newfile.close(); //close the file object.
    }
    // Provide the input text in a stream
    antlr4::ANTLRInputStream input(file);

    // Create a lexer from the input
    WPLLexer lexer(&input);

    // Create a token stream from the lexer
    antlr4::CommonTokenStream tokens(&lexer);

    // Create a parser from the token stream
    WPLParser parser(&tokens);

    // Parse the input
    WPLParser::CompilationUnitContext* tree = parser.compilationUnit();

    // Now visit the parse tree
    //std::cout << file << std::endl;
    //fflush(stdout);
    SymbolVisitor visit = SymbolVisitor(STManager());
    visit.visitCompilationUnit(tree);

    //std::cout << visit.manager.toString();

//    std::ofstream out("foo.txt");
//    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
//    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    CodeGenVisitor cg = CodeGenVisitor("123", visit.manager);
    cg.visitCompilationUnit(tree);
    return 0;
}
