package Compiler.CodeGen;

public class BlockLocation implements ICode{
    String blockName;
    int loc;

    public BlockLocation(String n){
        this.blockName = n;
        this.loc = 0;
    }


    @Override
    public void initialize(int location, CodeGenerator codeGen) {
        this.loc = codeGen.blocks.get(blockName);
    }

    @Override
    public String toString(){
        return loc + ",";
    }
}
