#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#include"List.h"
int paranthesis_checker(stack* stk,char exp[])                                           
{
    int flag;                                                                           //Flag variable
    flag=1;
    int i;
    char x;
    for(i=0;exp[i]!='\0';i++)                                                           //Loops till end of string
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') stack_push(stk,(int)exp[i]);      //Push if exp[i]= '{' or '(' or '['
        else if(!stack_is_empty(stk))
        {
            if(exp[i]==')')
            {
                while(!stack_is_empty(stk) && (x=(char)stack_pop(stk))!='(')
                {
                    if(x=='{' || x=='[')                                                //If there is any other('{' or '[') opening bracket in between them
                    {
                        flag=0;
                        break;
                    }
                } 
            }
            else if(exp[i]=='}')
            {
                while(!stack_is_empty(stk) && (x=(char)stack_pop(stk))!='{')
                {
                    if(x=='(' || x=='[')                                                //If there is any other('(' or '[') opening bracket in between them
                    {
                        flag=0;
                        break;
                    }
                } 
            }
            else
            {
                while(!stack_is_empty(stk) && (x=(char)stack_pop(stk))!='[')
                {
                    if(x=='{' || x=='(')                                                //If there is any other('(' or '{') opening bracket in between them
                    {
                        flag=0;
                        break;
                    }
                } 
            }
        }
        else                                                                            //Stack is empty and closing bracket is added so break
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int main()
{
    int t;
    scanf("%d",&t);                                                                     //No. of test cases
    int i;
    for(i=0;i<t;i++)
    {
        stack* stk;
        stk=stack_new();
        char exp[1000];
        scanf("%s",exp);
        int ans;
        if(strlen(exp)%2==1) ans=0;
        else ans=paranthesis_checker(stk,exp);                                          //Function call
        printf("%d\n",ans);                                                             //Printing the answer
    }
    return 0;
}
