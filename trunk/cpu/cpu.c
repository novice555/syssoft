/*
// Limitation of SIC Simulator
// - read/write only 2 device
// Info
// - 0xF1 - Device for input
// - 0x05 - Device for output
*/

#include<stdio.h>
#include"cpu.h"
#include<stdlib.h>

/*function init*/
int cpu(void);
int debug_mode(int mode);
int load_bsl(void);
void fetch_decode(void);
int execute(void);
void savememory(void);
void register_overflow(void);
int init(void);
int test_device(int device_id);
int read_device(int device_id);
void write_device(int device_id, int c);
int load_mem(unsigned char *num, int mode);
void save_mem(int value, unsigned char *target, int mode);

/*variable init*/
/*
*   address : address from instruction
*   path : TA address
*/
unsigned char memory[MAX_ADDRESS] = {0};
int ra = 0, rx = 0, rl = 0, rpc = 0, rsw = 0;
int opcode = 0, xbit = 0, address = 0, path = 0;
FILE *device_input, *device_output, *device_loader, *device_assambler; 
int debug = 1;

int cpu(void)
{
    char buff_debug[20] = "", e = 0;
    char str[20000];
    int count, debug_count,check =  1;
    e = init();
 //   e = 1;
   // fscanf(device_loader,"%s",str);
   // printf("%s\n",str);
    if(e)
        return e;
    load_bsl();
    savememory();
    while(rpc<MAX_ADDRESS-1)
    {
        fetch_decode();
        rpc += 3;
        debug_mode(1);
        //if(rpc==0x7100)
        //    check = 1;
        if(execute())
        {
            savememory();
            return 5;
        }
        register_overflow();
    }
    //file_device_close();
    savememory();
    return 0;
}

void register_overflow(void)
{
    ra &= 0xFFFFFF;
    rx &= 0xFFFFFF;
    rl &= 0xFFFFFF;
    rpc &= 0xFFFFFF;
    rsw &= 0xFFFFFF;
}
