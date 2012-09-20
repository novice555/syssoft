/*
* cpu function
* open file for read/write
* F1: input_device
*    "out.obj"
*    for read data from device
* 05: output_device
*    "write_device.txt"
*    for write data to device
* **all device can read or write data**
* extern: device_input, device_output
*/  
#include<stdio.h>
#include"cpu.h"
int file_device_init(void)
{
    if((device_input = fopen("code.o","r+"))==NULL)
        return 1;
    if((device_output = fopen("output.txt","r+"))==NULL)
        return 1;
    return 0;
}

int file_device_close(void)
{
    fclose(device_input);
    fclose(device_output);
}

