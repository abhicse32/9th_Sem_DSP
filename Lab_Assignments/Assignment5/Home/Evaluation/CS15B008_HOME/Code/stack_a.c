#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define size 1000

//CREATING A NEW STACK
stack* stack_new()
{
 stack* new = (stack *)malloc(sizeof(stack));
 new->top = -1;
 new->arr = (int *)malloc(sizeof(int));
 return new;
}

//PUSHING AN ELEMENT INTO A STACK
void stack_push(stack* pile, int n)
{
 if(stack_is_full(pile))
 {
   return;
 }
 else
 {
   (pile->top)++;
   pile->arr[pile->top] = n;
 }
}

//POPPING AN ELEMENT FROM A STACK
int stack_pop(stack* pile)
{ 
 if(stack_is_empty(pile))
 {
  return INT_MIN;
 }
 else
 {
  return pile->arr[pile->top--];
 }
}

//CHECKING IF A STACK IS EMPTY OR NOT
bool stack_is_empty(stack* pile)
{
 if(pile->top == -1) 
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

//CHECKING IF THE STACK IS FULL OR NOT
bool stack_is_full(stack* pile)
{
 if(pile->top == size - 1)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

//FINDING THE SIZE OF THE STACK
int stack_size(stack* pile)
{
 return (pile->top+1);
}

//PRINTING THE ELEMENTS IN A STACK	
void stack_print(stack* pile)
{
 int i = 0;
 for(i = pile->top;i>=0;i--)
 {
  printf("%d ",pile->arr[i]);
 }
}
 
  

