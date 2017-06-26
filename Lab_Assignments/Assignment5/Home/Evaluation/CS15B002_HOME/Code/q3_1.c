#include<stdio.h>
#include "stack.h"
#include "List.h"
#include<stdlib.h>
#include<string.h>
int check(char c);
int variable(char c);
int operation(char c);
int main()
{
	int i;
	for(i=0;i<10;i++)
	{
		char a[100],b[100];
		stack* s;
		s=stack_new();
		int k=0,c=0,j;
		while (1)
		{
			char l;
			scanf("%c",&l);
			a[k]=l;
			if(l=='\n') break;
			k++;
		}
		for(j=0;j<=k;j++)
		{
			int x=variable(a[j]),y=operation(a[j]);
			if(x ==1) 
			{
				b[c]=a[j];c++;
				if(a[j+1] == '\n'){b[c]=' ' ;c++;} 
				if(a[j+1] == ' ') {b[c]=a[j+1] ;c++;}
			}
			else if(y==1) 
			{
				while(1)
				{
					if(stack_is_empty(s)) {stack_push(s,a[j]);break;}
					char p = stack_pop(s);
					if(p == '(')
					{
						stack_push(s,p);
						stack_push(s,a[j]);
						break;
					}
					if(check(p)<check(a[j]))
					{
						stack_push(s,p);
						stack_push(s,a[j]);
						break;
					}
					else 
					{
						b[c]=p;
						b[c+1]=' ';
						c+=2;
					}
				}
			}
			else if(a[j] == '(' ) stack_push(s,a[j]);
			else if(a[j] == ')' )
			{
				char g=stack_pop(s);
				while(g != '(' && !stack_is_empty(s) ) 
				{
					b[c] = g;
					b[c+1] = ' ' ;
					c+=2;
					g = stack_pop(s);
				}
			}
		}
		while(!stack_is_empty(s))
		{
			char h = stack_pop(s);
			b[c] =h;
			b[c+1] = ' ';
			c+=2;
		}
		for(j=0;j<c;j++)
		{
			printf("%c",b[j]);
		}
		printf("\n");
	}
	return 0;
}
int variable(char c)
{
	if((c>='a' && c<= 'z')||(c>='A' && c<='Z')||(c>='0'&&c<='9')) return 1;
	else return 0;
}
int operation(char c)
{
	
	if(c=='+')return 1;
	else if(c=='-')return 1;
	else if(c=='*')return 1;
	else if(c=='/')return 1;
	else if(c=='^')return 1;
	else if(c=='&')return 1;
	else if(c=='|')return 1;
	else if(c=='%')return 1;
	else return 0;
}
int check(char c)
{
	if(c=='+')return 3;
	else if(c=='-')return 3;
	else if(c=='*')return 4;
	else if(c=='/')return 4;
	else if(c=='^')return 1;
	else if(c=='&')return 2;
	else if(c=='|')return 0;
	else if(c=='%')return 4;
}
