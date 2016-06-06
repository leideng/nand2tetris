#include "HackAssembler.h"
#include<iostream>
#include<string>
int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "usage: " << argv[0] << ", <asm file>" << std::endl;
        return -1;
    }
    
    std::string asm_file(argv[1]);
    std::string hack_file = asm_file.substr(0, asm_file.size()-4) + ".hack";
    
    HackAssembler hack_assember(argv[1], hack_file);
    
    hack_assember.assembler();
    
    return 0;
}