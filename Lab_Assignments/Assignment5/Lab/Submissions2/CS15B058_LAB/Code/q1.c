//Program to check if parentheses are valid, Author: B Arjun, CS15B058
#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
int main(void)
{
	int t;
	scanf("%d",&t);
	
	int i;
	for(i=0;i<t;i++)
	{
		char s[1001];
		scanf("%s",s);
		int j;
		int flag=1; 				//to check if parenthesis mismatch happens
		stack *bracket=stack_new(); 		//stack to store parentheses
		for(j=0;s[j]!='\0';j++)
		{
			if(s[j]=='('||s[j]=='['||s[j]=='{') 		//if its opening bracket, just push
			{
				stack_push(bracket,s[j]);
			}
			else
			{
				char x=stack_pop(bracket); 		//if bracket is empty x=-1, so remaining conditions are still valid
				
				if(s[j]==')'&&x!='(')               //if ) doesnt match the parenthesis at top of stack
				{
					printf("0");
					flag=0;
					break;			
				}
				else if(s[j]==']'&&x!='[')	 //if ] doesnt match the parenthesis at top of stack
				{
					printf("0");
					flag=0;
					break;			
				}
				else if(s[j]=='}'&&x!='{') 	 //if } doesnt match the parenthesis at top of stack
				{
					printf("0");
					flag=0;
					break;			
				}
			}
		}
		if(stack_is_empty(bracket)&&flag==1)		//the expression is valid if stack is empty at end of input
		{
			printf("1");
		}
		else if(flag==1) 			//if mismatch wasnt found but there are elements in stack its invalid
		{
			printf("0");
		}
		printf("\n");
	}
}
