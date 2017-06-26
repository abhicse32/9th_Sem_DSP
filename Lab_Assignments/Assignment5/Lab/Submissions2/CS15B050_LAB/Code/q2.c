#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#include"List.h"

int no_of_reversals(stack* stk,char exp[])                                  //Computes the no. of reversals and returns it
{
    int i;                                                                  //Counter variable
    char x;
    int count=0;                                                            //No. of reversals
    for(i=0;exp[i]!='\0';i++)                                               //Loop till end of string
    {
        if(exp[i]=='{') stack_push(stk,'{');                                //Push '{'
        else if(!stack_is_empty(stk)) 
        {
            while(!stack_is_empty(stk) && (x=(char)stack_pop(stk))!='{')    //Brackets are in proper order
            {
            //do nothing
            }
        }
        else
        {
            exp[i]='{';                                                     //Reversing '}'
            stack_push(stk,exp[i]);
            count++;                                                        //count++
        }
    }
    if(!stack_is_empty(stk))                                                //remaining brackets will all be same
    {
        count=count + ((stack_size(stk))/2);                                //As remaining brackets are same reverse half of them
    }
    return count;                                                           //Return answer
}

int main()
{
    int t;
    scanf("%d",&t);                                                         //No. of testcases
    int i;
    for(i=0;i<t;i++)
    {
        stack* stk;
        stk=stack_new();
        char exp[1000];
        scanf("%s",exp);
        int ans;
        if(strlen(exp)%2==1) ans=-1;                                        //If they are odd in number ans=-1
        else ans=no_of_reversals(stk,exp);                                  //Function call
        printf("%d\n",ans);   
    }
    return 0;
}
