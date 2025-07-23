import Compiler.IntCodeCompiler;
import IntCodeMachine.IntCodeMachine;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        if(help(args)){
            printHelp();
            return;
        }

        boolean run = getParam(args, "-r");
        boolean print = getParam(args, "-p");
        boolean save = !getParam(args, "--dont-save");
        String sourceFile = args[0];
        String destinationFile = getDestination(args);

        File file = new File(sourceFile);
        IntCodeCompiler comp = new IntCodeCompiler(file);
        String codeStr = comp.compile();

        if(codeStr.length() < 3){
            return;
        }

        if(print){
            System.out.println(codeStr);
        }

        if(save){
            saveCode(codeStr, destinationFile);
        }

        if(run && save) {
            // Run the code in code.txt
            long[] code = getCode(destinationFile);
            IntCodeMachine machine = new IntCodeMachine(code);
            machine.run();
        }


    }

    private static boolean getParam(String[] args, String param) {
        for(int i = 1; i < args.length; i++){
            if(args[i].equals(param)){
                return true;
            }
        }
        return false;
    }

    private static String getDestination(String[] args) {
        String destination = args[0].substring(0, args[0].length()-2).concat("IC");
        for(int i = 1; i < args.length - 1; i++){
            if(args[i].equals("-d")){
                return args[i + 1];
            }
        }
        return destination;
    }



    private static void saveCode(String codeStr, String destinationFile) {
        try {
            File myObj = new File(destinationFile);
            myObj.createNewFile();
            FileWriter myWriter = new FileWriter(destinationFile);
            myWriter.write(codeStr);
            myWriter.close();
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    public static long[] getCode(String fileName){
        String[] codeStrArr = new String[0];
        String text = "";
        try {
            File file = new File(fileName);
            Scanner myReader = new Scanner(file);
            while (myReader.hasNextLine()) {
                text = text + myReader.nextLine();
                //System.out.println(data);
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
            return null;
        }
        codeStrArr = text.split(",");
        long[] code = new long[codeStrArr.length];
        for (int i = 0; i < codeStrArr.length; i++) {
            code[i] = Long.parseLong(codeStrArr[i]);
        }
        return code;
    }

    /*
    -d -p -r --dont-save
     */
    public static boolean help(String[] args){
        for(int i = 0; i < args.length; i++){
            if(args[i].equals("-h")){
                return true;
            }
            if(i > 0 && !(args[i].equals("-d") || args[i].equals("-p") || args[i].equals("-r") || args[i].equals("--dont-save")) ){
                return true;
            }
            if(args[i].equals("-d")){
                i++;
            }
        }
        return false;
    }

    public static void printHelp(){
        System.out.println("""
                usage: Main <source path> [-d <path>] [-p] [-r] [--dont-save] [-h]
                 
                 <source path>\t The source code's file path
                 -d\t\t\t\t Set the destination path - default to <source path>.IC
                 -p\t\t\t\t Print the compiled IntCode - default false
                 -r\t\t\t\t Run the code once compiled - default false
                 --dont-save\t Don't save the compiled code, it will also not run the program - default save
                 -h\t\t\t\t Help
                                
                """);
    }
}