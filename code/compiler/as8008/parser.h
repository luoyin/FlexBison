#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <malloc.h>
#include "as8008.h"

extern int yylineno;
void yyerror(char *s, ...);

unsigned char SolveCommand_LRR(char *s);
unsigned char SolveCommand_LRM(char *s);
unsigned char SolveCommand_LMR(char *s);
unsigned char SolveCommand_LRI(char *s);
unsigned char SolveCommand_INR(char *s);
unsigned char SolveCommand_DCR(char *s);

#endif
