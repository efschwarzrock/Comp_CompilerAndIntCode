package Compiler.CodeGen;

import Compiler.Symbols.SymbolTableManager;

import java.util.LinkedList;

public class Instruction {
    public int code;
    public ICode Code;

    public Instruction(int c){
        this.code = c;
        this.Code = null;
    }

    public Instruction(ICode c){
        this.code = 0;
        this.Code = c;
    }

    public void initialize(int location, CodeGenerator codeGen){
        if(this.Code == null){
            return;
        }
        this.Code.initialize(location, codeGen);
    }

    @Override
    public String toString(){
        if(this.Code == null){
            return code + ",";
        }
        return this.Code.toString();
    }

}
