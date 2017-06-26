#include "queue.h"
#include "stack.h"
#include "List.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int postfixeval()
	{
		stack* stk;
		stk=stack_new();
		int i,x,y;
		char c,d,e;
		c=getchar();
		if(c==EOF) return 1;
		while(c!='\n')
		{
		switch(c)
		{
		case '+':	
		case '-':
		case '*':
		case '/':
		case '^':
		case '&':
		case '|':
		case '%':
				
				switch(c)
				{
				case '+':
						y=stack_pop(stk);
						x=stack_pop(stk);
						stack_push(stk,x+y);
						break;	
				case '-':	
						e=getchar();
						if((e==' ')||(e=='\n'))
						{
							y=stack_pop(stk);
							x=stack_pop(stk);
							stack_push(stk,x-y);
							break;
						}
						else
						{
							
							i=e-48;
							e=getchar();
							while(e!=' ')
							{
								i=i*10+(e-48);
								e=getchar();
					
							}
							stack_push(stk,-i);
							break;
						}
				case '*':
						y=stack_pop(stk);
						x=stack_pop(stk);
						stack_push(stk,x*y);
						break;
				case '/':
						y=stack_pop(stk);
						x=stack_pop(stk);
						stack_push(stk,x/y);
						break;
				case '^':
						y=stack_pop(stk);
						x=stack_pop(stk);
						stack_push(stk,x^y);
						break;
				case '&':
						y=stack_pop(stk);
						x=stack_pop(stk);
						stack_push(stk,x&y);
						break;
				case '|':
						y=stack_pop(stk);
						x=stack_pop(stk);
						stack_push(stk,x|y);
						break;
				case '%':
						y=stack_pop(stk);
						x=stack_pop(stk);
						stack_push(stk,x%y);
						break;				
				}
				break;
		default :
				if(c!=' ')
				{
				i=c-48;
				c=getchar();
				while(c!=' ')
				{
					i=i*10+(c-48);
					c=getchar();
					
				}
				stack_push(stk,i);
				break;
				}
				else break;
		}
			c=getchar();			
		
			
			
		}
			stack_print(stk);
			printf("\n");
		postfixeval();
	}



int main()
	{
        postfixeval();
		printf("\n");		
	}
