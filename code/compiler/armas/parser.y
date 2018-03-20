%{
#include "parser.h"
%}

%union{
	struct s_REG *reg;
	unsigned int imm;
}

%token <reg> REG
%token <imm> IMM

%token EOL
%token ROT
%token LSL
%token LSR
%token ASR
%token ROR
%token RRX

%%

stmt: 
	| stmt stmt_ins EOL
	;
	
stmt_ins:
	| stmt_ins_branch
	| stmt_ins_data_process
	;
	
stmt_ins_data_process:
	| opcode_data_process1 reg, shifter_operand
	| opcode_data_process2 reg, shifter_operand
	| opcode_data_process3 reg, reg, shifter_operand
	;

shifter_operand: 
	IMM,
	| reg
	| reg, ROT #IMM
	| reg, ROT reg
	;
	
	
opcode_data_process1:
	| MOV
	| MVN
	;

opcode_data_process2:
	| CMP
	| CMN
	| TST
	| TEQ
	;
	
opcode_data_process3:
	| ADD
	| SUB
	| RSB
	| ADC
	| SBC
	| RSC
	| AND
	| BIC
	| EOR
	| ORR
	;
	
reg: REG				{ printf("R%d\n> ", $1->regndx); }
	;
	


%%