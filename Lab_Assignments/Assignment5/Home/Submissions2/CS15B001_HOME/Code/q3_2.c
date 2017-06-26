/*
This program evaluates the given postfix expression

Ameet S Deshpande
CS15B001
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "List.h"
#include <limits.h>


int evaluate(int a,int b,char o)	//This function evaluates the expression depending on the type of operator
{
	if(o == '+')
	{
		return a+b;
	}
	else if(o == '-')
	{
		return a-b;
	}
	else if(o == '*')
	{
		return a*b;
	}
	else if(o == '/')
	{
		return a/b;
	}
	else if(o == '%')
	{
		return a%b;
	}
	else if(o == '&')
	{
		return a&b;
	}
	else if(o == '^')
	{
		return a^b;
	}
	else if(o == '|')
	{
		return a|b;
	}
	

	return INT_MIN;
}






int main()
{
	char a[1000];
	stack *s;	//The stack being used for the conversion
	char c = ' ';		//Used for storing the characters required
	int popped1,popped2;	//Stores the value of the popped element
	int count=0;
	int number=0;
	int assign= 0;
	int i=0;

	s = stack_new();	//Making a new stack

	

	for(i=0;i<10;++i)
	{

	fgets (a, 999, stdin);
	//scanf("%[^\n]s",a);

	c=' ';
	count=0;

	while(c!='\0')
	{	
		c = a[count];
		count++;

		if(c=='\0')		//If the string is already evaluated then break out of the loop
		{
			break;
		}

		if(((c>='0')&&(c<='9'))||((a[count]>='0')&&(a[count]<='9')))
		{	number = 0;
			if((c>='0')&&(c<='9'))
			{
				while((c>='0')&&(c<='9'))
				{
					number = ( (int)(c)-'0' ) + number*10;
					c = a[count];
					count++;
				}

				stack_push(s,number);
			}

			else
			{	
				c = a[count];
				count++;

				while((c >= '0')&&(c <= '9'))
				{
					number = ( (int)(c)-'0' ) + number*10;
					c = a[count];
					count++;
				}

				stack_push(s,-number);				
			}
		}

		else if(c==' ')
		{
			continue;
		}

		else
		{	
			popped2 = stack_pop(s);
			popped1 = stack_pop(s);
			assign = evaluate(popped1,popped2,c);
			stack_push(s,assign);
			c=a[count];
			count++;
		}
	}

	assign = stack_pop(s);
	printf("%d\n",assign);


	}


	return 0;
} 