
#include "stack.h"
#include <stdbool.h>
//#include "stack.c"
#include "queue_using_stack.h"

// create a new queue
stack* queue_new(){
//	queue *q;
//	q=(queue*)malloc(sizeof(queue));
	stack *front=stack_new();
//	q->front->head=q->rear->head;
	return front;
}

// add an element to the queue
void enqueue(stack* front, int dat){

	stack *temp=stack_new();
	int x;
	//printf("xP");
	//printf("\nzzzz%d ",stack_is_empty(front)? 1 : 0);
	if(stack_is_empty(front)){
		stack_push(front, dat);
	//	printf("l");
		return;
	}
	// reverse stack q->front
	while(!stack_is_empty(front)){
		x=stack_pop(front);
		stack_push(temp, x);
		if(stack_is_empty(front)) break;
	//	printf("P");
	}

	//push the data
	stack_push(temp, dat);

	//reverse again
	while(!stack_is_empty(temp)){
		stack_push(front, stack_pop(temp));
	//	printf("Q");	
	}

}

// remove the front element from the queue
int dequeue(stack* front){
	return stack_pop(front);
}

// Check if queue is empty
bool queue_is_empty(stack* front){
	return stack_is_empty(front);
}

// find the size of the queue
int queue_size(stack* front){
	return stack_size(front);
}

// print queue element
void queue_print(stack* front){
	stack_print(front);
}

