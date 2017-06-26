#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char top_ele(stack* stk)									//Returns the value of top element in stack
{
	char ch;
	ch=(char)stk->top->head->data;
	return ch;
}

int priority(char ch)										//Every operator has its own precedence value
{
	if(ch=='*' || ch=='/' || ch=='%') return 5;
	if(ch=='+' || ch=='-') return 4;
	if(ch=='&') return 3;
	if(ch=='^') return 2;
	if(ch=='|') return 1;
	if(ch=='(') return 0;
	
}

int is_operator(char ch)									//Checks if the given character is an operator
{
	if(ch=='*' || ch=='/' || ch=='+' || ch=='-' || ch=='|' || ch=='%' || ch=='&' || ch=='^') return 1;
	return 0;
}

void In_To_Post(stack* stk,char exp[])						//Function converts infix expression to postfix
{
	int i;
	char x;
	for(i=0;exp[i]!='\n';i++)
	{ 
		if(isalnum(exp[i]))									//Checks if the character is an alphabet or a number
		{
			if(isalnum(exp[i+1])) printf("%c",exp[i]);		//Checks if it is a multi-digit number or a word
			else printf("%c ",exp[i]);
		}
		else if(is_operator(exp[i]) || exp[i]=='(' || exp[i]==')')	//Checks if it is not ' '(space)
		{
			if(exp[i]=='(') stack_push(stk,(int)'(');				//Push '(' into the stack
			else 
			{
				if(exp[i]==')')
				{
					while((x=stack_pop(stk))!='(') printf("%c ",x);	//Pops all the elements till '(' and prints them
				}
				else												//exp[i] is now an operator
				{
					while(!stack_is_empty(stk) && priority(exp[i])<=priority(top_ele(stk))) 
					{
						x=stack_pop(stk);							//Pops the operator in stack
						printf("%c ",x);
					}
					stack_push(stk,exp[i]);							
				}	
			}
			if(exp[i+1]==' ') i++;									//Ignore spaces
		}	 
	}
	while(!stack_is_empty(stk))										//Prints the remaining elements in stack
	{
		x=stack_pop(stk);
		printf("%c ",x);
	}
	printf("\n");
}

int main()
{
	char exp[1000];
	while(fgets(exp,1000,stdin)!=NULL)								//Takes input til EOF
	{
		stack* stk;
		stk=stack_new();
		In_To_Post(stk,exp);
	}
	return 0;
}	
