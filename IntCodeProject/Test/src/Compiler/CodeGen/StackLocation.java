package Compiler.CodeGen;

import Compiler.Symbols.SymbolTableManager;

import java.util.LinkedList;

public class StackLocation implements ICode{
    int loc = -1;
    public void initialize(int location, CodeGenerator codeGen){
        this.loc = codeGen.code.size() + 10;
    }
    @Override
    public String toString(){
        return loc + ",";
    }
}
