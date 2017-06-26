#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void check(char s[]);	//checks if the givemn expression is correct and prints corresponding value
int pref(char );		//returns corresponding integer for given character	

int main(){
	int t;
	scanf("%d",&t);
	int x;
	for(x=0; x<t ;x++){		//loop for t testcases
		char s[1000];
		scanf("%s",s);
		check(s);
	}
	return 0;
}

int pref(char c){	//positive for closing brackets and negative for opening
	int p;	
	switch(c){
		
		case '(':	p=-1;	break;
		case '{':	p=-2;	break;
		case '[':	p=-3;	break;
		case ')':	p=1;	break;
		case '}':	p=2;	break;
		case ']':	p=3;	break;
	}
	return p;
}

void check(char s[]){
	stack *st=stack_new();
	int i;
	for(i=0 ; s[i]!='\0'; i++){
		int k=pref(s[i]);		
		if( k < 0 ){		//pushing opening brackets onto stack
			stack_push(st,s[i]);
		}
		else{				//checking if closing bracket encountered corresponds to the one on the stack
			if(pref(stack_pop(st)) != ((-1)*k)){
				printf("0\n");
				return;
			}	
		}
	}
	printf("1\n");
	return;
}


