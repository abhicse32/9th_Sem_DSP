/*
*Written Teratipally Srikar,CS15B037
*On September 16th 2016
*This program takes an iput of string from screen
*and returns the minimum of reversals to be done
*so that the brackets are in correct order
*/

#include<stdio.h>   /*Including the required header files*/
#include<string.h>
#include"stack.h"
#include<stdlib.h>

int main()
{   
    int i;      /*Counter*/
    int n;      /*Number of testcases*/
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        char array[1000];   /*Decalring the string*/
        scanf("%s",array);
        int length = strlen(array); /*Length of the string*/
        int counter = checker(array,length,0);
        printf("%d\n",counter);
    }
}

int check(char x, char y)   /*This function checks if x and y forms a closed pair of brackets*/
{
    int result;
    if((x=='{') && (y=='}')) result = 1;
    else if((x=='(') &&( y==')')) result = 1;
    else if((x=='[' )&& (y==']')) result = 1;
    else result = 0;

    return result;
}

int checker(char arr[], int l,int count)    /*This function counts the minimum number of reversals*/
{
    if(l%2==1) return -1;   /*If there are odd number of elements then, they cannot form a correct pair*/
    char prev;
    int i;  /*Counter*/
    int flag;   /*Flag*/

    stack* stk = stack_new();   /*Intialising a stack*/

    for(i=0;i<l;i++)
    {
        if(stack_size(stk)==0)  {
                                    prev = arr[i];      /*If there are no elements then we have to directly add*/
                                    stack_push(stk,prev);
                                }

        else    {
                    int flag = check(prev,arr[i]);
                    if(flag == 0) {
                                    prev = arr[i];  /*If prev and arr[i] are not equal then we have to add into stack*/
                                    stack_push(stk,prev);
                                  }

                    else    {
                                prev = stack_pop(stk);  /*If they form a closed pair then we can remove it*/
                                if(stack_size(stk)!=0)  prev = stack_peep(stk);
                            }
                }
    }
    
    if(stack_is_empty(stk)) return count;   /*If the stack is empty then we can return count*/
    else {
            prev = stack_peep(stk);
            if(prev == '}') return (count+(stack_size(stk)/2)); /*If last element is } then count will be no.of elements/2*/
            else    {
                        prev = stack_pop(stk);
                        prev = '}';
                        count = count+1;        /*else reverse the last element and then again call it*/
                        stack_push(stk,prev);

                        int i;  /*Counter*/
                        l = stack_size(stk);    /*Length of the stack*/
                        for(i=l-1;i>=0;i--)
                        {
                            arr[i] = stack_pop(stk);
                        }
                        count = checker(arr,l,count);
                    }
        }
}

