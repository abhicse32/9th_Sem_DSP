/* To evaluate the value of Postfix Expression.
   Author: CS15B046 Jahnvi Patel
   Date: September 12th, 2016*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int Convert(char expr[])
{
	stack* s=stack_new();
	stack_push(s,INT_MIN);
	int i=0;
	
	while(expr[i]!='\0')
	{
		char ch=expr[i];
		if(ch!=' ' && ch!='\n')
			
		{
			int num=0;
			int flag=0;


			/*Forming the number*/
			if((ch>='0'&& ch<='9') || (ch=='-' && expr[i+1]!=' '))
			{
				if(ch=='-')
					{
						flag=1;
						i++;
						ch=expr[i];
					}

				while(ch!=' ')
				{	
					num=num*10+ch-48;
					i++;
					ch=expr[i];
				}
				if(flag==1)
					num*=-1;

		/*Push the number in stack*/
			stack_push(s,num);

			}
					
			else if(s->top->head->data!=INT_MIN)
				{	/*If operator encountered, pop two operands and perform the required operation 
						and push the result back in stack */
					int op1,op2;
					op1=stack_pop(s);
					op2=stack_pop(s);

	
					if(ch=='+')
						stack_push(s,op2 + op1);
					else if(ch=='-')
						stack_push(s,op2 - op1);
					else if(ch=='*')
						stack_push(s,op2 * op1);
					else if(ch=='/')
						stack_push(s,op2 / op1);
					else if(ch=='%')
						stack_push(s,op2 % op1);
					else if(ch=='&')
						stack_push(s,op2 & op1);
					else if(ch=='|')
						stack_push(s,op2 | op1);
					else if(ch=='^')
						stack_push(s,op2 ^ op1);


				}
					
	}

	
	i++;
	}
	
	//The last value left in the stack gives the result of desired expression
	return s->top->head->data;
}


void main(int* argc, char* argv[])
{
	
	char str[1000];
	while(fgets(str,1000,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		printf("%d\n",Convert(str));
	}
}