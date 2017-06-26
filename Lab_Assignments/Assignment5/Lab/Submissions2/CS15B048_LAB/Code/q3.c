/* Program to find next greater element in an array in order of appearance
 * Author : G.Kavya CS15B048
 * Date : 16.09.2016
 */

#include "stack.h"
#include "queue.h"

#include<stdio.h>

/*
// First idea using queue where first element is element of interest and after being alotted is dequeued
int main(){
  int t;
  while(t-- > 0){
	queue *my_queue = queue_new();
	stack* my_stack = stack_new();
	// Number of entries
	int n;
	scanf("%d", &n);
	int i = 0;
	int waiting;
	//for(; i < n; i++){
	while(i == 0 || !queue_is_empty(my_queue)){
	  if(i < n){
		int num;
		scanf("%d", &num);
		enqueue(my_queue, num);
		i++;
	  }

	  waiting = my_queue->front->head->data;

	  if(stack_is_empty(my_stack)){
		//waiting = stack_pop(my_stack);
		if(num > waiting){
		  stack_push(my_stack, num);
		  dequeue(my_queue);
		  printf("%d ", num);
		}
	  }
	  else {
		// Current maximum number
		int comp = stack_pop(my_stack);
		// Use that and push it back into stack
		if(comp > waiting){
		  printf("%d ", comp);
		  stack_push(my_stack, comp);
		}
		// Else it is no longer useful to be compared so thrown away
	  }
	}
*/

int main(){
  int t;
  scanf("%d", &t);

  // Loop through testcases
  while(t-- > 0){
	int n;
	scanf("%d", &n);
	int array[n];
	int i;

	for(i = 0; i < n; i++){
	  scanf("%d", &array[i]);
	}

	stack* indices = stack_new();
	stack_push(indices, 0);
	i = 1;

	while(i < n){
	  int previndex = stack_pop(indices);
	  // If element is greater that that whose index is on top of stack then till it is greater all those elements get their value as this element
	  if(array[i] > array[previndex]){
		int flag = 1;
		while(array[i] > array[previndex]){
		  array[previndex] = array[i];
		  if(stack_is_empty(indices)){
			flag = 0;
			break;
		  }
		  previndex = stack_pop(indices);
		}
		// We need to push the element we wrongly popped
		if(flag)
		  stack_push(indices, previndex);
		// Push this element also
		stack_push(indices, i);
	  }
	  else{
		// Push the element we popped 
		stack_push(indices, previndex);
		// Push this element also waiting for something bigger
		stack_push(indices, i);
	  }
	  i++;
	}
	// Those elements still in stack are waiting for something bigger which does not exist so make them -1
	while(!stack_is_empty(indices)){
	  int index = stack_pop(indices);
	  array[index] = -1;
	}
	for(i = 0; i < n; i++){
	  printf("%d ", array[i]);
	}
	printf("\n");
  }
}
