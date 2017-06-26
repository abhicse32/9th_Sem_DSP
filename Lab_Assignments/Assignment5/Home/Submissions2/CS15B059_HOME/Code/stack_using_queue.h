#include"queue.h"

//to create a new stack
queue* stack_new();

//to add an element at the front of a queue
void stack_push(queue* que, int elm);

//to remove the first element of a queue
int stack_pop(queue * que);

//to check if the queue is empty
bool stack_is_empty(queue* que);

//to return the size of the queue
int stack_size(queue* que);

//to print the queue
void stack_print(queue * que);
