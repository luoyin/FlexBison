#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

extern int yylineno;
void yyerror(char *s, ...);

struct s_REG
{
	int regndx;
};

struct s_REG * SolveReg(char *s);
void yyerror(char *s, ...);
