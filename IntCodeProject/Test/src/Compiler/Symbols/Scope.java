package Compiler.Symbols;

import java.util.HashMap;

public class Scope {
    public String name;
    public HashMap<String, Symbol> syms;

    public Scope(String n){
        this.name = n;
        this.syms = new HashMap<>();
    }

    public Symbol getSymbol(String name){
        return syms.get(name);
    }

    public void addSymbol(String name, int location, boolean global){
        Symbol vs = new Symbol(name, location, global);
        syms.put(name, vs);
    }

    @Override
    public String toString(){
        String ret = this.name + ": #########################################################\n";

        for (String key : this.syms.keySet()) {
            ret = ret + this.syms.get(key).toString();
        }
        return ret;
    }
}
