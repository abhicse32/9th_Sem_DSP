//Header file created for implementing stack using functions specified for queue data structure.


#include "List.h"
#include "stack.h"



//create a new stack
stack* queue_new();

// add an element in the queue
void queue_print(stack*);

// remove the first element from the queue
int dequeue(stack*);

// Check if queue is empty
bool queue_is_empty(stack*);

// find the size of the queue
int queue_size(stack*);

// print queue element
void queue_print(stack*);
