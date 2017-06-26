#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "List.c"
#include "stack.h"
#include "stack.c"

void main()
{
	int n;
	scanf("%d", &n);
	
	stack *open;
	int i,j;
	int *val;
	val = (int *)malloc(n * sizeof(int));
	
	char *s[n];
	
	for(i=0; i<n; i++)
	{
		val[i] = 1;
		open = stack_new();
		char bracket;
		s[i] = (char *)malloc(1000 * sizeof(char));
		
		scanf("%s", s[i]);
		
		for(j=0; s[i][j]!='\0'; j++)
		{
			if(s[i][j] == '(' || s[i][j] == '{' || s[i][j] == '[')
				stack_push(open, s[i][j]);
			else
			{
				if(stack_is_empty(open))
					val[i] = 0;
				else
				{
					bracket = stack_pop(open);
					if(!((s[i][j] == ')' && bracket == '(') || (s[i][j] == '}' && bracket == '{') || (s[i][j] == ']' && bracket == '[')))
						val[i] = 0;
				}
			}
		}
		if(val[i] == 1 && !stack_is_empty(open))
			val[i] = 0;		
	}
	
	for(i=0; i<n; i++)
	{
		printf("%d\n", val[i]);
	}
}
