/*D TEJA VARDHAN REDDY CS15B014 16/9/16*/
/* the next greater element for each array element separated by space
in order*/
#include<stdio.h>
#include"stack.h"
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		stack*s=stack_new();			//TO STORE DATA
		stack*s1=stack_new();				// to store indices
		int n,i;
		scanf("%d",&n);
		int a[10003],c[10003];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			
			c[i]=-1;
		}
		for(i=0;i<n;i++){
			int ind,data,check=0;
			if(stack_is_empty(s)){			//if stack is empty  push element into the stack 
				stack_push(s,a[i]);
				stack_push(s1,i);
			}	
			else{
				while(!stack_is_empty(s)){		//check with top if top<a[i]  then c[ind]=a[i]
					 data=stack_pop(s);
					 ind=stack_pop(s1);
					if(data<a[i]){
						c[ind]=a[i];
						//printf("%d  %d   ",ind,a[i]);
						
					}
					else{
						check=1;
						break;
						
					}
				}
				if(check==0){
					stack_push(s,a[i]);
					stack_push(s1,i);
				}
				else{
					stack_push(s,data);
					stack_push(s1,ind);
					stack_push(s1,i);
					stack_push(s,a[i]);
				}
				
				
			}
		}
		for(i=0;i<n;i++)				//printing reqd output
			printf("%d ",c[i]);
		printf("\n");
	}
}
