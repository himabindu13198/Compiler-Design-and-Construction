%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void yyerror(char* a);
%}


%token id num N


%left '+' '-'
%left '*' '/'

%%

start:expr N {printf("\n Valid expression\n Answer is : %d\n",$1); exit(0);} 
      |id {printf("\n Identifier accepted"); exit(0);};

expr: 	     
     |expr '+' expr {$$ = $1+$3;}
     |expr '-' expr {$$ = $1-$3;}
     |expr '*' expr {$$ = $1*$3;}
     |expr '/' expr {$$ = $1/$3;}	     
     |'('expr')'    {$$ = $2;}  
     |num  	    {$$ = $1;} ;

%%

void main()
{
printf("\n Enter the expression: \n");
yyparse();
}

void yyerror(char* a)
{
printf("%s",a);
} 



