#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
stack* stack_new()
{
	stack* a;
	a = (stack*)malloc(sizeof(stack));
	a->top = (LList*)malloc(sizeof(LList));
	(a->top)->head = NULL;
	return a;
}
void stack_push(stack* a, int n)
{
	Node* b=(Node*)malloc(sizeof(Node));
	b->data = n;
	b->next = (a->top)->head;	
	(a->top)->head = b;
}
int stack_pop(stack* a)
{
	if(a->top->head == NULL) return INT_MIN;
	int x = (a->top)->head->data;
	(a->top)->head = ((a->top)->head)->next;
	return x;
}
bool stack_is_empty(stack* a)
{
	if((a->top)->head == NULL) return 1;
	else return 0;
}
int stack_size(stack* a)
{
	return llist_size(a->top);
}
void stack_print(stack* a)
{
	llist_print(a->top);
}
