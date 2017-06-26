/*
        K ALEKHYA REDDY
        CS15B059
        16SEPT16
        TO CHECK IF BRACKETS ARE BALANCED OR NOT
        */
#include<stdio.h>
#include"stack.h"
#define size 1000
void check(char *str);	//function prototype
void main()
{
	int n;
	scanf("%d ",&n);	//inputs the number of test cases
	int i;
	for(i=0;i<n;i++)
	{
		char str[size];
		fgets(str,size,stdin);	//inputs the string from the user
		check(str);
	}
}

//function which checks if the paranthesis are balanced or not
void check(char *str)
{
	int chk=1;
	int i=0;
	int x;
	stack* temp=stack_new();	//create a new stack
	while(str[i+1]!='\0')
	{
		
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')	//if its an opening brace just push it
		{
			stack_push(temp,str[i]);
			i++;
		}
		else
		{
			if(temp->top->head ==NULL)	//if its empty
			{
				chk=0;
				break;
			}
			else{	
			x=stack_pop(temp);	//pop the first element
			if(x=='[' && str[i]==']');	//if they are not matching then break
			else if(x=='(' && str[i]==')');
			else if(x=='{' && str[i]=='}');
			else
			{
				chk=0;
				break;	
			}
			}
			i++;
		}
	}
	if(stack_is_empty(temp))
	printf("%d\n",chk);//to print the output
	else
		printf("0\n");
		
}
