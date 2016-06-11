#include "VMTranslator.h"
#include "Parser.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

VMTranslator::VMTranslator(const std::vector<std::string> & VM_input_files, 
                           const std::string& asm_output_file)
{
    for(int i=0; i < VM_input_files.size(); i++)
    {
        VM_input_file_v_.push_back(VM_input_files[i]);
    }
    
    asm_output_file_ = asm_output_file;
    
    //clear the asm_output_file
    std::ofstream ofs(asm_output_file_.c_str(), std::ofstream::out);
}

void VMTranslator::translate()
{
    for(int i=0; i < VM_input_file_v_.size(); i++)
    {
        translateSingleVMFile(VM_input_file_v_[i]);
    }
}

void VMTranslator::translateSingleVMFile(const std::string& VM_input_file)
{
    //open the input VM file
    std::ifstream ifs(VM_input_file.c_str(),std::ifstream::in);
    if(!ifs.good())
    {
        std::cout << "cannot open the VM file: " << VM_input_file << std::endl;
        exit(-1);
    }
    
    //open the output asm file, note that we sue append mode
    std::ofstream ofs(asm_output_file_.c_str(), std::ofstream::app);
    
    std::string buffer;
    while(std::getline(ifs, buffer))
    {
        Parser parser(buffer);
        
        parser.removeComments();
        parser.removeLeadingAndEndingWhiteSpace();

        //do not handle empty VM code (comment line)
        if(parser.isEmpty())
        {
            buffer.clear();
            continue;
        }
        else
        {
            std::string asm_code = parser.convertToAsm();
            ofs << asm_code << std::endl;
        } 
        buffer.clear();
    } 
}