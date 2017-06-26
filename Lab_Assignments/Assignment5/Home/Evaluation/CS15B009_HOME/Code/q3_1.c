/*  Program to convert an infix mathematical expression into a postfix expression

	By : Chandrashekhar D --- Roll no.CS15B009 --- 17 Sept 2016  */

#include "stack.h"
#include <string.h>
#include <stdio.h>

/*  Declaration of constant operators for comparison  */
const char open = '(';
const char close = ')';

const char operators[8] = {'*','/','%','+','-','&','^','|'};

/*  Function to return the precedence of an operator on a scale of 1 to 5 */
int precedence(char c)
{
	if (c == '*' || c == '/' || c == '%')
		return 5;
	else if (c == '+' || c == '-')
		return 4;
	else if (c == '&')
		return 3;
	else if (c == '^')
		return 2;
	else
		return 1;
}

/*  Function to check if a given character is an operator  */
bool isOperator(char c)
{
	int i,isOp = false;
	for (i = 0;i < 8;i++)
	{
		if (c == operators[i])
			isOp = true;
	}
	return isOp;
}

/*  Main function  */
int main()
{
	char buf;
	while(!feof(stdin))		//	Reads input until end of file is reached
	{
		stack *stk = stack_new();
		char *s;
		char *spl;
		scanf("%[^\n]",s);				// Scans a string until newline character is reached (excludes newline)
		char *token = strtok(s," ");	// Splits a string using space " " as delimiter
		
		while(token)					// Loops as long as token is not NULL
		{
			spl = token;				// the consecutive substrings separated by spaces in original string
			
			if (isOperator(spl[0]))		// If the present substring is an operator
			{
				int p = precedence(spl[0]);
				if (!stack_is_empty(stk))
				{
					// pop and print all the operators with higher or equal precedence than the present one 
					while (p <= precedence((char)stk->top->head->data) && stk->top->head->data != 40)
					{
						char c = (char) stack_pop(stk);
						printf("%c ",c);
						if (stack_is_empty(stk))
							break;
					}
				}
				stack_push(stk,(int)spl[0]);	// Push the present operator
			}
			
			else if (spl[0] == open)
				stack_push(stk,(int)spl[0]);	// Push the character if it is an opening bracket
			
			else if (spl[0] == close)
			{
				while (!stack_is_empty(stk))	// If closing bracket, pop and print all operators until a corresponding opening
				{								// bracket is reached
					char c = (char) stack_pop(stk);
					if (c == open)
						break;
					printf("%c ",c);
				}
			}
			else
				printf("%s ",spl);				// If it is an operand, simply print the operand
			
			token = strtok(NULL," ");			// Increment the pointer to the next substring 
		}
		while(!stack_is_empty(stk))
			printf("%c ",(char)stack_pop(stk));	// Print all the remaining operators in the stack
		printf("\n");
		buf = getchar();						// captures the trailing newline character
	}
	return 0;
}