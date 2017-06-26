#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
stack* stack_new()                                             // create a new stack
{
	stack *stk;
	stk=(stack*)malloc(sizeof(stack));
	stk->top=llist_new();
	return stk;
}

void stack_push(stack* stk, int data)                           // push an element on the stack
{
	llist_prepend(stk->top,data);                               //Push is equivalent to prepend
}

int stack_pop(stack* stk)                                       // pop the top element from the stack
{
	int element=stk->top->head->data;
	llist_remove_first(stk->top);                               //Pop is equivalent to remove first
	return element;
}

bool stack_is_empty(stack* stk)                                 // Check if stack is empty
{
	if(stk->top->head==NULL) return 1;
	return 0;
}

int stack_size(stack* stk)                                      // find the size of the stack
{
	return llist_size(stk->top);                                //stac's size is just list size 
}

void stack_print(stack* stk)                                    //Print the stack
{
    LList* lst=stk->top;
    Node* cur;
    cur= lst->head;
    while(cur!=NULL)                                            //Loops till last element
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
}
