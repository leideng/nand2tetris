#include "JackCompiler.h"

#include <vector>
#include <string> 
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

using std::string;
using std::map;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::cout;
using std::endl;


///initialize label_counter_
int JackCompiler::label_counter_ = 0;

JackCompiler::JackCompiler(const string& txt_token_file, const string& vm_file)
{
    txt_token_file_ = txt_token_file;
    
    ///read the input txt_token_file_
    ifstream ifs(txt_token_file_.c_str());
    if(!ifs.good())
    {
        cout << "cannot open the token file: " << txt_token_file_ << endl;
        exit(-1);
    }
    
    string buffer;
    while(getline(ifs,buffer))
    {
        //buffer: classification string, separated by a space
        int space_idx = buffer.find(' ');
        vector<string> token_v(2);
        token_v[0] = buffer.substr(0, space_idx);
        token_v[1] = buffer.substr(space_idx+1);
        tokens_vv_.push_back(token_v);
    }
    
    vm_file_ = vm_file;
    vm_file_ofs_.open(vm_file_.c_str());
    
    //initial the index of the current token to be compiled 
    cur_idx_ = 0;
}
    
void JackCompiler::run()
{
    compileClass();
    return;
}


void JackCompiler::compileClass()
{
    //read keyword class
    cur_idx_++;
   
    //read the class name
    class_name_ = getString();
    cur_idx_++;
    
    //read symbol '{'
    cur_idx_++;
    
    while(!(getClassification() == "symbol" && getString() == "}"))
    {
        if(getString() == "static" ||
           getString() == "field" )
        {
            compileClassVarDec();
        }
        else if(getString() == "constructor" ||
                getString() == "function" ||
                getString() == "method")
        {
            subroutine_type_ = getString();
            compileSubroutineDec();
        }
        else 
        {
            cout << "not a class variable declaration or a class subroutine: " << getString() << endl;
            exit(-1);
        }
    }
    
    //read symbol '}'
    cur_idx_++;
    
    return;
}

void JackCompiler::compileClassVarDec()
{
    SymbolTable::Kind kind;
    //read the keyword, static or field
    if(getString() == "static")
    {
        kind = SymbolTable::STATIC;
    }
    else if(getString() == "field")
    {
        kind = SymbolTable::FIELD;
    }
    else
    {
        cout << "not static/field kind: " << getString() << endl;
        exit(-1);
    }
    cur_idx_++;
    
    //read the type: int, char, boolean, or className
    string type = getString();
    cur_idx_++;
    
    //read the first varName (mandatory)
    string name = getString();
    cur_idx_++; 
    
    //add the first name into the class-scope symbol table
    symbol_table_class_.insertEntry(name, type, kind);
    
    
    while(!(getClassification() == "symbol" && getString() == ";"))
    {
        //read symbol ","
        cur_idx_++;
        
        //read another varName
        name = getString();
        cur_idx_++; 
        
        symbol_table_class_.insertEntry(name, type, kind);
    }
    
    //read the symbol ";"
    cur_idx_++;
    
    
    return;
}

void JackCompiler::compileSubroutineDec()
{
    //read the keyword, constructor, function, or method
    cur_idx_++;
    
    //read the return type
    cur_idx_++;
    
    //read the subroutine name
    string name = class_name_ + "." + getString();
    cur_idx_++;
    
    //read the symbol '('
    cur_idx_++;
    
    //compile the parameter list
    compileParameterList();
    
    //read the symbol ')';
    cur_idx_++;
    
    //compile subroutine body's variable declaration
    compileSubroutineBody(true);
    
    int n_local = symbol_table_subroutine_.kindCount(SymbolTable::VAR);

    vm_file_ofs_ << "function " << name << " " << n_local << endl;
    
    if(subroutine_type_ == "constructor") //if this subroutine is a constructor
    {
        //get the number of fields of this class
        int n_field = symbol_table_class_.kindCount(SymbolTable::FIELD);
        vm_file_ofs_ << "push constant " << n_field << endl;
        
        //allocate memory and set the THIS register
        vm_file_ofs_ << "call Memory.alloc 1" << endl;
        vm_file_ofs_ << "pop pointer 0" << endl;
    }
    else if(subroutine_type_ == "method") //if this subroutine is a method
    {
        //set the THIS register
        vm_file_ofs_ << "push argument 0" << endl;
        vm_file_ofs_ << "pop pointer 0" << endl;
    }
    //compile subroutine body and generate VM code
    compileSubroutineBody(false);
    
    //clear the subroutine-scope symbol table
    symbol_table_subroutine_.clear();
}

 
void JackCompiler::compileParameterList()
{
    if(subroutine_type_ == "method") //this is a class method
    {
        //insert the artificial "this" as the first argument
        //we will not look up "this", but it can update the number of argument of the current method
        //see "int n_local = symbol_table_subroutine_.kindCount(SymbolTable::VAR);" in JackCompiler::compileSubroutineDec()
        symbol_table_subroutine_.insertEntry("this", "int", SymbolTable::ARGUMENT); 
    }
    
    while(getString() != ")") 
    {
        //read the type
        string type = getString();
        cur_idx_++;
        
        //read the name
        string name = getString();
        cur_idx_++;
        
        symbol_table_subroutine_.insertEntry(name, type, SymbolTable::ARGUMENT);
        
        if(getString() == ",")
        {
            //read the symbol ","
            cur_idx_++;
        }
    }
    
    return;
}

void JackCompiler::compileSubroutineBody(bool onlyVarDec)
{
    if(onlyVarDec) //this is a little bit tricky to get the number of local variables
    {
        //store the current index
        int old_cur_idx = cur_idx_;
        
        //read the symbol "{"
        cur_idx_++;
        
        //compile variable declaration
        compileVarDec();
        
        //read the symbol "}" 
        cur_idx_++;
        
        //recovery the current index
        cur_idx_ = old_cur_idx;
    }
    else
    {
        //read the symbol "{"
        cur_idx_++;
        
        //compile variable declaration
        compileVarDec();
        
        //compile statement sequence
        compileStatements();
        
        //read the symbol "}" 
        cur_idx_++;
    }
    
    return;
}


void JackCompiler::compileVarDec()
{      
    while(getString() == "var")
    {
        
        //read the keyword "var"
        cur_idx_++;
        
        //read type
        string type = getString();
        cur_idx_++;
        
        //read varName
        string name = getString();
        cur_idx_++;
        
        symbol_table_subroutine_.insertEntry(name, type, SymbolTable::VAR);
        
        while(getString() == ",")
        {
            //read symbol ","
            cur_idx_++;
            
            //write varName      
            name = getString();
            cur_idx_++;
            
            symbol_table_subroutine_.insertEntry(name, type, SymbolTable::VAR);
        }
        
        //read the symbol ";"
        cur_idx_++;
        
    }
    
    return;
}


void JackCompiler::compileStatements()
{
    
    while(1)
    {
        if(getString() == "let")
        {
            compileLetStatement();
        }
        else if(getString() == "if")
        {
            compileIfStatement();
        }
        else if(getString() == "while")
        {
            compileWhileStatement();
        }
        else if(getString() == "do")
        {
            compileDoStatement();
        }
        else if(getString() == "return")
        {
            compileReturnStatement();
        }
        else
        {
            break;
        }
    }
    
    return;
}



void JackCompiler::compileLetStatement()
{
    //read the keyword let
    cur_idx_++;
    
    //read varName
    string name = getString();
    cur_idx_++;
    
    string segment = getSegment(name);
    int index =getIndex(name);

    if(getString() == "[")  //generate VM code for array
    {
        //push the array base address
        vm_file_ofs_ << "push " << segment << " " << index << endl;
        
        //read the symbol "["
        cur_idx_++;
        
        //read expression
        compileExpression();
        
        //read the symbol "]"
        cur_idx_++;
        
        //push the array element address 
        vm_file_ofs_ << "add" << endl;
       
        
        //read the symbol "="
        cur_idx_++;
    
        //read the expression
        compileExpression();
    
        //pop the expression result to temp 0
        vm_file_ofs_ << "pop temp 0" << endl;
        //pop the array element address to the that register
        vm_file_ofs_ << "pop pointer 1" << endl;
        //push the expression result, that is stored in temp 0
        vm_file_ofs_ << "push temp 0" << endl;
        //pop the result to that 0
        vm_file_ofs_ << "pop that 0" << endl;
        //read the symbol ";"
        cur_idx_++;
    }
    else
    {
        //generate VM code for non-array
        
        //read the symbol "="
        cur_idx_++;
    
        //read the expression
        compileExpression();
        
        vm_file_ofs_ << "pop " << segment << " " << index << endl;
    
        //read the symbol ";"
        cur_idx_++; 
    }

    return;
}


void JackCompiler::compileIfStatement()
{
    //see figure 11.5 in the book
    string label_L1 = assignVMLabel("If_L1");
    string label_L2 = assignVMLabel("If_L2");
    
    
    //read the keyword "if"
    cur_idx_++;
    
    //read the symbol "("
    cur_idx_++;
    
    //write the expression
    compileExpression();
    //get the "not"
    vm_file_ofs_ <<"not" << endl;
    
    //read the symbol ")"
    cur_idx_++;
    
    vm_file_ofs_ <<"if-goto " << label_L1 << endl;
    
    //read the symbol "{"
    cur_idx_++;

    //write the statements
    compileStatements();
    
    //read the symbol "}"
    cur_idx_++; 

    
    
    if(getString() == "else")
    {
        vm_file_ofs_ << "goto " << label_L2 << endl;
        
        //read the keyword "else"
        cur_idx_++;
        
        //read the symbol "{"
        cur_idx_++;

        vm_file_ofs_ << "label " << label_L1 << endl;
        
        //compile the statements
        compileStatements();
        
        //read the symbol "}"
        cur_idx_++; 
        
        vm_file_ofs_ << "label " << label_L2 << endl;
    }
    else //there does not exist "else" part
    {
        vm_file_ofs_ << "label " << label_L1 << endl;
    }
    
    
       
    return;
}

void JackCompiler::compileWhileStatement()
{
    //see figure 11.5 in the book
    string label_L1 = assignVMLabel("While_L1");
    string label_L2 = assignVMLabel("While_L2");
    
    //read the keyword "while"
    cur_idx_++;
    
    //read the symbol "("
    cur_idx_++;
    
    vm_file_ofs_ << "label " << label_L1 << endl;

    //compile the expression
    compileExpression();
    //get the "not"
    vm_file_ofs_ <<"not" << endl;
    
    vm_file_ofs_ <<"if-goto " << label_L2 << endl;
    
    //read the symbol ")"
    cur_idx_++;
    
    //read the symbol "{"
    cur_idx_++;
    
    //write the statements
    compileStatements();
    
    vm_file_ofs_ <<"goto " << label_L1 << endl;
    
    //read the symbol "}"
    cur_idx_++;
    
    vm_file_ofs_ <<"label " << label_L2 << endl;
    
    return;
}

void JackCompiler::compileDoStatement()
{
    
    //read the keyword "do"
    cur_idx_++;
    
    compileSubroutineCall();
    
    //read the symbol ";"
    cur_idx_++;
    
    //just pop the return value 
    vm_file_ofs_ << "pop temp 0" << endl;
    
    return;
}

void JackCompiler::compileReturnStatement()
{
    
    //read the keyword "return"
    cur_idx_++;
    
    if(getString() != ";")
    {
        compileExpression();
        vm_file_ofs_ << "return" << endl;
    }
    else //just return 0
    {
        vm_file_ofs_ << "push constant 0" << endl;
        vm_file_ofs_ << "return" << endl;
    }
    
    //read the symbol ";"
    cur_idx_++;
     
    return;
}


void JackCompiler::compileSubroutineCall()
{
    //get subroutine name or class name/variable name
    string name = getString(); //subroutine name or a object name, or a class name
    cur_idx_++;
    
    bool isMethod = true;
    
    if(getString() == ".")  //name is an object name or a class name
    {
        if(!symbol_table_subroutine_.isExist(name) && !symbol_table_class_.isExist(name)) 
            //name is a class name, this subroutine is a constructor or a function, but not method 
        {
            isMethod = false;
            
            //read the symbol "."
            cur_idx_++;
                   
            //update the VM function name
            name = name + "." + getString(); 
            cur_idx_++;
        }
        else
        {
            isMethod = true;

            string segment = getSegment(name);
            string type = getType(name);
            int index = getIndex(name);
            
            vm_file_ofs_ << "push " << segment << " " << index << endl;
            
            //read the symbol "."
            cur_idx_++;
                   
            //update the VM function name
            name = type + "." + getString(); 
            cur_idx_++;
        }
    }
    else //current class subroutine
    {
        isMethod = true;
        
        //push  this
        vm_file_ofs_ << "push pointer 0" << endl;
        
        name = class_name_ + "." + name; //update the VM function name
    }
    
    //read the symbol "(";
    cur_idx_++;
    
    //compile expression list
    int n_arg = compileExpressionList();
    
    if(isMethod)
    {
        n_arg++;
    }
    
    vm_file_ofs_ << "call " << name << " " << n_arg << endl;
    

    //read the symbol ")"
    cur_idx_++;   
}


void JackCompiler::compileExpression()
{    
    //we need to use the postfix order to generate the VM code
    //that is to say "term1 op term2" should be generated as "vm(term1) vm(term2) vm(op)" 
    //similarly  "term1 op1 term2 op2 term 3" can ge generated as "vm(term1 op1 term 2) vm(term3) vm(op2)"
    
    //compile term
    compileTerm();  //vm(term1)
    
    while(getClassification() == "symbol" &&
       (getString() == "+" ||
        getString() == "-" ||
        getString() == "*" ||
        getString() == "/" ||
        getString() == "&" ||
        getString() == "|" ||
        getString() == "<" ||
        getString() == ">" ||
        getString() == "="))
    {
        
        //read the operator (symbol)
        string op = getString();
        cur_idx_++;
        
        //compile term
        compileTerm();  //vm(term2)
        
        if(op == "+")  //vm(op)
        {
            vm_file_ofs_ << "add" << endl;
        }
        else if(op == "-")
        {
            vm_file_ofs_ << "sub" << endl;
        }
        else if(op == "*")
        {
            vm_file_ofs_ << "call Math.multiply 2" << endl;
        }
        else if(op == "/")
        {
            vm_file_ofs_ << "call Math.divide 2" << endl;
        }
        else if(op == "&")
        {
            vm_file_ofs_ << "and" << endl;
        }
        else if(op == "|")
        {
            vm_file_ofs_ << "or" << endl;
        }
        else if(op == "<")
        {
            vm_file_ofs_ << "lt" << endl;
        }
        else if(op == ">")
        {
            vm_file_ofs_ << "gt" << endl;
        }
        else if(op == "=")
        {
            vm_file_ofs_ << "eq" << endl;
        }
    } 
    
    return;
}


//The implementation of this function is quite long, but all 
//branches follows the grammar rules of term, see Figure 10.5 in the book
void JackCompiler::compileTerm()
{
    if(getClassification() == "integerConstant")
    {
        vm_file_ofs_ << "push constant " << getString() << endl;
        cur_idx_++;
    }
    else if(getClassification() == "stringConstant")
    {
        string str = getString();
        vm_file_ofs_ << "push constant " << str.size() << endl;
        vm_file_ofs_ << "call String.new 1" << endl;
        for(int i=0; i < str.size(); ++i)
        {
            vm_file_ofs_ << "push constant " << (int) (str[i]) << endl;
            vm_file_ofs_ << "call String.appendChar 2" << endl;
        }
        
        cur_idx_++;
    }
    else if(getClassification() == "keyword" &&
            (getString() == "true" ||
             getString() == "false" ||
             getString() == "null" ||
             getString() == "this"))
    {
        if(getString() == "true")
        {
            vm_file_ofs_ << "push constant 1" << endl;
            vm_file_ofs_ << "neg" << endl;
        }
        else if(getString() == "false" || getString() == "null")
        {
            vm_file_ofs_ << "push constant 0" << endl;
        }
        else if(getString() == "this")
        {
            vm_file_ofs_ << "push pointer 0" << endl;
        }
        cur_idx_++;
    }
    else if(getClassification() == "identifier") //could be varName or subroutineCall
    {
        //judge whether it is a subroutineCall by looking-ahead
        int index_temp = cur_idx_;
        bool isSubroutineCall = false;
        
        if(tokens_vv_[index_temp+1][0] == "symbol" &&
           tokens_vv_[index_temp+1][1] == "(")
        {
            isSubroutineCall = true;
        }
        else if(tokens_vv_[index_temp+1][0] == "symbol" &&
                tokens_vv_[index_temp+1][1] == ".")
        {
            if(tokens_vv_[index_temp+2][0] == "identifier" &&
               tokens_vv_[index_temp+3][0] == "symbol" &&
               tokens_vv_[index_temp+3][1] == "(")
            {
                isSubroutineCall = true;
            }
        }
        else
        {
            //do nothing
        }
        
        if(isSubroutineCall) //is subroutineCall
        {
            compileSubroutineCall();
        }
        else //just variable
        {
            //read varName
            string name = getString();
            cur_idx_++;
               
            string segment = getSegment(name);
            int index = getIndex(name);
            
            if(getClassification() == "symbol" &&
               getString() == "[") //this is an array name
            {
                //push the array base address
                vm_file_ofs_ << "push " << segment << " " << index << endl;
        
                //read the symbol "["
                cur_idx_++;
                
                //compile the expression
                compileExpression();
                
                //push the array element address 
                vm_file_ofs_ << "add" << endl;
                //pop the array element address to the that register
                vm_file_ofs_ << "pop pointer 1" << endl;
                //push the value of the array element address
                vm_file_ofs_ << "push that 0" << endl;
                //read the symbol "]"
                cur_idx_++;
            }
            else //this is not an array name
            {
                vm_file_ofs_ << "push " << segment << " " << index << endl;
            }
        }
    }
    else if(getClassification() == "symbol" && getString() == "(")
    {
        //read the symbol "("
        cur_idx_++;
        
        //compile the expression
        compileExpression();
        
        //read the symbol ")"
        cur_idx_++;
    }
    else if(getClassification() == "symbol" &&
            (getString() == "-" || getString() == "~"))
    {
        //read the unary operator
        string op = getString();
        cur_idx_++;
        
        //compile the term
        compileTerm();
        
        if(op == "-")
        {
            vm_file_ofs_ << "neg" << endl;
        }
        else if(op == "~")
        {
            vm_file_ofs_ << "not" << endl;
        }
    }
    else
    {
        cout << "cannot handle such term: getClassification()=" << getClassification()
             << ", getString()=" << getString() << endl;
        exit(-1);
    }
    
    return;
}

int JackCompiler::compileExpressionList()
{
    int ret = 0; 
    if(getString() != ")")
    {
        //compile the expression
        compileExpression();
        ret++;
        
        while(getString() == ",")
        {
            //read the symbol ","
            //writeSymbol(getString());
            cur_idx_++;
            
            //write the expression
            compileExpression();
            ret++;
        }
    }
    
    return ret; 
}  


string JackCompiler::getClassification()
{
    return tokens_vv_[cur_idx_][0];
}

string JackCompiler::getString()
{
    return tokens_vv_[cur_idx_][1];
}

string JackCompiler::assignVMLabel(const string& symbol)
{
    std::ostringstream oss;
    oss << label_counter_;
    string label = "_JACKCOMPILER_" + oss.str() + '_' + symbol;
    ++label_counter_;
    return label;
}

SymbolTable::Kind JackCompiler::getKind(const string& name)
{
    if(symbol_table_subroutine_.isExist(name))
    {
        return symbol_table_subroutine_.getKind(name);
    }
    else if(symbol_table_class_.isExist(name))
    {
        return symbol_table_class_.getKind(name);
    }
    else
    {
        cout << "cannot find the name in both symbol tables: " << name << endl;
        exit(-1);
    }
}

string JackCompiler::getType(const string& name)
{
    if(symbol_table_subroutine_.isExist(name))
    {
        return symbol_table_subroutine_.getType(name);
    }
    else if(symbol_table_class_.isExist(name))
    {
        return symbol_table_class_.getType(name);
    }
    else
    {
        cout << "cannot find the name in both symbol tables: " << name << endl;
        exit(-1);
    }
}

int JackCompiler::getIndex(const string& name)
{
    if(symbol_table_subroutine_.isExist(name))
    {
        return symbol_table_subroutine_.getIndex(name);
    }
    else if(symbol_table_class_.isExist(name))
    {
        return symbol_table_class_.getIndex(name);
    }
    else
    {
        cout << "cannot find the name in both symbol tables: " << name << endl;
        exit(-1);
    }
}

string JackCompiler::getSegment(const string& name)
{
    SymbolTable::Kind kind = getKind(name);
    
    string segment;
    switch(kind)
    {
        case SymbolTable::STATIC:
            segment = "static";
            break;
        case SymbolTable::FIELD:
            segment = "this";
            break;
        case SymbolTable::ARGUMENT:
            segment = "argument";
            break;
        case SymbolTable::VAR:
            segment = "local";
    } 
    return segment;
}