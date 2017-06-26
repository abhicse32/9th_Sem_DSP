#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "List.h"

int evaluate(void){

	stack *stk = stack_new();

	char a;
	
	int x,y;

	while(a = getchar()){
	
		switch(a){
			
			case '+' : {
				y = stack_pop(stk);
				x = y + stack_pop(stk);
				stack_push(stk,x);
				a = getchar();
				if(a == '\n') return stk->top->head->data;
				break;
			}
			
			case '-' :{
				char c;
				c = getchar();
				if((c == ' ')||(c == '\n')){
					y = stack_pop(stk);
					x = stack_pop(stk) - y;
					stack_push(stk,x);
					if(c == '\n') return stk->top->head->data;
					break;	
				}
				else{
					int i = 2;
					char* str = (char*)malloc(10*sizeof(char));
					str[0] = a;
					str[1] = c;
					a = getchar();
					while(a != ' '){
						if(a == '\n') return stk->top->head->data;
						str[i] = a;
						i++;
						a = getchar();					
					}
					str[i] = '\0';
					int temp = atoi(str);
					stack_push(stk,temp);
					break;				
				}
			}	
				
			case '*' :{ 
				y = stack_pop(stk);
				x = stack_pop(stk) * y;
				stack_push(stk,x);
				a = getchar();
				if(a == '\n') return stk->top->head->data;
				break;	
			}
				
			case '/' :{
				y = stack_pop(stk);
				x = stack_pop(stk) / y;
				stack_push(stk,x);
				a = getchar();
				if(a == '\n') return stk->top->head->data;
				break;
			}
				
			case '^' :{
				y = stack_pop(stk);
				x = stack_pop(stk) ^ y;
				stack_push(stk,x);
				a = getchar();
				if(a == '\n') return stk->top->head->data;
				break;
			}
				
			case '&' :{ 
				y = stack_pop(stk);
				x = stack_pop(stk) & y;
				stack_push(stk,x);
				a = getchar();
				if(a == '\n') return stk->top->head->data;
				break;
			}
			
			case '|' :{ 
				y = stack_pop(stk);
				x = stack_pop(stk) | y;
				stack_push(stk,x);
				a = getchar();
				if(a == '\n') return stk->top->head->data;
				break;
			}
			
			case '%' :{
				y = stack_pop(stk);
				x = stack_pop(stk) % y;
				stack_push(stk,x);
				a = getchar();
				if(a == '\n') return stk->top->head->data;
				break;
			}	
			
			default :{
				int i = 1;
				char* str = (char*)malloc(10*sizeof(char));
				str[0] = a;
				a = getchar();
				while(a != ' '){
					if(a == '\n') break;
					str[i] = a;
					i++;
					a = getchar();					
				}
				str[i] = '\0';
				int temp = atoi(str);
				stack_push(stk,temp);
				if(a == '\n') return stk->top->head->data;
				break;
			}		
		}
			
	}
	
}

int main(){

		printf("%d\n",evaluate());
		printf("%d\n",evaluate());
		printf("%d\n",evaluate());
		printf("%d\n",evaluate());
		printf("%d\n",evaluate());
		printf("%d\n",evaluate());
		printf("%d\n",evaluate());
		printf("%d\n",evaluate());
		printf("%d\n",evaluate());
		printf("%d\n",evaluate());
		

}
