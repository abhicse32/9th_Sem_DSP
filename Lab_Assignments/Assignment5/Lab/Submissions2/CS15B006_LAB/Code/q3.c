#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int stack_top(stack*);

int main()
{
	int t;
	scanf("%d", &t);
	
	int n;
	int i;
	stack *stk, *stk2;												// ONE FOR DATA, ANOTHER FOR IINDEX
	int *a, *b;														// INPUT AND OUTPUT	

	while( t > 0 ){
		scanf("%d", &n);
		
		stk = stack_new();											// ALLOCATING NEW SPACE	
		stk2 = stack_new();
		a = (int*)malloc(sizeof(int)*n);
		b = (int*)malloc(sizeof(int)*n);
		
		for (int i = 0; i < n; ++i){
			scanf("%d", &a[i]);										// INPUT 		
		}
		
		stack_push(stk, a[0]);										// INITIALIZING STACK WITH THE STARTING ARRAY
		stack_push(stk2, 0);
		
		for(i = 1; i < n ; i++){
			
			if(a[i] <= stack_top(stk)) {
				stack_push(stk, a[i]);								// PUSHING IF ELEMENT SMALLER THAN TOP OF STACK
				stack_push(stk2, i);
			}
			else{
				while(!stack_is_empty(stk) && a[i] > stack_top(stk)){		// IF CURRENT GREATER THAN TOP
					b[stack_pop(stk2)] = a[i];								// CURRENT IS VALUE FOR TOP ELEMENT'S OUTPUT 			
					stack_pop(stk);
				}

				stack_push(stk, a[i]);								// PUSHING THE CURRENT NUMBER IN ARRAY
				stack_push(stk2, i);
			}
		}
		while(!stack_is_empty(stk)){								// FOR ANY REMAINING ELEMENTS IN STACK THERE ARE NO INTEGERS IN
			b[stack_pop(stk2)] = -1;								// THE ARRAY GREATER THAN THEM TO THEIR RIGHT
			stack_pop(stk);
		}
		for(i = 0; i < n; i++){
			if(b[i] == 0) b[i] = -1;								// -1 FOR FINAL REMAINING NUMBERS WHICH AREN'T CHECKED 
			printf("%d ", b[i]);													
		}
		printf("\n");

		free(stk);
		free(stk2);
		free(a);
		free(b);
		t--;
	}
	return 0;
}

int stack_top(stack* stk){
	return(stk->top->head->data);							// FOR FINDIN TOP OF THE FUNCTION
}
