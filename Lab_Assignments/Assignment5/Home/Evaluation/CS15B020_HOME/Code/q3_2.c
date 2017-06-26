#include "queue.h"
#include "stack.h"
#include "List.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void intopost()
	{
		stack* st;
		st=stack_new();
		int i,x,y;
		char c,ch;
        
		c=getchar();
		if(c==EOF) return ;

		while(c!='\n')
		{

if(c=='+')
                {
						stack_push(st,stack_pop(st)+stack_pop(st));
                }
else if(c=='-')
                {
						ch=getchar();
						if((ch==' ')||(ch=='\n'))
						{
							y=stack_pop(st);
							x=stack_pop(st);
							stack_push(st,x-y);
						}
						else
						{
							
							i=ch-48;
							ch=getchar();
							while(ch!=' ')
							{
								i=i*10+(ch-48);
								ch=getchar();
					
							}
							stack_push(st,-i);
						}
                }
else if(c=='*')
                {
						y=stack_pop(st);
						x=stack_pop(st);
						stack_push(st,x*y);
                }
else if(c=='/')
                {
						y=stack_pop(st);
						x=stack_pop(st);
						stack_push(st,x/y);
                }
else if(c=='^')
                {
						y=stack_pop(st);
						x=stack_pop(st);
						stack_push(st,x^y);
                }
else if(c=='&')
                {
						y=stack_pop(st);
						x=stack_pop(st);
						stack_push(st,x&y);
                }
else if(c=='|')
                {
						y=stack_pop(st);
						x=stack_pop(st);
						stack_push(st,x|y);
                }
else if(c=='%')
                {
						y=stack_pop(st);
						x=stack_pop(st);
						stack_push(st,x%y);
                }
else
        {
				if(c!=' ')
				{
				i=c-48;
				c=getchar();
				while(c!=' ')
				{
					i=i*10+(c-48);
					c=getchar();
					
				}
				stack_push(st,i);
				}
        }
            	c=getchar();
	  }
					
		
			
			
		
			stack_print(st);
			printf("\n");
		intopost();
	}



int main()
	{
        intopost();
		printf("\n");
        return 0;
	}
