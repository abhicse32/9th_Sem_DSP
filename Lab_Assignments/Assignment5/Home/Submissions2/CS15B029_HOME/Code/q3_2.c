#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include "stack.h"

int Perform(char,int,int);
int operator(char);
int evaluate(char*);
int digit(char);

int main(){
	
	int t=10;
	for(t=10;t>=0;t--){		
		char str[200];
		fgets(str,200,stdin);
		int answer=evaluate(str);
		printf("%d\n",answer);
	}
	return 0;
}

int evaluate(char equ[200]){

	stack* avi=stack_new();
	
	for(int k=0;k<strlen(equ);k++){
		if(equ[k]==' '){
			continue;
		}
		else if(operator(equ[k])==1 && (equ[k+1]==' ') || operator(equ[k])==1 && k==strlen(equ)-2){
			int operand2=stack_pop(avi);
			int operand1=stack_pop(avi);
			
			int answer=Perform(equ[k],operand1,operand2);
			stack_push(avi,answer);
		}
		else if((digit(equ[k])==1) || ((operator(equ[k]))==1 && (digit(equ[k+1])==1))){
		
			int operand=0;
			if((operator(equ[k])==1) && (digit(equ[k+1])==1)){
			
				while((k<strlen(equ)) && (digit(equ[k+1])==1)){
					operand=operand*10+(equ[k+1]-'0');
					k++;
				}
				stack_push(avi,-1*operand);
			}
			else{
			
				while(k<strlen(equ) && (digit(equ[k])==1)){
			
					operand=operand*10 + (equ[k]-'0');
					k++;
				}
				k--;
				stack_push(avi,operand);
			}
		}
		
	}
	
	return stack_pop(avi);
}
			
int operator(char c){

	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='|' || c=='&' || c=='^' || c=='%'){
		return 1;
	}
	else{
		return 0;
	}
}

int digit(char c){
	if(c>='0'&& c<='9') return 1;
	else return 0;
}

int Perform(char operator,int operand1,int operand2){
	
	if(operator=='-') return operand1-operand2;
	else if(operator=='*') return operand1*operand2;
	else if(operator=='/') return operand1/operand2;
	else if(operator=='+') return operand1+operand2;
	else if(operator=='%') return operand1 % operand2;
	else if(operator=='^') return operand1 ^ operand2;
	else if(operator=='|') return operand1 | operand2;
	else if(operator=='&') return operand1 & operand2;
	else{
		return -1;
	}
}
		
