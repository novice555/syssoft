#define MaxArray 100
#define Maxlength 100
typedef struct {
    char name[Maxlength];
    int value;
} dict;
typedef struct {
    char Symbol[Maxlength];
    char Mnemonic[Maxlength];
    char Parameter[Maxlength];
} assambly;
extern assambly list[MaxArray];

