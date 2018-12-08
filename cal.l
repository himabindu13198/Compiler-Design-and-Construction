%{
#include "cal.tab.h"    
extern yylval;
%}


%%

[a-zA-Z][a-zA-Z0-9]*	{ return id;}
[0-9]+			{yylval=atoi(yytext); return num;}
[\n]			{return N;}
.			{return yytext[0];}
%%

int yywrap()
{
return 1;
}
