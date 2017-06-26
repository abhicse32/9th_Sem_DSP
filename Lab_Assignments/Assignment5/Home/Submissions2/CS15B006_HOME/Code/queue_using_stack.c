#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "stack.h"
#include "queue_using_stack.h"

stack* queue_new(){
	stack* q = malloc(sizeof(stack));
	q->top = llist_new();
	return q;
}
// Taking top of stack as front of queue
void enqueue(stack* q, int i){
	if(stack_is_empty(q)) {																	//  when stack is empty it is pushed so as to get added at rear position
		stack_push(q, i);
		return;
	}
	int t = stack_pop(q);																	// popping out
	enqueue(q, i);																			// Recursive function												
	stack_push(q, t);																		// pushing back in
	return;
}

int dequeue(stack* q){
	return(stack_pop(q));																	// popping out from front
}

bool queue_is_empty(stack* q){																// WHen stack is empty
	return(stack_is_empty(q));
}

int queue_size(stack* q){
	return(stack_size(q));
}

void queue_print(stack* q){
	stack_print(q);
	return;
}
