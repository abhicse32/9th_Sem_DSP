#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "List.h"
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int n1,j;
		stack* a;
		a=stack_new();
		scanf("%d",&n1);
		int b[n1],c[n1];
		for(j=0;j<n1;j++)
		{
			scanf("%d",&b[j]);
		}
		for(j=n1-1;j>=0;j--)
		{
			Node* y=(a->top)->head;
			while(y!=NULL)
			{	
				if(b[j] < y->data)
				{
					stack_push(a,b[j]);
					c[j]=y->data;
					break;
				}
				else 
				{
					int g;
					g = stack_pop(a);
					y = y->next;
				}
			}
			if(y==NULL)
			{
				stack_push(a,b[j]);
				c[j]=-1;
			}				
		}
		for(j=0;j<n1;j++)
		{
			printf("%d ",c[j]);
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}		
