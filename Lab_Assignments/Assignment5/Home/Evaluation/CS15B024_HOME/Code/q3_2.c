#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include "stack.h"
#include <string.h>
int is_digit(char ch)
{
	return(ch>='0' && ch<='9');
}
int postfix(char a[1000])
{
	stack *s=stack_new();
	int i=0;
	while(a[i]!='\0')
	{
		if(is_digit(a[i]))
		{
			stack_push(s,a[i]-'0');
			i++;
		}
		else if (a[i]!=' ')
		{
			int x=stack_pop(s);
			int y=stack_pop(s);
		
		
				if(a[i]=='+')
				{
					stack_push(s,y+x);
				}
				else if(a[i]=='-')
				{
					stack_push(s,y-x);
				}
				else if(a[i]=='*')
				{
					stack_push(s,y*x);
				}
				else if(a[i]=='/')
				{
					stack_push(s,y/x);
				}
				else if(a[i]=='&')
				{
					stack_push(s,y&x);
				}
				else if(a[i]=='|')
				{
					stack_push(s,y|x);
				}
				else if(a[i]=='^')
				{
					stack_push(s,y^x);
				}

			i++;
		}
	}
	return stack_pop(s);

}
int main()
{
	 char a[1000];
	 scanf("%s",a);
	fgets(a,1000,stdin);
	int x
	x=postfix(a);
	printf("%d",x);
	printf("\n");
}
	 

