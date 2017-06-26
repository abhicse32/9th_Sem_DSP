//Program to print next greater of each value in an array, Author:B Arjun, CS15B058
#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
int main(void)
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int* A=(int*)malloc(n*sizeof(int));
		int j;
		for(j=0;j<n;j++)
			scanf("%d",&A[j]);
		stack* indtrav=stack_new(); 		//stack to traverse elements of the array
		stack* ind=stack_new(); 		//stack to store index of popped out elements
		stack* nextval=stack_new();		//stack to store next greater for corresponding indices
		for(j=0;j<n;j++)
		{
			if(stack_is_empty(indtrav)) 		//if empty stack, push the index into traverse stack
				stack_push(indtrav,j);
			else 
			{
				int x=stack_pop(indtrav); 	
				int flag=0;			//to check if traverse stack becomes empty
				while(A[j]>A[x])		//to pop out indices of elements smaller then A[j]
				{
					stack_push(ind,x);	//index stored in ind stack
					stack_push(nextval,A[j]);	//next greater stored in nextval
					if(stack_is_empty(indtrav))
					{
						flag=1;
						break;
					}
					x=stack_pop(indtrav);
				}
				if(flag==0)
					stack_push(indtrav,x);		//if stack doesnt become empty push back the popped element
				stack_push(indtrav,j);			//push the index of current element in array
				
			}
		}
		while(!stack_is_empty(indtrav)) 	//elements which dont have next greater, we pop out and store -1
		{
			int y=stack_pop(indtrav);
			stack_push(ind,y);
			stack_push(nextval,-1);
		}
		while(!stack_is_empty(ind)) 		//we scan through ind and nextval stacks and we update the input array
		{
			int index=stack_pop(ind);
			int val=stack_pop(nextval);	
			A[index]=val;			//we store next greater values in respective indices in the array
		}
		for(j=0;j<n;j++)
			printf("%d ",A[j]);
		printf("\n");
	}
}
