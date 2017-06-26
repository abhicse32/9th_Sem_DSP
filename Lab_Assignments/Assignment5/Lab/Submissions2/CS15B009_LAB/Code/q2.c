/*  Program to calculate minimum number of reversals required in a paranthesis expression to make it balanced
	
	By  Chandrashekhar D --- Roll no. CS15B009 ---- 16 Sept 2016  */

#include "stack.h"
#include "List.h"
#include <stdio.h>

/*  Function to calculate the number of opening braces in a stack containing opening and closing braces 
	Input parameters : Pointer to the stack
	Returns : number of opening braces */
int countOpen(stack *stk)
{
	int count = 0;
	Node *n = stk->top->head;
	while(n != NULL)
	{
		if (n->data == 123)
			count++;
		n = n->next;
	}
	return count;
}

int main()
{
	const int open = 123;		// Constant integer symbol for opening bracket
	const int close = 125;		// Constant integer symbol for closing bracket
	stack *stk;
	char input;
	int t,ans;
	scanf("%d",&t);				// Number of test cases
	input = getchar();
	while(t--)
	{
		stk = stack_new();		// Initializing an empty stack

		while ((input = getchar())!='\n')		// read characters until a newline character is encountered
		{
			if (input == '{')
				stack_push(stk,open);			// Push if an opening bracket is encountered 
			else
			{
				if (stack_is_empty(stk) || stk->top->head->data == close)   // If closing bracket appears consecutively
					stack_push(stk,close);
				else if (stk->top->head->data == open)				//  If opening bracket is at top, pop it and eliminate the pair 
					stack_pop(stk);
			}
		}
		if (stack_size(stk)%2 == 1)				// If odd number of unbalanced braces are remaining, impossible to balance them
			ans = -1;
		else									
		{
			int x = countOpen(stk);				
			ans = x%2 + stack_size(stk)/2;
		}
		printf("%d\n",ans);
	}
	return 0;
}
