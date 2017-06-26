/*This code converts Infix expression to Postfix expression
Y BHARGAVA SAI CS15B042 18-Sep-2016*/
#include <stdio.h>
#include "stack.h"
/*For every character I gave an integer mapping as follows
( ---> 0
- ---> 1
+ ---> 2
* ---> 3
/ ---> 4
% ---> 5
& ---> 6
| ---> 7
^ ---> 8
*/

// This functions gives the precedence order followed in C
int precedence(int x){
	if(x == 0) return 0;
	if(x == 1) return 4;
	if(x == 2) return 4;
	if(x == 3) return 5;
	if(x == 4) return 5;
	if(x == 5) return 5;
	if(x == 6) return 3;
	if(x == 7) return 1;
	if(x == 8) return 2;
}

int main(){
	int i;
	for(i = 0;i < 10;i++){
	char c;
	stack* s;
	int x;
	s = stack_new();
	while((c = getchar()) != '\n'){			//It reads character by character and terminates when a new line character is read
		if(c == ' ') continue;
		if((c >= 48 && c <= 57) || (c >= 97 && c <= 122)|| (c <= 90 && c >= 65) ){
			bool flag = false;
			printf("%c",c);
			c = getchar();
			if(c == '\n'){
				printf(" ");
				break;
			}	
			while(c != ' '){
				printf("%c",c);
				c = getchar();
				if(c == '\n'){ 
					flag = true;
					break;
				}
			}
			printf(" ");
			if(flag) break;
		}
		else if(c == '(') stack_push(s,0);		//if '(' is scanned , it is pushed to stack
		else if(c == ')'){						//if ')' is scanned , all elements are popped and printed until '(' is reached
 			while(!stack_is_empty(s)){
				x = stack_pop(s);
				if(x == 0) break;
				if(x == 1) printf("- ");
				else if(x == 2) printf("+ ");
				else if(x == 3) printf("* ");
				else if(x == 4) printf("/ ");
				else if(x == 5) printf("%% ");
				else if(x == 6) printf("& ");
				else if(x == 7) printf("| ");
				else if(x == 8) printf("^ ");
			}
		}
		/*If an operator is scanned this is followed
		1.if stack is empty push the operator
		2.if precedence of top element is less than the new operator ,Push the operator
		3.if precedence of top element is more than the new operator,Pop operators and print them until u find an operator
		which has lesser precedence than the new operator*/
		else if(c == '-'){					
			if(stack_is_empty(s)){
				stack_push(s,1);
				continue;
			} 
			x = stack_pop(s);
			if(precedence(x) < precedence(1)){
				stack_push(s,x);
				stack_push(s,1);
			}
			else{
				stack_push(s,x);
				while(!stack_is_empty(s)){
					x = stack_pop(s);
					if(precedence(x) < precedence(1)){
						stack_push(s,x);
						break;
					}
					if(x == 1) printf("- ");
					else if(x == 2) printf("+ ");
					else if(x == 3) printf("* ");
					else if(x == 4) printf("/ ");
					else if(x == 5) printf("%% ");
					else if(x == 6) printf("& ");
					else if(x == 7) printf("| ");
					else if(x == 8) printf("^ ");
				}
				stack_push(s,1);
			}
		}	
		else if(c == '+'){
			if(stack_is_empty(s)){
				stack_push(s,2);
				continue;
			} 
			x = stack_pop(s);
			if(precedence(x) < precedence(2)){
				stack_push(s,x);
				stack_push(s,2);
			}
			else{
				stack_push(s,x);
				while(!stack_is_empty(s)){
					x = stack_pop(s);
					if(precedence(x) < precedence(2)){
						stack_push(s,x);
						break;
					}
					if(x == 1) printf("- ");
					else if(x == 2) printf("+ ");
					else if(x == 3) printf("* ");
					else if(x == 4) printf("/ ");
					else if(x == 5) printf("%% ");
					else if(x == 6) printf("& ");
					else if(x == 7) printf("| ");
					else if(x == 8) printf("^ ");
				}
				stack_push(s,2);
			}
		}
		else if(c == '*'){
			if(stack_is_empty(s)){
				stack_push(s,3);
				continue;
			}	
			x = stack_pop(s);
			if(precedence(x) < precedence(3)){	
				stack_push(s,x);
				stack_push(s,3);
			}				
			else{
				stack_push(s,x);
				while(!stack_is_empty(s)){
					x = stack_pop(s);
					if(precedence(x) < precedence(3)){
						stack_push(s,x);
						break;
					}
					if(x == 1) printf("- ");
					else if(x == 2) printf("+ ");
					else if(x == 3) printf("* ");
					else if(x == 4) printf("/ ");
					else if(x == 5) printf("%% ");
					else if(x == 6) printf("& ");
					else if(x == 7) printf("| ");
					else if(x == 8) printf("^ ");
				}
				stack_push(s,3);	
			}
		}
		else if(c == '/'){
			if(stack_is_empty(s)){
				stack_push(s,4);
				continue;
			}	
			x = stack_pop(s);
			if(precedence(x) < precedence(4)){
				stack_push(s,x);
				stack_push(s,4);
			}
			else{
				stack_push(s,x);
				while(!stack_is_empty(s)){
					x = stack_pop(s);
					if(precedence(x) < precedence(4)){
						stack_push(s,x);
						break;
					}
					if(x == 1) printf("- ");
					else if(x == 2) printf("+ ");
					else if(x == 3) printf("* ");
					else if(x == 4) printf("/ ");
					else if(x == 5) printf("%% ");
					else if(x == 6) printf("& ");
					else if(x == 7) printf("| ");
					else if(x == 8) printf("^ ");
				}
				stack_push(s,4);
			}
		}
		else if(c == '%'){
			if(stack_is_empty(s)){
				stack_push(s,5);
				continue;
			}
			x = stack_pop(s);
			if(precedence(x) < precedence(5)){
				stack_push(s,x);
				stack_push(s,5);
			}
			else{
				stack_push(s,x);
				while(!stack_is_empty(s)){
					x = stack_pop(s);
					if(precedence(x) < precedence(5)){
						stack_push(s,x);
						break;
					}
					if(x == 1) printf("- ");
					else if(x == 2) printf("+ ");
					else if(x == 3) printf("* ");
					else if(x == 4) printf("/ ");
					else if(x == 5) printf("%% ");
					else if(x == 6) printf("& ");
					else if(x == 7) printf("| ");
					else if(x == 8) printf("^ ");
				}
				stack_push(s,5);
			}
		}
		else if(c == '&'){
			if(stack_is_empty(s)){
				stack_push(s,6);
				continue;
			}
			x = stack_pop(s);
			if(precedence(x) < precedence(6)){
				stack_push(s,x);
				stack_push(s,6);
			}
			else{
				stack_push(s,x);
				while(!stack_is_empty(s)){
					x = stack_pop(s);
					if(precedence(x) < precedence(6)){
						stack_push(s,x);
						break;
					}
					if(x == 1) printf("- ");
					else if(x == 2) printf("+ ");
					else if(x == 3) printf("* ");
					else if(x == 4) printf("/ ");
					else if(x == 5) printf("%% ");
					else if(x == 6) printf("& ");
					else if(x == 7) printf("| ");
					else if(x == 8) printf("^ ");
				}
				stack_push(s,6);
			}
		}
		else if(c == '|'){
			if(stack_is_empty(s)){
				stack_push(s,7);
				continue;
			}
			x = stack_pop(s);
			if(precedence(x) < precedence(7)){
				stack_push(s,x);
				stack_push(s,7);
			}
			else{
				stack_push(s,x);
				while(!stack_is_empty(s)){
					x = stack_pop(s);
					if(precedence(x) < precedence(7)){
						stack_push(s,x);
						break;
					}
					if(x == 1) printf("- ");
					else if(x == 2) printf("+ ");
					else if(x == 3) printf("* ");
					else if(x == 4) printf("/ ");
					else if(x == 5) printf("%% ");
					else if(x == 6) printf("& ");
					else if(x == 7) printf("| ");
					else if(x == 8) printf("^ ");
				}
				stack_push(s,7);
			}
		}
		else if(c == '^'){
			if(stack_is_empty(s)){
				stack_push(s,8);
				continue;
			}
			x = stack_pop(s);
			if(precedence(x) < precedence(8)){
				stack_push(s,x);
				stack_push(s,8);
			}
			else{
				stack_push(s,x);
				while(!stack_is_empty(s)){
					x = stack_pop(s);
					if(precedence(x) < precedence(8)){
						stack_push(s,x);
						break;
					}
					if(x == 1) printf("- ");
					else if(x == 2) printf("+ ");
					else if(x == 3) printf("* ");
					else if(x == 4) printf("/ ");
					else if(x == 5) printf("%% ");
					else if(x == 6) printf("& ");
					else if(x == 7) printf("| ");
					else if(x == 8) printf("^ ");
				}
				stack_push(s,8);
			}
		}
	}
	while(!stack_is_empty(s)){
		x = stack_pop(s);
		if(x == 1) printf("- ");
		else if(x == 2) printf("+ ");
		else if(x == 3) printf("* ");
		else if(x == 4) printf("/ ");
		else if(x == 5) printf("%% ");
		else if(x == 6) printf("& ");
		else if(x == 7) printf("| ");
		else if(x == 8) printf("^ ");
	}
	printf("\n");
	}
	return 0;	
}