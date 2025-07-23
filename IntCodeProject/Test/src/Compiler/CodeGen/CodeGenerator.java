package Compiler.CodeGen;

import Compiler.Symbols.Scope;
import Compiler.Symbols.SymbolTableManager;

import java.io.File;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class CodeGenerator {
    public File codeFile;
    public SymbolTableManager manager;
    private String scope;
    private int scopeStackSize;
    public LinkedList<Instruction> code;
    public LinkedList<Instruction> globals;
    public HashMap<String, Integer> blocks;
    int lastRet = 0;
    boolean inDeclared = false;
    boolean outCharDeclared = false;
    public CodeGenerator(File codeFile, SymbolTableManager manager) {
        this.scope = "";
        this.code = new LinkedList<>();
        this.codeFile = codeFile;
        this.manager = manager;
        this.globals = new LinkedList<>();
        this.blocks = new HashMap<>();
    }

    public boolean generate() {
        this.scope = "";
        Scanner codeScanner;
        try {
            codeScanner = new Scanner(this.codeFile);
        }catch (Exception e){
            System.out.println("File Not Found");
            return false;
        }
        code.add(new Instruction(109));//start stack pointer
        code.add(new Instruction(new StackLocation()));//temp stack pointer
        code.add(new Instruction(1105));//Jump to program
        code.add(new Instruction(1));//true
        code.add(new Instruction(new ProgramLocation()));//tem program start

        while (codeScanner.hasNextLine()) {
            this.process(codeScanner.nextLine(), codeScanner);
            lastRet++;
        }
        codeScanner.close();
        code.addAll(globals);
        return true;
    }

    private void process(String line, Scanner codeScanner) {
        //System.out.println(line);
        if (line.indexOf("define") == 0) {//it is beginning of function definition
            this.processFunc(line);
        }else if(line.contains("declare void @print(i8*)")){//it's the print function definition
            this.processPrintDefine();
        }else if(line.contains("declare void @outChar(i32)")){//it's the printchar function definition
            this.processOutCharDefine();
        }else if(line.contains("declare void @outInt(i32)")){//it's the printint function definition
            this.processOutIntDefine();
        }else if(line.contains("declare i32 @in()")){//it's the in function definition
            this.processInDefine();
        } else if(line.indexOf('@') == 0){//it is a global variable definition
            this.processGlobalInit(line);
        } else if (line.indexOf("  store") == 0) {//Store instruction
            this.processStore(line);
        } else if (line.contains(" = alloca ")) {//Allocate memory instruction
            this.processAllocate(line);
        } else if (line.contains("= load ")) {//load
            this.processLoad(line);
        }else if(line.contains(" = zext i1 ")){//more loads
            this.processZext(line);
        }else if(line.contains(" = trunc i32")){//more loads
            this.processTrunc(line);
        } else if (line.contains(" = getelementptr ")) {//get array element
            this.processArrElement(line, codeScanner);
        } else if (line.contains("= add ")) {//add
            this.processAdd(line);
        }else if(line.contains(" = sub")) {//subtract
            this.processSub(line);
        } else if (line.contains("= mul ")) {//mul
            this.processMul(line);
        }else if(line.contains(" = sdiv")) {//divide
            this.processDiv(line);
        }else if(line.contains(" = icmp eq ")){//equal too
            this.processEqual(line);
        }else if(line.contains(" = icmp ne ")){//not equal too
            this.processNotEqual(line);
        }else if(line.contains(" = icmp slt ")){//less than
            this.processLessThan(line);
        }else if(line.contains(" = icmp sle ")){//less than or equal
            this.processLessThanEqual(line);
        }else if(line.contains(" = icmp sgt ")){//greater than
            this.processGreaterThan(line);
        }else if(line.contains(" = icmp sge ")){//greater than or equal
            this.processGreaterThanEqual(line);
        }else if(line.contains(" = and ")){//and
            this.processAnd(line);
        }else if(line.contains(" = or ")){//or
            this.processOr(line);
        }else if(line.contains(" = xor ")){//not
            this.processNot(line);
        } else if (line.contains(" = call i32 @in()") && inDeclared) {//in extern func
            this.processInFuncCall(line);
        } else if (line.contains("call void @outChar(") && outCharDeclared){//out proc call
            this.processOutCall(line);
        } else if(line.contains("  call void")){//proc call
            this.processProcCall(line);
        } else if (line.contains(" = call ")) {//function call
            this.processFuncCall(line);
        } else if (line.contains(" ret ")) {//return
            this.processReturn(line);
        } else if (line.contains("}") && lastRet > 2 ) {//return
            this.processReturn(line);
        } else if (line.contains("; preds =")){//block
            this.processBlock(line);
        } else if (line.contains(" br i1 ")){//jump if
            this.processJumpIf(line);
        } else if (line.contains(" br label ")){//jump
            this.processJump(line);
        }
        //else if(line.length() > 0){
            //System.out.println(line);
        //}

    }

    private void processFunc(String line) {
        String funcName = line.substring(line.indexOf('@'), line.indexOf('('));
        Scope s = manager.varSyms.scopes.get(funcName);
        this.scopeStackSize = s.syms.size() + 2;//plus 2 so that we can pass in the instruction ptr and return ptr to functions we call
        this.manager.funcSyms.global.getSymbol(funcName).location = this.code.size();
        //set global vars
        this.scope = funcName;
    }

    private void processPrintDefine() {
        String funcName = "@print";
        this.manager.funcSyms.global.getSymbol(funcName).location = this.code.size();
        this.code.add(new Instruction(2101));
        this.code.add(new Instruction(0));
        this.code.add(new Instruction(0));
        this.code.add(new Instruction(new RelativeToCurLocation(9)));
        this.code.add(new Instruction(2101));
        this.code.add(new Instruction(0));
        this.code.add(new Instruction(0));
        this.code.add(new Instruction(new RelativeToCurLocation(2)));
        this.code.add(new Instruction(1006));
        this.code.add(new Instruction(5555));
        this.code.add(new Instruction(new RelativeToCurLocation(10)));
        this.code.add(new Instruction(4));
        this.code.add(new Instruction(5555));
        this.code.add(new Instruction(21201));
        this.code.add(new Instruction(0));
        this.code.add(new Instruction(1));
        this.code.add(new Instruction(0));
        this.code.add(new Instruction(1106));
        this.code.add(new Instruction(0));
        this.code.add(new Instruction(new RelativeToCurLocation(-19)));
        this.code.add(new Instruction(2106));
        this.code.add(new Instruction(0));
        this.code.add(new Instruction(-2));

        //2101, 0, 0, +9, 2101, 0, 0, +2, 1006, 5555555, +10, 04, 5555555, 21201, 0, 1, 0, 1106, 0, +-19,2106, 0, -1,
    }

    private void processOutCharDefine() {
        outCharDeclared = true;
    }

    private void processOutIntDefine() {
        boolean temp = outCharDeclared;
        outCharDeclared = true;
        String code = getOutIntCode();
        while(code.length() > 1){
            String line = code.substring(0, code.indexOf('\n'));
            code = code.substring(code.indexOf('\n') + 1);
            this.process(line, null);
        }
        outCharDeclared = temp;
    }

    private void processInDefine() {
        inDeclared = true;
    }

    private void processGlobalInit(String line) {
        //String name = line.substring(0,line.indexOf(" "));
        if(line.contains("c\"")) {//it is a string
            this.processStringInit(line);
        }else if(line.contains(" = dso_local global i8* getelementptr ")){//it is an initialized string var
            this.processStringVarInit(line);
        } else if(line.contains(" = dso_local global i32 ")){//it is an initialized int or bool
            String val = line.substring(line.lastIndexOf(' ') + 1);
            int value = Integer.parseInt(val);//can not be initialized to a variable
            globals.add(new Instruction(value));
        }else if(line.indexOf(']') == line.length()-1){//it is an array
            String lengthExtra = line.substring(line.indexOf('[')+1);
            String length = lengthExtra.substring(0, lengthExtra.indexOf(' '));
            int len = Integer.parseInt(length);
            while(len > 0){
                globals.add(new Instruction(0));
                len--;
            }
        } else{
            globals.add(new Instruction(0));
        }
    }

    private void processStore(String line) {
        if(line.contains(" getelementptr ")){
            this.processStringStore(line);
            return;
        }
        String firstHalf = line.substring(0, line.indexOf(","));
        String secondHalf = line.substring(line.indexOf(",") + 1, line.lastIndexOf(','));
        String value = firstHalf.substring(firstHalf.lastIndexOf(' ') + 1);
        String place = secondHalf.substring(secondHalf.lastIndexOf(' ') + 1);
        if(manager.varSyms.getSymbol(place, this.scope) != null && manager.varSyms.getSymbol(place, this.scope).arrayPtr){//it is an array pointer
            this.threeParamCommandRelative(1, place, "0", 4);
            //this.setArrayPtr(arrValue, index, 4);
            this.setFuncParamVals(1, value, "0", 0, manager.varSyms.getSymbol(place, this.scope).arrayType);
        }else {
            this.threeParamCommand(1, value, "0", place);//add
        }
        //store i8* getelementptr inbounds ([8 x i8], [8 x i8]* @l, i32 0, i32 0), i8** %l, align 8
        ///                                             ^^                      ^^
        //                                              index(not value)
        // call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @0, i32 0, i32 0))
    }

    private void processAllocate(String line) {
        if(line.contains(" = alloca i")){//single value
            String place = line.substring(2, line.indexOf(" = "));
            this.threeParamCommand(1, "0", "0", place);//add
        }else if(line.contains(" = alloca [")){//multi value
            String place = line.substring(2, line.indexOf(" = "));
            String sizeStr = line.substring(line.indexOf('[') + 1);
            sizeStr = sizeStr.substring(0, sizeStr.indexOf(' '));
            int size = Integer.parseInt(sizeStr);
            for(int i = 0; i < size; i++){
                this.threeParamCommand(1, "0", "0", place, i);//add
            }
        }

    }

    private void processLoad(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String secondHalf = line.substring(line.indexOf(','), line.lastIndexOf(','));
        String value = secondHalf.substring(secondHalf.lastIndexOf(' ') + 1);
        this.threeParamCommand(1, value, "0", place);//add
    }

    private void processZext(String line) {
        String place = line.substring(2, line.indexOf(" = zext"));
        String value = line.substring(line.indexOf(" = zext i1") + 11);
        value = value.substring(0, value.indexOf(' '));
        this.threeParamCommand(1, value, "0", place);//add
    }

    private void processTrunc(String line) {
        String place = line.substring(2, line.indexOf(" = trunc"));
        String value = line.substring(line.indexOf(" = trunc i32") + 13);
        value = value.substring(0, value.indexOf(' '));
        this.threeParamCommand(1, value, "0", place);//add
    }

    private void processArrElement(String line, Scanner codeScanner) {
        String place = line.substring(2, line.indexOf(" = "));
        String secondHalf = line.substring(line.lastIndexOf(']'));
        String arrValue = secondHalf.substring(secondHalf.indexOf(' ') + 1, secondHalf.indexOf(','));
        String index = line.substring(line.lastIndexOf(' ') + 1);
        String loadLine = codeScanner.nextLine();
        String finalDest = loadLine.substring(2);
        finalDest = finalDest.substring(0, finalDest.indexOf(' '));
        this.setArrayPtr(arrValue, index, place);////
        this.setArrayPtr(arrValue, index, 2);
        this.threeParamCommand(1, arrValue, "0", finalDest);
        //String storeLine = codeScanner.nextLine();
        /*
        if(storeLine.indexOf("  store") == 0 && storeLine.indexOf(place) == storeLine.lastIndexOf(',')-place.length()){
            //%2 = getelementptr [5 x i32], [5 x i32]* @garr, i32 0, i32 2
            //%3 = load i32, i32* %2, align 4//we do not want to call bc the hashmap has no val in it yet
            //store i32 7, i32* %2, align 4
            String value = storeLine.substring(0, storeLine.indexOf(','));
            value = value.substring(value.lastIndexOf(' ') + 1);
            this.setArrayPtr(arrValue, index, 4);
            this.threeParamCommand(1, value, "0", arrValue);
        }else{
            String finalDest = loadLine.substring(2);
            finalDest = finalDest.substring(0, finalDest.indexOf(' '));
            this.setArrayPtr(arrValue, index, 2);
            this.threeParamCommand(1, arrValue, "0", finalDest);
            this.process(storeLine, codeScanner);
        }

         */
    }

    private void processAdd(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String val2 = line.substring(line.lastIndexOf(' ')+1);
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);
        this.threeParamCommand(1, val1, val2, place);//add
    }

    private void processSub(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String val2 = line.substring(line.lastIndexOf(' ')+1);
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);
        this.threeParamCommand(2, "-1", val2, place);
        this.threeParamCommand(1, val1, place, place);//add
    }

    private void processMul(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String val2 = line.substring(line.lastIndexOf(' ')+1);
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);
        this.threeParamCommand(2, val1, val2, place);//mul
    }

    private void processDiv(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String val2 = line.substring(line.lastIndexOf(' ')+1);
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);
        this.threeParamCommand(12, val1, val2, place);//divide
    }

    private void processEqual(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String val2 = line.substring(line.lastIndexOf(' ')+1);
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);
        this.threeParamCommand(8, val1, val2, place);//equal
    }

    private void processNotEqual(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String val2 = line.substring(line.lastIndexOf(' ')+1);
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);
        this.threeParamCommandRelative(8, val1, val2, 2);
        this.threeParamCommand(1, "5555", "-1", place);//add
        this.threeParamCommand(2, place, place, place);//multiply
    }

    private void processLessThan(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String val2 = line.substring(line.lastIndexOf(' ')+1);
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);
        this.threeParamCommand(7, val1, val2, place);//less than
    }

    private void processLessThanEqual(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String val2 = line.substring(line.lastIndexOf(' ')+1);
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);
        this.threeParamCommand(7, val2, val1, place);//less than
        //0 -1 = -1 ->^2 1
        //1 -1 = 0
        this.threeParamCommand(1, place, "-1", place);//add
        this.threeParamCommand(2, place, place, place);//multiply
    }

    private void processGreaterThan(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String val2 = line.substring(line.lastIndexOf(' ')+1);
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);
        this.threeParamCommand(7, val2, val1, place);//less than
    }

    private void processGreaterThanEqual(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String val2 = line.substring(line.lastIndexOf(' ')+1);
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);

        this.threeParamCommand(7, val1, val2, place);//less than
        //0 -1 = -1 ->^2 1
        //1 -1 = 0
        this.threeParamCommand(1, place, "-1", place);//add
        this.threeParamCommand(2, place, place, place);//multiply
    }

    private void processAnd(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String val2 = line.substring(line.lastIndexOf(' ')+1);
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);
        this.threeParamCommand(2, val1, val2, place);//multiply
    }

    private void processOr(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String val2 = line.substring(line.lastIndexOf(' ')+1);
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);
        this.threeParamCommand(1, val1, val2, place);//add 0 if false 1 if true 2 if both true(we want to set 2 to 1)
        this.threeParamCommandRelative(2, val1, val2, 2);//multiply   1 if both true 0 if not
        this.threeParamCommandRelative(2, "1", "-1", 2);//multiply  turn to -1 if both true
        this.threeParamCommand(1, "1", place, place);//add         subtract 1 if both true 2->1 else subtract 0
    }

    private void processNot(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        String Temp = line.substring(0, line.lastIndexOf(", "));
        String val1 = Temp.substring(Temp.lastIndexOf(' ')+1);
        //0 -1 = -1 ->^2 1
        //1 -1 = 0
        this.threeParamCommand(1, val1, "-1", place);//add
        this.threeParamCommand(2, place, place, place);//multiply
    }

    private void processInFuncCall(String line) {
        String place = line.substring(2, line.indexOf(" = "));
        int instruction = 3;
        Instruction loc = null;
        if(place.indexOf('%') == 0){//dealing with  stack variable
            instruction += 200;
            loc = new Instruction(manager.varSyms.getSymbol(place, this.scope).location);
        } else if ( place.indexOf('@') == 0) {//dealing with a global
            loc = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(place, this.scope).location));
        } else if (place.indexOf('%') == -1 && place.indexOf('@') == -1) {//dealing with a constant
            instruction += 100;
            loc = new Instruction(Integer.parseInt(place));
        }
        this.code.add(new Instruction(instruction));
        this.code.add(loc);
    }

    private void processOutCall(String line) {
        //  call void @outChar(i32 %anInt104)
        String params = line.substring(line.indexOf('('), line.indexOf(')'));
        String outVal = params.substring(params.indexOf(' ') + 1);
        int instruction = 4;
        Instruction out = null;
        if(outVal.indexOf('%') == 0){//dealing with  stack variable
            instruction += 200;
            out = new Instruction(manager.varSyms.getSymbol(outVal, this.scope).location);

        }else if ( outVal.indexOf('@') == 0) {//dealing with a global
            out = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(outVal, this.scope).location));
        }  else if (outVal.indexOf('%') == -1 && outVal.indexOf('@') == -1) {//dealing with a constant
            instruction += 100;
            out = new Instruction(Integer.parseInt(outVal));
        }
        this.code.add(new Instruction(instruction));
        this.code.add(out);
    }

    private void processProcCall(String line) {
        //pass in params
        LinkedList<String> params = this.getFuncCallParams(line);
        for(int i = 0; i < params.size(); i++){
            int location = (this.scopeStackSize+i);
            this.setFuncParamVals(1, "0", params.get(i), location, 2);
        }
        //Adjust stack pointer
        this.code.add(new Instruction(109));
        this.code.add(new Instruction(this.scopeStackSize));
        //pass in return loc
        this.code.add(new Instruction(21101));
        this.code.add(new Instruction(0));
        this.code.add(new Instruction(new RelativeToCurLocation(5)));
        this.code.add(new Instruction(-2));
        //go to function
        String funcNameUntrimmed = line.substring(line.indexOf("  call void "), line.indexOf('('));
        String funcName = funcNameUntrimmed.substring(funcNameUntrimmed.indexOf("@"));
        this.code.add(new Instruction(1105));
        this.code.add(new Instruction(1));
        this.code.add(new Instruction(this.manager.funcSyms.global.getSymbol(funcName).location));
        //adjust stack pointer
        this.code.add(new Instruction(109));
        this.code.add(new Instruction(-1*this.scopeStackSize));

    }

    private void processFuncCall(String line) {
        //pass in params
        LinkedList<String> params = this.getFuncCallParams(line);
        for(int i = 0; i < params.size(); i++){
            int location = (this.scopeStackSize+i);
            this.setFuncParamVals(1, "0", params.get(i), location, 2);
        }
        //Adjust stack pointer
        this.code.add(new Instruction(109));
        this.code.add(new Instruction(this.scopeStackSize));
        //pass in return loc
        this.code.add(new Instruction(21101));
        this.code.add(new Instruction(0));
        this.code.add(new Instruction(new RelativeToCurLocation(5)));
        this.code.add(new Instruction(-2));
        //go to function
        String funcNameUntrimmed = line.substring(line.indexOf(" = call "), line.indexOf('('));
        String funcName = funcNameUntrimmed.substring(funcNameUntrimmed.indexOf("@"));
        this.code.add(new Instruction(1105));
        this.code.add(new Instruction(1));
        this.code.add(new Instruction(this.manager.funcSyms.global.getSymbol(funcName).location));
        //adjust stack pointer
        this.code.add(new Instruction(109));
        this.code.add(new Instruction(-1*this.scopeStackSize));
        //Get return value
        String retVarName = line.substring(2, line.indexOf(" = "));
        this.getFuncReturnVals(retVarName);

    }

    private void processReturn(String line) {
        lastRet = 0;
        if(!line.contains("  ret void") && !line.contains("}") && !line.contains(" getelementptr inbounds ")) {
            String retVal = line.substring(line.lastIndexOf(' ') + 1);
            //place return value
            this.setFuncParamVals(1, "0", retVal, -1, 2);
        }else if(line.contains(" getelementptr inbounds ")){
            String paramStart = line.substring(line.indexOf('@'));
            String retVal = "S" + paramStart.substring(0, paramStart.indexOf(','));
            this.setFuncParamVals(1, "0", retVal, -1, 2);
        }
        //return
        if(this.scope.equals("@program")){
            this.code.add(new Instruction(99));
            return;
        }
        this.code.add(new Instruction(2105));
        this.code.add(new Instruction(1));
        this.code.add(new Instruction(-2));
    }

    private void processBlock(String line) {
        String blockName = this.scope + "%" + line.substring(0, line.indexOf(':'));
        this.blocks.put(blockName, this.code.size());
    }

    private void processJumpIf(String line) {
        //br i1 %6, label %bTrue, label %bContinue
        String falseBlock = this.scope + line.substring(line.lastIndexOf('%'));
        String trueBlock = this.scope + line.substring(line.indexOf(", label") + 8, line.lastIndexOf(','));
        String varVal = line.substring(line.indexOf(" br i1")+ 7, line.indexOf(','));
        int instruction = 1005;
        Instruction bool = null;
        if(varVal.indexOf('%') == 0){//dealing with  stack variable
            instruction += 200;
            bool = new Instruction(manager.varSyms.getSymbol(varVal, this.scope).location);
        }else if(varVal.indexOf('@') == 0){//globalVar
            bool = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(varVal, this.scope).location));
        } else if (varVal.indexOf('%') == -1 && varVal.indexOf('@') == -1) {//dealing with a constant
            instruction += 100;
            bool = new Instruction(Integer.parseInt(varVal));
        }
        this.code.add(new Instruction(instruction));
        this.code.add(bool);
        this.code.add(new Instruction(new BlockLocation(trueBlock)));
        this.code.add(new Instruction(1105));
        this.code.add(new Instruction(1));
        this.code.add(new Instruction(new BlockLocation(falseBlock)));
    }

    private void processJump(String line) {
        String blockName = this.scope + line.substring(line.indexOf('%'));
        this.code.add(new Instruction(1105));
        this.code.add(new Instruction(1));
        this.code.add(new Instruction(new BlockLocation(blockName)));
    }

    private void processStringVarInit(String line) {
        String cut = line.substring(0, line.lastIndexOf(','));
        cut = cut.substring(0, cut.lastIndexOf(','));
        String name = cut.substring(cut.lastIndexOf(' ')+1);
        globals.add(new Instruction(new GlobalLocation(manager.varSyms.global.getSymbol(name).location)));
    }

    private void processStringInit(String line) {
        String text = line.substring(line.indexOf("c\"") + 5, line.length()-16);
        //parse string
        int i = 0;
        while(i<text.length()) {
            if (text.charAt(i) == '\\') {
                if (text.charAt(i + 1) == '\\') {
                    globals.add(new Instruction('\\'));
                    i = i + 2;
                } else {
                    String codeInHex = text.substring(i + 1, i + 3);
                    globals.add(new Instruction(Integer.parseInt(codeInHex, 16)));
                    i = i + 3;
                }
            } else {
                globals.add(new Instruction(text.charAt(i)));
                i++;
            }
        }
        globals.add(new Instruction(0));

    }

    private void processStringStore(String line) {
        String backHalf = line.substring(line.indexOf("), "), line.lastIndexOf(','));
        String place = backHalf.substring(backHalf.lastIndexOf(' ') + 1);
        String value = line.substring(line.indexOf('@'));
        value = value.substring(0, value.indexOf(','));
        this.setStrPtr(value, place);
    }

    private void setStrPtr(String stringName, String destination){
        int instruction = 1101;
        Instruction des = null;
        Instruction v1 = new Instruction(0);
        Instruction v2 = null;

        if(destination.indexOf('%') == 0) {//putting on the stack
            instruction += 20000;
            des = new Instruction(manager.varSyms.getSymbol(destination, this.scope).location);
        }else if(destination.indexOf('@') == 0){//globalVar
            des = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(destination, this.scope).location));
        }

        if(stringName.indexOf('%') == 0){//dealing with  stack variable
            v2 = new Instruction(manager.varSyms.getSymbol(stringName, this.scope).location);
        }else if(stringName.indexOf('@') == 0){//globalVar
            v2 = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(stringName, this.scope).location));
        } else if (stringName.indexOf('%') == -1 && stringName.indexOf('@') == -1) {//dealing with a constant
            System.out.println("Something went wrong in setStrPtr of CodeGen");
        }



        this.code.add(new Instruction(instruction));
        this.code.add(v1);
        this.code.add(v2);
        this.code.add(des);
    }

    private void setArrayPtr(String arrayBase, String index, int destination){
        int instruction = 101;
        Instruction des = new Instruction(new RelativeToCurLocation(destination));
        Instruction v1 = null;
        Instruction v2 = null;


        if(arrayBase.indexOf('%') == 0){//dealing with  stack variable
            v1 = new Instruction(manager.varSyms.getSymbol(arrayBase, this.scope).location);
        }else if(arrayBase.indexOf('@') == 0){//globalVar
            v1 = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(arrayBase, this.scope).location));
        } else if (arrayBase.indexOf('%') == -1 && arrayBase.indexOf('@') == -1) {//dealing with a constant
            System.out.println("Something went wrong in setArrayPtr or CodeGenerator");
        }

        if(index.indexOf('%') == 0){//dealing with  stack variable
            instruction += 2000;
            v2 = new Instruction(manager.varSyms.getSymbol(index, this.scope).location);
        }else if(index.indexOf('@') == 0){//globalVar
            v2 = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(index, this.scope).location));
        } else if (index.indexOf('%') == -1 && index.indexOf('@') == -1) {//dealing with a constant
            instruction += 1000;
            v2 = new Instruction(Integer.parseInt(index));
        }

        this.code.add(new Instruction(instruction));
        this.code.add(v1);
        this.code.add(v2);
        this.code.add(des);
    }

    private void setArrayPtr(String arrayBase, String index, String destination){
        int instruction = 101;
        Instruction des = null;
        Instruction v1 = null;
        Instruction v2 = null;

        if(destination.indexOf('%') == 0) {//putting on the stack
            instruction += 20000;
            des = new Instruction(manager.varSyms.getSymbol(destination, this.scope).location);
        }else if(destination.indexOf('@') == 0){//globalVar
            des = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(destination, this.scope).location));
        }

        if(arrayBase.indexOf('%') == 0){//dealing with  stack variable
            v1 = new Instruction(manager.varSyms.getSymbol(arrayBase, this.scope).location);
        }else if(arrayBase.indexOf('@') == 0){//globalVar
            v1 = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(arrayBase, this.scope).location));
        } else if (arrayBase.indexOf('%') == -1 && arrayBase.indexOf('@') == -1) {//dealing with a constant
            System.out.println("Something went wrong in setArrayPtr or CodeGenerator");
        }

        if(index.indexOf('%') == 0){//dealing with  stack variable
            instruction += 2000;
            v2 = new Instruction(manager.varSyms.getSymbol(index, this.scope).location);
        }else if(index.indexOf('@') == 0){//globalVar
            v2 = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(index, this.scope).location));
        } else if (index.indexOf('%') == -1 && index.indexOf('@') == -1) {//dealing with a constant
            instruction += 1000;
            v2 = new Instruction(Integer.parseInt(index));
        }

        this.code.add(new Instruction(instruction));
        this.code.add(v1);
        this.code.add(v2);
        this.code.add(des);
    }

    private LinkedList<String> getFuncCallParams(String line){
        String justFuncParams = line.substring(line.indexOf('('));
        LinkedList<String> params = new LinkedList<>();
        if(justFuncParams.length() < 3){
            return params;
        }
        //while there is at least a param
        while(justFuncParams.length() > 1) {
            //get begining of param
            int paramBegin = justFuncParams.indexOf(' ') + 1;
            if(justFuncParams.substring(paramBegin).indexOf("getelementptr") == 0){
                String paramStart = justFuncParams.substring(justFuncParams.indexOf('@'));
                String paramName = "S" + paramStart.substring(0, paramStart.indexOf(','));
                int paramEnd = justFuncParams.indexOf("),");
                if(paramEnd == -1){
                    paramEnd = justFuncParams.indexOf("))")-1;
                }
                params.add(paramName);
                justFuncParams = justFuncParams.substring(paramEnd + 3);

            }else {
                //get end
                int paramEnd = justFuncParams.indexOf(',');
                //if last param then no , so look for )
                if (paramEnd == -1) {
                    paramEnd = justFuncParams.indexOf(')');
                }
                String varName = justFuncParams.substring(paramBegin, paramEnd);
                params.add(varName);
                justFuncParams = justFuncParams.substring(Math.min(justFuncParams.length(), paramEnd + 2));
            }
        }
        return params;
    }

    private void setFuncParamVals(int command, String value1, String value2, int destination, int destinationType){
        int instruction = command;
        Instruction v1 = null;
        Instruction v2 = null;
        Instruction des = new Instruction(destination);

        if(destinationType == 2) {//putting on the stack
            instruction += 20000;
        }else if(destinationType == 0){
            des = new Instruction(new GlobalLocation(destination));
        }

        if(value1.indexOf('%') == 0){//dealing with  stack variable
            instruction += 200;
            v1 = new Instruction(manager.varSyms.getSymbol(value1, this.scope).location);
        }else if(value1.indexOf('@') == 0){//globalVar
            v1 = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(value1, this.scope).location));
        } else if (value1.indexOf('%') == -1 && value1.indexOf('@') == -1) {//dealing with a constant
            instruction += 100;
            v1 = new Instruction(Integer.parseInt(value1));
        }

        if(value2.indexOf('%') == 0){//dealing with  stack variable
            instruction += 2000;
            v2 = new Instruction(manager.varSyms.getSymbol(value2, this.scope).location);
        }else if(value2.indexOf('@') == 0){//globalVar
            v2 = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(value2, this.scope).location));
        }else if(value2.indexOf('S') == 0){//String
            instruction += 1000;
            String varName = value2.substring(1);
            v2 = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(varName, this.scope).location));
        } else if (value2.indexOf('%') == -1 && value2.indexOf('@') == -1 && value2.indexOf('S') == -1) {//dealing with a constant
            instruction += 1000;
            v2 = new Instruction(Integer.parseInt(value2));
        }

        this.code.add(new Instruction(instruction));
        this.code.add(v1);
        this.code.add(v2);
        this.code.add(des);
    }

    private void getFuncReturnVals(String destination){
        int instruction = 2101;
        int v1 = 0;
        int v2 = this.scopeStackSize-1;
        Instruction des = null;

        if(destination.indexOf('%') == 0) {//putting on the stack
            instruction += 20000;
            des = new Instruction(manager.varSyms.getSymbol(destination, this.scope).location);
        }else if(destination.indexOf('@') == 0){
            des = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(destination, this.scope).location));
        }

        this.code.add(new Instruction(instruction));
        this.code.add(new Instruction(v1));
        this.code.add(new Instruction(v2));
        this.code.add(des);
    }

    private void threeParamCommand(int command, String value1, String value2, String destination){
        this.threeParamCommand(command, value1, value2, destination, 0);
    }

    private void threeParamCommand(int command, String value1, String value2, String destination, int modifier){
        int instruction = command;
        Instruction des = null;
        Instruction v1 = null;
        Instruction v2 = null;
        if(destination.indexOf('%') == 0) {//putting on the stack
            instruction += 20000;
            des = new Instruction(manager.varSyms.getSymbol(destination, this.scope).location + modifier);
        }else if(destination.indexOf('@') == 0){//globalVar
            des = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(destination, this.scope).location + modifier));
        }

        if(value1.indexOf('%') == 0){//dealing with  stack variable
            instruction += 200;
            v1 = new Instruction(manager.varSyms.getSymbol(value1, this.scope).location);
        }else if(value1.indexOf('@') == 0){//globalVar
            v1 = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(value1, this.scope).location));
        } else if (value1.indexOf('%') == -1 && value1.indexOf('@') == -1) {//dealing with a constant
            instruction += 100;
            v1 = new Instruction(Integer.parseInt(value1));
        }

        if(value2.indexOf('%') == 0){//dealing with  stack variable
            instruction += 2000;
            v2 = new Instruction(manager.varSyms.getSymbol(value2, this.scope).location);
        }else if(value2.indexOf('@') == 0){//globalVar
            v2 = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(value2, this.scope).location));
        } else if (value2.indexOf('%') == -1 && value2.indexOf('@') == -1) {//dealing with a constant
            instruction += 1000;
            v2 = new Instruction(Integer.parseInt(value2));
        }

        this.code.add(new Instruction(instruction));
        this.code.add(v1);
        this.code.add(v2);
        this.code.add(des);
    }

    private void threeParamCommandRelative(int command, String value1, String value2, int destination){
        int instruction = command;
        Instruction des = new Instruction(new RelativeToCurLocation(destination));
        Instruction v1 = null;
        Instruction v2 = null;


        if(value1.indexOf('%') == 0){//dealing with  stack variable
            instruction += 200;
            v1 = new Instruction(manager.varSyms.getSymbol(value1, this.scope).location);
        }else if(value1.indexOf('@') == 0){//globalVar
            v1 = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(value1, this.scope).location));
        } else if (value1.indexOf('%') == -1 && value1.indexOf('@') == -1) {//dealing with a constant
            instruction += 100;
            v1 = new Instruction(Integer.parseInt(value1));
        }

        if(value2.indexOf('%') == 0){//dealing with  stack variable
            instruction += 2000;
            v2 = new Instruction(manager.varSyms.getSymbol(value2, this.scope).location);
        }else if(value2.indexOf('@') == 0){//globalVar
            v2 = new Instruction(new GlobalLocation(manager.varSyms.getSymbol(value2, this.scope).location));
        } else if (value2.indexOf('%') == -1 && value2.indexOf('@') == -1) {//dealing with a constant
            instruction += 1000;
            v2 = new Instruction(Integer.parseInt(value2));
        }

        this.code.add(new Instruction(instruction));
        this.code.add(v1);
        this.code.add(v2);
        this.code.add(des);
    }

    private String getOutIntCode() {
        return """
                define void @outInt(i32 %0) {
                entry:
                  %i = alloca i32, align 4
                  store i32 %0, i32* %i, align 4
                  %restOfNumber = alloca i32, align 4
                  %i1 = load i32, i32* %i, align 4
                  store i32 %i1, i32* %restOfNumber, align 4
                  %i2 = load i32, i32* %i, align 4
                  %1 = icmp slt i32 %i2, 0
                  %2 = zext i1 %1 to i32
                  %3 = trunc i32 %2 to i1
                  br i1 %3, label %bTrue, label %bContinue

                bTrue:                                            ; preds = %entry
                  call void @outChar(i32 45)
                  %restOfNumber3 = load i32, i32* %restOfNumber, align 4
                  %4 = sub nsw i32 0, 1
                  %5 = mul nsw i32 %restOfNumber3, %4
                  store i32 %5, i32* %restOfNumber, align 4
                  br label %bContinue

                bContinue:                                        ; preds = %bTrue, %entry
                  %i6 = load i32, i32* %i, align 4
                  %6 = icmp eq i32 %i6, 0
                  %7 = zext i1 %6 to i32
                  %8 = trunc i32 %7 to i1
                  br i1 %8, label %bTrue4, label %bContinue5

                bTrue4:                                           ; preds = %bContinue
                  call void @outChar(i32 48)
                  ret void
                  br label %bContinue5

                bContinue5:                                       ; preds = %bTrue4, %bContinue
                  %digit = alloca i32, align 4
                  %largers = alloca i32, align 4
                  %reverse = alloca i32, align 4
                  store i32 0, i32* %reverse, align 4
                  %size = alloca i32, align 4
                  store i32 0, i32* %size, align 4
                  %restOfNumber7 = load i32, i32* %restOfNumber, align 4
                  %9 = icmp sgt i32 %restOfNumber7, 0
                  %10 = zext i1 %9 to i32
                  %11 = trunc i32 %10 to i1
                  br i1 %11, label %lTrue, label %lContinue

                lTrue:                                            ; preds = %lTrue, %bContinue5
                  %restOfNumber8 = load i32, i32* %restOfNumber, align 4
                  %12 = sdiv i32 %restOfNumber8, 10
                  %13 = mul nsw i32 %12, 10
                  store i32 %13, i32* %largers, align 4
                  %restOfNumber9 = load i32, i32* %restOfNumber, align 4
                  %largers10 = load i32, i32* %largers, align 4
                  %14 = sub nsw i32 %restOfNumber9, %largers10
                  store i32 %14, i32* %digit, align 4
                  %restOfNumber11 = load i32, i32* %restOfNumber, align 4
                  %15 = sdiv i32 %restOfNumber11, 10
                  store i32 %15, i32* %restOfNumber, align 4
                  %reverse12 = load i32, i32* %reverse, align 4
                  %16 = mul nsw i32 %reverse12, 10
                  %digit13 = load i32, i32* %digit, align 4
                  %17 = add nsw i32 %16, %digit13
                  store i32 %17, i32* %reverse, align 4
                  %size14 = load i32, i32* %size, align 4
                  %18 = add nsw i32 1, %size14
                  store i32 %18, i32* %size, align 4
                  %restOfNumber15 = load i32, i32* %restOfNumber, align 4
                  %19 = icmp sgt i32 %restOfNumber15, 0
                  %20 = zext i1 %19 to i32
                  %21 = trunc i32 %20 to i1
                  br i1 %21, label %lTrue, label %lContinue

                lContinue:                                        ; preds = %lTrue, %bContinue5
                  %reverse16 = load i32, i32* %reverse, align 4
                  store i32 %reverse16, i32* %restOfNumber, align 4
                  %size19 = load i32, i32* %size, align 4
                  %22 = icmp sgt i32 %size19, 0
                  %23 = zext i1 %22 to i32
                  %24 = trunc i32 %23 to i1
                  br i1 %24, label %lTrue17, label %lContinue18

                lTrue17:                                          ; preds = %lTrue17, %lContinue
                  %restOfNumber20 = load i32, i32* %restOfNumber, align 4
                  %25 = sdiv i32 %restOfNumber20, 10
                  %26 = mul nsw i32 %25, 10
                  store i32 %26, i32* %largers, align 4
                  %restOfNumber21 = load i32, i32* %restOfNumber, align 4
                  %largers22 = load i32, i32* %largers, align 4
                  %27 = sub nsw i32 %restOfNumber21, %largers22
                  store i32 %27, i32* %digit, align 4
                  %restOfNumber23 = load i32, i32* %restOfNumber, align 4
                  %28 = sdiv i32 %restOfNumber23, 10
                  store i32 %28, i32* %restOfNumber, align 4
                  %digit24 = load i32, i32* %digit, align 4
                  %29 = add nsw i32 %digit24, 48
                  store i32 %29, i32* %digit, align 4
                  %digit25 = load i32, i32* %digit, align 4
                  call void @outChar(i32 %digit25)
                  %size26 = load i32, i32* %size, align 4
                  %30 = sub nsw i32 %size26, 1
                  store i32 %30, i32* %size, align 4
                  %size27 = load i32, i32* %size, align 4
                  %31 = icmp sgt i32 %size27, 0
                  %32 = zext i1 %31 to i32
                  %33 = trunc i32 %32 to i1
                  br i1 %33, label %lTrue17, label %lContinue18

                lContinue18:                                      ; preds = %lTrue17, %lContinue
                  ret void
                }

                """;
    }





    /*
FUNCTION STUFF
declare i32 @printf(i8*, ...)- extern func#############################################
define i32 @intf() {- function#########################################################
}- end func????????????????????????????????????????????????????????????????????????????
entry:- function/block start???????????????????????????????????????????????????????????
bTrue:  ; preds = %entry- ^^^^ I think I don't need to worry about preds ##############
ret i32 3- return######################################################################
%13 = call i32 (i8*, ...) @printf()- call extern func##################################
i8* getelementptr inbounds ([13 x i8], [13 x i8]* @2, i32 0, i32 0) - extern func params
%178 = call i32 @boolf(i32 %anInt90, i32 1, i8* %177)- call intern func################

VARIABLE STUFF
%x = alloca i32, align 4- declare var##################################################
@0 = private unnamed_addr constant [13 x i8] c"\22Error func\22\00", align 1- string###
@globalVar = dso_local global i32 5 - global var#######################################
store i32 %0, i32* %x, align 4- store val in variable##################################
%x1 = load i32, i32* %x, align 4- load var#############################################
ret i8* getelementptr inbounds ([15 x i8], [15 x i8]* @1, i32 0, i32 0) - string var###

OPERATIONS
%7 = and i1 %5, %6- and################################################################
%4 = or i1 %2, %3- or##################################################################
%10 = xor i1 %9, true- not#############################################################
%3 = icmp eq i32 %x1, 32 - is eql #####################################################
%10 = icmp slt i32 1, 1- <#############################################################
%10 = icmp sle i32 1, 1- <=############################################################
%10 = icmp sgt i32 1, 1- >#############################################################
%10 = icmp sge i32 1, 1- >=############################################################
%4 = zext i1 %3 to i32- bool to int####################################################
%5 = trunc i32 %4 to i1- into to bool##################################################
%44 = mul nsw i32 4, 10- multiply######################################################
%53 = sdiv i32 2, 2- divide############################################################
%45 = add nsw i32 2, %44- add##########################################################
%63 = sub nsw i32 2, %62- subtract#####################################################

CONDITIONAL STUFF
br i1 %12, label %bTrue, label %bContinue- if jump to code#############################
br label %bContinue	- jump to code#####################################################





     */


}
