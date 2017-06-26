#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include "List.h"
#define MAX 1000
/*typedef struct_Stack
{
	int top;
	char arr;
}stack;
void stack_new()
{
	stack* a=(stack*)malloc(sizeof(stack));
	a->top=-1;
	
}
int isempty(stack* s)
{
	if(s->top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int size_of_stack(stack *s)
{
	return((s->top)+1);
}
void stack_push(stack *s,char n)
{
	s->arr[++s->top]=n;
}
char stack_pop(stack *s)
{
	x=s->arr[s->top--];
	return x;
}*/
int reversal(stack*s)
{
	int p;
	p=stack_size(s);
	if(p%2==1)
	{
		return -1;
	}
	else 
	{
		stack* a=stack_new();
		char x;
		char y;
		char z;
		int chk=stack_is_empty(s);
		while(stack_is_empty(s)!=1)
		{
			if(stack_is_empty(a)==1)
			{
			x=stack_pop(s);
			stack_push(a,x);
			}
			y=a->top->head->data;
			if(y=='}')
			{
				z=stack_pop(s);
				if(z=='{')
				{
				stack_pop(a);
				}
				else
				{
				stack_push(a,z);
				}
			}
			else
			{
				z=stack_pop(s);
				stack_push(a,z);
			}
		}
		if(stack_is_empty(a)==1)
		{
			return 0;
		}
		else 
		{
			int c1=0;
			int c2=0;
			int c=0;
			while(stack_is_empty(a)!=1)
			{
				char m;
				m=stack_pop(a);
				if(m=='{')
				{
					c1++;
				}
				else if(m=='}')
				{
					c2++;
				}
			}
			if(c1%2==0 && c2%2==0)
			{
				c=(c1/2)+(c2/2);
			}
			else if(c1%2==1 && c2%2==1 )
			{
				c=(c1/2)+(c2/2)+2;
			}
			else 
			{
				c=(c1/2)+(c2/2)+1;
			}
			return c;
		}
}
}
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	int j=0;
	for(i=0;i<t;i++)
	{
		j=0;
		stack *s=stack_new();
		char a[1000];
		scanf("%s",a);
		while(a[j]!='\0')
		{
			stack_push(s,a[j]);
			j++;
			
		}
		printf("%d",reversal(s));
		printf("\n");
	}
	return 0;
}	
		
			
				
					
	
