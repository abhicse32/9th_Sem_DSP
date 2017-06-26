#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "List.h"

void main(){

	int T;
	scanf("%d",&T);
	
	char a = getchar();
	
	int i;
	for(i = 0; i < T; i++){
	
		a = getchar();
		stack* st = stack_new();
		int c = 0;
						
		while(1){
			
			if(a == '\n'){
				
				if((stack_size(st))%2 == 1) printf("-1\n");
				else printf("%d\n",(c + stack_size(st)/2));
				break ;
			}
			if(a == '{'){
				stack_push(st,a);
				a = getchar();
				continue;
			}
			if(a == '}'){
				if(!stack_is_empty(st))
				stack_pop(st);
				
				else{
					stack_push(st,a);
					c++;
				}
				a = getchar();
				continue ;
			}			
		}
		
	}
}
