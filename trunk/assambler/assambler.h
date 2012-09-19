#define MaxArray 5000
#define Maxlength 100
#define MAX_OPCODE 26
typedef struct {
    char name[Maxlength];
    int value;
} dict;
typedef struct {
    char Symbol[Maxlength];
    char Mnemonic[Maxlength];
    char Parameter[Maxlength];
    int Address;
} assambly;
extern assambly list[MaxArray];
extern dict SymbolTable[MaxArray];
extern int N_Instruction;
extern int N_Symbol;
extern char ProgramName[Maxlength];
extern int ProgramLength;
extern FILE *fptr;
