#ifndef JACK_TOKENIZER_H
#define JACK_TOKENIZER_H

#include <string> 
#include <map>
#include <fstream>

using std::string;
using std::map;
using std::ofstream;

class JackTokenizer
{
    public:
    
    enum TokenType
    {
        SYMBOL,
        KEYWORD,
        IDENTIFIER,
        INT_CONST,
        STRING_CONST
    };

    JackTokenizer(const string& jack_file, const string& xml_file, const string& txt_file);
    
    ///get the start position of the line comment, i.e., "//" of the input single-line code
    ///return -1 if not found
    /// Example:  code = "return; //return now"
    /// Then return 8, the position of the first '/'
    int getLineCommentStartPosition(const string& code);
    
    ///get the start position of the block comment, i.e., "/*" of the input single-line code
    ///return -1 if not found
    /// Example:  code = "return; /*return now*/"
    /// Then return 8, the position of the first '/'
    int getBlockCommentStartPosition(const string& code);
    
    ///get the end position of the block comment, i.e., "*/" of the input single-line code
    ///return -1 if not found
    /// Example:  code = "return; /*return now*/"
    /// Then return 21, the position of the second '/'
    int getBlockCommentEndPosition(const string& code);   
    
    ///process single word that is not a symble and does not contain white spaces, 
    ///write the result into both xml and txt file streams
    /// @note the input word cannot be string constant, which should be handled specially
    void processSingleWord(const string& word, ofstream& ofs_xml, ofstream& ofs_txt);

    ///process a single symbol 
    ///write the result into both xml and txt file streams
    void processSingleSymbol(char symbol, ofstream& ofs_xml, ofstream& ofs_txt);
    
   
    ///the main function to tokenize the input file into the output files
    void run();
    
    private:
    
    ///the input jack file
    string jack_file_;
    
    ///the output xml file
    string xml_file_;
    
    ///the output txt file with the format <classification string\n>
    ///Here classification is symbol, keyword, symbol, identifier, integerConstant, stringConstant
    ///This is easier to be handled by the parser than the xml file
    string txt_file_; 

    ///hash table for symbols
    map<char, bool> symbols_;

    ///hash table for keywords
    map<string, bool> keywords_;
};

#endif