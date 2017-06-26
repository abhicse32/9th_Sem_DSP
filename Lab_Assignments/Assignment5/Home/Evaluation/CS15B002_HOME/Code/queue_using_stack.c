#include "stack.h"
#include "List.h"
#include "queue_using_stack.h"
#include <stdio.h>
#include <stdlib.h>
void enqueue(stack* q,int n)
{
	stack* q1=stack_new();
	stack_push(q,n);
	Node* b=q->top->head;
	while(b!=NULL)
	{
		stack_push(q1,b->data);
		b=b->next;
	}
	stack_print(q1);
}
void dequeue(stack* q)
{
	stack* q1=stack_new();
	Node* b=q->top->head;
	while(b!=NULL)
	{
		stack_push(q1,b->data);
		b=b->next;
	}
	int x=stack_pop(q1);
	q->top->head = NULL;
	b = q1->top->head ;
	while(b != NULL)
	{
		stack_push(q,b->data);
		b=b->next;
	}
	printf("%d",x);
}
void size(stack* q)
{
	printf("%d",stack_size(q));
}
void empty(stack* q)
{
	printf("%d",stack_is_empty(q));
}

