#include "as8008.h"
#include "parser.h"

int main(int argc, char **argv)
{
	printf("> ");
	return yyparse();
}