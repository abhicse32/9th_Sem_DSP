#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"
#include "stack.h"
int stack_top(stack* s)
{
	int top;
	top=stack_pop(s);
	stack_push(s,top);
	return top;
}
void nextGreat(int a[],int n)
{
	stack *s;
	s=stack_new();
	//temp=stack_new();
	int i;
	int b[n];
	for(i=0;i<n;i++)
	{
		if(stack_is_empty(s))
		{
			stack_push(s,a[i]);
			a[i]=-1;
		}
		else
		{
			int j=0,k=0;
			while(a[i]>stack_top(s) && k==0)
			{
				j++;
				if(a[i-j]==-1)
				{
					a[i-j]=a[i];
					stack_pop(s);
				}
				if(stack_is_empty(s))
				k=1;
			}
			stack_push(s,a[i]);
			a[i]=-1;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int j,a[n];
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		nextGreat(a,n);
		for(j=0;j<n;j++)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
	}
	return 0;
}
