#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int to_machinecode()
{
    FILE *fr, *fw;
    char buffer[1000];
    fr = fopen("bsl.o","r");
    fw = fopen("bsl.w","w");
    fscanf(fr,"%s",buffer);
    
}
