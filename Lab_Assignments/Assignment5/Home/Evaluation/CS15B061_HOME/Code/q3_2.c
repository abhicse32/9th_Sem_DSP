
/*-----------------------------------------------------------------------------
 *  Program to evaluate postfix expression
 *  Name: Harshavardhan.P.K.
 *  RollNo: CS15B061
 *  Date: 17 Sept, 2016
 *-----------------------------------------------------------------------------*/
#include "stack.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int posteval(char*);
#define NUMSIZE 8

/*-----------------------------------------------------------------------------
 *  Function: posteval - to evaluate the postfix expression
 *  Input: st - the postfix expression
 *  Returns the answer of postfix expression
 *-----------------------------------------------------------------------------*/
int posteval(char *st){
	stack* s = stack_new();
	int len=0;
	//calculate length of st
	while(st[len]!='\0') len++;
	//token stores tokens of st
	char* token = (char*)malloc(sizeof(char)*NUMSIZE);
	token=strtok(st," ");
	//digit stores the numbers extracted from token
	int n1,n2,digit;
	while(token){
		//if we get a number push to stack
		if(sscanf(token,"%d",&digit)){
			
			stack_push(s,digit);
		}
		else
			//if operator to the corresponding operation with top 2 numbers
			switch(token[0]){
				case '+': stack_push(s,stack_pop(s)+stack_pop(s));
					  break;
				case '-':   n1=stack_pop(s);n2=stack_pop(s);stack_push(s,n2-n1);
					   break;
				case '*':  stack_push(s,stack_pop(s)*stack_pop(s));
					   break;
				case '/':  n1=stack_pop(s);n2=stack_pop(s);stack_push(s,n2/n1);
					   break;
				case '%':  n1=stack_pop(s);n2=stack_pop(s);stack_push(s,n2%n1);
					   break;
				case '|': stack_push(s,stack_pop(s)|stack_pop(s));
					  break;
				case '&': stack_push(s,stack_pop(s)&stack_pop(s));
					  break;
				case '^': stack_push(s,stack_pop(s)^stack_pop(s));
					  break;	  	  	   	   
				
			}	   
		token=strtok(NULL," ");
	}
	//the remaining element is obviously th eanswer to expression
	return stack_pop(s);

}

int main(void){
	char st[100];
	while(fgets(st,100,stdin))
	printf("%d\n",posteval(st));
	return 0;
}
