#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int checkfinal(int);

char str[10];
int i,state=0,final[20]= {2,3,4,6,7,21,9,11,13,14,16,17,18,19,20,23,24}; //17 final states
char keywords[100] = "void main int float char char* if else while do printf";
FILE *fi, *fo;

void main()
{

fi=fopen("input_lex2.txt","r");
fo=fopen("output_lex2.txt","w");


while(fscanf(fi,"%s",str) != EOF)
{
	//printf("String read is :%s\n", str);
	if(!strcmp(str,"`"))fprintf(fo,"%s","\n");
	
	if(strstr(keywords,str))
	{
		fprintf(fo,"%s%s%s","token(keyword,",str,") ");
	}

	else if(!strcmp(str,"(") || !strcmp(str,";") || !strcmp(str,")") || !strcmp(str,"\"") || !strcmp(str,"{") || !strcmp(str,"}"))
	{
		//printf("hi");
		state=24;
		if(checkfinal(state)){fprintf(fo,"%s",str); }
		state=0;
	}

 	else if(isalpha(str[0]))
	{
		state=10;
		for(i=1;i<strlen(str);i++)
		{
			if(i!=strlen(str))if(isalpha(str[i])||isdigit(str[i])) state=10; else printf("\n Error in identifier\n");
		}
		if(i==strlen(str)) state=11;
		if(checkfinal(state)){ fprintf(fo,"%s%s%s","token(identifier,",str,") "); }
		state=0;
	}
	
	else if(str[0]=='<')
	{
		state=1;
		for(i=1;i<strlen(str);i++)
		{
			if(i!=strlen(str))if(str[i]=='=') state=2; else if(str[i]=='>') state=3; else printf("\n Error in operator");
		}
		if(i==strlen(str)) state=4;
		if(checkfinal(state)){fprintf(fo,"%s%s%s","token(Relop,",str,") "); }
		state=0;
	}
	
	else if(str[0]=='>')
	{
		state=5;
		for(i=1;i<strlen(str);i++)
		{
			if(i!=strlen(str))if(str[i]=='=') state=6; else printf("\n Error in operator");
		}
		if(i==strlen(str)) state=7;
		if(checkfinal(state)){fprintf(fo,"%s%s%s","token(Relop,",str,") "); }
		state=0;
	}

	else if(str[0]=='=')
	{
		state=8;
		for(i=1;i<strlen(str);i++)
		{
			if(i!=strlen(str))if(str[i]=='=') state=9; else printf("\n Error in operator");
		}
		if(i==strlen(str)) state=21;
		if(checkfinal(state)){fprintf(fo,"%s%s%s","token(Relop,",str,") "); }
		state=0;
	}

	else if(str[0]=='+')
	{
		state=12;
		for(i=1;i<strlen(str);i++)
		{
			if(i!=strlen(str))if(str[i]=='+') state=13; else printf("\n Error in operator");
		}
		if(i==strlen(str)) state=14;
		if(checkfinal(state)){fprintf(fo,"%s%s%s","token(Operator,",str,") "); }
		state=0;
	}
		
	else if(str[0]=='-')
	{
		state=15;
		for(i=1;i<strlen(str);i++)
		{
			if(i!=strlen(str))if(str[i]=='-') state=16; else printf("\n Error in operator");
		}
		if(i==strlen(str)) state=17;
		if(checkfinal(state)){fprintf(fo,"%s%s%s","token(Operator,",str,") "); }
		state=0;
	}
	
	else if(str[0]=='*')
	{
		state=18;
		if(checkfinal(state)){fprintf(fo,"%s%s%s","token(Operator,",str,") "); }
		state=0;
	}
		
	else if(str[0]=='/')
	{
		state=19;
		if(checkfinal(state)){fprintf(fo,"%s%s%s","token(Operator,",str,") "); }
		state=0;
	}

	else if(str[0]=='%')
	{
		state=20;
		if(checkfinal(state)){fprintf(fo,"%s%s%s","token(Operator,",str,") "); }
		state=0;
	}
	else if(isdigit(str[0]))
	{
		state=22;
		for(i=1;i<strlen(str);i++)
		{
			if(i!=strlen(str))if(isdigit(str[i])) state=22; else printf("\n Error in identifier\n");
		}
		if(i==strlen(str)) state=23;
		if(checkfinal(state)){ fprintf(fo,"%s%s%s","token(number,",str,") "); }
		state=0;
	}
		
			 
}

fclose(fi);
fclose(fo);
}

int checkfinal(int a)
{
int flag =0;
for(i=0;i<17;i++)
{
	if(a==final[i])
	flag=1;
}
if(flag==1) return 1;
else return 0;
}
