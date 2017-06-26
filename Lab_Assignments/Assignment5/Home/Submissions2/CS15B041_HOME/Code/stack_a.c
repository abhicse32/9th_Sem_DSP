#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new()
{
	stack* s;
	s=(stack*)malloc(sizeof(stack));
	s->arr=(int*)malloc(100*sizeof(int));
	
	
	s->top=-1;
	
	return s;
}
void stack_push(stack* s, int d)
{	
	if(stack_is_full(s))
	{
		return ;
	}
	else if(stack_is_empty(s))
	{
		s->top=0;	
		s-arr[top]=d;
	}
	else
	{	
	s->arr[s->top+1]=d;
	s->top++;
	}	
}

int stack_pop(stack* s)
{
	int i;
	if(stack_is_empty(s))
	return 0;
	if(s->top>=0)
	{
	i=s->arr[s->top];
	}
	

	s->top--;
	return i;
}

bool stack_is_empty(stack* s)
{
	if ( stack_size==0)
     	 return 1;
  	 else
     	 return 0;
}
bool stack_is_full(stack* s)
{
	if(s->top == stack_size-1)
	return 1;
	else
	return 0;
}

int stack_size(stack* s)
{	
	int count;
	count=0;
	
	if(s->top ==-1)
	return 0;
	else
	return s->top+1;


}

void stack_print(stack* s)
{	int i;
	if(stack_is_empty(s))
	return ;
	else
	while(!stack_is_empty(s))
	{
		for(i=0;i<=s->top;i++)
		{
	
			printf("%d",s->arr[i]);
		}
	}
}










































