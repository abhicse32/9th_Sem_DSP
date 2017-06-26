#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>


stack* stack_new()
{
	stack* s=(stack*) malloc(sizeof(stack));
	s->top= llist_new();
	return s;
}

void stack_push(stack* s, int n)
{
	Node* temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=n;
	if(stack_is_empty(s))
	{
	s->top->head=temp;
	}
	else
	{
		s->top->head->next=temp;
		s->top->head=s->top->head->next;
	}
}

int stack_pop(stack* s)
{
	int x;	
	x=s->top->head->data;
	if(stack_is_empty(s))
	return 0;
	else
	{s->top->head=s->top->head->next;	
	return x;
	}
}


bool stack_is_empty(stack* s)
{
	if(stack_size(s)==0)
	return 1;
	else
	return 0;
}

int stack_size(stack* s)
{

	return llist_size(s->top);
}
void stack_print(stack* s)
{
	Node* a;
	a=s->top->head;
	if(s->top->head != NULL)
	{
		while(a!=NULL)
		{
			printf("%d",a->data);
		}
	}
}
/*int main()
{
	stack* s;	
	s=stack_new();
	stack_print(s);

	
}
*/







































		

