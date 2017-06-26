#include<stdio.h>
#include "stack.h"
#include "List.h"
#include<stdlib.h>
#include<string.h>
int main()
{
	int i;
	for(i=0;i<10;i++)
	{
		char a[100],b[];
		stack* s;
		s=stack_new();
		int k=0,c=0,j;
		while (1)
		{
			char l;
			scanf("%c",&l);
			if(l=='\n') break;
			else a[k]=l;
			k++;
		}
		k++;
		for(j=0;j<k;j++)
		{
			if(variable(a[j])) {b[c]=a[j];c++}
			else if(a[j] == '(' ) stack_push(s,a[j]);
			else if(operation(a[j])) stack_push(s,a[j]);
			else if(a[j] == ')' )
			{
				char g=stack_pop(s);
				while(g != '(' ) 
				{
					b[c] = g;
					c++;
					g = stack_pop(s);
				}
			}
		}
		while(!stack_is_empty(s))
		{
			char h = stack_pop(s);
			b[c] =h;
			c++;
		}
	}
	return 0;
}
bool variable(char c)
{
	if((c>='a' && c<= 'z')||(c>='A' && c<='Z')) return true;
	else return false;
}
bool operation(char c)
{
	if(c=='+')return true;
	else if(c=='-')return true;
	else if(c=='*')return true;
	else if(c=='/')return true;
	else if(c=='^')return true;
	else return false;
}
