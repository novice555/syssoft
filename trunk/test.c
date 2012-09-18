#include<stdio.h>
int main()
{
    FILE *fp;
    char buffer[100];
    int count = 0;
    fp = fopen("Input.txt","r");
    while(!feof(fp))
    {
        if(fgets(buffer,100,fp) != NULL)
            printf("%s",buffer);
        count++;
    }
    printf("%d\n",count);
}
