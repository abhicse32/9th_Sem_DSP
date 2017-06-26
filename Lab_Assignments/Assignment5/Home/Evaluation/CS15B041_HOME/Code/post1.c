#include<stdio.h>
#include"List.h"
#include"stack.h"

int order(char);


int order(char x)
{
   if(x == '(')
 return(0);
   if(x == '+' || x == '-')
 return(1);
   if(x == '*' || x == '/' || x == '%')
 return(2);
    if(x=='(')
 return(3);
}


void main()
{
stack* s;
//stack* s1;
//stack* s2;
char x;
int i;
i=0;
char exp[1000];
s=stack_new();
//s1=stack_new();
//s2=stack_new();
	scanf("%s",&exp[1000]);



	while(exp[i] !='\0')
	  {
		   if(exp[i] != '+' || exp[i] != '/' || exp[i] != '*' || exp[i] != '-' || exp[i] != '('|| exp[i] != ')')
       			{
				printf("%c",exp[i]);
			}
		   else
		     {  if(exp[i] == '(')
			   {
				stack_push(s,'(');
				i++;
			    }
		       else
		       {
			 if(exp[i] == ')')
			     while((x=stack_pop(s))!='(')
			     {
				printf("%c",x);
			     }
			 else
			 {
	while( !stack_is_empty(s))
			{ 	char v;
				v=stack_pop(s);
				while(order(exp[i])<order(v) ||  order(exp[i])==order(v) )
			     {
			     stack_push(s,v);	
			     x=stack_pop(s);
			     printf("%c",x);
			     }
			 stack_push(s,exp[i]);
			 }
		       }
		    }
		  }
		  while(!stack_is_empty(s))
		    {
		    x=stack_pop(s);
  		  printf("%c",x);
    
		    }
}
}


