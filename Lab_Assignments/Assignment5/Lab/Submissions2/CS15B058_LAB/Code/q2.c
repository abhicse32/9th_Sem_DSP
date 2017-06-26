//Program to find minimum no. of reversals, Author: B Arjun, CS15B058
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
		stack *bracket=stack_new(); 		//stack to store curly brackets
		int rev=0;
		for(j=0;s[j]!='\0';j++)
		{
			if(s[j]=='{') 			//if opening bracket, push into stack
			{
				stack_push(bracket,s[j]);
			}
			else if(stack_is_empty(bracket)) 	//if } and empty stack, 1 reversal must be done and } becomes {.
			{
				rev++;
				stack_push(bracket,'{');
			}
			else 					//in this case there will be a matching for } so we just pop out
			{
				char x=stack_pop(bracket);		
			}	
		}
		int stcksize=stack_size(bracket);	//to find remaining number of {
		if(stcksize%2==1) 			//if odd no. of {, cannot be made valid
			printf("-1");
		else 					//if its even exactly half will be reversed
			printf("%d",rev+stcksize/2);
		printf("\n");
	}
}
