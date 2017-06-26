/*
Program to count no. of reversals needed to correct expression
Name: Harshavardhan.P.K.
Roll No: CS15B061
Date: 16 Sept, 2016
*/
#include "stack.h"
#include <string.h>
#include <stdio.h>


int reversal(char*);

/*
Function: reversal -> to compute no. of reversal of braces required. If cant be resolved by reversal output is -1
Input: char* st -> input string
Output: no. of reversals required
ct - stores no of reversals needed
*/
int reversal(char* st){
	int len=strlen(st);
	if(len%2==1) return -1; // if odd then no reversal possible
	stack* s = stack_new();
	int i,ct=0; 				//ct measures no of reversals
	for (i=0;i<len;i++){
		switch(st[i]){
			case '}':if(stack_is_empty(s)){stack_push(s,st[i]); break; } 	//if stack is empty push } else if { is found match with it, else push }
				 if((stack_pop(s))=='{') break;
				else {stack_push(s,'}'); stack_push(s,'}');break;}
			case '{':stack_push(s,'{') ; break;	  //if { push to stack
		}
	}
	//Now all the correct substrings are paired and we need to see about unpaired braces
	//if(stack_size(s)%2==1) return -1;
	while(!stack_is_empty(s)){
		char c2=stack_pop(s);
		char c1=stack_pop(s);
		if(c1=='{') ct++; 		//if { is found next should be { hence '{{' needs one reversal
		else{
			if(c2=='{') ct+=2; 	//in this case the substring '}{' needs 2 reversals
			else ct++;		//in case of '}}' need only one reversal
		}
	}
	return ct;
}

#define CHARMAX 1005
int main(void){
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++){
		char st[CHARMAX];
		scanf("%s",st);
		printf("%d\n",reversal(st));
	}
	return 0;
}
