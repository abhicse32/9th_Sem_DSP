#include"List.h"
#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
  
   //creating a new queue
stack* queue_new(){

	stack *Q=stack_new();     
	return Q;
}

// add an element to the queue
void enqueue(stack *Q,int x){
 
	stack *sstack = stack_new();
	
	while(!stack_is_empty(Q)){
		stack_push(sstack,stack_pop(q));
        }
        stack_push(sstack,x);
        
        while(!stack_is_empty(sstack)){
        	stack_push(Q , stack_pop(sstack));
        }
        
}
       
  // removing the front element from the queue
int dequeue(stack* Q){

        return stack_pop(Q);
}
  
  // Checking if queue is empty
bool queue_is_empty(stack* Q){
	stack_is_empty( Q);
}
  
  // finding the size of the queue
int queue_size(stack* Q){
        return stack_size(stack* Q);
}
  
  // printing queue element
void queue_print(stack* Q){
        stack_print(stack* Q);
}
