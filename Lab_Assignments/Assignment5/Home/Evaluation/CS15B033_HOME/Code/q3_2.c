#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void operate( stack *numstk, char x)
{
	int num2 = stack_pop(numstk);
	int num1 = stack_pop(numstk);

	switch(x)
	{
		case '+': stack_push(numstk, num1+num2);break;
		case '-': stack_push(numstk, num1-num2);break;
		case '*': stack_push(numstk, num1*num2);break;
		case '/': stack_push(numstk, num1/num2);break;
		case '%': stack_push(numstk, num1%num2);break;
		case '|': stack_push(numstk, num1|num2);break;
		case '^': stack_push(numstk, num1^num2);break;
		case '&': stack_push(numstk, num1&num2);break;
	}
}

void evaluate( char *str, int len)
{
	stack *numstk = stack_new();
	char temp[10];
	int templen = 0;
	int i = 0;
	while( i<len )
	{
		if( str[i] != ' ')
		{
			if( !isdigit( str[i]) && str[i+1] == ' ' )
				{
					operate( numstk, str[i]);
					templen = 0;
				}

			else if( !isdigit(str[i]) && isdigit( str[i+1]) && i+1<len)
			{
				temp[templen++] = str[i];
			}
			else if( isdigit( str[i]) && str[i+1] == ' ')
			{
				temp[templen++] = str[i];
				temp[templen++] = '\0';
				stack_push(numstk, atoi(temp));
				templen = 0;
			}
			else if( isdigit(str[i]))
				temp[templen++] = str[i];
		}
		i++;
	}
	printf("%d\n", stack_pop(numstk));
}

int main()
{
	char exp[100];
	while(fgets( exp, 100, stdin))
		evaluate(exp, strlen(exp));
	return 0;
}