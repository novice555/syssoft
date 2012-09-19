#include<stdio.h>
#include<string.h>
#include"assambler.h"
void add_symboltable(char *sym, int address)
{
    strcpy(SymbolTable[N_Symbol].name, sym);
    SymbolTable[N_Symbol].value = address;
    N_Symbol++;
}
