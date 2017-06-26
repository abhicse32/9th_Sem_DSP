/*  Program to check if a given expression containing paranthesis is balanced or not 

	By  Chandrashekhar D --- Roll no. CS15B009 ---- 16 Sept 2016  */

#include "stack.h"
#include <stdio.h>

/*  Function to find if a number is present in a cnstant array
	Input parameters : the array arr, the number to be searched
	Returns : true if num is present in arr, false otherwise  */
bool contains(int arr[],int num)
{
	return (num == arr[0] || num == arr[1] || num == arr[2]);
}

/*  Main function */
int main()
{
	int openBraces[3] = {40,91,123};  		// Constants '(' , '[' and '{'
 	int closeBraces[3] = {41,93,125};		// Constants ')' , ']' and '}'
	stack *stk;
	int t,isBalanced;
	char input;
	scanf("%d",&t);			// Number of testcases
	input = getchar();
	while(t--)
	{
		stk = stack_new();	// Initializing an empty stack
		isBalanced = 1;		// Assuming expression is balanced

		while ((input = getchar())!='\n')		// Read characters until a newline is encountered
		{
			if (contains(openBraces,(int)input))
				stack_push(stk,(int)input);		// Push if an open bracket

			else if (contains(closeBraces,(int)input))
			{
				if (stack_is_empty(stk) || contains(closeBraces,stk->top->head->data)) // If two consecutive closing brackets
					stack_push(stk,(int)input);
				else
				{
					int check = (stk->top->head->data)-((int)input);		// Check if the opening bracket matches type with input
					if (check == -1 || check == -2)
						stack_pop(stk);	
					else
						isBalanced = 0;	
				}
				
			}
		} 
		if (isBalanced == 1 && !stack_is_empty(stk))		// If stack is not empty after full traversal, expression is unbalanced
			isBalanced = 0;
			
		printf("%d\n",isBalanced);
	}
	return 0;
}


