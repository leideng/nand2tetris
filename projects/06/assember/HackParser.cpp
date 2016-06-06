#include "HackParser.h"
#include<iostream>
#include <sstream> 
#include<cstdlib>
#include<cctype>
#include<bitset>

HackParser::HackParser(const std::string& code)
{
    code_ = code;
}


bool HackParser::isEmpty() const
{
    return code_.empty();
}

std::string HackParser::getCode() const
{
    return code_;
}

void HackParser::removeLeadingAndEndingWhiteSpace()
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

void HackParser::removeComments()
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


HackParser::CommandType HackParser::getCommandType() const
{
    if(isEmpty())
    {
        std::cout << "empty code" << std::endl;
        exit(-1);
    }
    
    if(code_[0] == '@')
    {
        return A_COMMAND;
    }
    
    if(code_[0] == '(' && code_[code_.size()-1] == ')')
    {
        return L_COMMAND;
    }
    return C_COMMAND;
}

std::string HackParser::getSymbol() const
{
    HackParser::CommandType command_type = getCommandType();
    if(command_type == C_COMMAND)
    {
        std::cout << "This is a C_COMMAND" << std::endl;
        exit(-1);
    }
    
    if(command_type == A_COMMAND)
    {
        return code_.substr(1, code_.size()-1);
    }
    
    if(command_type == L_COMMAND)
    {
        return code_.substr(1, code_.size()-2);
    }
}

bool HackParser::containVariable() const
{
    HackParser::CommandType command_type = getCommandType();
    if(command_type != HackParser::A_COMMAND) //not A command
    {
        return false;
    }
    
    std::string symbol = getSymbol();
    
    bool isDecimal = true;
    for(int i=0; i < symbol.size(); i++)
    {
        if(isdigit(symbol[i]))
        {
            continue;
        }
        else
        {
            isDecimal = false;
            break;
        }
    }
    return (!isDecimal);
}

std::string HackParser::convertToBinary() const
{
    HackParser::CommandType command_type = getCommandType();
    if(command_type == HackParser::A_COMMAND)
    {
        return convertToBinaryACommand();
    }
    else if (command_type == HackParser::C_COMMAND)
    {
        return convertToBinaryCCommand();
    }
    else
    {
        std::cout << "not A/C command" << std::endl;
        exit(-1);
    }
}

std::string HackParser::convertToBinaryACommand() const
{
    if(getCommandType() != HackParser::A_COMMAND)
    {
        std::cout << "not A command" << std::endl;
        exit(-1);
    }
    int value;
    std::istringstream iss(getSymbol());   
    iss >> value;   
    ///it does not contain leading zeros
    std::string binary = std::bitset<15>(value).to_string(); //to binary
    std::string leading_zeros(16-binary.size(), '0');
    binary = leading_zeros + binary;
    return binary;
}

///@Note: The C command dest=comp;jump cannot contain white space
///I did not handle white space in this program
std::string HackParser::convertToBinaryCCommand() const
{
    if(getCommandType() != HackParser::C_COMMAND)
    {
        std::cout << "not C command" << std::endl;
        exit(-1);
    }
    
    //C command: dest=comp;jump
    std::string dest;
    std::string comp;
    std::string jump; 
    
    size_t equal_idx = code_.find('=');
    size_t semicolon_idx = code_.find(';');
    
    if(equal_idx == std::string::npos) // do not find equal '='
    {
        dest = "000";
    }
    else
    {
        std::string dest_symbol = code_.substr(0, equal_idx);
        
        if(dest_symbol == "M")
        {
            dest = "001";
        }
        else if(dest_symbol == "D")
        {
            dest = "010";
        }
        else if(dest_symbol == "MD")
        {
            dest = "011";
        }
        else if(dest_symbol == "A")
        {
            dest = "100";
        }
        else if(dest_symbol == "AM")
        {
            dest = "101";
        }
        else if(dest_symbol == "AD")
        {
            dest = "110";
        }
        else if(dest_symbol == "AMD")
        {
            dest = "111";
        }
    }
    
    ///get compy_symbol based on whether it contains semicolon ";"
    std::string comp_symbol; 
    
    if(semicolon_idx == std::string::npos) //do not semicolon ';'
    {
        comp_symbol = code_.substr(equal_idx+1);
        
        jump = "000";        
    }
    else // find equal ";"
    {
        comp_symbol = code_.substr(equal_idx+1, semicolon_idx-equal_idx-1);
        
        std::string jump_symbol = code_.substr(semicolon_idx+1);
        if(jump_symbol == "JGT")
        {
            jump = "001";
        }
        else if(jump_symbol == "JEQ")
        {
            jump = "010";
        }
        else if(jump_symbol == "JGE")
        {
            jump = "011";
        }
        else if(jump_symbol == "JLT")
        {
            jump = "100";
        }
        else if(jump_symbol == "JNE")
        {
            jump = "101";
        }
         else if(jump_symbol == "JLE")
        {
            jump = "110";
        }
        else if(jump_symbol == "JMP")
        {
            jump = "111";
        }
    }
    
    if(comp_symbol == "0")
    {
        comp = "0101010";
    }
    else if(comp_symbol == "1")
    {
        comp = "0111111";
    }
    else if(comp_symbol == "-1")
    {
        comp = "0111010";
    }
    else if(comp_symbol == "D")
    {
        comp = "0001100";
    }
    else if(comp_symbol == "A")
    {
        comp = "0110000";
    }   
    else if(comp_symbol == "!D")
    {
        comp = "0001101";
    }
    else if(comp_symbol == "!A")
    {
        comp = "0110001";
    }
    else if(comp_symbol == "-D")
    {
        comp = "0001111";
    }
    else if(comp_symbol == "-A")
    {
        comp = "0110011";
    }
    else if(comp_symbol == "D+1")
    {
        comp = "0011111";
    }
    else if(comp_symbol == "A+1")
    {
        comp = "0110111";
    }
    else if(comp_symbol == "D-1")
    {
        comp = "0001110";
    }
    else if(comp_symbol == "A-1")
    {
        comp = "0110010";
    }   
    else if(comp_symbol == "D+A")
    {
        comp = "0000010";
    }
    else if(comp_symbol == "D-A")
    {
        comp = "0010011";
    }
    else if(comp_symbol == "A-D")
    {
        comp = "0000111";
    }
    else if(comp_symbol == "D&A")
    {
        comp = "0000000";
    }  
    else if(comp_symbol == "D|A")
    {
        comp = "0010101";
    }
    else if(comp_symbol == "M")
    {
        comp = "1110000";
    }   
    else if(comp_symbol == "!M")
    {
        comp = "1110001";
    }
    else if(comp_symbol == "-M")
    {
        comp = "1110011";
    }
    else if(comp_symbol == "M+1")
    {
        comp = "1110111";
    }
    else if(comp_symbol == "M-1")
    {
        comp = "1110010";
    }
    else if(comp_symbol == "D+M")
    {
        comp = "1000010";
    }
    else if(comp_symbol == "D-M")
    {
        comp = "1010011";
    }
    else if(comp_symbol == "M-D")
    {
        comp = "1000111";
    }
    else if(comp_symbol == "D&M")
    {
        comp = "1000000";
    }   
    else if(comp_symbol == "D|M")
    {
        comp = "1010101";
    }    

    std::string binary =  "111" + comp + dest + jump;
    return binary;
}