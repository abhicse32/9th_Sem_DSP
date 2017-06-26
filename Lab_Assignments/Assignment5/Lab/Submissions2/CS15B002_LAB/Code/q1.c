#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "stack.h"
#include "List.h"
int allot(char c);
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
		}
		if(stack_is_empty(b)) printf("1\n");
		else printf("0\n"); 
	}	
	return 0;
}
int allot(char c)
{
	int p;
	if(c=='{') p=0;
	if(c=='}') p=1;	
	if(c=='(') p=10;
	if(c==')') p=11;
	if(c=='[') p=20;
	if(c==']') p=21;
	return p;
}	
