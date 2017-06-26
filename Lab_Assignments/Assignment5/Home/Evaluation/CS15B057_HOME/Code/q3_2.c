/*
	Author:G.Kavitha
	Roll No.: CS15B057
	Date: 16/09/16
	Evaluating postfix notation
*/
#include<stdio.h>
#include "stack.h"
#include <string.h>
const int SIZE=1005;
int main(){
	char str[SIZE];//input string
	stack* s=stack_new();//Creating new stack
	while(fgets(str,SIZE,stdin)!=NULL){//Reading in the string
		str[strlen(str)-1]='\0';

		char* temp=strtok(str," ");//temp now holds the part of the string seperated by space
		while(temp!=NULL){
			if(!strcmp(temp,"+")){//If it is +, then pop out two numbers to do b+a and then push the result
				int a=stack_pop(s);
				int b=stack_pop(s);
				stack_push(s,a+b);
			}
			else if(!strcmp(temp,"-")){//If it is -, then pop out two numbers to do b-a and then push the result
				int a=stack_pop(s);
				int b=stack_pop(s);
				stack_push(s,b-a);	
			}
			else if(!strcmp(temp,"*")){//If it is *, then pop out two numbers to do b*a and then push the result
				int a=stack_pop(s);
				int b=stack_pop(s);
				stack_push(s,a*b);	
			}
			else if(!strcmp(temp,"/")){//If it is /, then pop out two numbers to do b/a and then push the result
				int a=stack_pop(s);
				int b=stack_pop(s);
				if(a==0) break;
				stack_push(s,b/a);	
			}
			else if(!strcmp(temp,"&")){//If it is &, then pop out two numbers to do b&a and then push the result
				int a=stack_pop(s);
				int b=stack_pop(s);
				stack_push(s,a&b);	
			}	
			else if(!strcmp(temp,"%")){//If it is %, then pop out two numbers to do b%a and then push the result
				int a=stack_pop(s);
				int b=stack_pop(s);
				if(a==0) break;
				stack_push(s,b%a);	
			}	
			else if(!strcmp(temp,"^")){//If it is ^, then pop out two numbers to do b^a and then push the result
				int a=stack_pop(s);
				int b=stack_pop(s);
				stack_push(s,a^b);	
			}	
			else if(!strcmp(temp,"|")){//If it is |, then pop out two numbers to do b|a and then push the result
				int a=stack_pop(s);
				int b=stack_pop(s);
				stack_push(s,a|b);	
			}	
				
			else{//If it is number, then push it into stack
				int num=atoi(temp);
				stack_push(s,num);
			}
			temp=strtok(NULL," ");
		}

		int ans=stack_pop(s);//ans is the number in the stack
		printf("%d\n",ans);//Printing answer
	}		
	return 0;
}
