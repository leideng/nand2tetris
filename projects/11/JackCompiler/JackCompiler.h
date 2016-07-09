#ifndef JACK_COMPILER_H
#define JACK_COMPILER_H

#include "SymbolTable.h"
#include <vector>
#include <string> 
#include <map>
#include <fstream>

using std::vector;
using std::string;
using std::map;
using std::ofstream;

class JackCompiler
{
    public:
    
    JackCompiler(const string& txt_token_file, const string& vm_file);
    
    void run();
    
    ///compile the whole class
    void compileClass();
    
    ///compile class variable declaration 
    void compileClassVarDec();
    
    ///compile class subroutine  
    void compileSubroutineDec();
    
    ///compile parameter list
    void compileParameterList();
    
    ///compile subroutine body
    ///if onlyVarDec=true, then only READ the variable declaration (we do not advance the cur_idx_)
    ///otherwise, advance cur_idx_ and generate VM codes
    void compileSubroutineBody(bool onlyVarDec = false);
    
    ///compile variable declaration inside a subroutine
    void compileVarDec();
    
    ///compile statement sequence
    void compileStatements();
    
    ///compile let statement
    void compileLetStatement();
    
    ///compile if statement
    void compileIfStatement();
    
    ///compile while statement
    void compileWhileStatement();
        
    ///compile do statement
    void compileDoStatement();
    
    ///compile return statement
    void compileReturnStatement();
    
    ///compile subroutine call
    void compileSubroutineCall();
    
    ///compile expression
    void compileExpression();
    
    ///compile a term in a expression
    void compileTerm();
    
    ///compile expression list, return number of expressions
    int compileExpressionList();
    
    
    ///get the classification of the current token
    ///Classification: keyword, symbol, integerConstant, stringConstant, identifier
    string getClassification();
    
    ///get the string of the current token
    string getString();
    
    ///get the kind of a given name in the symbol tables
    ///Note that it will look up first subroutine-scope and then class-scope symbol tables
    SymbolTable::Kind getKind(const string& name);
    
    ///get the type of a given name in the symbol tables
    ///Note that it will look up first subroutine-scope and then class-scope symbol tables
    string getType(const string& name);
    
    ///get the index of a given name in the symbol tables
    ///Note that it will look up first subroutine-scope and then class-scope symbol tables
    int getIndex(const string& name);
    
    ///get the segment of a given name in the symbol tables
    /// @return: "static", "this", "argument", "local"
    ///Note that it will look up first subroutine-scope and then class-scope symbol tables
    string getSegment(const string& name);
    
    ///assign a unique label for the converted VM code
    ///We use the following format:
    ///     _JACKCOMPILER_(label_counter_)_symbol
    ///e.g. _JACKCOMPILER_0_symbol, _JACKCOMPILER_1_symbol, etc.
    ///@note it will increase label_counter_ by 1 during each invocation
    static string assignVMLabel(const string& symbol);
    
    private:
    
    ///the input text token file, with the format <classification string\n>
    string txt_token_file_;
    
    ///the output VM file
    string vm_file_;
    
    ///the ofstream of the output vm file;
    ofstream vm_file_ofs_;
    
    ///we read the input txt_token_file_ into memory and store it as a vector of a string vector
    vector< vector<string> > tokens_vv_;
    
    ///the index of the current token to be compiled
    int cur_idx_;
    
    ///the class name
    string class_name_;
    
    ///the current subroutine type, "constructor", "function", "method"
    string subroutine_type_;
    
    ///the class-scope symbol table
    SymbolTable symbol_table_class_;
    
    ///the subroutine-scope symbol table
    ///it will be constructed when entering one subroutine
    ///it will be cleared when exiting the subroutine
    SymbolTable symbol_table_subroutine_;
    
    ///the current label counter, it is a static variable shared by all JackCompiler objects
    ///Initialize it as 0
    static int label_counter_; 
    
};

#endif