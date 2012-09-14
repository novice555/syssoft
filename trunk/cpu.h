/*
* cpu header
*/
#define DEBUG 1
#define MAX_ADDRESS 302768
#define MAX_DEVICE 4

/*===== extern section =====*/
//decode
extern int opcode, xbit, address, path;
//memory
extern unsigned char memory[];
//device data
extern FILE *device_input, *device_output;
//register
extern int ra, rx, rl, rpc, rsw;
//
