/*
Author : Hima Bindu Bhardwaj
For the grammar : 

E -> TE’
E’ -> +TE’ | Ɛ
T -> FT’
T’ -> *FT’ | Ɛ
F -> (E) | id

*/

#include<stdio.h>
#include<string.h>

char input[100];
char productions[100][100];
int i,len,curr=0,p=0;

void E();
void T();
void Ed();
void Td();
void F();
void parse();

void main()
{

	printf("\n Enter the string to parse\n");
	scanf("%s",input);
	len=strlen(input);
	//input[len]='$';
	E();
	//printf("\n Value of p is: %d",p);
	printf("\n Productions parsed are:");
		for(i=0;i<p;i++)
		{
			printf("\n %s",productions[i]);
		}	
	if(curr==len) 
	{
		printf("\n String accepted");
		/*printf("\n Productions parsed are:");
		for(i=0;i<p;i++)
		{
			printf("\n %s",productions[i]);
		}*/
	}
	else printf("\n String rejected");
}



void parse()
{
curr++;
}
void E()
{

	strcpy(productions[p++],"E -> TE’");
	T();
	Ed();
}
void T()
{
	strcpy(productions[p++],"T -> FT’");
	F();
	Td();
}

void Ed()
{
	if(input[curr]=='+')
	{
		strcpy(productions[p++],"E’ -> +TE’");
		parse();
		T();
		Ed();
	}
	else
	{
		strcpy(productions[p++],"E’ -> null");
	}
}

void F()
{
	if(input[curr]=='(')
	{
		strcpy(productions[p++],"F -> (E)");
		parse();
		E();
		if(input[curr]==')') parse();
	}
	else
	{
		strcpy(productions[p++],"F -> id");
		parse();
	}
}
 
void Td()
{
	if(input[curr]=='*')
	{
		strcpy(productions[p++],"T’ -> *FT’");
		parse();
		F();
		Td();
	}
	else
	{
		strcpy(productions[p++],"T’ -> null");
	}
}



