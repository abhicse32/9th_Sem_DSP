#include"stack.h"

//to create a new stack
stack* queue_new();

//to add an element at the end of a stack
void enqueue(stack* stk, int elm);

//to remove an element at the front of a stack
int dequeue(stack * stk);

//to check if the stack is empty
bool queue_is_empty(stack * stk);

//to get the size of the stack
int queue_size(stack * stk);

//to print the stack
void queue_print(stack *stk);
