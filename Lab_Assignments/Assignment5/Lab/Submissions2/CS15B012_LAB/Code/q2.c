#include "List.h"
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>

int count(stack* stk)
{
    int x;
    x=0;
    char temp;
    temp=stack_pop(stk);
   while(temp!='}')
   { 
    x++;
    temp=stack_pop(stk);
    }
    return x;
}

void check(stack *stk,char c)
{
    if(stack_is_empty(stk))
    {
    /* when the starting elements are there push it*/   
            stack_push(stk,c);
        
    }
    else
    {
        if(c=='{')
        {
            stack_push(stk,c);
          
        }    
        if(c=='}')
        {
            char temp;
            temp=stack_pop(stk);
            if(temp=='{')
            {
            }  
            else
            {
                stack_push(stk,temp);
                stack_push(stk,c);
            }
        }    
    }
    
}

int main()
{
    int t;
    /* t is number of test cases*/
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++)
    {
        char* s;
        s=(char*)malloc(1000*sizeof(char));
        /* to input the sting of brackets*/ 
        scanf("%s",s);
        int j;
        j=0;
        stack* stk;
        stk=stack_new();
        while(s[j]!='\0')
        {
            check(stk,s[j]);
            j++;
        }
        int size;
        size=stack_size(stk);
        if(stack_size(stk)%2==1)
        { free(s) ;
        printf("-1\n");
        }
        else
        { free(s);
      if(count(stk)%2==1)
        {printf("%d\n",size/2+1);
         }
        else
        {printf("%d\n",size/2);
          }
        }
    }
    return 0;
}
