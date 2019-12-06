%{
	#include "y.tab.h"
	#include "ast.h"
	extern int yylex();
	extern void yyparse(char *s);
%}


%%
"+"	{ return ADD; }
"-"	{ return SUB; }
"/"	{ return DIV; }
"*"	{ return MUL; }
"("	{ return LBR; }
")"	{ return RBR; }
[0-9]+	{ yylval.ival = atoi(yytext); return NUMBER; }
[a-zA-Z]+ { yylval.sval = yytext; return STRING; }
[ \t]	{}
\n	{ return EOL; }
.	{ exit(1); }
%%

int yywrap(){
	return 1; 
}
