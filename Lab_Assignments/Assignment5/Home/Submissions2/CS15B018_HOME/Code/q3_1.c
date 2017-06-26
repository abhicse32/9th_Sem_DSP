//converting an infix epression to a postfix expression
#include<stdio.h>
#include <ctype.h>
#include"List.h"
#include"stack.h"
 
int check(char x)
{									//priority bool function
    	if(x == '(')					return 0;
    	else if(x == '|')				return 1;
    	else if(x == '^')				return 2;
    	else if(x == '&')				return 3;
    	else if(x == '+' || x == '-')			return 4;
    	else if(x == '*' || x == '/' || x == '%')	return 5;
    	else 						return 6;
}
 
int main()
{

	int j;
	for(j = 0; j < 10; j++)						//give the test cases
	{
        	char exp[1000], x;
        
        	int i = 0;
        	while(1)
        	{
        		char temp = getchar();				//scanning each character into exp
        		if(temp == '\n') break;
        		exp[i] = temp;
        		i++;
		}
		exp[i] = '\0'; 
	 
        	stack* st  = stack_new();				//st is operand stack
        	
        	stack* st2 = stack_new();				//st2 is variable stack
        	
        	i = 0;
        	while(exp[i] != '\0')
        	{
        		if(exp[i] == ')')
                	{	
                        	while((x = stack_pop(st)) != '(')	//pop all the elements till '(' when ')' is used
                		printf("%c ", x);
                	}	
                	else if(check(exp[i]) == 6)	
                	{						//pushing elements into variable stack
                		if(stack_is_empty(st2))	
                		{
                			printf("%c", exp[i]);
                			stack_push(st2, exp[i]);
                		}
                		else if(exp[i] == ' ' && st2 -> top -> head -> data == ' ');	
                		else
                		{	
                			printf("%c", exp[i]);
                			stack_push(st2, exp[i]);
                		}
                	}
                	else if(stack_is_empty(st))	stack_push(st, exp[i]);
                	else if(exp[i] == '(')		stack_push(st, exp[i]);
        		else
        		{
        			//checking priority and pushing or popping respectively
            			while(check(st -> top -> head -> data) >= check(exp[i]))
            			{
                			printf("%c ",stack_pop(st));
                			if(stack_is_empty(st) || (st -> top -> head -> data=='(')) break;
                		}
            			stack_push(st, exp[i]);
        		}
        		fflush(stdout);
                	i++;
        	}
    		while(!stack_is_empty(st))
    		{
    			if(st -> top -> head -> data == '(') stack_pop(st);	//popping the remaining elements
    			if(st2 -> top -> head -> data == ' ')
    			{
    				char k = stack_pop(st);
    				stack_push(st2, k);
        			printf("%c", k);
        		}
        		else	printf(" %c",stack_pop(st));
    		}
    		printf("\n");	
	}
}
