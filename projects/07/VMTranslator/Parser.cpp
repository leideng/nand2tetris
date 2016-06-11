#include "Parser.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib> 
#include <cctype>

///initialize label_counter_
int Parser::label_counter_ = 0;

Parser::Parser(const std::string& code)
{
    code_ = code;
}


bool Parser::isEmpty() const
{
    return code_.empty();
}

std::string Parser::getCode() const
{
    return code_;
}

void Parser::removeLeadingAndEndingWhiteSpace()
{
    //find the first non-white letter
    int first_non_white_idx = -1;
    for(int i=0; i < code_.size(); ++i)
    {
        if(std::isspace(code_[i]))
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
        code_.clear();
        return;
    }
    
    //first the last non-white letter
    int last_non_white_idx = -1;
    for(int i=code_.size()-1; i >= 0; --i)
    {
        if(std::isspace(code_[i]))
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
    code_ = code_.substr(first_non_white_idx, last_non_white_idx-first_non_white_idx+1);
}

void Parser::removeComments()
{
    //remove comment, use a finite automata to find the pattern "//"
    // we use three states: 
    // state 1: others
    // state 2: "/"
    // state 3: "//"
    
    //the index of the beginning of comments in this line
    int comment_state_idx = -1;
    int state = 1;
    for(int i=0; i < code_.size(); ++i)
    {
        if(state == 1)
        {
            if(code_[i] == '/')
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
            if(code_[i] == '/')
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
        code_.erase(code_.begin()+comment_state_idx, code_.end());       
    }
}


Parser::CommandType Parser::getCommandType() const 
{
    std::istringstream iss(code_);
    std::string command;
    iss >> command;
    
    if(command == "add" || 
       command == "sub" || 
       command == "neg" ||
       command == "eq"  ||
       command == "gt"  ||
       command == "lt"  ||
       command == "and" ||
       command == "or"  ||
       command == "not")
    {
        return C_ARITHMETIC;
    }
    else if(command == "push")
    {
        return C_PUSH;
    }
    else if(command == "pop")
    {
        return C_POP;
    }
    else if(command == "label")
    {
        return C_LABEL;
    }
    else if(command == "goto")
    {
        return C_GOTO;
    }
    else if(command == "if-goto")
    {
        return C_IF;
    }
    else if(command == "function")
    {
        return C_FUNCTION;
    }
    else if(command == "return")
    {
        return C_RETURN;
    }
    else if(command == "call")
    {
        return C_CALL;
    }
    else
    {
        std::cout << "do not have such command: " << command << std::endl;
        exit(-1);
    }
}


std::string Parser::convertToAsm() const
{
    CommandType type = getCommandType();
    
    switch(type)
    {
        case C_ARITHMETIC:
            return convertToAsmArithmetic();
        case C_PUSH:
            return convertToAsmPush();
        case C_POP:
            return convertToAsmPop();
        case C_LABEL:
        case C_GOTO:
        case C_IF:
        case C_FUNCTION:
        case C_RETURN:
        case C_CALL:
        default:
            std::cout << "cannot handle such command type" << type << std::endl;
            exit(-1);
    }
}

std::string Parser::convertToAsmArithmetic() const
{
    std::string command = getArg1();
    
    if(command == "add")
    {
        return convertToAsmAdd();
    }
    else if(command == "sub")
    {
        return convertToAsmSub();
    }
    else if(command == "neg")
    {
        return convertToAsmNeg();
    }
    else if(command == "eq")
    {
        return convertToAsmEq();
    }
    else if(command == "gt")
    {
        return convertToAsmGt();
    }
    else if(command == "lt")
    {
        return convertToAsmLt();
    }
    else if(command == "and")
    {
        return convertToAsmAnd();
    }
    else if(command == "or")
    {
        return convertToAsmOr();
    }
    else if(command == "not")
    {
        return convertToAsmNot();
    }
    else
    {
        std::cout << "do not have such arithmetic command:" << command << std::endl;
        exit(-1);
    }
    
 
    
}

std::string Parser::convertToAsmAdd() const
{
    std::string asm_code;
    
    asm_code += "@SP\n";
    asm_code += "AM=M-1\n"; //decrease SP by 1 and let A be the address of y
    asm_code += "D=M\n";  //D=y
    asm_code += "A=A-1\n"; //A is the address of x
    asm_code += "M=D+M\n"; // x=y+x
    
    return asm_code;
}

std::string Parser::convertToAsmSub() const
{
    std::string asm_code;
    
    asm_code += "@SP\n";
    asm_code += "AM=M-1\n"; //decrease SP by 1 and let A be the address of y
    asm_code += "D=M\n";  //D=y
    asm_code += "A=A-1\n"; //A is the address x x
    asm_code += "M=M-D\n"; // x=x-y
    
    return asm_code;
}

std::string Parser::convertToAsmAnd() const
{
    std::string asm_code;
    
    asm_code += "@SP\n";
    asm_code += "AM=M-1\n"; //decrease SP by 1 and let A be the address of y
    asm_code += "D=M\n";  //D=y
    asm_code += "A=A-1\n"; //A is the address of x
    asm_code += "M=D&M\n"; // x=y AND x
    
    return asm_code;
}

std::string Parser::convertToAsmOr() const
{
    std::string asm_code;
    
    asm_code += "@SP\n";
    asm_code += "AM=M-1\n"; //decrease SP by 1 and let A be the address of y
    asm_code += "D=M\n";  //D=y
    asm_code += "A=A-1\n"; //A is the address of x
    asm_code += "M=D|M\n"; // x=y OR x
    
    return asm_code;
}

std::string Parser::convertToAsmNeg() const
{
    std::string asm_code;
    
    asm_code += "@SP\n";
    asm_code += "A=M-1\n"; //A is the address of y
    asm_code += "M=-M\n"; //y = (NOT y)
    
    return asm_code;
    
}

std::string Parser::convertToAsmNot() const
{
    std::string asm_code;
    
    asm_code += "@SP\n";
    asm_code += "A=M-1\n"; //A is the address of y
    asm_code += "M=!M\n"; //y = (NOT y)
    
    return asm_code;
}

std::string Parser::convertToAsmEq() const
{
    std::string asm_code;
    std::string EQ_label = assignAsmLabel("EQ");
    std::string END_label = assignAsmLabel("END");
    
    asm_code += "@SP\n";
    asm_code += "AM=M-1\n"; //decrease SP by 1 and let A be the address of y
    asm_code += "D=M\n"; //D=y
    asm_code += "A=A-1\n"; //A is the address of x
    asm_code += "D=M-D\n"; //D=x-y
    asm_code += ('@' +  EQ_label + '\n'); 
    asm_code += "D;JEQ\n"; //jump to (EQ_label) if D=x-y=0
    asm_code += "@SP\n";  
    asm_code += "A=M-1\n"; //A is the address of x
    asm_code += "M=0\n"; //do not jump, i.e., (D=x-y) != 0, let x=false(0x0000)
    asm_code += ('@' + END_label + '\n'); 
    asm_code += "0;JMP\n"; 
    asm_code += ('(' +  EQ_label + ')' + '\n');
    asm_code += "@SP\n"; 
    asm_code += "A=M-1\n"; //A is the address of x
    asm_code += "M=-1\n"; //if D=x-y=0, let x=true(0xFFFF) 
    asm_code += ('(' + END_label + ')' + '\n'); 

    return asm_code;
}

std::string Parser::convertToAsmGt() const
{
    std::string asm_code;
    std::string GT_label = assignAsmLabel("GT");
    std::string END_label = assignAsmLabel("END");
    
    asm_code += "@SP\n";
    asm_code += "AM=M-1\n"; //decrease SP by 1 and let A be the address of y
    asm_code += "D=M\n"; //D=y
    asm_code += "A=A-1\n"; //A is the address of x
    asm_code += "D=M-D\n"; //D=x-y
    asm_code += ('@' +  GT_label + '\n'); 
    asm_code += "D;JGT\n"; //jump to (GT_label) if D=x-y>0
    asm_code += "@SP\n";  
    asm_code += "A=M-1\n"; //A is the address of x
    asm_code += "M=0\n"; //do not jump, i.e., (D=x-y) <= 0, let x=false(0x0000)
    asm_code += ('@' + END_label + '\n'); 
    asm_code += "0;JMP\n"; 
    asm_code += ('(' +  GT_label + ')' + '\n');
    asm_code += "@SP\n"; 
    asm_code += "A=M-1\n"; //A is the address of x
    asm_code += "M=-1\n"; //if D=x-y>0, let x=true(0xFFFF) 
    asm_code += ('(' + END_label + ')' + '\n'); 

    return asm_code;    
}

std::string Parser::convertToAsmLt() const
{
    std::string asm_code;
    std::string LT_label = assignAsmLabel("LT");
    std::string END_label = assignAsmLabel("END");
    
    asm_code += "@SP\n";
    asm_code += "AM=M-1\n"; //decrease SP by 1 and let A be the address of y
    asm_code += "D=M\n"; //D=y
    asm_code += "A=A-1\n"; //A is the address of x
    asm_code += "D=M-D\n"; //D=x-y
    asm_code += ('@' +  LT_label + '\n'); 
    asm_code += "D;JLT\n"; //jump to (GT_label) if D=x-y < 0
    asm_code += "@SP\n";  
    asm_code += "A=M-1\n"; //A is the address of x
    asm_code += "M=0\n"; //do not jump, i.e., (D=x-y) >= 0, let x=false(0x0000)
    asm_code += ('@' + END_label + '\n'); 
    asm_code += "0;JMP\n"; 
    asm_code += ('(' +  LT_label + ')' + '\n');
    asm_code += "@SP\n"; 
    asm_code += "A=M-1\n"; //A is the address of x
    asm_code += "M=-1\n"; //if D=x-y>0, let x=true(0xFFFF) 
    asm_code += ('(' + END_label + ')' + '\n'); 

    return asm_code;     
}



std::string Parser::convertToAsmPush() const
{
    std::string asm_code;
    std::string segment = getArg1();
    int index = getArg2();
    
    if(segment == "constant")
    {
        if(getCommandType() != C_PUSH)
        {
            std::cout << "no such command" << std::endl;
            exit(-1);
        }
        
        std::ostringstream oss;
        oss << index;
        asm_code += '@' + oss.str() + '\n';
        asm_code += "D=A\n";
        asm_code += "@SP\n";
        asm_code += "A=M\n";
        asm_code += "M=D\n";
        asm_code += "@SP\n";
        asm_code += "M=M+1\n";
    }
    return asm_code;
}

std::string Parser::convertToAsmPop() const
{
}

std::string Parser::getArg1() const
{
    CommandType type = getCommandType();
    if(type == C_ARITHMETIC)
    {
        return code_;
    }
    else if(type == C_PUSH ||
            type == C_POP ||
            type == C_LABEL ||
            type == C_GOTO ||
            type == C_IF ||
            type == C_FUNCTION ||
            type == C_CALL)
    {
        std::istringstream iss(code_);
        std::string command;
        std::string arg1; 
        iss >> command >> arg1;
        return arg1;
    }
    else
    {
        std::cout << "cannot get the first argument for command type: " << type << std::endl;
        exit(-1);
    }  
}

int Parser::getArg2() const
{
    CommandType type = getCommandType();
    if(type == C_PUSH ||
       type == C_POP ||
       type == C_FUNCTION ||
       type == C_CALL)
    {
        std::istringstream iss(code_);
        std::string command;
        std::string arg1;
        int arg2;
        iss >> command >> arg1 >> arg2;
        return arg2;   
    }
    else
    {
        std::cout << "cannot get the second argument for command type: " << type << std::endl;
        exit(-1);
    }
}

std::string Parser::assignAsmLabel(const std::string& symbol)
{
    std::ostringstream oss;
    oss << label_counter_;
    std::string label = "_VMTRANSLATOR_" + oss.str() + '_' + symbol;
    ++label_counter_;
    return label;
}




