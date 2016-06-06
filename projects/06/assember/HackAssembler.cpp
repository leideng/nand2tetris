#include "HackAssembler.h"
#include "HackParser.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cctype>

HackAssembler::HackAssembler(std::string asm_file_in, std::string binary_file_out)
{
    asm_file_ = asm_file_in;
    binary_file_ = binary_file_out;
    readAsmFile();
    return;
}


void HackAssembler::assembler()
{
    removeWhiteSpaceAndComments();
    
    printAsmProgram();
    
    removeSymbols();
    translatePureAsmIntoBinary();
}


void HackAssembler::removeWhiteSpaceAndComments()
{
    //remove white space line by line
    // if a line is empty or pure white space, remove this line
    // otherwise, remove the leading and ending white space, and also comments
    for(int line_no=0; line_no<asm_program_.size(); ++line_no)
    {  
        //the original code
        std::string code = asm_program_[line_no];
        
       // std::cout << "line_no=" << line_no << ":" << code << std::endl;
        HackParser parser(code);
        
        parser.removeComments();
        parser.removeLeadingAndEndingWhiteSpace();

        //remove empty line 
        if(parser.isEmpty())
        {
            asm_program_.erase(asm_program_.begin()+line_no);
            //decrement line_no such that next time it still comes to line line_no 
            --line_no;
            continue;
        }
        else
        {
            asm_program_[line_no] = parser.getCode();
        } 
    }    
}

void HackAssembler::removeSymbols()
{
    ///construct the symbol table
    ///initialize the symbol table, by adding the predefined symbols
    addPredefinedToSymbolTable();
    printSymbolTable();
    ///first pass the asm program, by adding the label symbols
    addLablesToSymbolTable();
    ///second pass the asm program, by adding the variable symbols
    addVariablesToSymbolTable();
}


void HackAssembler::translatePureAsmIntoBinary()
{
}


void HackAssembler::readAsmFile()
{
    std::ifstream ifs(asm_file_.c_str(),std::ifstream::in);
    if(!ifs.good())
    {
        std::cout << "cannot open the asm file: " << asm_file_ << std::endl;
        exit(-1);
    }
    
    std::string buffer;
    while(std::getline(ifs, buffer))
    {
        asm_program_.push_back(buffer);
        buffer.clear();
    }
    //printAsmProgram();
}


void HackAssembler::printAsmProgram() const
{
    for(int i=0; i<asm_program_.size(); ++i)
    {
        std::cout << asm_program_[i] << std::endl;
    }
}

void HackAssembler::printSymbolTable() const
{
    for(std::map<std::string,int>::const_iterator miter=symbol_table_.begin(); miter != symbol_table_.end(); ++miter)
    {
        std::cout << miter->first << "," << miter->second << std::endl;
    }
}


void HackAssembler::addPredefinedToSymbolTable()
{
    symbol_table_["SP"] = 0;
    symbol_table_["LCL"] = 1;
    symbol_table_["ARG"] = 2;
    symbol_table_["THIS"] = 3;
    symbol_table_["THAT"] = 4;
    symbol_table_["R0"] = 0;
    symbol_table_["R1"] = 1;
    symbol_table_["R2"] = 2;
    symbol_table_["R3"] = 3;
    symbol_table_["R4"] = 4;
    symbol_table_["R5"] = 5;
    symbol_table_["R6"] = 6;
    symbol_table_["R7"] = 7;
    symbol_table_["R8"] = 8;
    symbol_table_["R9"] = 9;
    symbol_table_["R10"] = 10;
    symbol_table_["R11"] = 11;
    symbol_table_["R12"] = 12;
    symbol_table_["R13"] = 13;
    symbol_table_["R14"] = 14;
    symbol_table_["R15"] = 15;
    symbol_table_["SCREEN"] = 16384;
    symbol_table_["KBD"] = 24576;
}

void HackAssembler::addLablesToSymbolTable()
{
    int instruction_line = 0;
    for(int i=0; i < asm_program_.size(); i++)
    {
        HackParser parser(asm_program_[i]);
        HackParser::CommandType command_type = parser.getCommandType();
        if(command_type == HackParser::L_COMMAND) // L command
        {
            std::string symbol = parser.getSymbol();
        }
    }  
}

void HackAssembler::addVariablesToSymbolTable()
{
}