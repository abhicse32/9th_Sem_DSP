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
		int count=0;
		scanf("%s",exp);
		if(strlen(exp)%2==1){
			printf("-1\n");
			continue;
		} 
		stack* S = stack_new();
		if(exp[0]=='}') count++;		
		stack_push(S,'{');
		i++;
		while(i<strlen(exp)){
			if(exp[i]=='{') stack_push(S,exp[i]);
			else if(exp[i]=='}'){
				if(stack_is_empty(S)){ 
					count++;
					stack_push(S,'{');
				}	
				else{
					stack_pop(S);
				}
			}
			i++;
		
		}
		int s=stack_size(S);
		printf("%d\n",count+s/2);
		
	}

	return 0;	
}
