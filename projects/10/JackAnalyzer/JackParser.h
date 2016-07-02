#ifndef JACK_PARSER_H
#define JACK_PARSER_H

#include<string>
#include<vector>
#include<fstream>

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

class JackParser
{
    public:
    
    JackParser(const string& txt_token_file, const string& xml_file);
    
    ///the main function to parse the input file into the output file
    void run();
    
    ///parse the whole class
    void parseClass();
    
    ///parse class variable declaration 
    void parseClassVarDec();
    
    ///parse class subroutine  
    void parseSubroutineDec();
    
    ///parse parameter list
    void parseParameterList();
    
    ///parse subroutine body
    void parseSubroutineBody();
    
    ///parse variable declaration inside a subroutine
    void parseVarDec();
    
    ///parse statement sequence
    void parseStatements();
    
    ///parse let statement
    void parseLetStatement();
    
    ///parse if statement
    void parseIfStatement();
    
    ///parse while statement
    void parseWhileStatement();
        
    ///parse do statement
    void parseDoStatement();
    
    ///parse return statement
    void parseReturnStatement();
    
    ///parse subroutine call
    void parseSubroutineCall();
    
    ///parse expression
    void parseExpression();
    
    ///parse a term in a expression
    void parseTerm();
    
    ///parse expression list
    void parseExpressionList();
   
    ///write keyword terminal element 
    void writeKeyword(string s);
    
    ///write symbol terminal element
    void writeSymbol(string s);
    
    ///write integerConstant terminal element
    void writeIntegerConstant(string s);
    
    ///write stringConstant terminal element
    void writeStringConstant(string s);
    
    ///write identifier terminal element
    void writeIdentifier(string s);
    
    ///write type element of the current token
    ///type: int | char | boolean | className
    ///We do not update cur_idx_ inside this function.
    void writeType();
    
    ///return true if the current token is a keyword
    bool isKeyword();
    
    ///get the classification of the current token
    ///Classification: keyword, symbol, integerConstant, stringConstant, identifier
    string getClassification();
    
    ///get the string of the current token
    string getString();
    
    private:
    ///the input text token file, with the format <classification string\n>
    string txt_token_file_;
    
    ///the output xml file 
    string xml_file_;
    
    ///the ofstream of the output xml file;
    ofstream xml_file_ofs_;
    
    ///we read the input txt_token_file_ into memory and store it as a vector of a string vector
    vector< vector<string> > tokens_vv_;
    
    ///the index of the current token to be parsed
    int cur_idx_;
};

#endif