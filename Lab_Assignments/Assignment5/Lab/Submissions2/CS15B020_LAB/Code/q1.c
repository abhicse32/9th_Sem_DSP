#include "stack.h"
#include "List.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pcheck(stack* stk)
	{
		static int i;
		char c,d;
		c=getchar();						/*Taking input through stack recursively*/
		switch(c)
		{
		case '\n':
					if(stack_is_empty(stk)) return 1;	/*Returning appropriate values when we reach end of the the line*/
					else return 0;
		case '{':
		case '[':
		case '(':
					stack_push(stk,(int)c);			/*Taking all Open paranthesis into the stack*/
					break;
		case ')':	
					d=(char)stack_pop(stk);
					stack_push(stk,(int)d);
					if(stack_is_empty(stk)) {stack_push(stk,(int)c);}				/*For every close paranthesis we get,pairing them with appropriate open brackets*/
					else if((char)stack_pop(stk)!='(') {stack_push(stk,(int)d);stack_push(stk,(int)c);}		/*And removing that pair from the stack*/
					else break;
		case ']':
					d=(char)stack_pop(stk);
					stack_push(stk,(int)d);
					if(stack_is_empty(stk)) {stack_push(stk,(int)c);}
					else if((char)stack_pop(stk)!='[') {stack_push(stk,(int)d);stack_push(stk,(int)c);}
					else break;
		case '}':
					d=(char)stack_pop(stk);
					stack_push(stk,(int)d);
					if(stack_is_empty(stk)) {stack_push(stk,(int)c);}
					else if((char)stack_pop(stk)!='{') {stack_push(stk,(int)d);stack_push(stk,(int)c);}
					else break;
		}
		return pcheck(stk);					/*Calling the function recursively*/
					
	}
								

int main()
	{
		char c;
		int i,j;
		int test;
		scanf("%d",&test);					/*Taking the input for no. of test cases*/
		getchar();						/*Omitting the extra '\n' character*/
		for(i=0;i<test;i++)
		{
			stack *stk;
			stk=stack_new();				/*Initialising stack*/
			printf("%d\n",pcheck(stk));
			
		}
	}
	
