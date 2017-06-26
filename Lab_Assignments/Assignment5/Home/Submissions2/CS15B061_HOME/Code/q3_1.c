
/*-----------------------------------------------------------------------------
 *  Program to convert infix to postfix expression
 *  Name: Harshavardhan.P.K.
 *  RollNo: CS15B061
 *  Date: Sept 17, 2016
 *-----------------------------------------------------------------------------*/
#include "stack.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* postfix(char*);

/*-----------------------------------------------------------------------------
 *  Function: postfix - to convert infix to postfix
 *  Input: exp : infix expression string
 *  Returns string of postfix
 *-----------------------------------------------------------------------------*/
char* postfix(char* exp){
	int len=0,i,j;
	//calculate length of string
	while(exp[len]!='\0') len++;
	//ans stores the resultant postfix string
	char* ans=(char*)malloc(sizeof(char)*(len+2));
	stack* s = stack_new();
	//push sentinal last element in stack
	stack_push(s,(int)'#');
	i=0;j=0;
	while(i<len){
		//if next token is a variable
		if(isalnum(exp[i])){
			while(isalnum(exp[i])){
			ans[j++]=exp[i]; //extract all the letters of variable to ans
			i++;
			}
			ans[j++]=' ';
			i++;
			continue;
		}
		//in case we get a operator or paranthesis
		else{
			if(exp[i]==')'){
				//pop all elements until '(' and capture in ans
				char c = stack_pop(s);
				while(c!='(' && c!='#'){
					ans[j++]=c;
					ans[j++]=' ';
					c = stack_pop(s);
				}
			}
			//if any other operator pop all the elements of same or higher precedence and put in ans, then push this operator
			else if(exp[i]=='+' || exp[i]=='-'){
				char c = stack_pop(s);
				while(c=='*' || c=='/' || c=='+' || c=='-'){
					ans[j++]=c;
					ans[j++]=' ';
					c = stack_pop(s);
				}
				stack_push(s,c);
				stack_push(s,exp[i]);
			}
			else if(exp[i]=='|'){
				char c = stack_pop(s);
				while(c!='(' && c!='#'){
					ans[j++]=c;
					ans[j++]=' ';
					c=stack_pop(s);
				}
				stack_push(s,c);
				stack_push(s,exp[i]);
			}

			else if(exp[i]=='&'){
				char c = stack_pop(s);
				while(c!='(' && c!='#' && c!='|' && c!='^'){
					ans[j++]=c;
					ans[j++]=' ';
					c=stack_pop(s);
				}
				stack_push(s,c);
				stack_push(s,exp[i]);
			}

			else if(exp[i]=='*' || exp[i]=='/' || exp[i]=='%'){
				char c = stack_pop(s);
				while(c=='*' || c=='/' || c=='%'){
					ans[j++]=c;
					ans[j++]=' ';
					c = stack_pop(s);
				}
				stack_push(s,c);
				stack_push(s,exp[i]);
			}
			else if(exp[i]=='^'){
				char c = stack_pop(s);
				while(c!='(' && c!='#' && c!='|'){
					ans[j++]=c;
					ans[j++]=' ';
					c = stack_pop(s);
				}
				stack_push(s,c);
				stack_push(s,exp[i]);
			}
			else if(exp[i]=='(') stack_push(s,exp[i]);
		}
		i+=2;
	}//pop out all remaining operators into ans
	char c = stack_pop(s);
	while(c!='#'){
		ans[j++]=c;
		ans[j++]=' ';
		c = stack_pop(s);
	}
	ans[j]='\0';
	//return the postfix expression
	return ans;

}




int main(void){
	char st[1000];
	while(fgets(st,1000,stdin))
	printf("%s\n",postfix(st));
	return 0;
}
