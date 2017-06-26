
#include "stack.h"
#include <stdbool.h>
#include "queue_using_stack.h"

// create a new queue
stack* queue_new()
{
	stack *stk=stack_new();
	return stk;
}

// add an element to the queue
void enqueue(stack* stk, int data)
{

	stack* temp = stack_new();

	while(! stack_is_empty(stk) )
	{
		int val = stack_pop(stk);
		stack_push(temp, val);
	}

	stack_push(stk, data);

	while(! stack_is_empty(temp) )
	{
		int val = stack_pop(temp);
		stack_push(stk, val);
	}

}

// remove the front element from the queue
int dequeue(stack* stk)
{
	int val = stack_pop(stk);
	return val;
}

// Check if queue is empty
bool queue_is_empty(stack* stk)
{
	return stack_is_empty(stk);
}

// find the size of the queue
int queue_size(stack* stk)
{
	return stack_size(stk);
}

// print queue element
void queue_print(stack* stk)
{
	stack_print(stk);
}