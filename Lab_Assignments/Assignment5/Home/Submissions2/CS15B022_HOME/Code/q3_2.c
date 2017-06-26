#include<stdio.h>
#include"List.h"
#include"stack.h"
#include<string.h>
#include<stdlib.h>
void evaluatepostfix(char POSTFIX[100]);
void main()
{
	int i =10;
	int j = 0;
	for(j = 0;j<10;j++)
	{
		char POSTFIX[100];
		fgets(POSTFIX,100,stdin);
		evaluatepostfix(POSTFIX);
	}
}	
void evaluatepostfix(char POSTFIX[100])
{
	stack *stack = stack_new();
	int i = 0;
	int j;
	while(POSTFIX[i] != '\n')
	{
	//printf("%d",i);
		if(POSTFIX[i] == '*' || POSTFIX[i] == '/' || POSTFIX[i] == '+' || POSTFIX[i] == '|' || POSTFIX[i] == '&' || POSTFIX[i] == '^' || POSTFIX[i] == '%')
		{
			int pop1 = stack_pop(stack);
			int pop2 = stack_pop(stack);
			int push;
			if(POSTFIX[i] == '*')
			{
				push = pop1*pop2;
				stack_push(stack,push);
			}
			else if(POSTFIX[i] == '/')
			{
				push = pop2/pop1;
				stack_push(stack,push);
			}
			else if(POSTFIX[i] == '+')
			{
				push = pop1+pop2;
				stack_push(stack,push);
			}
			else if(POSTFIX[i] == '|')
			{
				push = pop1|pop2;
				stack_push(stack,push);
			}
			else if(POSTFIX[i] == '&')
			{
				push = pop1&pop2;
				stack_push(stack,push);
			}
			else if(POSTFIX[i] == '^')
			{
				push = pop2^pop1;
				stack_push(stack,push);
			}
			else if(POSTFIX[i] == '%')
			{
				push = pop2%pop1;
				stack_push(stack,push);
			}
			i = i + 1;
		}
		 if(POSTFIX[i] == '-')
		 {
			if(POSTFIX[i+1] == ' ' || POSTFIX[i+1] == '\n' )
			{
				int pop11 = stack_pop(stack);
				int pop22 = stack_pop(stack);
				int push1 = pop22 - pop11;
				stack_push(stack,push1);
				i = i + 1;
			}
			else 
			{	i = i + 1;
				char String[100] ;
				int counter = 0;
				while(POSTFIX[i] != ' ')
				{
					String[counter] = POSTFIX[i];
					i = i + 1;
					counter = counter + 1;
				}
				String[counter] = '\0';
				int num = atoi(String);
				num = -num;
				stack_push(stack,num);
			}
		}
		if(POSTFIX[i] != '*' && POSTFIX[i] != '/' && POSTFIX[i] != '+' && POSTFIX[i] != '|' && POSTFIX[i] != '&' && POSTFIX[i] != '^' && POSTFIX[i] != '%' && POSTFIX[i] != '-' && POSTFIX[i]!=' ' && POSTFIX[i]!='\n' && POSTFIX[i]!='\n')
		{
			char String1[100];
			int counter1 = 0;
			while(POSTFIX[i] != ' ')
			{
				String1[counter1] = POSTFIX[i];
				counter1 = counter1 + 1;
				i = i + 1;
			}
			String1[counter1] = '\0';
			int num1 = atoi(String1);
			//printf("%d\n",num1);
			stack_push(stack,num1);
		}
		if(POSTFIX[i] == ' ')
		{
			i = i + 1;
		}
	}
	int ans = stack_pop(stack);
	printf("%d\n",ans);
}
