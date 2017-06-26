#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include<string.h>
int main(){
	int t;
	char c;
	scanf("%d",&t);
	while(t--){
		char exp[1001];
		int i=0;
		int flag=0;
		int j=0;
		int k=0;
		scanf("%s",exp);
		stack* S = stack_new();
		switch(exp[0]){
			case ')':
			case '}':
			case ']':
				{
					//printf("a\n");
					printf("0\n");
					j=1;
					break;	
				}
		}		
		if(j==1) continue;
		stack_push(S,exp[0]);
		i++;
		while(i<strlen(exp)){
			switch(exp[i]){
				case '(':
				case '{': 
				case '[':
					{
						stack_push(S,exp[i]);
						i++;
						break;
					}
					
				case ')':
					 {
					 	c=stack_pop(S);
					 	if(c=='(') i++;
					 			
					 	else{
					 		//printf("b\n");
					 		printf("0\n");
					 	        flag=1;
					 	
					 	}
					 	break;	
					 }
					 
				
				case '}':
					 {
					 	c=stack_pop(S);
					 	if(c=='{') i++;
					 	else{
					 		//printf("c\n");
					 		printf("0\n");
					 		flag=1;
					 	}
					 	break;
					 }
					 
				case ']':
					 {
					 	c=stack_pop(S);
					 	if(c=='[') i++;
					 	else{
					 		//printf("d\n");
					 		printf("0\n");
					 		flag=1;
					 	}
					 	break;
					 }
					 
			
			}
			if(flag==1) 
				break;	
		}
		if(flag==1) continue;
		if(stack_is_empty(S)==1&&flag==0) printf("1\n");	
        
        	else{
    			if(stack_is_empty == 0)	printf("0\n");			    
        	}
	}

	
}
