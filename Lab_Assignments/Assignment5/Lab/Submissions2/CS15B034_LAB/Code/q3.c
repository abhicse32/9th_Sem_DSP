//Raghavan S CS15B034 q3.c Lab Assignment 5
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
int i;
int x;
int n;
int *c,*d;
scanf("%d",&t);
while(t>0)
{
	t--;
	s=stack_new();
	scanf("%d",&n);
	c=(int*)malloc(sizeof(int)*n);
	d=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",c+i);
	d[n-1]=-1;
	stack_push(s,c[n-1]);
	for(i=n-2;i>=0;i--)
	{
		while(c[i]>=s->top->head->data)
		{
			x=stack_pop(s);
			if(stack_is_empty(s))
			{	d[i]=-1;
				break;
			}
		}
		if(!stack_is_empty(s))
			d[i]=s->top->head->data;
		stack_push(s,c[i]);
	}
	for(i=0;i<n;i++)
		printf("%d ",*(d+i));
	printf("\n");
	free(c);
	free(d);
	free(s);
}
return 0;
}
