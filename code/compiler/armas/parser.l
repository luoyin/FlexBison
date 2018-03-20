%{
#include "parser.h"
#include "parser.tab.h"
%}

CONDITION		(EQ|NE|CS|HS|CC|LO|MI|PL|VS|VC|HI|LS|GE|LT|GT|LE|AL|)
REGINDEX		(0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15)

%%

	// REG
R{REGINDEX}		{ yylval.reg=SolveReg(yytext); return REG; }
\n				{ return EOL; }
.

%%

