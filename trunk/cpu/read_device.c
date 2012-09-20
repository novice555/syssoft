/*
* cpu function
* read 1 byte from file
* implement for read data from device for SIC
* F1: input_device
* 05: output_device
* see also test_device.c
* extern : device_input, device_output
*/
#include<stdio.h>
#include"cpu.h"
int read_device(int device_id)
{
    int c;
    if(device_id==0x04)
        c = fgetc(device_input);
    else if(device_id==0x05)
        c = fgetc(device_output);
    else if(device_id==0xF0)
        c = fgetc(device_loader);
    else if(device_id==0xF1)
        c = fgetc(device_assambler);
    if(c==EOF)
        return 4;
    else
        return c;
}

