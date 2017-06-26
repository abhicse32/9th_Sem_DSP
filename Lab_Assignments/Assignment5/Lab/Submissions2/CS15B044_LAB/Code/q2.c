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
int counter (char a[],int n)
{
	if(n%2==1)
	return -1;
	stack *s;
	s=stack_new();
	int i;
	int count=0;
	for(i=0;i<n;i++)
	{
		if(stack_is_empty(s))
		{
			stack_push(s,a[i]);
		}
		else
		{
			if(stack_top(s)=='}')
			{
				stack_pop(s);
				stack_push(s,'{');
				i--;
				count++;
			}
			else 
			{
				stack_push(s,a[i]);
				if(stack_top(s)=='}')
				{
					stack_pop(s);
					stack_pop(s);
				}
			}		
		}
	}
	while(!stack_is_empty(s))
	{
		stack_pop(s);
		stack_pop(s);
		count++;
	}
	return count;
}
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
		char a[1000];
		scanf("%s",a);
		int n=strlen(a);
		printf("%d\n",counter(a,n));
	}
	return 0;
}
