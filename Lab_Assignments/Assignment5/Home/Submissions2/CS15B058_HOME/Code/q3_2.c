//Program to evaluate a postfix expression,Author:B Arjun,CS15B058
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <ctype.h>
int main(void)
{
	stack* operandstack=stack_new();
	char s[1000];
	while(fgets(s,1000,stdin)!=NULL)
	{
		int i,j;
		for(i=0;s[i]!='\n';i++);
		s[i]=' ';
		int flag=1;	
		int isneg=0;
		for(i=0,j=0;s[i]!='\0';i++)
		{
			if(s[i]==' ')			//if its space we push operand from j to i-1
			{
				if(j<i)			//to avoid a case where there is extra space
				{
					int k,l;
					char s1[1000];
					for(k=j,l=0;k<i;k++,l++)
						s1[l]=s[k];
					s1[l]='\0';
					int operand=atoi(s1);
					stack_push(operandstack,operand);		//we push operand into stack
					j=i+1;
				}
			}
			
			else if(s[i]=='-'&&isalnum(s[i+1]))			//if the number is negative dont consider it as operator
				continue;
			else if(!isalnum(s[i]))
			{
				
				if(stack_size(operandstack)<2)		//if less than 2 operands means invalid expression
				{
					flag=-1;
					break;
				}
				int x2=stack_pop(operandstack);
				int x1=stack_pop(operandstack);
				int result;
				switch(s[i])
				{
					case '*':{
								result=x1*x2;
								break;
							}
					case '/':{
								result=x1/x2;
								break;
							}
					case '%':{
								result=x1%x2;
								break;
							}
					case '+':{
								result=x1+x2;
								break;
							}
					case '-':{
								result=x1-x2;
								break;
							}
					case '&':{
								result=x1&x2;
								break;
							}
					case '|':{
								result=x1|x2;
								break;
							}
					case '^':{
								result=x1^x2;
								break;
							}														
				}
				stack_push(operandstack,result);	//we push result of operation on 2 operands at the top into stack
				i++;
				j+=2;			//next operand can only be after 2 characters
			}
		
		}
		if(stack_size(operandstack)!=1)				//if there are operands which are not used, invalid
			flag=-1;
		if(flag==1)
			printf("%d\n",stack_pop(operandstack));			//last element in operandstack will be the result
		else
			printf("Invalid\n");
	}
}