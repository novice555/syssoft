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
        target[0] = (0xFF0000 & value) >>16;
        target[1] = (0x00FF00 & value) >>8;
        target[2] = (0x0000FF & value);
    }
    else if(mode==1)
        target[0] = (0x0000FF & value);
}

