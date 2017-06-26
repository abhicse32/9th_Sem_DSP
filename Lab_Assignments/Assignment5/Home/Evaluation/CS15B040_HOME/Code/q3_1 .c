#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>
#include "List.h"
#include "stack.h"

char gettop(stack* S){
	return llist_get(S->top,0);
}


int precedence(char operator){
	switch(operator){
		case '*':
		case '/':
		case '%':
		return 4;
		break;
		case '+':
		case '-':
		return 3;
		break;
		case '^':
		return 1;
		break;
		case '&':
		return 2;
		break;
		case '|':
		return 0;
		break;	
	}
	return -1;
}

bool isOperator(char c){
	switch(c){
		case '*':
		case '/':
		case '%':
		case '+':
		case '-':
		case '^':
		case '&':
		case '|':
		case '(':
		case ')':
		return true;
	}
	 return false;
}

void infixToPostfix(){
	char c=getchar();
	char out[100];
	int i;
	for(i=0;i<99;i++) out[i]='#';
	int j=0;
	char pop;
	stack* S=stack_new();
	i=0;
	while(c!='\n'){
		while(!isOperator(c)){ 
			//printf("%c",c);
			out[i]=c;
			i++;
			c=getchar();
			if(c=='\n') 
			{	j=1;
				break;
			}	
			//printf("s");
			if(i==100) return;
		}	
			if(j==1) break;
			if(stack_is_empty(S)==true){
				stack_push(S,c);
				c=getchar();
				continue;
			}	
			else if(c =='('){ 
				stack_push(S,c);
				c=getchar();
				continue;
			}	
			else if(c == ')'){
				while(gettop(S)!='('){
					pop=stack_pop(S);
					out[i]=' ';
					out[++i]=pop;
					i++;
					if(i==100) return;		
				}
				stack_pop(S);
				c=getchar();
				continue; 
			}
			else if(precedence(c)>precedence(gettop(S))){
				stack_push(S,c);
				c=getchar();
				continue;

			}
			else if(precedence(c)<=precedence(gettop(S))){
				while(precedence(c)<=precedence(gettop(S)) && !stack_is_empty(S)){
						out[i]=' ';
						out[++i]=stack_pop(S);
						i++;
						if(i==100) return;	
				}
				stack_push(S,c);
				c=getchar();
				continue;
			}
			
	
	}
		//stack_print(S);	
		while(!stack_is_empty(S)){
			out[i]=' ';
			out[i+1]=stack_pop(S);
			i+=2;
	}
	printf("%c",out[0]);
	for(i=1;out[i]!='#';i++){
		if(out[i]==' '&&out[i-1]==' '); 
		else printf("%c",out[i]);

	}
	return;
		
}

int main(){
	int t=10;
	while(t--){
		infixToPostfix();
		printf("\n");
	}
	return 0;

}





