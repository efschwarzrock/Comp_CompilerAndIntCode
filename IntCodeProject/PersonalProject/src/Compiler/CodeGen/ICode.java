package Compiler.CodeGen;

import Compiler.Symbols.SymbolTableManager;

import java.util.LinkedList;

public interface ICode {
    public void initialize(int location, CodeGenerator codeGen);
}
