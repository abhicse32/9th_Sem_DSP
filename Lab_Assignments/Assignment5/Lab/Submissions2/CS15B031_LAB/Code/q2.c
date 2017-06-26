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
	char* exp = (char*) malloc(sizeof(char) * SIZE);
	while(t--){									//runs t times
		scanf("%s", exp);
		stack* st = stack_new();
		int i, count = 0;
		int len = strlen(exp);
		//printf("%d\n", stack_size(st));
		if(len % 2 == 1){							//if strlen in odd.. cant be balanced
			printf("-1\n");
		}
		else{
			//printf("%s\n", exp);
			for(i = 0; i < len; i++){
				if(stack_size(st) <= 0 && exp[i] == '}'){		//increments count only if stack is empty and exp[i] = }
					count++;
					stack_push(st, '{');				//push { into stack
				}
				else{
					if(stack_size(st) > 0 && exp[i] == '}'){	//pops if stack is nonempty
						stack_pop(st);
					}	
				
					else{						//just push if exp[i] = {
						if(exp[i] == '{'){
							stack_push(st, '{');
						}
					}
				}
				//printf("%d\n", stack_size(st));
			}
			printf("%d\n", count + (stack_size(st)/2));			//stack need not be empty.. but will always be of even size
		}
	}
	return 0;
}




















