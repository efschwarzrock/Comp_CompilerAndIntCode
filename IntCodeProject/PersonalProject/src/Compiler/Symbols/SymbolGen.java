package Compiler.Symbols;

import java.io.File;
import java.util.Scanner;

public class SymbolGen {
    public File codeFile;
    public SymbolTableManager manager;
    private String scope;
    private int location;
    public SymbolGen(File code){
        this.codeFile = code;
    }

    public boolean generate() {
        this.manager = new SymbolTableManager();
        this.scope = "";
        this.location = 0;
        Scanner codeScanner;
        try {
            codeScanner = new Scanner(this.codeFile);
        }catch (Exception e){
            System.out.println("File Not Found");
            return false;
        }

        while (codeScanner.hasNextLine()) {
            this.process(codeScanner.nextLine());
        }
        codeScanner.close();
        return true;
    }

    private void process(String line){
        if(line.indexOf('@') == 0){//it is a global variable
            String name = line.substring(0,line.indexOf(" "));
            this.manager.varSyms.addSymbol(name, this.location, "");
            this.location++;
            //check if it is a string and leave enough room
            if(line.contains("c\"")){
                String text = line.substring(line.indexOf("c\"") + 5, line.length()-16);
                //parse string
                int i = 0;
                while(i<text.length()){
                    if(text.charAt(i) == '\\'){
                        if(text.charAt(i+1) == '\\'){
                            i = i + 2;
                        }else{
                            i = i + 3;
                        }
                    }else{
                        i++;
                    }
                    location++;
                }

                //System.out.println(text);
                //System.out.println(line);
            }else if(line.indexOf(']') == line.length()-1){//it is an array so we need to leave room
                String lengthExtra = line.substring(line.indexOf('[')+1);
                String length = lengthExtra.substring(0, lengthExtra.indexOf(' '));
                int len = Integer.parseInt(length);
                location += len-1;
            }
        }else if(line.indexOf("define") == 0){
            this.processFunc(line);
        }else if(line.indexOf('%') == 2){
            String name = line.substring(2,line.substring(3).indexOf(" ") + 3);
            this.manager.varSyms.addSymbol(name, this.location, this.scope);
            this.location++;

            if(line.contains("alloca [")){//it is an array and we need to adjust for that
                String lengthExtra = line.substring(line.indexOf('[')+1);
                String length = lengthExtra.substring(0, lengthExtra.indexOf(' '));
                int len = Integer.parseInt(length);
                location += len-1;
            }else if(line.contains(" getelementptr ")){//it is an array ptr so we need to set that
                this.manager.varSyms.getSymbol(name, this.scope).arrayPtr = true;
                if(line.contains("@")){//global
                    this.manager.varSyms.getSymbol(name, this.scope).arrayType = 0;
                }else{//on the stack
                    this.manager.varSyms.getSymbol(name, this.scope).arrayType = 2;
                }
            }

        }else if(line.contains("declare void @print(i8*)")){
            this.manager.funcSyms.addSymbol("@print", -1, "");
        }else if(line.contains("declare void @outInt(i32)")){
            String code = getOutIntCode();
            while(code.length() > 1){
                String l = code.substring(0, code.indexOf('\n'));
                code = code.substring(code.indexOf('\n') + 1);
                this.process(l);
            }
        }
    }

    private void processFunc(String line) {
        String funcName = line.substring(line.indexOf('@'), line.indexOf('('));
        this.manager.funcSyms.addSymbol(funcName, -1, "");//add the function, we will calculate the location later
        //set global vars
        this.scope = funcName;
        this.location = 0;


        String l = line;
        //while there is another param
        while(l.indexOf('%') != -1){
            //get begining of param
            int paramBegin = l.indexOf('%');
            //get end
            int paramEnd = l.indexOf(',');
            //if last param then no , so look for )
            if(paramEnd == -1){
                paramEnd = l.indexOf(')');
            }
            String varName = l.substring(paramBegin, paramEnd);
            l = l.substring(paramEnd + 1);

            this.manager.varSyms.addSymbol(varName, this.location, this.scope);
            this.location++;

        }
        if(this.location == 0){
            this.manager.varSyms.scopes.put(this.scope, new Scope(this.scope));
        }



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
}
