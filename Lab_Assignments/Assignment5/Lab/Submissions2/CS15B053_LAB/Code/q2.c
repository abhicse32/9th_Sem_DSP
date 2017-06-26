#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"
#include "List.c"
#include "stack.h"
#include "stack.c"


int get_top(stack *s)
{
	return s->top->head->data;
}



void main()
{
	int n;
	scanf("%d", &n);
	
	int i,j, closed, count, x;
	int *rev;
	rev = (int *)malloc(n * sizeof(int));
	stack *brac;
	
	char *s[n];
	
	for(i=0; i<n; i++)
	{
		rev[i] = -1;
		brac = stack_new();
		closed = 0;

		s[i] = (char *)malloc(1000 * sizeof(char));		
		scanf("%s", s[i]);

		if(strlen(s[i]) % 2 != 0)
			continue;

		for(j=0; s[i][j]!='\0'; j++)
		{
			if(s[i][j] == '{')
				stack_push(brac, s[i][j]);
			else
			{
				if(stack_is_empty(brac))
				{
					stack_push(brac, s[i][j]);	
					closed++;
				}
				else if(get_top(brac) == '{')
					x = stack_pop(brac);
				else
				{
					stack_push(brac, s[i][j]);
					closed++;
				}
			}
		}
		count = stack_size(brac);
		if(closed % 2 == 0)
			rev[i] = count/2;
		else
			rev[i] = count/2 + 1;		
	}
		
	for(i=0; i<n; i++)
	{
		printf("%d\n", rev[i]);
	}
}
