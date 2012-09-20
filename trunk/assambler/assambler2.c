#include<stdio.h>
#include<string.h>
#include"assambler.h"
#include<ctype.h>
#include<stdlib.h>
//aassambly list[MaxArray];
//dict SymbolTable[MaxArray];
//int N_Instruction;
//int N_Symbol;
char Value_Object_Code[MaxArray][Maxlength];


void __Init__(){
	N_Instruction = 14;
	N_Symbol = 1;
	strcpy( SymbolTable[0].name, "BLAH" );
	SymbolTable[0].value = 4096;
	
	strcpy( list[0].Symbol, "COPY" );
	strcpy( list[0].Mnemonic, "START" );
	strcpy( list[0].Parameter, "1000H" );
	strcpy( list[1].Mnemonic, "WORD" );
	strcpy( list[1].Parameter, "-4096" );
	strcpy( list[2].Mnemonic, "WORD" );
	strcpy( list[2].Parameter, "4096" );
	strcpy( list[3].Mnemonic, "BYTE" );
	strcpy( list[3].Parameter, "X'F1'" );
	strcpy( list[4].Mnemonic, "BYTE" );
	strcpy( list[4].Parameter, "C'HELLO'" );
	strcpy( list[5].Mnemonic, "ADD" );
	strcpy( list[5].Parameter, "BLAH   , X" );
	strcpy( list[6].Mnemonic, "RESW" );
	strcpy( list[6].Parameter, "" );
	strcpy( list[7].Mnemonic, "WORD" );
	strcpy( list[7].Parameter, "-4096" );
	strcpy( list[8].Mnemonic, "WORD" );
	strcpy( list[8].Parameter, "4096" );
	strcpy( list[9].Mnemonic, "BYTE" );
	strcpy( list[9].Parameter, "X'F1'" );
	strcpy( list[10].Mnemonic, "BYTE" );
	strcpy( list[10].Parameter, "C'HELLO'" );
	strcpy( list[11].Mnemonic, "RESW" );
	strcpy( list[11].Parameter, "BLAH   , X" );
	strcpy( list[12].Mnemonic, "WORD" );
	strcpy( list[12].Parameter, "F1H" );
	strcpy( list[13].Mnemonic, "END" );
	strcpy( list[13].Parameter, "1000H" );
}

int Check_Num( char *parameter ){
	char str[16] = "0123456789ABCDEF";
    int i, j;
    int chk_num = 1;
	int len = strlen( parameter );
	for (i = 0; i < len; i++){
		if( !isdigit( parameter[i] ) ){
			if( i == 0 && parameter[i] == '-' ){
				continue;
			}
			chk_num = 0;
			break;
		}
	}
	if( chk_num ){
		return 10;
	} else {
		for (i = 0; i < len - 1; i++){
			chk_num = 0;
			for( j = 0; j < 16; j++ ){
				if( parameter[i] == str[j] ){
					chk_num = 1;
				}
			}
			if(!chk_num){
				return -1;
			}
		}
	}
	if( parameter[len - 1] == 'H' ){
		return 16;
	}
	
	return -1;
}

int Check_X_Index( char *parameter, char *result ){
	char delims[] = " ,";
	strcpy( result, strtok( parameter, delims ));
	if( strtok( NULL, delims ) == NULL ){
		return 0;
	}
	return 1;
}

int Get_Opcode_Sic( char *Mnemonic, char *result ){
	int Num_Instruction = 26;
	char Instruction[26][5] = {	"ADD",	"AND",	"COMP",	"DIV",	"J",	"JEQ",	"JGT",	"JLT",	"JSUB",	"LDA",	"LDCH",	"LDL",	"LDX",	"MUL",	"OR",	"RD",	"RSUB",	"STA",	"STCH",	"STL",	"STSW",	"STX",	"SUB",	"TD",	"TIX",	"WD"	};
	char Opcode[26][3] = {		"18",	"40",	"28",	"24",	"3C",	"30",	"34",	"38",	"48",	"00",	"50",	"08",	"04",	"20",	"44",	"D8",	"4C",	"0C",	"54",	"14",	"E8",	"10",	"1C",	"E0",	"2C",	"DC"	};
	int i;

	for(i = 0; i < Num_Instruction; i++){
		if( strcmp( Instruction[i], Mnemonic ) == 0 ){
			strcpy( result, Opcode[i] );
			return 1;
		}
	}
	
	return 0;
}

long Get_Address_Symbol( int n_symbol, char *parameter ){
	int i;
	for(i = 0; i < n_symbol; i++){
		if( strcmp( SymbolTable[i].name, parameter ) == 0 ){
			return SymbolTable[i].value; 
		}
	}
	return -1;
}

void Get_Other_Object_Code( assambly Source, int N_Line ){
	long Object_Code = -1;
	int len = strlen( Source.Parameter );
	char *pEnd = &Source.Parameter[ len - 1 ];
	char result[100] = "";
	char tmp_str[100];
	int i, tmp;
	
	if( strcmp( Source.Mnemonic, "WORD" ) == 0 ){
		if( Check_Num( Source.Parameter ) != -1 ){
			if( Check_Num( Source.Parameter ) == 10 ){
				Object_Code = atoi( Source.Parameter );	
			} else if( Check_Num( Source.Parameter ) == 16 ){
				Object_Code = strtol( Source.Parameter, &pEnd, 16 );
			}
			Object_Code = Object_Code & 0xFFFFFF;
			sprintf( Value_Object_Code[N_Line], "%06lX", Object_Code );				
		}
	} else if( strcmp( Source.Mnemonic, "BYTE" ) == 0 ){
		strncpy( result, &Source.Parameter[2], len - 3 );
		if( Source.Parameter[0] == 'X' ){
            //printf("%s\n", result);
			//pEnd = &result[ strlen(result) - 1 ];
			//Object_Code = strtol( result, &pEnd, 16 );
			sprintf( Value_Object_Code[N_Line], "%s",result );
		} else if( Source.Parameter[0] == 'C' ){
			for(i = 0; i < strlen( result ); i++){
				tmp = result[i];
				sprintf( tmp_str, "%X", tmp );
				strcat( Value_Object_Code[N_Line], tmp_str );			
			}	
		}					
	}
}

long Get_Object_Code_Format( char tmp[] ){
	long Object_Code;
	char *pEnd;	
	if( Check_Num( tmp ) != -1 ){
		if( Check_Num( tmp ) == 10 ){
			Object_Code = atoi( tmp );	
		} else if( Check_Num( tmp ) == 16 ){
			pEnd = &tmp[ strlen( tmp - 1) ];
			Object_Code = strtol( tmp, &pEnd, 16 );
		}
		Object_Code = Object_Code & 0xFFFFFF;
	} else {
		Object_Code = Get_Address_Symbol( N_Symbol, tmp );	
	}
	return Object_Code;
}

void Write_Object_File(){
	int N_Line = 0;
	int Sum_Word = 0;
	int Start_Line = 0;
	int End_Line = 0;
	int Line;
	long Object_Code = 0;
	//char tmp[100];
	
	FILE *Object_File;
	Object_File = fopen("code.o", "w");
	if( Object_File == NULL ){
		printf("Cannot Open File.\n");
		return;
	}
	
	// H LINE
	Object_Code = Get_Object_Code_Format( list[0].Parameter );
	fprintf( Object_File, "H%s %06lX%06X\n",list[0].Symbol, Object_Code,list[N_Instruction-1].Address - list[0].Address);
	//T LINE
	for(N_Line = 1; N_Line < N_Instruction - 1; N_Line++){
		if( strcmp( Value_Object_Code[N_Line], "RES") == 0 ){
			continue;
		}
		Sum_Word = 0;
		Start_Line = N_Line;
		while( strcmp( Value_Object_Code[N_Line], "RES") != 0 && N_Line < N_Instruction - 1 ){
			Sum_Word += strlen( Value_Object_Code[N_Line] );
			if( Sum_Word > 60 ){
				Sum_Word -= strlen( Value_Object_Code[N_Line] );
				break;	
			}
			N_Line++;
		}
		End_Line = --N_Line;
		fprintf( Object_File, "T%06X%02X", list[Start_Line].Address,Sum_Word/2);
		for( Line = Start_Line; Line <= End_Line; Line++ ){
			fprintf( Object_File, "%s", Value_Object_Code[Line]);
		}
		fprintf( Object_File, "\n");
	}
	
	// E LINE
	Object_Code = Get_Object_Code_Format( list[N_Instruction-1].Parameter );
	fprintf( Object_File, "E%06lX",Object_Code);
	
	fclose(Object_File);
}

void Get_Object_Code( assambly list[],int N_Instruction ){
	//int Is_Ins = 0;
	char Opcode[3];
	//char Output[100] = "";
	char tmp[100] = "";
	//int n_line = 1;
	//int n_word = 0;
	long Object_Code;
	int i;
	int X_Index;
	char *pEnd;
	
	for(i = 1; i < N_Instruction - 1 ; i++){
		if( Get_Opcode_Sic( list[i].Mnemonic, Opcode ) ){
			strcpy( Value_Object_Code[i], Opcode );
			if( strcmp( list[i].Mnemonic,"RSUB" ) == 0 ){
				strcat( Value_Object_Code[i], "0000" );
				//printf("%s\n",Value_Object_Code[i]);
				continue;
			}
			X_Index = Check_X_Index( list[i].Parameter, tmp );
			if( !X_Index ){
				strcpy( tmp, list[i].Parameter );	
			}
			if( Check_Num( tmp ) != -1 ){
				if( Check_Num( tmp ) == 10 ){
					Object_Code = atoi( tmp );	
				} else if( Check_Num( tmp ) == 16 ){
					pEnd = &list[i].Parameter[ strlen(list[i].Parameter) - 1 ];
					Object_Code = strtol( tmp, &pEnd, 16 );
				}
				Object_Code = Object_Code & 0xFFFF;
			} else {
				Object_Code = Get_Address_Symbol( N_Symbol, tmp );	
			}
			if( X_Index ){
				Object_Code += 0x8000; 
			}
			sprintf( tmp, "%04lX", Object_Code );
			strcat( Value_Object_Code[i], tmp );
		} else {
			if( strncmp( list[i].Mnemonic, "RES", 3 ) == 0 ){
				strcpy( Value_Object_Code[i], "RES" );
				//printf("%s\n",Value_Object_Code[i]);
				continue;
			}
			Get_Other_Object_Code( list[i], i );
		}
		//printf("%s\n",Value_Object_Code[i]);
	}
	
	Write_Object_File();
	
}

int assambler_passtwo(void) {
	//__Init__();
	Get_Object_Code( list, N_Instruction );
    //getch();
    return 0;
}
