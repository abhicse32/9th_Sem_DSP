// Driver program and logic for evaluating a postfix expression
// Author : Milind Srivastava
// Date : 16 Sep 2016

#include <stdio.h>
#include "stack.h"
#define EXPRESSION_MAX_SIZE 1000
#define NUMBER_MAX_SIZE 10

int main()
{
	char input[EXPRESSION_MAX_SIZE];

	stack* operands = stack_new();

	while(fgets(input, EXPRESSION_MAX_SIZE, stdin) != NULL) // reading till EOF
	{
		int i = -1;
		
		while(i == -1 || (input[i] != '\0' && input[i] != '\n'))
		{
			if((input[i+1] >= '0' && input[i+1] <= '9') || (input[i+1] == '-' && input[i+2] != ' ')) // while next input is a number
			{
				char number[NUMBER_MAX_SIZE];
				int count = 0;
				while(input[i+1] != '\0' && input[i+1] != '\n' && input[i+1] != ' ')
				{
					number[count] = input[i+1];
					i++;
					count++;
				}
				number[count] = '\0';
				int num = atoi(number); // calculate number from string
				stack_push(operands, num); // push number onto stack
			}
			else if(input[i+1] != '\0' && input[i+1] != '\n' && input[i+1] != ' ') // if it is an operator
			{
				int temp2 = stack_pop(operands); // pop top 2 elements
				int temp1 = stack_pop(operands);
				int result;
				switch(input[i+1]) // calculate result
				{
					case '+':result = temp1 + temp2;
					break;

					case '-':result = temp1 - temp2;
					break;

					case '*':result = temp1 * temp2;
					break;

					case '/':result = temp1 / temp2;
					break;

					case '&':result = temp1 & temp2;
					break;

					case '|':result = temp1 | temp2;
					break;

					case '^':result = temp1 ^ temp2;
					break;

					case '%':result = temp1 % temp2;
					break;
				}
				stack_push(operands, result); // push result onto stack
			}
			i++;
		}

		stack_print(operands); // print stack

		while(!stack_is_empty(operands)) // empty stack so that it is ready for next expression
		{
			int temp = stack_pop(operands);
		}

		printf("\n");
	}

	return 0;
}