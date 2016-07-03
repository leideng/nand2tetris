#include "JackParser.h"
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<cstdlib>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

///To make the program simple, I will have very minimal error-detection codes
JackParser::JackParser(const string& txt_token_file, const string& xml_file)
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
    
    xml_file_ = xml_file;
    xml_file_ofs_.open(xml_file_.c_str());
    
    ///initial the index of the current token to be parsed 
    cur_idx_ = 0;
}

void JackParser::run()
{
    parseClass();
    return;
}

void JackParser::parseClass()
{
    //write the label "<class>"
    xml_file_ofs_ << "<class>" << endl;
    
    //read keyword class
    writeKeyword("class");
    cur_idx_++;
   
    //read the class name
    writeIdentifier(getString());
    cur_idx_++;
    
    //read symbol '{'
    writeSymbol(getString());
    cur_idx_++;
    
    while(!(getClassification() == "symbol" && getString() == "}"))
    {
        if(getString() == "static" ||
           getString() == "field" )
        {
            parseClassVarDec();
        }
        else if(getString() == "constructor" ||
                getString() == "function" ||
                getString() == "method")
        {
            parseSubroutineDec();
        }
        else 
        {
            cout << "not a class variable declaration or a class subroutine: " << getString() << endl;
            exit(-1);
        }
    }
    
    //read symbol '}'
    writeSymbol(getString());
    
    //write the label "</class>"
    xml_file_ofs_ << "</class>" << endl;
    return;
}

void JackParser::parseClassVarDec()
{
    //write the label "<classVarDec>"
    xml_file_ofs_ << "<classVarDec>" << endl;
    
    //write the keyword, static or field
    writeKeyword(getString());
    cur_idx_++;
    
    //write the type: int, char, boolean, or className
    if(getClassification() == "keyword")
    {
        writeKeyword(getString());
        cur_idx_++;
    }
    else //getClassification() == "identifier"
    {
        writeIdentifier(getString());
        cur_idx_++;
    }
    
    //write the first varName (mandatory)
    writeIdentifier(getString());
    cur_idx_++; 
        
    while(!(getClassification() == "symbol" && getString() == ";"))
    {
        //write symbol ","
        writeSymbol(getString());
        cur_idx_++;
        
        writeIdentifier(getString());
        cur_idx_++; 
    }
    
    //write the symbol ";"
    writeSymbol(getString());
    cur_idx_++;
    
    //write the label "</classVarDec>"
    xml_file_ofs_ << "</classVarDec>" << endl;
    
    return;
}

void JackParser::parseSubroutineDec()
{
    //write the label "<subroutineDec>"
    xml_file_ofs_ << "<subroutineDec>" << endl;
    
    //write the keyword, constructor, function, or method
    writeKeyword(getString());
    cur_idx_++;
    
    //write the return type
    writeType();
    cur_idx_++;
    
    //write the subroutine name
    writeIdentifier(getString());
    cur_idx_++;
    
    //write the symbol '(';
    writeSymbol(getString());
    cur_idx_++;
    
    //parse the parameter list
    parseParameterList();
    
    //write the symbol ')';
    writeSymbol(getString());
    cur_idx_++;
    
    //parse subroutine body
    parseSubroutineBody();
    
    //write the label "</subroutineDec>"
    xml_file_ofs_ << "</subroutineDec>" << endl;
    
    return;
}

void JackParser::parseParameterList()
{
    //write the label "<parameterList>"
    xml_file_ofs_ << "<parameterList>" << endl;
    
    while(getString() != ")") 
    {
        writeType();
        cur_idx_++;
        
        writeIdentifier(getString());
        cur_idx_++;
        
        if(getString() == ",")
        {
            writeSymbol(getString());
            cur_idx_++;
        }
    }
 
    //write the label "</parameterList>"
    xml_file_ofs_ << "</parameterList>" << endl;
    
    return;
}

void JackParser::parseSubroutineBody()
{
    //write the label "<subroutineBody>"
    xml_file_ofs_ << "<subroutineBody>" << endl;
    
    //write the symbol "{"
    writeSymbol(getString());
    cur_idx_++;
    
    //write variable declaration
    parseVarDec();
    
    //write statement sequence
    parseStatements();
    
    //write the symbol "}" 
    writeSymbol(getString());
    cur_idx_++;
    
    //write the label "</subroutineBody>"
    xml_file_ofs_ << "</subroutineBody>" << endl;
    
    return;
}


void JackParser::parseVarDec()
{      
    while(getString() == "var")
    {
        //write the label "<varDec>"
        xml_file_ofs_ << "<varDec>" << endl;
        
        //write the keyword "var"
        writeKeyword(getString());
        cur_idx_++;
        
        //write type
        writeType();
        cur_idx_++;
        
        //write varName
        writeIdentifier(getString());
        cur_idx_++;
        
        while(getString() == ",")
        {
            //write symbol ","
            writeSymbol(getString());
            cur_idx_++;
            
            //write varName      
            writeIdentifier(getString());
            cur_idx_++;
        }
        
        //write the symbol ";"
        writeSymbol(getString());
        cur_idx_++;
        
        //write the label "</varDec>"
        xml_file_ofs_ << "</varDec>" << endl;
    }
    
    return;
}

void JackParser::parseStatements()
{
    //write the label "<statements>"
    xml_file_ofs_ << "<statements>" << endl;
    
    while(1)
    {
        if(getString() == "let")
        {
            parseLetStatement();
        }
        else if(getString() == "if")
        {
            parseIfStatement();
        }
        else if(getString() == "while")
        {
            parseWhileStatement();
        }
        else if(getString() == "do")
        {
            parseDoStatement();
        }
        else if(getString() == "return")
        {
            parseReturnStatement();
        }
        else
        {
            break;
        }
    }
    
    //write the label "</statements>"
    xml_file_ofs_ << "</statements>" << endl;    
    return;
}



void JackParser::parseLetStatement()
{
    //write the label "<letStatement>"
    xml_file_ofs_ << "<letStatement>" << endl;

    //write the keyword let
    writeKeyword(getString());
    cur_idx_++;
    
    //write varName
    writeIdentifier(getString());
    cur_idx_++;
    
    if(getString() == "[") 
    {
        //write the symbol "["
        writeSymbol(getString());
        cur_idx_++;
        
        //write expression
        parseExpression();
        
        //write the symbol "]"
        writeSymbol(getString());
        cur_idx_++;
    }
    
    //write the symbol "="
    writeSymbol(getString());
    cur_idx_++;
    
    //write the expression
    parseExpression();
    
    //write the symbol ";"
    writeSymbol(getString());
    cur_idx_++;
    
    //write the label "</letStatement>"
    xml_file_ofs_ << "</letStatement>" << endl;
    
    return;
}

void JackParser::parseIfStatement()
{
    //write the label "<ifStatement>"
    xml_file_ofs_ << "<ifStatement>" << endl;
    
    //write the keyword "if"
    writeKeyword(getString());
    cur_idx_++;
    
    //write the symbol "("
    writeSymbol(getString());
    cur_idx_++;
    
    //write the expression
    parseExpression();
    
    //write the symbol ")"
    writeSymbol(getString());
    cur_idx_++;
    
    //write the symbol "{"
    writeSymbol(getString());
    cur_idx_++;

    //write the statements
    parseStatements();
    
    //write the symbol "}"
    writeSymbol(getString());
    cur_idx_++; 

    if(getString() == "else")
    {
        //write the keyword "else"
        writeKeyword(getString());
        cur_idx_++;
        
        //write the symbol "{"
        writeSymbol(getString());
        cur_idx_++;

        //write the statements
        parseStatements();
        
        //write the symbol "}"
        writeSymbol(getString());
        cur_idx_++; 
    }
    
    //write the label "</ifStatement>"
    xml_file_ofs_ << "</ifStatement>" << endl;    
    return;
}

void JackParser::parseWhileStatement()
{
    //write the label "<whileStatement>"
    xml_file_ofs_ << "<whileStatement>" << endl;
    
    //write the keyword "while"
    writeKeyword(getString());
    cur_idx_++;
    
    //write the symbol "("
    writeSymbol(getString());
    cur_idx_++;
    
    //write the expression
    parseExpression();
    
    //write the symbol ")"
    writeSymbol(getString());
    cur_idx_++;
    
    //write the symbol "{"
    writeSymbol(getString());
    cur_idx_++;
    
    //write the statements
    parseStatements();
    
    //write the symbol "}"
    writeSymbol(getString());
    cur_idx_++;
    
    //write the label "</whileStatement>"
    xml_file_ofs_ << "</whileStatement>" << endl;
    return;
}

void JackParser::parseDoStatement()
{
    //write the label "<doStatement>"
    xml_file_ofs_ << "<doStatement>" << endl;
    
    //write the keyword "do"
    writeKeyword(getString());
    cur_idx_++;
    
    parseSubroutineCall();
    
    //write the symbol ";"
    writeSymbol(getString());
    cur_idx_++;
    
    //write the label "</doStatement>"
    xml_file_ofs_ << "</doStatement>" << endl;
    return;
}

void JackParser::parseReturnStatement()
{
    //write the label "<returnStatement>"
    xml_file_ofs_ << "<returnStatement>" << endl;
    
    //write the keyword "return"
    writeKeyword(getString());
    cur_idx_++;
    
    if(getString() != ";")
    {
        parseExpression();
    }
    
    //write the symbol ";"
    writeSymbol(getString());
    cur_idx_++;
    
    //write the label "</returnStatement>"
    xml_file_ofs_ << "</returnStatement>" << endl;    
    return;
}

void JackParser::parseSubroutineCall()
{
    //write subroutine name or class name/variable name
    writeIdentifier(getString());
    cur_idx_++;
    
    if(getString() == ".") 
    {
        //write the symbol "."
        writeSymbol(getString());
        cur_idx_++;
        
        //write the subroutine name
        writeIdentifier(getString());
        cur_idx_++;
    }
    
    //write the symbol "(";
    writeSymbol(getString());
    cur_idx_++;
    
    //write expression list
    parseExpressionList();
    
    //write the symbol ")"
    writeSymbol(getString());
    cur_idx_++;  
}

void JackParser::parseExpression()
{    
    //write the label "<expression>"
    xml_file_ofs_ << "<expression>" << endl; 
    
    //parse term
    parseTerm();
    
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
        //write the operator (symbol)
        writeSymbol(getString());
        cur_idx_++;
        
        //parse term
        parseTerm();
    }
    //write the label "</expression>"
    xml_file_ofs_ << "</expression>" << endl; 
    
    return;
}

void JackParser::parseTerm()
{
    //write the label "<term>"
    xml_file_ofs_ << "<term>" << endl; 
     
    if(getClassification() == "integerConstant")
    {
        writeIntegerConstant(getString());
        cur_idx_++;
    }
    else if(getClassification() == "stringConstant")
    {
        writeStringConstant(getString());
        cur_idx_++;
    }
    else if(getClassification() == "keyword" &&
            (getString() == "true" ||
             getString() == "false" ||
             getString() == "null" ||
             getString() == "this"))
    {
        writeKeyword(getString());
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
        
        if(isSubroutineCall)
        {
            parseSubroutineCall();
        }
        else
        {
            //write varName
            writeIdentifier(getString());
            cur_idx_++;
            
            if(getClassification() == "symbol" &&
               getString() == "[")
            {
                //write the symbol "["
                writeSymbol(getString());
                cur_idx_++;
                
                //parse the expression
                parseExpression();
                
                //write the symbol "]"
                writeSymbol(getString());
                cur_idx_++;
            }
        }
    }
    else if(getClassification() == "symbol" && getString() == "(")
    {
        //write the symbol "("
        writeSymbol(getString());
        cur_idx_++;
        
        //parse the expression
        parseExpression();
        
        //write the symbol ")"
        writeSymbol(getString());
        cur_idx_++;
    }
    else if(getClassification() == "symbol" &&
            (getString() == "-" || getString() == "~"))
    {
        //write the unary operator
        writeSymbol(getString());
        cur_idx_++;
        
        //parse the term
        parseTerm();
    }
    else
    {
        cout << "cannot handle such term: getClassification()=" << getClassification()
             << ", getString()=" << getString() << endl;
        exit(-1);
    }
    
    //write the label "</term>"
    xml_file_ofs_ << "</term>" << endl;
    return;
}

void JackParser::parseExpressionList()
{
    //write the label "<expressionList>"
    xml_file_ofs_ << "<expressionList>" << endl; 
    
    if(getString() != ")")
    {
        //write the expression
        parseExpression();
        
        while(getString() == ",")
        {
            //write the symbol ","
            writeSymbol(getString());
            cur_idx_++;
            
            //write the expression
            parseExpression();
        }
    }
    
    //write the label "</expressionList>"
    xml_file_ofs_ << "</expressionList>" << endl;
    return;
}

void JackParser::writeKeyword(string s)
{
    xml_file_ofs_ << "<keyword> " << s  << " </keyword>" << endl;
    return;
}

void JackParser::writeSymbol(string s)
{
    
    if(s == "<")
    {
        xml_file_ofs_ << "<symbol> &lt; </symbol>" << endl;
    }
    else if(s == ">")
    {
        xml_file_ofs_ << "<symbol> &gt; </symbol>" << endl;
    }
    else if(s == "\"")
    {
        xml_file_ofs_ << "<symbol> &quot; </symbol>" << endl;
    }
    else if(s == "&")
    {
        xml_file_ofs_ << "<symbol> &amp; </symbol>" << endl;
    }
    else
    {
        xml_file_ofs_ << "<symbol> " << s  << " </symbol>" << endl;
    }
    return;
}

void JackParser::writeIntegerConstant(string s)
{
    xml_file_ofs_ << "<integerConstant> " << s  << " </integerConstant>" << endl;
    return;
}

void JackParser::writeStringConstant(string s)
{
    xml_file_ofs_ << "<stringConstant> " << s  << " </stringConstant>" << endl;
    return;
}

void JackParser::writeIdentifier(string s)
{
    xml_file_ofs_ << "<identifier> " << s  << " </identifier>" << endl;
    return;
}

void JackParser::writeType()
{
    if(isKeyword()) //void, int, char, or boolean
    {
        writeKeyword(getString());
    }
    else //className, getClassification() == "identifier"
    {
        writeIdentifier(getString());
    }
}

bool JackParser::isKeyword()
{
    return (getClassification() == "keyword");
}

string JackParser::getClassification()
{
    return tokens_vv_[cur_idx_][0];
}

string JackParser::getString()
{
    return tokens_vv_[cur_idx_][1];
}