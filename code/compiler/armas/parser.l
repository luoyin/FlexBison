%{
#include "parser.h"
#include "parser.tab.h"
%}

CONDITION		(?i:"EQ"|"NE"|"CS"|"HS"|"CC"|"LO"|"MI"|"PL"|"VS"|"VC"|"HI"|"LS"|"GE"|"LT"|"GT"|"LE"|"AL"|"")
REGINDEX		("0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"|"10"|"11"|"12"|"13"|"14"|"15")
ROT				(LSL|LSR|ASR|ROR)

%%

	// REG
("R"|"r"){REGINDEX}$				{ yylval.regndx=SolveReg(yytext); return REG; }
^#[+]?(0[xX][0-9A-Fa-f]+)			{ yylval.imm=SolveImm_Hex(yytext); return IMM_P; }
^#[-]?(0[xX][0-9A-Fa-f]+)			{ yylval.imm=SolveImm_Hex(yytext); return IMM_N; }
^(?i:"LDR")({CONDITION})			{ yylval.condcode=SolveCondCode(yytext+3); return LDR; }
\n									{ return EOL; }
","									{ return COMMA; }
.									{ printf("Mystery character %c\n> ", yytext[0]); }

%%


