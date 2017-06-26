#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isOperand(char x)
{
 
	if(x=='+' || x=='-' || x=='/' || x=='*' || x=='%' || x=='&' || x=='|' || x=='^')
	return 1;
	else
	return 0;
}
int main()
{
  int k;
  for(k=0;k<10;k++)
  {
	char* str;
	int i;
	str=(char*)malloc(sizeof(char)*1000);
	stack* p= stack_new();
	scanf(" %[^\n]s",str);
	i=0;
    stack_push(p,0);
	while(str[i] != '\0')
	{	
        if(isOperand(str[i]) == 1  && (str[i+1] ==' ' ))
        {
          long int x = (long int)stack_pop(p);
          long int y = (long int)stack_pop(p);
          if(str[i] == '+')
          stack_push(p,x+y);
          if(str[i] == '-')
          stack_push(p,y-x);
          if(str[i] == '*')
          stack_push(p,x*y);
          if(str[i] == '/')
          stack_push(p,y/x);
          if(str[i] == '&')
          stack_push(p,x&y);
          if(str[i] == '|')
          stack_push(p,x|y);
          if(str[i] == '%')
          stack_push(p,y%x);
          if(str[i] == '^')
          stack_push(p,x^y);
          i++;	
            if(isOperand(str[i+1]) == 0 )
			{            
			stack_push(p,0);}
        }
       else if(isOperand(str[i]) == 1  && (str[i+1] =='\0' ))
        {
          long int x = (long int)stack_pop(p);
          long int y = (long int)stack_pop(p);
          if(str[i] == '+')
          stack_push(p,x+y);
          if(str[i] == '-')
          stack_push(p,y-x);
          if(str[i] == '*')
          stack_push(p,x*y);
          if(str[i] == '/')
          stack_push(p,y/x);
          if(str[i] == '&')
          stack_push(p,x&y);
          if(str[i] == '|')
          stack_push(p,x|y);
          if(str[i] == '%')
          stack_push(p,y%x);
          if(str[i] == '^')
          stack_push(p,x^y);
      			
        }
	    else if(isOperand(str[i]) == 0 && str[i+1] == ' ')
		{
            long int x = (10*stack_pop(p)) + (int)str[i]-48;
            stack_push(p,x);
            i++;
            if(isOperand(str[i+1]) == 0)
            stack_push(p,0);
      }
	    else if(isOperand(str[i]) == 0 && str[i+1] != ' ')
		{
            long int x = (10*stack_pop(p)) + (int)(str[i])-48;
            stack_push(p,x);
        }
        else if(str[i]=='-' && str[i+1] != ' ')
        {
           if(str[i+1] != '\0')
           {
              stack_push(p,0);
               i++;
              while(str[i] != ' ')
              {
              
                 long int x = (10*stack_pop(p)) + (int)str[i]-48;
                 stack_push(p,x);
                 i++;
              }
              long int x= stack_pop(p);
              stack_push(p,-x);
             stack_push(p,0);
            }
        }
        if(str[i] != '\0')
       i++;//stack_print(p);printf("\n");
     }
     printf("%ld\n",(long int)stack_pop(p));fflush(stdout);
   }
   return 0;
}
