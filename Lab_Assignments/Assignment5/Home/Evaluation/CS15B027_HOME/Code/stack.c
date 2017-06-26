#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
stack* stack_new()
{
  stack* p=(stack *)malloc(sizeof(stack));
  p->top=llist_new();
  return p;
}
void stack_push(stack* lst, int data)
{
	llist_prepend(lst->top,data);
}
int stack_pop(stack* lst)
{
	int pop= llist_get(lst->top,0);
	llist_remove_first(lst->top);
	return pop;
}
bool stack_is_empty(stack* lst)

{
    if((lst->top)->head == NULL)    
    return 1;
    else
    return 0;
}
int stack_size(stack* lst)
{
  int i=0;
  Node* n=(lst->top)->head;
  while(n!=NULL)
  {
     n=n->next;
     i++;
  }
  return i;
}

void stack_print(stack* lst)
{
	llist_print(lst->top);
}
int stack_top(stack* st){
	int ret_val= llist_get(st->top,0);
	return ret_val;
}
