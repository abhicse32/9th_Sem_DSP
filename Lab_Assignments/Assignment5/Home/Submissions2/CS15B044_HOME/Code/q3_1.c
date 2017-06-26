#include<stdio.h>
#include<string.h>
#include"stack.h"
#include"List.h"
int stack_top(stack* s)
{
	int top;
	top=stack_pop(s);
	stack_push(s,top);
	return top;
}
int check(char a)
{
	if(a=='^')
	return 1;
	else if(a=='|')
	return 0;
	else if(a=='&')
	return 2;
	else if(a=='+' || a=='-')
	return 3;
	else if(a=='*' || a=='%' || a=='/')
	return 4;
	else if(a=='(' || a==')')
	return -2;
	return -1;
}
stack* postfix(stack *s,char *a)
{
	if(check(a[0])==-1) 
	{
		printf("%s ",a);
	}
	else
	{
		if(stack_is_empty(s))
		stack_push(s,a[0]);
		else
		{
			if(a[0]== '(')
			stack_push(s,a[0]);
		
			else if(a[0]==')')
			{
				while(stack_top(s)!='(')
				{
					char b;
					b=(int)stack_pop(s);
					printf("%c ",b);
				}
				stack_pop(s);
			}
			else if(check(a[0])==4)
			{
				while(check(stack_top(s))==4) 
				{
					char b;
					b=(int)stack_pop(s);
					printf("%c ",b);
					if(stack_is_empty(s))
					break;
				}
				stack_push(s,a[0]);
			}
			else if(check(a[0])==3)
			{
				while(check(stack_top(s))>=3) 
				{
					char b;
					b=(int)stack_pop(s);
					printf("%c ",b);
					if(stack_is_empty(s))
					break;
				}
				stack_push(s,a[0]);
			}
			else if(check(a[0])==2)
			{
				while(check(stack_top(s))>=2) 
				{
					char b;
					b=(int)stack_pop(s);
					printf("%c ",b);
					if(stack_is_empty(s))
					break;
				}
				stack_push(s,a[0]);
			}
			else if(check(a[0])==1)
			{
				while(check(stack_top(s))>=1) 
				{
					char b;
					b=(int)stack_pop(s);
					printf("%c ",b);
					if(stack_is_empty(s))
					break;
				}
				stack_push(s,a[0]);
			}
			else if(check(a[0])==0)
			{
				while(check(stack_top(s))>=0) 
				{
					char b;
					b=(int)stack_pop(s);
					printf("%c ",b);
					if(stack_is_empty(s))
					break;
				}
				stack_push(s,a[0]);
			}
		}
	}
	return s;
}
int main()
{
	char a[1000];
	stack *st;
	st=stack_new();
	while(fgets(a,1000,stdin)!=NULL)
	{	
		a[strlen(a)-1] ='\0';
		char *token;
		const char s[2]= " ";
		token = (char *)strtok(a, s);
		while( token != NULL ) 
   		{
  		    st=postfix(st,token);
    	  	token = (char *)strtok(NULL, s);
    	}	
    	while(!stack_is_empty(st))
    	{
    		char b;
			b=(int)stack_pop(st);
			printf("%c ",b);
   	 	}
   	 	printf("\n");
    }
}
