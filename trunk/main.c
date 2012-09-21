#include<stdio.h>
#include<string.h>
#include"assambler/assambler.h"
#include"cpu/cpu.h"
void inter_active(void);
int main(int argc, char *argv[])
{
    FILE *ft = fopen(argv[1],"r");
    if(ft==NULL){
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }
    int e;
    fclose(ft);
    e = assambler_passone(argv[1]);
    if(e){
        printf("Pass I Error: Line: %d Error Code %d\n", N_Instruction, e);
        return 1;
    }
    printf("\n------ PASS I Success ------\n\n");
    printf("Please press 1 to continue\n");
    inter_active();
    e = assambler_passtwo();
    if(e){
        printf("Pass II Error: Symbol is not found\n");
        return 1;
    }
    printf("\n------ PASS II Success ------\n\n");
    printf("Please press 1 to load and run cpu (by BSL and Loader)\n");
    inter_active();
    e = cpu();
    if(e){
        printf("CPU Error: Error %d\n", e);
        return 1;
    }
    printf("\n-------- Run Successful -------\n\n");
    printf("memmory dump into file \"memdump.txt\" please 1 to exit\n");
    inter_active();
    return 0;
}
void inter_active(void)
{
    char buffer[20];
    do {
        printf(": ");
        scanf("%s", buffer);
    } while(buffer[0]!='1');
}
