//Raghavan S CS15B034 q2.c Lab Assignment 5
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
	if(len%2==0)
	{
		printf("%d\n",-1);
		continue;
	}
	for(i=0;c[i]!='\0';i++)
	{	if(c[i]=='{')
			stack_push(s,c[i]);
		else
		{
			if(stack_is_empty(s))
			{
				flag++;
				stack_push(s,'{');
			}
			else
				d=stack_pop(s);
		}

	}
if(!stack_is_empty(s))
{
flag+=stack_size(s)/2;
}
printf("%d\n",flag);
free(s);
}
free(c);
return 0;
}
