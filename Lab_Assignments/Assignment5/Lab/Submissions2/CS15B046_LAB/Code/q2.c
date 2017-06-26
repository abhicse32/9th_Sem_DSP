/*To check the minimum no. of reversals required in a given string
  Author: CS15B046 Jahnvi Patel
  September 16th, 2016*/

#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>

/*Returns the number of reversals if can be balanced, -1 otherwise*/
int reversals(char str[])
{
	stack* s=stack_new();
	int i=0,rev=0;
	/*Remove all balanced pairs of paranthesis*/
	while(str[i]!='\0')
	{
		char ch=str[i];
		
		if(ch=='{')
			stack_push(s,ch);
		else if(ch=='}' && !stack_is_empty(s))
			if(s->top->head->data=='{')
				stack_pop(s);
			else stack_push(s,ch);
		else stack_push(s,ch);

		i++;
	}
	/*If all balanced, return 0*/
	if(stack_is_empty(s))
		return 0;
	/*If odd number left of brackets left, cannot be balanced*/
	if(stack_size(s)%2==1)
		return -1;
	/*Otherwise checks eaqh bracket and pairs it up with the one before it in the stack and counts reversals accordingly*/
	while(!stack_is_empty(s))
	{
		char ch=stack_pop(s);
		if(ch=='}')
			{
				rev++;
				char temp=stack_pop(s);
			}
		else if(ch=='{')
		{
			char temp=stack_pop(s);
			if(temp=='{')
				rev++;
			else rev+=2;
		}
	}

	return rev;
	

}


int main()
{
	//Number of test cases
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
		char expr[1000];
		scanf("%s",expr);
		printf("%d\n",reversals(expr));

	}
	
	return 0;
	
}

