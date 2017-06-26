#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "stack.h"
#include "List.h"
int allot(char c);
int check(stack* a);
int main()
{
	int n,j;
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		char a[1005];
		stack* b = stack_new();
		scanf("%s",a);
		int k=strlen(a),i,p,q;
		for(i=0;i<k;i++)
		{
			p=allot(a[i]);
			if(stack_is_empty(b)) stack_push(b,p);	
			else
			{
				int x=((b->top)->head)->data;
				if(p==(x+1)) q=stack_pop(b);
				else stack_push(b,p);
			}
		}int x=((b->top)->head)->data;int t=stack_size(b);
		if(t%2==1) printf("-1\n");
		else if(stack_is_empty(b)) printf("0\n");
		else printf("%d\n",check(b));
	}	
	return 0;
}
int check(stack* a)
{
	int d;
	int x=((a->top)->head)->data;int t=stack_size(a);
	if(x==1) d=t/2; 
	else
	{
		if(stack_is_empty(a))return 0;		
		int q=stack_pop(a);
		int r=stack_pop(a);
		if(r==0)return 1+check(a);
		else 
		{
			stack_push(a,r);
			stack_push(a,1);
			return 1+check(a);
		}				
	}			
}
int allot(char c)
{
	int p;
	if(c=='{') p=0;
	if(c=='}') p=1;	
	return p;
}
