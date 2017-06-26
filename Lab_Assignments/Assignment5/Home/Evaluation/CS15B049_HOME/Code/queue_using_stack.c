#include "List.h"
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

Node* recR(Node* head)
{
	Node* temp;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	else
	{
		temp = recR(head->next);
		(head->next)->next = head;
		head->next = NULL;
	}	
	
	return temp;
}

void rev(stack* s)
{
	if(stack_is_empty(s)==false)
	{
		(s->top)->head = recR( (s->top)->head );
	}
	
}

void enqueue(stack* s, int data)
{
	if(stack_is_empty(s)==true)
	{
		stack_push(s,data);
	}
	else
	{
		rev(s);
		stack_push(s,data);
		rev(s);
	}		

}

int dequeue(stack* s)
{
	return stack_pop(s);
}

bool queue_is_empty(stack* s)
{
	return stack_is_empty(s);
}

int queue_size(stack* s)
{
	return stack_size(s);
}

void queue_print(stack* s)
{
	stack_print(s);
}


