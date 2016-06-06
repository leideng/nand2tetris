#include "HackAssembler.h"
#include<iostream>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "usage: " << argv[0] << ", <asm file>" << std::endl;
        return -1;
    }
    
    HackAssembler hack_assember(argv[1], "a.hack");
    
    hack_assember.assembler();
    
    return 0;
}