#include<stdio.h>
#include<string.h>
#include"assambler.h"
int StrToInt(char *str2)
{
    char *pEnd;
    if(str2[strlen(str2)-1]=='H')
    {
        pEnd = &str2[strlen(str2)-2];
        return (int) strtol(str2, &pEnd, 16);
    }
    else
    {
        pEnd = &str2[strlen(str2)-1];
        return (int) strtol(str2, &pEnd, 10);
    }
}

