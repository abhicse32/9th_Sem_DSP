/*This code evaluates the Postfix expression
Y BHARGAVA SAI CS15B042 18-Sep-2016*/
#include <stdio.h>
#include "stack.h"
//#include "List.c"

int main(){
	int v;
	for(v = 0;v < 10;v++){
	stack* stk = stack_new();
	char c;
	int x;
	int y;	
	while((c = getchar()) != '\n'){			//It is read character by character and terminates when a new line character is read
		if(c == ' ') continue;
		else if((c >= 48 && c <= 57)){		//If a number is scanned it is pushed into the stack
			x = c - 48;
			bool flag = false;
			c = getchar();
			if(c == '\n'){
				stack_push(stk,x);
				break;
			}	
			while(c != ' '){				
				x = (x*10) + (c - 48);
				c = getchar();
				if(c == '\n'){ 
					flag = true;
					break;
				}
			}
			stack_push(stk,x);
			if(flag) break;				
		}
		else if(c == '-'){						//If - is scanned checks whether it is a negative no.Pushes into stack if its a number
			c = getchar();						//else pops two numbers out of the stack and performs substraction and pushes result
			if(c == '\n') break;
			else if(c == ' '){
				x = stack_pop(stk);
				y = stack_pop(stk);
				stack_push(stk,y - x);
			}
			else{
				x = c - 48;
				bool flag = false;
				c = getchar();
				if(c == '\n'){
					stack_push(stk,x);
					break;
				}	
				while(c != ' '){
					x = (x*10) + (c - 48);
					c = getchar();
					if(c == '\n'){ 
						flag = true;
						break;
					}
				}
				stack_push(stk,-1*x);
				if(flag) break;
			}
		}
		else if(c == '*'){			//Pops two numbers,multiplied and pushes back the result 
			x = stack_pop(stk);
			y = stack_pop(stk);
			stack_push(stk,y * x);
		}
		else if(c == '+'){			//Pops two numbers,added and pushes back the result
			x = stack_pop(stk);
			y = stack_pop(stk);
			stack_push(stk,y + x);
		}
		else if(c == '/'){			//Pops two numbers,divided and pushes back the result
			x = stack_pop(stk);
			y = stack_pop(stk);
			stack_push(stk,y / x);
		}
		else if(c == '%'){			//Pops a,b and pushes a % b
			x = stack_pop(stk);
			y = stack_pop(stk);
			stack_push(stk,y % x);
		}
		else if(c == '&'){			//Pops a,b and pushes a & b
			x = stack_pop(stk);
			y = stack_pop(stk);
			stack_push(stk,y & x);
		}
		else if(c == '|'){			//Pops a,b and pushes a | b
			x = stack_pop(stk);
			y = stack_pop(stk);
			stack_push(stk,y | x);
		}
		else if(c == '^'){			//Pops a,b and pushes a ^ b
			x = stack_pop(stk);
			y = stack_pop(stk);
			stack_push(stk,y ^ x);
		}
	}
	x = stack_pop(stk);
	printf("%d\n",x);				//Prints the final answer
}
return 0;
}

