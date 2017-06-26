#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue_a.h"
#include <limits.h>

#define size 1000

/*
typedef struct Queue_a{
	int *arr;
	int front;
	int rear;
}queue;*/

// create a new queue
queue* queue_new(){
	queue *q;
	q=(queue*)malloc(sizeof(queue));
	q->arr=(int*)malloc(sizeof(int)*(size+1));
	q->front=0;
	q->rear=size;
}

// add an element in the queue
void enqueue(queue* q, int dat){
	if(((q->rear-q->front)==-1)||(q->rear==size&&q->front==0)){
	//	q->front=0;
		q->rear=q->front;
		q->arr[q->front]=dat;
	}
	else{
		if(q->rear!=size){
			q->arr[++(q->rear)]=dat;
		}
		else{
			q->rear=0;
			q->arr[0]=dat;
		}
	}
}

// remove the first element from the queue
int dequeue(queue* q){
	int f=q->front, r=q->rear;
	int val=q->arr[f];
	if(!((f-r+size+2)%(size+1)))
		return  INT_MIN;
	else{
		q->front++;
		if(q->front==size) q->front=0;
	}
	return val;

}

// Check if queue is empty
bool queue_is_empty(queue* q){
	int f=q->front, r=q->rear;
	if(f){
		return(r==f-1);
	}
	else{
		return r==size;
	}
}

// bool check if queue is full
bool queue_is_full(queue* q){
	int f=q->front, r=q->rear;
	if(f>1){
		return r==f-2;
	}
	else if(f==1){
		return r==size;
	}
	else{
		return r==size-1;
	}
}

// find the size of the queue
int queue_size(queue* q){
	int f=q->front, r=q->rear;
	if((f-1==r)||(f==0&&r==size))
		return 0;
	else if(r>=f)
		return r-f+1;
	else if (r<f)
		return size-f+r+1;
}

// print queue element
void queue_print(queue* q){
	int f=q->front, r=q->rear;
	int i=f;
	while(i<=r){
		printf("%d ",q->arr[i]);
		i++;	
		if(i==size) i=0;
	}
//	printf("\n");
}