#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include "stack.h"
#define MAX 1000
void print_NGE(int p[1000],int n)
{
	int i=0;
	stack *a=stack_new();
	stack *b=stack_new();
	stack *c=stack_new();
	int x;
	int y;
	stack_push(a,i);
	for(i=1;i<n;i++)	//take three stacks a,b,c 
	{
		if(stack_is_empty(a)!=1)	//if a is empty push an index into it now compare elements of a with p[x] and if p[i] greater
		{				//then push x into b and p[i] into c keep doing till the end of array 
			x=stack_pop(a);
			while(p[x]<p[i])
			{
				stack_push(b,x);
				stack_push(c,p[i]);
				if(stack_is_empty(a)==1)
				break;
				x=stack_pop(a);
			}
			if(p[x]>=p[i])
			{
				stack_push(a,x);
			}
		}
		stack_push(a,i);
	}
	while(stack_is_empty(a)!=1)
	{
		int m;
		m=stack_pop(a);
		stack_push(b,m);
		stack_push(c,-1);
	}
	int q[n];
	while(stack_is_empty(b)!=1 || stack_is_empty(c)!=1)
	{
		i=stack_pop(b);
		q[i]=stack_pop(c);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",q[i]);
		
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	int j;
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int p[n];
		for(j=0;j<n;j++)
		{
			scanf("%d",&p[j]);
		}
		print_NGE(p,n);
		printf("\n");
	}		
}
	
	
	
	
	
	
			
			
			
			
		
			
		
	
	
	
