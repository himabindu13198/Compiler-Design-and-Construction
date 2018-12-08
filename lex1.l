/* FIRST PROGRAM
AUTHOR: HIMA BINDU*/

%{
#include<stdio.h>
int comment=0;
int notfunc=1;
%}

identifier [a-zA-Z][a-zA-Z0-9_]*


%%

"#".*	{printf("\nHEADER FILE:\t");}
"/*"	{printf("\n COMMENT BEGINS\t"); comment=1;}
"*/"	{printf("\nCOMMENT ENDS\n"); comment=0;}
"//"	{printf("\n COMMENT\n");}
"if"|"else"|"continue"|"break"|"exit"|"switch"|"return"|"int"|"printf"|"char"|"char*"|"float"|"double"|"struct"|"void"	{if(!comment)printf("\nKEYWORD:");}
"for""(".*")"|"while""(".*")"|"do"	{if(!comment)printf("\nLOOP BEGINS\n");}
[identifier]*"(".*")"	{notfunc=0; if(!notfunc)printf(" FUNCTION ");}
"{"	{printf("\nBLOCK BEGINS\n");}
"}"	{printf("\nBLOCK ENDS\n");}
"<"|">"|"<="|">="|"=="|"<>"	{printf("\tRELOP\t");}
"="	{printf("\tASSIGNMENT OPERATOR\t");}
[identifier]"["[0-9]*"]"	{printf("ARRAY");}
"("	{ECHO;}
")"	{ECHO;}
"+"+|"-"+ {printf("\nUnary Operator\n");}
.	;
%%

int main()
{
FILE *f;
f=fopen("input.txt","r");
if(!f)
{
	printf("\n File could not be opened");
	return 0;
}
yyin = f;
yylex();
return 1;
}

int yywrap()
{
return 1;
}
