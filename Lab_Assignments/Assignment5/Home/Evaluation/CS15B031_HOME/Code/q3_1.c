//Author: Phalguna Rao Ch.
//CS15B031
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "stack.h"
#include "List.h"
int order(char var){
	if(var == '|') return 0;
	if(var == '^') return 1;
	if(var == '&') return 2;
	if(var == '+' || var == '-') return 3;
	if(var == '*' || var == '/' || var == '%') return 4;
}
bool comp(char a, char b){
	if(order(a) >= order(b)) return true;
	else return false;
}
int main(){
	int t = 10;
	while(t--){		
		char var = getchar();					
		stack *st=stack_new();	
		while(1){
			if(isalnum(var)){			
				printf("%c",var);
				var=getchar();
				while(isalnum(var)){
					printf("%c",var);
					var=getchar();						
				}
				printf(" ");
			}
			else if(var=='('){
				stack_push(st,'(');
			}
			else if(var==')'){
				if(!stack_is_empty(st)){
					char temp=stack_pop(st);	
					while(temp!='('){
						printf("%c ",temp);
						temp=stack_pop(st);
					}
				}
			}
			else{
		
				int k = order(var);
				if(k == 4){
	
					if(!stack_is_empty(st)){
						int t=0;
						char temp=stack_pop(st);
						int p = order(temp);	
						bool q = comp(temp, var);									
						while(p == 4){	
																				
							printf("%c ",temp);
							if(stack_is_empty(st)){
								t=1;
								break;
							}
							else temp=stack_pop(st);
							p = order(temp);
						}
						if(t!=1) stack_push(st,temp);
					}
					stack_push(st,var);
				}
				else if(k ==3){
					
					if(!stack_is_empty(st)){
						int t=0;
						char temp=stack_pop(st);
						int p = order(temp);								
						while((temp=='*')||(temp=='/')||(temp=='%')||(temp=='+')||(temp=='-')){
							printf("%c ",temp);
							if(stack_is_empty(st)){
								t=1;
								break;
							}
							else temp=stack_pop(st);
							int p = order(temp);								
						}
						if(t!=1) stack_push(st,temp);
					}
					stack_push(st,var);
				}
				
				else if(var=='&'){
					
					if(!stack_is_empty(st)){
						int t=0;
						char temp=stack_pop(st);
						while((temp=='*')||(temp=='/')||(temp=='%')||(temp=='+')||(temp=='-')||(temp=='&')){
							printf("%c ",temp);
							if(stack_is_empty(st)){
								t=1;
								break;
							}
							else temp=stack_pop(st);
						}
						if(t!=1) stack_push(st,temp);
					}
					stack_push(st,var);
				}
	
				else if(var=='^'){
					
					if(!stack_is_empty(st)){
						int t=0;
						char temp=stack_pop(st);
						while((temp=='*')||(temp=='/')||(temp=='%')||(temp=='+')||(temp=='-')||(temp=='&')||(temp=='^')){
							printf("%c ",temp);
							if(stack_is_empty(st)){
								t=1;
								break;
							}
							else temp=stack_pop(st);
						}
						if(t!=1) stack_push(st,temp);
					}
					stack_push(st,var);
				}
	
				else if(var=='|'){
					
					if(!stack_is_empty(st)){
						int t=0;
						char temp=stack_pop(st);
						while((temp=='*')||(temp=='/')||(temp=='%')||(temp=='+')||(temp=='-')||(temp=='&')||(temp=='^')||(temp=='|')){
							printf("%c ",temp);
							if(stack_is_empty(st)){
								t=1;
								break;
							}
							else temp=stack_pop(st);
						}
						if(t!=1) stack_push(st,temp);
					}
					stack_push(st,var);
				}
			}
			if((var=='\0')||(var=='\n')) break;	
			var=getchar();
			if((var=='\0')||(var=='\n')) break;			
		}
		
		while(stack_is_empty(st) == false){
			char temp=stack_pop(st);
			printf("%c ",temp);
		}
		printf("\n");
	}
	return 0;
}                             
