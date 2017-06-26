// Defines functions defined in stack_using_queue.h
// Author : Milind Srivastava
// Date : 16 Sep 2016

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack_using_queue.h"

// creates new stack
queue* stack_new()
{
	queue* temp = queue_new();
	return temp;
}

//push element on to stack
void stack_push(queue* qu, int x)
{
	if(queue_size(qu) == 0)
	{
		enqueue(qu, x);
		return;
	}
	int i = 0;
	int size = stack_size(qu);
	int* arr = (int*)malloc(size * sizeof(int));
	while(!stack_is_empty(qu))
	{
		arr[i] = dequeue(qu);
		i++;
	}
	enqueue(qu, x);
	i = 0;
	while(i < size)
	{
		enqueue(qu, arr[i]);
		i++;
	}
}

// pop element form stack
int stack_pop(queue* qu)
{
	if(queue_size(qu) == 0)
	{
		return INT_MIN;
	}
	return dequeue(qu);
}

// checking if stack is empty
bool stack_is_empty(queue* qu)
{
	return queue_is_empty(qu);
}

// return size of stack
int stack_size(queue* qu)
{
	return queue_size(qu);
}

// print stack
void stack_print(queue* qu)
{
	queue_print(qu);
}