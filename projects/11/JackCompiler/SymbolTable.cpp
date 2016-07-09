#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
    n_static_ = 0;
    n_field_ = 0;
    n_argument_ = 0;
    n_var_ = 0;
}

void SymbolTable::insertEntry(const string& name,
                              const string& type,
                              Kind kind)
{
    if(isExist(name))
    {
        return; //already exist, do nothing
    }
    
    int index;
    switch(kind)
    {
        case STATIC:
            index = n_static_;
            n_static_++;
            break;
        case FIELD:
            index = n_field_;
            n_field_++;
            break;   
        case ARGUMENT:
            index = n_argument_;
            n_argument_++;
            break;            
        case VAR:
            index = n_var_;
            n_var_++;       
    }
    
    Entry entry;
    entry.name_ = name;
    entry.type_ = type;
    entry.kind_ = kind;
    entry.index_ = index;

    name_entry_m_[name] = entry;
}

bool SymbolTable::isExist(const string& name) const
{
    return (name_entry_m_.find(name) != name_entry_m_.end());
}

string SymbolTable::getType(const string& name) const
{
    Entry entry = name_entry_m_.find(name)->second;
    return entry.type_;
}

SymbolTable::Kind SymbolTable::getKind(const string& name) const
{
    Entry entry = name_entry_m_.find(name)->second;
    return entry.kind_;
}

int SymbolTable::getIndex(const string& name) const
{
    Entry entry = name_entry_m_.find(name)->second;
    return entry.index_;
}

int SymbolTable::kindCount(Kind kind) const
{
    switch(kind)
    {
        case STATIC:
            return n_static_;
        case FIELD:
            return n_field_; 
        case ARGUMENT:
            return n_argument_;            
        case VAR:
            return n_var_;       
    }
    
    //fake return
    return 0;
}

void SymbolTable::clear()
{
    name_entry_m_.clear();
    n_static_ = 0;
    n_field_ = 0;
    n_argument_ = 0;
    n_var_ = 0;
    
}