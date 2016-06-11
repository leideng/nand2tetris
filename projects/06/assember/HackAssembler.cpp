#include "HackAssembler.h"
#include "HackParser.h"
#include<iostream>
#include <sstream> 
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
    removeSymbols();
    
 //   printAsmProgram();
    
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
    
    // printSymbolTable();
    ///first pass the asm program, by adding the label symbols
    addLablesToSymbolTable();
    
    //printSymbolTable();
    ///second pass the asm program, by adding the variable symbols
    addVariablesToSymbolTable();
    
    //printSymbolTable();
    
    //now we remove the L_COMMAND lines and replace all symbols with values in the symbol_table_
    for(int line_no=0; line_no < asm_program_.size(); line_no++)
    {
        HackParser parser(asm_program_[line_no]);
        HackParser::CommandType command_type = parser.getCommandType();
        if(command_type == HackParser::L_COMMAND) // L command
        {
            asm_program_.erase(asm_program_.begin()+line_no);
            --line_no;
            continue;
        }
        
        if(command_type == HackParser::A_COMMAND && parser.containVariable()) // A command
        {
            std::string symbol = parser.getSymbol();
            if(symbol_table_.find(symbol) == symbol_table_.end())
            {
                std::cout << "cannot find the symbol: " << symbol << std::endl;
                exit(-1);
                
            }
            else
            {
                int value = symbol_table_[symbol];
                std::ostringstream convert;   // stream used for the conversion
                convert << value;      // insert the textual representation of 'value' in the characters in the stream
                std::string value_str = convert.str(); // string which will contain the decimal value 
                asm_program_[line_no] = '@' + value_str; // set the new command by replacing the symbols with values
            }
        } 
    }
}


void HackAssembler::translatePureAsmIntoBinary()
{
    std::ofstream ofs(binary_file_.c_str(),std::ofstream::out);
    for(int i=0; i<asm_program_.size(); ++i)
    {
        HackParser parser(asm_program_[i]);
        ofs << parser.convertToBinary() << std::endl;
    }
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
            //std::cout << "get a L command, with symbol: " << symbol << std::endl;
            //add to the symbol table
            symbol_table_[symbol] = instruction_line;
        }
        else // A or C command
        {
            instruction_line++;
        }
    }  
}

void HackAssembler::addVariablesToSymbolTable()
{
    int RAM_address = 16;
    for(int i=0; i < asm_program_.size(); i++)
    {
        HackParser parser(asm_program_[i]);
        HackParser::CommandType command_type = parser.getCommandType();
        if(command_type == HackParser::A_COMMAND && parser.containVariable())
        {
            std::string symbol = parser.getSymbol();
            if(symbol_table_.find(symbol) == symbol_table_.end())
            {
                symbol_table_[symbol] = RAM_address;
                RAM_address++;
            }
        }
    }
}