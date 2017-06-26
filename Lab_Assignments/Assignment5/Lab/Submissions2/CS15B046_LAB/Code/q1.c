/*To check if the pair of brackets are balanced or not
  Author: CS15B046 Jahnvi Patel
  September 16th, 2016
*/
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>

/*A function that returns 1 if paranthesis are balanced, 0 otherwise */
int check(char str[])
{
	stack* s=stack_new();
	
	int i=0,count=0;
	while(str[i]!='\0')
	{
		char ch=str[i];
		/*If opening bracket, push into the stack*/
		if(ch=='(' || ch=='{' || ch=='[')
			{
				count++;
				stack_push(s,ch);
			}
		/*If closing bracket encountered, then check if the popped out bracket is it's pair or not*/
		else if(ch==')' || ch=='}' || ch==']' )
		{ 
				
				if(!stack_is_empty(s))
				{
					count--;
					
					char temp=stack_pop(s);
				if(ch=='}' && temp!='{')
					return 0;
				else if(ch==')' && temp!='(')
					return 0;
				else if(ch==']' && temp!='[')
					return 0;
				}
				else return 0;
		}

		i++;
	}
	/*If no. of opening and closing brackets are equal, return true*/
if(count==0)
	return 1;
	
	return 0;

}

int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
		char expr[1000];
		scanf("%s",expr);
		printf("%d\n",check(expr));

	}
	
	return 0;
	
}

