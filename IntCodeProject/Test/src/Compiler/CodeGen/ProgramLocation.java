package Compiler.CodeGen;

import Compiler.Symbols.SymbolTableManager;

import java.util.LinkedList;

public class ProgramLocation implements ICode{
    int loc = -1;
    public void initialize(int location, CodeGenerator codeGen){
        this.loc = codeGen.manager.funcSyms.global.getSymbol("@program").location;
    }
    @Override
    public String toString(){
        return loc + ",";
    }
}
