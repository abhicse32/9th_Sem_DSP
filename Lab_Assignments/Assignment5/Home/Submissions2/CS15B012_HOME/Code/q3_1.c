#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>


int pre(char x)
{
	int a;
	switch(x)
	{

		case '&': a=2;
				  break;
		case '*':
		case '/':
		case '%': a=4;
				  break;
		case '+':
		case '-': a=3;
				  break;
		case '^': a=1;
				  break;		
		case '|': a=0;
				  break;
		case '(': a=-1;
				  break;
		
		          		  		  
	}
	return a;
}

int oprend(char x)
{
	/* these are the list of operends used in the program*/


	if(x=='+'||x=='-'||x=='/'||x=='*'||x=='%'||x=='&'||x=='|'||x=='^'||x=='('||x==')')
	return 1;
	else
	return 0;	
	
	
}



int main()
{
int l;
for(l=0;l<10;l++)
{
	char* str;
	int i;
	str=(char*)malloc(sizeof(char)*1000);
	stack* stk;
	stk=stack_new();
	/* storing the expression in the str*/
	scanf(" %[^\n]s",str);
	i=0;
	
	
	while(str[i]!='\0')
	{
	  /* here if we take care of end conditions*/
		char x;
		x=str[i];
	
		if(oprend(x))
		{
		/*checking oprend is ti oprend or not*/
		/* here is start of program if not*/ 
			int b=1;
			char y;
				if (x=='(')
				   {	
					stack_push(stk,x);
				   }
				 /* this when x=)*/
				else 
				
				{
					 if (x==')')
			    	{
			    		y=stack_pop(stk);				
						while(y!='(')
						{

						printf("%c ",y);
						y=stack_pop(stk);
						} 
					}
				else
				 {/* inserting operaters*/
				 if (stack_is_empty(stk))
				 {
				 stack_push(stk,x);
				 }
				 else{y=stack_pop(stk);
					while(pre(y)>=pre(x))
					{
						printf("%c ",y);
						if(	stack_is_empty(stk))
						{b=0;
						break;}	
						y=stack_pop(stk);					
					}
					if(b!=0)
	                {stack_push(stk,y);}
					stack_push(stk,x);
					
				 }
				 
				 }
			i++;
			}			

		}

			/* for non oprend */
			 
		else
		{	
			while(x!=' ')// Here we are taking each character at a time so we have a loop to take all digits
			{
				printf("%c",x);
				i++;
				if(str[i]=='\0')
				break;
				x=str[i];
			}	
			printf(" ");
	
		}
		/* this is to increment if it passes from the loops and there is space*/
		if(str[i]!=0)
		{
		i++;
		x=str[i];
		if(x==' ')
		{
		i++;
		x=str[i];
		}		
		}
	}/*end of string*/

while(!stack_is_empty(stk))
{
	char t;
	t= stack_pop(stk);
	
	printf("%c ",t);
}
printf("\n");
free(str);
}
return 0;

}

