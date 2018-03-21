%{
#include "parser.h"
%}

%union{
	unsigned int regndx;
	unsigned int condcode;
	int imm;
}

%token <regndx> REG
%token <condcode> COND
%token <condcode> LDR
%token <imm> IMM_P
%token <imm> IMM_N

%token EOL
%token COMMA
%token ROT
%token LSL
%token LSR
%token ASR
%token ROR
%token RRX

%%

stmt: 
	| stmt reg EOL
	| stmt addr_mode2 EOL
	| stmt imm EOL		
	;
	
addr_mode2:
	'[' REG ',' 		{ printf("Addressing Mode2\n> "); }
	;

imm:
	IMM_P				{ printf("Imm=+0x%x\n", $1); }
	| IMM_N				{ printf("Imm=-0x%x\n", $1); }

reg: REG				{ printf("R%d\n> ", $1); }
	;
	


%%