//Raghavan S CS15B034 q1.c Lab Assignment 5
#include<stdio.h>
#include "stack.h"
#include "List.h"
#include<string.h>
#include<stdlib.h>
#define MAX 1000
int main()
{
stack *s;
int t;
int flag=0;
int i;
int len;
char *c,d;
c=(char*)malloc(sizeof(char)*MAX);
scanf("%d\n",&t);
while(t>0)
{
	t--;
	s=stack_new();
	flag=0;
	fgets(c,MAX,stdin);
	len=strlen(c);
	c[len-1]='\0';
	for(i=0;c[i]!='\0';i++)
	{	if(c[i]=='('||c[i]=='{'||c[i]=='[')
			stack_push(s,c[i]);
		else
		{
			if(stack_is_empty(s))
			{
				flag=1;
				break;
			}
			d=stack_pop(s);
			switch(c[i])
			{
				case '}':	if(d!='{')
						{
							flag=1;
							break;
						}
						break;
				case ']':	if(d!='[')
						{
							flag=1;
							break;
						}
						break;
				case ')':	if(d!='(')
						{
							flag=1;
							break;
						}
						break;

			}
		}

	}
if(!stack_is_empty(s))
flag=1;
printf("%d\n",1-flag);
free(s);
}
free(c);
return 0;
}
