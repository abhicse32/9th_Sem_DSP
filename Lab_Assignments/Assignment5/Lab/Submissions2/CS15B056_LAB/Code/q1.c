//COUNTS THE NUMBER OF MATCHING BRACES
//AUTHOR-SARTHAK PANDEY
//CS15B056

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "List.h"
#include "stack.h"

int main ()
{
	char a[1000];
	int n,i;
	stack *stk;
	stk=stack_new();
	scanf("%d",&n);
	for(i=0;i<n;i++)										//ITERATES N NUMBER OF TIMES
	{
		int j=0,k,cntr=0,c;
		scanf("%s",a);
		for(j=0;a[j]!='\0';j++)
		{
			if (a[j]==')'||a[j]=='}'||a[j]==']')                                           //IF CLOSING BRACKETS THEN POPS LAST VALUE AND CHECKS
			{	
				if(stack_size==0)
				{
					cntr=-1;
					break;
				}
				else 
					c=stack_pop(stk);
				if((c=='('&&a[j]==')')||(c=='{'&&a[j]=='}')||(c=='['&&a[j]==']'))      //CHECKS IF CORRESPONDING OPENING BRACKET PRESENT OR NOT
				{
					cntr++;
				}
				else
				{
					cntr=-1;
					break;
				}
			}
			else
			{
				stack_push(stk,a[j]);                                                  //IF OPENING BRACKET THEN PUSHES IT IN STACK
			}
			
		}
		if(stack_size(stk)!=0)
			{
			cntr=-1;                                                                       //RETURNS -1 IF ELEMENTS LEFT IN STACK
			}
		while(stack_size(stk)!=0)
			stack_pop(stk);

		if(cntr>=0)
		printf("1\n");                                                                         //FINAL OUTPUT
		else
		printf("0\n");
		
	}
	return 0;
}



			
			
