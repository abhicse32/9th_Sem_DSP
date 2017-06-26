#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

void eval(char*);						// For separting in operators and numbers 																		

void calculate(stack*, char);			// Evaluating the value according to the operator

int main(){
	char *s = (char*)malloc(sizeof(char)*1000);
	int i ;
	int len;
	for(i = 0; i < 10; i++){										// Reading input
		fgets(s, 1000, stdin);
		len = strlen(s);
		if(s[len-1] == '\n')s[len-1] = '\0';										// Removing the new line character taken by the fgets file from input 
		eval(s);
	}
	return 0;	
}

void eval(char* s){
	
	int i = 0;
	int l, t;
	stack* stk = stack_new();

	while(s[i] != '\0'){
		char* temp = (char*)malloc(sizeof(char)*26);								// Temporary var to convert string to a number
		if(s[i] > 47 && s[i] != '|' && s[i] != '^'){								// When input are numbers
			l = 0;
			while(s[i] != ' '){														// While number is not ended	
				temp[l] = s[i];														// Storing that number into temp string
				i++; l++;
			}
			temp[l] = '\0';
			t = atoi(temp);															// atoi function to convert to number		
			stack_push(stk, t);
			i++;
		}
		else{
			if(s[i] == '-' && s[i+1] > 47 && s[i+1] != '|' && s[i+1] != '^'){			// Case of negative numbers
				i++;
				l = 0;
				while(s[i] != ' '){
					temp[l] = s[i];
					i++; l++;
				}
				temp[l] = '\0';
				t = atoi(temp);
				t = -1*t;
				stack_push(stk, t);
				i++;		
			}
		
			else{																	// Case of operator
				calculate (stk, s[i]);												// Calling operator function		
				i = i+2;
			}

		}
		free(temp);																	// Freeing variable space
	}
	printf("%d\n", stack_pop(stk)); fflush(stdout);
	return;
}

void calculate(stack* stk, char s){
	int u, v, ans;
	u = stack_pop(stk);															// Takking two operands
	v = stack_pop(stk);
	switch(s){																	// Applying operation depending on operator	
		case '+': ans = v + u; break;
		case '-': ans = v - u; break;
		case '*': ans = v*u; break;
		case '/': ans = v/u; break;
		case '&': ans = v&u; break;
		case '|': ans = v|u; break;
		case '%': ans = v%u; break;
		case '^': ans = v^u; break;
	}
	stack_push(stk, ans);														// Storing the answer in stack
	return;
}
