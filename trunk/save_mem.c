/*
* CPU Function
* Save register to memory
* mode 1 : 
* mode 3 : value 24 bit to 3 byte memory
*/
#include<stdio.h>
#include"cpu.h"
void save_mem(int value, unsigned char *target, int mode)
{
    if(mode==3)
    {
        target[0] = (0x0000FF&value);
        target[1] = (0x0000FF&(value>>8));
        target[2] = (0x0000FF&(value>>16));
    }
    else if(mode==1)
        target[0] = (0x0000FF&value);
}

