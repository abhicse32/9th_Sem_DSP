#include<stdio.h>
#include"ORIList.c"
#include<stdlib>

  

stack* queue_new()
{	stack* s;
	s = stack_new();
	return s;
}
	

void enqueue(stack* s, int x)
{
   stack_push(s,x);
}
  

int dequeue(stack* s)
{
  stack* s1;
	s1=stack_new();
	int x;
	if(stack_size==0)
	return -1;
	while(!stack_is_empty(s))
	{
		x=stack_pop(s);
		stack_push(s1,x);
	}
	int val=stack_pop(P);
	while(!stack_is_empty(s1))
	{
		x=stack_pop(s1);
		stack_push(s,x);
	}
	return val;
}

  
bool queue_is_empty(stack* s)
{
	if(stack_size==0)
	return 1;
	else
	return 0;
}


int queue_size(stack* s)
{ 
	
	
	return stack_size(s);
	
}




void queue_print(stack* s)
{	
	stack* s1;
	s1=stack_new();
	int x;
	if(stack_size(s)==0)
	return;
	while(!stack_is_empty(s))
	{
		x=stack_pop(s);
		stack_push(s1,x);
	}
	stack_print(s1);
	while(!stack_is_empty(s1))
	{
		x=stack_pop(s1);
		stack_push(s,x);
	}
}


