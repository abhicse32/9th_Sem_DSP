//COUNTS THE NUMBER OF BRACES TO BE INVERTED TO TURN IT INTO A MEANINGFUL BRACES STRING
//AUTHOR-SARTHAK PANDEY
//CS15B056

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "List.h"
#include "stack.h"

int main()
{
	int n,j,i;
	scanf("%d",&n);
	stack *stk;
	stk=stack_new();
	char a[1000];
	for(j=0;j<n;j++)                                                                              //ITERATES N NUMBER OF TIMES
	{
		int ele=0,inv=0;
		scanf("%s",a);
		for(i=0;a[i]!='\0';i++)
			;
		if(i%2!=0)
		{
			inv=-1;                                                                       //IF NUMBER OF BRACKETS ODD,THEN CANNOT BE MADE MEANINGFUL BY INVERTING
			
		}
		else
		{
		for (i=0;a[i]!='\0';i++)
		{
			if (a[i]=='{')
				stack_push(stk,a[i]);                                                 //IF OPENING BRACKET,THEN PUSH IT IN STACK
			else if (a[i]=='}'&&stack_size(stk)==0)
			{
				inv=inv+1;
				stack_push(stk,'{');                                                  //IF CLOSING BRACKET WITHOUT OPENING BRACKET,THEN INVERT IT
			}
			else if (a[i]=='}'&&stack_pop(stk)=='{')
				;
		}
		inv=inv+stack_size(stk)/2;                                                            //STACK CONTAINS EVEN NO OF OPENING BRACKETS
		}
		printf("%d\n",inv);
		while(stack_size(stk)!=0)                                                             //CLEARES THE USED STACK
			stack_pop(stk);
	}
	return 0;
}



			
