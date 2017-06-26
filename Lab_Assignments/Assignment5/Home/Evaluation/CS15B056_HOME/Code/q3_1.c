//THIS CODE CONVERTS INSCRIPT TO POSTSCRIPT
//AUTHOR -SARTHAK PANDEY
//CS15B056

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "stack.h"
#include <string.h>
void stack_op (stack *stk,int data);
int preference(int i);
int main ()
{

	int i;
	stack *stk;
	stk=stack_new();
	char a[1000];
	while (fgets(a,999,stdin)!=NULL)
	{
		a[strlen(a)-1]='\0';
		for (i=0;a[i]!='\0';i++)
		{
			if (a[i]=='(')
				stack_push(stk,a[i]);                               //IF AN OPENING BRACKET ENCOUNTERED, PUSH IT IN STACK                
			else if ((a[i]!=')'&&a[i]!='('&&a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'&&a[i]!='^'&&a[i]!='%'&&a[i]!='&'&&a[i]!='|')||(a[i]=='-'&&a[i+1]!=' '))
			{
				if (a[i]!=' ')
				{
				if(a[i+1]!=' '&&a[i+1]!='\0')                                         //THIS IF PRINTS THE NUMBERS ALPHABETS ETC AS SOON AS IT SEES THEM
					printf("%c",a[i]);
				else
					printf("%c ",a[i]);
				}
			}
			
			else 
				stack_op(stk,a[i]);                                                   //IF AN OPERATOR OR CLOSING BRACKET ,THEN THIS FUNCTION IS CALLED
		}
		while(stack_size(stk)!=0)
		{
			printf("%c ",stack_pop(stk));                                                  //PRINTS THE FINAL ELEMENTS LEFT IN STACK
		}
		printf("\n");
		
	}
	return 0;
}

int preference(int i)                                                                                 // THIS FUNCTION RETURNS PREFERENCE OF VARIOUS OPERATORS
{
	if (i=='*'||i=='/'||i=='%')
		return 3;
	else if (i=='+'||i=='-')
		return 2;
	else if (i=='&')
		return 1;
	else if (i=='^')
		return 0;
	else if (i=='|')
		return -1;
	else if (i=='(')
		return -2;
	
		
		
}


void stack_op(stack *stk,int c)
{
	int i;
	if (c==')')                                                                                   //IF A CLOSING BRACKET IS ENCOUNTERED ,EMPTY STACK TILL OPENING BRACKET REACHED
	{
		i=stack_pop(stk);
		while (i!='(')
		{
			printf("%c ",i);
			i=stack_pop(stk);
		}
	}
	else
	{
		int j,flag=0;
		if (stack_size(stk)!=0)
		{
			for(j=stack_pop(stk);preference(j)>=preference(c);)                           //IF AN OPERATOR OF LOWER PREFERENCE ENCOUNTERED ,THEN PRINT ALL OPERATORS OF HIGHER OR EQUAL 
			{                                                                             //PREFERENCE BEFORE IT
				printf("%c ",j);
				if (stack_size(stk)!=0)
					j=stack_pop(stk);
				else
				{
					flag=-1;
					break;
				}
			}
			if(flag==0)
				stack_push(stk,j);
		}
		stack_push(stk,c);
	}	
}		
		
		
		
		
		
		
		
		
		
		
		
	
	
	
				
			
	

