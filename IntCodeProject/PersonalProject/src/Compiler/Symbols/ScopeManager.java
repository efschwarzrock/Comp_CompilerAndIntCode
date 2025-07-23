package Compiler.Symbols;

import java.util.HashMap;

public class ScopeManager {
    public Scope global;
    public HashMap<String, Scope> scopes;

    public ScopeManager(){
        this.global = new Scope("global");
        this.scopes = new HashMap<>();
    }

    public Symbol getSymbol(String name, String scope){
        Scope curScope = this.scopes.get(scope);
        Symbol sym = curScope.getSymbol(name);
        if(sym == null){
            sym = this.global.getSymbol(name);
        }
        return sym;
    }

    public void addSymbol(String name, int location, String scope){
        if(scope.equals("")){
            global.addSymbol(name, location, true);
        }else{
            Scope curScope = this.scopes.get(scope);
            if(curScope == null){
                curScope = new Scope(scope);
                this.scopes.put(scope, curScope);
            }
            curScope.addSymbol(name, location, false);
        }
    }

    @Override
    public String toString(){
        String ret = this.global.toString();
        for (String key : this.scopes.keySet()) {
            ret = ret + this.scopes.get(key).toString();
        }
        return ret;
    }
}

