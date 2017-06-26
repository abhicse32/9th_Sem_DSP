#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "List.h"
 int check(char *s)
  {  int i,ctr=0;
     char x;
     stack *brac;
     brac= stack_new();

     for(i=0;s[i]!='\0';i++)
     { 

       if( s[i]=='{' )
         stack_push(brac,s[i]);
       else
        {   if(stack_is_empty(brac)==1)
             { s[i]='{';
               ctr++;
               stack_push(brac,s[i]);
               continue;
             }
            x=stack_pop(brac);
        }

     }
    while(1)
    { if(stack_is_empty(brac))
       return ctr;
      x=stack_pop(brac);
      if(stack_is_empty(brac))
       return -1;
      x=stack_pop(brac);
      ctr++;
    }

    return -1;
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
    
