// Lab Assignment 5 Question 1
// Parentheses Checker
// Author : Milind Srivastava
// Date : 16 Sep 2016

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int k;
    scanf("%d", &k); // input number of testcases
    while(k > 0)
    {
        char stack[1000];
        char arr[1000];
        
        int count = -1; // top element of array stack
        
        scanf("%s", arr);
        
        int i = 0;
        int flag = 1;
        for(i = 0; i < strlen(arr); i++)
        {
            if(arr[i] == '(' || arr[i] == '{' || arr[i] == '[') // if left bracket, push it
            {
                count++;
                stack[count] = arr[i];
            }
            else
            {
                switch(arr[i])
                {
                    case ')':
                    if(count == -1) // empty stack
                    {
                        flag = 0;
                        printf("0\n");
                        goto end;
                    }
                    else
                    {
                        int temp = stack[count];
                        count--;
                        if((char)temp != '(') // invalid bracket
                        {
                            flag = 0;
                            printf("0\n");
                            goto end;
                        }
                    }
                    break;
                    case '}':
                    if(count == -1) // empty stack
                    {
                        flag = 0;
                        printf("0\n");
                        goto end;
                    }
                    else
                    {
                        int temp = stack[count];
                        count--;
                        if((char)temp != '{') // invalid bracket
                        {
                            flag = 0;
                            printf("0\n");
                            goto end;
                        }
                    }
                    break;
                    case ']':
                    if(count == -1) // empty stack
                    {
                        flag = 0;
                        printf("0\n");
                        goto end;
                    }
                    else
                    {
                        int temp = stack[count];
                        count--;
                        if((char)temp != '[') // invalid bracket
                        {
                            flag = 0;
                            printf("0\n");
                            goto end;
                        }
                        break;
                    }
                }
            } 
        }
        end:
        if(flag == 1) // if no invalid brackets, print 1
        {
            printf("1\n");
        }
        k--;
    }
}
