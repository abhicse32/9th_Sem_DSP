/*
*Written Teratipally Srikar,CS15B037
*On September 16th 2016
*This program takes an iput of string from screen
*and returns the array consisting of the 
*number greater than that which comes first after that
*/
#include<stdio.h>   /*Including the required header files*/
#include<stdlib.h>
#include"stack.h"

void evaluate(int *arr, int n); 

int stack_peeep(stack* stk)
{
    return llist_get(stk->top,0);
}

int main()
{
    int t;  /*No. of testcases*/
    scanf("%d",&t);
    
    int j;  /*Counter*/
    for(j=0;j<t;j++)
    {   
        int n;  /*No.of elements in the array*/
        scanf("%d",&n);

        int arr[n]; /*Array for storing the elements*/
        int i;  /*Counter*/
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        evaluate(arr,n);
    }
}

void evaluate(int arr[], int n) /*This function takes input as an array and returns an array which has elements greater than each element*/
{
    stack *stk1 = stack_new();  /*Delcaring a stack that stores value*/
    stack *stk2 = stack_new();  /*Delcaring a stack that stores the index*/
    int result[n];  /*Array for storing the result*/
    int i;  /*Counter*/

    for(i=0;i<n;i++)
    {
        result[i] = -1;
        
        if(stack_size(stk1)==0) {       /*If there are no elements then we can directly add*/
                                    stack_push(stk1,arr[i]);
                                    stack_push(stk2,i);
                                }

        else if( stack_peeep(stk1) >= arr[i]) {  /*If the element is lesser than the stackelement then we have to add into it*/
                                                stack_push(stk1,arr[i]);
                                                stack_push(stk2,i);
                                            }
        else    {
                    do  {
                            int temp = stack_pop(stk1); /*Temporaray element*/
                            result[stack_pop(stk2)] = arr[i];
                        }   while((stack_peeep(stk1)<arr[i])&&(stack_size(stk1)!=0));

                    stack_push(stk1,arr[i]);    /*Pushing the element*/
                    stack_push(stk2,i);         /*Pushing the index*/
                }
    }
    
    for(i=0;i<n;i++)    /*This loop prints the result on the screen*/
    {
        printf("%d ",result[i]);
    }
    printf("\n");   /*Printing a new line*/
}
