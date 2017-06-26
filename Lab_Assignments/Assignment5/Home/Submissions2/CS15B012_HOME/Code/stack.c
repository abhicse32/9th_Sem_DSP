#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new()
{
	stack* new;
	new=(stack*)malloc(sizeof(stack));

	/* pointing the top to NULL*/	
	new->top=llist_new();
	return new;
}

void stack_push(stack* stk, int data)
{
llist_prepend(stk->top, data );
}

int stack_pop(stack* stk)
{
	if(!stack_is_empty(stk))
	{
		int x;
		x=stk->top->head->data;
		Node* temp;
		temp=stk->top->head;
		stk->top->head=temp->next;		
		return x;		
	}
}

bool stack_is_empty(stack* stk)
{
/* if the stk->top is pointed to NULL then it is empty*/
	if(stk->top->head==NULL)
	return 1;
	else
	return 0;
}

int stack_size(stack* stk)
{	/* create a pointer which moves from top to bottom*/
	int count=0;
	Node* cur;
	cur= stk->top->head;
	while(cur!=NULL)
	{	
		cur=cur->next;		
		count++;
	}
return count;	
}

void stack_print(stack* stk)
{  
	stack* new;
	new=stack_new();
	
	while(!stack_is_empty(stk))
	{
		int x;
		x=stack_pop(stk);
		printf("%d ",x);
		stack_push(new,x);										
	}
	//printf("\n");
	while(!stack_is_empty(new))
	{
		int x;
		x=stack_pop(new);
		stack_push(stk,x);	
	}	
}
