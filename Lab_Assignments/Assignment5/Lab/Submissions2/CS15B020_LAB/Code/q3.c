#include "stack.h"
#include "List.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stkfunc(stack* stk,int m)
	{
		static int l;
		int x;
		x=stack_pop(stk);
		if(x==-1) {stack_push(stk,x);l=-1; return l;}			/*Function to find the element in stk that is greater than m*/
		else{
		if(m<x) {stack_push(stk,x);l=x;return l;}			/*Returning -1 if no such elemnt exists*/
		else { stkfunc(stk,m); stack_push(stk,x);}
		return l;
		    }
	}



int func(stack* stk1,stack* stk2)
	{
		
		int x,y,z;
		x=stack_pop(stk1);
		y=stack_pop(stk2);
		z=stack_pop(stk1);
		
		if(stack_is_empty(stk1))					/*If condition when we reach end of the stack*/
		{	stack_push(stk2,y);
			
			if(y==-1)
			{
				if(z>x)
				{
				stack_push(stk2,-1);				/*Adding the corresponding values in stk2 based on the values in stk1*/
				}
				else stack_push(stk2,x);
				
			}
			else
			{
				
				
				if(z<x) stack_push(stk2,x);
				else if(z<y) stack_push(stk2,y);
				else 
				{
				int i;
				i=stkfunc(stk2,z);
				stack_push(stk2,i);
				}				
			}
			return 1;
			
		}
		else						/*If condition when we dont reach end of the stack*/
		{
			stack_push(stk2,y);
			stack_push(stk1,z);
			if(y==-1)
				{
					
					if(z>x)
					{
						stack_push(stk2,-1);
					}
					else stack_push(stk2,x);		/*Adding the corresponding values in stk2 based on the values in stk1*/
				}
			else
				{
					if(z<x) stack_push(stk2,x);
					else if(z<y) stack_push(stk2,y);
					else stack_push(stk2,stkfunc(stk2,z));
				}
			func(stk1,stk2);
		}	
	}




int main()
	{
		char c;

		int i,j,z,x,y;
		int test;
		scanf("%d",&test);				/*Taking input for test*/
		getchar();
		for(i=0;i<test;i++)
		{
			stack *stk1,*stk2;
			stk1=stack_new();
			stk2=stack_new();			/*Initialising new stacks*/
			int size;
			scanf("%d",&size);
			for(j=0;j<size;j++)
			{
				scanf("%d",&z);
				stack_push(stk1,z);		/*Taking the input in one of the stacks and using the other stack to store output*/
			}
			stack_push(stk2,-1);							
			func(stk1,stk2);					
			stack_print(stk2);			/*Printing the output stack*/
			 printf("\n");
		}	
	}	
		
