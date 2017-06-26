// to find the minimum reversals required to balance a dequence of braces {}

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int changes(char* arr)
{
	stack* stk = stack_new();

	int i, ctr=0;
	for(i=0; arr[i] != 0 ; i++)
	{
		if(arr[i] == '{')
			stack_push(stk , '{');

		else if(arr[i] == '}')
		{
			if(stack_is_empty(stk))
				{ ctr++; stack_push(stk , '{'); }
			else
				stack_pop(stk);
		}
	}

	if(stack_is_empty(stk))
		{ free(stk); return ctr;}
	else
		{ 
			if(stack_size(stk) % 2 != 0)
				{ free(stk); return -1; }
			else
			{	ctr = ctr + stack_size(stk)/2;     // when only opening braces still remain 
				free(stk); return ctr; 				// reverse half of them
			}
		}
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t>0)
	{
	char* arr = (char*) malloc (sizeof(char) * 1000) ;
	scanf("%s", arr);

	printf("%d\n", changes(arr));

	free(arr);
	t--;
	}

	return 0;
}