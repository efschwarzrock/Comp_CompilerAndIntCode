package Compiler.Symbols;

public class Symbol {
    public String name;
    public int location;
    public boolean global;
    public boolean arrayPtr;
    public int arrayType;

    public Symbol(String n, int l, boolean g){
        this.name = n;
        this.location = l;
        this.global = g;
        arrayPtr = false;
        arrayType = 0;
    }

    @Override
    public String toString(){
        return this.name + ", " + location + " " + this.global +"\n";
    }

}
