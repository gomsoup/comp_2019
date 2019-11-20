%{
	#include "y.tab.h"
	#include "ast.h"
	#include <stdlib.h>

	extern yyerror(char *msg);
%}
%%
'+'	{ return ADD; }
'-'	{ return SUB; }
'/'	{ return DIV; }
'*'	{ return MUL; }
'\('	{ return LBR; }
'\)'	{ return RBR; }
[0-9]+	{ yylval.ival = atoi(yytext); return NUMBER; }
[ \t]	{}
\n	{ return EOL; }
.	{ yyerror("Unknonw character"); }
%%

int yywrap(){
	return 1; 
}
	
