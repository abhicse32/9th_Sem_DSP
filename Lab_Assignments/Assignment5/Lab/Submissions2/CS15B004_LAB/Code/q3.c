// to print the next larger element corresponding to each element in an array

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main()
{
	int t;
	scanf("%d",&t);

	while(t>0)
	{

	int n , i;
	scanf("%d", &n);
	int* arr = (int *) malloc (sizeof(int) * n);

	stack* stk = stack_new();
	stack* idx = stack_new();



	for(i=0; i<n; i++)
		{	
			int new;
			scanf("%d", &new);

			if(stack_is_empty(stk))
			{	
				stack_push(stk, new);
				stack_push(idx, i);
			}
			else
			{
				if(new < stack_top(stk))
				{
					stack_push(stk, new);
					stack_push(idx, i);
				}
				else
				{
					while(new > stack_top(stk) )
					{	int val,pos;

						val = stack_pop(stk);
						pos = stack_pop(idx);
						arr[pos] = new;

						if(stack_is_empty(stk))
							break;
					}
					stack_push(stk, new);
					stack_push(idx, i);

				}
			}
		}

	while(! stack_is_empty(stk))
	{
		int val, pos;
		val = stack_pop(stk);
		pos = stack_pop(idx);
		arr[pos] = -1;
	}

	//print array
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	t--;
	}


	return 0;
}