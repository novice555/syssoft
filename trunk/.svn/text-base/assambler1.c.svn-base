#include <stdio.h>
#include <string.h>
#define MaxArray 100
#define Maxlength 100
int read(FILE *fp,char Text[MaxArray][Maxlength]); //read file
void initdel(char delet[Maxlength]);//init del
int ChNumber(char number[Maxlength]);
void ChString(int Address,char SAddress[MaxArray])
{
    char temp[MaxArray];
    int i=0,j=0,k;
    while(Address!=0)
    {
        temp[i]=(Address%10)+'0';
        Address/=10;
        i++;
    }
    k=i-1;
    for(j=0;j<i;j++,k--)
    {
        SAddress[j]=temp[k];
    }
}

int main(void)
{
    FILE *fp;
    char Text[MaxArray][Maxlength];
    char *str1,*str2;
    char delet[Maxlength];
    char Symbol[MaxArray][Maxlength];
    char Mnemonic[MaxArray][Maxlength];
    char Parameter[MaxArray][Maxlength];
    char SAddress[MaxArray];
    
    int TempAddress[MaxArray]={0};
    int a,i=0,nline,j=0;
    int count=0;
    int Address=0;
//    int check=0;// check that,Has line had Symbol
    fp = fopen("Input.txt","r");
    nline = read(fp,Text); //read file

    /* //check code
    for(i=0;i<nline;i++)
    printf("%s\n",Text[i]);*/
    initdel(delet);
    //------------------------------------------Symbol Table
    printf("%d\n", nline);
    for(i=0;i<nline;i++)
    {
 //       check=0;
        if(Text[i][0]==' '||Text[i][0]=='\t')
        {
            str1 = strtok(Text[i],delet);
            str2 = strtok(NULL, delet);
            if(str2==NULL)
            {
                //printf("%s\t",str1);
                strcpy(Mnemonic[i],str1);   
            }
            else
            {
                //printf("%s\t",str1);
                strcpy(Mnemonic[i],str1); 
                strcpy(Parameter[i],str2);  
                // printf("1%s\t",str2); 
            } 
        }
        else
        {
         
            str1 = strtok(Text[i],delet);
            strcpy(Symbol[i],str1);
            ++count;
            str1 = strtok(NULL, delet);
            // printf("%s\t",str1);
            strcpy(Mnemonic[i],str1);
            if(i==0)
            {
                    
                str1 = strtok(NULL, delet);
                //printf("%s\n",str1);
                Address = ChNumber(str1);
                TempAddress[0] = Address;
                   
            }
            else
            {
                
                str1 = strtok(NULL, delet);
                //printf("2%s\t",str1); 
                if(str1!=NULL)
                strcpy(Parameter[i],str1); 
            }
        }   

        for ( ;str1 != NULL;str1 = strtok(NULL, delet) )//splite
        {
  
            str2=str1;
            //printf("%d\t%s\n",i,str1);
        }
       
        if(i!=0)
        {
            TempAddress[i] = Address;  
            Address+=3;
        }
    }
    fclose(fp);
    for(j=0;j<nline;j++)
        printf("%d\t%s\t%s\t%s\t%d\t\n",j,Symbol[j],Mnemonic[j],Parameter[j],TempAddress[j]);
    
    //------------------------------------------Symbol Table
     
    return 0;
}

int read(FILE *fp,char Text[MaxArray][Maxlength]) //read file
{
    int nline=0;
    while(!feof(fp))
    {
        fgets(Text[nline],MaxArray,fp);
    //    if(Text[nline]=="")
    //        continue;
    //    ++nline;  
        if(blank_line(Text[nline]))
            nline++;
    }  
    return nline;
}
int blank_line(char *pstr)
{
    int i;
    for(i=0; i<strlen(pstr); i++)
        if(pstr[i]!=' ')
            return 1;
    else
        return 0;
}
void initdel(char delet[Maxlength])
{
    delet[0]='\t';
    delet[1]=' ';
    delet[2]='\n';
    delet[3]='\0';
}
int ChNumber(char *str2)
{
    int sum=0,i,ten=1;
    for(i=strlen(str2)-1;i>-1;i--,ten*=10)
    {
        sum+=(int)(str2[i]-'0')*ten;
    }  
    return sum;
}
