#include<stdio.h>
#include "q1_stack.h"
#include "q1_list.h"
char count(char ch);

char count(char ch)
{
	if(ch=='{')
	return '}';
	if(ch=='(')
	return ')';
	if(ch=='[')
	return ']';
}


int main()
{	int t;
	scanf("%d",&t);
	int i;
	

for(i=0;i<t;i++)		//TESTCASES
{	

	int m=0;
	//enter the string 
        char s[1000];
	 
	scanf("%s",&s);
        			
	stack* s1;
	s1=stack_new();
		int j=0;
	while(s[j]!='\0')
	{

		if(s[j] == '{' || s[j] == '(' || s[j] =='[')
		{
			stack_push(s1,s[j]);
			j++;
		}
		else
		{
			char x;
			if(!stack_is_empty(s1))
			{
			x=stack_pop(s1);
			if(count(x) != s[j])
				{
				printf("0");
				break;
				}
			else
			{
				j++;
			}
		
			}
			
			
		}
	}

	if(stack_is_empty(s1))
	printf("1");			

	}
}


