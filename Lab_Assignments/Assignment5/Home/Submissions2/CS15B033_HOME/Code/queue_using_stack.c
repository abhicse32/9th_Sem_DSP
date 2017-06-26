#include "queue_using_stack.h"
#include <stdlib.h>
#include <stdio.h>

queue* stack_new()
{
	queue *new = malloc(sizeof(queue));
	new->front = new->rear = llist_new();
	return new;
}

// push an element on the stack
void stack_push(queue* que, int elm)
{
	Node *new = node_new(elm);
	if( que->front->head == NULL)
		que->front->head = que->rear->head = new;
	else
	{
		que->rear->head->next = new;
		que->rear->head = new;
	}
}

// pop the top element from the stack
int stack_pop(queue* que)
{
	if( llist_size(que->front) != 0)
	{
		int x = que->front->head->data;
		Node *new = que->front->head;
		que->front->head = new->next;
		free(new);
		return x;
	}
	return 0;
}

// Check if stack is empty
bool stack_is_empty(queue* que)
{
	if(llist_size(que->front) == 0)
		return true;
	return false;
}

// find the size of the stack
int stack_size(queue* que)
{
	return llist_size(que->front);
}

// print stack element
void stack_print(queue* que)
{
	llist_print(que->front);
}