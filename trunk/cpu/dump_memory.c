#include<stdio.h>
#include"cpu.h"
int savememory(void)
{
    FILE *dumpfile;
    int i;
    dumpfile = fopen("memdump.txt","w");
    if(dumpfile!=NULL)
    {
        for(i=0; i<MAX_ADDRESS; i+=3)
        {
            fprintf(dumpfile,"%02X %02X %02X\n", memory[i], memory[i+1], memory[i+2]);
        }
        fclose(dumpfile);
    }
    else
        printf("Cannot write \"memdump.txt\"\n");
}
