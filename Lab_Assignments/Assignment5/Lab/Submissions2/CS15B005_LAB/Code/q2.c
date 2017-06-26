#include <stdio.h>
#include "stack.h"
#include "List.h"
void main()
{
	int t, i, j, count=0;
	scanf("%d",&t);
	for( i=0 ; i < t ; i++)
	{
		int count=0;
		stack* S = stack_new();
		char str[1010];
		scanf("%s", str);
		for( j=0 ; str[j] != '\0' ; j++)
		{
			if(stack_is_empty(S))
			{
				stack_push( S, str[j]);
				continue;
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
		
		
		if((stack_size(S)%2)!=0 )
		{
			printf("-1\n");
			continue;
		}
		
		if(stack_size(S)==0)
		{
			printf("0\n");
			continue;
		}
		
		while(!stack_is_empty(S))
		{
			if ((S->top->head->data)== '}')
			{
				stack_pop(S);
				if((S->top->head->data) == '}')
				{
					stack_pop(S);
					count++;
					continue;
				}
				if((S->top->head->data) == '{')
				{
					stack_pop(S);
					count = count+2;
					continue;
				}
			}
			if ((S->top->head->data)== '{')
			{
				stack_pop(S);
				if((S->top->head->data) == '{')
				{
					stack_pop(S);
					count++;
					continue;
				}
				if((S->top->head->data) == '}')
				{
					stack_pop(S);
					count = count+2;
					continue;
				}
			}
		}
		printf("%d\n",count);
	}
	return;
}
