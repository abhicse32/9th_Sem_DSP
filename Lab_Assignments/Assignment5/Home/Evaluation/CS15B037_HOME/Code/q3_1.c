/*
 * On 18th September 2016
 * Written by Teratipally Srikar
 * This program takes a string
 * as a infix expression and
 * converts it into postfix
*/

#include<stdio.h>   /*Including required header files*/
#include<stdlib.h>
#include<string.h>
#include "stack.h"
#include "List.h"

void convert(char* arr, int n); /*This function converts infix to postfix*/
bool is_operand(char c);        /*This function returns whether a character is operators*/
int precedence_check(char prev, char current);  /*This function checks the precedence*/
int stack_peep(stack* stk);     /*This function returns the top element of the stack*/
bool is_trueoperand(char c);    /*This function returns whether a character is operators*/

int main()
{
	int k=0;   /*Counter*/
	for(;k<10;k++){
	
	char arr[1000];    /*An array for storing the string*/
	char c;    /*Temp element*/    
	int i = 0; /*Counter*/
	int n = 0; /*Counter*/
		
	while(1)
	{
		c = getchar();    /*Scanning the element*/
		if(c=='\n') break;    /*Centinal*/
		if(c!=' ')	{
                                    arr[i] = c;
                                    i++;
                                }
	}
	arr[i] = ' ';
	i++;
	convert(arr,i);    /*Converts and prints the infix to postfix*/
}}

void convert(char* arr, int n)  /*This function converts infix to postfix*/
{
	int i; /*Counter*/
	int j; /*Counter*/
	stack* stk = stack_new();  /*Stack for storing the operators*/
	char* result = (char*) malloc((sizeof(char))*(1000));  /*For storing the result*/
	
	for(i=0,j=0;i<n;i++)
	{
							
		if(!is_operand(arr[i]))	{                         /*If the char is not operator we can add directly*/
                                            result[j] = arr[i];
                                            j++;
                                            continue;
                                        }
								
		if(is_trueoperand(arr[i]))	{      /*Just for manipulating the spaces*/
                                                    result[j] = ' ';
                                                    j++;
                                                }
		
		if(stack_is_empty(stk))	{                             /*If stack is empty then,we can add directly*/
                                            stack_push(stk,arr[i]);
                                            continue;
                                        }
						
		if(arr[i]=='(')	{                         /*If there is opening of bracket then, we can directly to it*/
                                    stack_push(stk,arr[i]);
                                    continue;
                                }
								
		if(arr[i]==')')	{                         /*If bracket is closed then, we should all the operators till it reacher) */
                                    while(stack_peep(stk)!='(')
                                    {
                                        result[j] = ' ';
					j++;
					result[j] = stack_pop(stk);
					j++;
                                    }
                                    char temp = stack_pop(stk);
                                    continue; 
                                }
						
		char prev = stack_peep(stk);  
		
		if(prev=='(')	{                           /*If the previous element is ( then it is similar to the emptiness of the stack*/
                                    stack_push(stk,arr[i]);
                                    continue;
                                }
						
		int flag = precedence_check(prev,arr[i]); /*Stores whether the current is high or low priority*/
		
		if(flag==1)	{
						do	{                                      /*If it is lower then, we have print till we encounter a operator lesser than tht*/
								result[j] = stack_pop(stk);
								j++;
								result[j] = ' ';
								j++;
								if(stack_is_empty(stk)) break;
								if(stack_peep(stk)=='(') break;
								prev = stack_peep(stk);
								flag = precedence_check(prev,arr[i]);
							}	while(flag==1);
							
						stack_push(stk,arr[i]);
						continue;
					}
		
		stack_push(stk,arr[i]);					
	}
	
	while(!stack_is_empty(stk))
	{
		char temp = stack_pop(stk);
		if(temp!='(')	{
                                    result[j] = temp;
                                    j++;
                                }
	}
	
	for(i=0;i<j;i++)   /*Printing the result*/
	{
		if(is_operand(result[i])&&is_operand(result[i+1]))	{
																printf("%c ",result[i]);
																continue;
															}
		printf("%c",result[i]);
	}

	printf("\n");
}

bool is_operand(char c)     /*This function returns whether a character is operators*/
{
	if(c==')') return true;
	if(c=='(') return true;
	if(c=='+') return true;
	if(c=='-') return true;
	if(c=='*') return true;
	if(c=='/') return true;
	if(c=='%') return true;
	if(c=='|') return true;
	if(c=='^') return true;
	if(c=='&') return true;
	
	else return false;
}

bool is_trueoperand(char c)     /*This function returns whether a character is operators*/
{
	if(c=='+') return true;
	if(c=='-') return true;
	if(c=='*') return true;
	if(c=='/') return true;
	if(c=='%') return true;
	if(c=='|') return true;
	if(c=='^') return true;
	if(c=='&') return true;
	
	else return false;
}

int precedence_check(char prev, char current)       /*This function checks the precedence*/
{
	int a;
	int b;
	
	if(prev=='(') a = 0;
	else if(prev=='*') a = 1;
	else if(prev=='/') a = 1;
	else if(prev=='%') a = 1;
	else if(prev=='+') a = 2;
	else if(prev=='-') a = 2;
	else if(prev=='&') a = 3;
	else if(prev=='^') a = 4;
	else if(prev=='|') a = 5;

	if(current=='(') b = 0;
	else if(current=='*') b = 1;
	else if(current=='/') b = 1;
	else if(current=='%') b = 1;
	else if(current=='+') b = 2;
	else if(current=='-') b = 2;
	else if(current=='&') b = 3;
	else if(current=='^') b = 4;
	else if(current=='|') b = 5;
	
	if(b>=a) return 1;
	else return 0;
}

int stack_peep(stack* stk)      /*This function returns the top element of the stack*/
{
	return (llist_get(stk->top,0));
}

