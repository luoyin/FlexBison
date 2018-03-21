#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

extern int yylineno;
void yyerror(char *s, ...);

unsigned int SolveReg(char *s);
unsigned int SolveCondCode(char *s);
int SolveImm_Hex(char *s);
int SolveHex(char *s);
int SolveHexChar(char c);
void yyerror(char *s, ...);
