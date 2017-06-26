/*      Program to check whether the given expression in paranthesis is valid or not
            G.Pranav    CS15B015    16-9-2016   */

#include<stdio.h>
#include "stack.h"
#include "List.h"
int main(){
    int t;
    scanf("%d",&t);     //inputting the number of test cases
    while(t--){
        int ans=0; 
        char exp[1001];     
        scanf("%s",exp);
        int i;
        stack *stackptr=stack_new();        //creating a stack data structure to store the ASCII values of required characters
        for(i=0;exp[i]!='\0';i++){
            if((exp[i]=='(')||(exp[i]=='[')||(exp[i]=='{')){
                stack_push(stackptr,exp[i]);        //pushing opening braces into stack
            }
            else{
                if(stack_is_empty(stackptr)){   //checking whether the stack is empty or not
                    ans=1;
                    break;
                }
                int temp=stack_pop(stackptr);
                if(!(((temp=='(')&&(exp[i]==')'))||((temp=='[')&&(exp[i]==']'))||((temp=='{')&&(exp[i]=='}')))) 
                {               //popping the opening brace corresponding to the given closing brace
                    ans=1;
                    break;
                }
            }
        }
        if(ans==1) printf("0\n");
        else{
            if(stack_is_empty(stackptr)) printf("1\n");
            else printf("0\n");             //checking whether the residual elements are present or not
        }
    }
    return 0;
}
