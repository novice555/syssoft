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
        strcpy(list[N_Instruction].Mnemonic, token);
        token = strtok(NULL, delimiter);
        if(token!=NULL)
        {
            strcpy(list[N_Instruction].Parameter, token);  
        //printf("%s\t",token);
        }
        else
        {
                //printf("%s\t",token);
            strcpy(list[N_Instruction].Parameter,"");
                // printf("1%s\t",str2); 
        }
    }
    else
    {
        token = strtok(line,delimiter);
        strcpy(list[N_Instruction].Symbol, token);
        token = strtok(NULL, delimiter);
        strcpy(list[N_Instruction].Mnemonic, token);                
        token = strtok(NULL, delimiter);
        if(token!=NULL)
            strcpy(list[N_Instruction].Parameter, token); 
        else
            strcpy(list[N_Instruction].Parameter, "");
    }
    list[N_Instruction].Address = curr_address;
    N_Instruction++;
    return 0;
}
