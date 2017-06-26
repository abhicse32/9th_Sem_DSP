#include "queue_using_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// create a new queue
stack* queue_new()
{
	stack* que=stack_new();
	return que;
}

// Check if queue is empty
bool queue_is_empty(stack* que)
{
	return stack_is_empty(que);
}

// add an element to the queue
void enqueue(stack* que, int data)
{
	stack* tempstack=stack_new(); 					//we use a temporary stack to store all the values of que
	while(!stack_is_empty(que))
		stack_push(tempstack,stack_pop(que));
	stack_push(que,data); 							//after emptying que, we push the new element
	while(!stack_is_empty(tempstack))
		stack_push(que,stack_pop(tempstack)); 		//we then pop elements from tempstack and push to que
	free(tempstack);

}

// remove the front element from the queue
int dequeue(stack* que)								//dequeue implements same way as pop
{
	return stack_pop(que);
}



// find the size of the queue
int queue_size(stack* que)
{
	return stack_size(que);
	
}

// print queue element
void queue_print(stack* que)
{
	stack_print(que);
}