#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <malloc.h>
#include "parser.h"

struct s_REG * SolveReg(char *s)
{
	struct s_REG *r = (struct s_REG *)malloc(sizeof(struct s_REG));
	r->regndx=atoi(s+1);
	
	return r;
}

void yyerror(char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	
	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}

int main(int argc, char **argv)
{
	printf("> ");
	return yyparse();
}
