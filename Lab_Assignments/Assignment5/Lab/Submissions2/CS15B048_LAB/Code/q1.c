/* Program to check whether a given input of braces is valid or not
 * Author : G.Kavya CS15B048
 * Date : 16.09.2016
*/

#include<stdio.h>
#include "stack.h"

// Checks if a is a matching closing brace for b
int isPair(char a, char b){
  return ((a == ')' && b == '(') || (a == '}' && b == '{') || (a == ']' && b == '['));
}

// Returns if input string is a valid set of braces
int isBalanced(char *input){
  int i = 0;
  stack *my_stack = stack_new();
  while(input[i] != '\0'){
	char c = input[i];
	if(c == '(' || c == '[' || c == '{'){
	  stack_push(my_stack, c);
	}
	else if(c == ')' || c == ']' || c == '}'){
	  // If stack is empty at this point it is incorrect
	  if(stack_is_empty(my_stack))
		  return 0;
	  int x = stack_pop(my_stack);
	  // If topmost in stack is not its pair then incorrect
	  if(!isPair(c, x))
		return 0;
	}
	i++;
  }
  // If stack is not empty after everything, it is incorrect
  if(!stack_is_empty(my_stack)){
	return 0;
  }
  return 1;
}

int main(){
  int n;
  scanf("%d", &n);

  while(n-- > 0){
	char input[1000];
	scanf("%s", input);
	printf("%d\n", isBalanced(input));
  }
  return 0;
}
