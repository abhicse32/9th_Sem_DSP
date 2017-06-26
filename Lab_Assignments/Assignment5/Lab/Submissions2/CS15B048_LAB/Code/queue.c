#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// create a new queue
queue* queue_new(){
  queue* new = (queue*) malloc(sizeof(queue));
  new->front = llist_new();
  new->rear = llist_new();
  return new;
}

// add an element to the queue
void enqueue(queue* my_queue, int value){
 if(my_queue->front->head == my_queue->rear->head) {
   // Queue is empty
   llist_append(my_queue->rear, value);
   // Both front and rear pointer point to the same element
   my_queue->front->head = my_queue->rear->head;
   return;
 }
 // Else just append to rear pointer since that takes O(1) time
 llist_append(my_queue->rear, value);
}

// remove the front element from the queue
int dequeue(queue* my_queue){
  if(my_queue->front->head == my_queue->rear->head){
	// Case of only one element
	int value = llist_remove_first(my_queue->front);
    my_queue->front->head = my_queue->rear->head;
	return value;
  }
  return llist_remove_first(my_queue->front);
}

// Check if queue is empty
bool queue_is_empty(queue* my_queue){
  return (my_queue->front->head == NULL);
}
  
// find the size of the queue
int queue_size(queue* my_queue){
  return llist_size(my_queue->front);
}

// print queue element
void queue_print(queue* my_queue){
  llist_print(my_queue->front);
}
