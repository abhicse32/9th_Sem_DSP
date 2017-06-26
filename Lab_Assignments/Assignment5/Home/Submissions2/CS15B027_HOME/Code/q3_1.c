#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isOperand(char x)
{
 
	if(x=='+' || x=='-' || x=='/' || x=='*' || x=='%' || x=='&' || x=='|' || x=='^' || x=='(' || x==')')
	return 1;
	else
	return 0;
}

int prec(char x)
{
	switch(x)
	{
	case '^':
	return 1;		

	case '&':
    return 2;

	case '+':
	case '-':
    return 3;

    case '*':
	case '/':
	case '%':
	return 4;

	case '|':
	return 0;

	case '(':
	return -1;	          		  		  
	}
}
int main()
{
  int k;
  for(k=0;k<10;k++)
  {
	char* str;
	int i;
	str=(char*)malloc(sizeof(char)*1000);
	stack* p;
	p = stack_new();
	scanf(" %[^\n]s",str);
	i=0;
    int l = strlen(str);
	while(i<l)
	{	
        char x = str[i];
	    if(isOperand(str[i]) == 1)
		{
		  int t=1;
		  char ch;
		  if (str[i] == '(')
		  stack_push(p,str[i]);
		  else
		  {
			 if (str[i] == ')')
			 {
	    		ch=stack_pop(p);				
				while(ch != '(')
				{
				printf("%c ",ch);    
                ch=stack_pop(p);
			    } 
		     }
			 else
			 {
               if (stack_is_empty(p))
               stack_push(p,str[i]);
			   else
               {
                  ch=stack_pop(p);
				  while(prec(ch) >= prec(str[i]))
				  {
				 	printf("%c ",ch);
					if(	stack_is_empty(p))
		 			{
                      t=0;
	 				  break;
                    }	
 				    ch=stack_pop(p);					
				  }
                    if(t != 0)
	                stack_push(p,ch);
					stack_push(p,str[i]);
			   } 
		      }
			        i++;
			}			
     	}
		else
		{
			while(x != ' ')
			{
				printf("%c",x);
				i++;
				if(str[i] == '\0')
				break;
				x = str[i];
			}	
			printf(" ");
	
		}
		if(str[i]!='\0')
		{
		  i++;
		  x = str[i];
		  if(x==' ')
		  {
		    i++;
		  }		
		}
	}
   while(!stack_is_empty(p))
   {
	  char ch;
	  ch= stack_pop(p);
      printf("%c ",ch);
   }
       printf("\n");
 }
   return 0;
}
