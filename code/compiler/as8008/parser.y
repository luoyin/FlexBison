%{
#include "parser.h"
%}

%union{
	unsigned char cmd;
}

%token <cmd> LRR
%token <cmd> LRM
%token <cmd> LMR
%token <cmd> LRI
%token <cmd> LMI
%token <cmd> INR
%token <cmd> DCR

%token EOL
%type <cmd> command0, line_cmd

%%

stmt:
	| stmt line_cmd EOL
	;
	
line_cmd:
	command0
	;
	
command0:
	LRR
	| LMR
	| LRM
	| INR
	| DCR
	;

%%
