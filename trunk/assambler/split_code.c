#include<stdio.h>
#include<string.h>
#include"assambler.h"
int split_assambly(char *line, int curr_address)
{
    char delimiter[] = " \t\n\0";
    char *token;
    //tmp
    if(line[0]==' ' || line[0]=='\t')
    {
        token = strtok(line, delimiter);
        strcpy(list[instruction_count].Mnemonic, token);
        token = strtok(NULL, delimiter);
        if(token!=NULL)
        {
            strcpy(list[instruction_count].Parameter, token);  
        //printf("%s\t",token);
        }
        else
        {
                //printf("%s\t",token);
            strcpy(list[instruction_count].Parameter,"");
                // printf("1%s\t",str2); 
        }
    }
    else
    {
        token = strtok(line,delimiter);
        strcpy(list[instruction_count].Symbol, token);
        token = strtok(NULL, delimiter);
        strcpy(list[instruction_count].Mnemonic, token);                
        token = strtok(NULL, delimiter);
        if(token!=NULL)
            strcpy(list[instruction_count].Parameter, token); 
        else
            strcpy(list[instruction_count].Parameter, "");
    }
    list[instruction_count].Address = curr_address;
    instruction_count++;
    return 0;
}
