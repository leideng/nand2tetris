#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;

class SymbolTable
{
    public:
    
    enum Kind
    {
        STATIC,
        FIELD,
        ARGUMENT,
        VAR
    };
    
    struct Entry
    {
        ///name of the identifier/symbol
        string name_;
        
        ///type of the symbol
        string type_;
        
        ///kind of the symbol
        Kind kind_;
        
        ///index of the symbols within its kind
        int index_;
    };
    
    SymbolTable();
    
    ///insert a symbol entry to the symbol table
    ///its index should be assigned automatically
    ///do nothing if the name already exists
    void insertEntry(const string& name,
                     const string& type,
                     Kind kind);
                    
    
    ///return true if the input name exists in the string table
    bool isExist(const string& name) const;
    
    ///get the type of the input name
    string getType(const string& name) const;    
    
    ///get the kind of the input name
    Kind getKind(const string& name) const;
   
    ///get the index of the input name
    int getIndex(const string& name) const;
    
    ///return the number of symbols of the input kind
    int kindCount(Kind kind) const;
    
    ///clear the symbol table
    void clear();
    
    private:
    
    ///the map of the symbol name and the entry in the symbol table 
    map<string, Entry> name_entry_m_;
    
    ///number of symbols of kind STATIC
    int n_static_;
    
    ///number of symbols of kind FIELD
    int n_field_;
    
    ///number of symbols of kind ARGUMENT
    int n_argument_;
    
    ///number of symbols of kind VAR
    int n_var_;
};

#endif