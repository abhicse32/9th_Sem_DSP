/*
This program prints the next maximum number for every number provided in the sequence in O(n) time

Ameet S Deshpande
CS15B001
*/


#include <stdio.h>

int main()
{
	int test;
	int a[10001],stack[10001];
	int top,pt;

	scanf("%d",&test);

	int i;	//Loop variable

	for(i=0;i<test;++i)
	{	
		top=-1;
		pt=-1;

		int n;

		scanf("%d",&n);	//Contains the number of integers being provided

		int j;	//Loop variable

		for(j=0;j<n;++j)
		{
			scanf("%d",&a[j]);
		}


		for(j=0;j<n;++j)
		{
			if(top==-1)		//If stack is empty, then just add the element
			{
				top=top+1;
				stack[top]=j;
			}

			else			//If stack is not empty, then pop the elements that are lesser than the current elements
			{	pt=top;

				while((a[stack[pt]]<a[j])&&(pt>=0))			//Remove pt variable if not required later------------------------------
				{
					a[stack[pt]]=a[j];
					pt--;
					top--;
				}

				top=top+1;
				stack[top]=j;


			}
		}		//Inner for loop ends

		j=top;		//For all the elements remaining in the stack, -1 should be printed
		while(j>=0)
		{
			a[stack[j]]=-1;
			j--;
		}


		for(j=0;j<n;++j)
		{
			printf("%d ",a[j]);
		}

		printf("\n");

	}
}
