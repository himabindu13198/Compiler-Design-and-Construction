/* Author : Hima Bindu
	OPERATOR PRECEDENCE PARSER 	*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void push(char c);
char pop();
void showstack();
void showip();
void reduceip();

char ip[20],optab[10][10][1],stack[20];
int i,j,k,n,top=-1, index_of(char);
char op[20],del;

void main()
{
/*for(i=0;i<20;i++)
{
        stack[i]=NULL;
        ip[i]=NULL;
        for(j=0;j<20;j++)
        {
                optab[i][j][1]=NULL;
        }
}*/
printf("\n Enter the number of operators:");
scanf("%d",&n);
printf("\n Enter the operators:");
for(i=0;i<n;i++)
{
        scanf("%s",&op[i]);
}
op[i]='$';
op[i+1]='i';
n=n+2;
/*printf("\n The operators are:");
for(i=0;i<n;i++)
{
        printf("%c",op[i]);
}*/
printf("\n Enter the precedence of operators:\n");
for(i=0;i<n;i++)
{
        //printf("\n %d",i+1);
        for(j=0;j<n;j++)
        {
                printf(" \n%c vs %c: ", op[i],op[j]);
                scanf("%s",&optab[i][j][1]);
        }
}
printf("\n The operator precedence table is as follows:\n");
printf("\t");
for(i=0;i<n;i++){printf("%c \t",op[i]);}
for(i=0;i<n;i++)
{
        printf("\n%c \t",op[i]);
        for(j=0;j<n;j++)
                {
                        printf("%c\t",optab[i][j][1]);
                }
}
printf("\n Enter the expression:");
scanf("%s",&ip);
strcat(ip,"$");
//printf("%s",ip);


//stack operation
push('$');
//showstack();
printf("\nSTACK\tINPUT\tACTION");
while(strlen(ip))
//int x;
//for(x=0;x<7;x++)
{
        int a,b,c;

        a=index_of(stack[top]); c=index_of(ip[0]);
//printf("%d",a);printf("%d",c);
        if(ip[0]=='$' && stack[top]=='$')
        {
                printf("\n String successfully parsed");
                exit(0);
        }
        else if(optab[c][a][1]=='>' || optab[c][a][1]=='=')
        {
                push(ip[0]);
                reduceip();
                printf("\n");
                showstack();
                printf("\t");
                showip();
                printf("\t%s","shift");
        }
        else if(optab[c][a][1]=='<')
        {
                do
                {
		if(stack[top]!='$')
                {del=pop();
                printf("\n");
                showstack();
                printf("\t");
                showip();
                printf("\t%s","reduce");
                b=index_of(del);
                }}while(optab[b][stack[top]][1]=='>');
        }
        else
        {
                printf("\n Error"); break;
        }
}
}

/*
a=input[0] and b=stack[top]
while(strlen(ip)!=1)
{
        if(optab[stack[top]][ip[0]]!='>')
        {
                push(ip[0]);
                reduceip();
        }
        else
        {
                del=pop();
        }
}
printf('\n');
//working fine till here, check the commented section
--if(strlen(ip)==1)
{
        while(optab[stack[top]][ip[0]]=='>')
        {
                del=pop();
        }
}
if(stack[top]=='$' && ip[0]=='$$')
{
        printf("\n String accepted");
}
else
{
        printf("\n String not accepted");
}--
} */

//functions definition

void push(char c)
{
stack[++top]=c;
}

char pop()
{
char c;
c=stack[top--];
}

void showstack()
{
        for(i=0;i<=top;i++)
        {
        printf("%c",stack[i]);
        }
}

void showip()
{
        for(i=0;i<strlen(ip);i++)
        {
                printf("%c",ip[i]);
        }
}
int index_of(char c)
{
int i;
        for(i=0;i<strlen(op);i++)
        {
                if(c==op[i])
                {
                        return i;
                }
        }
return -1;
}
void reduceip()
{
for(i=0;i<strlen(ip);i++)
{
        ip[i]=ip[i+1];
}
//ip[i]='\0';
//printf("\n Length now is: %d",strlen(ip));
}
