#include<stdio.h>
#include<string.h>
#include"List.h"
#include"stack.h"

//bool function for checking if the brackets of same type are placed together
bool check(char i,char j)				
{							
	if(i == '{' && j == '}')	return 1; 
	if(i == '(' && j == ')')	return 1; 
	if(i == '[' && j == ']')	return 1; 
	else 				return 0;
}

bool balance(char *exp)
{
	int i = 0;
	stack* stack1 = stack_new();

	while(exp[i])
	{
		if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[')	stack_push(stack1, (int)exp[i]);
		//stack loads only opening brackets 																
		if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
		{
			if(stack_is_empty(stack1))			return false;
			//if the exp starts with closing brackets, then function returns false
			
			else if(!(check(stack_pop(stack1), exp[i])))	return false;
			//if the closed bracket is not adjacent to the same type of bracket, then function returns false
		}
		i++;
	}
	if(stack_is_empty(stack1))	return true;
	//if every opening bracket is balanced, then function returns true
	
	else				return false;
}

int main()
{
	int i, n;
	
	scanf("%d",&n);
	//giving no.of inputs
	
	for(i = 0; i < n; i++)
	{
		char exp[1000];
		scanf("%s", exp);
		if(balance(exp))	printf("1\n");
		else		printf("0\n");
		//printing result
	}
	return 0;
}
 
