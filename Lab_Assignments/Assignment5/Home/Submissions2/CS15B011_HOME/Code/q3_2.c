#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main()
{
	int i,j,k=0,b,c,x,net;
	
	for(j = 0; j < 10; j ++)
	{
	char d;
	i = 0;
	x = 0;
	char *a = (char*) malloc(sizeof(char)*1000);
	char *temp = (char*) malloc(sizeof(char)*20);
	stack* results = stack_new();
	Node* temphead = results->top->head;
	while((d = getchar()) != '\n')
	{
		a[i] = d;
		i++;
	}
	a[i] = '\0';
	for(i = 0; a[i] != '\0'; i++)
	{

		
		if(a[i] == '*')
		{
			b = stack_pop(results);
			c = stack_pop(results);
			stack_push(results,b*c);
			x++;
		}
		else if(a[i] == '/')
		{
			b = stack_pop(results);
			c = stack_pop(results);
			stack_push(results,c/b);
			x++;
		}
		else if(a[i] == '%')
		{
			b = stack_pop(results);
			c = stack_pop(results);
			stack_push(results,c%b);
			x++;
		}
		else if(a[i] == '+')
		{
			b = stack_pop(results);
			c = stack_pop(results);
			stack_push(results,b+c);
			x++;
		}
		else if(a[i] == '-')
		{
			if(a[i+1] != ' ')
			{
				temp[k] = '-';
				k++;
				x=0;
				continue;
			}
			b = stack_pop(results);
			c = stack_pop(results);
			stack_push(results,c-b);
			x++;
		}
		else if(a[i] == '&')
		{
			b = stack_pop(results);
			c = stack_pop(results);
			stack_push(results,b&c);
			x++;
		}
		else if(a[i] == '^')
		{
			b = stack_pop(results);
			c = stack_pop(results);
			stack_push(results,b^c);
			x++;
		}
		else if(a[i] == '|')
		{
			b = stack_pop(results);
			c = stack_pop(results);
			stack_push(results,b|c);
			x++;
		}
		else 
		{
			if(a[i] == ' ' && x == 1)
			{
				x = 0;
				continue;
			}
			if(a[i] == ' ' && x != 1)
			{
				temp[k] = '\0';
				net = atoi(temp);
				stack_push(results,net);
				k = 0;
				x = 0;
				continue;
			}
			if(a[i] != ' ')
			{
				temp[k] = a[i];
				k++;
			}
			
			
		}

	}
	printf("%d\n",stack_pop(results) );

	}

}