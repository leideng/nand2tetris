#include "HackParser.h"
#include<iostream>
#include<cstdlib>
#include<cctype>

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
        return C_COMMAND;
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