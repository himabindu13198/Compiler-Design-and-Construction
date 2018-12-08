#include<stdio.h>
#include<string.h>

void replace(char,char,int);
FILE *ptr, *ptr1;
char arr[10][10],p=0,buffer[10],str[5],num,ch;
int i,j,k,n=0;

void main()
{


ptr=fopen("output.txt","r+");
ptr1=fopen("output1.txt","w");
if(ptr==NULL || ptr1==NULL)
{
	printf("\n Error in opening the file!");
}

while(fgets(buffer, sizeof(buffer), ptr)) 
{
strcpy(arr[p++],buffer); n++;
}
p=0;
printf("\n Number of lines is : %d",n);
for(i=0;i<n;i++)
{
printf("%s",arr[i]);
}

for(i=0;i<n;i++)
{
	for(j=0;j<strlen(arr[i]);j++)
	{
		if(arr[i][j]=='=' && isdigit(arr[i][j+1]) && arr[i][j+2]==';')
		{
			num=arr[i][j+1]; ch=arr[i][0]; replace(ch,num,i);
		}
	}
}

fclose(ptr);
}

void replace(char a, char num, int line)
{
int j;
for(i=line+1;i<n;i++)
{
	//if(arr[i][0]=='a') for(j=0;j<strlen(arr[i]);j++) fprintf(ptr1,"%c",arr[i][j]); 
	//else
	{
		for(j=0;j<strlen(arr[i]);j++)
		{
			if(arr[i][j]=='a') fprintf(ptr1,"%c",num); 
			else fprintf(ptr1,"%c",arr[i][j]);
		}
	}
	
}
}
