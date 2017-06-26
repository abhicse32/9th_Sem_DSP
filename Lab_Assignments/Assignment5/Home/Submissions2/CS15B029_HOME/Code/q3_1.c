#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>
#include "List.h"
#include "stack.h"

char stack_top(stack* avi){
	return llist_get(avi->top,0);
}


int avinash(char operator){
	switch(operator){
		case '/':
		case '%':
		case '*':
		return 4;
		break;
		case '-':
		case '+':
		return 3;
		break;
		case '&':
		return 1;
		break;
		case '|':
		return 2;
		break;
		case '^':
		return 0;
		break;	
	}
	return -1;
}

int Operator(char o){
	if(o=='+' || o=='-' || o=='/' || o=='*' || o=='%' || o=='(' || o==')' || o=='|' || o=='&' || o=='^') return 1;
	 return 0;
}

void infixtopostfix(){
	 char c=getchar();
	 char str[100];
	  int k;
	  for(k=0;k<99;k++) str[k]='#';
	      int j=0;
	      char pop;
	      stack* s=stack_new();
	      k=0;
	while(c!='\n'){
		while(Operator(c)==0){ 
			//printf("%c",c);
			str[k]=c;
			k++;
			c=getchar();
			  if(c=='\n') 
			  {
			  	j=1;
				break;
			 }	
			//printf("s");
			if(k==100) return;
		}	
			if(j==1) break;
			if(stack_is_empty(s)==true){
				stack_push(s,c);
				c=getchar();
				continue;
			}	
			else if(c =='('){ 
				stack_push(s,c);
				c=getchar();
				continue;
			}	
			else if(c == ')'){
				while(stack_top(s)!='('){
					pop=stack_pop(s);
					str[k]=' ';
					str[++k]=pop;
					k++;
					if(k==100) return;		
				}
				stack_pop(s);
				c=getchar();
				continue; 
			}
			else if(avinash(c)>avinash(stack_top(s))){
				stack_push(s,c);
				c=getchar();
				continue;

			}
			else if(avinash(c)<=avinash(stack_top(s))){
				while(avinash(c)<=avinash(stack_top(s)) && !stack_is_empty(s)){
						str[k]=' ';
						str[++k]=stack_pop(s);
						k++;
						if(k==100) return;	
				}
				stack_push(s,c);
				c=getchar();
				continue;
			}
			
	
	}
		//stack_print(S);	
		while(!stack_is_empty(s)){
			str[k]=' ';
			str[k+1]=stack_pop(s);
			k+=2;
	}
	printf("%c",str[0]);
	for(k=1;str[k]!='#';k++){
		if(str[k]==' '&&str[k-1]==' '); 
		else printf("%c",str[k]);

	}
	return;
		
}

int main(){
	int t=10;
	while(t--){
		infixtopostfix();
		printf("\n");
	}
	return 0;

}





