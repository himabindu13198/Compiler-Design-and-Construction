/*

AUTHOR : HIMA BINDU
INTERMEDIATE CODE
*/

%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void yyerror(char* a);

char reg[20][10]={"a","b","c","d","e","f","g","h","i","j"};
extern FILE *yyout;
int p=0,first=0;

%}


%token id num N


%left '+' '-'
%left '*' '/'

%%

start:expr N {printf("\nAnswer is : %d\n",$1);  fprintf(yyout,"%s:=%d;\n\n",reg[(const)p++],$1); exit(0);} 
     
expr: 	     
     |expr '+' expr {$$ = $1+$3;  fprintf(yyout,"%s:=%s + %d;\n\n",reg[(const)p++],reg[(const)p-1],$3); }
     |expr '-' expr {$$ = $1-$3;  fprintf(yyout,"%s:=%s - %d;\n\n",reg[(const)p++],reg[(const)p-1],$3); }
     |expr '*' expr {$$ = $1*$3;  fprintf(yyout,"%s:=%s * %d;\n\n",reg[(const)p++],reg[(const)p-1],$3); }
     |expr '/' expr {$$ = $1/$3;  fprintf(yyout,"%s:=%s / %d;\n\n",reg[(const)p++],reg[(const)p-1],$3); }	     
     |'('expr')'    {$$ = $2;     fprintf(yyout,"%s:=( %d );\n\n",reg[(const)p++],$2); }  
     |num  	    {$$ = $1;     if(!first) fprintf(yyout,"%s:=%d;\n\n",reg[(const)p++],$1); first=1; };

%%

void main()
{
yyout = fopen("output.txt","w");
printf("\n Enter the expression: \n");
yyparse();
}

void yyerror(char* a)
{
printf("%s",a);
} 


