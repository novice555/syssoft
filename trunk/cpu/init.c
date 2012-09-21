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
    device_input = fopen("code.o","r+");
    device_output = fopen("output.txt","r+");
    device_loader = fopen("loader.mac","r+");
    device_assambler = fopen("code.o.mac","r+");
    if(device_input==NULL || device_output==NULL || device_loader==NULL|| device_assambler)
        return 1;
    else
        return 0;
}

int deinit(void)
{
    fclose(device_input);
    fclose(device_output);
}

