// Driver program and logic for converting infix expression to postfix and printing it
// Author : Milind Srivastava
// Date : 16 Sep 2016

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define MAX_SIZE 1000 // maximum size of expression

int ISP (int);
int ICP (int);

int main()
{
	char input[MAX_SIZE];
	char* token;

	stack* operators = stack_new();

	while(fgets(input, MAX_SIZE, stdin) != NULL) // while EOF is not reached
	{
		token = strtok(input, " "); // split input using " " as delimiter
		while(token != NULL)
		{
			if(token[strlen(token) - 1] == '\n') // if last character is '\n' and rest of the string denotes a variable
			{
				if((token[0] >= 'A' && token[0] <= 'Z') || (token[0] >= 'a' && token[0] <= 'z') || (token[0] <= '9' && token[0] >= '0'))
				{
					int i = 0;
					while(i < (strlen(token) - 1)) // print the variable but not the newline
					{
						printf("%c", token[i]);
						i++;
					}
					printf(" ");
				}
			}

			else if((token[0] >= 'A' && token[0] <= 'Z') || (token[0] >= 'a' && token[0] <= 'z') || (token[0] <= '9' && token[0] >= '0')) // if token is a variable, print it
			{
				printf("%s ", token);
			}
			else
			{
				if(token[0] == ' ') // if token is a space, ignore
				{
					continue;
				}
				else if(token[0] == '(') // if token is a left bracket, push it onto the stack
				{
					stack_push(operators, (int)token[0]);
				}
				else if(token[0] == ')') // if token is a right bracket, pop till a left bracket is reached
				{
					while(stack_size(operators)>0)
					{
						int temp = stack_pop(operators);
						if(temp == (int)'(')
						{
							break;
						}
						else
						{
							printf("%c ", temp);
						}
					}
				}
				else
				{
					int icp = ICP((int)token[0]); // icp of token
					int isp = -2; // default value of isp
					int temp;
					if(stack_is_empty(operators)) // if stack is empty, do nothing
					{
						;
					}
					else // equivalent to peeking stack and calculating isp
					{
						temp = stack_pop(operators); // pop element
						isp = ISP(temp); // store isp
						stack_push(operators, temp); // push element back
					}
					while(icp <= isp && stack_size(operators) > 0)
					{
						int temp = stack_pop(operators);
						printf("%c ", temp); // print popped element

						if(stack_is_empty(operators)) // if stack is empty break
						{
							break;
						}
						temp = stack_pop(operators); // quivalent to peeking stacking and calculating isp
						isp = ISP(temp);
						stack_push(operators, temp);
					}
					stack_push(operators, (int)token[0]); // push token onto stack
				}
			}

			token = strtok(NULL, " "); // calculating next token
		}
		while(stack_size(operators) > 0)
		{
			int temp = stack_pop(operators);
			if(temp != (int)'(' && temp != (int)')') // print contents of stack except brackets
			{
				printf("%c ", temp);
			}
		}
		printf("\n");
	}

	return 0;
}

int ISP (int x) // function to return In Stack Priority
{
	char temp = (char)x;
	switch(temp)
	{
		case '%':
		case '*':
		case '/':return 5;
		case '+':
		case '-':return 4;
		case '&':return 3;
		case '^':return 2;
		case '|':return 1;
		default:return -1;
	}
}

int ICP (int x) // function to return InComing Priority
{
	char temp = (char)x;
	switch(temp)
	{
		case '%':
		case '*':
		case '/':return 5;
		case '+':
		case '-':return 4;
		case '&':return 3;
		case '^':return 2;
		case '|':return 1;
		default:return -1;
	}
}