#ifndef JACK_PARSER_H
#define JACK_PARSER_H

#include<string>


using std::string;

class JackParser
{
    public:
    
    JackParser(const string& txt_token_file, const string& xml_file);
    
    private:
    
    ///the input text token file, with the format <classification string\n>
    string txt_token_file_;
    
    ///the output xml file 
    string xml_file_;
};

#endif