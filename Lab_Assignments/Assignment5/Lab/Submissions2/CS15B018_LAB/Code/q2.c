#include<stdio.h>
#include<string.h>
#include"List.h"
#include"stack.h"

int reversal(char *exp)
{
	int i = 0;
	stack* stack1 = stack_new();
	//creating a stack
	
	int mid1, mid2;
	int count1 = 0;
	//starting count for no. of reversals
	
	while(exp[i])
	{
		if(exp[i] == '{' )	stack_push(stack1, (int)exp[i]);
		//if the exp has '{', then it will be moved to stack 
		
		if(exp[i] == '}' )
		{
			if(stack_is_empty(stack1)) count1++;
			//if the '{' are not present, count the no. of '}'
			
			else stack_pop(stack1);
			//else remove the top '{'
		}
		i++;
	}
	mid1 = (count1+1)/2;
	//the no. of reversals will be half the count for balancing
	//for odd it will be (count+1)/2
	
	if(stack_is_empty(stack1))	return mid1;
	
	//if the stack is not empty that is there are only '{', then again count no. of reversals
	int count2 = stack_size(stack1);
	mid2 = (count2+1)/2;
	return (mid1+mid2);
}

int main()
{
	int i, t, k;
	char exp[1005];
	
	//no. of test cases
	scanf("%d",&t);
	for(i = 0; i < t; i++)
	{
		int result;
		scanf("%s",exp);
		k = strlen(exp);
		
		//if string length is odd, prints -1, since it cannot be balanced
		if(k % 2 != 0)	result = -1;
		
		//else moves to the function
		else result = reversal(exp);
		printf("%d\n",result);
			
	}
}
