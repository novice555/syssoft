#include<stdio.h>
#include<string.h>
#include"assambler.h"


int is_blank_or_comment(char *pstr)
{
    int i;
    int len = strlen(pstr);
    for(i=0; i<len; i++)
    {
        if(pstr[i]=='.')
            return 1;
        else if(pstr[i]!=' '&&pstr[i]!='\t'&&pstr[i]!='\0'&&pstr[i]!='\n')
            return 0;
    }
    return 1;
}
int is_symboltable(char *sym)
{
    int i;
    for(i=0; i<N_Symbol; i++)
        if(strcmp(sym, SymbolTable[i].name)==0)
            return 1;
    return 0;
}


