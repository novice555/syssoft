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
int file_device_init(int device_id)
{
    if(device_id==0xF1)
    {
        fclose(device_input);
        if((device_input = fopen("out.obj","r+"))!=NULL)
        {
            return 0b100;
        }
        else
            return 0b001;
    }
    else if(device_id==0x05)
    {
        fclose(device_output);
        if((device_output = fopen("write_device.txt","r+"))!=NULL)
            return 0b100;
        else
            return 0b001;
    }
    else
        return 0b001;
}

