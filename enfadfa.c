#include<stdio.h>
#include<string.h>
#include<math.h>

/*
Possible inputs and their representations:
 
Alphabets - 0
Digits - 1
; - 2
Epsilon - 3
< - 4
= - 5
> - 6
! - 7
. - 8
{ - 9
} - 10
( - 11
) - 12
[ - 13
] - 14

*/

//int find_epsilon_closure(int);
void setnfa(int,char,int);
void printnfa();

int nfa[1000][100][1000] = {0};
//int state[1000] = {0};
int go[1000][100] = {0};
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
	printf("\n\nEnter the number of final states:");
	scanf("%d",&fin);
	printf("\nEnter the final states:");
	for(i=0;i<fin;i++)
	{
		scanf("%d",&f[i]);
	}
	int p,r,rel;
	char q;
	printf("\n Enter the number of rules according to the NFA:");
	scanf("%d",&rel);
	printf("\n\n Define translation rules as \"initial-state input-symbol(write 3 for epsilon) final-state\" \n");
	
	for(i=0;i<rel;i++)
	{
		scanf("%d %c %d",&p,&q,&r);
		setnfa(p,q,r);
	}
	printf("\n Enter initial state:");
	scanf("%d",&in);
	printnfa();

}


void setnfa(int a,char b,int c)
{

if(isalpha(b)) nfa[a][0][c]=1;
else if(b==';') nfa[a][2][c]=1;
else if(b=='3') nfa[a][3][c]=1;
else if(isdigit(b)) nfa[a][1][c]=1;
else if(b=='<') nfa[a][4][c]=1;
else if(b=='=') nfa[a][5][c]=1;
else if(b=='>') nfa[a][6][c]=1;
else if(b=='!') nfa[a][7][c]=1;
else if(b=='.') nfa[a][8][c]=1;
else if(b=='{') nfa[a][9][c]=1;
else if(b=='}') nfa[a][10][c]=1;
else if(b=='(') nfa[a][11][c]=1;
else if(b==')') nfa[a][12][c]=1;
else if(b=='[') nfa[a][13][c]=1;
else if(b==']') nfa[a][14][c]=1;

}

void printnfa()
{
int i,j,k;
for(i=0;i<1000;i++)
	for(j=0;j<100;j++)
		for(k=0;k<1000;k++)
			if(nfa[i][j][k]==1)printf("\n %d - %d - %d ", i,j,k);
}
/* int find_epsilon_closure(int a)
{
int clos;
clos=go[(int)pow(2,a)][3];
while(clos!=0)
{
	clos=clos|go[(int)pow(2,clos)][3]; */
