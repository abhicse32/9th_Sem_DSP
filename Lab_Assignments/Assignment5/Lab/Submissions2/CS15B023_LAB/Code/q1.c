#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "List.h"
 int check(char *s)
  {  int i;
     char x;
     stack *brac;
     brac= stack_new();

     for(i=0;s[i]!='\0';i++)
     { 

       if(s[i]=='(' || s[i]=='[' || s[i]=='{' )
         stack_push(brac,s[i]);
       else
        {   if(stack_is_empty(brac)==1)
             return 0;

            x=stack_pop(brac);

            if(s[i]==')' && x=='(')
             continue;
            if(s[i]=='}' && x=='{')
             continue;
            if(s[i]==']' && x=='[')
             continue;
           
            return 0;
        }

     }
     if(stack_is_empty(brac))
      { return 1;
      }
    return 0;
  }

int main()
{ int test;
  scanf("%d",&test);

  for( ;test>0;test--)
  {  char s[1001];
     scanf("%s",s);
     printf("%d\n",check(s)); 
  }
 return 0;
}
    
