#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>

int main(){

	int t;
	scanf("%d", &t);												// NUMBER OF TEST CASES
	stack *stk;
	int count;
	int temp;
	int i;
	while( t > 0 ){
		count = 0;				                                   // INITIALIZING COUNT AS ZERO
		i = 0;
		
		stk = stack_new();											
		char *s = (char*) malloc(sizeof(char)*1000); 				// ALLOCATING SPACE FOR STRING
		scanf("%s", s);
		
		if( strlen(s)%2 == 1 ) { printf("-1\n"); t--; continue;}    // WHEN LENGTH IS ODD IT ISN'T POSSIBLE TO MAKE IT VALID
		
		while(s[i] != '\0'){										// WHILE STRING IS NOT ENDED			
			if(s[i] == '}'){
				if(stack_is_empty(stk)){							// WHEN STACK IS EMPTY AND THERE IS CLOSE BRACKET IMPLIES THAT - 
					count++;										// - IT NEEDS TO BE FLIPPED, HENCE INCREASING THE COUNT AND  
					temp = '{';										// ADDING IT TO THE STACK AFTER FLIPPING IT			
					stack_push(stk, temp);
				}
				else stack_pop(stk);								// WHEN STACK ISN'T EMPTY THERE IS MATCHING BRACKET => POPPED OUT			
			}
			else stack_push(stk, s[i]);								// WHEN IT IS FORWARD BRACKET IT IS PUSHED INTO STACK	
			i++;
		}
		count = count + stack_size(stk)/2;							// AFTER EVRYTHING ELSE IF THERE ARE STILL (FORWARD)BRACKETS IN STACK		
																	// HALF OF THEM NEED TO BE FLIPPED TO MATCH OTHER HALF
		printf("%d\n", count);
		free(s);													// FREEING THE POINTER'S ALLOCATED SPACE
		t--;
	}
	
	return 0;
}
