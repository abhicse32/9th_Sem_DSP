#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "List.c"
#include "stack.h"
#include "stack.c"

int get_top(stack *s)
{
	return s->top->head->data;
}

void findnext(int *a, int till, stack *num, stack *final)
{
	int temp; 
	if(till>=0)
	{
		while(get_top(num) != -1 && get_top(num) <= a[till])
			temp = stack_pop(num);
		stack_push(final, get_top(num));
		stack_push(num, a[till]);
		findnext(a, till-1, num, final);		
	}
	return;
}

void main()
{
	int n;
	scanf("%d", &n);
	
	int i,j;
	int *a[n];
	int *lar[n];
	
	stack *num = stack_new();
	stack *final = stack_new();
	
	int *l;
	l = (int *)malloc(n * sizeof(int));
	
	for(i=0; i<n; i++)
	{
		a[i] = (int *)malloc(10000 * sizeof(int));
		lar[i] = (int *)malloc(10000 * sizeof(int));
				
		scanf("%d", &l[i]);
		for(j=0; j<l[i]; j++)
			scanf("%d", &a[i][j]);
		
		stack_push(num, -1);	
		findnext(a[i], l[i]-1, num, final);
		
		for(j=0; j<l[i]; j++)
			lar[i][j] = stack_pop(final);			
	}
		
	for(i=0; i<n; i++)
	{
		for(j=0; j<l[i]; j++)
			printf("%d ", lar[i][j]);
		printf("\n");
	}
}
