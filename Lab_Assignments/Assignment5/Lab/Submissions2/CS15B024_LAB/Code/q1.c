#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include "List.h"

#define MAX 1000
/*
typedef struct Stack
{
	int top;
	char arr[];
}stack;
int size_of_stack(stack *s);

void print(stack * s)
{
	int i=0;
	int si=size_of_stack(s);
	while(i<si)
	{
		printf("%c",s->arr[i]);
		i++;
	}

}
stack * stack_new()
{
	stack* a=(stack*)malloc(sizeof(stack));
	//char * arr=(char *)malloc(sizeof(char));
	a->top=-1;
	return a;
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
	if(isempty(s)==1)
	{
		return 0;
	}
	else
	{
	char x;
	x=s->arr[s->top--];
	return x;
	}
}*/
int parmatch(stack *s)
{
	stack* a=stack_new();
	//a->top=-1;
	char x;
	char y;
	char z;
	x=stack_pop(s);
	stack_push(a,x);
	int chk=stack_is_empty(s);
	//printf("%d",chk);
	while(stack_is_empty(s)!=1)
	{
		/*print(s);
		printf("\n");
		print(a);*/
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
		else if(y==')')
		{
			z=stack_pop(s);
			if(z=='(')
			{
				stack_pop(a);
			}
			else
			{
				stack_push(a,z);
			}
		}
		else if(y==']')
		{
			z=stack_pop(s);
			if(z=='[')
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
	/*printf("\n");	
	stack_print(s);
	printf("\n");
	stack_print(a);*/	
	}
	if(stack_is_empty(a)==1)
	{
		return 1;
	}
	else return 0;
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
		/*stack * temp=stack_new();
		while(isempty(s)==0)
		{
		
			char x=stack_pop(s);
			stack_push(temp,x);
		}*/
		//s->top=size_of_stack(s)-1;
		//print(s);
		printf("%d",parmatch(s));
		printf("\n");
	}
	return 0;
}	
		
			
		
		
		
		
		
		
		
		


		

