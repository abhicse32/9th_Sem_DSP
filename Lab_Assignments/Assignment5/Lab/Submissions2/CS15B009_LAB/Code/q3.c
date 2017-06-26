/*  Program to find the next greater element of each element in an array in the order in which they appear 
	
	By  Chandrashekhar D --- Roll no. CS15B009 ---- 16 Sept 2016  */

#include "stack.h"
#include <stdio.h>

/*  Main function */
int main()
{
	int t,n,i,temp,head;
	stack *stk;				// Stack to temporarily store elements of array
	stack *ind;				// Stack to store the indices of elements stored in stk
	
	scanf("%d",&t);			// Number of testcases
	while(t--)
	{
		stk = stack_new();	// Initializing them to empty stacks
		ind = stack_new();
		scanf("%d",&n);		// Number of elements in array
		
		int arr[n],ans[n];	// Arrays to store the inputs and the output respectively 
		for (i = 0;i < n;i++)
			scanf("%d",&arr[i]); 	// Taking input, array elements
		
		stack_push(stk,arr[0]);		// Push the first element into the stack
		stack_push(ind,0);
		
		for (i = 1;i < n;i++)
		{
			temp = arr[i];
			if (temp > (stk->top->head->data)) 			// If temp is greater than top of stack
			{
				while (temp > (stk->top->head->data))
				{
					stack_pop(stk);						// Pop the elements until temp remains greater than top of stack
					ans[stack_pop(ind)] = temp;			// the answer for all these elements is temp
					if (stack_is_empty(stk))
					{
						break;
					}
				}
				stack_push(stk,temp);					// Push temp into stack
				stack_push(ind,i);
			}
			else 										// If temp is not greater than top of stack, push temp into stack
			{
				stack_push(stk,temp);
				stack_push(ind,i);
			}
		}
		while (!stack_is_empty(ind))
			ans[stack_pop(ind)] = -1; 					// For elements still remaining in stack, there is no valid answer (so -1)
			
		for (i = 0;i < n;i++)
			printf("%d ",ans[i]);						// Printing the answer array
		printf("\n");
	}
	return 0;
}
