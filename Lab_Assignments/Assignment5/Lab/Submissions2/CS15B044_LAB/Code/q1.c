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
int checker (char a[],int n)
{
	stack *s;
	s=stack_new();
	int i;
	for(i=0;i<n;i++)
	{
		if(stack_is_empty(s))
		{
			stack_push(s,a[i]);
		}
		else
		{
			if(stack_top(s)==')' || stack_top(s)=='}'  || stack_top(s)==']' )
			return 0;
			else if(stack_top(s)=='(')
			{
				stack_push(s,a[i]);
				if(stack_top(s)=='}'  || stack_top(s)==']')
				return 0;
				else if(stack_top(s)==')')
				{
					stack_pop(s);
					stack_pop(s);
				}
				
			}
			else if(stack_top(s)=='{')
			{
				stack_push(s,a[i]);
				if(stack_top(s)==')'  || stack_top(s)==']')
				return 0;
				else if(stack_top(s)=='}')
				{
					stack_pop(s);
					stack_pop(s);
				}
				
			}
			else if(stack_top(s)=='[')
			{
				stack_push(s,a[i]);
				if(stack_top(s)=='}'  || stack_top(s)==')')
				return 0;
				else if(stack_top(s)==']')
				{
					stack_pop(s);
					stack_pop(s);
				}
				
			}
		}
	}
	if(stack_is_empty(s))
	return 1;
	return 0;
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
		printf("%d\n",checker(a,n));
	}
	return 0;
}
