package Compiler.CodeGen;

import Compiler.Symbols.SymbolTableManager;

import java.util.LinkedList;

public class RelativeToCurLocation implements ICode {
    int loc;

    public RelativeToCurLocation(int l){
        this.loc = l;
    }

    public void initialize(int location, CodeGenerator codeGen){
        this.loc = location + this.loc;
    }

    @Override
    public String toString(){
        return loc + ",";
    }

}
