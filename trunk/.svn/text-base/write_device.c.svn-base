/*
* cpu function
* implement for write data to device for SIC 
* F1: input_device
* 05: ouput_device
* see also test_device.c
* extern : device_input, device_output
*/
#include<stdio.h>
#include"cpu.h"
void write_device(int device_id, int c)
{
    if(device_id==0xF1)
        fputc(c, device_input);
    else if(device_id==0x05)
        fputc(c, device_output);
}

