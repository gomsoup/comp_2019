%{
	#include <stdlib.h>
	#include "y.tab.h"

	extern int yylval;
%}
%%
[0-9]+ 	{ yylval = atoi(yytext); return NUMBER; }
[-+()=/*]+ { return *yytext; }
[ \t]+	;
\n	return 0;

.	{ printf("error near '%s'\n", yytext); exit(-1); }
%%
int yywrap(){
	return 1;
}
