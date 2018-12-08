#include<stdio.h>
#include <stdlib.h>

int nfa[10][3] = {0};
int dfa[100][3][20]={0};
int states[10],count=0;
int epsclosure[20]={0};
int stack[20][20];
int stackstore[20];
int stacksize=0,stacktop=0,popsize,stacktop1=0;
int statetop0=0,statetop1=0;

//First step
struct stack
{
	int stackarray[20];
	int arrsize;
	struct stack * next;
	
}*top=NULL;
struct stackpop
{
	int stackarray1[20];
	int arrsize1;
	struct stackpop * next1;
	
}*top1=NULL;
struct state0
{
	int statearray0[20];
	int statesize0;
	struct state0 * next2;
	
}*top2=NULL,*head2=NULL;
struct state1
{
	int statearray1[20];
	int statesize1;
	struct state1 * next3;
	
}*top3=NULL,*head3=NULL;

void push(int arr[],int size)
{
	int i;
	struct stack *newnode;
	newnode=(struct stack*)malloc(sizeof(struct stack));
	for(i=0;i<size;i++)
		newnode->stackarray[i]=arr[i];
	newnode->arrsize=size;
	newnode->next=NULL;
	if(top==NULL)
		newnode->next=NULL;
	else
		newnode->next=top;
	top=newnode;
	
	stacktop++;
}
void push1(int arr[],int size)
{
	int i;
	struct stackpop *newnode;
	newnode=(struct stackpop*)malloc(sizeof(struct stackpop));
	for(i=0;i<size;i++)
		newnode->stackarray1[i]=arr[i];
	newnode->arrsize1=size;
	newnode->next1=NULL;
	if(top1==NULL)
		top1=newnode;
	else
	{
		struct stackpop *temp=top1;
		while(temp->next1!=NULL)
		{
			temp=temp->next1;
			
		}
		temp->next1=newnode;
		
	}
	
	
	
	stacktop1++;
}
void push2(int arr[],int size)
{
	int i;
	struct state0 *newnode;
	newnode=(struct state0*)malloc(sizeof(struct state0));
	for(i=0;i<size;i++)
		newnode->statearray0[i]=arr[i];
	newnode->statesize0=size;
	newnode->next2=NULL;
	if(top2==NULL && head2==NULL)
	{
		top2=newnode;
		head2=newnode;
	}
	else
	{
		struct state0*temp=top2;
		while(temp->next2!=NULL)
		{
			temp=temp->next2;
			
		}
		temp->next2=newnode;
		top2=newnode;
		
	}
	
	
	
	statetop0++;
}
void push3(int arr[],int size)
{
	int i;
	struct state1 *newnode;
	newnode=(struct state1*)malloc(sizeof(struct state1));
	for(i=0;i<size;i++)
		newnode->statearray1[i]=arr[i];
	newnode->statesize1=size;
	newnode->next3=NULL;
	if(top3==NULL && head3==NULL)
	{
		top3=newnode;
		head3=newnode;
	}
	else
	{
		struct state1*temp=top3;
		while(temp->next3!=NULL)
		{
			temp=temp->next3;
			
		}
		temp->next3=newnode;
		top3=newnode;
		
	}
	
	
	
	statetop1++;
}
int pop()
{
	int i,size;
	if(top==NULL)
		printf("\nStack is empty");
	else
	{
		struct stack *temp=top ;
		for(i=0;i<temp->arrsize;i++)
			stackstore[i]=temp->stackarray[i];
		size=temp->arrsize;
		top=temp->next;
		
		free(temp);
	}
	stacktop--;
	return(size);
}
void display()
{
	int i;
	
	if(top==NULL)
		;
	else
	{
		struct stack *temp=top;
		while(temp!=NULL)
		{
			
			for(i=0;i<temp->arrsize;i++)
			{
				printf("%d",temp->stackarray[i]);
			}
			printf("\n");
			temp=temp->next;
		}
	
	}
}	
void display1()
{
	int i;
	
	if(top1==NULL)
		;
	else
	{
		struct stackpop *temp=top1;
		while(temp!=NULL)
		{
			
			for(i=0;i<temp->arrsize1;i++)
			{
				printf("%d",temp->stackarray1[i]);
			}
			printf("\t");
			temp=temp->next1;
		}
	
	}
}	
void display2()
{
	int i;
	
	if(head2==NULL)
		;
	else
	{
		struct state0 *temp=head2;
		while(temp!=NULL)
		{
			
			for(i=0;i<temp->statesize0;i++)
			{
				printf("%d",temp->statearray0[i]);
			}
			printf("\t");
			temp=temp->next2;
		}
	
	}
}	

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
void split(int num)
{
	int rem,i;
	while(num>0)
		{			
			int flag=0;			
			rem=num%10;
			for(i=0;i<count;i++)
			{
				if(rem==epsclosure[i])
					flag=1;			
			}
			if(flag==0)
			{
				epsclosure[i]=rem;
				count++;
				
			}
			num=num/10;
		}
}
void epsilonclosure(int Q)
{
	int i,eps,temp;	
	epsclosure[0]=Q;
	count=1;
	if(nfa[Q][2]!=-1)
	{
		eps=nfa[Q][2];	
		split(eps);
		for(i=1;i<count;i++)
		{
			temp=epsclosure[i];			
			if(nfa[temp][2]!=-1)
			{
				split(nfa[temp][2]);
			}
		}  
		
		
	}
	bubblesort(&epsclosure[0],count);
}
void arraystore(int arr[])
{
		
	int i,j,temp1,flag1,temp2,flag2,rem,num,k,count0=0,count1=0,s;
	int state0arr[20]={-2};
	int state1arr[20]={-2};
	
	
	
	for(j=0;j<top->arrsize;j++)
	{
		
		flag1=0,flag2=0;		
		temp1=arr[j];
		
		//state0		
		if(nfa[temp1][0]!=-1)
		{
			num=nfa[temp1][0];			
			if(num>9)
			{
				while(num>0)
				{				
					rem=num%10;
					for(i=0;i<count0;i++)
					{
						if(state0arr[i]==rem)
							flag1=1;	
					}
					if(flag1==0)
					{
						state0arr[count0]=rem;	
						count0++;
					}
					num=num/10;
				}	
				
			}
			else
			{			
				for(i=0;i<count0;i++)
				{
					if(state0arr[i]==num)
						flag1=1;	
				}
				if(flag1==0)
				{
					state0arr[count0]=num;	
					count0++;
				}
				
			}
			
			
			
		}
		
		
		//state1
		if(nfa[temp1][1]!=-1)
		{	
			num=nfa[temp1][1];			
			if(num>9)
			{
				while(num>0)
				{				
					rem=num%10;
					for(i=0;i<count1;i++)
					{
						if(state1arr[i]==rem)
							flag2=1;	
					}
					if(flag2==0)
					{
						state1arr[count1]=rem;	
						count1++;
					}
					num=num/10;
					
				}	
				
			}			
		
			else
			{				
				for(i=0;i<count1;i++)
				{
					if(state1arr[i]==nfa[temp1][1])
						flag2=1;	
				}
				if(flag2==0)
				{
					state1arr[count1]=nfa[temp1][1];	
					count1++;
				}
				
			}
			
			
			
			
		}
		
		
		
	}	
	for(i=0;i<count0;i++)
	{
		count=0;
		epsilonclosure(state0arr[i]);
		for(j=0;j<count;j++)
		{
			flag1=0;						
			for(k=0;k<count0;k++)
			{
				if(epsclosure[j]==state0arr[k])
				{	
					flag1=1;
				}

    			}
			if(flag1==0)
			{
				state0arr[count0]=epsclosure[j];
				count0++;
			}
		}	
		
				
	}
	
	for(i=0;i<count1;i++)
	{
		
		count=0;
		epsilonclosure(state1arr[i]);
		
		for(j=0;j<count;j++)
		{
			flag1=0;						
			for(k=0;k<count1;k++)
			{
				if(epsclosure[j]==state1arr[k])
				{
					flag1=1;
					break;
				}
			}
			if(flag1==0)
			{
				state1arr[count1]=epsclosure[j];
				count1++;
			}
		}	
		
	}
	bubblesort(&state0arr[0],count0);
	bubblesort(&state1arr[0],count1);
	/*if(count0==0)
		state0arr[0]=21312;
	else if(count1==0)
		state1arr[0]=123122;
	*/
	push2(state0arr,count0);
	push3(state1arr,count1);
	count0=0;
	count1=0;

}
int arraycomp(int arr1[],int btn ) //if result==1 then arrays equal
{
	int i,j,flag;	
	int size1,size2,result=0;
	if(btn==1)
		size2=top2->statesize0;
	else
		size2=top3->statesize1;
	
	if(size1!=size2)
	{
		
		if(top1==NULL)
			printf("\nStack1 empty");
		else
		{
			
			struct stackpop *temp=top1;
			while(temp!=NULL)
			{
				flag=0;
				
				for(i=0;i<temp->arrsize1;i++)
				{
					if(arr1[i]!=temp->stackarray1[i])
					{	
						flag=1;
						break;
					}
				}
				temp=temp->next1;
			}
			if(flag==1)
			{
				result=1;
			}
		}
	}
	return(result);
}


void main()
{
	int state,initial,final,rules,i,j,k,c,eps,value,n,size,iter=0;
	int temp0,temp1,tempeps,newstate=1,rowiter=0;
	printf("\n\nEnter the number of states:");
	scanf("%d",&state);
	
	for(i=0;i<state;i++)
		states[i]=i;

	printf("\nState numbers from 0 to %d\n", state-1);

	printf("Enter initial state:");
	scanf("%d",&initial);

	printf("Enter the final state:");
	scanf("%d",&final);
	
	for(i=0;i<state;i++)
	{
		printf("\nTransition when 0 applied on %d:",i);
		scanf("%d",&temp0);
		
		nfa[i][0]=temp0;
		

		printf("\nTransition when 1 applied on %d:",i);
		scanf("%d",&temp1);
		
		nfa[i][1]=temp1;
		

		printf("\nTransition when epsilon applied on %d:",i);
		scanf("%d",&tempeps);
		
		nfa[i][2]=tempeps;
		
		
	}
	//Printing nfa table
	printf("\n\n\n\nState\t0\t1\tEpsilon\n");
	printf("--------------------------\n");
	for(i=0;i<state;i++)
	{	
		printf("%d\t",i);		
		for(j=0;j<3;j++)
		{
			printf("%d\t",nfa[i][j]);
		}
		printf("\n");
	}
	//Printing epsilon closure of all states
	printf("\n\n\nFinding epsilon closure for all states:");
	for(i=0;i<state;i++)
	{
		epsilonclosure(i);
		printf("\nEpsilon closure for %d is:",i);
		for(j=0;j<count;j++)
			printf("%d ",epsclosure[j]);
		printf("\n");

	}	
	//Third step
	
		count=0;
		epsilonclosure(0);
		
		push(epsclosure,count);
		
		for(k=0;k<count;k++)
		{
			dfa[rowiter][0][k]=epsclosure[k];
							
		}
		
		
		
		
		while(stacktop!=0)
		{				
			
			
			arraystore(top->stackarray);
			popsize=pop();
			push1(stackstore,popsize);
			
			/////////////////////////
			for(k=0;k<popsize;k++)
			{	
				dfa[rowiter][0][k]=stackstore[k];
							
			}
			
			
			
			for(i=0;i<top2->statesize0;i++)
				dfa[rowiter][1][i]=top2->statearray0[i];
			
			for(i=0;i<top3->statesize1;i++)
				dfa[rowiter][2][i]=top3->statearray1[i];
			
			
			
			
			for(i=1;i<=2;i++)
			{
				if(dfa[rowiter][i][0]!=-2)
				{
					value=arraycomp(dfa[rowiter][i],i);
				//printf("value:%d",value);
					if(value==1)
					{
						if(i==1)
							size=top2->statesize0;
						else
							size=top3->statesize1;	
						
						push(dfa[rowiter][i],size);
						
					}
				
				}
				
			}
			
			
			rowiter++;
			
		}
		
	
	
	printf("\n\n\nDFA table\n");
	struct stackpop *tem=top1;
	struct state0 *tem1=head2;
	struct state1 *tem2=head3;
	//printf("\nrowiter:%d",rowiter);
	printf("\n\nState\t0\t1\n");
	printf("--------------------------\n");
	for(i=0;i<rowiter;i++)
	{	
			
			for(k=0;k<tem->arrsize1;k++)
				printf("%d",dfa[i][0][k]);
			
			tem=tem->next1;
			printf("\t");
			for(k=0;k<tem1->statesize0;k++)
				printf("%d",dfa[i][1][k]);
			printf("\t");
			tem1=tem1->next2;
			for(k=0;k<tem2->statesize1;k++)
				printf("%d",dfa[i][2][k]);
			printf("\t");
			tem2=tem2->next3;
			printf("\n");
			
	}	
	
}
