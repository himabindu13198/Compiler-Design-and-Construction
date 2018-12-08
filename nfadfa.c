#include<stdio.h>
#include<string.h>
#include<math.h>

int ninputs;
int nfa[1000][3][1000] = {0};
int state[1000] = {0};
int go[1000][2] = {0};
int arr[1000] = {0};

int main()
{
	int st,fin,in;
	int f[10];
	int i,j,s=0,final=0,flag=0, k,l;
	int c;
	printf("\nEnter the number of states:");
	scanf("%d",&st);
	printf("\nGive state numbers from 0 to %d", st-1);
	printf("\n\nEnter the final state:");
	scanf("%d",&fin);
	int p,q,r,rel;
	printf("\n Enter the number of rules according to the E-NFA:");
	scanf("%d",&rel);
	printf("\n\n Define translation rules as \"initial-state input-symbol ( final-state\" \n");
	
	for(i=0;i<rel;i++)
	{
		scanf("%d %d %d",&p,&q,&r);
		if(q==0)
			dfa[p][0][r]=1;
		else
			dfa[p][1][r]=1;
	}
	printf("\n Enter initial state:");
	scanf("%d",&in);
	in=pow(2,in);
	i=0;
	printf("\n Solving accordingly :\n");
	int x=0;
	for(i=0;i<st;i++)
	{
		for(j=0;j<2;j++)
		{
			int stf=0;
			for(k=0;k<st;k++)
			{
				if(dfa[i][j][k]==1)
					stf=stf+pow(2,k);
			}	
			go[(int)(pow(2,i))][j]=stf;
			printf("%d - %d --> %d\n",(int)(pow(2,i)),j,stf);
			if(state[stf]==0)
				arr[x++]=stf;
			state[stf]=1;
		}
	}
	//for new states
	for(i=0;i<x;i++)
	{
		printf("for %d ---",arr[i]);
		for(j=0;j<2;j++)
		{
			int new=0;
			for(k=0;k<st;k++)
			{
				if(arr[i] & (1<<k))
				{
					int h=pow(2,k);
					if(new==0)
						new=go[h][j];
					new=new|(go[h][j]);
					go[arr[i]][j]=new;
					//printf("\n-------VALUE OF NEW: %d",new);
				}
			}
			if(state[new]==0)
			{
				arr[x++]=new;
				
			}
			state[new]=1;
			
		}
	}
	printf("\n The total number of distinct states in NFA are:\n\n");
	printf("STATE \t 0 \t 1 \n\n");
	for(i=0;i<1000;i++)
	{
		if(state[i]==1)
		{
			if(i==0)
			printf("qo");
			else
			for(j=0;j<st;j++)
			{
				int x=1<<j;
				if(x&i)
				{
					printf("q%d",j);
				}
			}
			printf("\t %d \t %d",go[i][0],go[i][1]);
			printf("\n");
		}
	}
	}
		

