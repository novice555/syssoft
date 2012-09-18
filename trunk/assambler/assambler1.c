/*
* asssambler_passone
* return 0 : success
* return 1 : Error: syntax error
* return 2 : Error: START is not first of programs
* return 3 : Error: Cannot find END
* return 4 : Error: Duplicated Symbol
* return 5 : Error: Mnemonic not found
*
* check syntax:
* blank line, comment line
* fix BYTE format C'blah..3' X'F..F'
*/
#include <stdio.h>
#include <string.h>
#define MaxArray 100
#define Maxlength 100
int file_readline(FILE *fp,char buffer[]); //read file
//void initdel(char delimiter[Maxlength]);//init del

char Symbol[MaxArray][Maxlength];
char Mnemonic[MaxArray][Maxlength];
char Parameter[MaxArray][Maxlength];
int TempAddress[MaxArray]={0};
char delimiter[] = " \t\n\0";
int instruction_count = 0;

assambly list[MaxArray];
dict SymbolTable[MaxArray];



int opcode_count = 26;
int symbol_count = 0;
char ProgramName[Maxlength];
int StartAddress=0;

int StrToInt(char number[Maxlength]);
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

int assambler_passone(void)
{
    char line_buffer[Maxlength];
    FILE *fptr;
    char Text[MaxArray][Maxlength];
    int RunAddress 0;
    
    
    int a,i=0,nline,j=0, inst_length;
    int count=0;
//    int check=0;// check that,Has line had Symbol
    fptr = fopen("Input.txt","r");
    //nline = file_readline(fp,Text); //read file

    /* //check code
    for(i=0;i<nline;i++)
    printf("%s\n",Text[i]);*/
    //------------------------------------------Symbol Table
    //printf("%d\n", nline);
    //va new program
    file_readline(fptr, line_buffer);
    //str1 = strtok(line_buffer, delimiter);
    //str2 = strtok(NULL, delimiter);
    split_assambly(line_buffer);
    if (strcmp(Mnemonic[0],"START")==0):
    {
    
        strcpy(ProgramName,Symbol[0]);
        StartAddress = StrToInt(Parameter[0]);
        RunAddress = StartAddress;
     
    //    strcpy(Symbol[instruction_count], ProgramName);
    //    str2 = strtok(NULL,delimiter);
        
    }
    else
        return 2;
        
    while(file_readline(fptr, line_buffer))
    {
        split_assambly(line_buffer);   
        //check duplicate symbol
        if((Symbol[instruction_count], "")!=0)
        {
            if(is_symboltable(Symbol[instruction_count]))
                return 4;
            else
                //add symbol to symboltable
                add_symboltable(Symbol[instruction_count], RunAdress);
        }
        //check mnemonic
        inst_length = search_mnemonic(Mnemonic[instruction_count], Parameter[instruction_count])
        if(inst_length==0)
            return 5;
        else
            RunAddress += inst_length;
    }

    for(j=0;j<instruction_count;j++)
        printf("%d\t%s\t%s\t%s\t%d\t\n",j,Symbol[j],Mnemonic[j],Parameter[j],TempAddress[j]);
    return 0;

}
int add_symboltable(char *sym, int address)
{
    strcpy(SymbolTable[symbol_count].name, sym);
    SymbolTable[symbol_count].value = address
    symbol_count++;
}

int is_symboltable(char *sym)
{
    int i;
    for(i=0; i<symbol_count; i++)
        if(strcmp(sym,SymbolTable[i]==0))
            return 1;
    return 0;
}

int search_mnemonic(char *opcode, char *operand)
{
    int i;
    for(i=0; i<opcode_count; i++)
        if(strcmp(opcode,OpcodeTable[i])==0)
            return 3;
    if(strcmp(opcode, "WORD")==0)
        return 3;
    else if(strcmp(opcode, "RESW")==0)
        return 3 * StrToInt(operand);
    else if(strcmp(opcode, "RESB")==0)
        return StrToInt(operand);
    else if(strcmp(opcode, "BYTE")==0)
        if(operand[0]=='X')
            return (strlen(operand)-3)/2;
        else if(operand[0]=='C')
            return strlen(operand)/2;
        else
            return 0;
    else
        return 0;
}



int split_assambly(char *line)
{
    char *token;
    //tmp
    if(line[0]==' ' || line[0]=='\t')
    {
        token = strtok(line,delimiter);
        strcpy(Mnemonic[instruction_count],token);
        token = strtok(NULL, delimiter);
        if(token!=NULL)
        {
            strcpy(Parameter[instruction_count],token);  
        //printf("%s\t",token);
        }
        else
        {
                //printf("%s\t",token);
            strcpy(Parameter[instruction_count],"");
                // printf("1%s\t",str2); 
        }
    }
    else
    {
        token = strtok(line,delimiter);
        strcpy(Symbol[instruction_count], token);
        token = strtok(NULL, delimiter);
        strcpy(Mnemonic[instruction_count], token);                
        token = strtok(NULL, delimiter);
        if(token!=NULL)
            strcpy(Parameter[instruction_count], token); 
        else
            strcpy(Parameter[instruction_count], "");
    }
    instruction_count++;
    return 0;
}



int file_readline(FILE *fp, char buffer[]) //read file
{
    if(fgets(buffer,Maxlength,fp)!=NULL)
    {
    //    if(Text[nline]=="")
    //        continue;
    //    ++nline;  
        if(is_blank_or_comment(buffer))
            return (file_readline(fp, buffer));
        return 1;
    }
    else
        return 0;
}
/*
int is_blank_line(char *pstr)
{
    int i;
    int len = strlen(pstr);
    for(i=0; i<len; i++)
        if(pstr[i]!=' ')
            return 1;
    else
        return 0;
}
*/
int is_blank_or_comment(char *pstr)
{
    int i, check = 1;
    int len = strlen(pstr);
    for(i=0; i<len; i++)
    {
        if(pstr[i]=='.')
            return 1;
        else if(pstr[i]!=' '&&pstr[i]!='\t'&&pstr[i]!='\0'&&pstr[i]!='\n')
            return 0;
    }
    return 1;
}
/*
void initdel(char delimiter[Maxlength])
{
    delimiter[0]='\t';
    delimiter[1]=' ';
    delimiter[2]='\n';
    delimiter[3]='\0';
}
*/
int StrToInt(char *str2)
{
    int sum=0,i,tmp=1, base, t;
    if(str2[strlen(str2)-1]=='H')
    {
        base = 16;
        t = 2;
    }
    else
    {
        base = 10;
        t = 1;
    }
    for(i=strlen(str2)-t; i>-1; i--,tmp*=base)
        sum+=(int)(str2[i]-'0')*tmp;
    return sum;
}
