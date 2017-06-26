#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>
#include "List.h"
#include "stack.h"

char stack_top(stack* S){
	char ret_val=llist_get(S->top,0);
	return ret_val;
}


int weight(char c){

	if(c=='*' || c=='/' || c=='%'){
		return 5;
	}
	if(c=='+' || c=='-'){
		return 4;
	}
	if(c=='&'){
		return 3;
	}
	if(c=='^'){
		return 2;
	}
	if(c=='|'){
		return 1;
	}
	return -1;
}

bool Operator(char c){
	if(c=='+' || c=='-' || c=='&' || c=='|' || c=='*' || c=='/' || c=='%' || c=='^' || c=='(' || c==')'){
		return true;
	}
	 return false;
}

void convert_infix_to_postfix(){
	char c=getchar();
	char exp[100];
	int i;
	for(i=0;i<99;i++) exp[i]='@';
	int j=0;
	stack* S=stack_new();
	i=0;
	while(c!='\n'){
	
		while(!Operator(c)){ 
			exp[i]=c;
			i++;
			c=getchar();
			if(c=='\n') {
				j=1;
				break;
			}	
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
			while(stack_top(S)!='('){
				char x;
				x=stack_pop(S);
				exp[i]=' ';
				exp[++i]=x;
				i++;
				if(i==100) return;		
			}
			stack_pop(S);
			c=getchar();
			continue; 
		}
		
		else if(weight(c)>weight(stack_top(S))){
			stack_push(S,c);
			c=getchar();
			continue;

		}
		
		else if(weight(c)<=weight(stack_top(S))){
		
			while(weight(c)<=weight(stack_top(S)) && !stack_is_empty(S)){
			
				exp[i]=' ';
				exp[++i]=stack_pop(S);
				i++;
				if(i==100) return;	
			}
				stack_push(S,c);
				c=getchar();
				continue;
		}	
	}	
	while(!stack_is_empty(S)){
		exp[i]=' ';
		exp[i+1]=stack_pop(S);
		i+=2;
	}
	printf("%c",exp[0]);
	
	for(i=1;exp[i]!='@';i++){
		if(exp[i]==' '&&exp[i-1]==' '); 
		else printf("%c",exp[i]);

	}
	return;
		
}

int main(void){
	int t=10;
	while(t>0){
		convert_infix_to_postfix();
		printf("\n");
		t--;
	}
	return 0;

}





