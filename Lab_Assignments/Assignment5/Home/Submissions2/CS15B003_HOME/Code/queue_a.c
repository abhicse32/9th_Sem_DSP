#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new(){

	queue* que = (queue*)malloc(sizeof(queue));
	que->arr = (int*)malloc(sizeof(size*sizeof(int)));

	que->front = -1;
	que->rear = -1;

	return que;
}

void enqueue(queue* que, int data){

	if(que->front == -1){
		que->front = 0;
		que->rear = 0;
		que->arr[0] = data;
		return ;
	}

	if((que->rear + 1)%size == que->front) return;
	
	if(que->rear == size-1){
		que->arr[0] = data;
		que->rear = 0;
		return ;
	}
	
	que->rear++;
	que->arr[que->rear] = data;
	return;
}

int dequeue(queue* que){
	
	int element = que->arr[que->front];

	if(que->front == que->rear){
		que->front = -1;
		que->rear = -1;
		return element;	
	}
	
	if(que->front == size-1){
		que->front = 0;
		return element;
	}

	que->front++;
	return element;	
}

bool queue_is_full(queue* que){

	if((que->rear + 1)%size == que->front) return 1;
	return 0;	
}

int queue_size(queue* que){

	if(que->front == -1) return 0;
	if(que->front <= que->rear)
		return que->rear - que->front + 1;
	
	return size - que->front + que->rear + 1;
}

bool queue_is_empty(queue* que){

	if(que->front == que->rear) return 1;
	return 0;
}

void queue_print(queue* que){

	int n = queue_size(que);
	int i;

	for(i = 0; i < n ; i++)
		printf("%d ",que->arr[(que->front + i)%size]);

	return ;
}
