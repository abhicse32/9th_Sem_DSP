/* Program to find minumum number of reversals to make a string of braces valid
 * Author : G.Kavya CS15B048
 * Date : 16.09.2016
*/

#include "stack.h"
#include<stdio.h>

// We remove all the balanced pairs and leave the others (closing and opening) in stack
// Next we find number of reversals to make this a set of consecutive opening and closing braces
int minReversals(char *input){
  int i = 0;
  stack *my_stack = stack_new();
  while(input[i] != '\0'){
	char c = input[i];
	if(c == '{')
	  stack_push(my_stack, c);
	else if(c == '}'){
	  // If stack is empty at this stage, we enter it instead 
	  if(stack_is_empty(my_stack))
		stack_push(my_stack, c);
	  else {
		int x = stack_pop(my_stack);
		// If it is not its opening brace then we push this into the stack
		if(x == '}'){
		  stack_push(my_stack, x);
		  stack_push(my_stack, c);
		}
	  }
	}
	i++;
  }
  // Now we are left with the unpaired braces
  // Case 1: Trivial case of perfectly paired wherein stack is empty
  if(stack_is_empty(my_stack))
	return 0;
  // Case 2: If stack has odd number inside it cannot be balanced
  if(stack_size(my_stack) % 2 != 0)
	return -1;
  // Start from the last and make it alternatively closed and opened
  int moves = 0;
  int closed = 1; // To keep track of whether this is opened or closed
  while(!stack_is_empty(my_stack)){
	// If the current brace is not what is expected then move increases
	if(closed == 1){
	  if(stack_pop(my_stack) == '{')
		moves++;
	  closed = 0;
	}
	else if(closed == 0){
	  if(stack_pop(my_stack) == '}')
		moves++;
	  closed = 1;
	}
  }
  return moves;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t-- > 0){
	char input[1000];
	scanf("%s", input);
	printf("%d\n", minReversals(input));
  }
  return 0;
}
