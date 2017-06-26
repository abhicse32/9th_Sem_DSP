/*
This program finds the maximum and second maximum of a given array

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>

int main()
{	
	
	int n;	//Size of the array
	int *a;	//Pointer for storing the array elements
	int i;	//Loop variable
	
	int max1,max2,maxi;	//Contains the maximum and the second maximum numbers
	
	scanf("%d",&n);	//Prompting user to enter the size of the array
	
	a=(int *)malloc(n*sizeof(int));
	//a=new int[n];
	
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);	//Prompting the user to enter the elements of the array
	}
	
	max1=a[0];
	for(i=1;i<n;++i)
	{
		if(a[i]>max1)
		{
			max1=a[i];
			maxi=i;
		}
	}
	max2=-2147483648;
	for(i=0;i<n;++i)
	{
		if((a[i]>max2)&&(i!=maxi))
		{
			max2=a[i];
		}
	}
	
	
	printf("%d %d",max1,max2);
	//delete[] a;
	free(a);
}