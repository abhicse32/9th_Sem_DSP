/*
        K ALEKHYA REDDY
        CS15B059
        16SEPT16
        COUNT THE NUMBER OF REVERSALS
        */
#include<stdio.h>
#include"stack.h"
#define size 1000
void pushall(char *str);	//function prototype
void main()
{
	int n;
	scanf("%d",&n);	//inputs the number of test cases
	int i;
	for(i=0;i<n;i++)
	{
		char str[size];
		scanf("%s",str);	//inputs the string from the user
		pushall(str);
	}
}

//function which removes all the matching brackets
void pushall(char * str)
{
	int i=0;
	int x;
	int rev=0;
	stack* temp=stack_new();	//create a new stack
	while(str[i]!='\0')
	{
		if(str[i]=='{')	//if its an opening brace just push it
		{
			stack_push(temp,str[i]);
			i++;
		}
		else
		{	
			if(temp->top->head==NULL)	//if the stack is empty
			{
				stack_push(temp,'{');
				rev++;	//it cant  have a matching bracket hence reverse it and push
				i++;
			}
			else
			{
			x=stack_pop(temp);
			if(x=='{' && str[i]=='}');
			else
			{
				stack_push(temp,x);	//push the previously popped element
				stack_push(temp,str[i]);//pushes the new value because it doesnt match
			}
			i++;
			}	
			
		}
	}
	
	int s= stack_size(temp);
	if(s%2 !=0)
	{
		rev=-1; //not possible
	}
	else
	{
		rev=rev+s/2;
	}
	
	printf("%d\n",rev);		
}











