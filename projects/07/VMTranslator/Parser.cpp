#include "Parser.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib> 
#include <cctype>

///initialize label_counter_
int Parser::label_counter_ = 0;

Parser::Parser(const std::string& code,const std::string& VM_file_name)
{
    code_ = code;
    //the CPU emulator does not support symbol with '/' in the asm code
    //we thus replace '/' by '_'
    for(int i=0; i < VM_file_name.size(); i++)
    {
        if(VM_file_name[i] == '/')
        {
            VM_file_name_ += '_';
        }
        else 
        {
            VM_file_name_ += VM_file_name[i];
        }
    }
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


std::string Parser::convertToAsmPush() const
{
    std::string segment = getArg1();    
    if(segment == "constant")
    {        
        return convertToAsmPushConstant();
    }
    else if(segment == "argument")
    {
        return convertToAsmPushArgument();
    }
    else if(segment == "local")
    {
        return convertToAsmPushLocal();
    }
    else if(segment == "this")
    {
        return convertToAsmPushThis();
    }
    else if(segment == "that")
    {
        return convertToAsmPushThat();
    }
    else if(segment == "pointer")
    {
        return convertToAsmPushPointer();
    }
    else if(segment == "temp")
    {
        return convertToAsmPushTemp();
    }          
    else if(segment == "static")
    {
        return convertToAsmPushStatic();
    }
    else
    {
        std::cout << "cannot handle such segment: " << segment << std::endl;
        exit(-1);
    }
}

std::string Parser::convertToAsmPop() const
{
    std::string segment = getArg1();    
    if(segment == "argument")
    {
        return convertToAsmPopArgument();
    }
    else if(segment == "local")
    {
        return convertToAsmPopLocal();
    }
    else if(segment == "this")
    {
        return convertToAsmPopThis();
    }
    else if(segment == "that")
    {
        return convertToAsmPopThat();
    }
    else if(segment == "pointer")
    {
        return convertToAsmPopPointer();
    }
    else if(segment == "temp")
    {
        return convertToAsmPopTemp();
    }          
    else if(segment == "static")
    {
        return convertToAsmPopStatic();
    }
    else
    {
        std::cout << "cannot handle such segment: " << segment << std::endl;
        exit(-1);
    }    
}


/********************** individual convertToAsm functions **********************/
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



/********************** individual convertToPush functions **********************/

std::string Parser::convertToAsmPushArgument() const
{
    std::string asm_code;
    int index = getArg2();
    std::ostringstream oss;
    oss << index;
    std::string index_str = oss.str();
    
    asm_code += "@ARG\n"; 
    asm_code += "D=M\n";  //store the segment base address into register D
    
    asm_code += ('@' + index_str + '\n'); //A=index
    asm_code += "A=A+D\n"; //A=segment base address + index
    asm_code += "D=M\n"; //store RAM[segment base address + index] into register D
    
    asm_code += "@SP\n";
    asm_code += "A=M\n";
    asm_code += "M=D\n";  //push RAM[segment base address + index] into the stack
    
    asm_code += "@SP\n";
    asm_code += "M=M+1\n"; //increase SP by 1
    
    return asm_code;
}

std::string Parser::convertToAsmPushLocal() const
{
    std::string asm_code;
    int index = getArg2();
    std::ostringstream oss;
    oss << index;
    std::string index_str = oss.str();
    
    asm_code += "@LCL\n"; 
    asm_code += "D=M\n";  //store the segment base address into register D
    
    asm_code += ('@' + index_str + '\n'); //A=index
    asm_code += "A=A+D\n"; //A=segment base address + index
    asm_code += "D=M\n"; //store RAM[segment base address + index] into register D
    
    asm_code += "@SP\n";
    asm_code += "A=M\n";
    asm_code += "M=D\n";  //push RAM[segment base address + index] into the stack
    
    asm_code += "@SP\n";
    asm_code += "M=M+1\n"; //increase SP by 1
    
    return asm_code;
}

std::string Parser::convertToAsmPushThis() const
{
    std::string asm_code;
    int index = getArg2();
    std::ostringstream oss;
    oss << index;
    std::string index_str = oss.str();
    
    asm_code += "@THIS\n"; 
    asm_code += "D=M\n";  //store the segment base address into register D
    
    asm_code += ('@' + index_str + '\n'); //A=index
    asm_code += "A=A+D\n"; //A=segment base address + index
    asm_code += "D=M\n"; //store RAM[segment base address + index] into register D
    
    asm_code += "@SP\n";
    asm_code += "A=M\n";
    asm_code += "M=D\n";  //push RAM[segment base address + index] into the stack
    
    asm_code += "@SP\n";
    asm_code += "M=M+1\n"; //increase SP by 1
    
    return asm_code;
}

std::string Parser::convertToAsmPushThat() const
{
    std::string asm_code;
    int index = getArg2();
    std::ostringstream oss;
    oss << index;
    std::string index_str = oss.str();
    
    asm_code += "@THAT\n"; 
    asm_code += "D=M\n";  //store the segment base address into register D
    
    asm_code += ('@' + index_str + '\n'); //A=index
    asm_code += "A=A+D\n"; //A=segment base address + index
    asm_code += "D=M\n"; //store RAM[segment base address + index] into register D
    
    asm_code += "@SP\n";
    asm_code += "A=M\n";
    asm_code += "M=D\n";  //push RAM[segment base address + index] into the stack
    
    asm_code += "@SP\n";
    asm_code += "M=M+1\n"; //increase SP by 1
    
    return asm_code;
}

std::string Parser::convertToAsmPushTemp() const
{
    std::string asm_code;
    int index = getArg2();
    if(index < 0 || index > 7)
    {
        std::cout << "index for temp segment is not in range [0,7]" << std::endl;
        exit(-1);
    }
    std::ostringstream oss;
    oss << (index + 5); //temp 0 = R5, temp 1 = R6, ..., temp 7 = R12
    asm_code += "@R" + oss.str() + '\n';
    asm_code += "D=M\n"; // store the value RAM[temp index] into register D
    
    asm_code += "@SP\n";
    asm_code += "A=M\n";
    asm_code += "M=D\n";  // push the value RAM[temp index] into the stack 
    
    asm_code += "@SP\n";
    asm_code += "M=M+1\n"; //increase SP by 1 
    
    return asm_code;
}

std::string Parser::convertToAsmPushPointer() const
{
    std::string asm_code;
    int index = getArg2();

    if(index == 0) //push pointer 0
    {
        asm_code += "@THIS\n"; 
        asm_code += "D=M\n"; //store the value RAM[THIS] into register D

        asm_code += "@SP\n";
        asm_code += "A=M\n";
        asm_code += "M=D\n";  // push the value RAM[THIS] into the stack 
    
        asm_code += "@SP\n";
        asm_code += "M=M+1\n"; //increase SP by 1 
    }
    else if(index == 1) //push pointer 1
    {
        asm_code += "@THAT\n"; 
        asm_code += "D=M\n"; //store the value RAM[THAT] into register D

        asm_code += "@SP\n";
        asm_code += "A=M\n";
        asm_code += "M=D\n";  // push the value RAM[THAT] into the stack 
    
        asm_code += "@SP\n";
        asm_code += "M=M+1\n"; //increase SP by 1 
    }
    else
    {
        std::cout << "index for pointer segment is not in range [0,1]" << std::endl;
        exit(-1);        
    }
    
    return asm_code;
}


std::string Parser::convertToAsmPushConstant() const
{
    std::string asm_code;
    int index = getArg2();
    std::ostringstream oss;
    oss << index;
    std::string index_str = oss.str();
    
    asm_code += '@' + index_str + '\n';
    asm_code += "D=A\n"; //store the constant into register A
    
    asm_code += "@SP\n";
    asm_code += "A=M\n";
    asm_code += "M=D\n"; //push the constant into the stack
    
    asm_code += "@SP\n";
    asm_code += "M=M+1\n"; //increase SP by 1
    
    return asm_code;
}

std::string Parser::convertToAsmPushStatic() const
{
    std::string asm_code;
    int index = getArg2();
    std::ostringstream oss;
    oss << index;
    std::string index_str = oss.str();
    
    asm_code += ('@' + VM_file_name_ + '.' + index_str + '\n');
    asm_code += "D=M\n";
    
    asm_code += "@SP\n";
    asm_code += "A=M\n";
    asm_code += "M=D\n"; //push the value into the stack
    
    asm_code += "@SP\n";
    asm_code += "M=M+1\n"; //increase SP by 1
    
    return asm_code;
}


/********************** individual convertToPop functions **********************/

std::string Parser::convertToAsmPopArgument() const
{
    std::string asm_code;
    std::string segment = getArg1();
    int index = getArg2();
    std::ostringstream oss;
    oss << index;
    std::string index_str = oss.str();

    asm_code += "@ARG\n";
    asm_code += "D=M\n";      //store the segment base address into register D
    asm_code += ('@' + index_str + '\n'); //A=index
    asm_code += "D=A+D\n"; //D=segment base address + index
    asm_code += "@R13\n"; //We must use R13-15 to help pop
    asm_code += "M=D\n"; //store (segment base address + index) into R13
    
    asm_code += "@SP\n";
    asm_code += "A=M-1\n";
    asm_code += "D=M\n";  //pop the stack value into register D
    
    asm_code += "@R13\n";
    asm_code += "A=M\n"; //A=segment base address + index
    asm_code += "M=D\n"; //put the popped value into RAM[segment base address + index] 
    
    asm_code += "@SP\n";
    asm_code += "M=M-1\n"; //decrease SP by 1    
   
    return asm_code;
}

std::string Parser::convertToAsmPopLocal() const
{
    std::string asm_code;
    std::string segment = getArg1();
    int index = getArg2();
    std::ostringstream oss;
    oss << index;
    std::string index_str = oss.str();

    asm_code += "@LCL\n";
    asm_code += "D=M\n";      //store the segment base address into register D
    asm_code += ('@' + index_str + '\n'); //A=index
    asm_code += "D=A+D\n"; //D=segment base address + index
    asm_code += "@R13\n"; //We must use R13-15 to help pop
    asm_code += "M=D\n"; //store (segment base address + index) into R13
    
    asm_code += "@SP\n";
    asm_code += "A=M-1\n";
    asm_code += "D=M\n";  //pop the stack value into register D
    
    asm_code += "@R13\n";
    asm_code += "A=M\n"; //A=segment base address + index
    asm_code += "M=D\n"; //put the popped value into RAM[segment base address + index] 
    
    asm_code += "@SP\n";
    asm_code += "M=M-1\n"; //decrease SP by 1    
   
    return asm_code;
}

std::string Parser::convertToAsmPopThis() const
{
    std::string asm_code;
    std::string segment = getArg1();
    int index = getArg2();
    std::ostringstream oss;
    oss << index;
    std::string index_str = oss.str();

    asm_code += "@THIS\n";
    asm_code += "D=M\n";      //store the segment base address into register D
    asm_code += ('@' + index_str + '\n'); //A=index
    asm_code += "D=A+D\n"; //D=segment base address + index
    asm_code += "@R13\n"; //We must use R13-15 to help pop
    asm_code += "M=D\n"; //store (segment base address + index) into R13
    
    asm_code += "@SP\n";
    asm_code += "A=M-1\n";
    asm_code += "D=M\n";  //pop the stack value into register D
    
    asm_code += "@R13\n";
    asm_code += "A=M\n"; //A=segment base address + index
    asm_code += "M=D\n"; //put the popped value into RAM[segment base address + index] 
    
    asm_code += "@SP\n";
    asm_code += "M=M-1\n"; //decrease SP by 1    
   
    return asm_code;
}

std::string Parser::convertToAsmPopThat() const
{
    std::string asm_code;
    std::string segment = getArg1();
    int index = getArg2();
    std::ostringstream oss;
    oss << index;
    std::string index_str = oss.str();

    asm_code += "@THAT\n";
    asm_code += "D=M\n";      //store the segment base address into register D
    asm_code += ('@' + index_str + '\n'); //A=index
    asm_code += "D=A+D\n"; //D=segment base address + index
    asm_code += "@R13\n"; //We must use R13-15 to help pop
    asm_code += "M=D\n"; //store (segment base address + index) into R13
    
    asm_code += "@SP\n";
    asm_code += "A=M-1\n";
    asm_code += "D=M\n";  //pop the stack value into register D
    
    asm_code += "@R13\n";
    asm_code += "A=M\n"; //A=segment base address + index
    asm_code += "M=D\n"; //put the popped value into RAM[segment base address + index] 
    
    asm_code += "@SP\n";
    asm_code += "M=M-1\n"; //decrease SP by 1    
   
    return asm_code;
}

std::string Parser::convertToAsmPopTemp() const
{
    std::string asm_code;
    int index = getArg2();
    if(index < 0 || index > 7)
    {
        std::cout << "index for temp segment is not in range [0,7]" << std::endl;
        exit(-1);
    }
    std::ostringstream oss;
    oss << (index + 5); //temp 0 = R5, temp 1 = R6, ..., temp 7 = R12
    
    asm_code += "@R" + oss.str() + '\n';
    asm_code += "D=A\n"; // store the value RAM[temp index] into register D
    asm_code += "@R13\n"; //We must use R13-15 to help pop
    asm_code += "M=D\n"; //store the address into R13  
    
    asm_code += "@SP\n";
    asm_code += "A=M-1\n";
    asm_code += "D=M\n";  //pop the stack into register D
    
    asm_code += "@R13\n";
    asm_code += "A=M\n"; //A=temp index
    asm_code += "M=D\n"; //put the popped value into RAM[temp index]
    
    asm_code += "@SP\n";
    asm_code += "M=M-1\n"; //decrease SP by 1     
    
    return asm_code;    
}

std::string Parser::convertToAsmPopPointer() const
{
    std::string asm_code;
    int index = getArg2();

    if(index == 0) //pop pointer 0
    {
        asm_code += "@SP\n";
        asm_code += "A=M-1\n";
        asm_code += "D=M\n";  //pop the stack into register D
        
        asm_code += "@THIS\n"; 
        asm_code += "M=D\n"; //store the popped value into RAM[THIS] 
    
        asm_code += "@SP\n";
        asm_code += "M=M-1\n"; //decrease SP by 1 
    }
    else if(index == 1) //pop pointer 1
    {
        asm_code += "@SP\n";
        asm_code += "A=M-1\n";
        asm_code += "D=M\n";  //pop the stack into register D
        
        asm_code += "@THAT\n"; 
        asm_code += "M=D\n"; //store the popped value into RAM[THIS] 
    
        asm_code += "@SP\n";
        asm_code += "M=M-1\n"; //decrease SP by 1 
    }
    else
    {
        std::cout << "index for pointer segment is not in range [0,1]" << std::endl;
        exit(-1);        
    }
    
    return asm_code;
}


std::string Parser::convertToAsmPopStatic() const
{
    std::string asm_code;
    int index = getArg2();
    std::ostringstream oss;
    oss << index;
    std::string index_str = oss.str();
    
    asm_code += ('@' + VM_file_name_ + '.' + index_str + '\n');
    asm_code += "D=A\n";
    asm_code += "@R13\n"; //We must use R13-15 to help pop
    asm_code += "M=D\n"; //store the address into R13  
    
    asm_code += "@SP\n";
    asm_code += "A=M-1\n";
    asm_code += "D=M\n";  //pop the stack into register D
        
    asm_code += "@R13\n";
    asm_code += "A=M\n"; //A=static variable address
    asm_code += "M=D\n"; //put the popped value into RAM[static variable address]
    
    asm_code += "@SP\n";
    asm_code += "M=M-1\n"; //decrease SP by 1   
    
    return asm_code;
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




