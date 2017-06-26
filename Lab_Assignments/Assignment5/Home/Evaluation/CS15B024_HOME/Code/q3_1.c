#include<stdio.h>]
#include<stdlib.h>
#include "List.h"
#include "stack.h"
int ISP(char ch)
{
	switch(ch)
	{
		case ')':
		return 0;
		case '+':
		case '-':
		return 1;
		case '*':
		case '/':
		return 2;
		case '^':
		return 3;
	}
	return -1;
}
int ICP(char ch)
{
	switch(ch)
	{
		case '^':
		return 4;
		case '*':
		case '/':
		return 2;
		case '+':
		case '-':
		return 1;
		case ')':
		return 4;
	}
	return -1;
}
int intopost(char a[1000])
{
	int b[1000];
	stack*s =stack_new();
	int i=0;
	int j=-1;
	while(a[i]!='\0')
	{
		if(a[i]!=)
		{
			b[++j]=a[i];
			i++;
		}
		else if(a[i]=='(')
		{
			stack_push(s,a[i]);
			i++;
		}
		else if(a[i]==')')
		{	
			while(stack_is_empty(s))!=1 &&	s->top->head!='(')
			{
				b[++j]=stack_pop(s);
			}
			if(stack_is_empty(s)!=1 && s->top->head!='(')
			{
				return -1;
			}
			else stack_pop(s);
			i++;
		}
		else
		{
			while(stack_is_empty(s)!=1 && ICP(a[i])<=ISP(s->top->head))
			{
				b[++j]=stack_pop(s);
			}
			stack_push(s,a[i]);
			i++;
		}
	}
	while(stack_is_empty(s)!=1)
	{
		b[++j]=stack_pop(s);
	}
	b[++j]='\0';
	printf("%s",b);
	printf("\n");
}
int main()
{
	char a[1000];
	scanf("%s",&a);
	intopost(a);
}	
	
	

