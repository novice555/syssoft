/*
* asssambler_passone
* return 0 : success
* return 1 : Error: syntax error
* return 2 : Error: START is not first of programs
* return 3 : Error: Cannot find END
* return 4 : Error: Duplicated Symbol
* return 5 : Error: Mnemonic not found
* return 6 : Error: Cannot Open file
* return 7 : Error: Parameter Not Correct Format //not finish
* return 8 : Error: Load Address is lower than 0x1000
* check syntax:
* blank line, comment line
* fix BYTE format C'blah..3' X'F..F'
*/
#include<stdio.h>
#include<string.h>
#include"assambler.h"

int StrToInt(char *number);
int open_file(char *name);
int file_readline(char *buffer);
int is_blank_or_comment(char *pstr);
int is_symboltable(char *sym);
int split_assambly(char *line, int curr_address);
int StrToInt(char *str2);
int search_mnemonic(char *opcode, char *operand);
void add_symboltable(char *sym, int address);

assambly list[MaxArray];
dict SymbolTable[MaxArray];
int N_Instruction = 0;
int N_Symbol = 0;
char ProgramName[Maxlength];
int ProgramLength;
FILE *fptr = NULL;

int assambler_passone(char *asm_name)
{
    int StartAddress, inst_length;
    char line_buffer[Maxlength*3] = "";
    int RunAddress = 0;
    //open file
    //if(!open_file(asm_name))
    //    return 6;
    fptr = fopen(asm_name,"r");
    if(fptr==NULL)
        return 6;
    file_readline(line_buffer);
    split_assambly(line_buffer, 0);
    if (strcmp(list[0].Mnemonic, "START")==0)
    {
    
        strcpy(ProgramName, list[0].Symbol);
        StartAddress = StrToInt(list[0].Parameter);
        RunAddress = StartAddress;
        list[0].Address = StartAddress;
    //    if(StartAddress<0x1000)
    //        return 8;
        
    }
    else
        return 2;
        
    while(file_readline(line_buffer))
    {
        //printf("%s",line_buffer);
        split_assambly(line_buffer, RunAddress);
        if(strcmp(list[N_Instruction-1].Mnemonic,"END")==0)
            break;

        //check duplicate symbol
        if(strcmp(list[N_Instruction-1].Symbol, "")!=0)
        {
            if(is_symboltable(list[N_Instruction-1].Symbol))
                return 4;
            else
                //add symbol to symboltable
                add_symboltable(list[N_Instruction-1].Symbol, RunAddress);
        }
        //check mnemonic
 //       printf("%d\n",N_Instruction);
        inst_length = search_mnemonic(list[N_Instruction-1].Mnemonic, list[N_Instruction-1].Parameter);
        if(inst_length==0)
            return 5;
        else
            RunAddress += inst_length;
    }
    if(strcmp(list[N_Instruction-1].Mnemonic, "END")!=0)
        return 3;

    ProgramLength = StrToInt(list[N_Instruction-1].Parameter) - StrToInt(list[0].Parameter);
    int j;
    printf("-------- to PassII -------\n");
    for(j=0; j<N_Instruction; j++)
        printf("%d\t%s\t%s\t%s\t%04X\t\n",j+1,list[j].Symbol,list[j].Mnemonic, list[j].Parameter, list[j].Address);
    //printf("%d\n", N_Instruction);
    printf("-------- Symbol Table --------\n");
    for(j=0; j<N_Symbol; j++)
        printf("%s\t%X\t\n", SymbolTable[j].name, SymbolTable[j].value);
    printf("Instruction Count: %d Symbol Count: %d\n",N_Instruction,N_Symbol);
        
    return 0;

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

