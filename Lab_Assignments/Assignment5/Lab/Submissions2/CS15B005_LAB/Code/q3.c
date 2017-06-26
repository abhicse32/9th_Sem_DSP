#include <stdio.h>
#include "stack.h"
#include "List.h"
void main()
{
	int t, i, j, n,temp;
	scanf("%d",&t);
	for( i=0 ; i < t ; i++)
	{
		scanf("%d",&n);
		int arr[1000], nmax[1000];
		for( j=0 ; j<n ; j++)
		{
			scanf("%d",&arr[j]);
			nmax[j] = -1;
		}
		stack* S = stack_new();
		
		stack_push(S, arr[0]);
		
		int curr, pop;
		for( j=1 ; j<n ; j++)
		{
			curr = arr[j];
			if(stack_is_empty(S) == false)
			{
				pop = stack_pop(S);
				while( curr > pop)
				{
					for( temp = 0 ; temp<n ; temp++)
					{
						if(arr[temp] == pop)
						{
							if(nmax[temp] == -1)
							{
								nmax[temp] = curr;
								break;
							}
						}
					}
					if(stack_is_empty(S) == true)
					{
						break;
					}
					pop = stack_pop(S);
					
				}
				if(curr <= pop)
				{
					stack_push(S,pop);
				}
			}
			stack_push(S,curr);
		}
		for( j=0 ; j<n ; j++)
		{
			printf("%d ",nmax[j]);
		}
		printf("\n");
	}
	return ;
}
