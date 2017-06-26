#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "List.h"
#include<string.h>

int check_parenthesis(char*);//checking the matching parenthesis
int matching(char,char);//checking the corresponding matching brackets if available

int main(void){

	int t;
	scanf("%d",&t);
	int i;
	char string[1001];
	int check[t];
	for(i=0;i<t;i++){
		scanf("%s",string);
		check[i]=check_parenthesis(string);		
	}
	for(i=0;i<t;i++){
		printf("%d\n",check[i]);
	}
	return 0;
}

int check_parenthesis(char s[1001]){
	
	if(strlen(s)%2!=0){
		return 0;
	}
	else{
		stack* sstack;
		sstack=stack_new();
		int i=0;
		while(s[i]!='\0'){

			if(s[i]=='{'||s[i]=='['||s[i]=='('){
				stack_push(sstack,s[i]);
			}
			if(s[i]=='}'||s[i]==']'||s[i]==')'){
				if(stack_is_empty(sstack)){
					return 0;
				}
				int j=matching(stack_pop(sstack),s[i]);
				if(!j){
					return 0;
				}
			}
			i++;
		}
		if(stack_is_empty(sstack)){
			return 1;
		}
	}
}

int matching(char c1,char c2){
	if(c1=='['&& c2==']'){
		return 1;
	}
	else if(c1=='{'&& c2=='}'){
		return 1;
	}
	else if(c1=='(' && c2==')'){
		return 1;
	}
	else{
		return 0;
	}
}
 
	
	
	
		
