
/*-----------------------------------------------------------------------------
 *  Program to implement queue ADT using linked lists
 *  Name: Harshavardhan.P.K.
 *  RollNo: CS15B061
 *  Date: 17 Sept,2016
 *-----------------------------------------------------------------------------*/
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include <stdbool.h>


/*-----------------------------------------------------------------------------
 *  Function: queue_new : to creata new queue
 *-----------------------------------------------------------------------------*/
queue* queue_new(){
	queue* newQ = (queue*)malloc(sizeof(queue));
	//allocate list for front and rear
	newQ->front=llist_new();
	newQ->rear=llist_new();
	return newQ;
}

/*-----------------------------------------------------------------------------
 *  Function: enqueue - to add an element to q from rear
 *  Inputs: q- the input q pointer
 *  	    n - the number to add
 *-----------------------------------------------------------------------------*/
void enqueue(queue* q, int n){
	//append to rear
	llist_append(q->rear,n);
	//if it is not first enqueue we have 2 consecutiove nodes from rear
	if(q->rear->head->next)
		//put rear to next node
	q->rear->head=q->rear->head->next;
	//in case of fist enqueue front->head shoul point to rear->head
	if(q->front->head == NULL)
		q->front->head=q->rear->head;
}

/*-----------------------------------------------------------------------------
 *  Function: dequeue - removes element from front
 *  Input: q - the input queue pointer
 *-----------------------------------------------------------------------------*/
int dequeue(queue* q){
	//fet element pointed by front
	int ans = llist_get(q->front,0);
	//remove the element
	llist_remove_first(q->front);
	if(q->front->head == NULL) q->rear->head=NULL;
	return ans;
}

/*-----------------------------------------------------------------------------
 *  Function : queue_is_empty - to check if queue is empty
 *  Input: q - pointer to input queue
 *  Returns 1 if empty else 0
 *-----------------------------------------------------------------------------*/
bool queue_is_empty(queue* q){
	return (!(q->front->head));
}

/*-----------------------------------------------------------------------------
 *  Function : queue_is_full - to check if queue is full
 *  Input: q - pointer to input queue
 *  Returns 1 if empty else 0
 *-----------------------------------------------------------------------------*/
int queue_size(queue* q){
	queue* t = queue_new();
	int sz=0;
	//dequeue all elments from q to t and count no. of elements
	while(!queue_is_empty(q)){
		int nu = dequeue(q);
		sz++;
		enqueue(t,nu);
	}
	//get back all the elements from t
	while(!queue_is_empty(t)){
		int nu = dequeue(t);
		enqueue(q,nu);
	}
	free(t);
	return sz;
}

/*-----------------------------------------------------------------------------
 *  Function: queue_print - print the queue
 *  Input - q pointer to input queue
 *-----------------------------------------------------------------------------*/
void queue_print(queue* q){

	queue* t = queue_new();
	//dequeue all elments from q to t and print them
	while(!queue_is_empty(q)){
		int nu = dequeue(q);
		printf("%d ",nu);
		enqueue(t,nu);
	}
	//get back all the elements from t
	while(!queue_is_empty(t)){
		int nu = dequeue(t);
		enqueue(q,nu);
	}
	
}

