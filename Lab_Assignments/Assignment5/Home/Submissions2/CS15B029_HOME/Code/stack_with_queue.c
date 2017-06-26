#include"List.h"
#include"queue.h"
#include<stdio.h>96

// create a new stack
queue* stack_new(){
	queue* stk=queue_new();
	return stk;
}

// push an element on the stack
void stack_push(queue* stk,int x){
   queue *temp = queue_new();
   while(queue_is_empty(stk)==0){
      enqueue(temp ,deque(stk));
    }
     enqueue(temp , x);
    while(queue_is_empty(temp)==0){
      enqueue(stk , dequeue(temp));
    }
}
  
 // pop the top element from the stack
int stack_pop(queue* stk){
	int x = dequeue(stk);
	return x;
}

// Check if stack is empty
bool stack_is_empty(queue* stk){
	return queue_is_empty(stk);
}

// find the size of the stack
int stack_size(queue* stk){
	return queue_size(stk);
}

// print stack element
void stack_print(queue* stk){
	queue_print(stk);
}
