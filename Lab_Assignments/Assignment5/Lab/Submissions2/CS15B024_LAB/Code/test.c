#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
	int top;
	char arr[];
}stack;
stack * stack_new();
int size_of_stack(stack *s);
void stack_push(stack *s,char n);
void print(stack * s);
char stack_pop(stack * s);
int isempty(stack * s);
void main()
{
	stack * a =stack_new();	
	 stack_push(a,'A');
	print(a);
	char s=stack_pop(a);
	//printf("%c\n",s);
	print(a);
	char b=stack_pop(a);
	print(a);
	//int c=size_of_stack(a);
	//printf("%d",c);
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

stack * stack_new()
{
	stack* a=(stack*)malloc(sizeof(stack));
	char * arr=(char *)malloc(sizeof(char));
	a->top=-1;
	return a;
}


void stack_push(stack *s,char n)
{
	s->arr[++s->top]=n;

}
void print(stack * s)
{
	int i=0;
	int si=size_of_stack(s);
	while(i<si)
	{
		printf("%c ",s->arr[i]);
		i++;
	}

}

int size_of_stack(stack *s)
{
	return((s->top)+1);
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
}
