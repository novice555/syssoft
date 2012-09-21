#include<stdio.h>
#include"cpu.h"
#define MAXLENGTH 1000
#define MAX_OPCODE 26
typedef struct {
    char name[MAXLENGTH];
    int value;
} dict;
int debug_mode(int mode)
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
    printf("-----------------------------------------------------------\n");
    printf("ra= %06X rx= %06X rl= %06X rpc= %06X rsw= %06X\n", ra, rx ,rl, rpc, rsw);
    printf("-----------------------------------------------------------\n");
    int i;
    char *inst_name;
    for(i=0;i<MAX_OPCODE; i++)
        if(OpcodeTable[i].value==opcode)
        {
            inst_name = OpcodeTable[i].name;
            break;
        }
    printf("instruction= %02X %02X %02X\n", memory[rpc-3], memory[rpc-2], memory[rpc-1]);
    printf("opcode name= %s\n", inst_name);
    printf("opcode= %02X xbit= %d address= %04X path= %04X\n", opcode, xbit, address, path);
    printf("memory[path] = %02X %02X %02X\n", memory[path], memory[path+1], memory[path+2]);

    static int stop1=0, count=0, debug_count=1;
    char buff_debug[20];
    if(rpc==0x48)
        stop1 = 1;
    if(count>=debug_count&&stop1)
    {
        scanf("%s",buff_debug);
        debug_count =(int) atol(buff_debug);
        if(buff_debug[0]=='e')
           count = -0xFFFFFF;
        else
           count = 1;
    }
    else
        count++;
    return 0;
}
