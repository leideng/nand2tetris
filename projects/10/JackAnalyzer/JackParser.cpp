#include "JackTokenizer.h"
#include "JackParser.h"


JackParser::JackParser(const string& txt_token_file, const string& xml_file)
{
    txt_token_file_ = txt_token_file;
    xml_file_ = xml_file;
}