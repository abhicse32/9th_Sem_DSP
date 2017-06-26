#include"List.h"
#include"stack.h"
#include "queue_using_stack.h"
#include<stdio.h>
#include<stdlib.h>
 
 
 
   //creating a new queue
stack* queue_new(){
      stack *q=stack_new();
     
	  return q;
}

// add an element to the queue
void enqueue(stack *q,int x){ 
    stack *temp = stack_new();
    while(stack_is_empty(q)==0){
       stack_push(temp , stack_pop(q));
       }
       stack_push(temp , x);
    while(stack_is_empty(temp)==0){
       stack_push(q , stack_pop(temp));
       }
}
       
  // removing the front element from the queue
 int  dequeue(stack* q){
      return stack_pop(q);
  }
  
  // Checking if queue is empty
bool queue_is_empty(stack* q){
     return stack_is_empty( q);
  }
  
  // finding the size of the queue
int queue_size(stack* q){
     return stack_size(stack* q);
  }
  
  // printing queue element
void queue_print(stack* q){
     stack_print(stack* q);
  }
