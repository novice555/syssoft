#include<stdio.h>
#include"cpu.h"
void execute(void)
{
    long long tmp;
    int cmp;
    switch(opcode)
    {
        //add
        case 0x18:
            ra += load_mem(&memory[path],3);
            break;
        //and
        case 0x40:
            ra &= load_mem(&memory[path],3);
            break;
        //comp
        // = -> 0b001
        // > -> 0b010
        // < -> 0b100
        // save status in register sw
        case 0x28:
            cmp = load_mem(&memory[path],3);
            if(ra==cmp)
                rsw = 0x1;
            else if (ra>cmp)
                rsw = 0x2;
            else if (ra<cmp)
                rsw = 0x4;
            else
                rsw = 0;
            break;
        //div
        case 0x24:
            ra /= load_mem(&memory[path],3);
            break;
        //j
        case 0x3C:
            rpc = path;
            break;
        //jeq
        case 0x30:
            if(rsw==0x1)
                rpc = path;
            break;
        //jgt
        case 0x34:
            if(rsw==0x2)
                rpc = path;
            break;
        //jlt
        case 0x38:
            if(rsw==0x4)
                rpc = path;
            break;
        //jsub
        case 0x48:
            rl = rpc;
            rpc = path;
            break;
        //lda
        case 0x00:
            ra = load_mem(&memory[path],3);
            break;
        //ldch
        case 0x50:
            ra = (ra&0xFFFF00) + load_mem(&memory[path], 1);
            break;
        //ldl
        case 0x08:
            rl = load_mem(&memory[path],3);
            break;
        //ldx
        case 0x04:
            rx = load_mem(&memory[path],3);
            break;
        //mul
        case 0x20:
            tmp = (long long) ra * load_mem(&memory[path],3);
            ra = (int) (0xFFFFFF & tmp);
            break;
        //or
        case 0x44:
            ra |= load_mem(&memory[path],3);
            break;
        //rsub
        case 0x4C:
            rpc = rl;
            break;
        //sta
        case 0x0C:
            //incomplete
            save_mem(ra, &memory[path], 3);
            break;
        //stch
        case 0x54:
            save_mem(ra, &memory[path], 1);
            break;
        //stl
        case 0x14:
            save_mem(rl, &memory[path], 3);
            break;
        //stsw
        case 0xE8:
            save_mem(rsw, &memory[path], 3);
            break;
        //stx
        case 0x10:
            save_mem(rx, &memory[path], 3);
            break;
        //sub
        case 0x1C:
            ra -= load_mem(&memory[path], 3);
            break;
        //tix
        case 0x2C:         
            cmp = load_mem(&memory[path],3);
            rx++;
            if(rx==cmp)
                rsw = 0x1;
            else if (rx>cmp)
                rsw = 0x2;
            else if (rx<cmp)
                rsw = 0x4;
            else
                rsw = 0;
            break;

        //td
        case 0xE0:
            rsw = file_device_init(memory[path]);
            break;
        //rd
        case 0xD8:
            ra = (ra&0xFFFF00) + read_device(memory[path]);
            break;
        //wd
        case 0xDC:
            write_device(memory[path], (ra&0x0000FF));
            break;
        default: 
            printf("CPU Error: Could not found opcode\n");
            break;
    }
}
