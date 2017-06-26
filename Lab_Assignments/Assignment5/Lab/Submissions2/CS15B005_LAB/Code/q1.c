#include <stdio.h>
#include "stack.h"
#include "List.h"
void main()
{
	int t, i;
	scanf("%d",&t);
	for( i=0 ; i < t ; i++)
	{
		stack* S = stack_new();
		char str[1010];
		scanf("%s", str);
		int j;
		for( j=0 ; str[j] != '\0' ; j++)
		{
			if(stack_is_empty(S))
			{
				stack_push( S, str[j]);
				continue;
			}
			if ((S->top->head->data)== '(')
			{
				if(str[j] == ')')
				{
					stack_pop(S);
					continue;
				}
			}
			if ((S->top->head->data)== '[')
			{
				if(str[j] == ']')
				{
					stack_pop(S);
					continue;
				}
			}
			if ((S->top->head->data)== '{')
			{
				if(str[j] == '}')
				{
					stack_pop(S);
					continue;
				}
			}
			
			stack_push( S, str[j]);
		}
		if(stack_is_empty(S))	printf("1\n");
		else	printf("0\n");
	}
	return;
}
