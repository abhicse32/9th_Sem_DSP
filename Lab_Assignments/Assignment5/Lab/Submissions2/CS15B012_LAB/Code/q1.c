#include "List.h"
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>

int check(stack *stk,char c)
{
    if(stack_is_empty(stk))
    {
    /* when the starting elements are closing brackets the that is not possible*/
        if(c==']'||c=='}'||c==')')
        return 0;
        else
        {
            stack_push(stk,c);
            return 1;
        }
    }
    else
    {
        if(c=='['||c=='{'||c=='(')
        {
            stack_push(stk,c);
            return 1;
        }    
        if(c==']'||c=='}'||c==')')
        {
            char temp;
            temp=stack_pop(stk);
            if(c==']'&&temp=='[')
            return 1;
            else if(c==')'&&temp=='(')
            return 1;            
            else if(c=='}'&&temp=='{')
            return 1;    
            else
            return 0;  
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
        int con;
        con=1;
        while(s[j]!='\0'&&con==1)
        {
            con=check(stk,s[j]);
            j++;
        }
        if(con==1&&stack_is_empty(stk))
        { free(s) ;
        printf("1\n");
        }
        else
        { free(s);
        printf("0\n");}
    }
    return 0;
}

