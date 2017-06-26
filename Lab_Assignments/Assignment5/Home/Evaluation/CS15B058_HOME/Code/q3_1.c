//Program to convert infix expression to postfix, Author: B Arjun, CS15B058
#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include<ctype.h>
int precedence(char a) 				//we make a function which gives a precedence mapping for each operator
{
	if(a=='(')
		return 0;
	else if(a=='|')
		return 1;
	else if(a=='^')
		return 2;
	else if(a=='&')
		return 3;
	else if(a=='+'||a=='-')
		return 4;
	else if(a=='*'||a=='/'||a=='%')
		return 5;
	else
		return 6;
}
int main(void)
{
	stack* operator=stack_new(); 			//stack to store operators
	char s[100];
	while(fgets(s,100,stdin)!=NULL)
	{
		int i,j;
		for(i=0;s[i]!='\n';i++);			//to make the new character stored because of fgets to space
		s[i]=' ';	
		for(i=0,j=0;s[i]!='\0';i++)
		{
			if(s[i]==' ')					//if a space is the string from previous space till this is operand
			{
				int k;
				for(k=j;k<=i;k++)
					printf("%c",s[k]);
				j=i+1;						//we set j to pos after space
			}

			else if(!isalnum(s[i]))			//if s[i] is an operator
			{
				if(precedence(s[i])==6)		//if its a closing bracket
				{
					while(!stack_is_empty(operator))
					{
						char x=stack_pop(operator);			//we pop all operators till the opening bracket
						if(precedence(x)==0)
							break;
						else
							printf("%c ",x);
					}
				}
				else
				{
					while(!stack_is_empty(operator))		
					{
						char x=stack_pop(operator);			//if prec(s[i]) is greater than top element or s[i] is opening bracket
						if(precedence(x)<precedence(s[i])||precedence(s[i])==0)		
						{
							stack_push(operator,x);
							stack_push(operator,s[i]);
							break;
						}
						else					//if precedence(s[i])>=precedence of top we print top operator
						{
							printf("%c ",x);
						}
					}
					if(stack_is_empty(operator))
						stack_push(operator,s[i]);
				}
				i++;			//we move i to next non space position(coz there wont be operand in i+1)
				j+=2;			//starting index of operator will be after 2 characters
			}
			

		}
		while(!stack_is_empty(operator))			//we pop all remaining operators
			printf("%c ",stack_pop(operator));
		printf("\n");
	}


}