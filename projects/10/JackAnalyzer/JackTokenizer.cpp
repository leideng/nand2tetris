#include "JackTokenizer.h"
#include <fstream> 
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::cout;
using std::endl;

JackTokenizer::JackTokenizer(const string& jack_file, const string& xml_file, const string& txt_file)
{
    jack_file_ = jack_file;
    xml_file_ = xml_file;
    txt_file_ = txt_file;
    
    //construct the hash table of 19 symbols
    symbols_['{']=true;
    symbols_['}']=true;
    symbols_['(']=true;
    symbols_[')']=true;
    symbols_['[']=true;
    symbols_[']']=true;
    symbols_['.']=true;
    symbols_[',']=true; 
    symbols_[';']=true;
    symbols_['+']=true;
    symbols_['-']=true;
    symbols_['*']=true;
    symbols_['/']=true;
    symbols_['&']=true;
    symbols_['|']=true;
    symbols_['<']=true;
    symbols_['>']=true;
    symbols_['=']=true;
    symbols_['~']=true;
    
    //construct the hash table of 21 keywords
    keywords_["class"]=true;
    keywords_["constructor"]=true;    
    keywords_["function"]=true;
    keywords_["method"]=true;    
    keywords_["field"]=true;
    keywords_["static"]=true;    
    keywords_["var"]=true;
    keywords_["int"]=true;    
    keywords_["char"]=true;
    keywords_["boolean"]=true;    
    keywords_["void"]=true;
    keywords_["true"]=true;    
    keywords_["false"]=true;
    keywords_["null"]=true;    
    keywords_["this"]=true;
    keywords_["let"]=true;
    keywords_["do"]=true;    
    keywords_["if"]=true;
    keywords_["else"]=true;    
    keywords_["while"]=true;
    keywords_["return"]=true;      
} 


void JackTokenizer::run()
{
    //open the input jack file
    ifstream ifs(jack_file_.c_str());
    if(!ifs.good())
    {
        cout << "cannot open the input jack file: " << jack_file_ << endl;
        exit(-1);
    }
    
    //open the output xml/txt file
    ofstream ofs_xml(xml_file_.c_str());
    ofstream ofs_txt(txt_file_.c_str());
    
    ofs_xml << "<tokens>" << endl;
    
    string buffer;
    bool isBlockComment = false; //the last line belongs to  a block comment, i.e., "/*" 
    while(std::getline(ifs, buffer))
    {
        /***************** first handle comments from the perspective of the whole line *******************/
        
        //cout << "get line: " << buffer << endl;
        
        //handle the end of block comment first
        if(isBlockComment) //the last line belongs to a block comment 
        {
            int blockCommentEndPos = getBlockCommentEndPosition(buffer);
            if(blockCommentEndPos != -1) //found the end of the block comment
            {
                buffer.erase(0, blockCommentEndPos+1);
                isBlockComment = false;
            }
            else
            {
                continue; //completely ignore this line
            } 
        }
       
        //handle the line comment of the remaining line (after removing the comments until the end of a block comment)
        int lineCommentPos = getLineCommentStartPosition(buffer);
        if(lineCommentPos != -1) //found line comment
        {
            buffer.erase(lineCommentPos); //remove the line comment
        }

        //handle the block comment of the remaining line (after removing the comments until the end of a block comment and the line comment)
        int blockCommentStartPos = getBlockCommentStartPosition(buffer);
        if(blockCommentStartPos != -1) //found the begnning of a block comment
        {
            //we need to see whether the end bock comment shows in this line
            int blockCommentEndPos = getBlockCommentEndPosition(buffer);
            if(blockCommentEndPos != -1) //found the end of the block comment
            {
                isBlockComment = false;
            }
            else
            {
                isBlockComment = true;
            }
            
            buffer.erase(blockCommentStartPos);
            
        }
        else
        {
            isBlockComment = false;
        }

 
        
        /*****then handle non-commented elements from the perspective of each single word (separated by white spaces) ********/
        int start_pos = 0;
        string word;
        for(size_t i=0; i < buffer.size(); ++i)
        {
            if(isspace(buffer[i])) //a white space
            {
                word = buffer.substr(start_pos, i-start_pos); 
                processSingleWord(word, ofs_xml, ofs_txt);
                start_pos = i+1;
            }
            else if(symbols_.find(buffer[i]) != symbols_.end()) //not white space, but a symbol letter
            {
               // cout << "find symbol: " << buffer[i] << endl;
                word = buffer.substr(start_pos, i-start_pos); 
                processSingleWord(word, ofs_xml, ofs_txt);
                processSingleSymbol(buffer[i], ofs_xml, ofs_txt);
                start_pos = i+1;
                
            }
            else if(buffer[i] == '"') //we need to handle string constant specially
            {
                
                //let us find another double quote '"'
                size_t found = buffer.find('"', i+1);                     
                if(found != string::npos)
                {
                    ofs_xml << "<stringConstant> " << buffer.substr(i+1,found-i-1) << " </stringConstant>" << endl;
                    ofs_txt << "stringConstant " << buffer.substr(i+1,found-i-1) << endl;
                    i=found;
                    start_pos=found+1;
                }
                else
                {
                    cout << "cannot find another double quote \"" << endl;
                    exit(-1);
                }                  
            }
            else //not a white space, and not a symbol letter, and not double quote
            {
                //do nothing
            }
        }
    }
    
    ofs_xml << "</tokens>" << endl;
}


int JackTokenizer::getLineCommentStartPosition(const string& code)
{
    int result = -1;
    
    for(int i=0; i+1 < code.size(); ++i)
    {
        if(code[i] == '/' && code[i+1] == '/')
        {
            result = i;
            break;
        }
    }
    
    return result;
}


int JackTokenizer::getBlockCommentStartPosition(const string& code)
{
    int result = -1;
    
    for(int i=0; i+1 < code.size(); ++i)
    {
        if(code[i] == '/' && code[i+1] == '*')
        {
            result = i;
            break;
        }
    }
    
    return result;
}


int JackTokenizer::getBlockCommentEndPosition(const string& code)
{
    int result = -1;
    
    for(int i=0; i+1 < code.size(); ++i)
    {
        if(code[i] == '*' && code[i+1] == '/')
        {
            result = i+1;
            break;
        }
    }
    
    return result;
}

void JackTokenizer::processSingleWord(const string& word, ofstream& ofs_xml, ofstream& ofs_txt)
{
    if(word.empty())
    {
        return;
    }
    
    if(keywords_.find(word) != keywords_.end()) //is a keyword
    {
        ofs_xml << "<keyword> " << word << " </keyword>" << endl;
        ofs_txt << "keyword " << word << endl;
        return;
    }
    
    
    //not a keyword, judge if it is an integer
    bool isInt = true;
    for(int i=0; i < word.size(); ++i)
    {
        if(!isdigit(word[i]))
        {
            isInt = false;
            break;
        }
    }
    
    if(isInt)
    {
        ofs_xml << "<integerConstant> " << word << "</integerConstant>" << endl;
        ofs_txt << "integerConstant " << word << endl;
        return;
    }
    
    //must be an identifier
    ofs_xml << "<identifier> " << word << " </identifier>" << endl;
    ofs_txt << "identifier " << word << endl;
    return;
}

void JackTokenizer::processSingleSymbol(char symbol, ofstream& ofs_xml, ofstream& ofs_txt)
{
    switch(symbol)
    {
        case '<':
            ofs_xml << "<symbol> &lt; </symbol>" << endl;
            break;
        case '>':
            ofs_xml << "<symbol> &gt; </symbol>" << endl;
            break;
        case '"':
            ofs_xml << "<symbol> &quot; </symbol>" << endl;
            break;
        case '&':
            ofs_xml << "<symbol> &amp; </symbol>" << endl;
            break;
        default:
            ofs_xml << "<symbol> " << symbol << " </symbol>" << endl;
    }
    
    ofs_txt << "symbol " << symbol << endl;
}