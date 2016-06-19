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
    
    //write the bootstrap code into the beginning of the output asm file
    //   SP=256
    //   call Sys.init
    //Here when we call Sys.init, we should have the same procedure of common call
    //For simplicity, we only increase SP by 5, i.e., we set the following bootstrap code
    //   SP=261
    //   goto Sys.init
    ofs << "@261\n" 
        << "D=A\n"
        << "@SP\n"
        << "M=D\n"
        << "@Sys.init\n"
        << "0;JMP\n\n";
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
    std::string current_function_name; //the current function name where the current VM command locates
    while(std::getline(ifs, buffer))
    {
        Parser parser(buffer, VM_input_file, current_function_name);
        
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
            //it is a little tricky to handle current function name here
            if(parser.getCommandType() == Parser::C_FUNCTION)
            {
                current_function_name = parser.getArg1(); //update current_function_name
                parser.setFunctionName(current_function_name); //reset function name for the parser
            }
        
            std::string asm_code = parser.convertToAsm();
            ofs << "//" + buffer << std::endl; //write the original VM code as a comment line
            ofs << asm_code << std::endl;
        } 
        buffer.clear();
    } 
}