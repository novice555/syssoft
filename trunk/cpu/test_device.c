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
int test_device(int device_id)
{
    
    if(device_id==0x04)
    {
        if(device_input != NULL)
        {
            return 0b100;
        }
        else
            return 0b001;
    }
    else if(device_id==0x05)
    {
        if(device_output != NULL)
            return 0b100;
        else
            return 0b001;
    }
    else if(device_id==0xF0)
    {
        if(device_loader != NULL)
            return 0b100;
        else
            return 0b001;
    }
    else if(device_id==0xF1)
    {
        if(device_assambler != NULL)
            return 0b100;
        else
            return 0b001;
    }
    else
        return 0b001;
}
