#include "HackAssembler.h"
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
    
 //   printAsmProgram();
    
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
        
        removeCommentsSingleLine(code);
        removeLeadingAndEndingWhiteSpaceSingleLine(code);

        //remove empty line 
        if(code.empty())
        {
            asm_program_.erase(asm_program_.begin()+line_no);
            //decrement line_no such that next time it still comes to line line_no 
            --line_no;
            continue;
        }
        else
        {
            asm_program_[line_no] = code;
        } 
    }    
}

void HackAssembler::removeSymbols()
{
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
    return;
}


void HackAssembler::printAsmProgram() const
{
    for(int i=0; i<asm_program_.size(); ++i)
    {
        std::cout << asm_program_[i] << std::endl;
    }
    return;
}

void HackAssembler::printSymbolTable() const
{
    for(std::map<std::string,int>::const_iterator miter=symbol_table_.begin(); miter != symbol_table_.end(); ++miter)
    {
        std::cout << miter->first << "," << miter->second << std::endl;
    }
    return;
}

void HackAssembler::removeLeadingAndEndingWhiteSpaceSingleLine(std::string& code)
{
    //find the first non-white letter
    int first_non_white_idx = -1;
    for(int i=0; i < code.size(); ++i)
    {
        if(std::isspace(code[i]))
        {
            continue;
        }
        else
        {
            first_non_white_idx = i;
            break;
        }            
    }
    //empty line or white-space line
    if(first_non_white_idx == -1)
    {
        code.clear();
        return;
    }
    
    //first the last non-white letter
    int last_non_white_idx = -1;
    for(int i=code.size()-1; i >= 0; --i)
    {
        if(std::isspace(code[i]))
        {
            continue;
        }
        else
        {
            last_non_white_idx = i;
            break;
        }              
    }
    
    //remove leading white space and ending white space
    code = code.substr(first_non_white_idx, last_non_white_idx-first_non_white_idx+1);
}

void HackAssembler::removeCommentsSingleLine(std::string& code)
{
    //remove comment, use a finite automata to find the pattern "//"
    // we use three states: 
    // state 1: others
    // state 2: "/"
    // state 3: "//"
    
    //the index of the beginning of comments in this line
    int comment_state_idx = -1;
    int state = 1;
    for(int i=0; i < code.size(); ++i)
    {
        if(state == 1)
        {
            if(code[i] == '/')
            {
                //turn to state 2: "/"
                state = 2;
            }
            else
            {
                //still in state 1: others
                state = 1;
            }
        }
        else if(state == 2)
        {
            if(code[i] == '/')
            {
                //turn to state 3: "//"
                state = 3;
            }
            else
            {
                //turn to state 1: others
                state = 1;
            }
        }
        
        // state == 3, we have found "//"
        if(state == 3)
        {
            comment_state_idx = i-1;
            break; 
        }
    }
    
    //std::cout << "comment_state_idx=" << comment_state_idx << std::endl;
    if(comment_state_idx != -1) //we did find comments
    {
        code.erase(code.begin()+comment_state_idx, code.end());       
    }
}