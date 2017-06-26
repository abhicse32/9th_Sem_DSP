#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "List.h"
#include<string.h>

int minrev_to_balance(char*);//min reversals for balancing the string
int matching(char,char);//matching 

int main(void){
	int t;
	scanf("%d",&t);
	int i;
	char string[1001];
	int minrev[t];
	
	for(i=0;i<t;i++){
		scanf("%s",string);
		minrev[i]=minrev_to_balance(string);//minimum reversal 		
	}
	for(i=0;i<t;i++){
		printf("%d\n",minrev[i]);
	}
	return 0;
}

int minrev_to_balance(char s[1001]){//function for calculating the minimum reversals for balancing the string
	if(strlen(s)%2!=0){//if the length of string is odd cannot be baalnced
		return -1;
	}
	else{
		stack* sstack;
		sstack=stack_new();//creating a new stack
		int count=0;
		int i=0;
		
		while(s[i]!='\0'){//When end is not met
		
			if((s[i]=='}')&&(stack_is_empty(sstack))){//if a closed bracking is met when the stack is empty reverse the bracket
				s[i]='{';
				count++;
			}

			if(s[i]=='{'){
				stack_push(sstack,s[i]);//push the element into stack
			}
			if(s[i]=='}'){ 
				if(stack_is_empty(sstack)){
					return count;
				}
				int j=matching(stack_pop(sstack),s[i]);
				if(!j){
					return 0;
				}
			}
			i++;
		}
		if(stack_is_empty(sstack)){//checking whether the stack is empty
			return count;
		}
		else{
			return count+(stack_size(sstack))/2;//when all the matchings are over
		}
	}
}

int matching(char c1,char c2){//checking the corresponding bracket for a open bracket if available
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
		
			
	
