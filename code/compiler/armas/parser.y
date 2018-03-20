%{
#include "parser.h"
%}

%union{
	struct s_REG *reg;
}

%token <reg> REG

%token EOL

%%

stmt: 
	| stmt reg EOL
	;
	
reg: REG				{ printf("R%d\n> ", $1->regndx); }
	;
	


%%