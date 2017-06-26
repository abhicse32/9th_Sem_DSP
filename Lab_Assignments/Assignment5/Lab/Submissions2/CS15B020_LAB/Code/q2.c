#include "stack.h"
#include "List.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	
int rcheck(stack* stk)
	{
		int i;
		i=0;		
		char c,d;
		while(1)				
		{
		c=getchar();						/*Taking input usinf getchar()*/
		switch(c)
		{
		case '\n':
					if(stack_is_empty(stk)!=1)
					{
						if(stack_size(stk)%2==0) {i=i+(stack_size(stk)/2);return i;}	/*Returning the no. of changes to be made based pn the no. of open brackets left*/
						else return -1;
					}
					else return i;
					
		case '{':
					stack_push(stk,(int)c);
					break;							/*Takinga ll open brackets into the stack*/
		case '}':
					
					if(stack_is_empty(stk)) {stack_push(stk,(int)'{');
					i=i+1;}							/*Pairing all the close brackets we come across with corresponding open brackets*/
					else  {stack_pop(stk); break;}
		
		
	}
	}
}





int main()
	{
		char c;
		int i,j;
		int test;
		scanf("%d",&test);						/*Taking the input for no. of test cases*/
		getchar();							/*Omitting the extra '\n' character*/
		for(i=0;i<test;i++)		
		{
			stack *stk;
			stk=stack_new();					/*Initialising stack*/
			printf("%d\n",rcheck(stk));				/*Calling the function*/
					
		}
	}
