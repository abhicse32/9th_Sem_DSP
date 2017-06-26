//program to check parenthesis are blanced or not by Akshay Kumar

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void main()
{
	int t,i,j;																			//declaration of variables
	scanf("%d",&t);																		//number of test cases
	for(i = 0; i < t; i ++)
	{
		char a[1000];
		scanf("%s",a);																	//input of string
		stack* st = stack_new();														//creating new stack
		for(j = 0; a[j] != '\0'; j ++)
		{
			if(a[j] == '{') stack_push(st,1);											//storing the opening parenthesis
			if(a[j] == '(') stack_push(st,2);
			if(a[j] == '[') stack_push(st,3);
			if(a[j] == '}')																//if you find open parenthesis of same kind pop it
			{
				if(stack_is_empty(st))
				{
					printf("0\n");
					break;
				}
				if(st->top->head->data == 1) stack_pop(st);
				else {printf("0\n");break;}
			}
			if(a[j] == ')')
			{
				if(stack_is_empty(st))													//if first one is closed parenthesis then it is not balanced
				{
					printf("0\n");
					break;
				}
				if(st->top->head->data == 2) stack_pop(st);
				else {printf("0\n");break;}
			}
			if(a[j] == ']')
			{
				if(stack_is_empty(st))
				{
					printf("0\n");
					break;
				}
				if(st->top->head->data == 3) stack_pop(st);
				else {printf("0\n");break;}
			}
		}
		
		if(a[j] == '\0') printf("1\n");													//if balanced prints 1
	}
}
