package Compiler.CodeGen;

import Compiler.Symbols.SymbolTableManager;

import java.util.LinkedList;

public class TextCode implements ICode {

    public void initialize(int location, CodeGenerator codeGen){

    }
    String loc;

    public TextCode(String s){
        this.loc = s;
    }

    @Override
    public String toString(){
        return loc + ",";
    }
}
