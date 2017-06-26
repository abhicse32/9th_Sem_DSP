#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main()
{
	int l;   			//number of test cases
	scanf("%d",&l); 

	int j;             //counter for test cases
char x = getchar();
	for(j=0;j<l;j++)
	
		{
		  stack* S;
		   	char x;

	S = stack_new();
	
     x = getchar();
     
	while(x!='\n')
		
		{
		  stack_push(S, x);
		  x = getchar();
		}
		      
     if(stack_size(S)==1) {printf("0\n");}

     else{		
     stack* A;
     A = stack_new();
	char z, y;
	int i;
	int size = stack_size(S);

	while(stack_size(S) != 0)	
 	 {  
 	 
	     if(stack_size(A) == 0){z = stack_pop(S);	stack_push(A, z);}
         y = stack_pop(A);
	    z = stack_pop(S);
 
    	     if(y == '}' && z == '{') {continue;}
		else if(y == ']' && z == '[') {continue;}
		else if(y == ')' && z == '(') {continue;}
		else {stack_push(A, y); stack_push(A, z);}
		
	 }   

	if(stack_size(A) == 0) printf("1\n");
	else printf("0\n");}
		}
}


