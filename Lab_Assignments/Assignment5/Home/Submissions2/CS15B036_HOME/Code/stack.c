#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>


// create a new stack
stack* stack_new()
{
	stack *temp= (stack*)malloc(sizeof(stack));
	temp->top=(LList*)malloc(sizeof(LList));
	temp->top->head=NULL;
	return temp;
}

// push an element on the stack
void stack_push(stack* stk, int x)
{
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=x;
	if(stk->top->head==NULL)
	{
		stk->top->head=temp;
		return ;
	}
	temp->next=stk->top->head;
	stk->top->head=temp;
}

// pop the top element from the stack
int stack_pop(stack* stk)
{
	int temp;
	if(stk->top->head==NULL)
	return -1;
	if(stk->top->head->next==NULL)
	{	temp=stk->top->head->data;
		stk->top->head=NULL;
		return temp ;
	}
	Node *p=stk->top->head;
	temp=p->data;
	stk->top->head=stk->top->head->next;
	p->next=NULL;
	return temp;
}

	

// Check if stack is empty
bool stack_is_empty(stack* stk)
{
	if(stk->top->head==NULL)
	return true;
	else
	return false;
}

// find the size of the stack
int stack_size(stack* stk)
{
	if(stk->top->head==NULL)
	return 0;
	int count=1;
	Node *p=stk->top->head;
	while(p->next!=NULL)
	{
		p=p->next;
		count++;
	}
	return count;
	
}


// print stack element
void stack_print(stack* stk)
{
	if(stk->top->head==NULL)
	return ;
	Node *p=stk->top->head;
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d ",p->data);
	
}
