#ifndef VM_TRANSLATOR_H
#define VM_TRANSLATOR_H

#include<string>
#include<vector>

class VMTranslator
{
    public:
    
    VMTranslator(const std::vector<std::string> & VM_input_files, const std::string& asm_output_file);
    
    ///translate all VM codes from all input VM files into the VM codes, written into the asm_output_file_
    void translate();
    
    ///translate the VM codes from the given SINGLE VM file into the VM codes, written into the asm_output_file (append mode) 
    void translateSingleVMFile(const std::string& VM_input_file);
    
    private:
    
    ///the input VM files, as a vector of strings
    std::vector<std::string> VM_input_file_v_;
 
    std::string asm_output_file_;
};



#endif