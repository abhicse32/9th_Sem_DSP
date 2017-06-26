											/*program to find max and next max by Akshay Kumar*/

#include<stdio.h>

void main()
{
	int n,i,j,max,nextmax;									/*declaration of variables*/
	scanf("%d",&n);
	int array[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	max=array[0];
	nextmax=array[0];
	for(j=0;j<n;j++)
	{
		if(max<array[j])
		{
			nextmax=max;
			max=array[j];	
		}
		else if(nextmax<array[j])
		{
			nextmax=array[j];
		}
	}
	printf("%d %d \n",max,nextmax);
}
