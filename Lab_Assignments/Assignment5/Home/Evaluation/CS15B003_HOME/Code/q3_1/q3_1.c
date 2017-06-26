#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"
#include "List.h"

int prefer(char a){

	switch(a){
		case '+' : return 4;
		case '-' : return 4;
		case '*' : return 5;
		case '/' : return 5;
		case '%' : return 5;
		case '&' : return 3;
		case '^' : return 2;
		case '|' : return 1;
	}
}

char* fun(void){
	
	int pref = 0;
	char a;
	int j = 0;
	int i = 0;
	int k = 0;
	char **str = (char**)malloc(100*sizeof(char*));
	for(k = 0; k < 100; k++) *(str + k) = (char*)malloc(100*sizeof(char));
	stack* stk_exp = stack_new();
	stack* stk_op = stack_new();
	a = getchar();
	
	while(a != ')'){
		
		if(a == '\n'){
			stack_push(stk_exp, str[j]);
			break;
		}

		if(a == ' '){
		
			if(j%2 == 0)
				stack_push(stk_exp, str[j]);
			
			else{
				
				if(pref >= prefer(str[j][0])){
				char *temp = stk_exp->top->head->data;
				stack_pop(stk_exp);
				stack_push(stk_exp, strcat(strcat(stack_pop(stk_exp)," "),strcat(strcat(temp," "),stack_pop(stk_op))));	
				stack_push(stk_op,str[j]);
				pref = prefer(str[j][0]);
				
				}
				
				else{
					stack_push(stk_op,str[j]);
					pref = prefer(str[j][0]);
				}
			
			}
			
			i = 0;
			j++;
			a = getchar();
			continue;
		}
		
		if(a == '('){
			getchar();
			stack_push(stk_exp,fun());
			a = getchar();
			if(a == '\n') break;
			a = getchar();
			j++;
			i = 0;
			continue;
		}
		str[j][i] = a;
		i++;
		a = getchar();
	
	}

	while(!stack_is_empty(stk_op)){
		
		char *top = stk_exp->top->head->data;
		
		stack_pop(stk_exp);
		stack_push(stk_exp, strcat(strcat(stack_pop(stk_exp)," "),strcat(strcat(top," "),stack_pop(stk_op))));
	}

	return stk_exp->top->head->data;		
}

int main(){
	
	int i = 0;
	
	for(i = 0; i < 10; i++) printf("%s\n",fun());

	return 0;	
}
