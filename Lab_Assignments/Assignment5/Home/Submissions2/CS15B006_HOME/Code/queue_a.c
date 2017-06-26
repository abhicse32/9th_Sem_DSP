#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000


queue* queue_new(){
	queue* q = malloc(sizeof(queue));	
	q->arr = (int*)malloc(sizeof(int)*size);										// Space allocation for arr and queue variable	
	q->front = 0;																	// initailizing all variables
	q->rear = size-1;
	return q;
}


void enqueue(queue* q, int i){
	if(queue_is_empty(q)){
		q->arr[q->front] = i;													// Empty case		
		q->rear = (q->rear + 1)%size;
		return;
	}
	if(queue_is_full(q)){														// WHen they are full		
		return;
	}
	q->rear = (q->rear + 1)%size;												// appending at rear positon
	q->arr[q->rear] = i;														
	return;
}

// remove the first element from the queue
int dequeue(queue* q){
	if(queue_is_empty(q)){														// Empty case
		return;
	}
	int i = q->arr[q->front];
	q->front = (q->front + 1)%size;												// removing from Front positon			
	return i;
}

// Check if queue is empty
bool queue_is_empty(queue* q){													
	if((q->rear - q->front + size)%size == size-1) return true;					// WHen they are empty rear will be behind front position	
	return false;
}

// bool check if queue is full
bool queue_is_full(queue* q){													// When full it will be behind by two position, covering entire circular array	
	if((q->rear - q->front + size)%size == size-2) return true;
	return false;
}

// find the size of the queue
int queue_size(queue* q){
	int t = (q->rear - q->front + size + 1)%size;										
	return t;
}

// print queue element
void queue_print(queue* q){
	if(!queue_is_empty(q)){
		int i = q->front;
		while(i != q->rear){
			printf("%d ", q->arr[i]);												// Printing entire queue by traversing the array
			fflush(stdout);
			i = (i + 1)%size;
		}
		printf("%d", q->arr[i]);
		fflush(stdout);
	}
		return;
}
