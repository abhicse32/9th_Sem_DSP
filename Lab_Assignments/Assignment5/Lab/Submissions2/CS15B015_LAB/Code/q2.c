/*      Program to find the minimum number of reversals needed to convert an invalid expression to a valid one
            G.Pranav    CS15B015    16-9-2016   */

#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "List.h"
int main(){
    int t;
    scanf("%d",&t);     //inputting the number of test cases
    while(t--){
        char arr[1001];
        scanf("%s",arr);        //inputting the array
        int i;
        stack *stackptr=stack_new();        //creating a new stack
        for(i=0;arr[i]!='\0';i++){
            if(arr[i]=='{'){
                stack_push(stackptr,arr[i]);        //pushing the opening braces into the stack
            }
            else{
                if(stack_is_empty(stackptr)){       //pushing the closing brace when the stack is empty
                    stack_push(stackptr,arr[i]);
                }
                else{
                    int temp=stack_pop(stackptr);       //popping the opening brace if it is the topmost element
                    if(temp=='}') 
                    {
                        stack_push(stackptr,arr[i]);
                        stack_push(stackptr,arr[i]);
                    }
                }
            }
         }
         int size1=stack_size(stackptr);        //finding the number of residual braces in the stack
         int size2=0;
         if(!stack_is_empty(stackptr)){
             int temp=stack_pop(stackptr);
             while(temp=='{'){              //storing the number of opening braces at the end of the stack in size2
                size2++;
                temp=stack_pop(stackptr);
             }
          }
          int num=size1-size2;              //storing the number of closing elements at the beginning of the stack in num
          if(size1%2==1) printf("-1\n");    //printing -1 for odd number of braces
          else{
            if(size2%2==1) printf("%d\n",size1/2+1);
            else printf("%d\n",size1/2);
          }
    }
    return 0;
}
