package IntCodeMachine;

import java.util.HashMap;
import java.util.Scanner;

public class IntCodeMachine {
    long[] code;
    long instructionPtr;
    long relativeBase;
    HashMap<Long, Long> virtualMemeory;
    Scanner scan;

    public IntCodeMachine(long[] c){
        this.code = c;
        this.scan = new Scanner(System.in);
    }

    public void run(){
        this.initialize();
        boolean done = false;
        while(!done){
            //this.printDiagnostics("run");
            long fullCommand = this.getValue(instructionPtr);
            int command = (int)(fullCommand%100);
            switch (command) {
                case 1 -> this.executeAdd(fullCommand);
                case 2 -> this.executeMultiply(fullCommand);
                case 3 -> this.executeInput(fullCommand);
                case 4 -> this.executeOutput(fullCommand);
                case 5 -> this.executeJumpTrue(fullCommand);
                case 6 -> this.executeJumpFalse(fullCommand);
                case 7 -> this.executeLessThan(fullCommand);
                case 8 -> this.executeGreaterThan(fullCommand);
                case 9 -> this.executeModifyRelativeBase(fullCommand);
                case 12 -> this.executeDivide(fullCommand);
                case 99 -> done = true;
            }
        }

    }

    private void executeAdd(long fullCommand) {
        long[] types = {0, 0, 0};
        long[] values = {0, 0};
        types[0] = (fullCommand/100)%10;
        types[1] = (fullCommand/1000)%10;
        types[2] = (fullCommand/10000)%10;
        int i = 0;
        while(i < 2){
            values[i] = this.getParam(types[i], this.getValue(instructionPtr+1+i));
            i++;
        }

        this.setParam(types[2], this.getValue(instructionPtr+3), values[0] + values[1]);
        instructionPtr += 4;
    }

    private void executeMultiply(long fullCommand) {
        long[] types = {0, 0, 0};
        long[] values = {0, 0};
        types[0] = (fullCommand/100)%10;
        types[1] = (fullCommand/1000)%10;
        types[2] = (fullCommand/10000)%10;
        int i = 0;
        while(i < 2){
            values[i] = this.getParam(types[i], this.getValue(instructionPtr+1+i));
            i++;
        }

        this.setParam(types[2], this.getValue(instructionPtr+3), values[0] * values[1]);
        instructionPtr += 4;
    }

    private void executeInput(long fullCommand) {
        long type = (fullCommand/100)%10;
        long input = scan.nextLong();
        this.setParam(type, this.getValue(instructionPtr+1), input);
        instructionPtr += 2;
    }

    private void executeOutput(long fullCommand) {
        long type = (fullCommand/100)%10;
        char output = (char)this.getParam(type, this.getValue(instructionPtr+1));
        //long output = this.getParam(type, this.getValue(instructionPtr+1));
        System.out.print(output);
        //long input = scan.nextLong();
        instructionPtr += 2;
    }

    private void executeJumpTrue(long fullCommand) {
        long[] types = {0, 0};
        types[0] = (fullCommand/100)%10;
        types[1] = (fullCommand/1000)%10;

        long bool = this.getParam(types[0], this.getValue(instructionPtr+1));
        if(bool != 0){
            instructionPtr = this.getParam(types[1], this.getValue(instructionPtr+2));
        }else{
            instructionPtr += 3;
        }
    }

    private void executeJumpFalse(long fullCommand) {
        long[] types = {0, 0};
        types[0] = (fullCommand/100)%10;
        types[1] = (fullCommand/1000)%10;

        long bool = this.getParam(types[0], this.getValue(instructionPtr+1));
        if(bool == 0){
            instructionPtr = this.getParam(types[1], this.getValue(instructionPtr+2));
        }else{
            instructionPtr += 3;
        }
    }

    private void executeLessThan(long fullCommand) {
        long[] types = {0, 0, 0};
        long[] values = {0, 0};
        types[0] = (fullCommand/100)%10;
        types[1] = (fullCommand/1000)%10;
        types[2] = (fullCommand/10000)%10;
        int i = 0;
        while(i < 2){
            values[i] = this.getParam(types[i], this.getValue(instructionPtr+1+i));
            i++;
        }
        if(values[0] < values[1]){
            this.setParam(types[2], this.getValue(instructionPtr+3), 1);
        }else{
            this.setParam(types[2], this.getValue(instructionPtr+3), 0);
        }
        instructionPtr += 4;
    }

    private void executeGreaterThan(long fullCommand) {
        long[] types = {0, 0, 0};
        long[] values = {0, 0};
        types[0] = (fullCommand/100)%10;
        types[1] = (fullCommand/1000)%10;
        types[2] = (fullCommand/10000)%10;
        int i = 0;
        while(i < 2){
            values[i] = this.getParam(types[i], this.getValue(instructionPtr+1+i));
            i++;
        }
        if(values[0] == values[1]){
            this.setParam(types[2], this.getValue(instructionPtr+3), 1);
        }else{
            this.setParam(types[2], this.getValue(instructionPtr+3), 0);
        }
        instructionPtr += 4;
    }

    private void executeModifyRelativeBase(long fullCommand) {
        long type = (fullCommand/100)%10;
        //char output = (char)this.getParam(type, this.getValue(instructionPtr+1));
        this.relativeBase += this.getParam(type, this.getValue(instructionPtr+1));
        instructionPtr += 2;
    }

    private void executeDivide(long fullCommand) {
        long[] types = {0, 0, 0};
        long[] values = {0, 0};
        types[0] = (fullCommand/100)%10;
        types[1] = (fullCommand/1000)%10;
        types[2] = (fullCommand/10000)%10;
        int i = 0;
        while(i < 2){
            values[i] = this.getParam(types[i], this.getValue(instructionPtr+1+i));
            i++;
        }
        this.setParam(types[2], this.getValue(instructionPtr+3), values[0] / values[1]);
        instructionPtr += 4;
    }

    private void initialize(){
        this.instructionPtr = 0;
        this.relativeBase = 0;
        virtualMemeory = new HashMap<>();
    }

    private long getParam(long type, long value){
        if(type == 0){
            return this.getValue(value);
        }else if(type == 2){
            return this.getValue(value + relativeBase);
        }else{
            return value;
        }
    }

    private long getValue(long address){
        if(address < code.length){
            return code[(int)address];
        }else{
            //this.printDiagnostics("Get");
            return virtualMemeory.get(address);
        }
    }

    private void setParam(long type, long address, long value){
        if(type == 0){
            this.setAddress(address, value);
        }else if(type == 2){
            this.setAddress(address + relativeBase, value);
        }else{
            System.out.println("Runtime Error/Compilation Error");
            printDiagnostics("Error Trace");
            throw new RuntimeException();
        }
    }
    private void setAddress(long address, long value){
        if(address < code.length){
            code[(int)address] = value;
        }else{
            virtualMemeory.put(address, value);
        }
    }

    public void printDiagnostics(String s){
        System.out.println(s);
        System.out.println("InstrPtr: " + this.instructionPtr);
        System.out.println("StackPtr: " + this.relativeBase);
        System.out.println("CodeSnip: " + this.code[(int)this.instructionPtr] + ", " + this.code[(int)this.instructionPtr + 1] + ", " + this.code[(int)this.instructionPtr + 2] + ", " + this.code[(int)this.instructionPtr + 3] + ", " + this.code[(int)this.instructionPtr + 4] + ", " + this.code[(int)this.instructionPtr + 5] + ", " + this.code[(int)this.instructionPtr + 6] + ", " + this.code[(int)this.instructionPtr + 7] + ", ");
        System.out.println(s);
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        int i = 0;
        while(i < this.code.length){
            str.append(Long.toString(this.code[i])).append(", ");
            i++;
        }
        return str.toString();
    }
}
