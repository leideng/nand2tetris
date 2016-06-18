#ifndef PARSER_H
#define PARSER_H

#include<string>
#include<vector>

class Parser
{
    public:
    
    ///define the VM command type
    enum CommandType
    {
        C_ARITHMETIC,
        C_PUSH,
        C_POP,
        C_LABEL,
        C_GOTO,
        C_IF,
        C_FUNCTION,
        C_RETURN,
        C_CALL
    };
    
    ///constructor
    Parser(const std::string& code, const std::string& VM_file_name);
    
    ///remove the leading white space and ending white space of the single-line code
    ///update code_
    void removeLeadingAndEndingWhiteSpace();
    
    ///remove the comment of the input single-line code
    ///update code_
    void removeComments();
    
    ///return true if the current command is empty
    bool isEmpty() const;
    
    std::string getCode() const;
   
    ///return the command type of the current command
    CommandType getCommandType() const;
    
    ///return the first argument of the current command
    ///If the current command is of type C_ARITHMETIC, return the command itself (e.g. add, sub)
    std::string getArg1() const;
    
    ///return the second argument of the current command, return int type
    int getArg2() const;
    
    ///convert the VM command into asm codes
    std::string convertToAsm() const;
    
    ///convert the VM command with C_ARITHMETIC type into asm codes
    std::string convertToAsmArithmetic() const;
    
    ///convert the VM command with C_PUSH type into asm codes
    std::string convertToAsmPush() const;
    
    ///convert the VM command with C_POP type into asm codes
    std::string convertToAsmPop() const;
    
    ///convert the VM command with C_LABEL type into asm codes
    std::string convertToAsmLabel() const;
    
    ///convert the VM command with C_GOTO type into asm codes
    std::string convertToAsmGoto() const;
    
    ///convert the VM command with C_IF type (if-goto) into asm codes
    std::string convertToAsmIf() const;
    
    ///convert the VM command with C_CALL type into asm codes
    std::string convertToAsmCall() const;
    
    ///convert the VM command with C_RETURN type into asm codes
    std::string convertToAsmReturn() const;

    ///convert the VM command with C_FUNCTION type into asm codes
    std::string convertToAsmFunction() const;
    
    ///convert the individual VM  arithmetic command into asm codes
    std::string convertToAsmAdd() const;
    std::string convertToAsmSub() const;
    std::string convertToAsmNeg() const;    
    std::string convertToAsmEq() const;
    std::string convertToAsmGt() const;
    std::string convertToAsmLt() const;
    std::string convertToAsmAnd() const;
    std::string convertToAsmOr() const;
    std::string convertToAsmNot() const;
    

    ///convert the individual (segment) VM push command into asm codes
    std::string convertToAsmPushArgument() const;
    std::string convertToAsmPushLocal() const;
    std::string convertToAsmPushThis() const;
    std::string convertToAsmPushThat() const;
    std::string convertToAsmPushTemp() const;
    std::string convertToAsmPushPointer() const;
    std::string convertToAsmPushConstant() const;
    std::string convertToAsmPushStatic() const;
    
    ///convert the individual (segment) VM pop command into asm codes
    std::string convertToAsmPopArgument() const;
    std::string convertToAsmPopLocal() const;
    std::string convertToAsmPopThis() const;
    std::string convertToAsmPopThat() const;
    std::string convertToAsmPopTemp() const;
    std::string convertToAsmPopPointer() const;
    std::string convertToAsmPopStatic() const;
    
    
    ///assign a unique label for the converted asm code
    ///We use the following format:
    ///     _VMTRANSLATOR_(label_counter_)_symbol
    ///e.g. _VMTRANSLATOR_0_symbol, _VMTRANSLATOR_1_symbol, etc.
    ///@note it will increase label_counter_ by 1 during each invocation
    static std::string assignAsmLabel(const std::string& symbol);
    
    private:

    ///the VM command
    std::string code_;
    
    ///the VM file name where code_ locates
    ///used to handle static variables
    std::string VM_file_name_;
    
    ///the function name where the current VM code locates 
    std::string function_name_;
    
    ///the current label counter, it is a static variable shared by all Parser objects
    ///Initialize it as 0
    static int label_counter_; 
};


#endif