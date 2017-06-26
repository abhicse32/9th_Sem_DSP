#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

// create a new queue
queue* queue_new(){
	queue* que= (queue*)malloc(sizeof(queue));
	que->arr= (int*)malloc(sizeof(int)*size);
	que->front=0;
	que->rear= 0;
	return que;
}

// push an element on the queue
void enqueue(queue* que, int data){
	if(!queue_is_full(que)){
		(que->rear)%=size;
		que->arr[que->rear]=data;
		++(que->rear);
	}
}

// pop the top element from the queue
int dequeue(queue* que){
	int retVal= -1;
	if(!queue_is_empty(que)){
		(que->front)%=size;
		retVal= que->arr[que->front];
		++(que->front);
	}
	return retVal;
}

// Check if queue is empty
bool queue_is_empty(queue* que){
	return queue_size(que)==0;
}

// bool check if queue is full
bool queue_is_full(queue* que){
	return queue_size(que) >= size;
}

// find the size of the queue
int queue_size(queue* que){
	return (que->rear > que->front)?(que->rear - que->front):
									(que->rear+ size - que->front);
}

// print queue element
void queue_print(queue* que){
	int i;
	if(que->rear > que->front)
		for(i= que->front; i < que->rear; i++)
			printf("%d ",que->arr[i]);
	else{
		for(i=que->front; i<size;++i)
			printf("%d ",que->arr[i]);
		for(int i=0;i<que->rear;++i)
			printf("%d ",que->arr[i]);		
	}
}