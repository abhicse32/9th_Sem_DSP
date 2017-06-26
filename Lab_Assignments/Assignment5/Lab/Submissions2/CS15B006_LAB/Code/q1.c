#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int main(){

    int t;						// Number of test cases	
    scanf("%d", &t);
    int i;						// COUNTER
    int temp;					// Temporary variable
    int breaking;				// Condition for breaking and for validity of given string	
    stack *stk;					// Stack variable
    
    while( t > 0 ){ 
		i = 0;
		breaking = 1;			
		stk = stack_new();		// Allocating space for stack pointer variable
		
		char *s = (char*)malloc(sizeof(char) * 1000);  // Allocating space for string pointer
		scanf("%s", s);
		
		while(s[i] != '\0' && breaking == 1){			
			switch(s[i]){								// Pushing forward brackets into the stack
				case '(':
				case '{':
				case '[': 
					stack_push(stk, s[i]);
					break;
				case ']':
					temp = stack_pop(stk);				// popping if the top character in stack is matching with current closing bracket
						if( temp != '[' ) {				// If it isn't function is wrong	
							breaking = 0;
						}
					break;
				case '}':
					temp = stack_pop(stk);
						if( temp != '{' ) {
							breaking = 0;
						}
					break;				
				case ')':
					temp = stack_pop(stk);
						if( temp != '(' ) {
							breaking = 0;
						}
					break;
			}
			i++;
		}
		printf("%d\n", breaking);					//	printing the result	
		free(stk);
		free(s);
		t--;
	}

	return 0;
}
