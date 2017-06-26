// to check if an sequence of brackets are balanced [{()}]

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int isbalanced(char* arr)
{
	stack* stk = stack_new();

	int i;
	for(i=0; arr[i] != 0; i++)
	{

		if(arr[i] == '{' || arr[i] == '[' || arr[i] == '(')
			stack_push(stk , arr[i]);

		else if(arr[i] == '}' || arr[i] == ']' || arr[i] == ')')
		{
			if(stack_is_empty(stk))
				{ free(stk); return 0;}

			char x = stack_pop(stk);

			if(arr[i] == '}' && x!= '{')
				{ free(stk); return 0;}
			if(arr[i] == ']' && x!= '[')
				{ free(stk); return 0;}
			if(arr[i] == ')' && x!= '(')
				{ free(stk); return 0;}
		}
	}

	if(stack_is_empty(stk))
		{ free(stk); return 1;}
	else
		{ free(stk); return 0;}
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t>0)
	{
	char* arr = (char*) malloc (sizeof(char) * 1000) ;
	scanf("%s", arr);

	printf("%d\n", isbalanced(arr));

	free(arr);
	t--;
	}

	return 0;
}