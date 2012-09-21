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
int init(void)
{
    device_input = fopen("input.txt","r+");
    device_output = fopen("output.txt","r+");
    device_loader = fopen("loader.mac","r+");
    device_assambler = fopen("code.o","r+");
    if(device_input==NULL )
        return 1;
    if(device_output==NULL) 
        return 2;
    if(device_loader==NULL) 
        return 3;
    if(device_assambler==NULL)
        return 4;
    return 0;
}

int deinit(void)
{
    fclose(device_input);
    fclose(device_output);
}

