#include "List.h"
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int j;
		stack* stk;
		stk=stack_new();
		int a[n];
		/* storing the elements in a array */
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		stack* new;
		new=stack_new();
		int arr[n];
		/* array to store last greater*/
		for(j=0;j<n;j++)
		{
			arr[j]=-1;
		}
		stack_push(stk,a[0]);
		stack_push(new,0);
		for(j=1;j<n;j++)
		{
			if(stack_is_empty(stk))
			{
				stack_push(stk,a[j]);
				stack_push(new,j);
			}
			else
			{/* push if greater then*/
				int x;
				x=stack_pop(stk);
				if(x>=a[j])
				{	stack_push(stk,x);
					stack_push(stk,a[j]);
					stack_push(new,j);
				}
				else
				{/* check for every condition*/
					int y;
					int x=1;

					do
					{

					arr[stack_pop(new)]=a[j];
					if(stack_is_empty(stk))
					{x=0;
					break;}
					
					else
					y=stack_pop(stk);

					}while(y<a[j]);
					if(x!=0)
					stack_push(stk,y);
					stack_push(stk,a[j]);
					stack_push(new,j);
				}			
				
			}		
		
		}
		for(j=0;j<n;j++)
		{
		printf("%d ",arr[j]);
		}
		printf("\n");
		
		
	}
	
}
