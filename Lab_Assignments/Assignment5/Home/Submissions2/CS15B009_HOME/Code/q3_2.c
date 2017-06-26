/*  Program to evaluate a postfix mathematical expression

	By : Chandrashekhar D --- Roll no.CS15B009 --- 17 Sept 2016  */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Function to evaluate a mathematical expression with 2 operands and an operator  */
int evaluate(int num1,int num2,int operation)
{
	int ans;
	switch(operation)
	{
		case 37:
			ans = num1%num2;
			break;
		case 38:
			ans = num1&num2;
			break;
		case 42:
			ans = num1*num2;
			break;
		case 43:
			ans = num1+num2;
			break;
		case 45:
			ans = num1-num2;
			break;
		case 47:
			ans = num1/num2;
			break;
		case 94:
			ans = num1^num2;
			break;
		case 124:
			ans = num1|num2;
			break;
	}
	return ans;
}

/*  Main function */
int main()
{
	while(1)
	{
		char input;
		stack *stk = stack_new();
		int ans,i = 0;
		
		while((input = getchar())!='\n' && input != '\0')		// Reads input character wise until a newline is encountered
		{
			if (input == EOF)							// Terminates program when end of file is encountered
				return 0;
			if ((int)input > 47 && (int)input < 58)		// If input is a number, read all the digits
			{
				do
				{
					i = 10*i + (input-'0');
				}
				while((input = getchar())!=' ');
				stack_push(stk,i);						// push the number into the stack
				i = 0;
			}
			else if (input == '-')
			{
				if ((input = getchar()) == ' ')
				{
					ans = evaluate(stack_pop(stk),stack_pop(stk),45);
					stack_push(stk,ans);
				}
				else
				{										// When input is a negative number
					do
					{
						i = 10*i + (input-'0');
					}
					while((input = getchar())!=' ');
					stack_push(stk,i*(-1));
					i = 0;
				}
				
			}
			else if (input == ' ')
				continue;
			else										// If input is an operator , pop the recent two numbers, perform the 
			{											// Operation on them and push back the result into stack
				ans = evaluate(stack_pop(stk),stack_pop(stk),(int)input);
				stack_push(stk,ans);
			}
		}
		printf("%d\n",stack_pop(stk));					// The last element remaining in stack is final value of expression
	}
	return 0;
}