#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void next_greater(stack*A, stack* S);
void F(stack* A, stack* S, int z);

int main()
{
	int l;   			//number of test cases
	scanf("%d",&l);

	int i, j;

	for(i=0;i<l;i++)
	
		{
		  stack* S;
		  int n, z;
		  scanf("%d",&n);
		   	int x[n], i;

	S = stack_new();

	for(j=0; j<n; j++)
		
		{
		  scanf("%d",&x[j]);
		}

	for(j=0;j<n;j++)

		{
		  stack_push(S, x[n-j-1]);
		}
		  
	      stack* A;
		  A = stack_new();
		  next_greater(A, S);
		  z = stack_pop(S);

		  while(stack_size(A) != 0)

		  	{
			  z = stack_pop(A);
			  stack_push(S, z);
			}

		  stack_print(S);
		}
}



void next_greater(stack* A, stack* S)
{   
	if(stack_size(S) == 1){ stack_push(A, -1); return;}

	int z;
	z = stack_pop(S);
	F(A, S, z);
	next_greater(A, S);

}

void F(stack* A, stack* S, int z)
{
	if(stack_size(S) == 0) stack_push(A, -1);

 	else{
	int y;
    y = stack_pop(S);
	if(z >= y) F(A , S, z);
	else stack_push(A, y);
    stack_push(S, y);}
}

