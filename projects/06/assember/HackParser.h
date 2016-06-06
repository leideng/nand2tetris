#ifndef HACK_PARSER_H
#define HACK_PARSER_H

#include<string>

/// HackPaser parses and manipulates the single-line command  
class HackParser
{
    public:
    
    ///define the command type
    enum CommandType
    {
        A_COMMAND,
        C_COMMAND,
        L_COMMAND
    };
    
    ///constructor function
    HackParser(const std::string& code);
    
    ///remove the leading white space and ending white space of the input single-line code
    ///update code_
    void removeLeadingAndEndingWhiteSpace();
    
    ///remove the comment of the input single-line code
    ///update code_
    void removeComments();
    
    ///return true if the command is empty
    bool isEmpty() const;
    
    ///get the code
    std::string getCode() const;
    
    ///get the command type (A,C, or L) 
    /// A Command: @xxx
    /// L Command: (XXX)
    /// C Command: others
    CommandType getCommandType() const;
    
    ///get the symbol in the command
    ///A Command: @xxx, return xxx
    ///L Command: (XXX), return XXX
    std::string getSymbol() const;
    
    ///judge if an A command contains a variable
    ///return true if @xxx where xxx is not a decimal number
    bool containVariable() const;
    
    ///convert the assembler command into binary machine language
    ///Note that the assembler command must have not symbols
    std::string convertToBinary() const;
    
    ///convert the A assembler command into binary machine language
    ///Note that the assembler command must have not symbols
    std::string convertToBinaryACommand() const;
    
    ///convert the C assembler command into binary machine language
    std::string convertToBinaryCCommand() const;
    
    private:
   
    ///the single-line code
    std::string code_;
};

#endif