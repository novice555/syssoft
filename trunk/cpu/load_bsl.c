#include<stdio.h>
#include"cpu.h"
#include<string.h>
#include<stdlib.h>
FILE *fp;
int load_bsl(void)
{
    char buffer[10000];
    char *pEnd;
    char *pStart;
    char base16[3];
    int x, entry, i, len, tmp, count;
    fp = fopen("bsl.mac","r");
    fscanf(fp,"%s", buffer);
    x = strtol(buffer,&pEnd,16);
    fscanf(fp,"%s", buffer);
    entry = strtol(buffer, &pEnd,16);
    printf("%X\n",entry);
    fscanf(fp,"%s", buffer);
    len = strlen(buffer);
    printf("length: string: %d program_length:%d\n", len, len/2);
//    printf("%s", buffer);
    count = 0;
    printf("");
    for(i=0;i<len;i+=2)
    {
//        pStart = &buffer[i];
//        pEnd = &buffer[i+1];
//        tmp = strtol(pStart, &pEnd, 16);
        base16[0] = buffer[i];
        base16[1] = buffer[i+1];
        base16[2] = '\0';
        pEnd = &base16[1];
        tmp = strtol(base16, &pEnd, 16);
        //printf("%X",tmp);
        memory[x+count] = tmp;
        count++;
    }
    rpc = entry;
}
