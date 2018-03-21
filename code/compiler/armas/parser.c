#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "parser.h"

unsigned int SolveReg(char *s)
{
	return atoi(s+1);
}

unsigned int SolveCondCode(char *s)
{
	if(strcasecmp(s, "EQ")==0)
		return 0x00;
	else if(strcasecmp(s, "NE")==0)
		return 0x01;
	else if(strcasecmp(s, "CS")==0 || strcasecmp(s, "HS")==0)
		return 0x02;
	else if(strcasecmp(s, "CC")==0 || strcasecmp(s, "LO")==0)
		return 0x03;
	else if(strcasecmp(s, "MI")==0)
		return 0x04;
	else if(strcasecmp(s, "PL")==0)
		return 0x05;
	else if(strcasecmp(s, "VS")==0)
		return 0x06;
	else if(strcasecmp(s, "VC")==0)
		return 0x07;
	else if(strcasecmp(s, "HI")==0)
		return 0x08;
	else if(strcasecmp(s, "LS")==0)
		return 0x09;
	else if(strcasecmp(s, "GE")==0)
		return 0x0A;
	else if(strcasecmp(s, "LT")==0)
		return 0x0B;
	else if(strcasecmp(s, "GT")==0)
		return 0x0C;
	else if(strcasecmp(s, "LE")==0)
		return 0x0D;
	else if(strcasecmp(s, "AL")==0 || strcmp(s, "")==0)
		return 0x0E;
	return 0x0F;
}

int SolveImm_Hex(char *s)
{
	int sign=1;
	if(s[1]=='-' || s[1]=='+')
		return SolveHex(s+4);
	else
		return SolveHex(s+3);
}

int SolveHex(char* s)
{
	int value=0;
	int i;
	for(i=0; i<strlen(s); i++)
	{
		value=value*16+SolveHexChar(s[i]);
	}
	return value;
}

int SolveHexChar(char c)
{
	if(c>='A' && c<='F')
		return c-'A'+10;
	if(c>='a' && c<='f')
		return c-'a'+10;
	if(c>='0' && c<='9')
		return c-'0';
	return 0;
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
