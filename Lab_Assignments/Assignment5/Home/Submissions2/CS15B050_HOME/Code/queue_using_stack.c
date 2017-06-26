#include "stack.h"
#include "List.h"
#include "queue_using_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

stack* queue_new()									// create a new queue
{
	stack *stk;
	stk=(stack*)malloc(sizeof(stack));
	stk->top=llist_new();
	return stk;
}

bool queue_is_empty(stack* stk)						// Check if queue is empty
{
	if(stk->top->head==NULL) return 1;
	return 0;
}

int queue_size(stack* stk)							// Returns the size of the queue
{
	return llist_size(stk->top);
}

void queue_print(stack* stk)						// print queue elements
{
    LList* lst=stk->top;
    Node* cur;
    cur= lst->head;
    while(cur!=NULL)                                //Loops till last element
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
}

stack* enqueue(stack* stk,int data)					// add an element to the queue
{
	if(stk->top->head==NULL)						//when stack is empty push the element
	{
		stack_push(stk,data);
		return stk;
	}
	int x=stack_pop(stk);							//After the element is pushed
	stk=enqueue(stk,data);							//the finally popped out x will
	stack_push(stk,x);								//now be pushed into the stack recursively
	return stk;
}

int dequeue(stack* stk)								// remove the first element from the queue
{
	if(stk->top->head==NULL)						//if queue is empty we cannot dequeue  
	{
		return INT_MIN;
	}
	else
	{
		int x=stack_pop(stk);						//dequeue is just pop
		return x;
	}
}
