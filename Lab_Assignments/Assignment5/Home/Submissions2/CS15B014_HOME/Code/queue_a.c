/*D TEJA VARDHAN REDDY CS15B014  18/9/16*/
/* QUEUE ARRAY FUNCTIONS*/
#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
// create a new queue
queue* queue_new(){
	queue*a=(queue*)malloc(sizeof(queue));
	a->arr=(int*)malloc(sizeof(int)*1000);
	a->front=0;
	a->rear=-1;
}
// add an element in the queue
void enqueue(queue*a, int data){
	if(!queue_is_full(a)){

		a->rear=(a->rear + 1)%size;
		(a->arr)[a->rear]=data;
	}
}
// remove the first element from the queue
int dequeue(queue*a){
	if(!queue_is_empty(a)){
		int front=a->front;
		front++;
		a->front++;
		return (a->arr)[front-1];
	}

}
// bool check if queue is full
bool queue_is_full(queue*a){
	int rear=a->rear;
	int front=a->front;
	if((rear-front+size+2)%size==0)
		return 1;
	else return 0;

}
// Check if queue is empty
bool queue_is_empty(queue*a){
	int rear=a->rear;
	int front=a->front;
	if((rear-front+size+1)%size==0)
		return 1;
	else
		return 0;
}

// find the size of the queue
int queue_size(queue*a){
	int rear=a->rear;
	int front=a->front;
	return (rear-front+size+1)%size;

}



// print queue element
void queue_print(queue*a){
	int rear=a->rear,i;
	int front=a->front;
	if(!queue_is_empty(a)){
		if(front>rear)
			rear+=size;
		for ( i = front; i <=rear ; ++i)
		{
			printf("%d ",(a->arr)[i%size]);
		}
	}
}
