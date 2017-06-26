//Author: Phalguna Rao Ch.
//Roll no.: CS15B031
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#include"List.h"
#define SIZE 1001
int main(){
int t;
scanf("%d", &t);
while(t--){										//Runs t times
	char* exp = (char*) malloc(sizeof(char) * SIZE);
	scanf("%s", exp);
	stack* st = stack_new();
	int i, p = 0;
	int len = strlen(exp);
	for(i = 0; i < len; i++){
		if(i == 0 && (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')){	//If a[0] is a closing bracket.. not balancing
			printf("0\n"); p = 1;
			break;
		}
		else{
			if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){		//push into stack
				stack_push(st, exp[i]);
			}
			else{								//check for the top in stack and print accordingly
				if(exp[i] == ')'){					
					if(stack_pop(st) == '('){
				
					}
					else{
						printf("0\n"); p = 1;
						break;
					}
				}
				else{
					if(exp[i] == '}'){
						if(stack_pop(st) == '{'){
							
						}
						else{
							printf("0\n"); p = 1;
							break;
						}
					}
			
					else{
						if(exp[i] == ']'){
							if(stack_pop(st) == '['){
								
							}
							else{
								printf("0\n"); p = 1;
								break;
							}
						}
					}
				}
			}
		}
	}
	if(p == 1){
	}
	else{									
		if(stack_is_empty(st) == false){
			printf("0\n");
			
		}
		else{
			printf("1\n");
			
		}
	}
}
return 0;
}
