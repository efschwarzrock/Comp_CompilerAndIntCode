package Compiler.CodeGen;

import Compiler.Symbols.SymbolTableManager;

import java.util.LinkedList;

public class GlobalLocation implements ICode {
    int loc;
    public GlobalLocation(int location) {
        loc = location;
    }

    @Override
    public void initialize(int location, CodeGenerator codeGen) {
        int numGlobals = codeGen.globals.size();
        int lastCodeIndex = codeGen.code.size();
        int firstGlobal = lastCodeIndex - numGlobals;
        loc = loc + firstGlobal;
    }

    @Override
    public String toString(){
        return loc + ",";
    }
}
