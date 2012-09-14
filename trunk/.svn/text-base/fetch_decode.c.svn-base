#include<stdio.h>
#include"cpu.h"
void fetch_decode(void)
{
    //memory[0] = 80;
    //memory[1] = 128;
    //memory[2] = 255;
    //fetch
    unsigned char* num = &memory[rpc];
    //decode
    opcode = num[0];
    if (num[1]&(1<<7))
        xbit = 1;
    else
        xbit = 0;

    /*
    if (memory[pc+1]>=128)
    {
        xbit = 1;
        num[1] -= 128;
    }
    else 
        xbit = 0;
    address = 0;
    do
    {
        //printf("%d,%d\n",two,num[1]%2);
        address += two*(num[1]%2);
        two *= 2;
        num[1] /= 2;
    }
    while(num[1]!=0);
    address += num[2];
    */
    
    address = ((num[1]&0x7F)<<8) + num[2];
    path = (xbit)?rx+address:address;
    path &= 0xFFF;      // over flow control
    //printf("%d\n%d\n%d\n",opcode,xbit,address);
    //printf("%d\n",memory[rpc+1]);
}
