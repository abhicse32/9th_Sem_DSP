#include "List.h"
#include "stack2queue.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()
	{
		queue* a;
		a=(queue*)malloc(1*sizeof(queue));
		a->stk=stack_new();
		return a;
	}

void enqueue(queue* que, int n)
	{
		if(stack_is_empty(que->stk)) {stack_push(que->stk,n); return;}
		int x;
		x=stack_pop(que->stk);
		 enqueue(que,n);
		 stack_push(que->stk,x);
	}
		
int dequeue(queue* que)
	{
		return stack_pop(que->stk);
	}

bool queue_is_empty(queue* que)
	{
		return stack_is_empty(que->stk);
	}

int queue_size(queue* que)
	{
		return stack_size(que->stk);	
	}

void queue_print(queue* que)
	{
		return stack_print(que->stk);
	}
