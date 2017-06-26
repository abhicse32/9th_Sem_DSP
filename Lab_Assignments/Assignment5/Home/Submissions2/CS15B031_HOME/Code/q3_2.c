//Author: Phalguna Rao Ch.
//CS15B031
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "List.h"
int main(){
	int t;
	for(t = 0; t < 10; t++){
		stack *st = stack_new();		
		int p = 0;
		char temp;
		int flag = 0;
		temp = getchar();			
		if(isdigit(temp)){		
			while(isdigit(temp)){
				flag = 1;
				int temp1 = temp-'0';		
				p = p*10+temp1;
				temp = getchar();
			}
		}
		else if(temp == '-'){		
										
			int temp2 = 0;
			temp = getchar();
			if(temp == ' ') temp = '-';		
			else{
				while(isdigit(temp)){
					temp2 = 1;
					flag = 1;
					int temp1 = temp-'0';
					p = p*10+temp1;
					temp = getchar();
			}
			if(temp2 == 1) p = -1 * p;
			}
		}
		while(1){
			if(flag == 1) stack_push(st,p);
			else if((temp != ' ')&&(temp!='\0')&&(temp!='\n')){
				int op2 = stack_pop(st);
				int op1 = stack_pop(st);
				switch(temp){
					case '+':
						stack_push(st, op1 + op2);
						break;
					case '-':
						stack_push(st, op1 - op2);
						break;
					case '*':
						stack_push(st, op1 * op2);
						break;
					case '/':
						stack_push(st, op1 / op2);
						break;
					case '%':
						stack_push(st, op1 % op2);
						break;
					case '&':
						stack_push(st, op1 & op2);
						break;
					case '|':
						stack_push(st, op1 | op2);
						break;
					case '^':
						stack_push(st, op1 ^ op2);
						break;
				}
			}
			p = 0;
			flag = 0;
			temp = getchar();
			if(temp == ' ') temp=getchar();
			if((temp == '\0')||(temp == '\n')) break;		
			else if(isdigit(temp)){
				while(isdigit(temp)){
					flag = 1;
					int temp1 = temp - '0';
					p = p * 10 + temp1;
					temp = getchar();
				}
			}
			if(temp == '-'){
				int temp2 = 0;
				temp = getchar();
				if(temp == ' ') temp = '-';
				else{
					while(isdigit(temp)){
						temp2 = 1;
						flag = 1;
						int temp1 = temp-'0';
						p = p * 10 + temp1;
						temp = getchar();
				}
				if(temp2 == 1) p= -1 * p;
				}
			}
		}
		printf("%d\n", stack_pop(st));
	}
	return 0;
}
