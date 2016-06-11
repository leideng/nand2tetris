#include "VMTranslator.h"
#include<iostream> 
#include<vector>
#include<string>

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout << "usage: " << argv[0] << " <VM file 1> <VM file 2> ..." << std::endl;
        return -1;
    }
    
    std::vector<std::string> VM_input_files;
    for(int i=1; i < argc; i++)
    {
        VM_input_files.push_back(argv[i]);
    }
    
    std::string asm_output_file = "a.asm";
    
    VMTranslator VM_translator(VM_input_files, asm_output_file);
    
    VM_translator.translate();
    
    return 0;
}
