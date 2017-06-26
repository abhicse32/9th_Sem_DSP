/*
	Author:G.Kavitha
	Roll No.: CS15B057
	Date: 16/09/16
	Infix to Postfix
*/
#include<stdio.h>
#include <string.h>
#include "stack.h"
const int SIZE=1005;

//Function to calculate the precedence of each of the operators
//Higher return value implies that the operator has higher precedence
int precedence(char ch){
	switch(ch){
		case '^': return 2;
		case '|': return 1;
		case '&': return 3;
		case '+': return 4;
		case '-': return 4;
		case '*': return 5;
		case '/': return 5;
		case '%': return 5;
		case '(': return 0;
		}
	return 0;
}

//Function to check if a particular string is an operator or not
//Returns 1 if it is an operator
int isOperator(char ch[SIZE]){
	if(!strcmp(ch,"+")||!strcmp(ch,"-")||!strcmp(ch,"*")||!strcmp(ch,"/")||!strcmp(ch,"^")||!strcmp(ch,"&")||!strcmp(ch,"|")||ch[0]=='%') return 1;
	return 0;
}

//Main function
int main(){
	stack* s=stack_new();//Creating new stack
	int top_prior=0;//Holds the precedence of the top most elemnt in the stack
	char str[SIZE];//input string

	while(fgets(str,SIZE,stdin)!=NULL){//Reading in the string
		top_prior=0;
		str[strlen(str)-1]='\0';

		char* temp=strtok(str," ");//temp now holds the part of the string seperated by space
		while(temp!=NULL){
			if(isOperator(temp)){//if it is an operator
				if(precedence(temp[0])>top_prior) {//If the operator is of higher precedence than the top element of the stack, then push this into stack
					stack_push(s,temp[0]);
					top_prior=precedence(temp[0]);//Updating precedence of the top element
				}
				else{//Then popping out all higher precedence operators and appending them into the postfix notation
					while(top_prior>=precedence(temp[0])){
						int save=stack_pop(s);
						printf("%c ",save);
						save=stack_pop(s);
						top_prior=precedence(save);
						stack_push(s,save);
					}
					stack_push(s,temp[0]);//Pushing the current operator into stack
					top_prior=precedence(temp[0]);//Updating precedence of top element
				}
			}
			else if(!strcmp(temp,"(")) {//If it is opening parenthesis then pushing it into stack
				stack_push(s,'(');
				top_prior=0;//Setting top_prior
			}
			else if(!strcmp(temp,")")){//If it is closing parenthesis then popping till open parenthesis is encountered
				int save=stack_pop(s);
				while(save!='('){
					printf("%c ",save);
					save=stack_pop(s);
				}
				if(stack_size(s)>0){
					save=stack_pop(s);
					top_prior=precedence(save);
					stack_push(s,save);			
				}
				else top_prior=0;
			}
			else {//It is a variable or a constant then appending to the postfix notation
				printf("%s ",temp);
			}
			temp=strtok(NULL," ");
		}
		while(stack_size(s)!=0){//When operators are left in the stack, then popping them out and appending them to the postfix notation
			int save=stack_pop(s);
			char t[2];
			t[0]=save; t[1]='\0';
			if(isOperator(t))
			printf("%c ",save);
		}
		printf("\n");
	}	
	return 0;
}
