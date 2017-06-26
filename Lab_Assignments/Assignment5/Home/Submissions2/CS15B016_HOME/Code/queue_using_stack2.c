
#include "stack.h"
#include <stdbool.h>



// create a new queue
queue* queue_new(){
	queue *q;
	q=(queue*)malloc(sizeof(queue));
	q->front=stack_new();
//	q->front->head=q->rear->head;
	return q;
}

// add an element to the queue
void enqueue(queue* q, int dat){

	stack *temp;
	
	// reverse stack q->front
	while(!stack_is_empty(q->front)){
		stack_push(temp, stack_pop(q->front));
	}

	//push the data
	stack_push(temp, dat);

	//reverse again
	while(!stack_is_empty(temp)){
		stack_push(q->front, stack_pop(temp));
	}

}

// remove the front element from the queue
int dequeue(queue* q){
	return stack_pop(q->front);
}

// Check if queue is empty
bool queue_is_empty(queue* q){
	return stack_is_empty(q->front);
}

// find the size of the queue
int queue_size(queue* q){
	return stack_size(q->front);
}

// print queue element
void queue_print(queue* q){
	stack_print(q->front);
}

