#include<stdio.h>
#include<string.h>

FILE *ptr, *ptr1;
char buffer[10], arr[10][10], str[10];
int n=0,p=0,j,i,k,q;
void process(char str1[]);

void main()
{

ptr=fopen("output.txt","r");
ptr1=fopen("assembly.txt","w+");
if(ptr==NULL || ptr1==NULL)
{
	printf("\n Error in opening file!");
}

while(fgets(buffer, sizeof(buffer), ptr)) 
{
strcpy(arr[p++],buffer); n++;
}

//printf("\n Number of lines: %d\n",n);

for(i=0;i<n;i++)
{
process(arr[i]);
}

fclose(ptr);
fclose(ptr1);
}

void process(char str1[10])
{
	char opr1,opr2,opr3;
	
	opr1=str1[0];
	
	opr2=str1[3];
	opr3=str1[5];
	//printf("\n opr1 is : %c, %c, %c",opr1,opr2,opr3);
	if(str1[4]==';')
	{
		fprintf(ptr1,"MOV %s,%c\n\n","AX",str1[3]);
	}
	if(str1[4]=='+')
	{
		fprintf(ptr1,"MOV %s,%c\n","AX",opr2);
		fprintf(ptr1,"ADD %c\n",opr3);
		fprintf(ptr1,"MOV %c,%s\n\n",opr1,"AX");
	}
	if(str1[4]=='-')
	{
		fprintf(ptr1,"MOV %s,%c\n","AX",opr2);
		fprintf(ptr1,"SUB %c\n",opr3);
		fprintf(ptr1,"MOV %c,%s\n\n",opr1,"AX");
	}
	if(str1[4]=='*')
	{
		fprintf(ptr1,"MOV %s,%c\n","AX",opr2);
		fprintf(ptr1,"MUL %c\n",opr3);
		fprintf(ptr1,"MOV %c,%s\n\n",opr1,"AX");
	}
	if(str1[4]=='/')
	{
		fprintf(ptr1,"MOV %s,%c\n","AX",opr2);
		fprintf(ptr1,"DIV %c\n",opr3);
		fprintf(ptr1,"MOV %c,%s\n\n",opr1,"AX");
	}
}




