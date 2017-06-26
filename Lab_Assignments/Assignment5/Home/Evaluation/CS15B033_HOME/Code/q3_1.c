#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack
{
	int top;
	char data[1000];
}stack;

int priority(char a)
{
	switch(a)
	{
		case '|': return 0;
		case '^': return 1;
		case '&': return 2;
		case '+':
		case '-': return 3;
		case '*':
		case '/':
		case '%': return 4;
		case ')': return -1;
		case '(': return 6;
	}

}
int main()
{
	char a[1000];

	while( (fgets( a, 1000, stdin)) != NULL)
	{
		stack stk;
		stk.top = -1;
		int i;
		for( i=0; i<strlen(a); i++)
		{
			char x = a[i];
			if( x != '\0' && x != ' ' && x != '\n')
			{
				if( isalnum(x) && (a[i+1] == ' ' || a[i+1] == '\n'))
					printf("%c ", x);
				else if( isalnum (x))
					printf("%c", x);
				else
				{
					while( stk.top != -1 &&  priority(stk.data[stk.top]) >= priority(x) && stk.data[stk.top] != '(' )
					{
						if( stk.data[stk.top] != '(')
						{
							printf("%c ", stk.data[stk.top]);
							stk.top--;
						}
						else if( stk.data[stk.top] == '(' && x == ')')
						{
							stk.top--;
							break;
						}
					}
					if( stk.data[stk.top] == '(' && x == ')')
						stk.top--;
					if( x != ')')
					{
						stk.top ++;
						stk.data[stk.top] = x;
					}
				}
			}
		}
		while( stk.top != -1)
			{
				printf("%c ", stk.data[stk.top]);
				stk.top--;
			}
		printf("\n");
	}
	return 0;
}