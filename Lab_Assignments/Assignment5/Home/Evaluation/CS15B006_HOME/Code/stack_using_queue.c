#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack_using_queue.h"

queue* stack_new(){
	queue* stk = queue_new();																	
	return stk;
}

void stack_push(queue* stk, int i){
	int n = queue_size(stk);
	int count = 0;
	enqueue(stk, i);																			// Enqueing at bottom
	int t;
	while(count < n){
		t = dequeue(stk);																		// Dequeing all remainig elements until it
		enqueue(stk, t);																		// ENqueing back so that initally enqued number is at top
		count++;
	}
	return;	
}

int stack_pop(queue* stk){
	return dequeue(stk);
}

bool stack_is_empty(queue* stk){
	return(queue_is_empty(stk));
}

void stack_print(queue* stk){
	queue_print(stk);
	return;
}

int stack_size(queue* stk){
	return queue_size(stk);
}
