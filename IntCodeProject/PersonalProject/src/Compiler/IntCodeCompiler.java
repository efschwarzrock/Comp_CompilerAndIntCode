package Compiler;

import Compiler.CodeGen.CodeGenerator;
import Compiler.CodeGen.Instruction;
import Compiler.Symbols.SymbolGen;

import java.io.File;
import java.util.LinkedList;

public class IntCodeCompiler {
    public File codeFile;
    public IntCodeCompiler(File code){
        this.codeFile = code;
    }

    public String compile(){
        SymbolGen symGen = new SymbolGen(this.codeFile);
        if(!symGen.generate()){
            return "";
        }

        CodeGenerator codeGen = new CodeGenerator(this.codeFile, symGen.manager);
        if(!codeGen.generate()){
            return "";
        }

        LinkedList<Instruction> code = codeGen.code;
        for(int i = 0; i < code.size(); i++){
            code.get(i).initialize(i, codeGen);
        }
        StringBuilder codeStrBuilder = new StringBuilder();
        for (Instruction instruction : code) {
            codeStrBuilder.append(instruction.toString());
        }

        String codeStr = codeStrBuilder.toString();
        codeStr = codeStr.substring(0, codeStr.length()-1);

        return codeStr;
    }
}
