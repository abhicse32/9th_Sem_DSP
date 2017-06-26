/*
*Written Teratipally Srikar,CS15B037
*On September 16th 2016
*This program takes an iput of string from screen
*checks if the brackets are in correct order or not
*/

#include<stdio.h>       /*Including the required header files*/
#include<string.h>
#include"stack.h"
#include<stdlib.h>

int main()
{
    int i;  /*Counter*/
    int n;  /*Number of test cases*/
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        char array[1000];   /*Intialisation of an array for storing the string*/
        scanf("%s",array);
        int length = strlen(array); /*Length of the array*/
        int result = checker(array,length);     /*Stores the result of the string*/
        printf("%d\n",result);
    }
}


int check(char x, char y)   /*This function checks whether x,y form a closed pair of brackets or not*/
{
    int result;
    if((x=='{') && (y=='}')) result = 1;
    else if((x=='(') &&( y==')')) result = 1;
    else if((x=='[' )&& (y==']')) result = 1;
    else result = 0;
    return result;
}

int checker(char arr[], int l)  /*This function checks whether the string contains valid order of brackets*/
{
    char prev;  /*This character stores the previous element in the stack*/
    int i;      /*Counter*/
    int flag;   /*flag*/

    stack* stk = stack_new();   /*Intialising a stack*/

    for(i=0;i<l;i++)
    {
        if(stack_size(stk)==0)  {   /*If there are no elements in the stack then we should add into it*/
                                    prev = arr[i];
                                    stack_push(stk,prev);
                                }

        else    {
                    int flag = check(prev,arr[i]);
                    if(flag == 0) {                 /*If prev is not equal to arr[i[ then we should add*/
                                    prev = arr[i];
                                    stack_push(stk,prev);
                                  }

                    else    {
                                prev = stack_pop(stk);  /*If they form a closed pair then we can remove them*/
                                if(stack_size(stk)!=0)  prev = stack_peep(stk);
                            }
                }
    }
        if(stack_size(stk)==0) return 1;    /*If the stack is empty then the order is correct*/
        else return 0;
}
