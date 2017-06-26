/*
 * On 18th September 2016
 * Written by Teratipally Srikar,CS15B037
 * This program evaluates a
 * fiven postfix expression
 */

#include <stdio.h>  /*Including the required header files*/
#include <stdlib.h>
#include <string.h>
#include "stack.h"

bool is_number(char c); /*This function determines if a given char is a number*/
int operate(char c);    /*This function retruns the type of operator*/
int evaluate();         /*This function evaluates a given postfix expression*/

int main()
{
	int i; /*Counter*/

	for(i=0;i<10;i++)
	{
		int result = evaluate();
		printf("%d\n",result);		
	}
}

int evaluate()  /*This function evaluates a given postfix expression*/
{
	stack* stk = stack_new();  /*For storing the operands*/
	char c;                    /*Temp variable*/
	int x=0;                   /*For storing the variable into stack*/
	int a;                     /*Temp variable*/
	int b;                     /*Temp variable*/
	int flag;                  /*Flag*/
	int result;                /*Stores the result*/
	char prev = 'a';
	int minus=0;               /*Flag for telling previous element is - */
	int flag1 = 1;             /*Determines whether the present variable is negative or not*/
	
	while(1)
	{
		c = getchar();
		
		if(c=='\n') break;    /*Sentinal*/
		
		if((minus==1)&&(c!=' '))	{
                                                    flag1 = -1;
                                                    minus = 0;
                                                }
		
		if(is_number(c))	{                        /*If char is number we have store it*/
                                            int temp = c - '0';
                                            x = x*10 + temp;
                                            prev = c;
                                            continue;
                                        }
							
		if((c==' ')&&(is_number(prev)))	{             /* If there is a space then, we should store the number*/
                                                    x = x*flag1;
                                                    stack_push(stk,x);
                                                    x=0;            /*Intiasling again*/
                                                    flag1 = 1;      /*Intiasling again*/
                                                    prev = c;
                                                    continue;
						}
		if((c==' ')&&(minus==1))	{
                                                    b = stack_pop(stk);
                                                    a = stack_pop(stk);
                                                    result = a - b;
                                                    stack_push(stk,result);
                                                    minus = 0;  /*Intiasling again*/
                                                    continue;
						}
		if((c==' ')&&(!is_number(prev))) continue;
										
		if(c=='-')	{
                                    minus = 1;
                                    prev = c;
                                    continue;
                                }
					
		prev = c;
		flag = operate(c);        /*Since if we encounter a operator, we can remove 2 elements and operate them*/
		b = stack_pop(stk);
		a = stack_pop(stk);
		
		switch(flag)	{
							case 0: {
										result = a + b;
										break;
                                                                }
									
							case 1: {
										result = a - b;
										break;
								}
									
							case 2: {
										result = a * b;
										break;
								}
									
							case 3: {
										result = a / b;
										break;
								}
							case 4: {
										result = a % b;
										break;
								}
							case 5: {
										result = a ^ b;
										break;
								}
							case 6: {
										result = a & b;
										break;
								}
							case 7: {
										result = a | b;
										break;
								}

						}
		stack_push(stk,result);
	}
	
	if(prev=='-')	{
                            b = stack_pop(stk);
                            a = stack_pop(stk);
                            result = a - b;
                            stack_push(stk,result);
			}
			
	return stack_pop(stk);
}

bool is_number(char c)  /*This function determines if a char is number*/
{
	if((c>='0') && (c<='9')) return true;
	else return false;
}

int operate(char c) /*Returns the distinct value for each operator*/
{
	if(c=='+') return 0;
	if(c=='-') return 1;
	if(c=='*') return 2;
	if(c=='/') return 3;
	if(c=='%') return 4;
	if(c=='^') return 5;
	if(c=='&') return 6;
	if(c=='|') return 7;
}
