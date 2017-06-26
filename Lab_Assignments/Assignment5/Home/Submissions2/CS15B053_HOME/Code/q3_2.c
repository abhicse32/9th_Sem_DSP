#include "List.h"
#include "List.c" 
#include "stack.h" 
#include "stack.c" 

#include <stdio.h>
#include <stdlib.h>


int evaluate(int *exp, int *exptype, int k)
{
	stack *s = stack_new();

	int op1, op2;
	int i;

	for(i=0; i<k; i++)
	{
		
		printf("\n %d \n", exptype[i]);

		if(exptype[i] == -1)
		{
			op1 = stack_pop(s);
			op2 = stack_pop(s);

			if(exp[i] == '+')
				stack_push(s, op2 + op1);
			else if(exp[i] == '-')
				stack_push(s, op2 - op1);
			else if(exp[i] == '*')
				stack_push(s, op2 * op1);
			else if(exp[i] == '/')
				stack_push(s, op2 / op1);			
		}
		else
			stack_push(s, exp[i]);

		stack_print(s);
		
			
	}
	return stack_pop(s);
}





void main()
{
	char *post;
	post = (char *)malloc(sizeof(char));

	int *exp, *exptype;
	exp = (int *)malloc(sizeof(int));
	exptype = (int *)malloc(sizeof(int));

	printf("Enter postfix expression : ");
	scanf ("%[^\n]%*c", post);

	printf("%s\n", post);

	int i, k=0, num;
	for(i=0; post[i] != '\0'; i++)
	{
		if(post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/')
		{
			exp[k] = post[i];
			exptype[k] = -1; 
			printf("%d exptyp", exptype[k]);
			k++;
		}
		else if(post[i] != ' ')
		{
			num = 0;
			while(post[i] != ' ')
			{
				num = num * 10 + (post[i] - 48);
				i++;
			}
			exp[k] = num;
			exptype[k] = 1;
			printf("%d exptyp", exptype[k]);
			k++;
		}
	}
	for(i=0; i<k; i++)
		printf("%d ", exptype[i] );
	printf("%d\n", evaluate(exp, exptype, k));
}