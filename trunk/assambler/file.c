#include<stdio.h>
#include<string.h>
#include"assambler.h"

int open_file(char *name)
{
    fptr = fopen(name, "r");
    if(fptr==NULL)
        return 0;
    else
        return 1;
}

int file_readline(char *buffer)
{
    if(fgets(buffer, Maxlength*3, fptr)!=NULL)
    {
        if(is_blank_or_comment(buffer))
        {
            return (file_readline(buffer));
        }
        return 1;
    }
    else
        return 0;
}
