/* To Convert an Infix Expression to Postfix Expression.
   Author: CS15B046 Jahnvi Patel
   Date: September 12th, 2016*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

/*A function that returns the precedence of + - / % * & | ^ operators */
int priority(char op)
{
   	if(op == '(')
 		return(0);
  	 if(op == '+' || op == '-')
 		return(4);
   	if(op == '*' || op == '/' || op == '%')
 		return(5);
   	else if(op=='&')
   		return(3);
   	else if(op=='^')
   		return(2);
   	else if(op=='|')
   		return(1);
}

void Convert(char expr[])
{
	stack* s=stack_new();
	stack_push(s,INT_MIN);
	int i=0;
	while(expr[i]!='\0')
	{
		char ch=expr[i];
		
			/*If the current word is an operand, print it*/
			if(isalnum(ch) || (ch=='-' && isalnum(expr[i+1])))
			{
				
				
					do{
						printf("%c",ch);
						i++;
						ch=expr[i];
					}while(isalnum(ch));
				printf(" ");
				
			}

			else if(ch!=' ')
				{	
					/*If stack is empty or if an opening paranthesis encountered, push */
					if(s->top->head->data==INT_MIN)
						stack_push(s,ch);
					else if(ch=='(')
						stack_push(s,ch);
					else if(ch==')')
					{
						/*Pop till left bracket found*/
						char op=stack_pop(s);
							while(op!='(')
							{
								printf("%c ",op);
								op=stack_pop(s);
							}
					}

				
					else 
					{
						/*While priority inStack>= priority inComing, pop*/
						while(priority(s->top->head->data) >= priority(ch) && s->top->head->data!=INT_MIN)
						{
							char op=stack_pop(s);
							printf("%c ",op);
						}
						stack_push(s,ch);
					}
				}
	
		i++;
	}
	/*Pop remaining operators left in the stack*/
	while(s->top->head->data!=INT_MIN)
        printf("%c ",stack_pop(s));
    

printf("\n");
}


void main(int* argc, char* argv[])
{
	char str[1000];
	while(fgets(str,100,stdin)!=NULL)
	{
		str[strlen(str)-1]='\0';
		Convert(str);
	}
}