#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include "queue_using_stack.h"
#include "stack.h"
#include "List.h"

stack* queue_new()
{
 stack* new = stack_new(); 
 return new;
}

bool queue_is_empty(stack* pile)
{
 bool p = stack_is_empty(pile);
 return p;
}

int queue_size(stack* pile)
{
 int p =stack_size(pile);
 return p;
}

void queue_print(stack* pile)
{
 stack_print(pile);
}

void enqueue(stack* pile)
{
 stack_invert(pile);
 stack_push(pile,x);
 stack_invert(pile);
}

int dequeue(stack* pile)
{ 
 int p = stack_pop(pile);
 return p;
}


void stack_invert(stack *pile)
{
 LList *list=pile->top;
 Node *first=list->head;
 if(first!=NULL) reverse_list(list);
}

void reverse_list(LList *list)
{
 Node *first=list->head;
 if((first==NULL)||((first->next)==NULL))
 {	
  list->head=first;			 
 }
 else
 {
  int temp=first->data;
  llist_remove_first(list);
  reverse_list(list);
  llist_append(list,temp);		
 }
}
