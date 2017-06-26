#include "queue.h"
#include"List.h"
#include <stdio.h>
#include <stdlib.h>

// creating a new queue
queue* queue_new(){
    queue* q=(queue*) malloc(sizeof(queue));
    q->front= llist_new();
     q->rear= llist_new();
     return q;
 }
 
// adding an element to the queue
void enqueue(queue* q, int data){
     llist_append(q->front , data);
     Node*p=(q->front)->head;
     while(p->next!=NULL)
     {
       p=p->next;
     } 
     (q->rear)->head = p; 
 }
 
 // removing the front element from the queue
int dequeue(queue* q){
    int x =((q->front)->head)->data;
    llist_remove_first(q->front);
    return x;
 }
 
 // Checking if queue is empty
bool queue_is_empty(queue* q){
	if(q->front->head)
		return false;
	return true;
}

// finding the size of the queue
int queue_size(queue* q){
	return llist_size(q->front);
}

// printing queue element
void queue_print(queue* q){
	llist_print(q->front);
}
  

    
