//program to finds the next larger element of every element by Akshay Kumar


#include <stdio.h>
#include "stack.h"
#include "List.h"

void main()
{
	int t,i,j;															//declaration of variables
	scanf("%d",&t);														//number of test cases
	for(i = 0; i < t; i ++)
	{
		int n,a,x;
		scanf("%d",&n);
		int b[n];
		stack* s1 = stack_new();										//creating new stack
		stack* s2 = stack_new();
		for(j = 0; j < n; j ++)											//this loop stores array into stack
		{
			scanf("%d",&b[j]);
			stack_push(s1,b[j]);
		}
		stack_push(s2,-1);												//initially put -1 into new stack
		for(j = 1; j < n; j ++)
		{
			a = stack_pop(s1);
			x = s1->top->head->data;
			if(a > x) stack_push(s2,a);									//if next number is greater push it
			else
			{
				Node* p = s2->top->head;
				while(1)												//else check in second stack from top which is the first greater number
				{
					if(p->data > x) 
					{
						stack_push(s2,p->data);
						break;
					}
					
					if(p->data == -1)									//if not found any push -1
					{
						stack_push(s2,-1);
						break;
					}
					p = p->next;
				}
			}
		}
		stack_print(s2);												//printin the result
		printf("\n");
	}
}
