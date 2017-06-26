#include<stdio.h>
#include "stack.h"
#include "List.h"
#include<stdlib.h>
#include<string.h>
int check(char);	
int main()
{
	int i;
	for(i=0;i<10;i++)
	{
		char a[100];
		stack* s;
		s=stack_new();
		int j,k=0;
		while (1)
		{
			char l;
			scanf("%c",&l);
			a[k] = l;
			if(l=='\n') break;
			k++;
		}
		a[k]=' ';
		int z=0;
		for(j=0;j<=k;j++)
		{
			int y=check(a[j]);
			if((y==3)&&(a[j+1]!=' '))
			{	j++;
				while(a[j]!=' ')
				{char m = a[j];	
				z+=(m-48);
				if(a[j+1] == ' ') {stack_push(s,-z);z=0;}
				else z=10*z; j++;}
			}
			else if(y==3)
			{
				int p = stack_pop(s);
				int q = stack_pop(s);
				int d= (q-p);
				stack_push(s,d);
			}
			else if(y==1)
			{
				char m = a[j];	
				z+=(m-48);
				if(a[j+1] == ' ') {stack_push(s,z);z=0;}
				else z=10*z;
			}
			else if(y==2)
			{
				int p = stack_pop(s);
				int q = stack_pop(s);
				int d=p+q ;
				stack_push(s,d);
			}
			else if(y==4)
			{
				int p = stack_pop(s);
				int q = stack_pop(s);
				q=q*p;
				stack_push(s,q);
			}else if(y==5)
			{
				int p = stack_pop(s);
				int q = stack_pop(s);
				int d = q/p;
				stack_push(s,d);
			}else if(y==6)
			{
				int p = stack_pop(s);
				int q = stack_pop(s);
				int d=(q%p);
				stack_push(s,d);
			}else if(y==7)
			{
				int p = stack_pop(s);
				int q = stack_pop(s);
				int d = q|p;
				stack_push(s,d);
			}else if(y==8)
			{
				int p = stack_pop(s);
				int q = stack_pop(s);
				int d=q&p;
				stack_push(s,d);
			}else if(y==9)
			{
				int p = stack_pop(s);
				int q = stack_pop(s);
				stack_push(s,(p^q));
			}
		}
		int p=stack_pop(s);
		printf("%d \n",p);
		//fflush(stdout);
	}
	return 0;
}
int check(char c)
{
	if(c>='0' && c<='9') return 1;
	else if(c == '+') return 2;
	else if(c == '-') return 3;
	else if(c == '*') return 4;
	else if(c == '/') return 5;
	else if(c == '%') return 6;
	else if(c == '|') return 7;
	else if(c == '&') return 8;
	else if(c == '^') return 9;
}
