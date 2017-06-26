#include <stdio.h>
#include "stack.h"
#include "List.h"
#include <string.h>

int check_op(char ch) //checks if character is an operator
{
	switch(ch)
	{
		case '+':
		case '-':
		case '/':
		case '*':
		case '^':
		case '&':
		case '|':
		case '%':
		case '(':
		case ')': return 1;
		default: return 0;

	}
}



int precedence(char ch)
{
	switch(ch)
	{
		case '+': return 3;
		case '-': return 3;
		case '/': return 4;
		case '*': return 4;
		case '&': return 2;
		case '%': return 4;
		case '^': return 1;
		case '|': return 0;
		case '(': return -1;
		case ')': return -1;
	}
}


void master(char s[], int size)
{
	char temp[15];
	int i=0, j, flag;

	stack* opstk = stack_new();

	while(i < size)
	{	

	// stores the name of the variable in temp 
	// returns the index after the space
	// ready to get the next variable

		int k=0;
		while((s[i]!=' ') && (s[i] != '\n') && (i != size))
		{
			temp[k] = s[i];
			k++; i++;
		}

		if(s[i]==' ' || s[i]=='\n')
			(i)++;

		temp[k]='\0';

		char ch = temp[0];

		// if not an operator then print it
		if(! check_op(ch))
			printf("%s ",temp);
		
		// if operator start the decision tree
		if (check_op(ch))
		{ 	

			if(stack_is_empty(opstk)) 
				stack_push(opstk, ch);

			else if (ch =='(')
				stack_push(opstk, ch);

			else if (ch ==')')
			{
				int top = stack_pop(opstk);

				while(top != '(')
				{
					printf("%c ", top);
					top = stack_pop(opstk);
				}
			}

			else
			{
				int top = stack_top(opstk);

				if( top =='(' )
					stack_push(opstk, ch);
				
				else if( precedence(ch) > precedence(top))
					stack_push(opstk, ch);

				else if ( precedence(ch) <= precedence(top))
				{
					while( precedence(ch) <= precedence(top) && ! stack_is_empty(opstk))
					{
						top = stack_pop(opstk);
						printf("%c ",top);

						if(! stack_is_empty(opstk) )
							top = stack_top(opstk);
					}

					stack_push(opstk, ch);
				}

			}
		}
	}

	while(!stack_is_empty(opstk))
	{
		printf("%c ", stack_pop(opstk));
	}
}

int main(int argc, char* argv[])
{

	char s[100];
	//gets(s);
	while(fgets(s, 100, stdin) != NULL)
	{
		int len = strlen(s);
		//printf("%d\n", len );
		//puts(s);
		s[len] = '\0';
		master(s, len);
		printf("\n");
	}

	return 0;

}
