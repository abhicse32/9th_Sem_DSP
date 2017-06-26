#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "List.h"

int label(char);

int main(){

	int T;
	scanf("%d",&T);
	
	char a = getchar();
	
	int i;
	for(i = 0; i < T; i++){
	
		a = getchar();
		stack* st = stack_new();
		int n = 0;	
				
		while(1){
			
			if(a == '\n'){
				if(stack_is_empty(st)) printf("1\n");
				else printf("0\n");
				break ;
			}
			if(label(a) > 0){
				n = label(a);
				stack_push(st,a);
				a = getchar();
				continue;
			}
			if(label(a) == -n){
				stack_pop(st);
				if(!stack_is_empty(st))
					n = label(st->top->head->data);
				else n = 0;	
				a = getchar();
				continue ;
			}
		
			else stack_push(st,a);
		
			a = getchar();			
		}
		
	}

	return 0;
}

int label(char a){

	switch(a){
		case '(' : return 1; 
		case ')' : return -1;
		case '{' : return 2;
		case '}' : return -2;
		case '[' : return 3;
		case ']' : return -3;
		
		default : return 0;
	}
}
