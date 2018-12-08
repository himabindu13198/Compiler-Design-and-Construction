/* AUTHOR: HIMA BINDU
NFA DFA
*/
#include<stdio.h>
#include<string.h>

int stackcount=0;
struct trans
{
	char sym;
	int tostate[10];
	int numtrans;
};

struct DFA
{
	int no;
	int dfastate[10];
	int len;
	struct trans translist[10];
}DFAStates[50];
int topA=-1,topB=-1;
struct stackA
{
	int stacka[20];
	int lena;
	
	
}Stcka[20];

struct stackb
{
	int stackb[20];
	int lenb;
	
}Stckb[20];

void pushA(int arr[],int len)
{
	int i;
	if(topA==20)
	{
		printf("\nStack is full");
	}
	else
	{	
		topA++;
		for(i=0;i<len;i++)
		{
			Stcka[topA].stacka[i]=arr[i];
		}
		Stcka[topA].lena=len;
		stackcount++;
	}
}

void pushB(int arr[],int len)
{
	int i;
	if(topB==20)
	{
		printf("\nStack is full");
	}
	else
	{	
		topB++;
		for(i=0;i<len;i++)
		{
			Stckb[topB].stackb[i]=arr[i];
		}
		Stckb[topB].lenb=len;
		
	}
}

int  popA()
{
	
	int len;
	if(topA==-1)
		printf("\nStack is Empty");
	else
	{
		len=Stcka[topA].lena;
		topA--;
		stackcount--;
	}
	
	return len;
}

struct state
{
	int no;
	struct trans translist[10];
};
struct state States[50];
char input[20];
int nos,inp,count=0;
int epsclosure[10];
int no=0;

void  bubblesort(int *arr1,int size)
{
	int i,j,k,temp;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(arr1[j+1] < arr1[j])
			{
				temp=arr1[j];
				arr1[j]=arr1[j+1];
				arr1[j+1]=temp;
				arr1[j+1]=temp;
				
			}
		}
			
	}
}
int present(int st)
{
	int i,flag=0;
	for(i=0;i<count;i++)
	{
		if(epsclosure[i]==st)
		{	
			flag=1;
			
		}	
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
void epsilonclosure(int init)
{
	int i,j,k,ret;
	epsclosure[0]=init;
	count=1;
	if(States[init].translist[inp].tostate[0]!=-1)
	{
		for(i=0;i<States[init].translist[inp].numtrans;i++)
		{
			ret=present(States[init].translist[inp].tostate[i]);
			if(ret!=0)
				epsclosure[count++]=States[init].translist[inp].tostate[i];
		
		}
		for(j=1;j<count;j++)
		{
			if(States[epsclosure[j]].translist[inp].tostate[0]!=-1)
			{
				
				for(i=0;i<States[epsclosure[j]].translist[inp].numtrans;i++)
				{
					ret=present(States[epsclosure[j]].translist[inp].tostate[i]);
					if(ret!=0)
						epsclosure[count++]=States[epsclosure[j]].translist[inp].tostate[i];
		
				}
			}
		}
	}
	bubblesort(&epsclosure[0],count);
}
void displaystackA()
{
	int i=topA,j;
	printf("\nStackA");
	while(i!=-1)
	{
		printf("\t");
		for(j=0;j<Stcka[i].lena;j++)
		{
			printf("%d",Stcka[i].stacka[j]);
		}
		
		i--;
	}
	
}
void displaystackB()
{
	int i=0,j;
	printf("\nStackB");
	while(i<=topB)
	{
		printf("\t");
		for(j=0;j<Stckb[i].lenb;j++)
		{
			printf("%d",Stckb[i].stackb[j]);
		}
		
		i++;
	}
	
}

void display()
{
	int i,j,k;
	printf("\n\nState\t");
	for(i=0;i<inp+1;i++)
		printf("%c\t",input[i]);
	printf("\n");
	for(i=0;i<nos;i++)
	{
		printf("%d\t",States[i].no);
		for(j=0;j<inp+1;j++)
		{
			for(k=0;k<States[i].translist[j].numtrans;k++)
			{	
				printf("%d",States[i].translist[j].tostate[k]);
			}
			printf("\t");
		}
		printf("\n");
		
	}
	
}

	

int arraycomp(int arr1[],int length)
{
	int i,j,flag,temp,ret;
	
	for(i=0;i<topB+1;i++)
	{
		
		flag=0;
		if(length!=Stckb[i].lenb)
		{
			
			flag=1;
		}
		else
		{
			
			for(j=0;j<length;j++)
			{
				if(arr1[j]!=Stckb[i].stackb[j])
				{	flag=1;
					
					break;
				}
				else
				{	
					flag=0;
					
				}	
			}
			
		}
		if(flag==1)
		{
			ret=0;
		}
		else if(flag==0)
		{
			ret=1;
			break;
			
			
		}	
		
	}
	
	return ret;
	
			
}
void arraystore()
{
	int i,j,k,counter,flag=0,n,flageps,tem,p,len,len1,len2,h;
	while(no!=-1)
	{
	for(j=0;j<inp;j++)
	{
		counter=0;
		for(i=0;i<Stcka[topA+1].lena;i++)
		{
			
			for(k=0;k<States[DFAStates[no].dfastate[i]].translist[j].numtrans;k++)
			{
				if(counter==0)
				{
					DFAStates[no].translist[j].tostate[counter++]=States[DFAStates[no].dfastate[i]].translist[j].tostate[k];
					
				}
				else
				{
					for(n=0;n<counter;n++)
					{
						if(States[DFAStates[no].dfastate[i]].translist[j].tostate[k]==DFAStates[no].translist[j].tostate[n])
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						DFAStates[no].translist[j].tostate[counter++]=States[DFAStates[no].dfastate[i]].translist[j].tostate[k];
						
					}
				}
			}
		}
		DFAStates[no].translist[j].numtrans=counter;	
		
	}
	for(j=0;j<inp;j++)
	{
		counter=DFAStates[no].translist[j].numtrans;
		for(i=0;i<DFAStates[no].translist[j].numtrans;i++)
		{
			epsilonclosure(DFAStates[no].translist[j].tostate[i]);
			
			
			for(tem=0;tem<count;tem++)
			{
				flageps=0;
				
				for(p=0;p<DFAStates[no].translist[j].numtrans;p++)
				{	
					
					if(epsclosure[tem]==DFAStates[no].translist[j].tostate[p])
					{	
						flageps=1;
						break;
					}
				}	
				if(flageps==0)
				{	
					
					DFAStates[no].translist[j].tostate[counter++]=epsclosure[tem];
					
				}	
			}
			
			
		}
		DFAStates[no].translist[j].numtrans=counter;	
		bubblesort(&DFAStates[no].translist[j].tostate[0],DFAStates[no].translist[j].numtrans);
		
		
		
		
		
		if(DFAStates[no].translist[j].tostate[0]!='\0')
		{
			
			
			pushA(DFAStates[no].translist[j].tostate,DFAStates[no].translist[j].numtrans);
			
			
		
		}	
		
	}
	 break;
	}
}


void main()
{
	int i,j,start,final[10],nof,k,ans=1,counter,n,flag=0,len,temp,h;
	char c;
	int len1;
	
	printf("\nEnter the no. of states:");
	scanf("%d",&nos);
	
	for(i=0;i<nos;i++)
	{
		States[i].no=i;	
	}
	
	printf("\nEnter the start state:");
	scanf("%d",&start);
	
	printf("\nEnter the num of final states:");
	scanf("%d",&nof);
	
	printf("\nEnter the final states:");
	
	for(i=0;i<nof;i++)
	{
		scanf("%d",&final[i]);
	}
	
	printf("\nEnter the num of input symbols:");
	scanf("%d",&inp);
	c=getchar();
	printf("\nEnter the input symbols:");
	for(i=0;i<inp;i++)
	{
		printf("\nNUM(%d,%d):",i,inp);	
		scanf("%c",&input[i]);
		c=getchar();
		printf("\n%d:%c",i+1,input[i]);
	}
	input[i]='e';
	/*for(i=0;i<inp+1;i++)
		printf("%c\t",input[i]);
	printf("\nfirst input :%c",input[0]);*/
	printf("\nEnter the transitions(-1 to stop):");
	for(i=0;i<nos;i++)
	{
		for(j=0;j<=inp;j++)
		{
			k=0;
			ans=1;
			States[i].translist[j].sym=input[j];
			while(ans=1)
			{
				printf("\nmove(%d,%c):",i,input[j]);
				scanf("%d",&States[i].translist[j].tostate[k]);
				if(States[i].translist[j].tostate[k]==-1)
				{
					States[i].translist[j].numtrans=k;
					ans=0;
					break;
				}
				k++;
			}	
		}
	}
	printf("\n\n\nNFA Transition");
	display();		//to test display
	
	//Conversion
	//----------------------------------------------------------------------------
	
	epsilonclosure(start);
	
	/*for(i=0;i<count;i++)
	{
		printf("\nepsclosure:%d",epsclosure[i]);
	}*/
	
	
	DFAStates[0].len=count;
	for(i=0;i<count;i++)
	{
		DFAStates[0].dfastate[i]=epsclosure[i];
	}
	pushA(DFAStates[0].dfastate,DFAStates[0].len);
	len=popA();
	pushB(Stcka[topA+1].stacka,len);
	
	arraystore();
	//displaystackA();
	
	
	while(stackcount>0)
	{
		
		
		len1=popA();	
		
		temp=arraycomp(Stcka[topA+1].stacka,len1);
		
		
		
		if(temp!=1)
		{
			no++;
			
			
			
			pushB(Stcka[topA+1].stacka,len1);
			
			
			
			for(i=0;i<len1;i++)
			{
				DFAStates[no].dfastate[i]=Stcka[topA+1].stacka[i];
				
			}
			DFAStates[no].len=len1;
			
			arraystore();
			
			
			
		}
		
		
	}
	
	
	printf("\n\n\nDFA Transition\n");
	printf("\n\nState\t");
	for(i=0;i<inp;i++)
		printf("%c\t",input[i]);
	printf("\n\n\n");
	for(h=0;h<=no;h++)
	{
	for(i=0;i<DFAStates[h].len;i++)
	{
		printf("%d",DFAStates[h].dfastate[i]);
	}
	printf("\t");
	
	
		for(j=0;j<inp;j++)
		{
		
			for(k=0;k<DFAStates[h].translist[j].numtrans;k++)
			{
				printf("%d",DFAStates[h].translist[j].tostate[k]);
			}	
			printf("\t");
		}
		printf("\n");
		
	
	}	
	
	
}
