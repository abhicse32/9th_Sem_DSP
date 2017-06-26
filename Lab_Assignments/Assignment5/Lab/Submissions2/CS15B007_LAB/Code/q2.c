#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

void count(char s[]);		//counts the minimum number oof inversions
int pref(char );			//returns an int for char argumented

int main(){
	int t;
	scanf("%d",&t);
	int x;
	for(x=0; x<t ;x++){		//loop for t testcases
		char s[1000];
		scanf("%s",s);
		if(strlen(s)%2!=0){	//printing -1 if string is of odd length
			printf("-1\n");		
		}
		else{
			count(s);
		}
	}
	return 0;
}

int pref(char c){
	if(c=='{'){			
		return 0;
	}
	else return 1;
}

void count(char s[]){
	stack *st=stack_new();
	int i;
	int c=0;
	for(i=0 ; s[i]!='\0' ; i++){
		int j=pref(s[i]);		
		if( j== 0){					//if { is entered it is pushed into the stack
			stack_push(st,0);
		}
		else if(stack_is_empty(st)){	//else if } is entered and stack is empty  
			stack_push(st,0);			//c is incremented and { is pushed into stack
			c++;
		}
		else{							//else if } is entered and stack is not empty  
			stack_pop(st);				//stack is popped
		}
	}
	int k=stack_size(st);				//half size of stack is added to current c
	k=k/2;
	c=c+k;
	printf("%d\n",c);
}
