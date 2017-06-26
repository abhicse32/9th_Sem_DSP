#include <stdio.h>
#include "List.h"
#include "stack.h"

// Converting the infix to postfix
void in_post( char* str );

// Part of the in_post  function which decides or controls the priority of the operatiors
void priority( stack* , char);

int main(){
	char s[1000];
	for(int i = 0; i < 10; i++){																		// Taking input through fgets and calling function 10 times for 
		fgets(s, 1000, stdin);																			// converting 10 testcases from infix to postfix
		in_post(s);
	}
	return 0;
}

void in_post(char* str){
	stack* stk = stack_new();
	
	int i = 0;
	while(str[i] != '\0'){																				// while string has not reached EOF		
	
		if(str[i] != '|' && str[i] > 47 && str[i] != '^' ){												// Case when charcter is either alphabets or numbers
			while(str[i] > 47){
				printf("%c", str[i]);
				i++;
			}
			printf(" ");																				// Space character for ouput
		}
		if(str[i] == ' ') i++;																			// Skipping space character from input
		else {
			priority(stk, str[i]);																		// Case of input being a operator charcter  												
			i = i+2;																					// Going to next char by jumping over both operator and space charc				
		}
	}
	char t;
	while( stack_is_empty(stk) != 1){																	// After going through string once pushing
		t = stack_pop(stk);																				// remaining operators from stack
		printf("%c ", t);
	}
	printf("\n");
}

void priority(stack* stk, char s){
	int i = 0;														
	char t;
	LList* p = stk->top;																				// Creating a node pointer  	
	switch (s){
		case '(':
			stack_push(stk, s);																					
			break;
		case '&':
			while(p->head != NULL && p->head->data != '(' && p->head->data != '|' && p->head->data != '^'){				// Pushing out the characters with higher or same priority 		
				t = stack_pop(stk);
				printf("%c ", t);
			}
			stack_push(stk, s);
			break;
		case '|':																										// Pushing out the characters with higher or same priority
			while(p->head != NULL && p->head->data != '(' ){
				t = stack_pop(stk);
				printf("%c ", t);
			}
			stack_push(stk, s);
			break;
		case '^':																										// Pushing out the characters with higher or same priority
			while(p->head != NULL && p->head->data != '(' && p->head->data != '|' ){
				t = stack_pop(stk);
				printf("%c ", t);
			}
			stack_push(stk, s);
			break;		
		case '%':																										// Pushing out the characters with higher or same priority
			while(p->head != NULL && (p->head->data == '*' || p->head->data == '/')){
				t = stack_pop(stk);
				printf("%c ", t);
			}
			stack_push(stk, s);
			break;
		case '*':																										// Pushing out the characters with higher or same priority
			while(p->head != NULL && (p->head->data == '%' || p->head->data == '/')){
				t = stack_pop(stk);
				printf("%c ", t);
			}
			stack_push(stk, s);
			break;
		case '/':																										// Pushing out the characters with higher or same priority
			while(p->head != NULL && (p->head->data == '%' || p->head->data == '*')){
				t = stack_pop(stk);
				printf("%c ", t);
			}
			stack_push(stk, s);
			break;
		case '-':																										// Pushing out the characters with higher or same priority
			while(p->head != NULL  && p->head->data != 40 && p->head->data != '|' && p->head->data != '&' && p->head->data != '^'){
				t = stack_pop(stk);
				printf("%c ", t);
			}
			stack_push(stk, s); 
			break;	
		case '+':																										// Pushing out the characters with higher or same priority
			while( p->head != NULL && p->head->data != 40 && p->head->data != '|' && p->head->data != '&' && p->head->data != '^' && p->head->data != '-'){
				t = stack_pop(stk);
				printf("%c ", t);
				i++;
			}
			stack_push(stk, s);
			break;
		case ')':																										// Pushing all characters until reaching '('
			while(p->head != NULL && p->head->data != 40 ){
				printf("%c ", stack_pop(stk));
			} 
			stack_pop(stk);
			break;
	}
	return;
}

