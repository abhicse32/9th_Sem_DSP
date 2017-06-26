#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include "queue.h"
#include "stack.h"
#include<string.h>



int prec(char c);

int stack_top(stack* stk);
void stacksort(stack* stk,int c);	
int main()
	{
    		char *string;
    		string = (char *)malloc(1000 * sizeof(char));
    		while(fgets(string,1000,stdin)!=NULL)            
    		{
        		stack *stk;
        		stk = stack_new();                              
        		int i = 0;
        		while(1)
        		{
				if(string[i] == '\0') break;
            			if((string[i]!=' ')&&(string[i]!='\n'))
            			{
                			
                			if(string[i] == '(')                 
                			{
                    				stack_push(stk,string[i]);
                    				i++;
                			}
                			else if(string[i] == ')')                 
                			{
                   	 			while((stack_top(stk)!= '(')&&(!stack_is_empty(stk)))
                        			printf("%c ",stack_pop(stk));
                    				stack_pop(stk);
                    				i++;
                			}
					else if(prec(string[i])==6)           
                			{
                    				while(string[i] != ' ')             
                    				{
                        				if(string[i] == '\n') break;  
	              	 				printf("%c",string[i]);
							i=i+1;
                    				}
                    				printf(" ");
                			}
                			else                                  
                			{
                    				if(stack_is_empty(stk)==1) stack_push(stk,string[i]);
                    				else
                    				{
							stacksort(stk,string[i]);	
                    				}
						
                    				i++;
                			}
            			}
            			else                                      
            			{
                			i++;
            			}
        		}
        		while(!stack_is_empty(stk))                     
           	 	printf("%c ",stack_pop(stk));
        		printf("\n");
    		}
	}
void stacksort(stack* stk,int c)
	{
		if(stack_is_empty(stk)) { stack_push(stk,c); return;}
		else
		{
		int x;
		x=stack_pop(stk);
		if(prec(x)<prec(c)) {stack_push(stk,x); stack_push(stk,c); return;}
		else{
			if(x!='(') printf("%c ",x);
			stacksort(stk,c);
			
		    }
		}
	}
int stack_top(stack* stk)
	{
		return ((stk->top)->head)->data;
	}	
int prec(char c)
	{
		switch(c)
		{
		case '*':						
		case '/':
		case '%':
				return 5;	
		case '+':
		case '-':
				return 4;
		case '^':
				return 2;
		case '&':
				return 3;
		case '|':
				return 1;
		case '(':
		case ')':
				return -1;
		default : 
				return 6;
		}
	}
