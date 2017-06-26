/*-----------------------------------------------------------------------------
 *  Program to implement queue ADT using arrays
 *  Name: Harshavardhan.P.K.
 *  RollNo: CS15B061
 *  Date: 17 Sept,2016
 *-----------------------------------------------------------------------------*/
#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

#include <stdbool.h>
#include <limits.h>



/*-----------------------------------------------------------------------------
 *  Function: queue_new : to creata new queue
 *-----------------------------------------------------------------------------*/
queue* queue_new(){
	//creates the queue structre
	queue* newQ = (queue*)malloc(sizeof(queue));
	//assign space for array
	newQ->arr = (int*)malloc(sizeof(size+1));
	//initialise front and rear value
	newQ->front=0;
	newQ->rear=size;
	return newQ;
}


/*-----------------------------------------------------------------------------
 *  Function: enqueue - to add an element to q from rear
 *  Inputs: q- the input q pointer
 *  	    n - the number to add
 *-----------------------------------------------------------------------------*/
void enqueue(queue* q, int n){
	//if queue is full cant add
	if(queue_is_full(q)) return;
	//increment rear index
	(q->rear)++;
	//if rear goes out of bound put right value and assign the number
	if(q->rear == size+1) q->rear=0;
	q->arr[q->rear]=n;
}

/*-----------------------------------------------------------------------------
 *  Function: dequeue - removes element from front
 *  Input: q - the input queue pointer
 *-----------------------------------------------------------------------------*/
int dequeue(queue* q){
	//if queue is empty return
	if(queue_is_empty(q)) return INT_MIN;
	//store the front element in ans
	int ans=q->arr[q->front];
	//increment front so the size decreases by 1
	(q->front)++;
	if(q->front==size+1) q->front = 0;
	return ans;
}


/*-----------------------------------------------------------------------------
 *  Function : queue_is_empty - to check if queue is empty
 *  Input: q - pointer to input queue
 *  Returns 1 if empty else 0
 *-----------------------------------------------------------------------------*/
bool queue_is_empty(queue* q){
	int front=q->front,rear;
	//if rear == size (initially) put it as -1 index
	if(q->rear == size) rear = -1;
	else rear = q->rear;
	return(front-rear == 1); 
}


/*-----------------------------------------------------------------------------
 *  Function : queue_is_full - to check if queue is full
 *  Input: q - pointer to input queue
 *  Returns 1 if empty else 0
 *-----------------------------------------------------------------------------*/
bool queue_is_full(queue* q){
	int rear;
	//if rear is out of bound set it right value
	if(q->rear>=size-1) rear=(q->rear)-size-1;
	else rear=q->rear;
	return((q->front) - rear == 2);
}


/*-----------------------------------------------------------------------------
 *  Function : queue_size - calculate size of queue
 *  Input : q - pointer to input queue
 *  Return size of queue
 *-----------------------------------------------------------------------------*/
int queue_size(queue* q){
	if(queue_is_empty(q)) return 0;
	//size of queue = (rear - front +1 +size)%size
	int ans=(q->rear) - (q->front) +1;
	if(ans<0) ans+=size+1;
	return ans;	
}


/*-----------------------------------------------------------------------------
 *  Function: queue_print - print the queue
 *  Input - q pointer to input queue
 *-----------------------------------------------------------------------------*/
void queue_print(queue* q){
	int i=queue_size(q),j,k=q->front;
	for(j=0;j<i;j++){
		//print the ith element in queue
		printf("%d ",q->arr[k]);
		//if k goes out of bound put it to right value
		k++;
		if(k==size+1) k=0; 
	}
}
