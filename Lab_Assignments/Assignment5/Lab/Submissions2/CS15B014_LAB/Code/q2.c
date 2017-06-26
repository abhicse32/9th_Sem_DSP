/*D TEJA VARDHAN REDDY CS15B014 16/9/16*/
/*to PRINT minimum reversals required to make S balanced. If it cannot be balanced, then print -1.*/
#include<stdio.h>
#include"stack.h"
int main(){
	int t;
	scanf("%d",&t);
	char ch=getchar();
	while(t--){
		int count=0;
		stack*s=stack_new();
		ch=getchar();
		while(ch!='\n'){
			if(ch=='{')
				stack_push(s,ch);			//IF IT IS OPENING THEN PUSH IT ON TO STACK
			else{
				if(stack_is_empty(s)){		//IF IT IS CLOSED AND STACK IS EMPTY THEN REVERSE IT 
					stack_push(s,ch);
					count++;				
				}
				else{
					stack_pop(s);
				}
			}
			ch=getchar();
		}
		while(!stack_is_empty(s)){			// IF IT IS OPEN AND THEN ADD ONE TO COUNT AND POP TWICE ,IF NOT POSSIBLE THEN RETURN -1
			stack_pop(s);
			count++;
			if(stack_is_empty(s)){
				count=-1;
				break;
			}
			stack_pop(s);
		}
		printf("%d\n",count);
		
	}
}
