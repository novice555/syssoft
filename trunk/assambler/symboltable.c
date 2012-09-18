#include<stdio.h>
#include<string.h>
#include"assambler.h"
void add_symboltable(char *sym, int address)
{
    strcpy(SymbolTable[symbol_count].name, sym);
    SymbolTable[symbol_count].value = address;
    symbol_count++;
}
