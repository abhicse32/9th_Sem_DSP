/*
Program to check if order and pairs of paranthesis are correct
Name: Harshavardhan.P.K.
RollNo: CS15B061
Date: Sept 16,2016
*/
#include "stack.h"
#include <stdio.h>
#include <string.h>
/*
Function: paracheck: returns 1 if expression is correct else returns 0
Input: char* st -> contains expression string
*/
int paracheck(char* st){
	int len=strlen(st);
	stack* s = stack_new(); 	//Create stack
			//Enter 1st element as #
	int i;
	for(i=0;i<len;i++){
		char c;
		switch(st[i]){
			case '{': case '(': case '[': 			//In case of opening brackets push it
				stack_push(s,st[i]);break;
			case '}': if((stack_pop(s))!='{') return 0;	//Check is opening and closing braces match else expression is wrong
					break;

			case ')': if((stack_pop(s))!='(') return 0;	
					break;
		
			case ']': if((stack_pop(s))!='[') return 0;	
					break;
		}
	}
	
	if(!(stack_is_empty(s))) return 0; 	//After evaluation check if stack is empty,
	return 1;
}

#define CHARMAX 1005
int main(void){
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++){
		char st[CHARMAX];
		scanf("%s",st);
		printf("%d\n",paracheck(st));
	}
	return 0;
}
