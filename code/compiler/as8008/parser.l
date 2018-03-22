%{
#include "parser.h"
#include "parser.tab.h"
%}

REG						("A"|"B"|"C"|"D"|"E"|"H"|"L")

%%

"L"{REG}{REG}			{ yylval.cmd=SolveCommand_LRR(yytext); return LRR; }
"L"{REG}"M"				{ yylval.cmd=SolveCommand_LRM(yytext); return LRM; }
"LM"{REG}				{ yylval.cmd=SolveCommand_LMR(yytext); return LMR; }
"L"{REG}"I"				{ yylval.cmd=SolveCommand_LRI(yytext); return LRI; }
"LMI"					{ yylval.cmd=0x3E; return LMI; }
"IN"{REG}				{ yylval.cmd=SolveCommand_INR(yytext); return INR; }
"DC"{REG}				{ yylval.cmd=SolveCommand_DCR(yytext); return DCR; }
"\n"					{ return EOL; }

%%

