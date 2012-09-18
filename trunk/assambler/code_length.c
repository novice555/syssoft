#include<stdio.h>
#include<string.h>
#include"assambler.h"

int search_mnemonic(char *opcode, char *operand)
{
    dict OpcodeTable[MAX_OPCODE] = {
                                {"ADD", 0x18},  
                                {"AND", 0x40},
                                {"COMP", 0x28},
                                {"DIV", 0x24},
                                {"J", 0x3C},
                                {"JEQ", 0x30},
                                {"JGT", 0x34},
                                {"JLT", 0x38},
                                {"JSUB", 0x48},
                                {"LDA", 0x00},
                                {"LDCH", 0x50},
                                {"LDL", 0x08},
                                {"LDX", 0x04},
                                {"MUL", 0x20},
                                {"OR", 0x44},
                                {"RD", 0xD8},
                                {"RSUB", 0x4C},
                                {"STA", 0x0C},
                                {"STCH", 0x54},
                                {"STL", 0x14},
                                {"STSW", 0xE8},
                                {"STX", 0x10},
                                {"SUB", 0x1C},
                                {"TD", 0xE0},
                                {"TIX", 0x2C},
                                {"WD", 0xDC}
                             
    };
    int i;
    int opcode_count = MAX_OPCODE;
 //   printf("%s\n",list[instruction_count-1].Mnemonic);
    for(i=0; i<opcode_count; i++)
    {
        //printf("%s\n",OpcodeTable[i].name);
        if(strcmp(opcode,OpcodeTable[i].name)==0)
            return 3;
    }
    if(strcmp(opcode, "WORD")==0)
        return 3;
    else if(strcmp(opcode, "RESW")==0)
        return 3 * StrToInt(operand);
    else if(strcmp(opcode, "RESB")==0)
        return StrToInt(operand);
    else if(strcmp(opcode, "BYTE")==0)
    {
        if(operand[0]=='X' && operand[1]=='\'')
            return (strlen(operand)-3)/2;
        else if(operand[0]=='C' && operand[1]=='\'')
            return strlen(operand)/2;
        else
        {
            printf("1231241\n");
            return 0;
        }
    }
    else
    {
        printf("aaabbbbbbb\n");
        return 0;
    }
}
