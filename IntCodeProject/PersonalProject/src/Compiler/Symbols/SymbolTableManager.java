package Compiler.Symbols;

public class SymbolTableManager {
    public ScopeManager varSyms;
    public ScopeManager funcSyms;

    public SymbolTableManager(){
        this.varSyms = new ScopeManager();
        this.funcSyms = new ScopeManager();
    }

}
