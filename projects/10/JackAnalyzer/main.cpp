#include "JackTokenizer.h"
#include "JackParser.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        cout << "Usage: " << argv[0] << " <a.jack> <b.jack> <c.jack> ..." << endl;
        return -1;
    }
    
    for(int i=1; i<argc; ++i)
    {
        string jack_file(argv[i]);
        
        //the xml file after tokenizing
        string xml_token_file = jack_file.substr(0, jack_file.size()-5) + "T.xml";
        
        //the text file after tokenizing, with the format <classification string\n>, e.g.
        // keyword if
        // symbol (
        // integerConstant 153
        // etc..
        string txt_token_file = jack_file.substr(0, jack_file.size()-5) + "T.txt";
        
        JackTokenizer tokenizer(jack_file, xml_token_file, txt_token_file);
        //run to tokenize the jack file and store the results into the xml file
        tokenizer.run();
        
        //the xml file after tokenizing and parsing
        string xml_parser_file = jack_file.substr(0, jack_file.size()-5) + ".xml";
        
        JackParser parser(txt_token_file, xml_parser_file);
        
        parser.run();
    }
    return 0;
}