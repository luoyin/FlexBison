#include "parser.h"

unsigned char SolveReg(char c)
{
	switch(c)
	{
		case 'A':
			return 0;
		case 'B':
			return 1;
		case 'C':
			return 2;
		case 'D':
			return 3;
		case 'E':
			return 4;
		case 'H':
			return 5;
		case 'L':
			return 6;
		default:
			return 7;
	}
}

unsigned char SolveCommand_LRR(char *s)
{
	unsigned char r1=SolveReg(s[1]);
	unsigned char r2=SolveReg(s[2]);
	
	return (0xC0 | (r1<<3) | r2);
}

unsigned char SolveCommand_LRM(char *s)
{
	unsigned char r_dst=SolveReg(s[1]);
	
	return (0xC0 | (r_dst<<3) | 0x07);
}

unsigned char SolveCommand_LMR(char *s)
{
	unsigned char r_src=SolveReg(s[2]);
	
	return (0xC0 | (0x07<<3) | r_src);
}

unsigned char SolveCommand_LRI(char *s)
{
	unsigned char r_dst=SolveReg(s[1]);
	
	return (0x00 | (r_dst<<3) | 0x06);
}

unsigned char SolveCommand_INR(char *s)
{
	unsigned char r_dst=SolveReg(s[1]);
	if(r_dst==0x00)
		yyerror("Invalid command");
	
	return (0x00 | (r_dst<<3) | 0x00);
}

unsigned char SolveCommand_DCR(char *s)
{
	unsigned char r_dst=SolveReg(s[1]);
	if(r_dst==0x00)
		yyerror("Invalid command");
	
	return (0x00 | (r_dst<<3) | 0x01);
}

void yyerror(char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	
	fprintf(stderr, "Line%d error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}

