#include<stdio.h>
#include"List.h"
#include"stack.h"
#include<stdlib.h>
#include<string.h>
void convertinfixtopostfix(char INFIX[100]);
void main()
{	int i = 0;
	for(i = 0;i<10;i++)
	{
		char INFIX[100];
		fgets(INFIX,100,stdin);
		 convertinfixtopostfix(INFIX);
	} 
}
void convertinfixtopostfix(char INFIX[100])
{
	char POSTFIX[100];
	int counter = 0;
	char pop;
	stack *stack = stack_new();
	int i = 0;
	while(INFIX[i] != '\n' )
	{
		if(INFIX[i] != '+' && INFIX[i] != '-' && INFIX[i] != '*' && INFIX[i] != '/' && INFIX[i] != '%' && INFIX[i] != '|' && INFIX[i] != '&' && INFIX[i] != '^' && INFIX[i] != '(' && INFIX[i] != ')' )
		{
			 while(INFIX[i] != '+' && INFIX[i] != '-' && INFIX[i] != '*' && INFIX[i] != '/' && INFIX[i] != '%' && INFIX[i] != '|' && INFIX[i] != '&' && INFIX[i] != '^'&& INFIX[i] != '\n' && INFIX[i] != ')' && INFIX[i] != '(')
			 {
			 	POSTFIX[counter] = INFIX[i];
			 	i = i + 1;
			 	counter = counter + 1;
			 }
		}
		else 
		{
			if(INFIX[i] == '+')
			{
				if(stack_is_empty(stack) == true)
				{
					stack_push(stack,INFIX[i]);
					i = i + 2;
				}
				else
				{
					pop = stack_pop(stack);
					if(pop == '&' || pop == '^' || pop == '|' || pop == '(')
					{
						stack_push(stack,pop);
						stack_push(stack,INFIX[i]);
						i = i + 2;
					}
					else 
					{
						if(pop == '+' || pop == '-' || pop == '*' || pop == '/' || pop == '%' )
						{	
							while(pop != '&' && pop != '^' && pop != '|' && pop != '(')
							{	
								POSTFIX[counter] = pop;
								counter = counter + 1;
								if(POSTFIX[counter-1] != ' ')
								{
									POSTFIX[counter] = ' ';
									counter = counter + 1;
								}
								if(stack_is_empty(stack) == false)
								{
									pop = stack_pop(stack);
								}
								else
								{
									break;
								}
							}
							if(pop == '&' || pop == '^' || pop == '|' || pop == '(')
							{
								stack_push(stack,pop);
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}
							else if(pop == '+' || pop == '-' || pop == '*' || pop == '/' || pop == '%' )
							{
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}
						}
					}
				}
			}
			if(INFIX[i] == '-')
			{
				if(stack_is_empty(stack) == true)
				{
					stack_push(stack,INFIX[i]);
					i = i + 2;
				}
				else
				{
					pop = stack_pop(stack);
					if(pop == '&' || pop == '^' || pop == '|' || pop == '(')
					{
						stack_push(stack,pop);
						stack_push(stack,INFIX[i]);
						i = i + 2;
					}
					else
					{
						if(pop == '+' || pop == '-' || pop == '*' || pop == '/' || pop == '%' )
						{
							while(pop != '&' && pop != '^' && pop != '|' && pop != '(')
							{
								POSTFIX[counter] = pop;
								counter = counter + 1;
								if(POSTFIX[counter-1] != ' ')
								{
									POSTFIX[counter] = ' ';
									counter = counter + 1;
								}
								if(stack_is_empty(stack) == false)
								{
									pop = stack_pop(stack);
								}
								else
								{
									break;
								}
							}
							if(pop == '&' || pop == '^' || pop == '|' || pop == '(')
							{
								stack_push(stack,pop);
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}
							else if(pop == '+' || pop == '-' || pop == '*' || pop == '/' || pop == '%')
							{
								stack_push(stack,INFIX[i]);
								i = i + 2;
							} 
						}
					}
				}
			}
			if(INFIX[i] == '*')
			{
				if(stack_is_empty(stack) == true)
				{
					stack_push(stack,INFIX[i]);
					i = i + 2;
				}
				else
				{
					pop = stack_pop(stack);
					if(pop == '&' || pop == '^' || pop == '|' || pop == '+' || pop == '-' || pop == '(')
					{
						stack_push(stack,pop);
						stack_push(stack,INFIX[i]);
						i = i + 2;
					}
					else
					{
						if( pop == '*' || pop == '/' || pop == '%' )
						{	
							while(pop != '&' && pop != '^' && pop != '|' && pop != '+' && pop != '-' && pop != '(')
							{	
								POSTFIX[counter] = pop;
								counter = counter + 1;
								if(POSTFIX[counter-1] != ' ')
								{
									POSTFIX[counter] = ' ';
									counter =counter + 1;
								}
								if(stack_is_empty(stack) == false)
								{
									pop = stack_pop(stack);
								}
								else
								{
									break;
								}
							}	
							if(pop == '&' || pop == '^' || pop == '|' || pop == '+' || pop == '-' || pop == '(')
							{
								stack_push(stack,pop);
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}
							else if(pop == '*' || pop == '/' || pop == '%')
							{
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}
						}
					}
				}
			}
			if(INFIX[i] == '/')
			{
				if(stack_is_empty(stack) == true)
				{
					stack_push(stack,INFIX[i]);
					i = i + 2;
				}
				else
				{
					pop = stack_pop(stack);
					if(pop == '&' || pop == '^' || pop == '|' || pop == '+' || pop == '-' || pop == '(')
					{
						stack_push(stack,pop);
						stack_push(stack,INFIX[i]);
						i = i + 2;
					}
					else
					{ 
						if( pop == '*' || pop == '/' || pop == '%' )
						{	
							while(pop != '&' && pop != '^' && pop != '|' && pop != '+' && pop != '-' && pop != '(')
							{
								POSTFIX[counter] = pop;
								counter = counter + 1;
								if(POSTFIX[counter - 1] != ' ')
								{
									POSTFIX[counter] = ' ';
									counter = counter + 1;
								}
								if(stack_is_empty(stack) == false)
								{
									pop = stack_pop(stack);
								}
								else
								{
									break;
								}
							}
							if(pop == '&' || pop == '^' || pop == '|' || pop == '+' || pop == '-' || pop == '(')
							{
								stack_push(stack,pop);
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}
							else if(pop == '*' || pop == '/' || pop == '%' )
							{
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}
						}
					}
				}
			}
			if(INFIX[i] == '%')
			{
				if(stack_is_empty(stack) == true)
				{
					stack_push(stack,INFIX[i]);
					i = i + 2;
				}
				else
				{
					pop = stack_pop(stack);
					if(pop == '&' || pop == '^' || pop == '|' || pop == '+' || pop == '-' || pop == '(')
					{
						stack_push(stack,pop);
						stack_push(stack,INFIX[i]);
						i = i + 2;
					}
					else
					{
						if( pop == '*' || pop == '/' || pop == '%' )
						{
							while(pop != '&' && pop != '^' && pop != '|' && pop != '+' && pop != '-' && pop != '(')
							{
								POSTFIX[counter] = pop;
								counter = counter + 1;
								if(POSTFIX[counter - 1] != ' ')
								{
									POSTFIX[counter] = ' ';
									counter = counter + 1;
								}
								if(stack_is_empty(stack) == false)
								{
									pop = stack_pop(stack);
								}
								else
								{
									break;
								}
							}
							if(pop == '&' || pop == '^' || pop == '|' || pop == '+' || pop == '-' || pop == '(')
							{
								stack_push(stack,pop);
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}
							else if(pop == '*' || pop == '/' || pop == '%' )
							{
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}

						}
					}
				}
			}
			if(INFIX[i] == '&')
			{
				if(stack_is_empty(stack) == true)
				{
					stack_push(stack,INFIX[i]);
					i = i + 2;
				}
				else
				{
					pop = stack_pop(stack);
					if( pop == '^' || pop == '|' || pop == '(')
					{
						stack_push(stack,pop);
						stack_push(stack,INFIX[i]);
						i = i + 2;
					}
					else
					{
						if( pop == '&' || pop == '*' || pop == '/' || pop == '%' || pop == '+' || pop == '-')
						{
							while(pop != '^' && pop != '|' && pop != '(')
							{
								POSTFIX[counter] = pop;
								counter = counter + 1;
								if(POSTFIX[counter - 1] != ' ')
								{
									POSTFIX[counter] = ' ';
									counter = counter + 1;
								}
								if(stack_is_empty(stack) == false)
								{
									pop = stack_pop(stack);
								}
								else
								{
									break;
								}
							}
							if(pop == '^' || pop == '|' || pop == '(')
							{
								stack_push(stack,pop);
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}
							else if(pop == '&' || pop == '*' || pop == '/' || pop == '%' || pop == '+' || pop == '-')
							{
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}

						}
					}
				}
			}
			if(INFIX[i] == '^')
			{
				if(stack_is_empty(stack) == true)
				{
					stack_push(stack,INFIX[i]);
					i = i + 2;
				}
				else
				{
					pop = stack_pop(stack);
					if(  pop == '|' || pop == '(')
					{
						stack_push(stack,pop);
						stack_push(stack,INFIX[i]);
						i = i + 2;
					}
					else
					{
						if(pop == '^' || pop == '&' || pop == '*' || pop == '/' || pop == '%' || pop == '-' || pop == '+')
						{
							while( pop != '|' && pop != '(')
							{
								POSTFIX[counter] = pop;
								counter = counter + 1;
								if(POSTFIX[counter - 1] != ' ')
								{
									POSTFIX[counter] = ' ';
									counter = counter + 1;
								}
								if(stack_is_empty(stack) == false)
								{
									pop = stack_pop(stack);
								}
								else
								{
									break;
								}
							}
							if( pop == '|' || pop == '(')
							{
								stack_push(stack,pop);
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}
							else if(pop == '^' && pop == '&' || pop == '*' || pop == '/' || pop == '%' || pop == '+' || pop == '-')
							{
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}

						}
					}
				}
			}			
			if(INFIX[i] == '|')
			{
				if(stack_is_empty(stack) == true)
				{
					stack_push(stack,INFIX[i]);
					i = i + 2;
				}
				else
				{
					pop = stack_pop(stack);
					if( pop == '(')
					{
						stack_push(stack,pop);
						stack_push(stack,INFIX[i]);
						i = i + 2;
					}
					else
					{
						if(pop == '|' || pop == '^' || pop == '&' || pop == '*' || pop == '/' || pop == '%' ||pop == '+' || pop == '-')
						{
							while( pop != '(')
							{
								POSTFIX[counter] = pop;
								counter = counter + 1;
								if(POSTFIX[counter - 1] != ' ')
								{
									POSTFIX[counter] = ' ';
									counter = counter + 1;
								}
								if(stack_is_empty(stack) == false)
								{
									pop = stack_pop(stack);
								}
								else
								{
									break;
								}
							}
							if(  pop == '(')
							{
								stack_push(stack,pop);
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}
							else if(pop == '|' && pop == '^' && pop == '&' || pop == '*' || pop == '/' || pop == '%' || pop == '+' || pop == '-')
							{
								stack_push(stack,INFIX[i]);
								i = i + 2;
							}

						}
					}
				}
			}			
            if(INFIX[i] == '(')
            {
            	if(stack_is_empty(stack) == true)
				{
					stack_push(stack,INFIX[i]);
					i = i + 2;
				}
				else
				{
					pop = stack_pop(stack);
					if( pop == '+'|| pop == '-' || pop == '*' || pop == '%' || pop == '/'|| pop == '^'|| pop == '&'|| pop == '|' || pop == '(')
					{
						stack_push(stack,pop);
						stack_push(stack,INFIX[i]);
						i = i + 2;
					}
				}
			}			
			if(INFIX[i] == ')')
			{
				pop = stack_pop(stack);
				while(pop != '(')
				{
					POSTFIX[counter] = pop;
					counter = counter + 1;
					POSTFIX[counter] = ' ';
					counter = counter + 1;
					pop = stack_pop(stack);
				}
				i = i + 2;
			}
		}
		if(INFIX[i-1] == '\n')
		{
			break;
		}
}

if(stack_is_empty(stack) == true)
{
	int j ;
	for(j = 0;j<=counter;j++)
	{
		printf("%c",POSTFIX[j]);
	}
}
else
{	int l;
	while(stack_is_empty(stack) == false)
	{
		pop = stack_pop(stack);
		if(POSTFIX[counter - 1] != ' ')
		{
		POSTFIX[counter] = ' ';
		counter = counter + 1;
		}
		POSTFIX[counter] = pop;
		counter = counter + 1;
	}
	for(l = 0;l<counter;l++)
	{
		printf("%c",POSTFIX[l]);
	}
	printf("\n");
}
}
	

					
			
