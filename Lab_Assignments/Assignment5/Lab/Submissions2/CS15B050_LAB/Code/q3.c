#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#include"List.h"
#define size 10000

void next_larger(stack* stk1,stack* stk2,stack* stk3,int n,int arr[])             //Computes and prints the next larger element
{
    int i;                                                                        //Counter variable
    stack_push(stk1,0);
    for(i=1;i<n;i++)
    {
        while(!stack_is_empty(stk1) && arr[i] > arr[stk1->top->head->data])       //loop till stack is not empty or given condition in loop fails
        {
            stack_push(stk2,stack_pop(stk1));                                     //pop the element in stk1 and push it in stk2
            stack_push(stk3,arr[i]);                                              //push the greater element in stk3 each time
        }
        stack_push(stk1,i);                                                       //Now push the index of the greater element (i) 
    }
    while(!stack_is_empty(stk1))                                                   
    {
        stack_push(stk2,stack_pop(stk1));                                         //Push the remaining elements' indices in stk2
        stack_push(stk3,-1);                                                      //-1 corresponds to element's index in stk2
    }
    for(i=0;i<n;i++) arr[stack_pop(stk2)]=stack_pop(stk3);                        //Storing stk3's values into its corresponding indices
    for(i=0;i<n;i++) printf("%d ",arr[i]);                                        //Printing the array
    printf("\n");
}    

int main()
{
    int t;
    scanf("%d",&t);                                                               //No. of testcases
    int i;
    int j;
    for(i=0;i<t;i++)
    {
        stack* stk1;                                                              //stack1 stores Traversing index
        stack* stk2;                                                              //stack2 stores popped out index
        stack* stk3;                                                              //stack 3 stores the corresponding greater elements; values of indices in stack2
        stk3=stack_new();
        stk1=stack_new();
        stk2=stack_new();
        int n;
        int j;
        scanf("%d",&n);
        int arr[n];
        for(j=0;j<n;j++) scanf("%d",&arr[j]);
        next_larger(stk1,stk2,stk3,n,arr);                                        //Function call
    }
    return 0;
}
