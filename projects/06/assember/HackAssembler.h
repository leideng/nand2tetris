#ifndef HACK_ASSEMBLER_H
#define HACK_ASSEMBLER_H

#include<fstream>
#include<string>
#include<vector>
#include<map>

class HackAssembler
{
    public:
    
    ///constructor function
    HackAssembler(std::string asm_file_in, std::string binary_file_out);
    
    ///the overall assembler function
    void assembler();
    
    ///remove white spaces and comments, keep updating asm_program_
    void removeWhiteSpaceAndComments();
    
    ///remove symbols by replacing them with decimal numbers, keep updating asm_program_
    void removeSymbols();
    
    ///translate pure assembler code (without white space, without symbols) into binary machine code,
    ///which is stored into binary_file_
    void translatePureAsmIntoBinary();

    
    ///private functions
    private:
    
    ///read the input asm file and construct the string vector asm_program_
    void readAsmFile();
    
    ///initialize the symbol table, by adding the predefined symbols
    void addPredefinedToSymbolTable();
    
    ///first pass the asm program, by adding the label symbols
    void addLablesToSymbolTable();
    
    ///second pass the asm program, by adding the variable symbols
    void addVariablesToSymbolTable(); 
    
    
    ///print asm_program_ 
    void printAsmProgram() const;
    
    ///print symbol_table_
    void printSymbolTable() const;
    
    
    ///private data structures
    private:
   
    ///the input assembler language file
    std::string asm_file_;
    
    ///the output binary machine language file
    std::string binary_file_;
    
    ///the string vector to store the assembler program, with each line as a string element 
    std::vector<std::string> asm_program_;
    
    ///symbol table 
    std::map<std::string, int> symbol_table_;
};

#endif