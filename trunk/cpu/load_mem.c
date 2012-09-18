/*
* CPU Function
* load from memory to register
* mode==3 : load 3 byte
* mode==1 : load 1 byte and replace at rightmost byte of register
*/
#include<stdio.h>
#include"cpu.h"
int load_mem(unsigned char *num, int mode)
{
    if(mode==3)
        return (num[0]<<16) + (num[1]<<8) + num[2];
    if(mode==1)
        return num[0];
    else
        return 0xFFFFFF;
}
