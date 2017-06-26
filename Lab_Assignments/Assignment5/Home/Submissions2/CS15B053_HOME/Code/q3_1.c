#include "List.h"
#include "List.c" 
#include "stack.h" 
#include "stack.c" 

#include <stdio.h>

int get_top(stack *s)
{
	return s->top->head->data;
}



int precedence(char op) //returns 1 if precedence of op1 is higher, -1 if precedence of op1 is lower, 0 if they are of equal precedence 
{
	if(op == '+' || op == '-')
		return 1;
	else if(op == '*' || op == '/')
		return 2;
	else
		return -1;
}



void convertexp(char *exp, char *post)
{
	
	stack *s = stack_new();

	int i, pi = 0;
	char x;
	
	for(i=0; exp[i]!='\0'; i = i+2)
	{
		if((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z'))
		{
			post[pi++] = exp[i];
			post[pi++] = ' ';
		}

		else if(exp[i] =='(')
			stack_push(s, exp[i]);

		else if(exp[i] == ')')
		{
			while (!stack_is_empty(s) && get_top(s) != '(')
			{
                post[pi++] = stack_pop(s);
                post[pi++] = ' ';
			}
            x = stack_pop(s);
		}

		else
		{
			while (!stack_is_empty(s) && precedence(exp[i]) <= precedence(get_top(s)))
			{
                post[pi++] = stack_pop(s);
                post[pi++] = ' ';
			}
            stack_push(s, exp[i]);
		}
	}
	while(!stack_is_empty(s))
	{
		post[pi++] = stack_pop(s);
		post[pi++] = ' ';
	}
	post[pi] = '\0';
}



void main()
{
	char *exp;
	exp = (char *)malloc(100 * sizeof(char));
	printf("Enter infix expression : ");
	scanf ("%[^\n]%*c", exp);

	char *post;
	post = (char *)malloc(100 * sizeof(char));

	convertexp(exp, post);
	printf("%s\n", post);

}	